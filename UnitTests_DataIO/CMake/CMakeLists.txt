# --------------------------------------------------------------------
# unittests_dataio : DataIO Unit Tests (Google Test console mode)
# GEN FrameWork
# --------------------------------------------------------------------

cmake_minimum_required(VERSION 3.16.0)
project(unittests_dataio)

set(GEN_DIRECTORY "../../..")


# --------------------------------------------------------------------
# Activate features/Defines
# Offline-safe DataIO coverage: no live remote sockets/TLS handshake,
# no USB/BT/I2C/SPI hardware drivers. Config/parse/buffer logic only.

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
option(APPFLOW_LOG_FEATURE                                      "Application Flow Log"                                    ON )
option(APPFLOW_CONSOLE_FEATURE                                  "Application Flow Console"                                ON )
option(APPFLOW_CFG_GENERAL_FEATURE                              "Application Flow CFG General"                            ON )
option(APPFLOW_CFG_LOG_FEATURE                                  "Application Flow CFG LOG"                                ON )
option(APPFLOW_CFG_REMOTEFILE_FEATURE                           "Application Flow CFG Remote File"                        ON )

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
option(CIPHER_ASYMMETRIC_RSA_FEATURE                            "Cipher Asymmetric RSA (XMPInteger/X.509)"                ON )

option(DIO_FEATURE                                              "Input/Output"                                            ON )
option(DIO_DNSRESOLVER_FEATURE                                  "DNS Resolver"                                            ON )
option(DIO_NOTIFICATIONS_MANAGER_FEATURE                        "Notifications Manager"                                   ON )
option(DIO_PUBLICINTERNETIP_FEATURE                             "Public Internet IP"                                      OFF)
option(DIO_STREAMTLS12_FEATURE                                  "TLS 1.2 (RFC 5246)"                                      ON )
option(DIO_STREAMTLS_FEATURE                                    "Data Input/Output Stream TLS"                            ON )

option(DIO_STREAM_FEATURE                                       "Stream"                                                  ON )
option(DIO_STREAMTCPIP_FEATURE                                  "Stream TCPIP"                                            ON )
option(DIO_STREAMUDP_FEATURE                                    "Stream UDP"                                              ON )
option(DIO_STREAMUART_FEATURE                                   "Stream UART"                                             ON )
option(DIO_STREAMUSB_FEATURE                                    "Stream USB"                                              OFF)
option(DIO_STREAMBLUETOOTH_FEATURE                              "Stream Bluetooth"                                        OFF)
option(DIO_STREAMBLUETOOTHLE_FEATURE                            "Stream Bluetooth LE"                                     OFF)
option(DIO_STREAMI2C_FEATURE                                    "Stream I2C"                                              OFF)
option(DIO_STREAMSPI_FEATURE                                    "Stream SPI"                                              OFF)
option(DIO_STREAMICMP_FEATURE                                   "Stream ICMP"                                             ON )
option(DIO_STREAMCIPHER_FEATURE                                 "Stream Cipher"                                           ON )

option(DIO_SMTP_FEATURE                                         "SMTP (email)"                                            ON )
option(DIO_WEBCLIENT_FEATURE                                    "Web Client"                                              ON )
option(DIO_WEBSERVER_FEATURE                                    "Web Server"                                              ON )
option(DIO_COREPROTOCOL_FEATURE                                 "Core Protocol"                                           ON )
option(DIO_PROTOCOL_FEATURE                                     "Protocol"                                                ON )
option(DIO_PROTOCOL_CLI_FEATURE                                 "Protocol in CLI"                                         ON )
option(DIO_ALERTS_FEATURE                                       "Alerts"                                                  ON )
option(DIO_PING_FEATURE                                         "Ping"                                                    ON )
option(DIO_NODES_FEATURE                                        "Nodes modules"                                           ON )
option(DIO_WAKEONLAN_FEATURE                                    "Wake On LAN"                                             ON )
option(DIO_CHECKCONNECTIONS_FEATURE                             "Check Connections"                                       ON )
option(DIO_NETWORKTIMEPROTOCOL_FEATURE                          "Network Time Protocol"                                   ON )
option(DIO_SNMP_FEATURE                                         "SNMP"                                                    ON )
option(DIO_ATCMD_FEATURE                                        "AT Commands"                                             ON )
option(DIO_MODBUSCLIENT_FEATURE                                 "DIO ModBus Client"                                       ON )
option(DIO_IEC60870_5_FEATURE                                   "DIO IEC 60870-5"                                         ON )
option(DIO_LOCATION_FEATURE                                     "Location API"                                            ON )
option(DIO_SCRAPERWEB_FEATURE                                   "Scraper Web"                                             ON )
option(DIO_SCRAPERWEB_MACMANUFACTURER_FEATURE                    "Scraper Web MAC Manufacturer"                            ON )
option(DIO_SCRAPERWEB_USERAGENTID_FEATURE                       "Scraper Web User Agent ID"                                ON )
option(DIO_DISPLAYDEVICE_FEATURE                                "Display Device"                                          ON )
option(DIO_APPLICATIONUPDATE_FEATURE                            "Application Update"                                      ON )
option(DIO_OSPIPELINE_FEATURE                                   "OS Pipeline"                                             ON )


# --------------------------------------------------------------------
# Main CMakeList of GEN

include("${GEN_DIRECTORY}/Common/CMake/GEN_Main.cmake")


# --------------------------------------------------------------------
# Directorys of the Application

set(APP_DIRECTORY_APPLICATION   "../Sources")
list(APPEND GEN_INCLUDES_DIR_LIST ${APP_DIRECTORY_APPLICATION})


# --------------------------------------------------------------------
# Source code of the Application

list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_Helper.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOMAC.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOIP.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOURL.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOEmailAddress.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOFactory.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIODevice.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOStream.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOStreamConfig.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOStream_XEvent.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOStreamTCPIPConfig.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOStreamUDPConfig.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOStreamUARTConfig.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOStreamICMPConfig.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOStreamDeviceIP.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOWebHeader.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOWebPageHTMLCreator.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOWebServer_QueryStrings.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOCoreProtocol_Header.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOCoreProtocol_CFG.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIORemoteFileCFG.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOAlerts.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIONodeItem.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIONodeItemValue.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOPing_XEvent.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOWakeOnLAN.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOSNMP.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOATCMDS.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOModBus_Client.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOIEC60870_5.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIONTP.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOScraperWebCache.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOScraperWebUserAgentID.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIODisplayDevice.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOApplicationUpdate.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOOSPipeline.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOLocation.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOStreamConfigString.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOCLIProtocol.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOProtocol_ApplicationData.cpp")
list(APPEND GEN_SOURCES_MODULES_LIST "${APP_DIRECTORY_APPLICATION}/UnitTests_DataIO_DIOCheckTCPIPConnections.cpp")


# --------------------------------------------------------------------
# End Proyect

include("${GEN_DIRECTORY}/Common/CMake/GEN_End.cmake")
