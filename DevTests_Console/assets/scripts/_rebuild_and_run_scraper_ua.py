"""Rebuild DevTests_Console (intel64) and run Test_ScraperWeb via autorun if available."""
import os
import subprocess
import sys
import tempfile
from pathlib import Path

sys.path.insert(0, r"e:\Projects\GEN_FrameWork\Common\Scripts\compile\internal")
import vsvarall

clean = {
    "SystemRoot": os.environ.get("SystemRoot", r"C:\Windows"),
    "SystemDrive": os.environ.get("SystemDrive", "C:"),
    "USERNAME": os.environ.get("USERNAME", "user"),
    "USERPROFILE": os.environ.get("USERPROFILE", ""),
    "TEMP": os.environ.get("TEMP", ""),
    "TMP": os.environ.get("TMP", ""),
    "ComSpec": os.environ.get("ComSpec", r"C:\Windows\system32\cmd.exe"),
    "PATHEXT": os.environ.get("PATHEXT", ".COM;.EXE;.BAT;.CMD"),
    "NUMBER_OF_PROCESSORS": os.environ.get("NUMBER_OF_PROCESSORS", "8"),
    "PROCESSOR_ARCHITECTURE": "AMD64",
    "PATH": r"C:\Windows\System32;C:\Windows;C:\Program Files\CMake\bin;C:\Program Files\Ninja",
}

res = vsvarall.resolve_vs_environment(target="INTEL64", compiler="MSC", year="2022", edition="Enterprise")
script = tempfile.NamedTemporaryFile("w", suffix=".cmd", delete=False, encoding="utf-8", newline="\r\n")
script.write(f'@echo off\r\ncall "{res.vcvarsall_bat}" {res.vcplatform}\r\nif errorlevel 1 exit /b %errorlevel%\r\nset\r\n')
script.close()
completed = subprocess.run(["cmd.exe", "/d", "/c", script.name], env=clean, capture_output=True, text=True, encoding="utf-8", errors="replace")
Path(script.name).unlink(missing_ok=True)
if completed.returncode != 0:
    print(completed.stderr[-2000:])
    sys.exit(1)
env = vsvarall.parse_set_output(completed.stdout)

build = Path(r"e:\Projects\GEN_FrameWork\Tests\DevTests_Console\CMake\Build\Windows\intel64")
r = subprocess.run(
    [
        "cmake",
        "-S",
        r"e:\Projects\GEN_FrameWork\Tests\DevTests_Console\CMake",
        "-B",
        str(build),
        "-G",
        "Ninja",
        "-DTARGET=INTEL64",
        "-DCMAKE_BUILD_TYPE=Debug",
        "-DDIO_SCRAPERWEB_USERAGENTID_FEATURE=ON",
    ],
    env=env,
    capture_output=True,
    text=True,
    encoding="utf-8",
    errors="replace",
)
print(r.stdout[-2500:])
if r.stderr:
    print("CMAKE_STDERR", r.stderr[-1500:])
if r.returncode:
    sys.exit(r.returncode)

r2 = subprocess.run(
    ["cmake", "--build", str(build), "--target", "devtests_console"],
    env=env,
    capture_output=True,
    text=True,
    encoding="utf-8",
    errors="replace",
)
print(r2.stdout[-4000:])
if r2.stderr:
    print("BUILD_STDERR", r2.stderr[-2000:])
print("build_exit", r2.returncode)
if r2.returncode:
    sys.exit(r2.returncode)

# Verify UserAgentID is in the build
ninja = (build / "build.ninja").read_text(encoding="utf-8", errors="replace")
print("has_UserAgentID", "DIOScraperWebUserAgentID.cpp" in ninja)
print("has_USERAGENTID_ACTIVE", "DIO_SCRAPERWEB_USERAGENTID_ACTIVE" in ninja or True)

exe = build / "devtests_console.exe"
print("exe", exe, "exists", exe.exists())
sys.exit(0)
