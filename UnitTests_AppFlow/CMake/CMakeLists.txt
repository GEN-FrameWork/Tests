# --------------------------------------------------------------------
# unittests_appflow : AppFlow Unit Tests (Google Test console mode)
# GEN FrameWork
# --------------------------------------------------------------------

cmake_minimum_required(VERSION 3.16.0)
project(unittests_appflow)

set(GEN_DIRECTORY "../../..")


# --------------------------------------------------------------------
# Activate features/Defines
# Offline-safe AppFlow: CFG/events/status serialize; no web listen, no
# internet check/NTP/update download, no alert Send to live SMTP.

option(DEBUG_FEATURE                                            "Debug mode"                                              ON )
option(XTRACE_FEATURE                                           "XTrace"                                                  ON )
option(XTRACE_NOINTERNET_FEATURE                                "No need for trace dependencies with Internet"            ON )
option(XMEMORY_CONTROL_FEATURE                                  "XMemory Control"                                         ON )

option(COVERAGE_CREATEINFO_FEATURE                              "Coverage - Create Info"                                  ON )

option(LINUX_VISUALSTUDIO_UTF8_FEATURE                          "Linux CodePage Editor UTF8"                              ON )

option(USE_CLANG_COMPILER_FEATURE                               "Use Clang Compiler"                                      ON )

option(LINUX_X11_FEATURE                                        "Linux X11"                                               ON )

option(XSLEEP_FEATURE                                           "XSleep"                                                  ON )
option(XUUID_FEATURE                                            "UUID functions"                                          ON )

option(APPFLOW_FEATURE                                          "Application Flow modules"                                ON )
option(APPFLOW_EXTENDED_FEATURE                                 "Application Flow Extended"                               ON )
option(APPFLOW_EXTENDED_APPLICATIONSTATUS_FEATURE               "Application Flow Extended Application Status"          ON )
option(APPFLOW_EXTENDED_INTERNETSTATUS_FEATURE                   "Application Flow Extended Internet Status"               ON )
option(APPFLOW_EXTENDED_APPLICATIONHEADER_FEATURE               "Application Flow Extended Application Header"            ON )
option(APPFLOW_CONSOLE_FEATURE                                  "Application Flow Console"                                ON )
option(APPFLOW_GRAPHICS_FEATURE                                 "Application Flow Graphics"                               ON )
option(APPFLOW_CHECKRESOURCESHARDWARE_FEATURE                   "Application Flow Check Resources Hardware"               ON )
option(APPFLOW_INTERNETSERVICES_FEATURE                         "Application Flow Internet Services"                      ON )
option(APPFLOW_LOG_FEATURE                                      "Application Flow Log"                                    ON )
option(APPFLOW_WEBSERVER_FEATURE                                "Application Flow Web Server"                             ON )
option(APPFLOW_UPDATE_FEATURE                                   "Application Flow Update"                                 ON )
option(APPFLOW_ALERTS_FEATURE                                   "Application Flow Alerts"                                 ON )

option(APPFLOW_CFG_FEATURE                                      "Application Flow CFG"                                    ON )
option(APPFLOW_CFG_GENERAL_FEATURE                              "Application Flow CFG General"                            ON )
option(APPFLOW_CFG_LOG_FEATURE                                  "Application Flow CFG LOG"                                ON )
option(APPFLOW_CFG_REMOTEFILE_FEATURE                           "Application Flow CFG Remote File"                        ON )
option(APPFLOW_CFG_INTERNETSERVICES_FEATURE                     "Application Flow CFG Internet services"                  ON )
option(APPFLOW_CFG_CHECKRESOURCESHARDWARE_FEATURE               "Application Flow CFG Check Resorces HW"                  ON )
option(APPFLOW_CFG_WEBSERVER_FEATURE                            "Application Flow CFG Web Server"                         ON )
option(APPFLOW_CFG_ALERTS_FEATURE                               "Application Flow CFG Alerts"                             ON )
option(APPFLOW_CFG_APPUPDATE_FEATURE                            "Application Flow CFG App Update"                         ON )
option(APPFLOW_CFG_DIOLOCATION_FEATURE                          "Application Flow CFG DIO Location"                       ON )
option(APPFLOW_CFG_DNSRESOLVER_FEATURE                          "Application Flow CFG DNS Resolver"                       OFF)

option(GOOGLETEST_FEATURE                                       "Google Test functionality"                               ON )
option(XSERIALIZABLE_BINARY_FEATURE                             "Serializable Binary"                                     ON )
option(XSERIALIZABLE_JSON_FEATURE                               "Serializable JSON"                                       ON )

option(XFILE_INI_FEATURE                                        "XFile INI format"                                        ON )
option(XFILE_CFG_FEATURE                                        "XFile Config format"                                     ON )
option(XFILE_TXT_FEATURE                                        "XFile Text format"                                       ON )
option(XFILE_XML_FEATURE                                        "XFile XML format"                                        ON )

option(HASH_SHA2_FEATURE                                        "Hash SHA2"                                               ON )
option(HASH_HMAC_FEATURE                                        "Hash HMAC"                                               ON )
option(CIPHER_SYMMETRIC_DES_FEATURE                             "Cipher Symmetric DES/3DES"                               ON )
option(CIPHER_ASYMMETRIC_RSA_FEATURE                            "Cipher Asymmetric RSA"                                   ON )

option(INP_FEATURE                                              "Input"                                                   ON )

option(GRP_FEATURE                                              "Graphics"                                                ON )
option(GRP_2D_FEATURE                                           "Graphics 2D"                                             ON )
option(GRP_DESKTOPMANAGER_FEATURE                               "Graphics Desktop Manager"                                ON )
option(GRP_OPENGL_FEATURE                                       "Graphics Open GL"                                        OFF)

option(DIO_FEATURE                                              "Input/Output"                                            ON )
option(DIO_DNSRESOLVER_FEATURE                                  "DNS Resolver"                                            ON )
option(DIO_NOTIFICATIONS_MANAGER_FEATURE                        "Notifications Manager"                                   ON )
option(DIO_PUBLICINTERNETIP_FEATURE                             "Public Internet IP"                                      ON )
option(DIO_STREAMTLS12_FEATURE                                  "TLS 1.2 (RFC 5246)"                                      ON )
option(DIO_STREAMTLS_FEATURE                                    "Data Input/Output Stream TLS"                            ON )
option(DIO_STREAM_FEATURE                                       "Stream"                                                  ON )
option(DIO_STREAMTCPIP_FEATURE                                  "Stream TCPIP"                                            ON )
option(DIO_STREAMUDP_FEATURE                                    "Stream UDP"                                              ON )
option(DIO_STREAMICMP_FEATURE                                   "Stream ICMP"                                             ON )
option(DIO_SMTP_FEATURE                                         "SMTP (email)"                                            ON )
option(DIO_WEBCLIENT_FEATURE                                    "Web Client"                                              ON )
option(DIO_WEBSERVER_FEATURE                                    "Web Server"                                              ON )
option(DIO_ALERTS_FEATURE                                       "Alerts"                                                  ON )
option(DIO_CHECKCONNECTIONS_FEATURE                             "Check Connections"                                       ON )
option(DIO_APPLICATIONUPDATE_FEATURE                            "Application Update"                                      ON )
option(DIO_LOCATION_FEATURE                                     "Location API"                                            ON )
option(DIO_SCRAPERWEB_FEATURE                                   "Scraper Web"                                             ON )
option(DIO_PING_FEATURE                                         "Ping"                                                    ON )
option(DIO_NETWORKTIMEPROTOCOL_FEATURE                          "Network Time Protocol"                                   ON )


# --------------------------------------------------------------------
# Main CMakeList of GEN

include("${GEN_DIRECTORY}/Common/CMake/GEN_Main.cmake")


# --------------------------------------------------------------------
# Directorys of the Application

set(APP_DIRECTORY_APPLICATION   "../Sources")
list(APPEND GEN_INCLUDES_DIR_LIST ${APP_DIRECTORY_APPLICATION})


# --------------------------------------------------------------------
# Source code of the Application

list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_Helper.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlow_XEvent.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowCFG.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowConsole.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowExtended.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowExtended_ApplicationStatus.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowExtended_InternetStatus.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowCheckResourcesHardware.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowCheckResourcesHardware_XEvent.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowInternetServices.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowInternetServices_XEvent.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowLog.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowWebServer.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowUpdate.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowAlerts.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowGraphics.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_AppFlow_APPFlowMain.cpp")

# Orphan core module: present under GEN/Graphic but not listed in GEN_Main_Sources.cmake.
list(APPEND GEN_SOURCES_MODULES_LIST "${GEN_DIRECTORY}/GEN/Graphic/GRPDisplayDevice.cpp")


# --------------------------------------------------------------------
# End Proyect

include("${GEN_DIRECTORY}/Common/CMake/GEN_End.cmake")