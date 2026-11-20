# --------------------------------------------------------------------
# unittests_sound : Sound Unit Tests (Google Test console mode)
# GEN FrameWork
# --------------------------------------------------------------------

cmake_minimum_required(VERSION 3.16.0)

# --------------------------------------------------------------------
# PreProject

set(GEN_DIRECTORY "../../..")

option(USE_CLANG_COMPILER_FEATURE                               "Use Clang Compiler"                                      ON)
include("${GEN_DIRECTORY}/Common/CMake/GEN_PreProject.cmake")

project(unittests_sound)

# --------------------------------------------------------------------
# Activate features/Defines

option(DEBUG_FEATURE                                            "Debug mode"                                              ON )
option(XTRACE_FEATURE                                           "XTrace"                                                  ON )
option(XTRACE_NOINTERNET_FEATURE                                "No need for trace dependencies with Internet"            ON )
option(XMEMORY_CONTROL_FEATURE                                  "XMemory Control"                                         ON )

option(COVERAGE_CREATEINFO_FEATURE                              "Coverage - Create Info"                                  ON )

option(LINUX_VISUALSTUDIO_UTF8_FEATURE                          "Linux CodePage Editor UTF8"                              ON )


option(XSLEEP_FEATURE                                           "XSleep"                                                  ON )
option(XUUID_FEATURE                                            "UUID functions"                                          ON )

option(DIO_FEATURE                                              "Input/Output"                                            ON )

option(APPFLOW_FEATURE                                          "Application Flow modules"                                ON )

option(GOOGLETEST_FEATURE                                       "Google Test functionality"                               ON )
option(XSERIALIZABLE_BINARY_FEATURE                             "Serializable Binary"                                     ON )
option(XSERIALIZABLE_JSON_FEATURE                               "Serializable JSON"                                       ON )

option(XFILE_INI_FEATURE                                        "XFile INI format"                                        ON )
option(XFILE_RIFF_FEATURE                                       "XFile RIFF format"                                       ON )
option(DIO_STREAMTLS12_FEATURE                                  "TLS 1.2 (RFC 5246)"                                      OFF)

option(SND_FEATURE                                              "Sound"                                                   ON )
option(SND_FILE_WAV_FEATURE                                     "Sound WAV file"                                          ON )
option(SND_FILE_OGG_FEATURE                                     "Sound OGG file"                                          ON )


# --------------------------------------------------------------------
# Main CMakeList of GEN

include("${GEN_DIRECTORY}/Common/CMake/GEN_Main.cmake")


# --------------------------------------------------------------------
# Directorys of the Application

set(APP_DIRECTORY_APPLICATION   "../Sources")
list(APPEND GEN_INCLUDES_DIR_LIST ${APP_DIRECTORY_APPLICATION})


# --------------------------------------------------------------------
# Source code of the Application

list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_Helper.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_SNDPlayCFG.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_SNDNote.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_SNDFactory_XEvent.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_SNDItem.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_SNDFactory.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_SNDFile.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_SNDFileWAV.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_SNDFileOGG.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_SNDOpenALBuffer.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_Sound_SNDOpenALPlayItem.cpp")


# --------------------------------------------------------------------
# End Proyect

include("${GEN_DIRECTORY}/Common/CMake/GEN_End.cmake")

# OpenAL Soft C++17 + warning suppressions (/wd4293, RESTRICT, …) come from
# GEN_ThirdPartyLibraries_Warnings_*_OpenAL in GEN_Main_Warnings.cmake.
# Do not set_source_files_properties(COMPILE_FLAGS) here — a replace wipes those flags.
