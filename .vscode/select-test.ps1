#Requires -Version 5.1
<#
.SYNOPSIS
  Cambia el test activo de CMake Tools en Cursor/VS Code.
.PARAMETER TestRelPath
  Ruta relativa bajo Tests, p.ej. DevTests_Console
#>
param(
  [Parameter(Mandatory = $true)]
  [string]$TestRelPath
)

$ErrorActionPreference = 'Stop'

$testsRoot = Split-Path -Parent $PSScriptRoot   # .../Tests
$repoRoot  = Split-Path -Parent $testsRoot      # .../GEN_FrameWork
$cmakeDir  = Join-Path $testsRoot ($TestRelPath -replace '/', '\') | Join-Path -ChildPath 'CMake'

if (-not (Test-Path (Join-Path $cmakeDir 'CMakeLists.txt'))) {
  Write-Error "No existe CMakeLists.txt en: $cmakeDir"
}

$posixRel  = ($TestRelPath -replace '\\', '/').Trim('/')
$wsRel     = "`${workspaceFolder:Tests}/$posixRel/CMake"
$localRel  = "`${workspaceFolder}/$posixRel/CMake"
$compile   = "$wsRel/compile_commands.json"
$compileLo = "$localRel/compile_commands.json"

function Set-JsonStringProp([string]$json, [string]$prop, [string]$value) {
  $escaped = $value.Replace('\', '\\').Replace('"', '\"')
  $pattern = '"' + [regex]::Escape($prop) + '"\s*:\s*"[^"]*"'
  $replacement = '"' + $prop + '": "' + $escaped + '"'
  if ($json -notmatch $pattern) {
    throw "No se encontro la propiedad '$prop' en el JSON."
  }
  return [regex]::Replace($json, $pattern, $replacement, 1)
}

# 1) Workspace multi-root
$workspaceFile = Join-Path $repoRoot 'GEN_FrameWork.code-workspace'
if (Test-Path $workspaceFile) {
  $ws = Get-Content -Raw -Encoding UTF8 $workspaceFile
  $ws = Set-JsonStringProp $ws 'cmake.sourceDirectory' $wsRel
  $ws = Set-JsonStringProp $ws 'cmake.copyCompileCommands' $compile
  $ws = Set-JsonStringProp $ws 'C_Cpp.default.compileCommands' $compile
  $clangdWsArg = "--compile-commands-dir=$wsRel"
  $clangdPattern = '"clangd\.arguments"\s*:\s*\[[^\]]*\]'
  $clangdReplacement = '"clangd.arguments": [' + "`n" + '      "' + $clangdWsArg.Replace('\', '\\').Replace('"', '\"') + '"' + "`n" + '    ]'
  if ($ws -match $clangdPattern) {
    $ws = [regex]::Replace($ws, $clangdPattern, $clangdReplacement, 1)
  }
  Set-Content -Path $workspaceFile -Value $ws.TrimEnd() -Encoding UTF8 -NoNewline
  Add-Content -Path $workspaceFile -Value "`n" -Encoding UTF8
  Write-Host "OK workspace: Tests/$posixRel"
}

# 2) Tests/.vscode/settings.json
$localSettings = Join-Path $PSScriptRoot 'settings.json'
if (Test-Path $localSettings) {
  $es = Get-Content -Raw -Encoding UTF8 $localSettings
  $es = Set-JsonStringProp $es 'cmake.sourceDirectory' $localRel
  if ($es -match '"cmake\.copyCompileCommands"') {
    $es = Set-JsonStringProp $es 'cmake.copyCompileCommands' $compileLo
  }
  if ($es -match '"C_Cpp\.default\.compileCommands"') {
    $es = Set-JsonStringProp $es 'C_Cpp.default.compileCommands' $compileLo
  }
  $clangdArg = "--compile-commands-dir=$localRel"
  $clangdPattern = '"clangd\.arguments"\s*:\s*\[[^\]]*\]'
  $clangdReplacement = '"clangd.arguments": [' + "`n" + '    "' + $clangdArg.Replace('\', '\\').Replace('"', '\"') + '"' + "`n" + '  ]'
  if ($es -match $clangdPattern) {
    $es = [regex]::Replace($es, $clangdPattern, $clangdReplacement, 1)
  }
  Set-Content -Path $localSettings -Value $es.TrimEnd() -Encoding UTF8 -NoNewline
  Add-Content -Path $localSettings -Value "`n" -Encoding UTF8
  Write-Host "OK Tests/.vscode/settings.json"
}

# 3) Repo root .vscode/settings.json
$rootSettings = Join-Path $repoRoot '.vscode\settings.json'
$absCmake = ($cmakeDir -replace '\\', '/')
if (Test-Path $rootSettings) {
  $rs = Get-Content -Raw -Encoding UTF8 $rootSettings
  if ($rs -match '"cmake\.sourceDirectory"') {
    $rs = Set-JsonStringProp $rs 'cmake.sourceDirectory' $absCmake
    Set-Content -Path $rootSettings -Value $rs.TrimEnd() -Encoding UTF8 -NoNewline
    Add-Content -Path $rootSettings -Value "`n" -Encoding UTF8
    Write-Host "OK .vscode/settings.json (raiz)"
  }
}

Write-Host ""
Write-Host "Test activo: $posixRel"
Write-Host "Siguiente paso: Command Palette -> CMake: Delete Cache and Reconfigure"
Write-Host "Luego elige el preset (MSVC / WSL GCC-Clang) y Build."
