/**-------------------------------------------------------------------------------------------------------------------
*
* @file       DevTests_Console.cpp
*
* @class      DEVTESTS_CONSOLE
* @brief      Developed tests console class
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @cond
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
* documentation files(the "Software"), to deal in the Software without restriction, including without limitation
* the rights to use, copy, modify, merge, publish, distribute, sublicense, and/ or sell copies of the Software,
* and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies or substantial portions of
* the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
* THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* @endcond
*
* --------------------------------------------------------------------------------------------------------------------*/
/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Defines.h"


/*---- INCLUDES ------------------------------------------------------------------------------------------------------*/

#include "DevTests_Console.h"

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

#include "VersionFrameWork.h"

#include "XFactory.h"
#include "XPath.h"
#include "XDateTime.h"
#include "XTimer.h"
#include "XDir.h"
#include "XRand.h"
#include "XVector.h"
//#include "XVectorSTL.h"
#include "XString.h"
#include "XSystem.h"
#include "XLog.h"
#include "XConsole.h"
#include "XFileTXT.h"
#include "XFileCSV.h"
#include "XFileXML.h"
#include "XFileRIFF.h"
#include "XFileDFU.h"
#include "XFileZIP.h"
#include "XVariant.h"
#include "XTranslation.h"
#include "XTranslation_GEN.h"
#include "XLanguage_ISO_639_3.h"
#include "XScheduler.h"
#include "XScheduler_XEvent.h"
#include "XThread.h"
#include "XTrace.h"
#include "XTraceServer.h"
#include "XObserver.h"
#include "XSharedMemoryManager.h"
#include "XProcessManager.h"
#include "XLicense.h"
#include "XOrderedList.h"
#include "XSerializable.h"

#include "HashMD5.h"
#include "HashSHA1.h"
#include "HashSHA2.h"
#include "HashWhirlpool.h"
#include "HashHMAC.h"
#include "CipherDES.h"
#include "Cipher3DES.h"
#include "CipherAES.h"
#include "CipherAESGCM.h"
#include "CipherBlowfish.h"
#include "CipherHKDF.h"
#include "CipherKeySymmetrical.h"
#include "CipherKeysFilePEM.h"
#include "CipherTrustedRootCertificatesX509.h"
#include "CipherCertificateX509Validator.h"
#include "CipherRSA.h"
#include "CipherECDSAX25519.h"
#include "DIOStreamTLS13KeySchedule.h"
#include "DIOStreamTLSRecord.h"
#include "DIOStreamTLSMessagesHandShakeServerFlight.h"
#include "DIOStreamTLS13Session.h"
#include "DIOStreamTLSSignature.h"
#include "DIOStreamTLS13HandshakeClient.h"
#include "DevTests_Console_TLS_RFC8448.h"

#include "CompressManager.h"

#include "DIOFactory.h"
#include "DIOStreamConfig.h"
#include "DIOStream.h"
#include "DIOStream_XEvent.h"
#include "DIOStreamDeviceIP.h"
#include "DIOStreamDeviceWifi.h"
#include "DIOStreamDeviceBluetooth.h"
#include "DIOStreamDeviceBluetoothLE.h"
#include "DIOStreamDeviceUSB.h"
#include "DIOStreamUARTConfig.h"
#include "DIOStreamUART.h"
#include "DIOStreamUSBLocalEnumDevices.h"
#include "DIOStreamUSBConfig.h"
#include "DIOStreamUSB.h"
#include "DIOStreamIPLocalEnumDevices.h"
#include "DIOStreamTCPIPConfig.h"
#include "DIOStreamTCPIP.h"
#include "DIOStreamUDPConfig.h"
#include "DIOStreamUDP.h"
#include "DIOStreamTCPIPServer.h"
#include "DIOStreamBluetoothLocalEnumDevices.h"
#include "DIOStreamBluetoothRemoteEnumDevices.h"
#include "DIOStreamBluetoothLERemoteEnumDevices.h"
#include "DIOStreamI2CConfig.h"
#include "DIOStreamI2C.h"
#include "DIOI2C_Devices.h"
#include "DIOStreamSPIConfig.h"
#include "DIOStreamSPI.h"
#include "DIOSPI_Devices.h"
#include "DIOStreamTLSConfig.h"
#include "DIOStreamTLS.h"
#include "DIONTP.h"
#include "DIOGPIO.h"
#include "DIOMPSSE.h"
#include "DIODNSProtocol_Client.h"
#include "DIODNSResolver.h"
#include "DIODNSProtocol_MitM_Server_XEvent.h"
#include "DIODNSProtocol_MitM_Server.h"
#include "DIOStreamWifiRemoteEnumDevices.h"
#include "DIOWakeOnLAN.h"
#include "DIONotificationsManager.h"
#include "DIOWebClient_XEvent.h"
#include "DIOWebClient.h"
#include "DIOCheckTCPIPConnections.h"
#include "DIOCheckInternetConnection.h"
#ifdef DIO_SCRAPERWEB_ACTIVE
#include "DIOScraperScript.h"
#endif
#ifdef DIO_SCRAPERWEB_GEOLOCATIONIP_ACTIVE
#include "DIOScraperWebGeolocationIP.h"
#endif
#ifdef DIO_SCRAPERWEB_PUBLICIP_ACTIVE
#include "DIOScraperWebPublicIP.h"
#endif
#ifdef DIO_SCRAPERWEB_WEATHER_ACTIVE
#include "DIOScraperWebWeather.h"
#endif
#ifdef DIO_SCRAPERWEB_TRANSLATION_ACTIVE
#include "DIOScraperWebTranslation.h"
#endif
#ifdef DIO_SCRAPERWEB_MACMANUFACTURER_ACTIVE
#include "DIOScraperWebMACManufacturer.h"
#endif

#ifdef DIO_SCRAPERWEB_USERAGENTID_ACTIVE
#include "DIOURL.h"
#include "DIOScraperWebUserAgentID.h"
#endif
#include "DIOWifiManagerMode.h"
#include "DIOATCMDS.h"
#include "DIOATCMDGSM.h"
#include "DIOSNMP.h"
#include "DIOLedNeoPixelWS2812B.h"
#include "DIOAlerts.h"
#include "DIODynDNS_Manager.h"
#include "DIOCoreProtocol_CFG.h"
#include "DIOCoreProtocol_Header.h"
#include "DIOCoreProtocol.h"
#include "DIOCoreProtocol_ConnectionsManager.h"

#ifdef SND_ACTIVE
#include "SNDFactory_XEvent.h"
#include "SNDItem.h"
#include "SNDFactory.h"
#endif

#include "INPFactory.h"
#include "INPSimulate.h"

#include "APPFlowLog.h"
#include "APPFlowCheckResourcesHardware_XEvent.h"
#include "APPFlowCheckResourcesHardware.h"
#include "APPFlowInternetServices.h"
#include "APPFlowAlerts.h"
#include "APPFlowExtended.h"
#include "APPFlowExtended_ApplicationStatus.h"
#include "APPFlowExtended_InternetStatus.h"

#include "XID_IBAN.h"

#ifdef WINDOWS
  #include "XWINDOWSAccessControlLists.h"
  #include "XWINDOWSRegistryManager.h"
  #include "XWINDOWSWinget.h"
  #include "DIOWINDOWSStreamWifiRemoteEnumDevices.h"     
  #include "DevTests_Console_WindowsPlatform.h"  
  #include "MainProcWINDOWS.h" 
#endif


#ifdef LINUX
  #include "DevTests_Console_LinuxPlatform.h"
  #include "INPLINUXDeviceID.h"
  #include "DIOLINUXDBus.h"
  #include "DIOLINUXNetworkManager.h"
#endif


#include "DevTests_Console_CFG.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/

APPLICATIONCREATEINSTANCE(DEVTESTS_CONSOLE, devtests_console)


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         DEVTESTS_CONSOLE::DEVTESTS_CONSOLE()
* @brief      Constructor of class.
* @ingroup    TESTS
*
* @return     Does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
DEVTESTS_CONSOLE::DEVTESTS_CONSOLE() : XFSMACHINE(0)
{
  Clean();
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         DEVTESTS_CONSOLE::~DEVTESTS_CONSOLE()
* @brief      Destructor of class.
* @ingroup    TESTS
*
* @return     Does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
DEVTESTS_CONSOLE::~DEVTESTS_CONSOLE()
{
  Clean();
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::IniFSMachine()
* @brief      Initializes the finite state machine.
* @ingroup    TESTS
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::IniFSMachine()
{
  if(!AddState( DEVTESTS_CONSOLE_XFSMSTATE_NONE            ,
                DEVTESTS_CONSOLE_XFSMEVENT_INI             , DEVTESTS_CONSOLE_XFSMSTATE_INI           ,
                DEVTESTS_CONSOLE_XFSMEVENT_END             , DEVTESTS_CONSOLE_XFSMSTATE_END           ,
                XFSMACHINESTATE_EVENTDEFEND)) return false;


  if(!AddState( DEVTESTS_CONSOLE_XFSMSTATE_INI             ,
                DEVTESTS_CONSOLE_XFSMEVENT_UPDATE          , DEVTESTS_CONSOLE_XFSMSTATE_UPDATE        ,
                DEVTESTS_CONSOLE_XFSMEVENT_END             , DEVTESTS_CONSOLE_XFSMSTATE_END           ,
                XFSMACHINESTATE_EVENTDEFEND)) return false;


  if(!AddState( DEVTESTS_CONSOLE_XFSMSTATE_UPDATE          ,
                DEVTESTS_CONSOLE_XFSMEVENT_NONE            , DEVTESTS_CONSOLE_XFSMSTATE_NONE          ,                
                DEVTESTS_CONSOLE_XFSMEVENT_END             , DEVTESTS_CONSOLE_XFSMSTATE_END           ,
                XFSMACHINESTATE_EVENTDEFEND)) return false;


  if(!AddState( DEVTESTS_CONSOLE_XFSMSTATE_END             ,
                DEVTESTS_CONSOLE_XFSMEVENT_NONE            , DEVTESTS_CONSOLE_XFSMSTATE_NONE          ,
                DEVTESTS_CONSOLE_XFSMEVENT_INI             , DEVTESTS_CONSOLE_XFSMSTATE_INI           ,
                XFSMACHINESTATE_EVENTDEFEND)) return false;

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::AppProc_PlatformIni()
* @brief      Initializes platform-specific resources.
* @ingroup    TESTS
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::AppProc_PlatformIni()
{
  //--------------------------------------------------------------------------------------
  
  #ifdef WINDOWS
  Windows_Platform_Ini();
  #endif  

  //--------------------------------------------------------------------------------------
  
  #ifdef LINUX
  Linux_Platform_Ini();    
  #endif  
    
  //--------------------------------------------------------------------------------------

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::AppProc_Ini()
* @brief      Initializes the application process.
* @ingroup    TESTS
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::AppProc_Ini()
{
  XSTRING string;
  XSTRING stringresult;
  XPATH   xpathsection;
  XPATH   xpath;
  bool    status = false;

  //-------------------------------------------------------------------------------------------------

  GEN_SET_VERSION(APPLICATION_NAMEAPP, APPLICATION_NAMEFILE, APPLICATION_VERSION, APPLICATION_SUBVERSION, APPLICATION_SUBVERSIONERR, APPLICATION_OWNER, APPLICATION_YEAROFCREATION)

  Application_GetName()->Set(APPLICATION_NAMEAPP);
  Application_GetExecutable()->Set(APPLICATION_NAMEFILE);

  //--------------------------------------------------------------------------------------------------

  //ACTIVATEXTHREADGROUP(XTHREADGROUPID_SCHEDULER);
  ACTIVATEXTHREADGROUP(XTHREADGROUPID_DIOSTREAM);
  //ACTIVATEXTHREADGROUP(XTHREADGROUPID_APPOWNER);

  //--------------------------------------------------------------------------------------------------

  GEN_XPATHSMANAGER.AdjustRootPathDefault(APPFLOW_DEFAULT_DIRECTORY_ROOT);

  GEN_XPATHSMANAGER.AddPathSection(XPATHSMANAGERSECTIONTYPE_GRAPHICS      , APPFLOW_DEFAULT_DIRECTORY_GRAPHICS);
  GEN_XPATHSMANAGER.AddPathSection(XPATHSMANAGERSECTIONTYPE_SOUNDS        , APPFLOW_DEFAULT_DIRECTORY_SOUNDS);
  GEN_XPATHSMANAGER.AddPathSection(XPATHSMANAGERSECTIONTYPE_DATABASES     , APPFLOW_DEFAULT_DIRECTORY_DATABASES);
  GEN_XPATHSMANAGER.AddPathSection(XPATHSMANAGERSECTIONTYPE_WEB           , APPFLOW_DEFAULT_DIRECTORY_WEB);
  GEN_XPATHSMANAGER.AddPathSection(XPATHSMANAGERSECTIONTYPE_FIRMWARE      , APPFLOW_DEFAULT_DIRECTORY_FIRMWARE);
  GEN_XPATHSMANAGER.AddPathSection(XPATHSMANAGERSECTIONTYPE_CERTIFICATES  , APPFLOW_DEFAULT_DIRECTORY_CERTIFICATES);
  GEN_XPATHSMANAGER.AddPathSection(XPATHSMANAGERSECTIONTYPE_SCRIPTS       , APPFLOW_DEFAULT_DIRECTORY_SCRIPTS);
  GEN_XPATHSMANAGER.AddPathSection(XPATHSMANAGERSECTIONTYPE_SCRAPERS      , APPFLOW_DEFAULT_DIRECTORY_SCRAPERS);

  GEN_XPATHSMANAGER.CreateAllPathSectionOnDisk();

  //--------------------------------------------------------------------------------------------------

  IniFSMachine();

  //--------------------------------------------------------------------------------------

  //Test_DIOWifiManagerMode(this);

  XTRACE_SETAPPLICATIONNAME((*Application_GetName()));
  XTRACE_SETAPPLICATIONVERSION(APPLICATION_VERSION, APPLICATION_SUBVERSION, APPLICATION_SUBVERSIONERR);
  XTRACE_SETAPPLICATIONID(string);
  //XTRACE_SETLOCALIPFILTER(172);

  APPFLOW_CFG_SETAUTOMATICTRACETARGETS

  //--------------------------------------------------------------------------------------

  /*
  GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpathsection);
  xpath.Create(3 , xpathsection.Get(), DEVTESTS_CONSOLE_LNG_NAMEFILE, XTRANSLATION_NAMEFILEEXT);

  if(!GEN_XTRANSLATION.Ini(xpath))
    {
      return false;
    }

  */

  GEN_XTRANSLATION.SetActual(XLANGUAGE_ISO_639_3_CODE_SPA); 

  //--------------------------------------------------------------------------------------

  APPFLOW_EXTENDED.APPStart(&APPFLOW_CFG, this);

  //--------------------------------------------------------------------------------------
  
  #ifdef SND_ACTIVE

  SubscribeEvent(SNDFACTORY_XEVENT_TYPE_SOUND_INI   , &GEN_SNDFACTORY.GetInstance());
  SubscribeEvent(SNDFACTORY_XEVENT_TYPE_SOUND_PLAY  , &GEN_SNDFACTORY.GetInstance());
  SubscribeEvent(SNDFACTORY_XEVENT_TYPE_SOUND_PAUSE , &GEN_SNDFACTORY.GetInstance());
  SubscribeEvent(SNDFACTORY_XEVENT_TYPE_SOUND_STOP  , &GEN_SNDFACTORY.GetInstance());
  SubscribeEvent(SNDFACTORY_XEVENT_TYPE_SOUND_END   , &GEN_SNDFACTORY.GetInstance());

  #endif

  //--------------------------------------------------------------------------------------


  SetEvent(DEVTESTS_CONSOLE_XFSMEVENT_INI);

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::AppProc_FirstUpdate()
* @brief      Executes the first application update.
* @ingroup    TESTS
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::AppProc_FirstUpdate()
{
  //--------------------------------------------------------------------------------------

  xtimerupdateconsole = GEN_XFACTORY.CreateTimer();
  if(!xtimerupdateconsole) return false;

  //--------------------------------------------------------------------------------------

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::AppProc_Update()
* @brief      Executes the application update cycle.
* @ingroup    TESTS
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::AppProc_Update()
{
  if(GetEvent()==DEVTESTS_CONSOLE_XFSMEVENT_NONE) // Not GEN_NEW event
    {
      switch(GetCurrentState())
        {
          case DEVTESTS_CONSOLE_XFSMSTATE_NONE         : break;

          case DEVTESTS_CONSOLE_XFSMSTATE_INI          : SetEvent(DEVTESTS_CONSOLE_XFSMEVENT_UPDATE);
                                                        break;

          case DEVTESTS_CONSOLE_XFSMSTATE_UPDATE       : switch(GetExitType())
                                                          { 
                                                            case APPFLOWBASE_EXITTYPE_BY_USER : SetEvent(DEVTESTS_CONSOLE_XFSMEVENT_END);
                                                                                                APPFLOW_EXTENDED.ShowAll();
                                                                                                break;

                                                            case APPFLOWBASE_EXITTYPE_UNKNOWN : if(xtimerupdateconsole)
                                                                                                  {
                                                                                                    if(xtimerupdateconsole->GetMeasureSeconds() >= 1)
                                                                                                      {
                                                                                                        APPFLOW_EXTENDED.ShowAll();

                                                                                                        xtimerupdateconsole->Reset();
                                                                                                      }
                                                    
                                                                                                    if(console->KBHit())
                                                                                                      {
                                                                                                        //XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[press key]"));

                                                                                                        int key = console->GetChar();
                                                                                                        KeyValidSecuences(key);
                                                                                                      }
                                                                       
                                                                                                    #ifdef DEVTESTS_CONSOLE_NOKEY
                                                                                                    {
                                                                                                      static bool nokey_tests_done = false;
                                                                                                      if(!nokey_tests_done)
                                                                                                        {
                                                                                                          nokey_tests_done = true;
                                                                                                          Do_Tests();
                                                                                                        }
                                                                                                    }
                                                                                                    #endif
                                                                                                  }                                                          
                                                                                                break;

                                                                                default       : break;                                                                                                                          
                                                            
                                                          }
                                                        break;

          case DEVTESTS_CONSOLE_XFSMSTATE_END          : break;

                                        default       : break;          

        }
    }
   else //  New event
    {
      if(GetEvent()<DEVTESTS_CONSOLE_LASTEVENT)
        {
          CheckTransition();

          switch(GetCurrentState())
            {
              case DEVTESTS_CONSOLE_XFSMSTATE_NONE     : break;
              
              case DEVTESTS_CONSOLE_XFSMSTATE_INI      : break;
              
              case DEVTESTS_CONSOLE_XFSMSTATE_UPDATE   : APPFLOW_EXTENDED.ShowAll();
                                                        break;
                                                        
              case DEVTESTS_CONSOLE_XFSMSTATE_END      : break;

                                        default       : break;
            }
        }
    }

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::AppProc_End()
* @brief      Ends the application process.
* @ingroup    TESTS
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::AppProc_End()
{
  XSTRING string;
  XSTRING stringresult;

  //--------------------------------------------------------------------------------------

  SetEvent(DEVTESTS_CONSOLE_XFSMEVENT_END);

  //--------------------------------------------------------------------------------------
  #ifdef SND_ACTIVE

  UnSubscribeEvent(SNDFACTORY_XEVENT_TYPE_SOUND_INI   , &GEN_SNDFACTORY.GetInstance());
  UnSubscribeEvent(SNDFACTORY_XEVENT_TYPE_SOUND_PLAY  , &GEN_SNDFACTORY.GetInstance());
  UnSubscribeEvent(SNDFACTORY_XEVENT_TYPE_SOUND_PAUSE , &GEN_SNDFACTORY.GetInstance());
  UnSubscribeEvent(SNDFACTORY_XEVENT_TYPE_SOUND_STOP  , &GEN_SNDFACTORY.GetInstance());
  UnSubscribeEvent(SNDFACTORY_XEVENT_TYPE_SOUND_END   , &GEN_SNDFACTORY.GetInstance());

  #endif


  //--------------------------------------------------------------------------------------

  if(xtimerupdateconsole)
    {
      GEN_XFACTORY.DeleteTimer(xtimerupdateconsole);
      xtimerupdateconsole = NULL;
    }

  //--------------------------------------------------------------------------------------

  APPFLOW_EXTENDED.APPEnd();
  APPFLOW_EXTENDED.DelInstance();  
  APPFLOW_CFG.DelInstance();

  //--------------------------------------------------------------------------------------

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::AppProc_PlatformEnd()
* @brief      Ends platform-specific resources.
* @ingroup    TESTS
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::AppProc_PlatformEnd()
{
  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::KeyValidSecuences(int key)
* @brief      Processes valid key sequences.
* @ingroup    TESTS
*
* @param[in]  key : key code to validate.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::KeyValidSecuences(int key)
{
  XCHAR character = (XCHAR)key;

  if((character<32) || (character>127)) character = _C('?');
  APPFLOW_LOG_ENTRY(XLOGLEVEL_WARNING, APPFLOW_CFG_LOG_SECTIONID_STATUSAPP, false, _L("Key pressed: 0x%02X [%c]"), key, character);

  console->Printf(_L("\r \r"));
  console->Printf(_L("\n"));

  switch(key)
    {
      case 0x1B : // ESC Exit application
                  SetExitType(APPFLOWBASE_EXITTYPE_BY_USER);
                  break;

      #ifndef DEVTESTS_CONSOLE_NOKEY
      
      case 'T'  : Do_Tests();
                  break;
      #endif                       
    }


  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Show_PlaySound()
* @brief      Shows the play sound test.
* @ingroup    TESTS
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Show_PlaySound()
{
  #ifdef SND_ACTIVE

  XTIMER* timer = NULL;
  timer = GEN_XFACTORY.CreateTimer();
  if(!timer) 
    {
      return false;
    }

  for(XDWORD c=0; c<GEN_SNDFACTORY.GetItems()->GetSize(); c++)
    {
      SNDITEM* item = GEN_SNDFACTORY.GetItems()->Get(c);
      if(item)
        {
          XSTRING typestr;  
          XSTRING statusstr;
          XSTRING ntimesstr;
          XSTRING measure;
          XSTRING resorcestr;
                        
          item->GetType(typestr);
          item->GetStatus(statusstr);

          if(item->GetNTimesToPlay() != SNDFACTORY_INLOOP)
            {
              ntimesstr.Format(_L("ntimes [%d of %d]"), (item->GetNTimesToPlay() - item->GetCounterPlay()), item->GetNTimesToPlay());
            }
           else
            {
              ntimesstr.Format(_L("ntimes [infinite]"));
            }   

          timer->Reset();
          timer->AddMilliSeconds(item->GetPlayingTime());
          timer->GetMeasureString(measure);

          resorcestr = item->GetID()->Get();       

          console->Printf(_L(" %02d %-10s %-10s %s %s [%s]\n"), c+1, typestr.Get(), statusstr.Get(), ntimesstr.Get(), measure.Get(), resorcestr.Get());                                       
        }       
    }

  console->Printf(_L("\n"));

  GEN_XFACTORY.DeleteTimer(timer);

  #endif

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Do_Tests()
* @brief      Runs the configured tests.
* @ingroup    TESTS
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Do_Tests()
{
  DEVTESTS_CONSOLE_LIST_FUNCTION listfunctions[] = {  { false  , Test_XString                       , _L("Test XString")                         },
                                                      { false  , Test_XBuffer                       , _L("Test XBuffer")                         },
                                                      { false  , Test_XVector                       , _L("Test XVector")                         },
                                                    //{ false  , Test_XVectorSTL                    , _L("Test XVector STL")                     },
                                                      { false  , Test_XRand                         , _L("Test_XRand")                           },
                                                      { false  , Test_XTrace                        , _L("Test XTrace")                          },
                                                      { false  , Test_XTraceServer                  , _L("Test XTraceServer")                    },
                                                      { false  , Test_XLogs                         , _L("Test XLogs")                           },
                                                      { false  , Test_XTimer                        , _L("Test XTimer")                          },
                                                      { false  , Test_XTree                         , _L("Test XTree")                           },
                                                      { false  , Test_XDir                          , _L("Test XDir")                            },
                                                      { false  , Test_XVariant                      , _L("Test XVariant")                        },
                                                      { false  , Test_Threads                       , _L("Test_Threads")                         },
                                                      { false  , Test_DateTime                      , _L("Test_DateTime")                        },                                                      
                                                      { false  , Test_DIOStreamTCPIPConnection      , _L("Test DIOStreamTCPIPConnection")        },
                                                      { false  , Test_XSystem                       , _L("Test System")                          },                                          
                                                      { false  , Test_SharedMemory                  , _L("Test SharedMemory")                    },
                                                      { false  , Test_GPIO                          , _L("Test GPIO")                            },
                                                      { false  , Test_WebClient                     , _L("Test WebClient")                       },
                                                      { false  , Test_MPSSE                         , _L("Test MPSSE")                           },
                                                      { true   , Test_ScraperWeb                    , _L("Test Scraper Script")                  },
                                                      { false  , Test_DNSResolver                   , _L("Test DNS Resolver")                    },
                                                      { false  , Test_DNSProtocolMitMServer         , _L("Test DNS Protocol MitM Server")        },
                                                      { false  , Test_DIOCheckTCPIPConnections      , _L("Test DIOCheckTCPIPConnections")        },
                                                      { false  , Test_WifiEnum                      , _L("Test Wifi Enum")                       },                                          
                                                      { false  , Test_WakeOnLAN                     , _L("Test Wake On LAN")                     }, 
                                                      { false  , Test_Hash                          , _L("Test Hash")                            },
                                                      { false  , Test_Cipher_Simetric               , _L("Test Cipher Simetric")                 }, 
                                                      { false  , Test_Cipher_HKDF                   , _L("Test Cipher HKDF")                     }, 
                                                      { false  , Test_Cipher_AESGCM                 , _L("Test Cipher AES GCM")                  }, 
                                                      { false  , Test_CipherFileKeys                , _L("Test Cipher File Keys")                },         
                                                      { false  , Test_CipherRSA                     , _L("Test Cipher RSA")                      },         
                                                      { false  , Test_CipherECDSAX25519             , _L("Test Cipher Curve 25519")              },         
                                                      { false  , Test_DIOStreamTCPIP                , _L("Test DIO Stream TCPIP")                },
                                                      { false  , Test_DIOStreamTLS_KeySchedule      , _L("Test DIO Stream TLS Key Schedule")     },
                                                      { false  , Test_DIOStreamTLS_Record           , _L("Test DIO Stream TLS Record")           },
                                                      { false  , Test_DIOStreamTLS                  , _L("Test DIO Stream TLS")                  },        
                                                      { false  , Test_SystemCPUUsage                , _L("Test System CPU Usage")                },         
                                                      { false  , Test_AppAlerts                     , _L("Test App Alerts")                      },  
                                                      { false  , Test_BluetoothEnum                 , _L("Test Bluetooth Enum")                  },                                          
                                                      { false  , Test_BluetoothLEEnum               , _L("Test Bluetooth LE Enum")               },                                          
                                                      { false  , Test_NTP_Protocol                  , _L("Test_NTP_Protocol")                    },                                              
                                                      { false  , Test_NTP_InternetServices          , _L("Test_NTP_InternetServices")            },                                              
                                                      { false  , Test_Sound                         , _L("Test Sound")                           },       
                                                      { false  , Test_ProcessManager                , _L("Test Process Manager")                 },
                                                      { false  , Test_GetUserAndDomain              , _L("Test Get User And Domain")             },
                                                      { false  , Test_I2C_GPIO_MCP2317              , _L("Test I2C GPIO MCP2317")                },
                                                      { false  , Test_SPI_GPIO_MCP2317              , _L("Test SPI GPIO MCP2317")                },
                                                      { false  , Test_WifiManagerMode               , _L("Test Wifi Manager Mode")               }, 
                                                      { false  , Test_NotificationsManager          , _L("Test Notifications Manager")           }, 
                                                      { false  , Test_ATCommandGSM                  , _L("Test AT Command GSM ")                 }, 
                                                      { false  , Test_SNMP                          , _L("Test SNMP ")                           },
                                                      { false  , Test_XFileJSON                     , _L("Test XFile JSON")                      },  
                                                      { false  , Test_XFileXML                      , _L("Test XFile XML")                       },  
                                                      { false  , Test_XFileRIFF                     , _L("Test XFile RIFF")                      },
                                                      { false  , Test_DIOStreamUSBConnection        , _L("Test DIOStreamConnection")             },
                                                      { false  , Test_XFileDFU                      , _L("Test XFile DFU")                       },
                                                      { false  , Test_SystemHostFile                , _L("Test System Host File")                },
                                                      { false  , Test_SystemBatteryLevel            , _L("Test System Battery Level")            },
                                                      { false  , Test_LedNeoPixelWS2812B            , _L("Test Led NeoPixel WS2812B")            }, 
                                                      { false  , Test_DIOPCap                       , _L("Test DIO PCap")                        },                                                      
                                                      { false  , Test_XLicense                      , _L("Test XLicense")                        },
                                                      { false  , Test_XSerializable                 , _L("Test XSerializable")                   },
                                                      { false  , Test_InputSimulate                 , _L("Test Input Simulate")                  },
                                                      { false  , Test_Scheduler                     , _L("Test Scheduler")                       },
                                                      { false  , Test_DynDNS                        , _L("Test DynDNS")                          }, 
                                                      { false  , Test_ID_IBAN                       , _L("Test XID IBAN")                        }, 
                                                      { false  , Test_Compress                      , _L("Test Compress")                        }, 
                                                      { false  , Test_DIOStreamTCPIPServer          , _L("Test DIO Stream TCPIP Server")         },  
                                                      { false  , Test_XPath                         , _L("Test eXtended Path")                   },  
                                                      
                                                      #ifdef WINDOWS
                                                      { false  , Test_WindowsACL                    , _L("Test Windows ACL")                     },
                                                      { false  , Test_WindowsRegistry               , _L("Test Windows Registry")                },                                                              
                                                      { false  , Test_WindowsWinget                 , _L("Test Windows WinGet")                  },                                                              
                                                      #endif

                                                      #ifdef LINUX
                                                      { false  , Test_DBUS                          , _L("Test DBUS")                            },
                                                      { false  , Test_NetWorkManager                , _L("Test Network Manager")                 },
                                                      { false  , Test_DeviceBusInputFile            , _L("Test Device Bus Input File")           },
                                                      #endif                                          
                                                  };

  bool status = false;
  
  for(int c=0; c<(sizeof(listfunctions)/sizeof(DEVTESTS_CONSOLE_LIST_FUNCTION)); c++)
    {
       if(listfunctions[c].active)
         {
           status = listfunctions[c].function(this);

           devtests_console->console->Printf(_L("\n"));
           devtests_console->console->Printf(_L(" [%02d] Test %-32s : %s \n"), c, listfunctions[c].namefunction, (status?_L("Ok."):_L("Error!")));
         }
    }

  //--------------------------------------------------------------------------------------------------

  console->PrintMessage(_L(" "), 0, false, true);

  #ifndef DEVTESTS_CONSOLE_NOKEY
  console->WaitKey(_L(" Pulsa una tecla para continuar... (%d)"), 1, false, 30);
  #else
  SetExitType(APPFLOWBASE_EXITTYPE_BY_USER);
  #endif
  
  //--------------------------------------------------------------------------------------------------

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Params_IsModeServer()
* @brief      Checks if the application parameters enable server mode.
* @ingroup    TESTS
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Params_IsModeServer()
{
  bool modeserver = false;

  if(devtests_console->GetExecParams())
    {
      XSTRING* param = (XSTRING*)devtests_console->GetExecParams()->Get(0);
      if(param)
        {
          if(!param->Compare(_L("SERVER"), true))
            {
              modeserver = true;
            }
        }
    }

  return modeserver;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XString(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xstring test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XString(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  XSTRING string;
  XSTRING substring;

  string = _L("hola radiola");
  string += _L(" mas... ");

  int index = string.Find(_L("mas"), true);
  if(index == XSTRING_NOTFOUND) return false;

  XBUFFER charstr;
  
  string.ConvertToASCII(charstr);
  printf("%s", charstr.GetPtrChar());

  substring.AdjustSize(32);

  string.Format(_L("esto es una prueba %d"), 10);
  string.UnFormat(_L("esto es una %s"), substring.Get());

  substring.AdjustSize();
  
  XVECTOR<XSTRING*> results;

  //string = _L("hola;Radiola;Prueba de example;mas");

  string = _L("[123|321][234|432][hola]");
  string.Split(_C('['), results, false);


  string.Format(_L("Pruebá de %3.2f%%"), 10.11f);
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, string.Get());


  XBUFFER xbuffer;

  string.ConvertToASCII(xbuffer, XSTRINGASCIICODE_CODEPAGE_437);
  substring.Empty();
  substring.ConvertFromASCII(xbuffer);

  string = _L("𠜎𠜱𠝹𠱓𠱸𠲖𠳏𠳕𠴕𠵼𠵿𠸎𠸏𠹷𠺝𠺢𠻗𠻹𠻺𠼭𠼮𠽌𠾴𠾼𠿪");
  substring.Empty();
  string.ConvertToUTF8(xbuffer, false);
  substring.ConvertFromUTF8(xbuffer);

  string = _L("แผ่นดินฮั่นเสื่อมโทรมแสนสังเวช");
  substring.Empty();
  string.ConvertToUTF16(xbuffer);  
  substring.ConvertFromXBuffer(xbuffer, XSTRINGCODING_UTF16);

  string = _L("ᚻᛖ ᚳᚹᚫᚦ ᚦᚫᛏ ᚻᛖ ᛒᚢᛞᛖ ᚩᚾ ᚦᚫᛗ ᛚᚪᚾᛞᛖ ᚾᚩᚱᚦᚹᛖᚪᚱᛞᚢᛗ ᚹᛁᚦ ᚦᚪ ᚹᛖᛥᚫ");
  substring.Empty();
  string.ConvertToUTF32(xbuffer);  
  substring.ConvertFromXBuffer(xbuffer, XSTRINGCODING_UTF32);
  
  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XBuffer(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xbuffer test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XBuffer(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  XBUFFER   buffer;
  XWORD     valueword  = 0;
  XDWORD    valuedword = 0;
  XVARIANT  variant;
  XSTRING   string;
 
  buffer.Resize(32);

  buffer.Set((XBYTE)0x01, 0);
  buffer.Set((XWORD)0x0203, 1);
  buffer.Set((XDWORD)0x55AA55AA, 3);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  buffer.SetWithMask(_L("D"), 3, 0xAAAAAAAA);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  buffer.InsertWithMask(_L("W"), 3, 0xCAFE);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  valueword = 0;
  buffer.GetWithMask(_L("W"), 3, &valueword);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  valueword  = 0;
  valuedword = 0;
  buffer.ExtractWithMask(_L("WD"), 3, &valueword, &valuedword);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  XBYTE array[8] = { 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08 };
  buffer.InsertWithMask(_L("A8"), 3, array);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  memset(array, 0, sizeof(array));
  buffer.InsertWithMask(_L("AX"), 3, array, sizeof(array));

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  memset(array, 0, sizeof(array));
  buffer.ExtractWithMask(_L("AX"), 3, array, sizeof(array));

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  variant = (XDWORD)10;
  buffer.InsertWithMask(_L("V"), 3, &variant);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  variant = (XDWORD)00;
  buffer.ExtractWithMask(_L("V"), 3, &variant);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  string = _L("hola radiola");
  buffer.InsertWithMask(_L("S"), 3, &string);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  string.Empty();
  buffer.ExtractWithMask(_L("S"), 3, &string);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);
  
  /*
  buffer.Bit_SetNBits(31);

  buffer.Bit_AddData(0xFFFFFFFF);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  buffer.Bit_AddData(0xFFFFFFFF);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  buffer.Bit_AddData(0xFFFFFFFF);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);

  XDWORD data = buffer.Bit_GetData(0);

  XTRACE_PRINTCOLOR(1, _L("%X"), data);

  data = 0xFFFF55AA;

  buffer.Bit_SetData(data, 0);

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, buffer, 1, 16);
  */

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XRand(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xrand test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XRand(DEVTESTS_CONSOLE* tests)
{
  GEN_XRAND.Ini();

  for(int c=0; c<10; c++)
    {
      int value = GEN_XRAND.Between(0, 10);
      XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("   [%2d] Random value: %d"), c, value);
    }

  for(int c=0; c<10; c++)
    {
      float value = ((float)GEN_XRAND.Between(0, 50) / (float)GEN_XRAND.Between(2, 9));
      XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("   [%2d] Random value: %f"), c, value);
    }

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XVector(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xvector test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XVector(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  /*
  XVECTOR<int>  vector;

  //vector.SetIsMulti(true);

  vector.Add(10);
  vector.Add(50);
  vector.Add(10);

  int number = vector.Get(1);

  vector.Delete(50);

  vector.DeleteAll();
  */

  XVECTOR<XSTRING*>  vector;

  for(int c=0; c<11; c++)
    {
      XSTRING* string = GEN_NEW XSTRING();
      if(string)
        {
          string->Set(_L("hola"));
        }

      vector.Add(string);
    }

  vector.DeleteContents();
  vector.DeleteAll();


  return true;
}


/*
bool DEVTESTS_CONSOLE::Test_XVectorSTL(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;
 
  XVECTORSTL<int>  vector;
 
  vector.Add(10);
  vector.Add(50);
  vector.Add(10);

  int number = vector.Get(1);

  vector.Delete(50);

  vector.DeleteAll();

  return true;
}
*/


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XTrace(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xtrace test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XTrace(DEVTESTS_CONSOLE* tests)
{
  XDWORD counter = 10;

  if(!tests->console) return false;

  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLACK, _L("[%d] Linea de DEBUG .... "), counter);
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[%d] Linea de DEBUG .... "), counter);
  XTRACE_PRINTCOLOR(XTRACE_COLOR_GREEN, _L("[%d] Linea de DEBUG .... "), counter);
  XTRACE_PRINTCOLOR(XTRACE_COLOR_PURPLE , _L("[%d] Linea de DEBUG .... "), counter);
  XTRACE_PRINTCOLOR(XTRACE_COLOR_RED, _L("[%d] Linea de DEBUG .... "), counter);
  XTRACE_PRINTCOLOR(XTRACE_COLOR_GRAY, _L("[%d] Linea de DEBUG .... "), counter);

  for(int c=0; c<5000; c++)
    {
      XTRACE_PRINTTAB(c, _L("[%d] Linea de DEBUG .... "), counter);
    }

  for(int c=0; c<5000; c++)
    {
      XTRACE_PRINTCODE(c, _L("[%d] Linea de DEBUG .... "), counter);
    }

  XBUFFER xbuffer;

  for(int c=0; c<1000; c++)
    {
      xbuffer.Add((XBYTE)0xFF);
    }

  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLACK  , xbuffer);
  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE   , xbuffer);
  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_GREEN  , xbuffer);
  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_PURPLE , xbuffer);
  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_RED    , xbuffer);
  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_GRAY   , xbuffer);


   for(int c=0; c<1000; c++)
    {
      XTRACE_PRINTDATABLOCKTAB(c, xbuffer);
    }

  for(int c=0; c<1000; c++)
    {
      XTRACE_PRINTDATABLOCKCODE(c, xbuffer);
    }

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XTraceServer(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xtraceserver UDP receive test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XTraceServer(DEVTESTS_CONSOLE* tests)
{
#if !(defined(DIO_ACTIVE) && defined(DIO_STREAMUDP_ACTIVE))
  if(tests && tests->console)
    {
      tests->console->Printf(_L("XTraceServer UDP not available in this build.\n"));
    }
  return false;
#else

  if(!tests) return false;
  if(!tests->console) return false;
  if(!XTRACE::instance) return false;

  const XWORD  serverport = 29101;
  XSTRING      marker1;
  XSTRING      marker2;
  XSTRING      address(_L("127.0.0.1"));
  bool         status = false;

  marker1.Format(_L("XTRACESERVER_TEST_MSG1_%d"), serverport);
  marker2.Format(_L("XTRACESERVER_TEST_MSG2_%d"), serverport);

  tests->console->Printf(_L(" XTraceServer listen *:%d ...\n"), serverport);

  XTRACESERVER traceserver;
  if(!traceserver.Ini(serverport))
    {
      tests->console->Printf(_L(" Error: Ini UDP server failed.\n"));
      return false;
    }

  if(!traceserver.IsOpenUDP())
    {
      tests->console->Printf(_L(" Error: server not open.\n"));
      traceserver.End();
      return false;
    }

  GEN_XSLEEP.MilliSeconds(50);

  DIOSTREAMUDPCONFIG  udpcfg;
  DIOSTREAMUDP*       udpclient = NULL;
  XDATETIME           xtime;
  XBUFFER             packet1;
  XBUFFER             packet2;

  udpcfg.SetMode(DIOSTREAMMODE_CLIENT);
  udpcfg.SetIsUsedDatagrams(true);
  udpcfg.GetRemoteURL()->Set(address);
  udpcfg.SetRemotePort(serverport);

  udpclient = (DIOSTREAMUDP*)GEN_DIOFACTORY.CreateStreamIO(&udpcfg);
  if(!udpclient || !udpclient->Open())
    {
      tests->console->Printf(_L(" Error: UDP client open failed.\n"));
      if(udpclient)
        {
          GEN_DIOFACTORY.DeleteStreamIO(udpclient);
        }
      traceserver.End();
      return false;
    }

  xtime.Read();

  if(!XTRACE::instance->SetTraceTextToXBuffer(0, 0x7F000001, XTRACE_COLOR_GREEN, 1, &xtime, marker1.Get(), packet1))
    {
      tests->console->Printf(_L(" Error: build packet 1 failed.\n"));
      udpclient->Close();
      GEN_DIOFACTORY.DeleteStreamIO(udpclient);
      traceserver.End();
      return false;
    }

  if(!XTRACE::instance->SetTraceTextToXBuffer(0, 0x7F000001, XTRACE_COLOR_BLUE, 2, &xtime, marker2.Get(), packet2))
    {
      tests->console->Printf(_L(" Error: build packet 2 failed.\n"));
      udpclient->Close();
      GEN_DIOFACTORY.DeleteStreamIO(udpclient);
      traceserver.End();
      return false;
    }

  if(!udpclient->WriteDatagram(address, serverport, packet1))
    {
      tests->console->Printf(_L(" Error: send packet 1 failed.\n"));
      udpclient->Close();
      GEN_DIOFACTORY.DeleteStreamIO(udpclient);
      traceserver.End();
      return false;
    }

  if(!udpclient->WriteDatagram(address, serverport, packet2))
    {
      tests->console->Printf(_L(" Error: send packet 2 failed.\n"));
      udpclient->Close();
      GEN_DIOFACTORY.DeleteStreamIO(udpclient);
      traceserver.End();
      return false;
    }

  udpclient->WaitToWriteDatagramsEmpty(1000);
  GEN_XSLEEP.MilliSeconds(100);

  XTRACESERVER_MSG msg1;
  XTRACESERVER_MSG msg2;

  if(!traceserver.WaitPop(msg1, 3000))
    {
      tests->console->Printf(_L(" Error: timeout waiting message 1 (count=%d dropped=%d).\n"), traceserver.GetCount(), traceserver.GetDroppedCount());
      udpclient->Close();
      GEN_DIOFACTORY.DeleteStreamIO(udpclient);
      traceserver.End();
      return false;
    }

  if(!traceserver.WaitPop(msg2, 3000))
    {
      tests->console->Printf(_L(" Error: timeout waiting message 2 (count=%d dropped=%d).\n"), traceserver.GetCount(), traceserver.GetDroppedCount());
      udpclient->Close();
      GEN_DIOFACTORY.DeleteStreamIO(udpclient);
      traceserver.End();
      return false;
    }

  tests->console->Printf(_L(" Recv1 seq=%d text=[%s]\n"), msg1.sequence, msg1.text.Get());
  tests->console->Printf(_L(" Recv2 seq=%d text=[%s]\n"), msg2.sequence, msg2.text.Get());

  status = true;

  if(msg1.text.Find(marker1.Get(), true) == XSTRING_NOTFOUND)
    {
      tests->console->Printf(_L(" Error: marker1 not found in message 1.\n"));
      status = false;
    }

  if(msg2.text.Find(marker2.Get(), true) == XSTRING_NOTFOUND)
    {
      tests->console->Printf(_L(" Error: marker2 not found in message 2.\n"));
      status = false;
    }

  if(msg1.sequence != 1)
    {
      tests->console->Printf(_L(" Error: unexpected sequence 1 (%d).\n"), msg1.sequence);
      status = false;
    }

  if(msg2.sequence != 2)
    {
      tests->console->Printf(_L(" Error: unexpected sequence 2 (%d).\n"), msg2.sequence);
      status = false;
    }

  traceserver.Clear();
  if(traceserver.GetCount() != 0)
    {
      tests->console->Printf(_L(" Error: Clear left %d messages.\n"), traceserver.GetCount());
      status = false;
    }

  udpclient->Close();
  GEN_DIOFACTORY.DeleteStreamIO(udpclient);
  traceserver.End();

  if(status)
    {
      tests->console->Printf(_L(" XTraceServer UDP receive OK.\n"));
    }

  {
    FILE* result = fopen("xtraceserver_test_result.txt", "wt");
    if(result)
      {
        fprintf(result, "%s\n", status ? "OK" : "ERROR");
        if(status)
          {
            fprintf(result, "Recv1 seq=%u\n", (unsigned)msg1.sequence);
            fprintf(result, "Recv2 seq=%u\n", (unsigned)msg2.sequence);
          }
        fclose(result);
      }
  }

  return status;
#endif
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XLogs(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xlogs test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XLogs(DEVTESTS_CONSOLE* tests)
{
  if(!APPFLOW_CFG.Log_IsActive()) 
    {
      return false;
    }

  XBUFFER  xbuffer;
  XRAND*   xrand = GEN_XFACTORY.CreateRand();
  int      index = 0;

  if(!xrand) return false;

  xrand->Ini();

  for(int d=0; d<100; d++)
    {   
      int ndata = xrand->Between(16, 64);

      for(int c=0; c<100; c++)
        {         
          if(tests->console->KBHit()) break;
            
          xbuffer.Delete();         
          for(int e=0; e<ndata; e++)
            {
              xbuffer.Add((XBYTE)xrand->Max(255));
            }       

          APPFLOW_LOG_ENTRY(XLOGLEVEL_INFO, APPFLOW_CFG_LOG_SECTIONID_GENERIC, false, _L("%08d %s"), index, _L("Entrada en memoria del LOG"));          
          APPFLOW_LOG_ENTRY(XLOGLEVEL_INFO, APPFLOW_CFG_LOG_SECTIONID_GENERIC, false, xbuffer);

          index++;
        }     
    }

  GEN_XFACTORY.DeleteRand(xrand);

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XTimer(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xtimer test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XTimer(DEVTESTS_CONSOLE* tests)
{
  XTIMER* xtimer = GEN_XFACTORY.CreateTimer();
  
  XQWORD  timer_sec1 = 0;
  XQWORD  timer_sec2 = 0;
  XSTRING measure;

  xtimer->AddSeconds(100000000L);  
  timer_sec1 = xtimer->GetMeasureSeconds();

  xtimer->AddSeconds(750000L);
  timer_sec2 = xtimer->GetMeasureSeconds();

  if(xtimer)
    {   
      xtimer->GetMeasureString(measure, true);
    }

  GEN_XFACTORY.DeleteTimer(xtimer);
  xtimer = NULL;
  
  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XTree_AddChilds(XTREE_NODE_TEST* node, int nchild)
* @brief      Runs the xtree add childs test.
* @ingroup    TESTS
*
* @param[in,out]  node : tree node used by the operation.
* @param[in]  nchild : number of child nodes to add.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XTree_AddChilds(XTREE_NODE_TEST* node, int nchild)
{
  bool status = true;

  for(int c=0; c<nchild; c++)
    {
      XSTRING* subnodedata = GEN_NEW XSTRING();
      if(subnodedata)
        {
          subnodedata->Format(_L("%2d Child"), c+1);

          XTREE_NODE_TEST* subnode = GEN_NEW XTREE_NODE_TEST(subnodedata);
          if(subnode)
            {
              node->AddChild(subnode);
            }
           else
            {
              status = false;
              break;
            }
        }
       else
        {
          status = false;
          break;
        }
    }

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XTree_InsertChilds(XTREE_NODE_TEST* node, int indexchild)
* @brief      Runs the xtree insert childs test.
* @ingroup    TESTS
*
* @param[in,out]  node : tree node used by the operation.
* @param[in]  indexchild : child index used by the insertion test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XTree_InsertChilds(XTREE_NODE_TEST* node, int indexchild)
{
  XSTRING* subnodedata = GEN_NEW XSTRING();
  if(!subnodedata) return false;

  subnodedata->Format(_L("%2d Insert Child"), indexchild);

  XTREE_NODE_TEST* subnode = GEN_NEW XTREE_NODE_TEST(subnodedata);
  if(subnode)
    {
      Test_XTree_AddChilds(subnode, 5);

      return node->InsertChild(indexchild, subnode);
    }

  return false;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XTree(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xtree test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XTree(DEVTESTS_CONSOLE* tests)
{
  XTREE_TEST        xtree;
  XSTRING*          rootdata  = NULL;
  XTREE_NODE_TEST*  root      = NULL;

  rootdata = GEN_NEW XSTRING();
  if(!rootdata) return false;

  rootdata->Set("Root");

  root = GEN_NEW XTREE_NODE_TEST(rootdata);
  if(!root)
    {
      GEN_DELETE rootdata;
      return false;
    }

  tests->Test_XTree_AddChilds(root, 3);

  for(int c=0; c<root->GetNChildren(); c++)
    {
      XTREE_NODE_TEST* subnode = root->GetChild(c);
      if(subnode)
        {
          tests->Test_XTree_AddChilds(subnode, 2);

          for(int d=0; d<subnode->GetNChildren(); d++)
            {
              XTREE_NODE_TEST* subnode2 = subnode->GetChild(d);
              if(subnode2)
                {
                  if((c == 2) && (d == 0))
                        tests->Test_XTree_InsertChilds(subnode, 1);
                   else tests->Test_XTree_AddChilds(subnode2, 1);
                }
            }
        }
    }

  xtree.SetRoot(root);

  //--------------------------------------------------------
  // Show content

  XTREE_NODE_ITERATOR_TEST  it(xtree.Begin());
  XTREE_NODE_ITERATOR_TEST  it_end(xtree.End());

  while(it != it_end)
    {
      XTREE_NODE_TEST*  node   = it.GetCurrent();
      XSTRING           string;
      if(node)
        {
          if(node->GetLevel())
            {
              XSTRING tabsstr;

              tabsstr.Empty();
              for(int c=0; c<node->GetLevel()-1; c++)
                {
                  tabsstr.Add(_L(" "));
                }

              string.Format(_L("%s|- [%02d]"), tabsstr.Get(), node->GetLevel());
            }

          string.AddFormat(_L("%s"), (*it)->Get());

          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("%s"), string.Get());          
        }

      ++it;
    }

  //--------------------------------------------------------
  // Delete all

  xtree.DeleteContents();
  xtree.DeleteAll();

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XDir(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xdir test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XDir(DEVTESTS_CONSOLE* tests)
{
  XDIR* xdir = GEN_XFACTORY.Create_Dir();
  if(!xdir) return false;

  XPATH         xpath;
  XDIRELEMENT   element;

  xdir->GetActual(xpath);

  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("Current DIR: [%s]"), xpath.Get());

  GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpath);
  xpath.Slash_Add();
      
  if(xdir->FirstSearch(xpath.Get(), _L("*"), &element))
    {
      do{ XSTRING datetimestr;
              
          element.GetDateTimeFile_LastAccess()->GetDateTimeToString((XDATETIME_FORMAT_ADDDATE | XDATETIME_FORMAT_ADDTIME | XDATETIME_FORMAT_TIMEWITHSECONDS | XDATETIME_FORMAT_TEXTMONTH), datetimestr);

          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("Elements DIR: [%s] %s"), element.GetNameFile()->Get(), datetimestr.Get());
           
        } while(xdir->NextSearch(&element));
    }            
    

  GEN_XFACTORY.Delete_Dir(xdir);

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XVariant(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xvariant test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XVariant(DEVTESTS_CONSOLE* tests)
{
  XVARIANT variant;
  XBUFFER  buffer;
  XSTRING  string;

  buffer.Add((XBYTE)0xAA);
  buffer.Add((XBYTE)0x55);
  buffer.Add((XBYTE)0xCA);
  buffer.Add((XBYTE)0xFE);
  
  variant = buffer;

  variant.ToString(string);

  buffer.Empty();
  buffer.ConvertFromBase64(string);

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_Threads(DEVTESTS_CONSOLE* tests)
* @brief      Runs the threads test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_Threads(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  DEVTESTS_CONSOLE_XTHREADPARAM listthread[DEVTESTS_CONSOLE_MAXNTHREADS];
  XTHREADCOLLECTED*            threads[DEVTESTS_CONSOLE_MAXNTHREADS];

  memset(listthread , 0, DEVTESTS_CONSOLE_MAXNTHREADS * sizeof(DEVTESTS_CONSOLE_XTHREADPARAM));
  memset(threads, 0, DEVTESTS_CONSOLE_MAXNTHREADS * sizeof(XTHREADCOLLECTED*));

  tests->xmutexthread = GEN_XFACTORY.Create_Mutex();
  if(!tests->xmutexthread) return false;

  for(int c=0; c<DEVTESTS_CONSOLE_MAXNTHREADS; c++)
    {
      threads[c] = CREATEXTHREAD(XTHREADGROUPID_APPOWNER, _L("DEVTESTS_CONSOLE::Test_Threads"), ThreadRunFunction, (void*)&listthread[c]);
      if(!threads[c]) return false;    

      listthread[c].index           = c;
      listthread[c].thread          = threads[c];
      listthread[c].devtest_console  = tests;

      switch(c)
        {        
          case 0  : threads[c]->SetPriority(XTHREADPRIORITY_LOW);       break;
          case 1  : threads[c]->SetPriority(XTHREADPRIORITY_LOW);       break;
          case 2  : threads[c]->SetPriority(XTHREADPRIORITY_LOW);       break;
          case 3  : threads[c]->SetPriority(XTHREADPRIORITY_REALTIME);  break;
          case 4  : threads[c]->SetPriority(XTHREADPRIORITY_LOW);       break;
          default : break;
        }

      threads[c]->Ini();      
    }

  GEN_XSLEEP.Seconds(5);

  for(int c=0; c<DEVTESTS_CONSOLE_MAXNTHREADS; c++)
    {
      DELETEXTHREAD(XTHREADGROUPID_APPOWNER, threads[c]);
    }

  GEN_XFACTORY.Delete_Mutex(tests->xmutexthread);  

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DateTime(DEVTESTS_CONSOLE* tests)
* @brief      Runs the date time test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DateTime(DEVTESTS_CONSOLE* tests)
{  
  XSTRING     datetimestring;
  XSTRING     dayofweek;
  XDATETIME*  datetime = GEN_XFACTORY.CreateDateTime();
  if(!datetime) return false;

  // --- Local Date --------------------------------------------------------------------    

  XSTRING function =  GEN_FUNCTION_EXEC;
  XSTRING module   =  GEN_MODULE_EXEC;
  int     line     =  GEN_LINE_EXEC;


  datetime->Read();

  datetime->GetDateTimeToString(XDATETIME_FORMAT_STANDARD, datetimestring);

  datetime->GetDayOfWeekString(dayofweek);

  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[DateTime] Date %s [%s] Number of Week %d, Number of Day: %d"), datetimestring.Get(), dayofweek.Get(), datetime->GetWeekOfYear(), datetime->GetDayOfYear());
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[DateTime] Date EPOCH: %d"), datetime->GetEPOCHFormat());

  // --- UTC Date -----------------------------------------------------------------------    
  
  datetime->Read(false);

  datetime->GetDateTimeToStringISO8601(XDATETIME_FORMAT_ISO8601_STANDARD, datetimestring);  
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[DateTime] Date ISO8601 (UTC) %s"), datetimestring.Get());
  
  datetime->GetDateTimeToStringISO8601(XDATETIME_FORMAT_ISO8601_STANDARD | XDATETIME_FORMAT_ISO8601_ADDHOUROFFSET, datetimestring);  
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[DateTime] Date ISO8601 (UTC + Offset) %s"), datetimestring.Get());

  // --- File Date ----------------------------------------------------------------------    

  XPATH xpath;

  GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpath);
  xpath.Slash_Add();
  xpath.Add(APPLICATION_NAMEFILE);
  xpath.Add(XFILECFG_EXTENSIONFILE);

  datetime->GetFileDateTime(xpath);
  datetime->GetDateTimeToString(XDATETIME_FORMAT_STANDARD, datetimestring);
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[DateTime] Date %s:%d of the file %s"), datetimestring.Get(), datetime->GetMilliSeconds(), xpath.Get());

  GEN_XFACTORY.DeleteDateTime(datetime);

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOStreamTCPIPConnection(DEVTESTS_CONSOLE* tests)
* @brief      Runs the diostream tcpipconnection test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOStreamTCPIPConnection(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  DIOSTREAMTCPIPCONFIG diostreamcfg;
  DIOSTREAM*           diostream    = NULL;
  bool                 status       = false;

  diostreamcfg.SetMode(DIOSTREAMMODE_SERVER);
  diostreamcfg.SetRemotePort(23);

  tests->console->Printf(_L("\n\nAbriendo servidor local %s : %d\n\n"), diostreamcfg.GetLocalIP()->Get(), diostreamcfg.GetRemotePort());

  diostream = (DIOSTREAM*)GEN_DIOFACTORY.CreateStreamIO(&diostreamcfg);
  if(diostream)
    {
      int c=0;
      while(!tests->console->KBHit())
        {
          if(diostream->Open())
            {
              status = diostream->WaitToConnected(1);

              tests->console->Printf(_L("\r\nConexion %d estado: %s"), c, status?_L("Connected. "):_L("Waiting... "));

              while(diostream->GetStatus()==DIOSTREAMSTATUS_CONNECTED)
                {
                  tests->console->Printf    (_L("\r\n Sending packet(%d)"), c++);

                  diostream->WriteStr (_L("Hello Jello!\r\n"));
                  diostream->WaitToFlushOutXBuffer();
                }

              if(diostream->GetStatus() !=  DIOSTREAMSTATUS_GETTINGCONNECTION) tests->console->Printf(_L("\r\nConexion %d estado: Disconnected"), c);

              diostream->Close();
              c=0;

              status = true;
            }
        }

      DIOFACTORY::GetInstance().DeleteStreamIO(diostream);
    }

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XSystem(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xsystem test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XSystem(DEVTESTS_CONSOLE* tests)
{
  XSTRING   plataform_name;
  XSTRING   OS_ID;
  XSTRING*  BIOSserialnumber;
  XSTRING*  CPUserialnumber;

  GEN_XSYSTEM.GetPlatform(&plataform_name);
  GEN_XSYSTEM.GetOperativeSystemID(OS_ID);

  BIOSserialnumber = GEN_XSYSTEM.GetBIOSSerialNumber();
  CPUserialnumber  = GEN_XSYSTEM.GetCPUSerialNumber();

  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("   Plataform                :  %s"), plataform_name.Get());
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("   Operative System Version :  %s"), OS_ID.Get());

  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("   BIOS serial number       :  %s"), BIOSserialnumber->Get());
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("   CPU serial number        :  %s"), CPUserialnumber->Get());
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("   CPU temperature          :  %3.2f Cº"), GEN_XSYSTEM.GetCPUTemperature());

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_SharedMemory(DEVTESTS_CONSOLE* tests)
* @brief      Runs the shared memory test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_SharedMemory(DEVTESTS_CONSOLE* tests)
{
  #define SHAREDMEMORYID _L("SharedMemoryID")

  if(!tests->console) return false;

  bool modeserver = tests->Params_IsModeServer();

  tests->console->Printf(_L(" Creating Shared Memory: %s \n"), (modeserver?_L("[Master]"):_L("[Slave]")));
  
  XBYTE*    pointer = NULL;
  XDWORD    size    = 0;
  XDWORD*   data    = 0;
  bool      status  = true;
  bool      exit    = false;

  if(modeserver)
    {
      size = 32;
      pointer = GEN_XSHAREDMEMORYMANAGER.Create(SHAREDMEMORYID, size);
    }
   else 
    {
      pointer = GEN_XSHAREDMEMORYMANAGER.Open(SHAREDMEMORYID, size);
    }

  tests->console->Printf(_L(" Create Shared Memory %d bytes: %s\n"), size, pointer?_L("Ok"):_L("Error!"));

  data = (XDWORD*)pointer;

  XRAND* xrand = GEN_XFACTORY.CreateRand();
  if(xrand)
    {
      if(pointer)
        {
          status = true;  
          
          do{
              if(tests->console->KBHit())
                {
                  switch(tests->console->GetChar())
                    {
                     case 0x1B : 
                                  #ifdef DEVTESTS_CONSOLE_NOKEY
                                  tests->SetExitType(APPFLOWBASE_EXITTYPE_BY_USER);     
                                  #endif
                                  exit = true;
                                  break;

                        default : (*data) = (XDWORD)xrand->Max(100000000);              
                                  break;
                    }
                }

              tests->console->Printf(_L(" Data Shared Memory: %04X \r"), (*data));

            } while(!exit);

          GEN_XSHAREDMEMORYMANAGER.Close();
        }
       else 
        { 
          status = false;
        }

      GEN_XFACTORY.DeleteRand(xrand);
    }

  
  tests->console->Printf(_L("\n Delete Shared Memory: Ok\n"));

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_GPIO(DEVTESTS_CONSOLE* tests)
* @brief      Runs the gpio test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_GPIO(DEVTESTS_CONSOLE* tests)
{   
  bool status = false;  

  #ifdef DIOGPIO_ACTIVE
  
  GEN_DIOGPIO.SetMode(DEVTESTS_CONSOLE_GPIOENTRYID_TESTGPIO, DIOGPIO_MODE_OUTPUT);
         
  while(!tests->console->KBHit())
    {
      GEN_DIOGPIO.SetValue(DEVTESTS_CONSOLE_GPIOENTRYID_TESTGPIO, true);
      GEN_XSLEEP.MilliSeconds(50);
             
      GEN_DIOGPIO.SetValue(DEVTESTS_CONSOLE_GPIOENTRYID_TESTGPIO, false);
      GEN_XSLEEP.MilliSeconds(50);
    }
          
  status = true;

  #endif

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_WebClient(DEVTESTS_CONSOLE* tests)
* @brief      Runs the web client test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_WebClient(DEVTESTS_CONSOLE* tests)
{
  DIOWEBCLIENT  webclient;
  DIOURL        url;
  XBUFFER       webpage;
  bool          status = true;

  tests->SubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_OPENWEB, &webclient);
  tests->SubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_WRITEHEADER, &webclient);
  tests->SubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_SENDPOSTDATA, &webclient);
  tests->SubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_HEADERERROR, &webclient);
  tests->SubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_READHEADER, &webclient);
  tests->SubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_READBODYBLOCK, &webclient);
  tests->SubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_CLOSEWEB, &webclient);

  url = _L("http://example.com/");
  status = webclient.Get(url, webpage, NULL, 30) &&
           (webclient.GetHeader()->GetResultServer() == 200) && !webpage.IsEmpty();
  XTRACE_PRINTCOLOR((status?1:4), _L("GET Web Client HTTP: %s"), status?_L("Ok!"):_L("Error!"));

  #ifdef DIO_STREAMTLS_ACTIVE

  if(status)
    {
      url = _L("https://example.com/");
      status = webclient.Get(url, webpage, NULL, 30) &&
               (webclient.GetHeader()->GetResultServer() == 200) && !webpage.IsEmpty();
      XTRACE_PRINTCOLOR((status?1:4), _L("GET Web Client HTTPS example.com: %s"), status?_L("Ok!"):_L("Error!"));
    }

  if(status)
    {
      bool getstatus;
      int  resultserver;

      url          = _L("www.genframework.com/assets/document/Introduccion_a_GEN_Framework.pdf");
      getstatus    = webclient.Get(url, webpage, NULL, 30);
      resultserver = webclient.GetHeader()->GetResultServer();
      status       = getstatus && (resultserver == 200) && !webpage.IsEmpty();

      XTRACE_PRINTCOLOR((status?1:4), _L("GET Web Client HTTPS www.genframework.com [GET: %s, HTTP: %d, size: %d]: %s"), getstatus?_L("Ok"):_L("Error"), resultserver, webpage.GetSize(), status?_L("Ok!"):_L("Error!"));
    }

 if(status)
    {
      bool getstatus;
      int  resultserver;

      url          = _L("https://www.google.com/");
      getstatus    = webclient.Get(url, webpage, NULL, 30);
      resultserver = webclient.GetHeader()->GetResultServer();
      status       = getstatus && (resultserver == 200) && !webpage.IsEmpty();

      XTRACE_PRINTCOLOR((status?1:4), _L("GET Web Client HTTPS www.google.com [GET: %s, HTTP: %d, size: %d]: %s"), getstatus?_L("Ok"):_L("Error"), resultserver, webpage.GetSize(), status?_L("Ok!"):_L("Error!"));
    }

  if(status)
    {
      url = _L("http://example.com/");
      status = webclient.Get(url, webpage, NULL, 30) &&
               (webclient.GetHeader()->GetResultServer() == 200) && !webpage.IsEmpty();
      XTRACE_PRINTCOLOR((status?1:4), _L("GET Web Client HTTP after HTTPS: %s"), status?_L("Ok!"):_L("Error!"));
    }

  #endif

  tests->UnSubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_OPENWEB, &webclient);
  tests->UnSubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_WRITEHEADER, &webclient);
  tests->UnSubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_SENDPOSTDATA, &webclient);
  tests->UnSubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_HEADERERROR, &webclient);
  tests->UnSubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_READHEADER, &webclient);
  tests->UnSubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_READBODYBLOCK, &webclient);
  tests->UnSubscribeEvent(DIOWEBCLIENT_XEVENT_TYPE_CLOSEWEB, &webclient);


  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_ScraperWeb(DEVTESTS_CONSOLE* tests)
* @brief      Dev test for typed scraper facades filled by scripts (PublicIP + Geo + Weather + Translation + MAC + UA).
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if enabled scraper probes succeed.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_ScraperWeb(DEVTESTS_CONSOLE* tests)
{
  #ifndef DIO_SCRAPERWEB_ACTIVE
  tests->console->Printf(_L("Scrapers features not active.\n"));
  return false;
  #else

  #ifndef SCRIPT_ACTIVE
  tests->console->Printf(_L("SCRIPT_ACTIVE missing (reconfigure CMake after scraper features).\n"));
  return false;
  #endif

  #ifdef DIO_SCRAPERWEB_PUBLICIP_ACTIVE
  DIOSCRAPERWEBPUBLICIP*          publicip              = GEN_NEW DIOSCRAPERWEBPUBLICIP();
  XCHAR*                          publicpaths[]         = { 
                                                            #ifdef SCRIPT_G_ACTIVE
                                                            _L("publicip.g")           , 
                                                            #endif    

                                                            #ifdef SCRIPT_JAVASCRIPT_ACTIVE
                                                            _L("publicip.js")          ,
                                                            #endif

                                                            #ifdef SCRIPT_LUA_ACTIVE      
                                                            _L("publicip.lua")         , 
                                                            #endif
                                                          };  
  const int                       npublic               =  (int)(sizeof(publicpaths) / sizeof(publicpaths[0]));
  #endif

  #ifdef DIO_SCRAPERWEB_GEOLOCATIONIP_ACTIVE
  DIOSCRAPERWEBGEOLOCATIONIP*     geolocationip         = GEN_NEW DIOSCRAPERWEBGEOLOCATIONIP();
  XCHAR*                          geopaths[]            = { 
                                                            #ifdef SCRIPT_G_ACTIVE
                                                            _L("geolocationip.g")      , 
                                                            #endif

                                                            #ifdef SCRIPT_JAVASCRIPT_ACTIVE
                                                            _L("geolocationip.js")     ,
                                                            #endif

                                                            #ifdef SCRIPT_LUA_ACTIVE
                                                            _L("geolocationip.lua")    ,
                                                            #endif
                                                          };
  const int                       ngeo                  =  (int)(sizeof(geopaths) / sizeof(geopaths[0]));  
  #endif    

  #ifdef DIO_SCRAPERWEB_WEATHER_ACTIVE
  DIOSCRAPERWEBWEATHER*           weather               = GEN_NEW DIOSCRAPERWEBWEATHER();
  XCHAR*                          weatherpaths[]        = { 
                                                             #ifdef SCRIPT_G_ACTIVE
                                                             _L("weather.g")           ,
                                                             #endif
                                
                                                             #ifdef SCRIPT_JAVASCRIPT_ACTIVE
                                                             _L("weather.js")          ,
                                                             #endif

                                                             #ifdef SCRIPT_LUA_ACTIVE
                                                             _L("weather.lua")         ,
                                                             #endif
                                                           };
  const int                       nweather              = (int)(sizeof(weatherpaths) / sizeof(weatherpaths[0]));
  #endif

  #ifdef DIO_SCRAPERWEB_TRANSLATION_ACTIVE
  DIOSCRAPERWEBTRANSLATION*       translation           = GEN_NEW DIOSCRAPERWEBTRANSLATION();
  XCHAR*                          translationpaths[]    = {
                                                             #ifdef SCRIPT_G_ACTIVE
                                                             _L("translation.g")       ,
                                                             #endif   

                                                             #ifdef SCRIPT_JAVASCRIPT_ACTIVE
                                                             _L("translation.js")      , 
                                                             #endif

                                                             #ifdef SCRIPT_LUA_ACTIVE
                                                             _L("translation.lua")     ,
                                                             #endif
                                                          };
  const int                       ntranslation          = (int)(sizeof(translationpaths) / sizeof(translationpaths[0]));
  #endif

  #ifdef DIO_SCRAPERWEB_MACMANUFACTURER_ACTIVE
  DIOSCRAPERWEBMACMANUFACTURER*   macmanufacturer       = GEN_NEW DIOSCRAPERWEBMACMANUFACTURER();
  XCHAR*                          macpaths[]            = { 
                                                            #ifdef SCRIPT_G_ACTIVE
                                                            _L("macmanufacturer.g")    ,
                                                            #endif
                 
                                                            #ifdef SCRIPT_JAVASCRIPT_ACTIVE
                                                            _L("macmanufacturer.js")   ,
                                                            #endif

                                                            #ifdef SCRIPT_LUA_ACTIVE
                                                            _L("macmanufacturer.lua")  ,
                                                            #endif
                                                          };
  const int                       nmac                  = (int)(sizeof(macpaths) / sizeof(macpaths[0]));
  #endif

  #ifdef DIO_SCRAPERWEB_USERAGENTID_ACTIVE
  DIOSCRAPERWEBUSERAGENTID*       useragentid           = GEN_NEW DIOSCRAPERWEBUSERAGENTID();
  XCHAR*                          uapaths[]             = {
                                                            #ifdef SCRIPT_G_ACTIVE
                                                            _L("useragentid.g")        ,
                                                            #endif

                                                            #ifdef SCRIPT_JAVASCRIPT_ACTIVE
                                                            _L("useragentid.js")       ,
                                                            #endif

                                                            #ifdef SCRIPT_LUA_ACTIVE
                                                            _L("useragentid.lua")      ,
                                                            #endif
                                                          };
  const int                       nua                   = (int)(sizeof(uapaths) / sizeof(uapaths[0]));
  #endif


  DIOIP                           ip;
  XSTRING                         ipstring;
  XPATH                           scriptspath;
  bool                            status                = true;
  const int                       timeout               = 15;


  if(
      #ifdef DIO_SCRAPERWEB_PUBLICIP_ACTIVE
      (!publicip) 
      #endif

      #ifdef DIO_SCRAPERWEB_GEOLOCATIONIP_ACTIVE
      || (!geolocationip)
      #endif  

      #ifdef DIO_SCRAPERWEB_WEATHER_ACTIVE
      || (!weather)
      #endif

      #ifdef DIO_SCRAPERWEB_TRANSLATION_ACTIVE
      || (!translation)
      #endif

      #ifdef DIO_SCRAPERWEB_MACMANUFACTURER_ACTIVE
      || (!macmanufacturer)
      #endif

      #ifdef DIO_SCRAPERWEB_USERAGENTID_ACTIVE
      || (!useragentid)
      #endif
    )
    {
      #ifdef DIO_SCRAPERWEB_PUBLICIP_ACTIVE
      GEN_DELETE publicip;
      #endif  

      #ifdef DIO_SCRAPERWEB_GEOLOCATIONIP_ACTIVE
      GEN_DELETE geolocationip;
      #endif  

      #ifdef DIO_SCRAPERWEB_WEATHER_ACTIVE
      GEN_DELETE weather;
      #endif

      #ifdef DIO_SCRAPERWEB_TRANSLATION_ACTIVE
      GEN_DELETE translation;
      #endif

      #ifdef DIO_SCRAPERWEB_MACMANUFACTURER_ACTIVE
      GEN_DELETE macmanufacturer;
      #endif

      #ifdef DIO_SCRAPERWEB_USERAGENTID_ACTIVE
      GEN_DELETE useragentid;
      #endif

      tests->console->Printf(_L("Scraper: allocation failed.\n"));
      return false;
    }

  GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_SCRAPERS, scriptspath);

  tests->console->Printf(_L("Scripts root : %s\n\n"), scriptspath.Get());

  tests->console->Printf(_L("--- Public IP (script probe per language) ---\n"));

  for(int c = 0; c < npublic; c++)
    {
      DIOSCRAPERSCRIPT runner;
      XSTRING          ok;
      XSTRING          runip;

      runner.SetArgInt(_L("timeout"), timeout);
      tests->console->Printf(_L("[%s] "), publicpaths[c]);
      if(!runner.Run(publicpaths[c]))
        {
          tests->console->Printf(_L("Run() failed.\n"));
          status = false;
        }
       else
        {
          runner.GetResult(_L("ok"), ok);
          runner.GetResult(_L("ip"), runip);
          tests->console->Printf(_L("ok=%s ip=%s\n"), ok.Get(), runip.Get());
          if(ok.Compare(_L("1")) != 0)
            {
              status = false;
            }
           else if(ipstring.IsEmpty())
            {
              ipstring = runip;
            }
        }
    }

  if(!ipstring.IsEmpty())
    {
      ip.Set(ipstring.Get());
    }

  tests->console->Printf(_L("\n--- Public IP (facade default .g) ---\n"));
  {
    DIOIP   facadeip;
    XSTRING facadeipstring;

    if(publicip->Get(facadeip, timeout, NULL, true))
      {
        facadeip.GetXString(facadeipstring);
        tests->console->Printf(_L("Public IP : %s\n"), facadeipstring.Get());
        if(ipstring.IsEmpty())
          {
            ipstring = facadeipstring;
            ip.Set(ipstring.Get());
          }
      }
     else
      {
        tests->console->Printf(_L("Public IP facade : Error.\n"));
        status = false;
      }
  }

  tests->console->Printf(_L("\n--- Geolocation IP (script probe per language) ---\n"));
  if(status && (!ipstring.IsEmpty()))
    {
      for(int c = 0; c < ngeo; c++)
        {
          DIOSCRAPERSCRIPT georunner;
          XSTRING          geook;
          XSTRING          geocountry;

          georunner.SetArg(_L("ip"), ipstring);
          georunner.SetArgInt(_L("timeout"), timeout);
          tests->console->Printf(_L("[%s] "), geopaths[c]);
          if(!georunner.Run(geopaths[c]))
            {
              tests->console->Printf(_L("Run() failed.\n"));
              status = false;
            }
           else
            {
              georunner.GetResult(_L("ok"), geook);
              georunner.GetResult(_L("country"), geocountry);
              tests->console->Printf(_L("ok=%s country=%s\n"), geook.Get(), geocountry.Get());
              if(geook.Compare(_L("1")) != 0)
                {
                  status = false;
                }
            }
        }

      DIOGEOLOCATIONIP_RESULT geoIP;

      tests->console->Printf(_L("\n--- Geolocation IP (facade default .g) ---\n"));
      if(geolocationip->Get(ip, geoIP, timeout, NULL, true))
        {
          tests->console->Printf(_L("Country      : %s\n"), geoIP.GetCountry());
          tests->console->Printf(_L("State        : %s\n"), geoIP.GetState());
          tests->console->Printf(_L("City         : %s\n"), geoIP.GetCity());
          tests->console->Printf(_L("ISP          : %s\n"), geoIP.GetISP());
          tests->console->Printf(_L("Organization : %s\n"), geoIP.GetOrganization());
          tests->console->Printf(_L("Latitude     : %f\n"), geoIP.GetLatitude());
          tests->console->Printf(_L("Longitude    : %f\n"), geoIP.GetLongitude());
        }
       else
        {
          tests->console->Printf(_L("Geolocation facade : Error.\n"));
          status = false;
        }
    }
   else if(status)
    {
      tests->console->Printf(_L("Geolocation skipped (no Public IP).\n"));
      status = false;
    }

  #ifdef DIO_SCRAPERWEB_WEATHER_ACTIVE
  tests->console->Printf(_L("\n--- Weather (script probe per language) ---\n"));
  {
    XSTRING location(_L("Bilbao"));

    for(int c = 0; c < nweather; c++)
      {
        DIOSCRAPERSCRIPT weatherrunner;
        XSTRING          weatherok;
        XSTRING          condition;
        XSTRING          temperature;

        weatherrunner.SetArg(_L("location"), location);
        weatherrunner.SetArgInt(_L("celsius"), 1);
        weatherrunner.SetArgInt(_L("timeout"), timeout);
        tests->console->Printf(_L("[%s] "), weatherpaths[c]);
        if(!weatherrunner.Run(weatherpaths[c]))
          {
            tests->console->Printf(_L("Run() failed.\n"));
            status = false;
          }
         else
          {
            weatherrunner.GetResult(_L("ok"), weatherok);
            weatherrunner.GetResult(_L("condition"), condition);
            weatherrunner.GetResult(_L("temperature"), temperature);
            tests->console->Printf(_L("ok=%s condition=%s temperature=%s\n"), weatherok.Get(), condition.Get(), temperature.Get());
            if(weatherok.Compare(_L("1")) != 0)
              {
                status = false;
              }
          }
      }

    DIOWEATHER_RESULT weatherresult;

    tests->console->Printf(_L("\n--- Weather (facade default .g) ---\n"));
    if(weather->Get(location, true, weatherresult, timeout, NULL, true))
      {
        tests->console->Printf(_L("Condition   : %s\n"), weatherresult.GetCondition());
        tests->console->Printf(_L("Temperature : %f\n"), weatherresult.GetTemperature());
        tests->console->Printf(_L("Humidity    : %f\n"), weatherresult.GetHumidity());
      }
     else
      {
        tests->console->Printf(_L("Weather facade : Error.\n"));
        status = false;
      }
  }
  #endif

  #ifdef DIO_SCRAPERWEB_TRANSLATION_ACTIVE
  tests->console->Printf(_L("\n--- Translation (script probe per language) ---\n"));
  {
    XSTRING text(_L("Hello %d world"));
    XSTRING sl(_L("auto"));
    XSTRING tl(_L("es"));

    for(int c = 0; c < ntranslation; c++)
      {
        DIOSCRAPERSCRIPT translationrunner;
        XSTRING          translationok;
        XSTRING          translated;

        translationrunner.SetArg(_L("text"), text);
        translationrunner.SetArg(_L("sl"), sl);
        translationrunner.SetArg(_L("tl"), tl);
        translationrunner.SetArgInt(_L("timeout"), timeout);
        tests->console->Printf(_L("[%s] "), translationpaths[c]);
        if(!translationrunner.Run(translationpaths[c]))
          {
            tests->console->Printf(_L("Run() failed.\n"));
            status = false;
          }
         else
          {
            translationrunner.GetResult(_L("ok"), translationok);
            translationrunner.GetResult(_L("translation"), translated);
            tests->console->Printf(_L("ok=%s translation=%s\n"), translationok.Get(), translated.Get());
            if(translationok.Compare(_L("1")) != 0)
              {
                status = false;
              }
          }
      }

    DIOTRANSLATION_RESULT translationresult;

    tests->console->Printf(_L("\n--- Translation (facade default .g) ---\n"));
    if(translation->Get(text, sl, tl, translationresult, timeout, NULL, true))
      {
        tests->console->Printf(_L("Source      : %s\n"), translationresult.GetSourceLanguage());
        tests->console->Printf(_L("Target      : %s\n"), translationresult.GetTargetLanguage());
        tests->console->Printf(_L("Text Target : %s\n"), text.Get());
        tests->console->Printf(_L("Translation : %s\n"), translationresult.GetTranslation());
      }
     else
      {
        tests->console->Printf(_L("Translation facade : Error.\n"));
        status = false;
      }
  }
  #endif

  #ifdef DIO_SCRAPERWEB_MACMANUFACTURER_ACTIVE
  tests->console->Printf(_L("\n--- MAC Manufacturer (script probe per language) ---\n"));
  {
    XSTRING mac(_L("00:1B:63:84:45:E6"));

    for(int c = 0; c < nmac; c++)
      {
        DIOSCRAPERSCRIPT macrunner;
        XSTRING          macok;
        XSTRING          manufacturer;

        macrunner.SetArg(_L("mac"), mac);
        macrunner.SetArgInt(_L("timeout"), timeout);
        tests->console->Printf(_L("[%s] "), macpaths[c]);
        if(!macrunner.Run(macpaths[c]))
          {
            tests->console->Printf(_L("Run() failed.\n"));
            status = false;
          }
         else
          {
            macrunner.GetResult(_L("ok"), macok);
            macrunner.GetResult(_L("manufacturer"), manufacturer);
            tests->console->Printf(_L("ok=%s manufacturer=%s\n"), macok.Get(), manufacturer.Get());
            if(macok.Compare(_L("1")) != 0)
              {
                status = false;
              }
          }
      }

    DIOMACMANUFACTURED_RESULT macresult;
    DIOMAC                    diomac;

    diomac.Set(mac);
    tests->console->Printf(_L("\n--- MAC Manufacturer (facade default .g) ---\n"));
    if(macmanufacturer->Get(diomac, macresult, timeout, NULL, true))
      {
        tests->console->Printf(_L("Manufacturer : %s\n"), macresult.GetManufacturer());
      }
     else
      {
        tests->console->Printf(_L("MAC Manufacturer facade : Error.\n"));
        status = false;
      }
  }
  #endif

  #ifdef DIO_SCRAPERWEB_USERAGENTID_ACTIVE
  tests->console->Printf(_L("\n--- User Agent ID (script probe per language) ---\n"));
  {
    XSTRING uaraw(_L("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"));
    DIOURL  uaencoded;

    uaencoded.EncodeUnsafeCharsFromString(uaraw);

    for(int c = 0; c < nua; c++)
      {
        DIOSCRAPERSCRIPT uarunner;
        XSTRING          uaok;
        XSTRING          browser;
        XSTRING          so;

        uarunner.SetArg(_L("ua"), uaencoded.Get());
        uarunner.SetArgInt(_L("timeout"), timeout);
        tests->console->Printf(_L("[%s] "), uapaths[c]);
        if(!uarunner.Run(uapaths[c]))
          {
            tests->console->Printf(_L("Run() failed.\n"));
            status = false;
          }
         else
          {
            uarunner.GetResult(_L("ok"), uaok);
            uarunner.GetResult(_L("browser"), browser);
            uarunner.GetResult(_L("os"), so);
            tests->console->Printf(_L("ok=%s browser=%s os=%s\n"), uaok.Get(), browser.Get(), so.Get());
            if(uaok.Compare(_L("1")) != 0)
              {
                status = false;
              }
          }
      }

    DIOUSERAGENTID_RESULT uaresult;

    tests->console->Printf(_L("\n--- User Agent ID (facade default .g) ---\n"));
    if(useragentid->Get(uaraw, uaresult, timeout, NULL, true))
      {
        tests->console->Printf(_L("Browser         : %s\n"), uaresult.GetBrowser());
        tests->console->Printf(_L("Browser version : %s\n"), uaresult.GetBrowserVersion());
        tests->console->Printf(_L("Browser type    : %s\n"), uaresult.GetBrowserType());
        tests->console->Printf(_L("OS              : %s\n"), uaresult.GetSO());
        tests->console->Printf(_L("OS type         : %s\n"), uaresult.GetOSType());
        tests->console->Printf(_L("OS version      : %s\n"), uaresult.GetOSVersion());
      }
     else
      {
        tests->console->Printf(_L("User Agent ID facade : Error.\n"));
        status = false;
      }
  }
  #endif

  tests->console->Printf(_L("\nScraper script test : %s\n"), status ? _L("Ok") : _L("Error"));

  #ifdef DIO_SCRAPERWEB_PUBLICIP_ACTIVE
  GEN_DELETE publicip;
  #endif  

  #ifdef DIO_SCRAPERWEB_GEOLOCATIONIP_ACTIVE
  GEN_DELETE geolocationip;
  #endif  

  #ifdef DIO_SCRAPERWEB_WEATHER_ACTIVE
  GEN_DELETE weather;
  #endif

  #ifdef DIO_SCRAPERWEB_TRANSLATION_ACTIVE
  GEN_DELETE translation;
  #endif

  #ifdef DIO_SCRAPERWEB_MACMANUFACTURER_ACTIVE
  GEN_DELETE macmanufacturer;
  #endif

  #ifdef DIO_SCRAPERWEB_USERAGENTID_ACTIVE
  GEN_DELETE useragentid;
  #endif

  return status;

  #endif
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_MPSSE(DEVTESTS_CONSOLE* tests)
* @brief      Runs the mpsse test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_MPSSE(DEVTESTS_CONSOLE* tests)
{
  DIOMPSSE* MPSSE = GEN_NEW DIOMPSSE();
  if(!MPSSE)  return false;

  bool status = false;

  if(MPSSE->Open(0))
    {
      tests->console->Printf(_L(" Device found FT%s \n"), MPSSE->GetChipTypeName());

      status = true;

      MPSSE->Close();
    }

  GEN_DELETE MPSSE;

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DNSResolver(DEVTESTS_CONSOLE* tests)
* @brief      Runs the dnsresolver test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DNSResolver(DEVTESTS_CONSOLE* tests)
{
  DIOURL  URL;
  DIOIP   ipresolved;
  bool    status      = false;

  //URL = _L("www.google.es");

  URL = _L("members.dyndns.org");

  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[DNS Resolve %s] Ini ..."), URL.Get());

  status = GEN_DIODNSRESOLVER.ResolveURL(URL.Get(), ipresolved);
  if(status)
    {
      XSTRING IPstring;

      ipresolved.GetXString(IPstring);

      XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[DNS Resolve %s] IP resuelve %s  (%s) "), URL.Get(), IPstring.Get(), (URL.IsLocalAddress()?_L("Local"):_L("Internet")));

    }
   else
    {
      XTRACE_PRINTCOLOR(XTRACE_COLOR_RED, _L("[DNS Resolve %s] Not Found DNS URL!!!"), URL.Get());
    }

  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[DNS Resolve %s] End."), URL.Get());

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DNSProtocolMitMServer(DEVTESTS_CONSOLE* tests)
* @brief      Runs the dnsprotocol mit mserver test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DNSProtocolMitMServer(DEVTESTS_CONSOLE* tests)
{
  bool status = false;
  
  DIODNSPROTOCOL_MITM_SERVER* mitmserver = GEN_NEW DIODNSPROTOCOL_MITM_SERVER();
  if(!mitmserver)
    {
      return status;
    }

  if(mitmserver->Ini())
    {
      tests->console->Printf(_L(" Activate DNS Protocol MitM Server..."));

      tests->SubscribeEvent(DIODNSPROTOCOL_MITM_SERVER_XEVENT_TYPE_ASKDNS, mitmserver);
      tests->SubscribeEvent(DIODNSPROTOCOL_MITM_SERVER_XEVENT_TYPE_ANSWERDNS, mitmserver);
    
  
      if(mitmserver->Activate(true))
        {        
          status = true;

          tests->console->Printf(_L(" [Ok]\n"));  

          while(!tests->console->KBHit())
            {
              GEN_XSLEEP.MilliSeconds(50);  
            }
        }
       else
        {
          tests->console->Printf(_L(" [Error!]\n"));  
        }

      tests->UnSubscribeEvent(DIODNSPROTOCOL_MITM_SERVER_XEVENT_TYPE_ASKDNS, mitmserver);
      tests->UnSubscribeEvent(DIODNSPROTOCOL_MITM_SERVER_XEVENT_TYPE_ANSWERDNS, mitmserver);
      
      tests->console->Printf(_L(" Deactivate DNS Protocol MitM Server...\n"));    

      mitmserver->End();

      tests->console->GetChar();
    }


  GEN_DELETE mitmserver;  

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOCheckTCPIPConnections(DEVTESTS_CONSOLE* tests)
* @brief      Runs the diocheck tcpipconnections test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOCheckTCPIPConnections(DEVTESTS_CONSOLE* tests)
{
  DIOCHECKINTERNETCONNECTION* checkinternetconnection       = NULL;
  DIOCHECKTCPIPCONNECTIONS*   checkTCPIPconnections         = NULL;
  bool                        status                        = false;

  checkinternetconnection = GEN_NEW DIOCHECKINTERNETCONNECTION(10);
  if(checkinternetconnection)
    {
      //haveinternetconnection = checkinternetconnection->Check();
    }

  checkTCPIPconnections = GEN_NEW DIOCHECKTCPIPCONNECTIONS();
  if(checkTCPIPconnections)
    {
      XDWORD connectionID = 0x55AA55AA;

      status = checkTCPIPconnections->Ini(5, true, true);
      if(status)
        {
          status = checkTCPIPconnections->Connection_Add(_L("172.18.0.1"), connectionID);

          while(!tests->console->KBHit())
            {
              GEN_XSLEEP.Seconds(1);
            }

          checkTCPIPconnections->End();
        }
    }

  if(checkTCPIPconnections)
    {
      GEN_DELETE checkTCPIPconnections;
      checkTCPIPconnections = NULL;
    }


  if(checkinternetconnection)
    {
      GEN_DELETE checkinternetconnection;
      checkinternetconnection = NULL;
    }


  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_WifiEnum(DEVTESTS_CONSOLE* tests)
* @brief      Runs the wifi enum test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_WifiEnum(DEVTESTS_CONSOLE* tests)
{
  bool                            status            = false;
  #ifdef DIOWIFI_ACTIVE
  DIOSTREAMWIFIREMOTEENUMDEVICES* wifiremotedevices = NULL;

  wifiremotedevices = (DIOSTREAMWIFIREMOTEENUMDEVICES*)GEN_DIOFACTORY.CreateStreamEnumDevices(DIOSTREAMENUMTYPE_WIFI_REMOTE);
  if(!wifiremotedevices) return false;

  status = wifiremotedevices->Search();

  for(XDWORD c=0; c<wifiremotedevices->GetDevices()->GetSize(); c++)
    {
      DIOSTREAMDEVICEWIFI* devicewifi = (DIOSTREAMDEVICEWIFI*)wifiremotedevices->GetDeviceByIndex(c);
      if(devicewifi) devicewifi->DebugPrintInfo();
    }

  GEN_DIOFACTORY.DeleteStreamEnumDevices(wifiremotedevices);
  #endif

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_WakeOnLAN(DEVTESTS_CONSOLE* tests)
* @brief      Runs the wake on lan test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_WakeOnLAN(DEVTESTS_CONSOLE* tests)
{
  DIOWAKEONLAN* wakeonlan = NULL;
  DIOMAC        MAC;
  DIOIP         broadcastIP;
//XBYTE         MACdata[DIOMAC_MAXSIZE] = { 0xC8, 0x7F, 0x54, 0xAE, 0x5C, 0x80 };
  XBYTE         MACdata[DIOMAC_MAXSIZE] = { 0x10, 0xBF, 0x48, 0x78, 0x63, 0x53 };
  bool          status                  = false;

  MAC.Set(MACdata);
  broadcastIP.Set(_L("192.168.0.255"));

  wakeonlan = GEN_NEW DIOWAKEONLAN();
  if(!wakeonlan) return status;

  status = wakeonlan->SendActivation(&MAC, &broadcastIP);

  GEN_DELETE wakeonlan;

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_Hash(DEVTESTS_CONSOLE* tests)
* @brief      Runs the hash test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_Hash(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  XBUFFER  input;
  XSTRING  leyend;
  XSTRING  string;
  bool     status = false;

  string = _L("The quick brown fox jumps over the lazy dog");

  tests->console->Printf(_L("Sentence: \"%s\"\n\n"), string.Get());

  XBUFFER charstr;

  string.ConvertToASCII(charstr);

  if(charstr.GetSize() > 1)
    {
      charstr.Resize(charstr.GetSize()-1);                          // ConvertToASCII() adds a zero terminator
    }

  input.Add((XBYTE*)charstr.Get(), charstr.GetSize());

  for(int c=0;c<8;c++)
    {
      HASH* hash = NULL;
      switch(c)
        {
          case  0 :  hash = GEN_NEW HASHCRC32();                    leyend = _L("CRC32");      break;
          case  1 :  hash = GEN_NEW HASHMD5();                      leyend = _L("MD5");        break;
          case  2 :  hash = GEN_NEW HASHSHA1();                     leyend = _L("SHA1");       break;
          case  3 :  hash = GEN_NEW HASHSHA2(HASHSHA2TYPE_224);     leyend = _L("SHA2 224");   break;
          case  4 :  hash = GEN_NEW HASHSHA2(HASHSHA2TYPE_256);     leyend = _L("SHA2 256");   break;
          case  5 :  hash = GEN_NEW HASHSHA2(HASHSHA2TYPE_384);     leyend = _L("SHA2 384");   break;
          case  6 :  hash = GEN_NEW HASHSHA2(HASHSHA2TYPE_512);     leyend = _L("SHA2 512");   break;
          case  7 :  hash = GEN_NEW HASHWHIRLPOOL();                leyend = _L("Whirpool");   break;
        }

      if(!hash) return false;

      tests->Test_Hash(hash, input, leyend.Get());
      GEN_DELETE hash;
    }

  //--------------------------------------------------------------------------------------------------
  // HMAC (RFC 2104) of the same sentence, keyed with a fixed key.

  XBYTE   HMACkeydata[]  = { 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
                             0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b };
  XBUFFER HMACkey;

  HMACkey.Add(HMACkeydata, sizeof(HMACkeydata));

  tests->console->Printf(_L("\nHMAC (key: 20 bytes of 0x0B)\n\n"));

  for(int c=0;c<5;c++)
    {
      HASH*     hash     = NULL;
      HASHHMAC* hashhmac = NULL;

      switch(c)
        {
          case  0 :  hash = GEN_NEW HASHMD5();                      leyend = _L("HMAC MD5");        break;
          case  1 :  hash = GEN_NEW HASHSHA1();                     leyend = _L("HMAC SHA1");       break;
          case  2 :  hash = GEN_NEW HASHSHA2(HASHSHA2TYPE_256);     leyend = _L("HMAC SHA256");     break;
          case  3 :  hash = GEN_NEW HASHSHA2(HASHSHA2TYPE_384);     leyend = _L("HMAC SHA384");     break;
          case  4 :  hash = GEN_NEW HASHSHA2(HASHSHA2TYPE_512);     leyend = _L("HMAC SHA512");     break;
        }

      if(!hash) return false;

      hashhmac = GEN_NEW HASHHMAC(hash);
      if(!hashhmac)
        {
          GEN_DELETE hash;
          return false;
        }

      hashhmac->SetKey(HMACkey);

      tests->Test_Hash(hashhmac, input, leyend.Get());

      GEN_DELETE hashhmac;
      GEN_DELETE hash;
    }

  //--------------------------------------------------------------------------------------------------
  // Check the HMAC implementation against the test case 1 of the RFC 4231:
  // key = 20 bytes of 0x0B, data = "Hi There".

  XBYTE   HMACresultSHA256[] = { 0xb0, 0x34, 0x4c, 0x61, 0xd8, 0xdb, 0x38, 0x53, 0x5c, 0xa8, 0xaf, 0xce, 0xaf, 0x0b, 0xf1, 0x2b,
                                 0x88, 0x1d, 0xc2, 0x00, 0xc9, 0x83, 0x3d, 0xa7, 0x26, 0xe9, 0x37, 0x6c, 0x2e, 0x32, 0xcf, 0xf7 };

  XBYTE   HMACresultSHA384[] = { 0xaf, 0xd0, 0x39, 0x44, 0xd8, 0x48, 0x95, 0x62, 0x6b, 0x08, 0x25, 0xf4, 0xab, 0x46, 0x90, 0x7f,
                                 0x15, 0xf9, 0xda, 0xdb, 0xe4, 0x10, 0x1e, 0xc6, 0x82, 0xaa, 0x03, 0x4c, 0x7c, 0xeb, 0xc5, 0x9c,
                                 0xfa, 0xea, 0x9e, 0xa9, 0x07, 0x6e, 0xde, 0x7f, 0x4a, 0xf1, 0x52, 0xe8, 0xb2, 0xfa, 0x9c, 0xb6 };

  XSTRING HMACdata           = _L("Hi There");
  XBUFFER HMACinput;

  HMACdata.ConvertToASCII(HMACinput);

  if(HMACinput.GetSize() > 1)
    {
      HMACinput.Resize(HMACinput.GetSize()-1);                      // ConvertToASCII() adds a zero terminator
    }

  tests->console->Printf(_L("\nHMAC check with the RFC 4231 test case 1\n\n"));

  for(int c=0;c<2;c++)
    {
      HASHSHA2* hashsha2 = NULL;
      HASHHMAC* hashhmac = NULL;
      XBYTE*    expected = NULL;
      XDWORD    sizeexpected = 0;

      switch(c)
        {
          case  0 :  hashsha2     = GEN_NEW HASHSHA2(HASHSHA2TYPE_256);
                     expected     = HMACresultSHA256;
                     sizeexpected = sizeof(HMACresultSHA256);
                     leyend       = _L("HMAC SHA256");
                     break;

          case  1 :  hashsha2     = GEN_NEW HASHSHA2(HASHSHA2TYPE_384);
                     expected     = HMACresultSHA384;
                     sizeexpected = sizeof(HMACresultSHA384);
                     leyend       = _L("HMAC SHA384");
                     break;
        }

      if(!hashsha2) return false;

      hashhmac = GEN_NEW HASHHMAC(hashsha2);
      if(!hashhmac)
        {
          GEN_DELETE hashsha2;
          return false;
        }

      hashhmac->SetKey(HMACkey);
      hashhmac->ResetResult();

      status = hashhmac->Do(HMACinput);
      if(status)
        {
          status = hashhmac->GetResult()->Compare(expected, sizeexpected);
        }

      tests->console->Printf(_L("%-12s : %s\n"), leyend.Get(), status?_L("Ok."):_L("Error!"));

      GEN_DELETE hashhmac;
      GEN_DELETE hashsha2;

      if(!status) break;
    }

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_OneCipher_Simetric(DEVTESTS_CONSOLE* tests, bool operation, CIPHER* cipher, XBUFFER& input, XBUFFER& output)
* @brief      Runs one symmetric cipher test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
* @param[in]  operation : true to encrypt data; false to decrypt data.
* @param[in]  cipher : cipher instance used by the test.
* @param[in]  input : input buffer used by the test.
* @param[out]  output : output buffer filled by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_OneCipher_Simetric(DEVTESTS_CONSOLE* tests, bool operation, CIPHER* cipher, XBUFFER& input, XBUFFER& output)
{
	if(!cipher) return false;

	bool status = operation?cipher->Cipher(input):cipher->Uncipher(input);
	
	if(!status)
		{
			tests->console->Printf(_L("Error!\n"));	
			return false;
		}

  output.CopyFrom((*cipher->GetResult()));

	for(int c=0;c<(int)(output.GetSize());c++)
		{
			tests->console->Printf(_L("%02X"), output.GetByte(c));
		}
		
	tests->console->Printf(_L("\n"));

	return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_Cipher_Simetric(DEVTESTS_CONSOLE* tests)
* @brief      Runs the cipher simetric test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_Cipher_Simetric(DEVTESTS_CONSOLE* tests)
{
  XBUFFER								input;
  XBUFFER								output;
	XSTRING								leyend;
	CIPHERKEYSYMMETRICAL  key;	  
  bool                  status      = false;
	
	XBYTE									inivector[]	= { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F };
	XBYTE									inputdata[]	= { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a, 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };
  XBYTE									keydata[]		= { 0x60, 0x3d, 0xeb, 0x10, 0x15, 0xca, 0x71, 0xbe, 0x2b, 0x73, 0xae, 0xf0, 0x85, 0x7d, 0x77, 0x81, 0x1f, 0x35, 0x2c, 0x07, 0x3b, 0x61, 0x08, 0xd7, 0x2d, 0x98, 0x10, 0xa3, 0x09, 0x14, 0xdf, 0xf4 }; // { 0x8e, 0x73, 0xb0, 0xf7, 0xda, 0x0e, 0x64, 0x52, 0xc8, 0x10, 0xf3, 0x2b, 0x80, 0x90, 0x79, 0xe5, 0x62, 0xf8, 0xea, 0xd2, 0x52, 0x2c, 0x6b, 0x7b }; // { 0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c };  

	
	key.Set(keydata, sizeof(keydata));	

  tests->console->Printf(_L("Plain text: "));

	for(int c=0; c<(int)(sizeof(inputdata)); c++)
		{
			tests->console->Printf(_L("%02X"), inputdata[c]);
		}

  tests->console->Printf(_L("\n\n"));

 
	for(int c=0;c<5;c++)
		{
			CIPHER*		cipher = NULL;
			switch(c)
				{
					case  0 :  cipher = GEN_NEW CIPHER();						leyend = _L("XOR (base)");	  break;
					case  1 :  cipher = GEN_NEW CIPHERDES();				leyend = _L("DES");			    break;
					case  2 :  cipher = GEN_NEW CIPHER3DES();				leyend = _L("3DES");			    break;										
					case  3 :  cipher = GEN_NEW CIPHERAES();				leyend = _L("AES");			    break;	
					case  4 :  cipher = GEN_NEW CIPHERBLOWFISH();		leyend = _L("Blowfish");	    break;						
				}
					
			if(cipher) 
				{
					cipher->SetChainingMode(CIPHERCHAININGMODE_CBC);				
					cipher->SetPaddingType(XBUFFER_PADDINGTYPE_ZEROS); 
					cipher->SetInitVector(inivector, sizeof(inivector));			

					cipher->SetKey(&key);

          input.Empty();
          input.Add((XBYTE*)inputdata, sizeof(inputdata));

          tests->console->Printf(_L("[ %s ]\n"), leyend.Get());
          tests->console->Printf(_L(" Cipher : "));
					status = Test_OneCipher_Simetric(tests, true, cipher, input, output);
          if(!status) break;

          input.Empty();

          tests->console->Printf(_L(" Uncipher : "));
          status = Test_OneCipher_Simetric(tests, false, cipher, output, input);        
          tests->console->Printf(_L("\n"));

          if(!status) break;

					GEN_DELETE cipher;
				}
		}

  if(!status) return false;

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
* 
* @fn         bool DEVTESTS_CONSOLE::Test_Cipher_HKDF(DEVTESTS_CONSOLE* tests)
* @brief      test  cipher  HKDf
* @ingroup    
* 
* @param[in]  tests : 
* 
* @return     bool : true if is succesful. 
* 
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_Cipher_HKDF(DEVTESTS_CONSOLE* tests)
{
  //--------------------------------------------------------------------------------------------------
  // HKDF (RFC 5869) check with the test case 1: extract and expand with SHA-256.

  XBYTE       HKDFikmdata[]   = { 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b,
                                  0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b, 0x0b };

  XBYTE       HKDFsaltdata[]  = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c };

  XBYTE       HKDFinfodata[]  = { 0xf0, 0xf1, 0xf2, 0xf3, 0xf4, 0xf5, 0xf6, 0xf7, 0xf8, 0xf9 };

  XBYTE       HKDFPRKdata[]   = { 0x07, 0x77, 0x09, 0x36, 0x2c, 0x2e, 0x32, 0xdf, 0x0d, 0xdc, 0x3f, 0x0d, 0xc4, 0x7b, 0xba, 0x63,
                                  0x90, 0xb6, 0xc7, 0x3b, 0xb5, 0x0f, 0x9c, 0x31, 0x22, 0xec, 0x84, 0x4a, 0xd7, 0xc2, 0xb3, 0xe5 };

  XBYTE       HKDFOKMdata[]   = { 0x3c, 0xb2, 0x5f, 0x25, 0xfa, 0xac, 0xd5, 0x7a, 0x90, 0x43, 0x4f, 0x64, 0xd0, 0x36, 0x2f, 0x2a,
                                  0x2d, 0x2d, 0x0a, 0x90, 0xcf, 0x1a, 0x5a, 0x4c, 0x5d, 0xb0, 0x2d, 0x56, 0xec, 0xc4, 0xc5, 0xbf,
                                  0x34, 0x00, 0x72, 0x08, 0xd5, 0xb8, 0x87, 0x18, 0x58, 0x65 };

  HASHSHA2    HKDFhash(HASHSHA2TYPE_256);
  CIPHERHKDF  HKDF(&HKDFhash);

  XBUFFER     HKDFikm;
  XBUFFER     HKDFsalt;
  XBUFFER     HKDFinfo;
  XBUFFER     HKDFPRK;
  XBUFFER     HKDFOKM;

  XBUFFER		  input;
  XBUFFER			output;
  XBYTE			  inputdata[]	    = { 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a, 0x6b, 0xc1, 0xbe, 0xe2, 0x2e, 0x40, 0x9f, 0x96, 0xe9, 0x3d, 0x7e, 0x11, 0x73, 0x93, 0x17, 0x2a };

  bool        status = false;   

  HKDFikm.Add(HKDFikmdata, sizeof(HKDFikmdata));
  HKDFsalt.Add(HKDFsaltdata , sizeof(HKDFsaltdata));
  HKDFinfo.Add(HKDFinfodata , sizeof(HKDFinfodata));

  tests->console->Printf(_L("[ HKDF SHA2 256 ]\n"));

  status = HKDF.Extract(HKDFsalt, HKDFikm, HKDFPRK);
  if(status)
    {
      status = HKDFPRK.Compare(HKDFPRKdata, sizeof(HKDFPRKdata));
    }

  tests->console->Printf(_L(" Extract : "));

  for(int c=0; c<(int)(HKDFPRK.GetSize()); c++)
    {
      tests->console->Printf(_L("%02X"), HKDFPRK.GetByte(c));
    }

  tests->console->Printf(_L("\n RFC 5869 test case 1 PRK : %s\n"), status?_L("Ok."):_L("Error!"));

  if(status)
    {
      status = HKDF.Expand(HKDFPRK, HKDFinfo, sizeof(HKDFOKMdata), HKDFOKM);
      if(status)
        {
          status = HKDFOKM.Compare(HKDFOKMdata, sizeof(HKDFOKMdata));
        }

      tests->console->Printf(_L(" Expand : "));

      for(int c=0; c<(int)(HKDFOKM.GetSize()); c++)
        {
          tests->console->Printf(_L("%02X"), HKDFOKM.GetByte(c));
        }

      tests->console->Printf(_L("\n RFC 5869 test case 1 OKM : %s\n\n"), status?_L("Ok."):_L("Error!"));
    }

  if(!status) return false;

  //--------------------------------------------------------------------------------------------------
  // Derive the key and the initialization vector of a symmetric cipher from a secret, the way TLS 1.3
  // does it with HKDF-Expand-Label, and use them with AES.

  CIPHERKEYSYMMETRICAL  HKDFderivedkey;
  CIPHERAES             HKDFcipher;
  XBUFFER               HKDFcontext;
  XBUFFER               HKDFkey;
  XBUFFER               HKDFinivector;

  status = HKDF.ExpandLabel(HKDFPRK, _L("key"), HKDFcontext, 32, HKDFkey);
  if(status)
    {
      status = HKDF.ExpandLabel(HKDFPRK, _L("iv"), HKDFcontext, 16, HKDFinivector);
    }

  if(!status) return false;

  tests->console->Printf(_L("[ HKDF derived material for AES ]\n"));

  tests->console->Printf(_L(" Key : "));

  for(int c=0; c<(int)(HKDFkey.GetSize()); c++)
    {
      tests->console->Printf(_L("%02X"), HKDFkey.GetByte(c));
    }

  tests->console->Printf(_L("\n IV : "));

  for(int c=0; c<(int)(HKDFinivector.GetSize()); c++)
    {
      tests->console->Printf(_L("%02X"), HKDFinivector.GetByte(c));
    }

  tests->console->Printf(_L("\n"));

  HKDFderivedkey.Set(HKDFkey);

  HKDFcipher.SetChainingMode(CIPHERCHAININGMODE_CBC);
  HKDFcipher.SetPaddingType(XBUFFER_PADDINGTYPE_ZEROS);
  HKDFcipher.SetInitVector(HKDFinivector);
  HKDFcipher.SetKey(&HKDFderivedkey);

  input.Empty();
  input.Add((XBYTE*)inputdata, sizeof(inputdata));

  tests->console->Printf(_L(" Cipher : "));
  status = Test_OneCipher_Simetric(tests, true, &HKDFcipher, input, output);

  if(status)
    {
      input.Empty();

      tests->console->Printf(_L(" Uncipher : "));
      status = Test_OneCipher_Simetric(tests, false, &HKDFcipher, output, input);
    }

  if(status)
    {
      if(input.GetSize() > sizeof(inputdata))
        {
          input.Resize(sizeof(inputdata));
        }

      status = input.Compare((XBYTE*)inputdata, sizeof(inputdata));
    }

  tests->console->Printf(_L(" Round trip with the derived key : %s\n"), status?_L("Ok."):_L("Error!"));

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_Cipher_AESGCM(DEVTESTS_CONSOLE* tests)
* @brief      Runs the cipher AES GCM test against the test vectors of the NIST SP 800-38D
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_Cipher_AESGCM(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  //--------------------------------------------------------------------------------------------------
  // Test vectors of the NIST SP 800-38D: cases 1 to 6 with AES-128 and 13 to 16 with AES-256.
  // Cases 5 and 6 use nonces that are not of 96 bits, so they exercise the reduction of the nonce
  // with GHASH instead of the direct path.

  XBYTE                 AESGCM_zeros[]          = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                                                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 };
  XBYTE                 AESGCM_key128[]         = { 0xfe, 0xff, 0xe9, 0x92, 0x86, 0x65, 0x73, 0x1c, 0x6d, 0x6a, 0x8f, 0x94, 0x67, 0x30, 0x83, 0x08 };
  XBYTE                 AESGCM_key256[]         = { 0xfe, 0xff, 0xe9, 0x92, 0x86, 0x65, 0x73, 0x1c, 0x6d, 0x6a, 0x8f, 0x94, 0x67, 0x30, 0x83, 0x08,
                                                    0xfe, 0xff, 0xe9, 0x92, 0x86, 0x65, 0x73, 0x1c, 0x6d, 0x6a, 0x8f, 0x94, 0x67, 0x30, 0x83, 0x08 };
  XBYTE                 AESGCM_nonce96[]        = { 0xca, 0xfe, 0xba, 0xbe, 0xfa, 0xce, 0xdb, 0xad, 0xde, 0xca, 0xf8, 0x88 };
  XBYTE                 AESGCM_nonce8[]         = { 0xca, 0xfe, 0xba, 0xbe, 0xfa, 0xce, 0xdb, 0xad };
  XBYTE                 AESGCM_nonce60[]        = { 0x93, 0x13, 0x22, 0x5d, 0xf8, 0x84, 0x06, 0xe5, 0x55, 0x90, 0x9c, 0x5a, 0xff, 0x52, 0x69, 0xaa,
                                                    0x6a, 0x7a, 0x95, 0x38, 0x53, 0x4f, 0x7d, 0xa1, 0xe4, 0xc3, 0x03, 0xd2, 0xa3, 0x18, 0xa7, 0x28,
                                                    0xc3, 0xc0, 0xc9, 0x51, 0x56, 0x80, 0x95, 0x39, 0xfc, 0xf0, 0xe2, 0x42, 0x9a, 0x6b, 0x52, 0x54,
                                                    0x16, 0xae, 0xdb, 0xf5, 0xa0, 0xde, 0x6a, 0x57, 0xa6, 0x37, 0xb3, 0x9b };
  XBYTE                 AESGCM_plain[]          = { 0xd9, 0x31, 0x32, 0x25, 0xf8, 0x84, 0x06, 0xe5, 0xa5, 0x59, 0x09, 0xc5, 0xaf, 0xf5, 0x26, 0x9a,
                                                    0x86, 0xa7, 0xa9, 0x53, 0x15, 0x34, 0xf7, 0xda, 0x2e, 0x4c, 0x30, 0x3d, 0x8a, 0x31, 0x8a, 0x72,
                                                    0x1c, 0x3c, 0x0c, 0x95, 0x95, 0x68, 0x09, 0x53, 0x2f, 0xcf, 0x0e, 0x24, 0x49, 0xa6, 0xb5, 0x25,
                                                    0xb1, 0x6a, 0xed, 0xf5, 0xaa, 0x0d, 0xe6, 0x57, 0xba, 0x63, 0x7b, 0x39, 0x1a, 0xaf, 0xd2, 0x55 };
  XBYTE                 AESGCM_aad[]            = { 0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef, 0xfe, 0xed, 0xfa, 0xce, 0xde, 0xad, 0xbe, 0xef,
                                                    0xab, 0xad, 0xda, 0xd2 };
  XBYTE                 AESGCM_cipher02[]       = { 0x03, 0x88, 0xda, 0xce, 0x60, 0xb6, 0xa3, 0x92, 0xf3, 0x28, 0xc2, 0xb9, 0x71, 0xb2, 0xfe, 0x78 };
  XBYTE                 AESGCM_cipher03[]       = { 0x42, 0x83, 0x1e, 0xc2, 0x21, 0x77, 0x74, 0x24, 0x4b, 0x72, 0x21, 0xb7, 0x84, 0xd0, 0xd4, 0x9c,
                                                    0xe3, 0xaa, 0x21, 0x2f, 0x2c, 0x02, 0xa4, 0xe0, 0x35, 0xc1, 0x7e, 0x23, 0x29, 0xac, 0xa1, 0x2e,
                                                    0x21, 0xd5, 0x14, 0xb2, 0x54, 0x66, 0x93, 0x1c, 0x7d, 0x8f, 0x6a, 0x5a, 0xac, 0x84, 0xaa, 0x05,
                                                    0x1b, 0xa3, 0x0b, 0x39, 0x6a, 0x0a, 0xac, 0x97, 0x3d, 0x58, 0xe0, 0x91, 0x47, 0x3f, 0x59, 0x85 };
  XBYTE                 AESGCM_cipher05[]       = { 0x61, 0x35, 0x3b, 0x4c, 0x28, 0x06, 0x93, 0x4a, 0x77, 0x7f, 0xf5, 0x1f, 0xa2, 0x2a, 0x47, 0x55,
                                                    0x69, 0x9b, 0x2a, 0x71, 0x4f, 0xcd, 0xc6, 0xf8, 0x37, 0x66, 0xe5, 0xf9, 0x7b, 0x6c, 0x74, 0x23,
                                                    0x73, 0x80, 0x69, 0x00, 0xe4, 0x9f, 0x24, 0xb2, 0x2b, 0x09, 0x75, 0x44, 0xd4, 0x89, 0x6b, 0x42,
                                                    0x49, 0x89, 0xb5, 0xe1, 0xeb, 0xac, 0x0f, 0x07, 0xc2, 0x3f, 0x45, 0x98 };
  XBYTE                 AESGCM_cipher06[]       = { 0x8c, 0xe2, 0x49, 0x98, 0x62, 0x56, 0x15, 0xb6, 0x03, 0xa0, 0x33, 0xac, 0xa1, 0x3f, 0xb8, 0x94,
                                                    0xbe, 0x91, 0x12, 0xa5, 0xc3, 0xa2, 0x11, 0xa8, 0xba, 0x26, 0x2a, 0x3c, 0xca, 0x7e, 0x2c, 0xa7,
                                                    0x01, 0xe4, 0xa9, 0xa4, 0xfb, 0xa4, 0x3c, 0x90, 0xcc, 0xdc, 0xb2, 0x81, 0xd4, 0x8c, 0x7c, 0x6f,
                                                    0xd6, 0x28, 0x75, 0xd2, 0xac, 0xa4, 0x17, 0x03, 0x4c, 0x34, 0xae, 0xe5 };
  XBYTE                 AESGCM_cipher14[]       = { 0xce, 0xa7, 0x40, 0x3d, 0x4d, 0x60, 0x6b, 0x6e, 0x07, 0x4e, 0xc5, 0xd3, 0xba, 0xf3, 0x9d, 0x18 };
  XBYTE                 AESGCM_cipher15[]       = { 0x52, 0x2d, 0xc1, 0xf0, 0x99, 0x56, 0x7d, 0x07, 0xf4, 0x7f, 0x37, 0xa3, 0x2a, 0x84, 0x42, 0x7d,
                                                    0x64, 0x3a, 0x8c, 0xdc, 0xbf, 0xe5, 0xc0, 0xc9, 0x75, 0x98, 0xa2, 0xbd, 0x25, 0x55, 0xd1, 0xaa,
                                                    0x8c, 0xb0, 0x8e, 0x48, 0x59, 0x0d, 0xbb, 0x3d, 0xa7, 0xb0, 0x8b, 0x10, 0x56, 0x82, 0x88, 0x38,
                                                    0xc5, 0xf6, 0x1e, 0x63, 0x93, 0xba, 0x7a, 0x0a, 0xbc, 0xc9, 0xf6, 0x62, 0x89, 0x80, 0x15, 0xad };
  XBYTE                 AESGCM_tag01[]          = { 0x58, 0xe2, 0xfc, 0xce, 0xfa, 0x7e, 0x30, 0x61, 0x36, 0x7f, 0x1d, 0x57, 0xa4, 0xe7, 0x45, 0x5a };
  XBYTE                 AESGCM_tag02[]          = { 0xab, 0x6e, 0x47, 0xd4, 0x2c, 0xec, 0x13, 0xbd, 0xf5, 0x3a, 0x67, 0xb2, 0x12, 0x57, 0xbd, 0xdf };
  XBYTE                 AESGCM_tag03[]          = { 0x4d, 0x5c, 0x2a, 0xf3, 0x27, 0xcd, 0x64, 0xa6, 0x2c, 0xf3, 0x5a, 0xbd, 0x2b, 0xa6, 0xfa, 0xb4 };
  XBYTE                 AESGCM_tag04[]          = { 0x5b, 0xc9, 0x4f, 0xbc, 0x32, 0x21, 0xa5, 0xdb, 0x94, 0xfa, 0xe9, 0x5a, 0xe7, 0x12, 0x1a, 0x47 };
  XBYTE                 AESGCM_tag05[]          = { 0x36, 0x12, 0xd2, 0xe7, 0x9e, 0x3b, 0x07, 0x85, 0x56, 0x1b, 0xe1, 0x4a, 0xac, 0xa2, 0xfc, 0xcb };
  XBYTE                 AESGCM_tag06[]          = { 0x61, 0x9c, 0xc5, 0xae, 0xff, 0xfe, 0x0b, 0xfa, 0x46, 0x2a, 0xf4, 0x3c, 0x16, 0x99, 0xd0, 0x50 };
  XBYTE                 AESGCM_tag13[]          = { 0x53, 0x0f, 0x8a, 0xfb, 0xc7, 0x45, 0x36, 0xb9, 0xa9, 0x63, 0xb4, 0xf1, 0xc4, 0xcb, 0x73, 0x8b };
  XBYTE                 AESGCM_tag14[]          = { 0xd0, 0xd1, 0xc8, 0xa7, 0x99, 0x99, 0x6b, 0xf0, 0x26, 0x5b, 0x98, 0xb5, 0xd4, 0x8a, 0xb9, 0x19 };
  XBYTE                 AESGCM_tag15[]          = { 0xb0, 0x94, 0xda, 0xc5, 0xd9, 0x34, 0x71, 0xbd, 0xec, 0x1a, 0x50, 0x22, 0x70, 0xe3, 0xcc, 0x6c };
  XBYTE                 AESGCM_tag16[]          = { 0x76, 0xfc, 0x6e, 0xce, 0x0f, 0x4e, 0x17, 0x68, 0xcd, 0xdf, 0x88, 0x53, 0xbb, 0x2d, 0x55, 0x1b };

  typedef struct
  {
    XCHAR*                leyend;

    XBYTE*                key;
    XDWORD                sizekey;

    XBYTE*                nonce;
    XDWORD                sizenonce;

    XBYTE*                plain;
    XDWORD                sizeplain;

    XBYTE*                additionaldata;
    XDWORD                sizeadditionaldata;

    XBYTE*                cipher;
    XDWORD                sizecipher;

    XBYTE*                tag;

  } AESGCM_TESTVECTOR;

  AESGCM_TESTVECTOR     AESGCM_vectors[] = { { _L("TC01 AES-128 no data")       , AESGCM_zeros    , 16, AESGCM_zeros    , 12, NULL          ,  0, NULL        ,  0, NULL            ,  0, AESGCM_tag01   },
                                             { _L("TC02 AES-128 one block")     , AESGCM_zeros    , 16, AESGCM_zeros    , 12, AESGCM_zeros  , 16, NULL        ,  0, AESGCM_cipher02 , 16, AESGCM_tag02   },
                                             { _L("TC03 AES-128 four blocks")   , AESGCM_key128   , 16, AESGCM_nonce96  , 12, AESGCM_plain  , 64, NULL        ,  0, AESGCM_cipher03 , 64, AESGCM_tag03   },
                                             { _L("TC04 AES-128 with AAD")      , AESGCM_key128   , 16, AESGCM_nonce96  , 12, AESGCM_plain  , 60, AESGCM_aad  , 20, AESGCM_cipher03 , 60, AESGCM_tag04   },
                                             { _L("TC05 AES-128 nonce of 8")    , AESGCM_key128   , 16, AESGCM_nonce8   ,  8, AESGCM_plain  , 60, AESGCM_aad  , 20, AESGCM_cipher05 , 60, AESGCM_tag05   },
                                             { _L("TC06 AES-128 nonce of 60")   , AESGCM_key128   , 16, AESGCM_nonce60  , 60, AESGCM_plain  , 60, AESGCM_aad  , 20, AESGCM_cipher06 , 60, AESGCM_tag06   },
                                             { _L("TC13 AES-256 no data")       , AESGCM_zeros    , 32, AESGCM_zeros    , 12, NULL          ,  0, NULL        ,  0, NULL            ,  0, AESGCM_tag13   },
                                             { _L("TC14 AES-256 one block")     , AESGCM_zeros    , 32, AESGCM_zeros    , 12, AESGCM_zeros  , 16, NULL        ,  0, AESGCM_cipher14 , 16, AESGCM_tag14   },
                                             { _L("TC15 AES-256 four blocks")   , AESGCM_key256   , 32, AESGCM_nonce96  , 12, AESGCM_plain  , 64, NULL        ,  0, AESGCM_cipher15 , 64, AESGCM_tag15   },
                                             { _L("TC16 AES-256 with AAD")      , AESGCM_key256   , 32, AESGCM_nonce96  , 12, AESGCM_plain  , 60, AESGCM_aad  , 20, AESGCM_cipher15 , 60, AESGCM_tag16   } };

  bool                  status = false;

  for(int c=0; c<(int)(sizeof(AESGCM_vectors)/sizeof(AESGCM_TESTVECTOR)); c++)
    {
      CIPHERAESGCM          cipherAESGCM;
      CIPHERKEYSYMMETRICAL  key;
      XBUFFER               nonce;
      XBUFFER               plain;
      XBUFFER               additionaldata;
      XBUFFER               ciphertext;
      XBUFFER               tag;

      key.Set(AESGCM_vectors[c].key, AESGCM_vectors[c].sizekey);

      nonce.Add(AESGCM_vectors[c].nonce, AESGCM_vectors[c].sizenonce);

      if(AESGCM_vectors[c].sizeplain)
        {
          plain.Add(AESGCM_vectors[c].plain, AESGCM_vectors[c].sizeplain);
        }

      if(AESGCM_vectors[c].sizeadditionaldata)
        {
          additionaldata.Add(AESGCM_vectors[c].additionaldata, AESGCM_vectors[c].sizeadditionaldata);
        }

      tests->console->Printf(_L("[ %s ]\n"), AESGCM_vectors[c].leyend);

      // ----- Cipher -----------------------------------------------------------------------------------

      status = cipherAESGCM.SetKey(&key);

      if(status)
        {
          status = cipherAESGCM.CipherAEAD(plain, nonce, additionaldata, tag);
        }

      if(status)
        {
          status = (cipherAESGCM.GetResult()->GetSize() == AESGCM_vectors[c].sizecipher)?true:false;
        }

      if(status && AESGCM_vectors[c].sizecipher)
        {
          status = cipherAESGCM.GetResult()->Compare(AESGCM_vectors[c].cipher, AESGCM_vectors[c].sizecipher);
        }

      tests->console->Printf(_L(" Cipher : "));

      for(int d=0; d<(int)(cipherAESGCM.GetResult()->GetSize()); d++)
        {
          tests->console->Printf(_L("%02X"), cipherAESGCM.GetResult()->GetByte(d));
        }

      tests->console->Printf(_L("\n Tag : "));

      for(int d=0; d<(int)(tag.GetSize()); d++)
        {
          tests->console->Printf(_L("%02X"), tag.GetByte(d));
        }

      if(status)
        {
          status = tag.Compare(AESGCM_vectors[c].tag, CIPHERAESGCM_TAGSIZE);
        }

      tests->console->Printf(_L("\n NIST SP 800-38D vector : %s\n"), status?_L("Ok."):_L("Error!"));

      // ----- Uncipher ---------------------------------------------------------------------------------

      if(status)
        {
          if(AESGCM_vectors[c].sizecipher)
            {
              ciphertext.Add(cipherAESGCM.GetResult());
            }

          status = cipherAESGCM.UncipherAEAD(ciphertext, nonce, additionaldata, tag);

          if(status)
            {
              if(AESGCM_vectors[c].sizeplain)
                   status = cipherAESGCM.GetResult()->Compare(plain);
              else status = cipherAESGCM.GetResult()->IsEmpty();
            }
        }

      tests->console->Printf(_L(" Uncipher and authenticate: %s\n\n"), status?_L("Ok."):_L("Error!"));

      if(!status)
        {
          return false;
        }
    }

  //--------------------------------------------------------------------------------------------------
  // A message that has been tampered with must never be accepted, and its plain text must never be
  // handed over. These are the checks that separate an AEAD from a plain cipher.

  CIPHERAESGCM          cipherAESGCM;
  CIPHERKEYSYMMETRICAL  key;
  XBUFFER               nonce;
  XBUFFER               plain;
  XBUFFER               additionaldata;
  XBUFFER               ciphertext;
  XBUFFER               tag;
  XBUFFER               altered;

  key.Set(AESGCM_key128, sizeof(AESGCM_key128));

  nonce.Add(AESGCM_nonce96, sizeof(AESGCM_nonce96));
  plain.Add(AESGCM_plain, sizeof(AESGCM_plain));
  additionaldata.Add(AESGCM_aad, sizeof(AESGCM_aad));

  tests->console->Printf(_L("[ Rejection of tampered messages ]\n"));

  status = cipherAESGCM.SetKey(&key);

  if(status)
    {
      status = cipherAESGCM.CipherAEAD(plain, nonce, additionaldata, tag);
    }

  if(status)
    {
      ciphertext.Add(cipherAESGCM.GetResult());

      status = cipherAESGCM.UncipherAEAD(ciphertext, nonce, additionaldata, tag);
    }

  tests->console->Printf(_L(" Valid message accepted : %s\n"), status?_L("Ok."):_L("Error!"));

  if(status)
    {
      altered.Add(tag);
      altered.Get()[0] ^= 0x01;

      status = cipherAESGCM.UncipherAEAD(ciphertext, nonce, additionaldata, altered)?false:true;

      tests->console->Printf(_L(" Altered tag rejected : %s\n"), status?_L("Ok."):_L("Error!"));
    }

  if(status)
    {
      status = cipherAESGCM.GetResult()->IsEmpty();

      tests->console->Printf(_L(" Plain text wiped : %s\n"), status?_L("Ok."):_L("Error!"));
    }

  if(status)
    {
      altered.Delete();
      altered.Add(ciphertext);
      altered.Get()[0] ^= 0x01;

      status = cipherAESGCM.UncipherAEAD(altered, nonce, additionaldata, tag)?false:true;

      tests->console->Printf(_L(" Altered cipher rejected : %s\n"), status?_L("Ok."):_L("Error!"));
    }

  if(status)
    {
      altered.Delete();
      altered.Add(additionaldata);
      altered.Get()[0] ^= 0x01;

      status = cipherAESGCM.UncipherAEAD(ciphertext, nonce, altered, tag)?false:true;

      tests->console->Printf(_L(" Altered AAD rejected : %s\n"), status?_L("Ok."):_L("Error!"));
    }

  if(status)
    {
      altered.Delete();
      altered.Add(nonce);
      altered.Get()[0] ^= 0x01;

      status = cipherAESGCM.UncipherAEAD(ciphertext, altered, additionaldata, tag)?false:true;

      tests->console->Printf(_L(" Altered nonce rejected : %s\n"), status?_L("Ok."):_L("Error!"));
    }

  if(status)
    {
      altered.Delete();
      altered.Add(tag.Get(), CIPHERAESGCM_TAGSIZE_MIN);

      status = cipherAESGCM.UncipherAEAD(ciphertext, nonce, additionaldata, altered)?false:true;

      tests->console->Printf(_L(" Short tag rejected : %s\n"), status?_L("Ok."):_L("Error!"));
    }

  tests->console->Printf(_L("\n"));

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_CipherFileKeys(DEVTESTS_CONSOLE* tests)
* @brief      Runs the cipher file keys test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_CipherFileKeys(DEVTESTS_CONSOLE* tests)
{
  CIPHERTRUSTEDROOTCERTIFICATESX509 trustedrootcertificates; 
  XPATH		                          xpathgeneric;	
	XPATH	 	                          xpath;
  XPATH	 	                          xpathtarget;
  bool                              status = false;
	
	XPATHSMANAGER::GetInstance().GetPathOfSection(XPATHSMANAGERSECTIONTYPE_CERTIFICATES, xpathgeneric);
//xpath.Create(3 , xpathgeneric.Get(), _L("root")    , CIPHERKEYSFILEPEM_EXT);	
  xpath.Create(3, xpathgeneric.Get(), _L("cacert"), CIPHERKEYSFILEPEM_EXT);	 
//xpath.Create(3 , xpathgeneric.Get(), _L("certificate"), CIPHERKEYSFILEKEY_EXT);	
//xpath.Create(2 , xpathgeneric.Get(), _L("certificate.ca.crt"));	
//xpath.Create(2 , xpathgeneric.Get(), _L("id_rsa"));
 

xpathtarget.Create(3, xpathgeneric.Get(), _L("cacert"), _L(".h"));	

//status = trustedrootcertificates.GenerateEmbeddedHeadere(&xpath, &xpathtarget);

	CIPHERKEYSFILEPEM* filekeys = GEN_NEW CIPHERKEYSFILEPEM();	
  if(filekeys) 
    {
      status = true;
    }

  if(status)
    {     
      //if(trustedrootcertificates.ReadFromFile(&xpath))
        {
          filekeys->DecodeCertificates(trustedrootcertificates.GetLines());
        }
    }

  GEN_DELETE filekeys;

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_CipherRSA(DEVTESTS_CONSOLE* tests)
* @brief      Runs the cipher rsa test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_CipherRSA(DEVTESTS_CONSOLE* tests)
{
  CIPHERRSA* cipher = GEN_NEW CIPHERRSA();
	if(!cipher) return false; 

  /*
  bool status = false;
	
	XPATH	 	 xpath;
	XPATH		 xpathgeneric;	

	XPATHSMANAGER::GetInstance().GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpathgeneric);
	xpath.Create(3 , xpathgeneric.Get(), _L("keys"), CIPHERKEYSFILEGKF_EXT);	
	
	CIPHERKEYSFILEGKF*		filekeys   = GEN_NEW CIPHERKEYSFILEGKF(xpath);	
	CIPHERKEYPUBLICRSA*		publickey  = NULL;
	CIPHERKEYPRIVATERSA*	privatekey = NULL;		
		
	publickey  = (CIPHERKEYPUBLICRSA*)filekeys->GetKey(CIPHERKEYTYPE_RSA_PUBLIC);
	privatekey = (CIPHERKEYPRIVATERSA*)filekeys->GetKey(CIPHERKEYTYPE_RSA_PRIVATE);

	if(!publickey || !privatekey)
		{
			status = false;

		} else status = true;

	XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("Load RSA keys : %s"), (status?_L("Ok."):_L("Fail.")));	
	
	if(status)
	  {
      XBUFFER input;
      XBYTE   inputdata[]	= "Esta es una prueba de un texto largo para ser encriptado usando la RSA. La prueba consiste en que sea mas largo que la clave, osea mas de 128 bytes de largo, y que ademas tenga una longitud que no sea complemento de 2, para que queden bien los Paddings internos de la funcion. Pues eso. se acabo el rollo de pollo.";

      input.Delete();
	    input.Add((XBYTE*)inputdata, sizeof(inputdata));

      XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("Data to cipher:"));	
      XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, input);

      status = false;
  
	    if(cipher->SetKey(publickey))
		    {
			    if(cipher->SetKey(privatekey)) 
				    {					
					    if(cipher->Cipher(input, CIPHERKEYTYPE_RSA_PRIVATE))
						    {
                  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("Data cipher:"));	
                  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, (*cipher->GetResult()));

							    cipher->Uncipher((*cipher->GetResult()), CIPHERKEYTYPE_RSA_PUBLIC); 
						    }

					    status = input.Compare(cipher->GetResult());						  
				    }
		    }
    }
		
	XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("Test RSA keys : %s"), (status?_L("Ok."):_L("Fail.")));	

	GEN_DELETE filekeys;
	
	GEN_DELETE cipher;

	return status;
  */ 
 
  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_CipherECDSAX25519(DEVTESTS_CONSOLE* tests)
* @brief      Runs the cipher ecdsax25519 test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_CipherECDSAX25519(DEVTESTS_CONSOLE* tests)
{
  CIPHERECDSAX25519  curve25519[2];
  bool              status           = false; 

  for(int c=0; c<2; c++)
    {
      status = curve25519[c].GenerateRandomPrivateKey();
      
      XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("Curve 25519 Private key %d: %s" ), c+1, status?_L("Ok"):_L("Error!")); 
      XTRACE_PRINTDATABLOCKCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), curve25519[c].GetKey(CIPHERECDSAX25519_TYPEKEY_PRIVATE), 32, 1, 32); 

      if(!status) break;

      status = curve25519[c].CreatePublicKey();

      XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("Curve 25519 Public key %d: %s" ), c+1, status?_L("Ok"):_L("Error!")); 
      XTRACE_PRINTDATABLOCKCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), curve25519[c].GetKey(CIPHERECDSAX25519_TYPEKEY_PUBLIC), 32, 1, 32);    

      if(!status) break;     
    }

  if(status)
    {   
      curve25519[0].CreateSharedKey(curve25519[1].GetKey(CIPHERECDSAX25519_TYPEKEY_PUBLIC));
      curve25519[1].CreateSharedKey(curve25519[0].GetKey(CIPHERECDSAX25519_TYPEKEY_PUBLIC));

      for(int c=0; c<2; c++)
        {    
          status = curve25519[c].GetKey(CIPHERECDSAX25519_TYPEKEY_SHARED)?true:false;

          XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("Curve 25519 Shared key %d: %s" ), c+1, status?_L("Ok"):_L("Error!")); 
          if(status) 
            {
              XTRACE_PRINTDATABLOCKCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), curve25519[c].GetKey(CIPHERECDSAX25519_TYPEKEY_SHARED), 32, 1, 32);         
            }

          if(!status) break;
        }
     
      if(status)
        {      
          for(int c=0; c<CIPHERECDSAX25519_MAXKEY; c++)
            {
              if(curve25519[0].GetKey(CIPHERECDSAX25519_TYPEKEY_SHARED)[c] != curve25519[1].GetKey(CIPHERECDSAX25519_TYPEKEY_SHARED)[c]) status = false;
            }

          XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("Curve 25519 Shared  Key are equal : %s"), status?_L("Ok"):_L("Error!")); 
        }

    }

  XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("Curve 25519 All generated : %s"), status?_L("Ok"):_L("Error!")); 

  return status ;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOStreamTCPIP(DEVTESTS_CONSOLE* tests)
* @brief      Runs the diostream tcpip test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOStreamTCPIP(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  DIOSTREAMTCPIPCONFIG  diostreamcfg;
  DIOSTREAM*            diostream    = NULL;
  XSTRING               line;
  bool                  status       = false;

  diostreamcfg.GetRemoteURL()->Set(_L("endorasoft.com"));
  diostreamcfg.SetMode(DIOSTREAMMODE_CLIENT);
  diostreamcfg.SetRemotePort(25);

  line.Format(_L("Server [%s]: %d"), diostreamcfg.GetRemoteURL()->Get(), diostreamcfg.GetRemotePort());
  tests->console->Printf(_L(" %s\n"), line.Get());
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, line.Get());

  diostream = GEN_DIOFACTORY.CreateStreamIO(&diostreamcfg);
  if(!diostream) return false;
  
  if(diostream->Open())
    {
      status = diostream->WaitToConnected(5);

      line.Format(_L("Connection status: %s"), status?_L("Connected."):_L("No connected."));  
      tests->console->Printf(_L(" %s\n"), line.Get());
      XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), line.Get());            

      if(status)
        {       
          XBUFFER buffer;
          XDWORD  size = 0;
        
          buffer.Resize(100);

          status = diostream->WaitToFilledReadingBuffer(30, 5);
          if(status)
            {
              size = diostream->Read(buffer);
            }

          line.Format(_L("Read: %d bytes"), size);  
          tests->console->Printf(_L(" %s\n"), line.Get());
          XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), line.Get());             
        }
  
      status = diostream->Close();

      line.Format(_L("Close connection: %s"), status?_L("Ok."):_L("Error!"));  
      tests->console->Printf(_L(" %s\n\n"), line.Get());
      XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), line.Get());                                 
    }

  GEN_DIOFACTORY.DeleteStreamIO(diostream);
  
  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOStreamTLS(DEVTESTS_CONSOLE* tests)
* @brief      Runs the diostream tls test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOStreamTLS(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  bool status = false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("[ Embedded X.509 trusted roots ]\n"));

  DIOSTREAMTLSCONFIG defaultrootsconfig;

  status = defaultrootsconfig.TrustedRoots_AddDefaults();
  status = status && !defaultrootsconfig.GetTrustedRoots()->IsEmpty();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Supported RSA roots are loaded"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("[ X25519 known keys from RFC 7748 ]\n"));

  XBYTE aliceprivate[] = { 0x77, 0x07, 0x6D, 0x0A, 0x73, 0x18, 0xA5, 0x7D, 0x3C, 0x16, 0xC1, 0x72, 0x51, 0xB2, 0x66, 0x45,
                           0xDF, 0x4C, 0x2F, 0x87, 0xEB, 0xC0, 0x99, 0x2A, 0xB1, 0x77, 0xFB, 0xA5, 0x1D, 0xB9, 0x2C, 0x2A };
  XBYTE alicepublic[]  = { 0x85, 0x20, 0xF0, 0x09, 0x89, 0x30, 0xA7, 0x54, 0x74, 0x8B, 0x7D, 0xDC, 0xB4, 0x3E, 0xF7, 0x5A,
                           0x0D, 0xBF, 0x3A, 0x0D, 0x26, 0x38, 0x1A, 0xF4, 0xEB, 0xA4, 0xA9, 0x8E, 0xAA, 0x9B, 0x4E, 0x6A };
  XBYTE bobprivate[]   = { 0x5D, 0xAB, 0x08, 0x7E, 0x62, 0x4A, 0x8A, 0x4B, 0x79, 0xE1, 0x7F, 0x8B, 0x83, 0x80, 0x0E, 0xE6,
                           0x6F, 0x3B, 0xB1, 0x29, 0x26, 0x18, 0xB6, 0xFD, 0x1C, 0x2F, 0x8B, 0x27, 0xFF, 0x88, 0xE0, 0xEB };
  XBYTE bobpublic[]    = { 0xDE, 0x9E, 0xDB, 0x7D, 0x7B, 0x7D, 0xC1, 0xB4, 0xD3, 0x5B, 0x61, 0xC2, 0xEC, 0xE4, 0x35, 0x37,
                           0x3F, 0x83, 0x43, 0xC8, 0x5B, 0x78, 0x67, 0x4D, 0xAD, 0xFC, 0x7E, 0x14, 0x6F, 0x88, 0x2B, 0x4F };
  XBYTE sharedkey[]    = { 0x4A, 0x5D, 0x9D, 0x5B, 0xA4, 0xCE, 0x2D, 0xE1, 0x72, 0x8E, 0x3B, 0xF4, 0x80, 0x35, 0x0F, 0x25,
                           0xE0, 0x7E, 0x21, 0xC9, 0x47, 0xD1, 0x9E, 0x33, 0x76, 0xF0, 0x9B, 0x3C, 0x1E, 0x16, 0x17, 0x42 };

  CIPHERECDSAX25519 alice;
  CIPHERECDSAX25519 bob;

  status = alice.GenerateRandomPrivateKey() && bob.GenerateRandomPrivateKey();

  if(status)
    {
      memcpy(alice.GetKey(CIPHERECDSAX25519_TYPEKEY_PRIVATE), aliceprivate, sizeof(aliceprivate));
      memcpy(bob.GetKey(CIPHERECDSAX25519_TYPEKEY_PRIVATE), bobprivate, sizeof(bobprivate));

      status = alice.CreatePublicKey() && bob.CreatePublicKey();
    }

  if(status)
    {
      status = !memcmp(alice.GetKey(CIPHERECDSAX25519_TYPEKEY_PUBLIC), alicepublic, sizeof(alicepublic));
      status = status && !memcmp(bob.GetKey(CIPHERECDSAX25519_TYPEKEY_PUBLIC), bobpublic, sizeof(bobpublic));
    }

  if(status)
    {
      status = alice.CreateSharedKey(bob.GetKey(CIPHERECDSAX25519_TYPEKEY_PUBLIC));
      status = status && bob.CreateSharedKey(alice.GetKey(CIPHERECDSAX25519_TYPEKEY_PUBLIC));
      status = status && !memcmp(alice.GetKey(CIPHERECDSAX25519_TYPEKEY_SHARED), sharedkey, sizeof(sharedkey));
      status = status && !memcmp(bob.GetKey(CIPHERECDSAX25519_TYPEKEY_SHARED), sharedkey, sizeof(sharedkey));
    }

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Public and shared keys match the RFC"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  XBYTE newsessionticket[] = { DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_NEW_SESSION_TICKET, 0x00, 0x00, 0x00 };
  XBYTE keyupdate[]        = { DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_KEY_UPDATE        , 0x00, 0x00, 0x01, 0x00 };

  XBYTE* messages[] =
  {
    DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO,
    DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO,
    DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS,
    DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE,
    DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY,
    DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED,
    newsessionticket,
    keyupdate,
  };

  XDWORD messagesizes[] =
  {
    sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO),
    sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO),
    sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS),
    sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE),
    sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY),
    sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED),
    sizeof(newsessionticket),
    sizeof(keyupdate),
  };

  XBYTE messagetypes[] =
  {
    DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_CLIENT_HELLO,
    DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_SERVER_HELLO,
    DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_ENCRYPTED_EXTENSIONS,
    DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_CERTIFICATE,
    DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_CERTIFICATE_VERIFY,
    DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_FINISHED,
    DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_NEW_SESSION_TICKET,
    DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_KEY_UPDATE,
  };

  tests->console->Printf(_L("[ Generic TLS 1.3 handshake codec ]\n"));

  for(XDWORD c=0; c<(sizeof(messages) / sizeof(messages[0])); c++)
    {
      DIOSTREAMTLS_MSG_HANDSHAKE message;
      XBUFFER                   input;
      XBUFFER                   encoded;
      bool                      status;

      input.Add(messages[c], messagesizes[c]);

      status = message.GetFromBuffer(input, false);
      status = status && input.IsEmpty();
      status = status && (message.GetMsgType() == messagetypes[c]);
      status = status && (message.GetLength() == (messagesizes[c] - DIOSTREAMTLS_MSG_HANDSHAKEHEADER_SIZE));
      status = status && message.SetToBuffer(encoded, false);
      status = status && encoded.Compare(messages[c], messagesizes[c]);

      tests->console->Printf(_L(" Message %-2d, type %-3d, round trip : %s\n"), c+1, messagetypes[c], status?_L("Ok."):_L("Error!"));
      if(!status) return false;
    }

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ TLS alert codec ]\n"));

  DIOSTREAMTLS_MSG_RECORD<DIOSTREAMTLS_MSG_ALERT> alertrecord;
  DIOSTREAMTLS_MSG_RECORD<DIOSTREAMTLS_MSG_ALERT> decodedalertrecord;
  XBUFFER                                        alertencoded;

  alertrecord.SetContenType(DIOSTREAMTLS_MSG_CONTENTTYPE_ALERT);
  alertrecord.SetProtocolVersion(DIOSTREAMTLS_MSG_VERSION_TLS_1_2);
  alertrecord.GetFragment()->SetLevel(DIOSTREAMTLS_ALERT_LEVEL_FATAL);
  alertrecord.GetFragment()->SetDescription(DIOSTREAMTLS_ALERT_DESCRIPTION_DECODE_ERROR);

  status = alertrecord.SetToBuffer(alertencoded, false);
  status = status && decodedalertrecord.GetFromBuffer(alertencoded, false);
  status = status && alertencoded.IsEmpty();
  status = status && (decodedalertrecord.GetContenType() == DIOSTREAMTLS_MSG_CONTENTTYPE_ALERT);
  status = status && (decodedalertrecord.GetFragment()->GetLevel() == DIOSTREAMTLS_ALERT_LEVEL_FATAL);
  status = status && (decodedalertrecord.GetFragment()->GetDescription() == DIOSTREAMTLS_ALERT_DESCRIPTION_DECODE_ERROR);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("An Alert record is decoded and rebuilt"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ Typed ClientHello and ServerHello codecs ]\n"));

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_CLIENTHELLO> clienthello;
  XBUFFER                                                          clientinput;
  XBUFFER                                                          clientencoded;

  clientinput.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));

  status = clienthello.GetFromBuffer(clientinput, false);
  status = status && clientinput.IsEmpty();
  status = status && (clienthello.GetMsgType() == DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_CLIENT_HELLO);
  status = status && (clienthello.GetBody()->GetCipherSuites()->GetSize() == 3);
  status = status && (clienthello.GetBody()->Extensions_GetAll()->GetSize() == 9);

  bool unknownextension = false;

  for(XDWORD c=0; c<clienthello.GetBody()->Extensions_GetAll()->GetSize(); c++)
    {
      DIOSTREAMTLS_MSG_EXTENSION* extension = clienthello.GetBody()->Extensions_GetAll()->Get(c);

      if(extension && (extension->GetType() == 0x001C))
        {
          unknownextension = true;
          break;
        }
    }

  status = status && unknownextension;
  status = status && clienthello.SetToBuffer(clientencoded, false);
  status = status && clientencoded.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("RFC ClientHello is decoded and rebuilt"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_SERVERHELLO> serverhello;
  XBUFFER                                                          serverinput;
  XBUFFER                                                          serverencoded;

  serverinput.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO));

  status = serverhello.GetFromBuffer(serverinput, false);
  status = status && serverinput.IsEmpty();
  status = status && (serverhello.GetMsgType() == DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_SERVER_HELLO);
  status = status && (serverhello.GetBody()->GetCipherSuite() == DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256);
  status = status && (serverhello.GetBody()->Extensions_GetAll()->GetSize() == 2);
  status = status && !serverhello.GetBody()->IsHelloRetryRequest();
  status = status && serverhello.SetToBuffer(serverencoded, false);
  status = status && serverencoded.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("RFC ServerHello is decoded and rebuilt"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBUFFER invalidclienthello;
  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_CLIENTHELLO> invalidmessage;

  invalidclienthello.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));
  invalidclienthello.Set((XBYTE)0x92, 50);                                      // Extensions say one byte more than the body contains

  XDWORD invalidsize = invalidclienthello.GetSize();

  status = !invalidmessage.GetFromBuffer(invalidclienthello, false);
  status = status && (invalidclienthello.GetSize() == invalidsize);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("An invalid extension length is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ Fragmented, coalesced and long handshake messages ]\n"));

  XBUFFER partial;
  XBUFFER extracted;

  partial.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, DIOSTREAMTLS_MSG_HANDSHAKEHEADER_SIZE - 1);
  status = !DIOSTREAMTLS_MSG_HANDSHAKE::Message_Extract(partial, extracted);
  status = status && (partial.GetSize() == (DIOSTREAMTLS_MSG_HANDSHAKEHEADER_SIZE - 1));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("An incomplete header consumes nothing"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  partial.Delete();
  partial.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO) - 1);
  status = !DIOSTREAMTLS_MSG_HANDSHAKE::Message_Extract(partial, extracted);
  status = status && (partial.GetSize() == (sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO) - 1));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("An incomplete body consumes nothing"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  partial.Delete();
  partial.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, 17);
  status = !DIOSTREAMTLS_MSG_HANDSHAKE::Message_Extract(partial, extracted);
  partial.Add(&DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO[17], sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO) - 17);
  status = status && DIOSTREAMTLS_MSG_HANDSHAKE::Message_Extract(partial, extracted);
  status = status && extracted.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));
  status = status && partial.IsEmpty();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("A fragmented message is retained and joined"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBUFFER coalesced;
  XBUFFER firstmessage;
  XBUFFER secondmessage;

  coalesced.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));
  coalesced.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO));

  status = DIOSTREAMTLS_MSG_HANDSHAKE::Message_Extract(coalesced, firstmessage);
  status = status && firstmessage.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));
  status = status && DIOSTREAMTLS_MSG_HANDSHAKE::Message_Extract(coalesced, secondmessage);
  status = status && secondmessage.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO));
  status = status && coalesced.IsEmpty();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Two coalesced messages are separated"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS_MSG_HANDSHAKE longmessage;
  DIOSTREAMTLS_MSG_HANDSHAKE decodedlongmessage;
  XBUFFER                   longencoded;

  longmessage.SetMsgType(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_CERTIFICATE);
  longmessage.GetBody()->Resize(70000);
  longmessage.GetBody()->FillBuffer(0xA5);

  status = longmessage.SetToBuffer(longencoded, false);
  status = status && (longencoded.GetByte(1) == 0x01) && (longencoded.GetByte(2) == 0x11) && (longencoded.GetByte(3) == 0x70);
  status = status && decodedlongmessage.GetFromBuffer(longencoded, false);
  status = status && (decodedlongmessage.GetLength() == 70000);
  status = status && longencoded.IsEmpty();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("The 24-bit length exceeds 65535"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ Typed TLS 1.3 server flight codecs ]\n"));

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_ENCRYPTEDEXTENSIONS> typedextensions;
  XBUFFER                                                                   typedextensionsinput;
  XBUFFER                                                                   typedextensionsoutput;

  typedextensionsinput.Add(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS));

  status = typedextensions.GetFromBuffer(typedextensionsinput, false);
  status = status && typedextensionsinput.IsEmpty();
  status = status && (typedextensions.GetBody()->Extensions_GetAll()->GetSize() == 3);
  status = status && typedextensions.SetToBuffer(typedextensionsoutput, false);
  status = status && typedextensionsoutput.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("EncryptedExtensions typed round trip"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_CERTIFICATE> typedcertificate;
  XBUFFER                                                          typedcertificateinput;
  XBUFFER                                                          typedcertificateoutput;

  typedcertificateinput.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE));

  status = typedcertificate.GetFromBuffer(typedcertificateinput, false);
  status = status && typedcertificateinput.IsEmpty();
  status = status && typedcertificate.GetBody()->GetRequestContext()->IsEmpty();
  status = status && (typedcertificate.GetBody()->CertificateList_GetAll()->GetSize() == 1);
  status = status && (typedcertificate.GetBody()->CertificateList_GetAll()->Get(0)->GetCertificateData()->GetSize() == 432);
  status = status && typedcertificate.SetToBuffer(typedcertificateoutput, false);
  status = status && typedcertificateoutput.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Certificate typed round trip"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_CERTIFICATEVERIFY> typedcertificateverify;
  XBUFFER                                                                typedcertificateverifyinput;
  XBUFFER                                                                typedcertificateverifyoutput;

  typedcertificateverifyinput.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY));

  status = typedcertificateverify.GetFromBuffer(typedcertificateverifyinput, false);
  status = status && typedcertificateverifyinput.IsEmpty();
  status = status && (typedcertificateverify.GetBody()->GetAlgorithm() == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA256);
  status = status && (typedcertificateverify.GetBody()->GetSignature()->GetSize() == 128);
  status = status && typedcertificateverify.SetToBuffer(typedcertificateverifyoutput, false);
  status = status && typedcertificateverifyoutput.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("CertificateVerify typed round trip"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_FINISHED> typedfinished;
  XBUFFER                                                       typedfinishedinput;
  XBUFFER                                                       typedfinishedoutput;

  typedfinishedinput.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED));

  status = typedfinished.GetFromBuffer(typedfinishedinput, false);
  status = status && typedfinishedinput.IsEmpty();
  status = status && (typedfinished.GetBody()->GetVerifyData()->GetSize() == 32);
  status = status && typedfinished.SetToBuffer(typedfinishedoutput, false);
  status = status && typedfinishedoutput.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Finished typed round trip"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBYTE certificaterequestdata[] = { DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_CERTIFICATE_REQUEST, 0x00, 0x00, 0x0B,
                                     0x00, 0x00, 0x08, 0x00, 0x0D, 0x00, 0x04, 0x00, 0x02, 0x08, 0x04 };

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_CERTIFICATEREQUEST> typedcertificaterequest;
  XBUFFER                                                                 typedcertificaterequestinput;
  XBUFFER                                                                 typedcertificaterequestoutput;

  typedcertificaterequestinput.Add(certificaterequestdata, sizeof(certificaterequestdata));

  status = typedcertificaterequest.GetFromBuffer(typedcertificaterequestinput, false);
  status = status && typedcertificaterequestinput.IsEmpty();
  status = status && typedcertificaterequest.GetBody()->GetRequestContext()->IsEmpty();
  status = status && (typedcertificaterequest.GetBody()->Extensions_GetAll()->GetSize() == 1);
  status = status && typedcertificaterequest.SetToBuffer(typedcertificaterequestoutput, false);
  status = status && typedcertificaterequestoutput.Compare(certificaterequestdata, sizeof(certificaterequestdata));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("CertificateRequest typed round trip"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ Generated TLS 1.3 ClientHello and automatic key share ]\n"));

  DIOSTREAMTLS13SESSION          generatedsession;
  DIOSTREAMTLS13HANDSHAKECLIENT generatedclient;
  DIOSTREAMTLSCONFIG          generatedconfig;
  XBUFFER                     generatedclienthello;
  XBUFFER                     generatedrecords;
  XBUFFER                     generatedinput;
  XBUFFER                     generatedplain;
  DIOSTREAMTLS_CONTENTTYPE    generatedtype = (DIOSTREAMTLS_CONTENTTYPE)0;

  status = generatedsession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && generatedclient.Ini(&generatedsession);
  status = status && generatedconfig.ApplicationProtocol_Add(DIOSTREAMTLS_ALPN_TYPE_HTTP_1_1);
  status = status && generatedclient.Capabilities_Set(&generatedconfig);
  status = status && generatedclient.ClientHello_Create(_L("localhost"), generatedclienthello, generatedrecords);
  status = status && generatedsession.RecordInput_Add(generatedrecords);
  status = status && (generatedsession.Record_Extract(generatedtype, generatedplain) == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && (generatedtype == DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE);
  status = status && generatedplain.Compare(generatedclienthello);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("ClientHello is wrapped for transport"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_CLIENTHELLO> generatedmessage;
  DIOSTREAMTLS_MSG_EXTENSION_KEY*                                  generatedkey = NULL;
  bool                                                             generatedSNI = false;
  bool                                                             generatedgroup = false;
  bool                                                             generatedsignature = false;
  bool                                                             generatedcertificatesignature = false;
  bool                                                             generatedversion = false;
  bool                                                             generatedALPN = false;

  generatedinput.Add(generatedclienthello);

  status = generatedmessage.GetFromBuffer(generatedinput, false);
  status = status && generatedinput.IsEmpty();
  status = status && (generatedmessage.GetBody()->GetClientVersion() == DIOSTREAMTLS_MSG_VERSION_TLS_1_2);
  status = status && (generatedmessage.GetBody()->GetSessionIDLength() == DIOSTREAMTLS_MSG_SESSIONID_SIZE);
  status = status && (generatedmessage.GetBody()->GetCipherSuites()->GetSize() == 2);
  status = status && (generatedmessage.GetBody()->GetCipherSuites()->Get(0) == DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256);
  status = status && (generatedmessage.GetBody()->GetCipherSuites()->Get(1) == DIOSTREAMTLS_MSG_CIPHER_AES_256_GCM_SHA384);

  for(XDWORD c=0; c<generatedmessage.GetBody()->Extensions_GetAll()->GetSize(); c++)
    {
      DIOSTREAMTLS_MSG_EXTENSION* extension = generatedmessage.GetBody()->Extensions_GetAll()->Get(c);
      if(!extension) return false;

      switch(extension->GetType())
        {
          case DIOSTREAMTLS_MSG_EXTENSION_TYPE_SNI                 : { DIOSTREAMTLS_MSG_EXTENSION_SNI* SNI;

                                                                      SNI = (DIOSTREAMTLS_MSG_EXTENSION_SNI*)extension;
                                                                      generatedSNI = (SNI->List_Get()->GetSize() == 1) &&
                                                                                     !SNI->List_Get()->Get(0)->Name_GetHost()->Compare(_L("localhost"));
                                                                    }
                                                                    break;

          case DIOSTREAMTLS_MSG_EXTENSION_TYPE_SUPPORTEDGROUPS     : { DIOSTREAMTLS_MSG_EXTENSION_SUPPORTEDGROUPS* groups;

                                                                      groups = (DIOSTREAMTLS_MSG_EXTENSION_SUPPORTEDGROUPS*)extension;
                                                                      generatedgroup = (groups->List_Get()->GetSize() == 3) &&
                                                                                       (groups->List_Get()->Get(0) == DIOSTREAMTLS_MSG_CURVEID_X25519) &&
                                                                                       (groups->List_Get()->Get(1) == DIOSTREAMTLS_MSG_CURVEID_SECP256R1) &&
                                                                                       (groups->List_Get()->Get(2) == DIOSTREAMTLS_MSG_CURVEID_SECP384R1);
                                                                    }
                                                                    break;

          case DIOSTREAMTLS_MSG_EXTENSION_TYPE_SIGNATUREALGORITHMS : { DIOSTREAMTLS_MSG_EXTENSION_SIGNATUREALGORITHMS* algorithms;

                                                                       algorithms = (DIOSTREAMTLS_MSG_EXTENSION_SIGNATUREALGORITHMS*)extension;
                                                                       generatedsignature = (algorithms->List_Get()->GetSize() == 3) &&
                                                                                            (algorithms->List_Get()->Get(0) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA256) &&
                                                                                            (algorithms->List_Get()->Get(1) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA384) &&
                                                                                            (algorithms->List_Get()->Get(2) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA512);
                                                                     }
                                                                     break;

          case DIOSTREAMTLS_MSG_EXTENSION_TYPE_SIGNATUREALGORITHMSCERT : { DIOSTREAMTLS_MSG_EXTENSION_SIGNATUREALGORITHMSCERT* algorithms;

                                                                           algorithms = (DIOSTREAMTLS_MSG_EXTENSION_SIGNATUREALGORITHMSCERT*)extension;
                                                                           generatedcertificatesignature = (algorithms->List_Get()->GetSize() == 9) &&
                                                                                                           (algorithms->List_Get()->Get(0) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA256) &&
                                                                                                           (algorithms->List_Get()->Get(1) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA384) &&
                                                                                                           (algorithms->List_Get()->Get(2) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA512) &&
                                                                                                           (algorithms->List_Get()->Get(3) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PKCS1_SHA256) &&
                                                                                                           (algorithms->List_Get()->Get(4) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PKCS1_SHA384) &&
                                                                                                           (algorithms->List_Get()->Get(5) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PKCS1_SHA512) &&
                                                                                                           (algorithms->List_Get()->Get(6) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_ECDSA_SECP256R1_SHA256) &&
                                                                                                           (algorithms->List_Get()->Get(7) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_ECDSA_SECP384R1_SHA384) &&
                                                                                                           (algorithms->List_Get()->Get(8) == DIOSTREAMTLS_MSG_SIGNATURESCHEME_ECDSA_SECP521R1_SHA512);
                                                                         }
                                                                         break;

          case DIOSTREAMTLS_MSG_EXTENSION_TYPE_ALPN                : { DIOSTREAMTLS_MSG_EXTENSION_ALPN* ALPN;
                                                                       DIOSTREAMTLS_ALPN_TYPE           applicationprotocol;

                                                                       ALPN = (DIOSTREAMTLS_MSG_EXTENSION_ALPN*)extension;
                                                                       generatedALPN = (ALPN->List_GetNProtocols() == 1) &&
                                                                                       ALPN->List_Get(0, applicationprotocol) &&
                                                                                       (applicationprotocol == DIOSTREAMTLS_ALPN_TYPE_HTTP_1_1);
                                                                     }
                                                                     break;

          case DIOSTREAMTLS_MSG_EXTENSION_TYPE_SUPPORTEDVERSIONS   : { DIOSTREAMTLS_MSG_EXTENSION_SUPPORTEDVERSIONS* versions;

                                                                       versions = (DIOSTREAMTLS_MSG_EXTENSION_SUPPORTEDVERSIONS*)extension;
                                                                       generatedversion = (versions->List_Get()->GetSize() == 1) &&
                                                                                          (versions->List_Get()->Get(0) == DIOSTREAMTLS_MSG_VERSION_TLS_1_3);
                                                                     }
                                                                     break;

          case DIOSTREAMTLS_MSG_EXTENSION_TYPE_KEYSHARE            : { DIOSTREAMTLS_MSG_EXTENSION_KEYSHARE* keyshare;

                                                                       keyshare = (DIOSTREAMTLS_MSG_EXTENSION_KEYSHARE*)extension;
                                                                       if(keyshare->List_Get()->GetSize() == 1)
                                                                         {
                                                                           generatedkey = keyshare->List_Get()->Get(0);
                                                                         }
                                                                     }
                                                                     break;

                                                               default : break;
        }
    }

  status = status && generatedSNI && generatedgroup && generatedsignature && generatedcertificatesignature &&
                     generatedversion && generatedALPN;
  status = status && generatedkey;
  status = status && (generatedkey->GetKeyType() == DIOSTREAMTLS_MSG_CURVEID_X25519);
  status = status && (generatedkey->GetKeyData()->GetSize() == CIPHERECDSAX25519_MAXKEY);
  status = status && !memcmp(generatedkey->GetKeyData()->Get(), generatedsession.GetKeyExchange()->GetKey(CIPHERECDSAX25519_TYPEKEY_PUBLIC), CIPHERECDSAX25519_MAXKEY);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("ClientHello offers only implemented features"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  CIPHERECDSAX25519                                                generatedserverkey;
  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_SERVERHELLO> generatedserverhello;
  DIOSTREAMTLS_MSG_EXTENSION_SUPPORTEDVERSIONS_SERVER*             generatedserverversion;
  DIOSTREAMTLS_MSG_EXTENSION_KEYSHARE_SERVER*                       generatedserverkeyshare;
  XBUFFER                                                           generatedserverhellobuffer;

  status = generatedserverkey.GenerateRandomPrivateKey() && generatedserverkey.CreatePublicKey();
  status = status && generatedserverkey.CreateSharedKey(generatedkey->GetKeyData()->Get());
  if(!status) return false;

  generatedserverhello.SetMsgType(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_SERVER_HELLO);
  generatedserverhello.GetBody()->SetLegacyVersion(DIOSTREAMTLS_MSG_VERSION_TLS_1_2);

  for(XDWORD c=0; c<DIOSTREAMTLS_MSG_RANDOM_SIZE; c++)
    {
      generatedserverhello.GetBody()->GetRandom()[c] = (XBYTE)(c + 1);
    }

  generatedserverhello.GetBody()->SetSessionIDLength(generatedmessage.GetBody()->GetSessionIDLength());
  memcpy(generatedserverhello.GetBody()->GetSessionID(), generatedmessage.GetBody()->GetSessionID(), generatedmessage.GetBody()->GetSessionIDLength());
  generatedserverhello.GetBody()->SetCipherSuite(DIOSTREAMTLS_MSG_CIPHER_AES_256_GCM_SHA384);
  generatedserverhello.GetBody()->SetCompressionMethod(DIOSTREAMTLS_MSG_COMPRESS_METHOD_NULL);

  generatedserverversion = GEN_NEW DIOSTREAMTLS_MSG_EXTENSION_SUPPORTEDVERSIONS_SERVER();
  if(!generatedserverversion) return false;

  generatedserverversion->SetVersion(DIOSTREAMTLS_MSG_VERSION_TLS_1_3);
  if(!generatedserverhello.GetBody()->Extensions_Add(generatedserverversion))
    {
      GEN_DELETE generatedserverversion;
      return false;
    }

  generatedserverkeyshare = GEN_NEW DIOSTREAMTLS_MSG_EXTENSION_KEYSHARE_SERVER();
  if(!generatedserverkeyshare) return false;

  generatedserverkeyshare->GetKey()->SetKeyType(DIOSTREAMTLS_MSG_CURVEID_X25519);
  if(!generatedserverkeyshare->GetKey()->GetKeyData()->Add(generatedserverkey.GetKey(CIPHERECDSAX25519_TYPEKEY_PUBLIC),
                                                           CIPHERECDSAX25519_MAXKEY))
    {
      GEN_DELETE generatedserverkeyshare;
      return false;
    }

  if(!generatedserverhello.GetBody()->Extensions_Add(generatedserverkeyshare))
    {
      GEN_DELETE generatedserverkeyshare;
      return false;
    }

  status = status && generatedserverhello.SetToBuffer(generatedserverhellobuffer, false);
  status = status && generatedclient.ServerHello_Process(generatedserverhellobuffer);
  status = status && (generatedsession.GetKeySchedule()->GetCipherSuite() == DIOSTREAMTLS_MSG_CIPHER_AES_256_GCM_SHA384);
  status = status && (generatedsession.GetKeySchedule()->GetHashSize() == HASHSHA2_384_DIGEST_SIZE);
  status = status && (generatedclient.GetState() == DIOSTREAMTLS13HANDSHAKECLIENT_STATE_WAIT_ENCRYPTEDEXTENSIONS);
  status = status && (generatedsession.GetEpoch(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL) == DIOSTREAMTLS13SESSION_EPOCH_HANDSHAKE);
  status = status && (generatedsession.GetEpoch(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE) == DIOSTREAMTLS13SESSION_EPOCH_HANDSHAKE);
  status = status && !memcmp(generatedsession.GetKeyExchange()->GetKey(CIPHERECDSAX25519_TYPEKEY_SHARED), generatedserverkey.GetKey(CIPHERECDSAX25519_TYPEKEY_SHARED), CIPHERECDSAX25519_MAXKEY);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Server selects AES-256 and derives X25519"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_ENCRYPTEDEXTENSIONS> generatedencryptedextensions;
  DIOSTREAMTLS_MSG_EXTENSION_ALPN*                                         generatedserverALPN;
  XBUFFER                                                                  generatedencryptedextensionsbuffer;

  generatedencryptedextensions.SetMsgType(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_ENCRYPTED_EXTENSIONS);

  generatedserverALPN = GEN_NEW DIOSTREAMTLS_MSG_EXTENSION_ALPN();
  if(!generatedserverALPN) return false;

  if(!generatedserverALPN->List_Add(DIOSTREAMTLS_ALPN_TYPE_HTTP_1_1) ||
     !generatedencryptedextensions.GetBody()->Extensions_Add(generatedserverALPN))
    {
      GEN_DELETE generatedserverALPN;
      return false;
    }

  status = generatedencryptedextensions.SetToBuffer(generatedencryptedextensionsbuffer, false);
  status = status && generatedclient.Handshake_Process(generatedencryptedextensionsbuffer);
  status = status && generatedclient.IsApplicationProtocolNegotiated();
  status = status && (generatedclient.GetApplicationProtocol() == DIOSTREAMTLS_ALPN_TYPE_HTTP_1_1);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("ALPN selects the offered HTTP/1.1"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION                                                    invalidALPNsession;
  DIOSTREAMTLS13HANDSHAKECLIENT                                           invalidALPNclient;
  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_ENCRYPTEDEXTENSIONS> invalidALPNextensions;
  DIOSTREAMTLS_MSG_EXTENSION_ALPN*                                      invalidserverALPN;
  XBUFFER                                                               generatedsharedsecret;
  XBUFFER                                                               invalidALPNbuffer;

  generatedsharedsecret.Add(generatedserverkey.GetKey(CIPHERECDSAX25519_TYPEKEY_SHARED), CIPHERECDSAX25519_MAXKEY);
  invalidALPNextensions.SetMsgType(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_ENCRYPTED_EXTENSIONS);

  invalidserverALPN = GEN_NEW DIOSTREAMTLS_MSG_EXTENSION_ALPN();
  if(!invalidserverALPN) return false;

  if(!invalidserverALPN->List_Add(DIOSTREAMTLS_ALPN_TYPE_HTTP_2) ||
     !invalidALPNextensions.GetBody()->Extensions_Add(invalidserverALPN))
    {
      GEN_DELETE invalidserverALPN;
      return false;
    }

  status = invalidALPNextensions.SetToBuffer(invalidALPNbuffer, false);
  status = status && invalidALPNsession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && invalidALPNclient.Ini(&invalidALPNsession);
  status = status && invalidALPNclient.Start(generatedclienthello);
  status = status && invalidALPNclient.ServerHello_Process(generatedserverhellobuffer, generatedsharedsecret);
  status = status && !invalidALPNclient.Handshake_Process(invalidALPNbuffer);
  status = status && !invalidALPNclient.IsApplicationProtocolNegotiated();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("An unoffered ALPN protocol is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ ECDHE P-256 and HelloRetryRequest ]\n"));

  CIPHERECDSA P256clientcipher;
  CIPHERECDSA P256servercipher;
  XBUFFER     P256clientprivate;
  XBUFFER     P256clientpublic;
  XBUFFER     P256serverprivate;
  XBUFFER     P256serverpublic;
  XBUFFER     P256clientsecret;
  XBUFFER     P256serversecret;
  XBUFFER     invalidP256public;

  status = P256clientcipher.KeyPair_Create(P256clientprivate, P256clientpublic);
  status = status && P256servercipher.KeyPair_Create(P256serverprivate, P256serverpublic);
  status = status && P256clientcipher.SharedSecret_Create(P256clientprivate, P256serverpublic, P256clientsecret);
  status = status && P256servercipher.SharedSecret_Create(P256serverprivate, P256clientpublic, P256serversecret);
  status = status && P256clientsecret.Compare(P256serversecret);
  status = status && (P256clientsecret.GetSize() == CIPHERECDSA_P256_COORDINATE_SIZE);

  invalidP256public.Add(P256clientpublic);
  invalidP256public.Get()[invalidP256public.GetSize()-1] ^= 0x01;
  status = status && !P256clientcipher.PublicKey_Check(invalidP256public);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("ECDHE P-256 creates the same shared secret"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION          HRRsession;
  DIOSTREAMTLS13HANDSHAKECLIENT HRRclient;
  DIOSTREAMTLSCONFIG          HRRconfig;
  XBUFFER                     HRRfirstclienthello;
  XBUFFER                     HRRfirstrecords;
  XBUFFER                     HRRbuffer;
  XBUFFER                     HRRsecondclienthello;
  XBUFFER                     HRRsecondrecords;

  status = HRRsession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && HRRclient.Ini(&HRRsession);
  status = status && HRRclient.Capabilities_Set(&HRRconfig);
  status = status && HRRclient.ClientHello_Create(_L("localhost"), HRRfirstclienthello, HRRfirstrecords);

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_CLIENTHELLO> HRRfirstmessage;
  XBUFFER                                                          HRRfirstinput;

  HRRfirstinput.Add(HRRfirstclienthello);
  status = status && HRRfirstmessage.GetFromBuffer(HRRfirstinput, false) && HRRfirstinput.IsEmpty();

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_SERVERHELLO> HRRmessage;
  DIOSTREAMTLS_MSG_EXTENSION_SUPPORTEDVERSIONS_SERVER*             HRRversion;
  DIOSTREAMTLS_MSG_EXTENSION_KEYSHARE_HELLORETRYREQUEST*           HRRkeyshare;
  DIOSTREAMTLS_MSG_EXTENSION_UNKNOWN*                              HRRcookie;
  XBYTE                                                            HRRrandom[] =
  {
    0xCF, 0x21, 0xAD, 0x74, 0xE5, 0x9A, 0x61, 0x11, 0xBE, 0x1D, 0x8C, 0x02, 0x1E, 0x65, 0xB8, 0x91,
    0xC2, 0xA2, 0x11, 0x16, 0x7A, 0xBB, 0x8C, 0x5E, 0x07, 0x9E, 0x09, 0xE2, 0xC8, 0xA8, 0x33, 0x9C,
  };
  XBYTE                                                            HRRcookiedata[] =
  {
    0x00, 0x04, 0x11, 0x22, 0x33, 0x44,
  };

  HRRmessage.SetMsgType(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_SERVER_HELLO);
  HRRmessage.GetBody()->SetLegacyVersion(DIOSTREAMTLS_MSG_VERSION_TLS_1_2);
  memcpy(HRRmessage.GetBody()->GetRandom(), HRRrandom, sizeof(HRRrandom));
  HRRmessage.GetBody()->SetSessionIDLength(HRRfirstmessage.GetBody()->GetSessionIDLength());
  memcpy(HRRmessage.GetBody()->GetSessionID(), HRRfirstmessage.GetBody()->GetSessionID(), HRRfirstmessage.GetBody()->GetSessionIDLength());
  HRRmessage.GetBody()->SetCipherSuite(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256);
  HRRmessage.GetBody()->SetCompressionMethod(DIOSTREAMTLS_MSG_COMPRESS_METHOD_NULL);

  HRRversion = GEN_NEW DIOSTREAMTLS_MSG_EXTENSION_SUPPORTEDVERSIONS_SERVER();
  HRRkeyshare = GEN_NEW DIOSTREAMTLS_MSG_EXTENSION_KEYSHARE_HELLORETRYREQUEST();
  HRRcookie = GEN_NEW DIOSTREAMTLS_MSG_EXTENSION_UNKNOWN();

  if(!HRRversion || !HRRkeyshare || !HRRcookie) return false;

  HRRversion->SetVersion(DIOSTREAMTLS_MSG_VERSION_TLS_1_3);
  HRRkeyshare->SetSelectedGroup(DIOSTREAMTLS_MSG_CURVEID_SECP256R1);
  HRRcookie->SetType(DIOSTREAMTLS_MSG_EXTENSION_TYPE_COOKIE);

  if(!HRRcookie->GetData()->Add(HRRcookiedata, sizeof(HRRcookiedata)) ||
     !HRRmessage.GetBody()->Extensions_Add(HRRversion) ||
     !HRRmessage.GetBody()->Extensions_Add(HRRkeyshare) ||
     !HRRmessage.GetBody()->Extensions_Add(HRRcookie))
    {
      return false;
    }

  status = status && HRRmessage.SetToBuffer(HRRbuffer, false);
  status = status && HRRclient.HelloRetryRequest_Process(HRRbuffer, HRRsecondclienthello, HRRsecondrecords);
  status = status && (HRRclient.GetState() == DIOSTREAMTLS13HANDSHAKECLIENT_STATE_WAIT_SERVERHELLO);
  status = status && (HRRsession.GetTranscript()->GetByte(0) == DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_MESSAGE_HASH);
  status = status && (HRRsession.GetTranscript()->GetByte(3) == HASHSHA2_256_DIGEST_SIZE);

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_CLIENTHELLO> HRRsecondmessage;
  XBUFFER                                                          HRRsecondinput;
  DIOSTREAMTLS_MSG_EXTENSION_KEY*                                  HRRsecondkey = NULL;
  bool                                                             HRRcookieechoed = false;

  HRRsecondinput.Add(HRRsecondclienthello);
  status = status && HRRsecondmessage.GetFromBuffer(HRRsecondinput, false) && HRRsecondinput.IsEmpty();
  status = status && !memcmp(HRRsecondmessage.GetBody()->GetRandom(), HRRfirstmessage.GetBody()->GetRandom(), DIOSTREAMTLS_MSG_RANDOM_SIZE);

  for(XDWORD c=0; c<HRRsecondmessage.GetBody()->Extensions_GetAll()->GetSize(); c++)
    {
      DIOSTREAMTLS_MSG_EXTENSION* extension = HRRsecondmessage.GetBody()->Extensions_GetAll()->Get(c);

      if(extension && (extension->GetType() == DIOSTREAMTLS_MSG_EXTENSION_TYPE_KEYSHARE))
        {
          DIOSTREAMTLS_MSG_EXTENSION_KEYSHARE* keyshare = (DIOSTREAMTLS_MSG_EXTENSION_KEYSHARE*)extension;

          if(keyshare->List_Get()->GetSize() == 1) HRRsecondkey = keyshare->List_Get()->Get(0);
        }

      if(extension && (extension->GetType() == DIOSTREAMTLS_MSG_EXTENSION_TYPE_COOKIE))
        {
          DIOSTREAMTLS_MSG_EXTENSION_UNKNOWN* cookie = (DIOSTREAMTLS_MSG_EXTENSION_UNKNOWN*)extension;

          HRRcookieechoed = cookie->GetData()->Compare(HRRcookiedata, sizeof(HRRcookiedata));
        }
    }

  status = status && HRRsecondkey && HRRcookieechoed;
  status = status && (HRRsecondkey->GetKeyType() == DIOSTREAMTLS_MSG_CURVEID_SECP256R1);
  status = status && (HRRsecondkey->GetKeyData()->GetSize() == CIPHERECDSA_P256_PUBLICKEY_SIZE);
  status = status && P256servercipher.PublicKey_Check((*HRRsecondkey->GetKeyData()));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("HRR rebuilds transcript and ClientHello2"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  CIPHERECDSA                                                      HRRservercipher;
  XBUFFER                                                          HRRserverprivate;
  XBUFFER                                                          HRRserverpublic;
  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_SERVERHELLO> HRRserverhello;
  DIOSTREAMTLS_MSG_EXTENSION_SUPPORTEDVERSIONS_SERVER*             HRRserverversion;
  DIOSTREAMTLS_MSG_EXTENSION_KEYSHARE_SERVER*                       HRRserverkeyshare;
  XBUFFER                                                           HRRserverhellobuffer;

  status = HRRservercipher.KeyPair_Create(HRRserverprivate, HRRserverpublic);

  HRRserverhello.SetMsgType(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_SERVER_HELLO);
  HRRserverhello.GetBody()->SetLegacyVersion(DIOSTREAMTLS_MSG_VERSION_TLS_1_2);
  for(XDWORD c=0; c<DIOSTREAMTLS_MSG_RANDOM_SIZE; c++) HRRserverhello.GetBody()->GetRandom()[c] = (XBYTE)(0x80 + c);
  HRRserverhello.GetBody()->SetSessionIDLength(HRRfirstmessage.GetBody()->GetSessionIDLength());
  memcpy(HRRserverhello.GetBody()->GetSessionID(), HRRfirstmessage.GetBody()->GetSessionID(), HRRfirstmessage.GetBody()->GetSessionIDLength());
  HRRserverhello.GetBody()->SetCipherSuite(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256);
  HRRserverhello.GetBody()->SetCompressionMethod(DIOSTREAMTLS_MSG_COMPRESS_METHOD_NULL);

  HRRserverversion = GEN_NEW DIOSTREAMTLS_MSG_EXTENSION_SUPPORTEDVERSIONS_SERVER();
  HRRserverkeyshare = GEN_NEW DIOSTREAMTLS_MSG_EXTENSION_KEYSHARE_SERVER();
  if(!HRRserverversion || !HRRserverkeyshare) return false;

  HRRserverversion->SetVersion(DIOSTREAMTLS_MSG_VERSION_TLS_1_3);
  HRRserverkeyshare->GetKey()->SetKeyType(DIOSTREAMTLS_MSG_CURVEID_SECP256R1);

  if(!HRRserverkeyshare->GetKey()->GetKeyData()->Add(HRRserverpublic) ||
     !HRRserverhello.GetBody()->Extensions_Add(HRRserverversion) ||
     !HRRserverhello.GetBody()->Extensions_Add(HRRserverkeyshare))
    {
      return false;
    }

  status = status && HRRserverhello.SetToBuffer(HRRserverhellobuffer, false);
  status = status && HRRclient.ServerHello_Process(HRRserverhellobuffer);
  status = status && (HRRclient.GetState() == DIOSTREAMTLS13HANDSHAKECLIENT_STATE_WAIT_ENCRYPTEDEXTENSIONS);
  status = status && (HRRsession.GetEpoch(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL) == DIOSTREAMTLS13SESSION_EPOCH_HANDSHAKE);
  status = status && (HRRsession.GetEpoch(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE) == DIOSTREAMTLS13SESSION_EPOCH_HANDSHAKE);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("ServerHello completes ECDHE P-256 after HRR"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBYTE oversizedhandshakeheader[] =
  {
    DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_CERTIFICATE, 0x40, 0x00, 0x00,
  };
  XBUFFER oversizedhandshake;
  XBUFFER oversizedextracted;

  oversizedhandshake.Add(oversizedhandshakeheader, sizeof(oversizedhandshakeheader));
  status = !DIOSTREAMTLS_MSG_HANDSHAKE::Message_Extract(oversizedhandshake, oversizedextracted);
  status = status && (oversizedhandshake.GetSize() == sizeof(oversizedhandshakeheader));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Oversized handshake input is bounded"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ Complete TLS 1.3 client handshake ]\n"));

  DIOSTREAMTLS13SESSION          session;
  DIOSTREAMTLS13HANDSHAKECLIENT handshakeclient;
  XBUFFER                     clienthellomessage;
  XBUFFER                     serverhellomessage;
  XBUFFER                     sharedsecretmessage;
  XBUFFER                     expectedtranscript;

  clienthellomessage.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));
  serverhellomessage.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO));
  sharedsecretmessage.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SHAREDSECRET, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SHAREDSECRET));

  status = session.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && handshakeclient.Ini(&session);                // Hito 2A: X.509 validation is explicitly deferred
  status = status && handshakeclient.Start(clienthellomessage);
  status = status && handshakeclient.ServerHello_Process(serverhellomessage, sharedsecretmessage);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Client and ServerHello activate handshake keys"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = handshakeclient.RecordInput_Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFLIGHTRECORD, 4);
  status = status && handshakeclient.Process();
  status = status && (handshakeclient.GetState() == DIOSTREAMTLS13HANDSHAKECLIENT_STATE_WAIT_ENCRYPTEDEXTENSIONS);
  status = status && handshakeclient.RecordInput_Add(&DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFLIGHTRECORD[4], 97);
  status = status && handshakeclient.Process();
  status = status && (handshakeclient.GetState() == DIOSTREAMTLS13HANDSHAKECLIENT_STATE_WAIT_ENCRYPTEDEXTENSIONS);
  status = status && handshakeclient.RecordInput_Add(&DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFLIGHTRECORD[101], sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFLIGHTRECORD) - 101);
  status = status && handshakeclient.Process();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Fragmented encrypted flight is accumulated"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = handshakeclient.IsServerFinishedVerified();
  status = status && (session.GetEpoch(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL) == DIOSTREAMTLS13SESSION_EPOCH_HANDSHAKE);
  status = status && (session.GetEpoch(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE) == DIOSTREAMTLS13SESSION_EPOCH_APPLICATION);
  status = status && handshakeclient.GetServerCertificate();
  status = status && (handshakeclient.GetServerCertificate()->CertificateList_GetAll()->GetSize() == 1);
  status = status && handshakeclient.GetServerCertificateVerify();
  status = status && (handshakeclient.GetServerCertificateVerify()->GetAlgorithm() == DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA256);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Server Finished is verified and keys advance"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  expectedtranscript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));
  expectedtranscript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO));
  expectedtranscript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS));
  expectedtranscript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE));
  expectedtranscript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY));
  expectedtranscript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED));

  status = session.GetTranscript()->Compare(expectedtranscript);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Transcript matches RFC byte for byte"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBUFFER clientfinishedmessage;
  XBUFFER clientfinishedrecords;

  status = handshakeclient.ClientFinished_Create(clientfinishedmessage, clientfinishedrecords);
  status = status && clientfinishedmessage.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHED));
  status = status && clientfinishedrecords.Compare(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHEDRECORD, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHEDRECORD));
  status = status && handshakeclient.IsHandshakeCompleted();
  status = status && handshakeclient.IsServerFinishedVerified();
  status = status && (session.GetEpoch(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL) == DIOSTREAMTLS13SESSION_EPOCH_APPLICATION);
  status = status && (session.GetEpoch(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE) == DIOSTREAMTLS13SESSION_EPOCH_APPLICATION);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Client Finished completes both directions"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  expectedtranscript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHED));

  status = session.GetTranscript()->Compare(expectedtranscript);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Complete transcript matches RFC bytes"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBUFFER encryptedextensionsmessage;
  XBUFFER certificatemessage;
  XBUFFER certificateverifymessage;
  XBUFFER serverfinishedmessage;
  XBUFFER forgedfinishedmessage;

  encryptedextensionsmessage.Add(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS));
  certificatemessage.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE));
  certificateverifymessage.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY));
  serverfinishedmessage.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED));
  forgedfinishedmessage.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED));
  forgedfinishedmessage.Get()[DIOSTREAMTLS_MSG_HANDSHAKEHEADER_SIZE] ^= 0x01;

  DIOSTREAMTLS13SESSION          forgedsession;
  DIOSTREAMTLS13HANDSHAKECLIENT forgedclient;

  status = forgedsession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && forgedclient.Ini(&forgedsession);
  status = status && forgedclient.Start(clienthellomessage);
  status = status && forgedclient.ServerHello_Process(serverhellomessage, sharedsecretmessage);
  status = status && forgedclient.Handshake_Process(encryptedextensionsmessage);
  status = status && forgedclient.Handshake_Process(certificatemessage);
  status = status && forgedclient.Handshake_Process(certificateverifymessage);
  status = status && !forgedclient.Handshake_Process(forgedfinishedmessage);
  status = status && (forgedclient.GetState() == DIOSTREAMTLS13HANDSHAKECLIENT_STATE_ERROR);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("A forged Finished is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION          ordersession;
  DIOSTREAMTLS13HANDSHAKECLIENT orderclient;

  status = ordersession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && orderclient.Ini(&ordersession);
  status = status && orderclient.Start(clienthellomessage);
  status = status && orderclient.ServerHello_Process(serverhellomessage, sharedsecretmessage);
  status = status && !orderclient.Handshake_Process(certificatemessage);
  status = status && (orderclient.GetState() == DIOSTREAMTLS13HANDSHAKECLIENT_STATE_ERROR);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("An out-of-order message is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION          requestsession;
  DIOSTREAMTLS13HANDSHAKECLIENT requestclient;
  XBUFFER                     certificaterequestmessage;

  certificaterequestmessage.Add(certificaterequestdata, sizeof(certificaterequestdata));

  status = requestsession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && requestclient.Ini(&requestsession);
  status = status && requestclient.Start(clienthellomessage);
  status = status && requestclient.ServerHello_Process(serverhellomessage, sharedsecretmessage);
  status = status && requestclient.Handshake_Process(encryptedextensionsmessage);
  status = status && requestclient.Handshake_Process(certificaterequestmessage);
  status = status && requestclient.IsCertificateRequested();
  status = status && requestclient.Handshake_Process(certificatemessage);
  status = status && requestclient.Handshake_Process(certificateverifymessage);
  status = status && (requestclient.GetState() == DIOSTREAMTLS13HANDSHAKECLIENT_STATE_WAIT_FINISHED);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Optional CertificateRequest is accepted"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  tests->console->Printf(_L("\n[ TLS 1.3 server authentication ]\n"));

  DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_CERTIFICATE> trustcertificate;
  XBUFFER                                                          trustcertificatemessage;
  XVECTOR<XBUFFER*>                                                trustedroots;
  XDATETIME                                                        certificatevalidationdate;

  trustcertificatemessage.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE));

  status = trustcertificate.GetFromBuffer(trustcertificatemessage, false);
  status = status && trustcertificatemessage.IsEmpty();
  status = status && (trustcertificate.GetBody()->CertificateList_GetAll()->GetSize() == 1);
  status = status && trustedroots.Add(trustcertificate.GetBody()->CertificateList_GetAll()->Get(0)->GetCertificateData());

  CIPHERCERTIFICATEX509 decodedtrustcertificate;
  status = status && decodedtrustcertificate.Decode((*trustedroots.Get(0)));
  status = status && decodedtrustcertificate.VerifySignature(decodedtrustcertificate.GetPublicCipherKey());
  status = status && DIOSTREAMTLSSIGNATURE::IsSupported(DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA256, decodedtrustcertificate.GetPublicCipherKey());
  status = status && DIOSTREAMTLSSIGNATURE::IsSupported(DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA384, decodedtrustcertificate.GetPublicCipherKey());
  status = status && DIOSTREAMTLSSIGNATURE::IsSupported(DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA512, decodedtrustcertificate.GetPublicCipherKey());
  status = status && !DIOSTREAMTLSSIGNATURE::IsSupported(DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PKCS1_SHA256, decodedtrustcertificate.GetPublicCipherKey());

  XSTRING pss384base64;
  XSTRING pss512base64;
  XBUFFER pss384buffer;
  XBUFFER pss512buffer;

  pss384base64.Add(_L("MIIDYzCCAhugAwIBAgIUf3wsp8ggcPddOBnGa6Ftnvh9/2kwPQYJKoZIhvcNAQEKMDCgDTALBglghkgBZQMEAgKhGjAYBgkqhkiG"));
  pss384base64.Add(_L("9w0BAQgwCwYJYIZIAWUDBAICogMCATAwETEPMA0GA1UEAwwGcHNzMzg0MB4XDTI2MDgyMTA0NDgzMVoXDTI2MDkyMDA0NDgzMVow"));
  pss384base64.Add(_L("ETEPMA0GA1UEAwwGcHNzMzg0MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEA2s0JKaQS2yJCgtMG1zc0+t1OPnn7cBJd"));
  pss384base64.Add(_L("kWMHD/9yXvwqncIIzbxFo+a0B+0InIrv0Ocebw3qhMHrcgUwTJdQJYbV9DM5s4n4oTQDs8IMO6fdyp/ZXt+GowIZ0KQUrWQflePo"));
  pss384base64.Add(_L("90vEUr5yl6WOr+KZRdivRyegvetLyJjWHyPZRx85iMfNhbNH/yjBHs3EI5oPk3nSxEDF7z/S/hpkNxXsSuNPc2tI//Zmyskm4Nzj"));
  pss384base64.Add(_L("IMHI7Ak9YONUhMJnEJluv/4YR1fEw8WjHJ1OROlI3qQt9eoCRcYffje4qiIJxAMjRgqzYFUsfBSMg4Xkfgo9ltZnoj/c74PSn6Ax"));
  pss384base64.Add(_L("whU7TG31+wIDAQABo1MwUTAdBgNVHQ4EFgQUHaFoFV3wRSd6sB5advMuEYcjC3IwHwYDVR0jBBgwFoAUHaFoFV3wRSd6sB5advMu"));
  pss384base64.Add(_L("EYcjC3IwDwYDVR0TAQH/BAUwAwEB/zA9BgkqhkiG9w0BAQowMKANMAsGCWCGSAFlAwQCAqEaMBgGCSqGSIb3DQEBCDALBglghkgB"));
  pss384base64.Add(_L("ZQMEAgKiAwIBMAOCAQEAe/g796UGJhR+7NKEfv+8UBsxwH0NWWpqpd5upYgcT4Igk43ImWClGWIytQOb6n3lHcd9NmO44TzKjB6T"));
  pss384base64.Add(_L("6CZPsU9DRttUII8FihqJxbiqia3SjLx8CgjFXGP+VvJBt8HQs7vtiHtBUTVQ7tc35k7BY4rs8X62BeN01rrGkjdkLqNZKUKHTAOv"));
  pss384base64.Add(_L("e4tTM3KTSiqn+wTew1wf9B681bGnrBUBFiKDPWh8lQnIBMOIBZeEMpVHlgvb+JyxAvT33shlgWNcdd8a1htJo1SfK67l2Mme+hDo"));
  pss384base64.Add(_L("K1jE3sDuOjFm2sBoBx+fR5utDzfDGdj24OjZEi40Fir3TmRuh+1Gey8ZmYZEUQ=="));

  pss512base64.Add(_L("MIIDYzCCAhugAwIBAgIUdxs2eOU1xe36clzjtetaz7NAYy8wPQYJKoZIhvcNAQEKMDCgDTALBglghkgBZQMEAgOhGjAYBgkqhkiG"));
  pss512base64.Add(_L("9w0BAQgwCwYJYIZIAWUDBAIDogMCAUAwETEPMA0GA1UEAwwGcHNzNTEyMB4XDTI2MDgyMTA0NDgzMVoXDTI2MDkyMDA0NDgzMVow"));
  pss512base64.Add(_L("ETEPMA0GA1UEAwwGcHNzNTEyMIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAtiUJlEXv2sKrLQj627v5cCtskhNgOghZ"));
  pss512base64.Add(_L("LqcGMdL5/9dMf7n/gvbOzNJmgsHZd93jOSIiRdB00lYahOKrC8UlsJNCl2dx/v9WfhT8yX0nvLLRIHiFYNyj3noRnGlLkfuQ9ICG"));
  pss512base64.Add(_L("f3jegGIBD8Vbp6HIOsyMXzWW6RjpMsVoirNvrHrS+WLjLXyxU8RnXDR+Pm3Ht1mUssdoaLbE0/CfZHyF1YnPA8DgMZ3BbgieVT1I"));
  pss512base64.Add(_L("uSj8zSDqolHckuetbhbVv3Io5RWq792GLzsPl7vQH44hO7lU0j22iuhEpGa9umPxrmL3RfYv/9aFRt/ftrivYGvIAfHUIIjVqdQu"));
  pss512base64.Add(_L("tvRZV45TOwIDAQABo1MwUTAdBgNVHQ4EFgQUNE2DuHIXuEaiC6wkeUXlZGdDzTQwHwYDVR0jBBgwFoAUNE2DuHIXuEaiC6wkeUXl"));
  pss512base64.Add(_L("ZGdDzTQwDwYDVR0TAQH/BAUwAwEB/zA9BgkqhkiG9w0BAQowMKANMAsGCWCGSAFlAwQCA6EaMBgGCSqGSIb3DQEBCDALBglghkgB"));
  pss512base64.Add(_L("ZQMEAgOiAwIBQAOCAQEAr3iWlaIaE+DkynspvN73KiOEWUSkhWNXrRqLHNv+bXace1+DAJxcwbB7gLQEHUHro7aXvT4F1IrzkceY"));
  pss512base64.Add(_L("UUDQjkJFmRmO40bg2XlXXr3P79NsXO0zNqqUwtjSTyGanShUy0SWY9zMPa5YgDVJPkF+QUOYKekhz2J5cCv2Jkzv42b/glHhrJNZ"));
  pss512base64.Add(_L("ikpJ3ryI/w2gvntsaPq2QHCt6AVLDOhTX1E0Z6VS39tXGBERcTmJKKUfxnM/eTpkPoyXvHNDJcrrFBR+PA0/YB8pbmXycAwxuTG2"));
  pss512base64.Add(_L("tOYSOkLYG6tMoLuLs9NXkJtrwb0jIno7uxkTXHqxTODhcT0Hmgq04EjImrxRLw=="));

  status = status && pss384buffer.ConvertFromBase64(pss384base64);
  status = status && pss512buffer.ConvertFromBase64(pss512base64);

  CIPHERCERTIFICATEX509 pss384certificate;
  CIPHERCERTIFICATEX509 pss512certificate;

  status = status && pss384certificate.Decode(pss384buffer);
  status = status && (pss384certificate.GetAlgorithmType() == CIPHERCERTIFICATEX509_ALGORITHM_TYPE_RSASSAPSS);
  status = status && (pss384certificate.GetRSASSAPSSHashType() == CIPHERCERTIFICATEX509_RSASSAPSS_HASH_TYPE_SHA384);
  status = status && (pss384certificate.GetRSASSAPSSSaltSize() == HASHSHA2_384_DIGEST_SIZE);
  status = status && pss384certificate.VerifySignature(pss384certificate.GetPublicCipherKey());

  status = status && pss512certificate.Decode(pss512buffer);
  status = status && (pss512certificate.GetAlgorithmType() == CIPHERCERTIFICATEX509_ALGORITHM_TYPE_RSASSAPSS);
  status = status && (pss512certificate.GetRSASSAPSSHashType() == CIPHERCERTIFICATEX509_RSASSAPSS_HASH_TYPE_SHA512);
  status = status && (pss512certificate.GetRSASSAPSSSaltSize() == HASHSHA2_512_DIGEST_SIZE);
  status = status && pss512certificate.VerifySignature(pss512certificate.GetPublicCipherKey());

  XBUFFER invalidPSSparameters;
  CIPHERCERTIFICATEX509 invalidPSScertificate;

  status = status && invalidPSSparameters.Add(pss384buffer);
  status = status && invalidPSSparameters.Set((XBYTE)(HASHSHA2_384_DIGEST_SIZE - 1), 97);
  status = status && invalidPSSparameters.Set((XBYTE)(HASHSHA2_384_DIGEST_SIZE - 1), 609);
  status = status && !invalidPSScertificate.Decode(invalidPSSparameters);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("X.509 RSA-PSS SHA-384/512 is verified"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XSTRING ECDSAcertificatebase64;
  XSTRING ECDSAcontentbase64;
  XSTRING ECDSAsignaturebase64;
  XBUFFER ECDSAcertificatebuffer;
  XBUFFER ECDSAcontent;
  XBUFFER ECDSAsignature;

  ECDSAcertificatebase64.Add(_L("MIIBbDCCARKgAwIBAgIITDMgud/Fp34wCgYIKoZIzj0EAwIwFTETMBEGA1UEAxMKZWNkc2EudGVzdDAeFw0yNjA4MjAwMDAwMDBa"));
  ECDSAcertificatebase64.Add(_L("Fw0yNjA5MjAwMDAwMDBaMBUxEzARBgNVBAMTCmVjZHNhLnRlc3QwWTATBgcqhkjOPQIBBggqhkjOPQMBBwNCAAR8tm/XNYdHtJYy"));
  ECDSAcertificatebase64.Add(_L("32EtjsPF4PfCRap7UJ1nEwLbDTpAg8k4aih589S9TipmvKDzk1PpgyQpGJVHzOmFjJRpluHTo0wwSjAMBgNVHRMBAf8EAjAAMA4G"));
  ECDSAcertificatebase64.Add(_L("A1UdDwEB/wQEAwIHgDATBgNVHSUEDDAKBggrBgEFBQcDATAVBgNVHREEDjAMggplY2RzYS50ZXN0MAoGCCqGSM49BAMCA0gAMEUC"));
  ECDSAcertificatebase64.Add(_L("IHIp0oNEuNMM11WyIAdp8wCMaUkZdkcWMb2vc2N5/7F4AiEA7yhfbbwhmV9Y3Q1FBE/lPJep9iXdFiQLR1B7+21TzDY="));

  ECDSAcontentbase64.Add(_L("ICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgICAgIFRMUyAxLjMsIHNlcnZl"));
  ECDSAcontentbase64.Add(_L("ciBDZXJ0aWZpY2F0ZVZlcmlmeQAAAQIDBAUGBwgJCgsMDQ4PEBESExQVFhcYGRobHB0eHw=="));

  ECDSAsignaturebase64.Add(_L("MEUCIQCJsxddoYx77lfBe9TO+BjZDubpPWHCYgnbhmEH1QJCEgIgSg/f49k6DLIWhJoTUNHaijIMsqFutuaOUo78bXiz5q8="));

  status = status && ECDSAcertificatebuffer.ConvertFromBase64(ECDSAcertificatebase64);
  status = status && ECDSAcontent.ConvertFromBase64(ECDSAcontentbase64);
  status = status && ECDSAsignature.ConvertFromBase64(ECDSAsignaturebase64);

  CIPHERCERTIFICATEX509 ECDSAcertificate;

  status = status && ECDSAcertificate.Decode(ECDSAcertificatebuffer);
  status = status && (ECDSAcertificate.GetAlgorithmType() == CIPHERCERTIFICATEX509_ALGORITHM_TYPE_ECDSAWITHSHA256);
  status = status && ECDSAcertificate.IsPublicCipherKeyValid();
  status = status && ECDSAcertificate.GetPublicCipherKey();
  status = status && (ECDSAcertificate.GetPublicCipherKey()->GetType() == CIPHERKEYTYPE_ECDSA_SECP256R1_PUBLIC);
  status = status && ECDSAcertificate.VerifySignature(ECDSAcertificate.GetPublicCipherKey());

  XBUFFER invalidECDSApointbuffer;
  CIPHERCERTIFICATEX509 invalidECDSApointcertificate;

  status = status && invalidECDSApointbuffer.Add(ECDSAcertificatebuffer);
  invalidECDSApointbuffer.Get()[140] ^= 0x01;
  status = status && !invalidECDSApointcertificate.Decode(invalidECDSApointbuffer);

  XBUFFER invalidECDSAcertificatebuffer;
  CIPHERCERTIFICATEX509 invalidECDSAcertificate;

  status = status && invalidECDSAcertificatebuffer.Add(ECDSAcertificatebuffer);
  invalidECDSAcertificatebuffer.Get()[invalidECDSAcertificatebuffer.GetSize()-1] ^= 0x01;
  status = status && invalidECDSAcertificate.Decode(invalidECDSAcertificatebuffer);
  status = status && !invalidECDSAcertificate.VerifySignature(invalidECDSAcertificate.GetPublicCipherKey());

  tests->console->Printf(_L(" %-42s : %s\n"), _L("X.509 ECDSA P-256/SHA-256 is verified"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = DIOSTREAMTLSSIGNATURE::IsSupported(DIOSTREAMTLS_MSG_SIGNATURESCHEME_ECDSA_SECP256R1_SHA256, ECDSAcertificate.GetPublicCipherKey());
  status = status && !DIOSTREAMTLSSIGNATURE::IsSupported(DIOSTREAMTLS_MSG_SIGNATURESCHEME_RSA_PSS_RSAE_SHA256, ECDSAcertificate.GetPublicCipherKey());
  status = status && DIOSTREAMTLSSIGNATURE::Verify(DIOSTREAMTLS_MSG_SIGNATURESCHEME_ECDSA_SECP256R1_SHA256, ECDSAcertificate.GetPublicCipherKey(), ECDSAcontent, ECDSAsignature);

  XBUFFER invalidECDSAsignature;
  XBUFFER malformedECDSAsignature;

  status = status && invalidECDSAsignature.Add(ECDSAsignature);
  invalidECDSAsignature.Get()[invalidECDSAsignature.GetSize()-1] ^= 0x01;
  status = status && !DIOSTREAMTLSSIGNATURE::Verify(DIOSTREAMTLS_MSG_SIGNATURESCHEME_ECDSA_SECP256R1_SHA256, ECDSAcertificate.GetPublicCipherKey(), ECDSAcontent, invalidECDSAsignature);

  status = status && malformedECDSAsignature.Add(ECDSAsignature);
  malformedECDSAsignature.Get()[1]--;
  status = status && !DIOSTREAMTLSSIGNATURE::Verify(DIOSTREAMTLS_MSG_SIGNATURESCHEME_ECDSA_SECP256R1_SHA256, ECDSAcertificate.GetPublicCipherKey(), ECDSAcontent, malformedECDSAsignature);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("ECDSA CertificateVerify is verified"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  certificatevalidationdate.SetYear(2018);
  certificatevalidationdate.SetMonth(8);
  certificatevalidationdate.SetDay(1);
  certificatevalidationdate.SetHours(12);
  certificatevalidationdate.SetMinutes(0);
  certificatevalidationdate.SetSeconds(0);
  certificatevalidationdate.SetMilliSeconds(0);
  certificatevalidationdate.SetIsLocal(false);

  status = status && certificatevalidationdate.IsValidDate();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("RFC certificate is loaded as explicit trust"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION          authenticatedsession;
  DIOSTREAMTLS13HANDSHAKECLIENT authenticatedclient;

  status = authenticatedsession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && authenticatedclient.Ini(&authenticatedsession);
  status = status && authenticatedclient.Authentication_Set(_L("rsa"), &trustedroots, &certificatevalidationdate);
  status = status && authenticatedclient.Start(clienthellomessage);
  status = status && authenticatedclient.ServerHello_Process(serverhellomessage, sharedsecretmessage);
  status = status && authenticatedclient.Handshake_Process(encryptedextensionsmessage);
  status = status && authenticatedclient.Handshake_Process(certificatemessage);
  status = status && authenticatedclient.Handshake_Process(certificateverifymessage);
  status = status && authenticatedclient.IsServerAuthenticated();
  status = status && (authenticatedclient.GetAuthenticationError() == DIOSTREAMTLS13HANDSHAKECLIENT_AUTHENTICATIONERROR_NONE);
  status = status && authenticatedclient.Handshake_Process(serverfinishedmessage);
  status = status && authenticatedclient.IsServerFinishedVerified();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("X.509 and RSA-PSS authenticate server"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBUFFER forgedcertificateverifymessage;
  forgedcertificateverifymessage.Add(certificateverifymessage);
  forgedcertificateverifymessage.Get()[DIOSTREAMTLS_MSG_HANDSHAKEHEADER_SIZE + 4] ^= 0x01;

  DIOSTREAMTLS13SESSION          invalidsignaturesession;
  DIOSTREAMTLS13HANDSHAKECLIENT invalidsignatureclient;

  status = invalidsignaturesession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && invalidsignatureclient.Ini(&invalidsignaturesession);
  status = status && invalidsignatureclient.Authentication_Set(_L("rsa"), &trustedroots, &certificatevalidationdate);
  status = status && invalidsignatureclient.Start(clienthellomessage);
  status = status && invalidsignatureclient.ServerHello_Process(serverhellomessage, sharedsecretmessage);
  status = status && invalidsignatureclient.Handshake_Process(encryptedextensionsmessage);
  status = status && invalidsignatureclient.Handshake_Process(certificatemessage);
  status = status && !invalidsignatureclient.Handshake_Process(forgedcertificateverifymessage);
  status = status && !invalidsignatureclient.IsServerAuthenticated();
  status = status && (invalidsignatureclient.GetAuthenticationError() == DIOSTREAMTLS13HANDSHAKECLIENT_AUTHENTICATIONERROR_CERTIFICATEVERIFY);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("A forged CertificateVerify is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION          invalidnamesession;
  DIOSTREAMTLS13HANDSHAKECLIENT invalidnameclient;

  status = invalidnamesession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && invalidnameclient.Ini(&invalidnamesession);
  status = status && invalidnameclient.Authentication_Set(_L("server"), &trustedroots, &certificatevalidationdate);
  status = status && invalidnameclient.Start(clienthellomessage);
  status = status && invalidnameclient.ServerHello_Process(serverhellomessage, sharedsecretmessage);
  status = status && invalidnameclient.Handshake_Process(encryptedextensionsmessage);
  status = status && !invalidnameclient.Handshake_Process(certificatemessage);
  status = status && (invalidnameclient.GetCertificateValidationError() == CIPHERCERTIFICATEX509VALIDATOR_ERROR_INVALIDNAME);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("A certificate for another name is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XDATETIME expiredvalidationdate;
  expiredvalidationdate.SetYear(2026);
  expiredvalidationdate.SetMonth(8);
  expiredvalidationdate.SetDay(20);
  expiredvalidationdate.SetHours(12);
  expiredvalidationdate.SetMinutes(0);
  expiredvalidationdate.SetSeconds(0);
  expiredvalidationdate.SetMilliSeconds(0);
  expiredvalidationdate.SetIsLocal(false);

  DIOSTREAMTLS13SESSION          expiredsession;
  DIOSTREAMTLS13HANDSHAKECLIENT expiredclient;

  status = expiredvalidationdate.IsValidDate();
  status = status && expiredsession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && expiredclient.Ini(&expiredsession);
  status = status && expiredclient.Authentication_Set(_L("rsa"), &trustedroots, &expiredvalidationdate);
  status = status && expiredclient.Start(clienthellomessage);
  status = status && expiredclient.ServerHello_Process(serverhellomessage, sharedsecretmessage);
  status = status && expiredclient.Handshake_Process(encryptedextensionsmessage);
  status = status && !expiredclient.Handshake_Process(certificatemessage);
  status = status && (expiredclient.GetCertificateValidationError() == CIPHERCERTIFICATEX509VALIDATOR_ERROR_INVALIDDATE);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("An expired certificate is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBUFFER untrustedroot;
  untrustedroot.Add((*trustedroots.Get(0)));
  untrustedroot.Get()[untrustedroot.GetSize()-1] ^= 0x01;

  XVECTOR<XBUFFER*> untrustedroots;
  untrustedroots.Add(&untrustedroot);

  DIOSTREAMTLS13SESSION          untrustedsession;
  DIOSTREAMTLS13HANDSHAKECLIENT untrustedclient;

  status = untrustedsession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && untrustedclient.Ini(&untrustedsession);
  status = status && untrustedclient.Authentication_Set(_L("rsa"), &untrustedroots, &certificatevalidationdate);
  status = status && untrustedclient.Start(clienthellomessage);
  status = status && untrustedclient.ServerHello_Process(serverhellomessage, sharedsecretmessage);
  status = status && untrustedclient.Handshake_Process(encryptedextensionsmessage);
  status = status && !untrustedclient.Handshake_Process(certificatemessage);
  status = status && (untrustedclient.GetCertificateValidationError() == CIPHERCERTIFICATEX509VALIDATOR_ERROR_UNTRUSTEDROOT);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("An untrusted certificate is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION          noconfigurationsession;
  DIOSTREAMTLS13HANDSHAKECLIENT noconfigurationclient;

  status = noconfigurationsession.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && noconfigurationclient.Ini(&noconfigurationsession);
  status = status && noconfigurationclient.Start(clienthellomessage);
  status = status && noconfigurationclient.ServerHello_Process(serverhellomessage, sharedsecretmessage);
  status = status && noconfigurationclient.Handshake_Process(encryptedextensionsmessage);
  status = status && !noconfigurationclient.Handshake_Process(certificatemessage);
  status = status && (noconfigurationclient.GetAuthenticationError() == DIOSTREAMTLS13HANDSHAKECLIENT_AUTHENTICATIONERROR_CONFIGURATION);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Authenticated mode requires trust policy"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ TLS 1.3 application stream and close ]\n"));

  DIOSTREAMTLSCONFIG streamconfig;

  status = streamconfig.IsTLS();
  status = status && (streamconfig.GetCipherSuite() == DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256);
  status = status && (streamconfig.GetCipherSuites()->GetSize() == 2);
  status = status && (streamconfig.GetSupportedGroups()->GetSize() == 3);
  status = status && (streamconfig.GetSignatureSchemes()->GetSize() == 3);
  status = status && (streamconfig.GetCertificateSignatureSchemes()->GetSize() == 9);
  status = status && streamconfig.GetApplicationProtocols()->IsEmpty();
  status = status && streamconfig.TrustedRoot_Add((*trustedroots.Get(0)));
  status = status && (streamconfig.GetTrustedRoots()->GetSize() == 1);
  status = status && streamconfig.GetTrustedRoots()->Get(0)->Compare((*trustedroots.Get(0)));

  streamconfig.SetCipherSuite(DIOSTREAMTLS_MSG_CIPHER_AES_256_GCM_SHA384);
  status = status && (streamconfig.GetCipherSuite() == DIOSTREAMTLS_MSG_CIPHER_AES_256_GCM_SHA384);
  status = status && (streamconfig.GetCipherSuites()->GetSize() == 1);
  streamconfig.SetCipherSuite(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("TLS configuration is secure by default"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLSCONFIG ECDSAconfig;

  // ECDSA P-256/P-384/P-521 are now part of CertificateSignatureSchemes by default (see "TLS configuration is
  // secure by default" above: 9 schemes, 3 of them ECDSA), so re-adding P-256 there must be rejected as a
  // duplicate rather than growing the list. For the handshake-signing SignatureSchemes list (CertificateVerify),
  // the defaults remain RSA-PSS only, so P-256 is still an explicit opt-in there.
  status = ECDSAconfig.SignatureScheme_Add(DIOSTREAMTLS_MSG_SIGNATURESCHEME_ECDSA_SECP256R1_SHA256);
  status = status && !ECDSAconfig.CertificateSignatureScheme_Add(DIOSTREAMTLS_MSG_SIGNATURESCHEME_ECDSA_SECP256R1_SHA256);
  status = status && (ECDSAconfig.GetSignatureSchemes()->GetSize() == 4);
  status = status && (ECDSAconfig.GetCertificateSignatureSchemes()->GetSize() == 9);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("ECDSA P-256 remains an explicit option"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ TLS 1.3 server preparation ]\n"));

  XMPINTEGER             localprime1;
  XMPINTEGER             localprime2;
  XMPINTEGER             localexponent;
  CIPHERKEYPRIVATERSA    sourceprivatekey;
  XBUFFER                localcertificate;
  int                    sourceprivatekeysize = 0;

  localprime1.Ini();
  localprime2.Ini();
  localexponent.Ini();

  status = localprime1.SetFromString(10, _L("61"));
  status = status && localprime2.SetFromString(10, _L("53"));
  status = status && localexponent.SetFromString(10, _L("2753"));
  status = status && sourceprivatekey.Set(localprime1, localprime2, localexponent);

  sourceprivatekeysize = sourceprivatekey.GetSizeInBytes();

  status = status && localcertificate.Add((*trustedroots.Get(0)));
  status = status && streamconfig.LocalCertificate_Add(localcertificate);
  status = status && streamconfig.SetLocalPrivateKey(&sourceprivatekey);
  status = status && streamconfig.HasLocalCredentials();
  status = status && (streamconfig.GetLocalCertificateChain()->GetSize() == 1);
  status = status && (streamconfig.GetLocalPrivateKey() != &sourceprivatekey);
  status = status && (streamconfig.GetLocalPrivateKey()->GetSizeInBytes() == sourceprivatekeysize);

  localcertificate.Get()[0] ^= 0x01;
  status = status && streamconfig.GetLocalCertificateChain()->Get(0)->Compare((*trustedroots.Get(0)));

  localprime1.End();
  localprime2.End();
  localexponent.End();

  status = status && sourceprivatekey.Set(localprime1, localprime2, localexponent);
  status = status && !sourceprivatekey.GetSizeInBytes();
  status = status && (streamconfig.GetLocalPrivateKey()->GetSizeInBytes() == sourceprivatekeysize);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Local credentials are copied and owned"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = streamconfig.LocalCredentials_Delete();
  status = status && !streamconfig.HasLocalCredentials();
  status = status && streamconfig.GetLocalCertificateChain()->IsEmpty();
  status = status && !streamconfig.GetLocalPrivateKey();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Local credentials are deleted together"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION memoryclient;
  DIOSTREAMTLS13SESSION memoryserver;
  XBYTE               memoryrequest[]  = "request from client";
  XBYTE               memoryresponse[] = "response from server";
  XBUFFER             memoryrecords;

  status = Test_DIOStreamTLS_SessionIni(memoryclient, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && Test_DIOStreamTLS_SessionIni(memoryserver, DIOSTREAMTLSKEYSCHEDULE_ROLE_SERVER);
  status = status && memoryclient.GetKeySchedule()->GetTrafficSecret(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL)->Compare
                                                                      ((*memoryserver.GetKeySchedule()->GetTrafficSecret (DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE)));
  status = status && memoryclient.GetKeySchedule()->GetTrafficSecret(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE)->Compare
                                                                      ((*memoryserver.GetKeySchedule()->GetTrafficSecret (DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL)));
  status = status && memoryclient.ApplicationData_Protect(memoryrequest, sizeof(memoryrequest)-1, memoryrecords);
  status = status && memoryserver.RecordInput_Add(memoryrecords);
  status = status && (memoryserver.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && memoryserver.GetApplicationInput()->Compare(memoryrequest, sizeof(memoryrequest)-1);

  memoryrecords.Delete();

  status = status && memoryserver.ApplicationData_Protect(memoryresponse, sizeof(memoryresponse)-1, memoryrecords);
  status = status && memoryclient.RecordInput_Add(memoryrecords);
  status = status && (memoryclient.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && memoryclient.GetApplicationInput()->Compare(memoryresponse, sizeof(memoryresponse)-1);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Local and remote directions cross in memory"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION acceptedclient;
  DIOSTREAMTLS13SESSION acceptedserver1;
  DIOSTREAMTLS13SESSION acceptedserver2;
  XBYTE               accepteddata[] = "first record of an accepted socket";
  XBUFFER             acceptedrecords;

  status = Test_DIOStreamTLS_SessionIni(acceptedclient, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && Test_DIOStreamTLS_SessionIni(acceptedserver1, DIOSTREAMTLSKEYSCHEDULE_ROLE_SERVER);
  status = status && Test_DIOStreamTLS_SessionIni(acceptedserver2, DIOSTREAMTLSKEYSCHEDULE_ROLE_SERVER);
  status = status && (acceptedserver1.GetRecord() != acceptedserver2.GetRecord());
  status = status && acceptedclient.ApplicationData_Protect(accepteddata, sizeof(accepteddata)-1, acceptedrecords);
  status = status && acceptedserver1.RecordInput_Add(acceptedrecords);
  status = status && acceptedserver2.RecordInput_Add(acceptedrecords);
  status = status && (acceptedserver1.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && (acceptedserver2.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && acceptedserver1.GetApplicationInput()->Compare(accepteddata, sizeof(accepteddata)-1);
  status = status && acceptedserver2.GetApplicationInput()->Compare(accepteddata, sizeof(accepteddata)-1);
  status = status && (acceptedserver1.GetRecord()->GetSequence(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE) == 1);
  status = status && (acceptedserver2.GetRecord()->GetSequence(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE) == 1);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Accepted sockets keep independent sessions"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION applicationclient;
  DIOSTREAMTLS13SESSION applicationserver;
  XBYTE               applicationdata[41];
  XBUFFER             applicationrecords;

  for(XDWORD c=0; c<sizeof(applicationdata); c++) applicationdata[c] = (XBYTE)(0x30 + c);

  status = Test_DIOStreamTLS_SessionIni(applicationclient, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && Test_DIOStreamTLS_SessionIni(applicationserver, DIOSTREAMTLSKEYSCHEDULE_ROLE_SERVER);
  status = status && applicationclient.GetRecord()->SetMaxPlainSize(7);
  status = status && applicationclient.ApplicationData_Protect(applicationdata, sizeof(applicationdata), applicationrecords);
  status = status && applicationserver.RecordInput_Add(applicationrecords.Get(), 4);
  status = status && (applicationserver.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_INCOMPLETE);
  status = status && applicationserver.RecordInput_Add(&applicationrecords.Get()[4], applicationrecords.GetSize() - 4);
  status = status && (applicationserver.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && applicationserver.GetApplicationInput()->Compare(applicationdata, sizeof(applicationdata));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Fragmented records deliver only plaintext"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBYTE applicationread[41];

  status = (applicationserver.ApplicationData_Read(applicationread, 13) == 13);
  status = status && (applicationserver.ApplicationData_Read(&applicationread[13], sizeof(applicationread) - 13) == (sizeof(applicationread) - 13));
  status = status && !memcmp(applicationread, applicationdata, sizeof(applicationdata));
  status = status && applicationserver.GetApplicationInput()->IsEmpty();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Application reads preserve partial consumption"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBUFFER reverseplain;
  XBUFFER reverserecords;

  reverseplain.Add((XBYTE*)"server application data", 23);

  status = applicationserver.ApplicationData_Protect(reverseplain, reverserecords);
  status = status && applicationclient.RecordInput_Add(reverserecords);
  status = status && (applicationclient.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && applicationclient.GetApplicationInput()->Compare(reverseplain);
  applicationclient.GetApplicationInput()->Delete();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Application traffic works in both roles"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBYTE   newsessionticketmessage[] = { DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_NEW_SESSION_TICKET, 0x00, 0x00, 0x00 };
  XBUFFER newsessionticketrecords;

  status = applicationserver.GetRecord()->Protect(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE, newsessionticketmessage, sizeof(newsessionticketmessage), newsessionticketrecords);
  status = status && applicationclient.RecordInput_Add(newsessionticketrecords);
  status = status && (applicationclient.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && !applicationclient.IsError();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("NewSessionTicket is consumed internally"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  XBUFFER closeclientrecords;
  XBUFFER closeserverrecords;
  XBUFFER closeidempotent;

  status = applicationclient.CloseNotify_Create(closeclientrecords);
  status = status && applicationclient.CloseNotify_Create(closeidempotent) && closeidempotent.IsEmpty();
  status = status && applicationserver.RecordInput_Add(closeclientrecords);
  status = status && (applicationserver.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && applicationserver.IsCloseNotifyReceived();
  status = status && !applicationclient.ApplicationData_Protect(applicationdata, sizeof(applicationdata), applicationrecords);
  status = status && applicationserver.CloseNotify_Create(closeserverrecords);
  status = status && applicationclient.RecordInput_Add(closeserverrecords);
  status = status && (applicationclient.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && applicationclient.IsCloseNotifySent() && applicationclient.IsCloseNotifyReceived();
  status = status && applicationserver.IsCloseNotifySent() && applicationserver.IsCloseNotifyReceived();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("close_notify is reciprocal and idempotent"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION truncatedsession;

  status = Test_DIOStreamTLS_SessionIni(truncatedsession, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && !truncatedsession.TransportClosed();
  status = status && truncatedsession.IsTransportClosedWithoutNotify() && truncatedsession.IsError();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("TCP close without close_notify is truncated"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION tamperedclient;
  DIOSTREAMTLS13SESSION tamperedserver;
  XBUFFER             tamperedrecords;

  status = Test_DIOStreamTLS_SessionIni(tamperedclient, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && Test_DIOStreamTLS_SessionIni(tamperedserver, DIOSTREAMTLSKEYSCHEDULE_ROLE_SERVER);
  status = status && tamperedclient.ApplicationData_Protect(applicationdata, sizeof(applicationdata), tamperedrecords);
  tamperedrecords.Get()[tamperedrecords.GetSize()-1] ^= 0x01;
  status = status && tamperedserver.RecordInput_Add(tamperedrecords);
  status = status && (tamperedserver.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_ERROR);
  status = status && tamperedserver.IsError() && tamperedserver.GetApplicationInput()->IsEmpty();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Forged application record is never exposed"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION posthandshakeclient;
  DIOSTREAMTLS13SESSION posthandshakeserver;
  XBUFFER             keyupdaterecords;
  XBUFFER             keyupdateresponse;
  XBUFFER             keyupdateapplicationrecords;

  status = Test_DIOStreamTLS_SessionIni(posthandshakeclient, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && Test_DIOStreamTLS_SessionIni(posthandshakeserver, DIOSTREAMTLSKEYSCHEDULE_ROLE_SERVER);
  status = status && posthandshakeclient.KeyUpdate_Create(true, keyupdaterecords);
  status = status && (posthandshakeclient.GetRecord()->GetSequence(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL) == 0);
  status = status && posthandshakeserver.RecordInput_Add(keyupdaterecords);
  status = status && (posthandshakeserver.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && (posthandshakeserver.GetRecord()->GetSequence(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE) == 0);
  status = status && posthandshakeclient.GetKeySchedule()->GetTrafficSecret(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL)->Compare
                                                                             ((*posthandshakeserver.GetKeySchedule()->GetTrafficSecret (DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE)));
  status = status && posthandshakeserver.PostHandshakeOutput_Extract(keyupdateresponse) && !keyupdateresponse.IsEmpty();
  status = status && posthandshakeclient.RecordInput_Add(keyupdateresponse);
  status = status && (posthandshakeclient.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && posthandshakeserver.GetKeySchedule()->GetTrafficSecret(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL)->Compare
                                                                             ((*posthandshakeclient.GetKeySchedule()->GetTrafficSecret (DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE)));
  status = status && posthandshakeclient.ApplicationData_Protect(applicationdata, sizeof(applicationdata), keyupdateapplicationrecords);
  status = status && posthandshakeserver.RecordInput_Add(keyupdateapplicationrecords);
  status = status && (posthandshakeserver.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_COMPLETE);
  status = status && posthandshakeserver.GetApplicationInput()->Compare(applicationdata, sizeof(applicationdata));

  tests->console->Printf(_L(" %-42s : %s\n"), _L("KeyUpdate renews both traffic directions"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION invalidkeyupdateclient;
  DIOSTREAMTLS13SESSION invalidkeyupdateserver;
  XBYTE               invalidkeyupdatemessage[] = { DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_KEY_UPDATE,
                                                     0x00, 0x00, 0x01, 0x02 };
  XBUFFER             invalidkeyupdaterecords;

  status = Test_DIOStreamTLS_SessionIni(invalidkeyupdateclient, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && Test_DIOStreamTLS_SessionIni(invalidkeyupdateserver, DIOSTREAMTLSKEYSCHEDULE_ROLE_SERVER);
  status = status && invalidkeyupdateserver.GetRecord()->Protect(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE, invalidkeyupdatemessage, sizeof(invalidkeyupdatemessage), invalidkeyupdaterecords);
  status = status && invalidkeyupdateclient.RecordInput_Add(invalidkeyupdaterecords);
  status = status && (invalidkeyupdateclient.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_ERROR);
  status = status && invalidkeyupdateclient.IsError();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("An invalid KeyUpdate value is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION trailingkeyupdateclient;
  DIOSTREAMTLS13SESSION trailingkeyupdateserver;
  XBYTE               trailingkeyupdatemessage[] = { DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_KEY_UPDATE,
                                                      0x00, 0x00, 0x01, 0x00,
                                                      DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_KEY_UPDATE,
                                                      0x00, 0x00, 0x01, 0x00 };
  XBUFFER             trailingkeyupdaterecords;

  status = Test_DIOStreamTLS_SessionIni(trailingkeyupdateclient, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && Test_DIOStreamTLS_SessionIni(trailingkeyupdateserver, DIOSTREAMTLSKEYSCHEDULE_ROLE_SERVER);
  status = status && trailingkeyupdateserver.GetRecord()->Protect(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE, trailingkeyupdatemessage, sizeof(trailingkeyupdatemessage), trailingkeyupdaterecords);
  status = status && trailingkeyupdateclient.RecordInput_Add(trailingkeyupdaterecords);
  status = status && (trailingkeyupdateclient.ApplicationData_Process() == DIOSTREAMTLS13SESSION_RESULT_ERROR);
  status = status && trailingkeyupdateclient.IsError();

  tests->console->Printf(_L(" %-42s : %s\n"), _L("Data after KeyUpdate in the same record is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  DIOSTREAMTLS13SESSION prematurekeyupdate;
  XBUFFER             prematurekeyupdateoutput;

  status = prematurekeyupdate.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  status = status && !prematurekeyupdate.KeyUpdate_Create(false, prematurekeyupdateoutput);

  tests->console->Printf(_L(" %-42s : %s\n"), _L("KeyUpdate before application keys is refused"), status?_L("Ok."):_L("Error!"));

  tests->console->Printf(_L("\n"));

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOStreamTLS_SessionIni(DIOSTREAMTLS13SESSION& session, DIOSTREAMTLSKEYSCHEDULE_ROLE role)
* @brief      Initialize one deterministic TLS 1.3 application epoch from the RFC 8448 transcript
* @note       The same setup is used for both roles to verify the role-neutral application record processing.
* @ingroup    TESTS
*
* @param[in]  session : Session to initialize.
* @param[in]  role : Role of this end.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOStreamTLS_SessionIni(DIOSTREAMTLS13SESSION& session, DIOSTREAMTLSKEYSCHEDULE_ROLE role)
{
  XBUFFER sharedsecret;
  XBUFFER clienthello;
  XBUFFER serverhello;
  XBUFFER encryptedextensions;
  XBUFFER certificate;
  XBUFFER certificateverify;
  XBUFFER serverfinished;

  sharedsecret.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SHAREDSECRET, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SHAREDSECRET));
  clienthello.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));
  serverhello.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO));
  encryptedextensions.Add(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS));
  certificate.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE));
  certificateverify.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY));
  serverfinished.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED));

  if(!session.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, role)) return false;

  if(!session.Transcript_Add(clienthello) || !session.Transcript_Add(serverhello) ||
     !session.HandshakeKeys_Activate(sharedsecret))
    {
      return false;
    }

  if(!session.Transcript_Add(encryptedextensions) || !session.Transcript_Add(certificate) ||
     !session.Transcript_Add(certificateverify) || !session.Transcript_Add(serverfinished))
    {
      return false;
    }

  if(!session.ApplicationKeys_Activate(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL) ||
     !session.ApplicationKeys_Activate(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE))
    {
      return false;
    }

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOStreamTLS_Check(DEVTESTS_CONSOLE* tests, XCHAR* leyend, XBUFFER& got, XBYTE* expected, XDWORD sizeexpected)
* @brief      Compares a result with the value published by the RFC 8448 and shows it
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
* @param[in]  leyend : legend text shown with the result.
* @param[in]  got : buffer produced by the classes under test.
* @param[in]  expected : value published by the RFC.
* @param[in]  sizeexpected : size of the published value.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOStreamTLS_Check(DEVTESTS_CONSOLE* tests, XCHAR* leyend, XBUFFER& got, XBYTE* expected, XDWORD sizeexpected)
{
  bool status = got.Compare(expected, sizeexpected);

  tests->console->Printf(_L(" %-38s : %s\n"), leyend, status?_L("Ok."):_L("Error!"));

  if(!status)
    {
      tests->console->Printf(_L(" obtained : "));

      for(int c=0; c<(int)(got.GetSize()); c++)
        {
          tests->console->Printf(_L("%02X"), got.GetByte(c));
        }

      tests->console->Printf(_L("\n expected : "));

      for(int c=0; c<(int)(sizeexpected); c++)
        {
          tests->console->Printf(_L("%02X"), expected[c]);
        }

      tests->console->Printf(_L("\n"));
    }

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOStreamTLS_BuildKeySchedule(DIOSTREAMTLS13KEYSCHEDULE& keyschedule, DIOSTREAMTLSKEYSCHEDULE_ROLE role)
* @brief      Runs the whole key schedule of the RFC 8448 handshake for one of the two roles
* @note       Only the role changes between the client and the server: this is what the second phase will reuse.
* @ingroup    TESTS
*
* @param[in]  keyschedule : key schedule to build.
* @param[in]  role : role of this end of the connection.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOStreamTLS_BuildKeySchedule(DIOSTREAMTLS13KEYSCHEDULE& keyschedule, DIOSTREAMTLSKEYSCHEDULE_ROLE role)
{
  XBUFFER sharedsecret;
  XBUFFER transcript;
  XBUFFER transcripthash;

  sharedsecret.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SHAREDSECRET, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SHAREDSECRET));

  if(!keyschedule.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, role))   return false;
  if(!keyschedule.EarlySecret_Calculate())                                 return false;
  if(!keyschedule.HandshakeSecret_Calculate(sharedsecret))                 return false;

  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));
  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO));

  if(!keyschedule.TranscriptHash(transcript, transcripthash))              return false;
  if(!keyschedule.HandshakeTrafficSecrets_Calculate(transcripthash))       return false;
  if(!keyschedule.MasterSecret_Calculate())                                return false;

  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS));
  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE));
  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY));
  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED));

  if(!keyschedule.TranscriptHash(transcript, transcripthash))              return false;

  return keyschedule.ApplicationTrafficSecrets_Calculate(transcripthash);
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOStreamTLS_KeySchedule(DEVTESTS_CONSOLE* tests)
* @brief      Runs the TLS key schedule test against the trace of the RFC 8448
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOStreamTLS_KeySchedule(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  DIOSTREAMTLS13KEYSCHEDULE keyschedule;
  XBUFFER                 sharedsecret;
  XBUFFER                 transcript;
  XBUFFER                 transcripthash;
  XBUFFER                 key;
  XBUFFER                 IV;
  XBUFFER                 verifydata;
  bool                    status = false;

  sharedsecret.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SHAREDSECRET, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SHAREDSECRET));

  tests->console->Printf(_L("[ Cipher suite and role ]\n"));

  status = keyschedule.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT);
  tests->console->Printf(_L(" %-38s : %s\n"), _L("Ini with AES_128_GCM_SHA256"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = ((keyschedule.GetHashSize() == 32) && (keyschedule.GetKeySize() == 16) && (keyschedule.GetIVSize() == 12));
  tests->console->Printf(_L(" %-38s : %s\n"), _L("Sizes hash 32, key 16, iv 12"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = keyschedule.Ini(0x0000, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT)?false:true;
  tests->console->Printf(_L(" %-38s : %s\n"), _L("An unknown cipher suite is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ The three secrets of the schedule ]\n"));

  if(!keyschedule.Ini(DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT)) return false;

  if(!keyschedule.EarlySecret_Calculate()) return false;
  status = Test_DIOStreamTLS_Check(tests, _L("Early Secret"), *keyschedule.GetEarlySecret(), DEVTESTS_CONSOLE_TLS_RFC8448_EARLYSECRET, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_EARLYSECRET));
  if(!status) return false;

  if(!keyschedule.HandshakeSecret_Calculate(sharedsecret)) return false;
  status = Test_DIOStreamTLS_Check(tests, _L("Handshake Secret"), *keyschedule.GetHandshakeSecret(), DEVTESTS_CONSOLE_TLS_RFC8448_HANDSHAKESECRET, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_HANDSHAKESECRET));
  if(!status) return false;

  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHELLO));
  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHELLO));

  if(!keyschedule.TranscriptHash(transcript, transcripthash))        return false;
  if(!keyschedule.HandshakeTrafficSecrets_Calculate(transcripthash)) return false;
  if(!keyschedule.MasterSecret_Calculate())                          return false;

  status = Test_DIOStreamTLS_Check(tests, _L("Master Secret"), *keyschedule.GetMasterSecret(), DEVTESTS_CONSOLE_TLS_RFC8448_MASTERSECRET, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_MASTERSECRET));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ Traffic secrets, asked for by direction and never by role ]\n"));

  status = Test_DIOStreamTLS_Check(tests, _L("Handshake, local (of the client)"), *keyschedule.GetTrafficSecret(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_HANDSHAKE, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL), DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHSTRAFFIC, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHSTRAFFIC));
  if(!status) return false;

  status = Test_DIOStreamTLS_Check(tests, _L("Handshake, remote (of the server)"), *keyschedule.GetTrafficSecret(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_HANDSHAKE, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE), DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHSTRAFFIC, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHSTRAFFIC));
  if(!status) return false;

  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS));
  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE));
  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY));

  if(!keyschedule.TranscriptHash(transcript, transcripthash)) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ Finished ]\n"));

  if(!keyschedule.CalculateFinished(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE, transcripthash, verifydata)) return false;

  status = Test_DIOStreamTLS_Check(tests, _L("verify data of the server Finished"), verifydata, &DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED[4], sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED) - 4);
  if(!status) return false;

  XBUFFER receivedverifydata;
  XBUFFER forgedverifydata;

  receivedverifydata.Add(&DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED[4], sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED) - 4);

  status = keyschedule.VerifyFinished(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE, transcripthash, receivedverifydata);
  tests->console->Printf(_L(" %-38s : %s\n"), _L("The server Finished is accepted"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  forgedverifydata.Add(receivedverifydata);
  forgedverifydata.Get()[0] ^= 0x01;

  status = keyschedule.VerifyFinished(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE, transcripthash, forgedverifydata)?false:true;
  tests->console->Printf(_L(" %-38s : %s\n"), _L("A forged Finished is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  transcript.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED));

  if(!keyschedule.TranscriptHash(transcript, transcripthash))                                              return false;
  if(!keyschedule.CalculateFinished(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL, transcripthash, verifydata))  return false;

  status = Test_DIOStreamTLS_Check(tests, _L("verify data of the client Finished"), verifydata, &DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHED[4], sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHED) - 4);
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ Application secrets and the eight traffic keys ]\n"));

  if(!keyschedule.ApplicationTrafficSecrets_Calculate(transcripthash)) return false;

  status = Test_DIOStreamTLS_Check(tests, _L("Application, local (of the client)"), *keyschedule.GetTrafficSecret(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL), DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTAPTRAFFIC, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTAPTRAFFIC));
  if(!status) return false;

  status = Test_DIOStreamTLS_Check(tests, _L("Application, remote (of the server)"), *keyschedule.GetTrafficSecret(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE), DEVTESTS_CONSOLE_TLS_RFC8448_SERVERAPTRAFFIC, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERAPTRAFFIC));
  if(!status) return false;

  if(!keyschedule.GetTrafficKeys(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_HANDSHAKE, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL, key, IV)) return false;
  if(!Test_DIOStreamTLS_Check(tests, _L("Client handshake write key"), key, DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHSKEY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHSKEY))) return false;
  if(!Test_DIOStreamTLS_Check(tests, _L("Client handshake write iv") , IV , DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHSIV , sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHSIV)))  return false;

  if(!keyschedule.GetTrafficKeys(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_HANDSHAKE, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE, key, IV)) return false;
  if(!Test_DIOStreamTLS_Check(tests, _L("Server handshake write key"), key, DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHSKEY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHSKEY))) return false;
  if(!Test_DIOStreamTLS_Check(tests, _L("Server handshake write iv") , IV , DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHSIV , sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHSIV)))  return false;

  if(!keyschedule.GetTrafficKeys(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL, key, IV)) return false;
  if(!Test_DIOStreamTLS_Check(tests, _L("Client application write key"), key, DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTAPKEY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTAPKEY))) return false;
  if(!Test_DIOStreamTLS_Check(tests, _L("Client application write iv") , IV , DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTAPIV , sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTAPIV)))  return false;

  if(!keyschedule.GetTrafficKeys(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE, key, IV)) return false;
  if(!Test_DIOStreamTLS_Check(tests, _L("Server application write key"), key, DEVTESTS_CONSOLE_TLS_RFC8448_SERVERAPKEY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERAPKEY))) return false;
  if(!Test_DIOStreamTLS_Check(tests, _L("Server application write iv") , IV , DEVTESTS_CONSOLE_TLS_RFC8448_SERVERAPIV , sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERAPIV)))  return false;

  // -----------------------------------------------------------------------------------------------
  // The same schedule seen by a server: what was local becomes remote and the other way round. Nothing else changes.

  tests->console->Printf(_L("\n[ The same schedule from the point of view of a server ]\n"));

  DIOSTREAMTLS13KEYSCHEDULE serverschedule;

  status = Test_DIOStreamTLS_BuildKeySchedule(serverschedule, DIOSTREAMTLSKEYSCHEDULE_ROLE_SERVER);
  tests->console->Printf(_L(" %-38s : %s\n"), _L("Built with the server role"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = Test_DIOStreamTLS_Check(tests, _L("Handshake, local (of the server)"), *serverschedule.GetTrafficSecret(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_HANDSHAKE, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL), DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHSTRAFFIC, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERHSTRAFFIC));
  if(!status) return false;

  status = Test_DIOStreamTLS_Check(tests, _L("Handshake, remote (of the client)"), *serverschedule.GetTrafficSecret(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_HANDSHAKE, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE), DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHSTRAFFIC, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTHSTRAFFIC));

  tests->console->Printf(_L("\n"));

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOStreamTLS_Record(DEVTESTS_CONSOLE* tests)
* @brief      Runs the TLS record layer test against the trace of the RFC 8448
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOStreamTLS_Record(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  DIOSTREAMTLS13KEYSCHEDULE   clientschedule;
  DIOSTREAMTLS13KEYSCHEDULE   serverschedule;
  DIOSTREAMTLSRECORD        clientrecord;
  DIOSTREAMTLSRECORD        serverrecord;
  DIOSTREAMTLS_CONTENTTYPE  contenttype;
  XBUFFER                   stream;
  XBUFFER                   onerecord;
  XBUFFER                   flight;
  XBUFFER                   expectedflight;
  bool                      status = false;

  if(!Test_DIOStreamTLS_BuildKeySchedule(clientschedule, DIOSTREAMTLSKEYSCHEDULE_ROLE_CLIENT)) return false;
  if(!Test_DIOStreamTLS_BuildKeySchedule(serverschedule, DIOSTREAMTLSKEYSCHEDULE_ROLE_SERVER)) return false;

  // -----------------------------------------------------------------------------------------------
  // The record the server of the RFC sends with its whole flight.

  tests->console->Printf(_L("[ Deciphering the flight of the server ]\n"));

  status = clientrecord.Ini(&clientschedule);
  tests->console->Printf(_L(" %-38s : %s\n"), _L("Ini of the record layer"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = (!clientrecord.IsProtected(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL) &&
            !clientrecord.IsProtected(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE));
  tests->console->Printf(_L(" %-38s : %s\n"), _L("Nothing protected before the keys"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = clientrecord.SetKeys(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_HANDSHAKE, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE);
  tests->console->Printf(_L(" %-38s : %s\n"), _L("Handshake keys of the remote end"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  stream.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFLIGHTRECORD, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFLIGHTRECORD));

  status = DIOSTREAMTLSRECORD::Record_Extract(stream, onerecord);
  tests->console->Printf(_L(" %-38s : %s\n"), _L("One whole record out of the stream"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = stream.IsEmpty();
  tests->console->Printf(_L(" %-38s : %s\n"), _L("The stream is left empty"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = clientrecord.Unprotect(onerecord, contenttype, flight);
  tests->console->Printf(_L(" %-38s : %s\n"), _L("Deciphered and authenticated"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = ((contenttype == DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE) &&
            (clientrecord.GetSequence(DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE) == 1));
  tests->console->Printf(_L(" %-38s : %s\n"), _L("Inner type handshake, sequence 1"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  expectedflight.Add(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_ENCRYPTEDEXTENSIONS));
  expectedflight.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATE));
  expectedflight.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CERTIFICATEVERIFY));
  expectedflight.Add(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_SERVERFINISHED));

  status = Test_DIOStreamTLS_Check(tests, _L("It is EE, Cert, CertVerify, Finished"), flight, expectedflight.Get(), expectedflight.GetSize());
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------
  // The record this end writes, in the clear first and protected afterwards.

  tests->console->Printf(_L("\n[ Protecting the record this end writes ]\n"));

  DIOSTREAMTLSRECORD  writer;
  XBUFFER             clientfinished;
  XBUFFER             records;

  clientfinished.Add(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHED, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHED));

  if(!writer.Ini(&clientschedule)) return false;

  status = writer.Protect(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE, clientfinished, records);
  if(status)
    {
      status = ((records.GetByte(0) == 0x16) && (records.GetByte(1) == 0x03) && (records.GetByte(2) == 0x03) &&
                (records.GetSize() == clientfinished.GetSize() + DIOSTREAMTLS_MSG_RECORDHEADER_SIZE));
    }

  tests->console->Printf(_L(" %-38s : %s\n"), _L("In the clear it keeps its own type"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  records.Delete();

  status = writer.SetKeys(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_HANDSHAKE, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL);
  if(status)
    {
      status = writer.Protect(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE, clientfinished, records);
    }

  if(status)
    {
      status = ((records.GetByte(0) == 0x17) && (records.GetByte(1) == 0x03) && (records.GetByte(2) == 0x03));
    }

  tests->console->Printf(_L(" %-38s : %s\n"), _L("Protected it looks like app data"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = Test_DIOStreamTLS_Check(tests, _L("Byte for byte the record of the RFC"), records, DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHEDRECORD, sizeof(DEVTESTS_CONSOLE_TLS_RFC8448_CLIENTFINISHEDRECORD));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------
  // And the server reads back what the client has just written.

  tests->console->Printf(_L("\n[ The server reads what the client wrote ]\n"));

  XBUFFER extracted;
  XBUFFER recovered;

  if(!serverrecord.Ini(&serverschedule)) return false;

  status = serverrecord.SetKeys(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_HANDSHAKE, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE);
  if(status)
    {
      stream.Delete();
      stream.Add(records);

      status = DIOSTREAMTLSRECORD::Record_Extract(stream, extracted);
    }

  if(status)
    {
      status = serverrecord.Unprotect(extracted, contenttype, recovered);
    }

  if(status)
    {
      status = (recovered.Compare(clientfinished) && (contenttype == DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE));
    }

  tests->console->Printf(_L(" %-38s : %s\n"), _L("The client Finished is recovered"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ Fragmentation, padding and partial records ]\n"));

  DIOSTREAMTLSRECORD  fragmenter;
  DIOSTREAMTLSRECORD  defragmenter;
  XBUFFER             big;
  XBUFFER             manyrecords;
  XBUFFER             rebuilt;
  XBUFFER             onefragment;
  XBUFFER             piece;
  int                 nrecords = 0;

  if(!fragmenter.Ini(&clientschedule))   return false;
  if(!defragmenter.Ini(&serverschedule)) return false;

  if(!fragmenter.SetKeys(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_LOCAL))    return false;
  if(!defragmenter.SetKeys(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_APPLICATION, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE)) return false;

  status = (!fragmenter.SetMaxPlainSize(0) && !fragmenter.SetMaxPlainSize(DIOSTREAMTLSRECORD_MAXPLAINSIZE + 1));
  tests->console->Printf(_L(" %-38s : %s\n"), _L("A size out of range is refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  fragmenter.SetMaxPlainSize(100);
  fragmenter.SetPaddingSize(7);

  for(XDWORD c=0; c<450; c++)
    {
      big.Add((XBYTE)(c & 0xFF));
    }

  status = fragmenter.Protect(DIOSTREAMTLS_MSG_CONTENTTYPE_APPLICATION_DATA, big, manyrecords);
  if(!status) return false;

  while(DIOSTREAMTLSRECORD::Record_Extract(manyrecords, onefragment))
    {
      DIOSTREAMTLS_CONTENTTYPE fragmenttype;

      if(!defragmenter.Unprotect(onefragment, fragmenttype, piece))                break;
      if(fragmenttype != DIOSTREAMTLS_MSG_CONTENTTYPE_APPLICATION_DATA)            break;

      rebuilt.Add(piece);
      nrecords++;
    }

  status = ((nrecords == 5) && manyrecords.IsEmpty());
  tests->console->Printf(_L(" %-38s : %s\n"), _L("450 bytes go out as 5 records"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  status = Test_DIOStreamTLS_Check(tests, _L("And they are rebuilt whole"), rebuilt, big.Get(), big.GetSize());
  if(!status) return false;

  XBUFFER partial;
  XBUFFER nothing;

  partial.Add(records.Get(), DIOSTREAMTLS_MSG_RECORDHEADER_SIZE - 1);
  status = (!DIOSTREAMTLSRECORD::Record_Extract(partial, nothing) && (partial.GetSize() == DIOSTREAMTLS_MSG_RECORDHEADER_SIZE - 1));
  tests->console->Printf(_L(" %-38s : %s\n"), _L("An incomplete header consumes nothing"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  partial.Delete();
  partial.Add(records.Get(), records.GetSize() - 1);
  status = (!DIOSTREAMTLSRECORD::Record_Extract(partial, nothing) && (partial.GetSize() == records.GetSize() - 1));
  tests->console->Printf(_L(" %-38s : %s\n"), _L("An incomplete record consumes nothing"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------

  tests->console->Printf(_L("\n[ Records that have been tampered with ]\n"));

  DIOSTREAMTLSRECORD  victim;
  XBUFFER             tampered;
  XBUFFER             discarded;

  if(!victim.Ini(&serverschedule))                                                                          return false;
  if(!victim.SetKeys(DIOSTREAMTLS13KEYSCHEDULE_LEVEL_HANDSHAKE, DIOSTREAMTLSKEYSCHEDULE_DIRECTION_REMOTE))     return false;

  tampered.Add(records);
  tampered.Get()[DIOSTREAMTLS_MSG_RECORDHEADER_SIZE] ^= 0x01;

  status = (!victim.Unprotect(tampered, contenttype, discarded) && discarded.IsEmpty());
  tests->console->Printf(_L(" %-38s : %s\n"), _L("Altered body refused, text wiped"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  tampered.Delete();
  tampered.Add(records);
  tampered.Get()[0] = 0x16;                                                     // The header is authenticated too

  status = victim.Unprotect(tampered, contenttype, discarded)?false:true;
  tests->console->Printf(_L(" %-38s : %s\n"), _L("Altered header refused"), status?_L("Ok."):_L("Error!"));
  if(!status) return false;

  // -----------------------------------------------------------------------------------------------
  // The record header is now shared with DIOSTREAMTLS_MSG_RECORD, so a ClientHello has to stay consistent.

  tests->console->Printf(_L("\n[ The header shared with DIOSTREAMTLS_MSG_RECORD ]\n"));

  DIOSTREAMTLS_MSG_RECORD<DIOSTREAMTLS_MSG_FRAGMENT<DIOSTREAMTLS_MSG_HANDSHAKE_CLIENTHELLO> >  clienthello;
  XBUFFER                                                                                      buffer;

  clienthello.SetContenType(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE);
  clienthello.SetProtocolVersion(DIOSTREAMTLS_MSG_VERSION_TLS_1_2);
  clienthello.GetFragment()->SetMsgType(DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE_CLIENT_HELLO);
  clienthello.GetFragment()->GetBody()->SetClientVersion(DIOSTREAMTLS_MSG_VERSION_TLS_1_2);
  clienthello.GetFragment()->GetBody()->GetCipherSuites()->Add((XWORD)DIOSTREAMTLS_MSG_CIPHER_AES_128_GCM_SHA256);
  clienthello.GetFragment()->GetBody()->SetCiphersuitesLength(sizeof(XWORD));
  clienthello.GetFragment()->GetBody()->SetCompressionLength(0x01);
  clienthello.GetFragment()->GetBody()->SetCompressionMethod(DIOSTREAMTLS_MSG_COMPRESS_METHOD_NULL);

  clienthello.CalculateLength();
  clienthello.SetToBuffer(buffer, false);

  status = ((buffer.GetByte(0) == DIOSTREAMTLS_MSG_CONTENTTYPE_HANDSHAKE) &&
            (buffer.GetByte(1) == 0x03) && (buffer.GetByte(2) == 0x03) &&
            (clienthello.GetLength() == (buffer.GetSize() - DIOSTREAMTLS_MSG_RECORDHEADER_SIZE)) &&
            (((XWORD)((buffer.GetByte(3) << 8) | buffer.GetByte(4))) == clienthello.GetLength()));

  tests->console->Printf(_L(" %-38s : %s\n"), _L("A ClientHello stays self consistent"), status?_L("Ok."):_L("Error!"));

  tests->console->Printf(_L("\n"));

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_SystemCPUUsage(DEVTESTS_CONSOLE* tests)
* @brief      Runs the system cpuusage test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_SystemCPUUsage(DEVTESTS_CONSOLE* tests)
{
  XSTRING nameapp;

  #ifdef WINDOWS
  nameapp = _L("tests.exe");
  #endif

  #ifdef LINUX
  nameapp = _L("tests");
  #endif


  while(!tests->console->KBHit())
    {      
      tests->console->Clear();

      tests->console->Printf(_L(" CPU usage %-16s : [%3d%%] \n"), _L("Total"), GEN_XSYSTEM.GetCPUUsageTotal());                                                                                             
      tests->console->Printf(_L(" CPU usage %-16s : [%3d%%] \n"), APPLICATION_NAMEAPP, GEN_XSYSTEM.GetCPUUsageForProcessName(nameapp.Get()));       

      /*
      for(int d=0; d<10; d++)
        {            
          for(int c=0; c<100000000; c++)
            {
               int a = 0;
               a++;
            }
        }
       */

      GEN_XSLEEP.Seconds(1);

    }

  tests->console->GetChar();

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_AppAlerts(DEVTESTS_CONSOLE* tests)
* @brief      Runs the app alerts test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_AppAlerts(DEVTESTS_CONSOLE* tests)
{
  int status[APPFLOW_ALERT_TYPE_MAX];
  int result = false;

  if(GEN_APPFLOWALERTS.Ini(&APPFLOW_CFG.GetInstance() , APPLICATION_NAMEAPP 
                                                      , APPLICATION_VERSION
                                                      , APPLICATION_SUBVERSION
                                                      , APPLICATION_SUBVERSIONERR
                                                      , status
                                                      , NULL))
    {
      int result;
      
      result = GEN_APPFLOWALERTS.Send((DIOALERTSSENDER_SMPT | DIOALERTSSENDER_WEB), DIOALERTS_CONDITIONS_ID_GENINTERN_TEST, DIOALERTLEVEL_SERIOUS, _L("Aterta TEST"), _L("Esto es una prueba de Alerta."));
      if(result) result = GEN_APPFLOWALERTS.Send((DIOALERTSSENDER_SMPT | DIOALERTSSENDER_WEB), DIOALERTS_CONDITIONS_ID_GENINTERN_TEST, DIOALERTLEVEL_SERIOUS, _L("Aterta TEST"), _L("Esto es una prueba de Alerta 2."));
  
      GEN_APPFLOWALERTS.End();
    }

  GEN_APPFLOWALERTS.DelInstance();

  return result;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_BluetoothEnum(DEVTESTS_CONSOLE* tests)
* @brief      Runs the bluetooth enum test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_BluetoothEnum(DEVTESTS_CONSOLE* tests)
{
  #ifdef DIO_STREAMBLUETOOTH_ACTIVE

  DIOSTREAMENUMDEVICES* enumdevicesremote = NULL;

  enumdevicesremote = GEN_DIOFACTORY.CreateStreamEnumDevices(DIOSTREAMENUMTYPE_BLUETOOTH_REMOTE);
	if(enumdevicesremote)
	  {					
      XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("Start Search sensors ... ")); 

      XTIMER*  xtimer;

      xtimer = GEN_XFACTORY.CreateTimer();

		  enumdevicesremote->Search();

		  xtimer->Reset();

			while(enumdevicesremote->IsSearching())
        {
          if(tests->console->KBHit()) break;          
				  XSLEEP::GetInstance().MilliSeconds(10);          
				}
					
			for(int c=0;c<(int)enumdevicesremote->GetDevices()->GetSize();c++)
			  {					
				  DIOSTREAMDEVICEBLUETOOTH* devicesearch = (DIOSTREAMDEVICEBLUETOOTH*)enumdevicesremote->GetDevices()->Get(c);
					if(devicesearch) 
						{	
              XSTRING MACstring; 

              devicesearch->GetMAC()->GetXString(MACstring);

              XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("  Sensor [MAC %s] %s"), MACstring.Get(), devicesearch->GetName()->Get()); 
            }
        }

       XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("End Search sensors ... ")); 

      GEN_XFACTORY.DeleteTimer(xtimer);
    }

  GEN_DIOFACTORY.DeleteStreamEnumDevices(enumdevicesremote);			

  #endif

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_BluetoothLEEnum(DEVTESTS_CONSOLE* tests)
* @brief      Runs the bluetooth leenum test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_BluetoothLEEnum(DEVTESTS_CONSOLE* tests)
{
  #ifdef DIO_STREAMBLUETOOTHLE_ACTIVE

  DIOSTREAMENUMDEVICES* enumdevicesremote = NULL;

  enumdevicesremote = GEN_DIOFACTORY.CreateStreamEnumDevices(DIOSTREAMENUMTYPE_BLUETOOTHLE_REMOTE);
	if(enumdevicesremote)
	  {					
      XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("Start Search sensors ... ")); 

      XTIMER*  xtimer;

      xtimer = GEN_XFACTORY.CreateTimer();

		  enumdevicesremote->Search();

		  xtimer->Reset();

			while(enumdevicesremote->IsSearching())
        {
          if(tests->console->KBHit()) break;          
				  XSLEEP::GetInstance().MilliSeconds(10);          
				}
					
      enumdevicesremote->StopSearch(false);
   

			for(int c=0;c<(int)enumdevicesremote->GetDevices()->GetSize();c++)
			  {					
				  DIOSTREAMDEVICEBLUETOOTHLE* devicesearch = (DIOSTREAMDEVICEBLUETOOTHLE*)enumdevicesremote->GetDevices()->Get(c);
					if(devicesearch) 
						{	
              XSTRING   MACstring; 
              XTIMER*   lastscantimer = devicesearch->GetLastScanTimer();
              XSTRING   lastscanmeasurestring;

              lastscantimer->GetMeasureString(lastscanmeasurestring, false);  
              devicesearch->GetMAC()->GetXString(MACstring);
              
              XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("  Sensor [MAC %s] %d last scan: %s"), MACstring.Get(), devicesearch->GetRSSI(), lastscanmeasurestring.Get()); 
            }
        }

      XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("End Search sensors ... ")); 

      GEN_XFACTORY.DeleteTimer(xtimer);
    }

  GEN_DIOFACTORY.DeleteStreamEnumDevices(enumdevicesremote);			

  #endif

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_NTP_Protocol(DEVTESTS_CONSOLE* tests)
* @brief      Runs the ntp protocol test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_NTP_Protocol(DEVTESTS_CONSOLE* tests)
{
  XDATETIME*  xdatetime_local = NULL;
  DIONTP*     ntp             = NULL;
  DIOURL      url;     
  bool        status          = false;  
  
  ntp = GEN_NEW DIONTP();
  if(!ntp)
    {
      return status;   
    }

  xdatetime_local = GEN_XFACTORY.CreateDateTime();
  if(xdatetime_local) 
    {
      xdatetime_local->Read();
    }
   else
    {
      GEN_DELETE ntp;
      return status;
    }

  //_L("1.es.pool.ntp.org"); 
  //_L("1.europe.pool.ntp.org"); 
  //_L("3.europe.pool.ntp.org"); 

  url = _L("1.es.pool.ntp.org");

  xdatetime_local->Read();

  status = ntp->GetTime(url, DIONTP_DEFAULTTIMEOUT, GEN_XSYSTEM.HardwareUseLittleEndian(), (*xdatetime_local));
         
  GEN_DELETE ntp;

  GEN_XFACTORY.DeleteDateTime(xdatetime_local);
   
  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_NTP_InternetServices(DEVTESTS_CONSOLE* tests)
* @brief      Runs the ntp internet services test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_NTP_InternetServices(DEVTESTS_CONSOLE* tests)
{ 
  bool                      status      = false; 

  #ifdef APPFLOW_EXTENDED_INTERNETSTATUS_ACTIVE

  XDATETIME*                datetime1;
  XDATETIME*                datetime2;
  XSTRING                   datetimestr;
  APPFLOWINTERNETSERVICES*  appinternetservices = NULL;
  

  if(APPFLOW_EXTENDED.GetInternetStatus())
    {
      appinternetservices = APPFLOW_EXTENDED.GetInternetStatus()->GetInternetServices();
    }

  if(appinternetservices) 
    {
      return false;
    }

  //while(!tests->console->KBHit())
    {
      int hours = 0;

      datetime1 = appinternetservices->DateTime_GetLocal();
      if(datetime1)
        {    
          datetime1->GetDateTimeToString(XDATETIME_FORMAT_STANDARD, datetimestr);
          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[NTP] Date Time Local : %s"), datetimestr.Get()); 

          datetime1->GetDateTimeToStringISO8601(XDATETIME_FORMAT_ISO8601_STANDARD, datetimestr);
          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[NTP] Date Time Local ISO8601: %s"), datetimestr.Get()); 

          status = true;
        }

      datetime2 = appinternetservices->DateTime_GetUTC();
      if(datetime2)
        {    
          datetime2->GetDateTimeToString(XDATETIME_FORMAT_STANDARD, datetimestr);
          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[NTP] Date Time UTC : %s"), datetimestr.Get()); 

          datetime2->GetDateTimeToStringISO8601(XDATETIME_FORMAT_ISO8601_STANDARD, datetimestr);
          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[NTP] Date Time UTC ISO8601 : %s"), datetimestr.Get());       

          datetime2->GetDateTimeToStringISO8601(XDATETIME_FORMAT_ISO8601_STANDARD | XDATETIME_FORMAT_ISO8601_ADDHOUROFFSET, datetimestr);
          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[NTP] Date Time UTC + offset ISO8601  : %s"), datetimestr.Get());       
          
          status = true;
        }

     GEN_XSLEEP.MilliSeconds(100);
    } 

  
  #endif

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_Sound(DEVTESTS_CONSOLE* tests)
* @brief      Runs the sound test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_Sound(DEVTESTS_CONSOLE* tests)
{  
  bool        status = false; 

  #ifdef SND_ACTIVE

  SNDPLAYCFG  playCFG;
  SNDITEM*    item[]   = { NULL, NULL, NULL }; 
  SNDITEM*    itemfile = NULL; 
  XPATH       xpath;
 

  if(!GEN_SNDFACTORY.IsSoundActive())
    {
      tests->console->Printf(_L(" Sound system: no avaible (no active) !!!)\n"));

      return status;
    }
   
  if(!GEN_XSYSTEM.Sound_SetLevel(90)) 
    {
      return false;
    }
      
  GEN_XSLEEP.MilliSeconds(100);
    
  status = true;

  //-------------------------------------------------------------------------

  item[0] = GEN_SNDFACTORY.CreateItem(640 , 3000);
  item[1] = GEN_SNDFACTORY.CreateItem(1000, 3000);
  item[2] = GEN_SNDFACTORY.CreateItem(850 , 3000); 


  GEN_SNDFACTORY.Sound_Play(item[0], &playCFG, SNDFACTORY_INLOOP);   
  GEN_SNDFACTORY.Sound_WaitToEnd(item[0], SNDFACTORY_MAXTIMEOUT_INFINITE, Test_WaitSound);  

  GEN_SNDFACTORY.Sound_Pause(item[0]);
 
  APPFLOW_EXTENDED.ShowAll();
  tests->Show_PlaySound();  

  GEN_XSLEEP.Seconds(3); 
  
  GEN_SNDFACTORY.Sound_Play(item[0], &playCFG, SNDFACTORY_INLOOP); 
  GEN_SNDFACTORY.Sound_WaitToEnd(item[0], SNDFACTORY_MAXTIMEOUT_INFINITE, Test_WaitSound);  

  GEN_SNDFACTORY.Sound_Stop(item[0]);
  
  APPFLOW_EXTENDED.ShowAll();
  tests->Show_PlaySound();   
 
    
  for(XDWORD c=0; c<sizeof(item)/sizeof(SNDITEM*); c++)
    {
      GEN_SNDFACTORY.Sound_Play(item[c], &playCFG);      
    }

  GEN_SNDFACTORY.Sound_WaitAllToEnd(SNDFACTORY_MAXTIMEOUT_INFINITE, Test_WaitSound);
  
  
  GEN_SNDFACTORY.MasterVolume_Set(50);

  playCFG.SetVolume(100);

  GEN_SNDFACTORY.Sound_Play(item[0], &playCFG); 

  int volume = GEN_SNDFACTORY.Sound_GetVolume(item[0]);
  
  GEN_SNDFACTORY.Sound_WaitAllToEnd(SNDFACTORY_MAXTIMEOUT_INFINITE, Test_WaitSound);
          
  GEN_SNDFACTORY.DeleteAllItems();
  
    
  //-------------------------------------------------------------------------
  
  
  GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_SOUNDS, xpath);
  xpath.Slash_Add();
  xpath.Add(_L("alarm.ogg"));

  itemfile = GEN_SNDFACTORY.CreateItem(xpath);
        
  GEN_SNDFACTORY.Sound_Play(itemfile, &playCFG, 3);    
  
  GEN_SNDFACTORY.Sound_WaitAllToEnd(SNDFACTORY_MAXTIMEOUT_INFINITE, Test_WaitSound);

  GEN_SNDFACTORY.DeleteAllItems();
  
  //-------------------------------------------------------------------------
  
  
  GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_SOUNDS, xpath);
  xpath.Slash_Add();
  xpath.Add(_L("imperialmarch60.wav"));

  itemfile = GEN_SNDFACTORY.CreateItem(xpath);
        
  GEN_SNDFACTORY.Sound_Play(itemfile, &playCFG);    
  
  GEN_SNDFACTORY.Sound_WaitAllToEnd(SNDFACTORY_MAXTIMEOUT_INFINITE, Test_WaitSound);

  GEN_SNDFACTORY.DeleteAllItems();
  

  //-------------------------------------------------------------------------

  #endif

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_ProcessManager(DEVTESTS_CONSOLE* tests)
* @brief      Runs the process manager test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_ProcessManager(DEVTESTS_CONSOLE* tests)
{
  XSTRING             command;
  XSTRING             params; 
  XSTRING             in;
  XSTRING             out;
  int                 returncode;
  XVECTOR<XPROCESS*>  applist;
    
  //command = _L("C:\\Program Files\\Notepad++\\notepad++.exe");
  command = _L("C:\\Program Files\\CMake\\bin\\cmake.exe");
  params  = _L("--version áñ");
  
  bool status = GEN_XPROCESSMANAGER.Application_Execute(command.Get(), params.Get(), &in, &out, &returncode);

  XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("Exec: %s "), (status?_L("Ok"):_L("Error!")));


  /*
  command = _L("/usr/bin/festival");
  params  = _L("--language spanish --tts");
  in      = _L("Hola radiola");
 
  bool status = GEN_XPROCESSMANAGER.Application_Execute(command.Get(), params.Get(), &in, NULL, &returncode);
  
  XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("Exec: %s "), (status?_L("Ok"):_L("Error!")));

  */


  /*
  bool status = GEN_XPROCESSMANAGER.Application_GetRunningList(applist);

  if(status)
    {

      XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("-- Applications ------------------------------------------------------------------"));        
      for(XDWORD c=0; c<applist.GetSize(); c++)
        {
          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("%04d    ID    : %d"), c, applist.Get(c)->GetID());        
          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("        Path  : %s")   , applist.Get(c)->GetPath()->Get());        
          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("        Name  : %s")   , applist.Get(c)->GetName()->Get());  
          if(!applist.Get(c)->GetWindowTitle()->IsEmpty())
            {
              XTRACE_PRINTCOLOR(XTRACE_COLOR_PURPLE, _L("        Title : [%s]")    , applist.Get(c)->GetWindowTitle()->Get());                     
            }
        }
    }
    
  applist.DeleteContents();
  applist.DeleteAll();
  */

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_GetUserAndDomain(DEVTESTS_CONSOLE* tests)
* @brief      Runs the get user and domain test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_GetUserAndDomain(DEVTESTS_CONSOLE* tests)
{
  bool status;

  XSTRING   user;
  XSTRING   domain;

  status = GEN_XSYSTEM.GetUserAndDomain(user, domain);
  
  tests->console->Printf(_L(" user [%s] domain [%s] \n\n"), user.Get(), domain.Get());

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_I2C_GPIO_MCP2317(DEVTESTS_CONSOLE* tests)
* @brief      Runs the i2 c gpio mcp2317 test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_I2C_GPIO_MCP2317(DEVTESTS_CONSOLE* tests)
{	
	tests->console->PrintMessage(_L(" I2C Test START..."), 1, true, true);	
		
	DIOI2CGPIOMCP2317* mcp2317 = GEN_NEW DIOI2CGPIOMCP2317;
	if(!mcp2317) return false;
	
	if(mcp2317->Ini(1, 0x23, 10))
		{
			tests->console->PrintMessage(_L(" Ini ..."), 1, true, true);	
			
			mcp2317->Configure();

			XBYTE rvalue = 0;
		  XBYTE wvalue;

			while(!tests->console->KBHit())
				{																
					for(int d=0; d<2; d++)
						{	
							wvalue = (!d)?0x01:0x80;

							for(int c=0; c<8; c++)
								{					
									
									tests->console->Printf(_L("Inputs: "));
									if(mcp2317->ReadInputs(DIOI2CGPIOMCP2317PORT_A, rvalue)) 
													tests->console->Printf(_L("%02X \r"), rvalue); 
									   else tests->console->Printf(_L("No read. \r"), rvalue); 
									

									mcp2317->WriteOutputs(DIOI2CGPIOMCP2317PORT_B, wvalue);
									
									if(!d) wvalue <<= 1; else wvalue >>= 1;

									XSLEEP::GetInstance().MilliSeconds(150);			

									if(tests->console->KBHit()) break;
								}
						}					
				}
					
			if(mcp2317->End())
				{
					tests->console->PrintMessage(_L(" End ..."), 1, true, true);	
				}
		}

	GEN_DELETE mcp2317;
	
  return true;	
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_SPI_GPIO_MCP2317(DEVTESTS_CONSOLE* tests)
* @brief      Runs the spi gpio mcp2317 test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_SPI_GPIO_MCP2317(DEVTESTS_CONSOLE* tests)
{	
	tests->console->PrintMessage(_L(" SPI Test START..."), 1, true, true);	
		
  /*
	DIOSPIGPIOMCP23S17* mcp23s17 = GEN_NEW DIOSPIGPIOMCP23S17();
	if(!mcp23s17) return false;
	
	if(mcp23s17->Ini(0, 10))
		{
			tests->console->PrintMessage(_L(" Ini ..."),1,true,true);	

      mcp23s17->Configure();
			   
			XBYTE rvalue = 0;
		  
			while(!tests->console->KBHit())
				{																					
          mcp23s17->Write_Register(DIOSPIGPIOMCP23S17_GPIOA, 0, 0xFF);
					XSLEEP::GetInstance().MilliSeconds(150);			

          mcp23s17->Write_Register(DIOSPIGPIOMCP23S17_GPIOA, 0, 0x00);
					XSLEEP::GetInstance().MilliSeconds(150);			

				  if(tests->console->KBHit()) break;
					
				}
					
			if(mcp23s17->End())
				{
					tests->console->PrintMessage(_L(" End ..."),1,true,true);	
				}
		}

	GEN_DELETE mcp23s17;
  */
	
  return true;	
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_WifiManagerMode(DEVTESTS_CONSOLE* tests)
* @brief      Runs the wifi manager mode test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_WifiManagerMode(DEVTESTS_CONSOLE* tests)
{
  DIOWIFIMANAGERMODE* wifimanagermode = NULL;
  bool                status          = false;

  wifimanagermode = GEN_DIOFACTORY.CreateWifiManagerMode();
  status = wifimanagermode?true:false;
  if(status) 
    {
      wifimanagermode->SetSelectNetInterface(_L("wlan0"));     
      wifimanagermode->SetModeType(DIOWIFIMANAGER_MODETYPE_LINUX_CLIENT_NM);
    }  

  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("Do Connexion ..."));
  status = wifimanagermode->SetMode_Client(_L("AIQ_m09888_09888"), NULL, false);   
  
  XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("Connexion status: %s"), status?_L("Ok"):_L("Error!"));

  //-------------------------------------------------------------------------
 /*
  XSTRING  _aim;
  DIOIP    _IP;
  XSTRING  _IPstring;

  _aim = _L("xtracebizintek.dyndns.org"); 
 
  GEN_DIODNSRESOLVER.ResolveURL(_aim.Get(), _IP);

  _IP.GetXString(_IPstring);

  tests->console->Printf(_L("\n url: %s IP: %s \n"), _aim.Get(), _IPstring.Get());
 

  //-------------------------------------------------------------------------

  APPFLOW_CFG.SetAutomaticDNSResolver();

  */

  for(int c=0; c<5; c++)
    {
      XSTRING string;
      string.ConvertFromBoolean(wifimanagermode->IsDisconnected(), XSTRINGBOOLEANMODE_HUMAN);
      XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("Is Connected: %s"), string.Get());
      GEN_XSLEEP.Seconds(1);
    }

  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("Disconnexion."));
  wifimanagermode->Disconnect();

  GEN_DIOFACTORY.DeleteWifiManagerMode(wifimanagermode);

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_NotificationsManager(DEVTESTS_CONSOLE* tests)
* @brief      Runs the notifications manager test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_NotificationsManager(DEVTESTS_CONSOLE* tests)
{
  DIONOTIFICATIONSMANAGER* notificationmanager = GEN_DIOFACTORY.CreateNotificationsManager();
  if(!notificationmanager) return false;

  XSTRING genericapp;
  genericapp.Format(_L("Infodesig.%s"), APPLICATION_NAMEFILE);

  notificationmanager->Ini(APPLICATION_NAMEAPP, genericapp.Get());
  
  XSTRING msg;
  XSTRING msgfinal;

  msg = _L("Esto es una prueba de mensaje");

  msgfinal = msg;

  DIONOTIFICATION notification;

  notification.Get_Title()->Set(APPLICATION_NAMEAPP);
  notification.Get_Message()->Set(msgfinal);

  notification.Application_SetHandle(tests->Application_GetHandle());
  notificationmanager->Do(notification);

  notificationmanager->End();
  GEN_DIOFACTORY.DeleteNotificationsManager(notificationmanager);
 
  return true;
} 


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_ATCommandGSM(DEVTESTS_CONSOLE* tests)
* @brief      Runs the atcommand gsm test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_ATCommandGSM(DEVTESTS_CONSOLE* tests)
{				
  #define ATCOMMAND_PIN  _L("7266")

	tests->console->Printf(_L("\n Creando dispositivo... \n"), 1 , true, true);	

	DIOSTREAMUARTCONFIG* diostreamcfg = GEN_NEW DIOSTREAMUARTCONFIG();
	if(diostreamcfg)
    {
	    diostreamcfg->SetFromString(_L("/dev/ttyUSB2,115200,8,N,1,NONE"));

	    DIOSTREAMUART* diostream = (DIOSTREAMUART*)DIOFACTORY::GetInstance().CreateStreamIO(diostreamcfg);
	    if(diostream) 
        {
	        DIOATCMDGSM* dioatcmdgsm =  GEN_NEW DIOATCMDGSM(diostream);
	        if(dioatcmdgsm) 
            {					
	            tests->console->Printf(_L(" Comprobando dispositivo... \n"), 1 , true, true);	

	            if(dioatcmdgsm->Ini(15, true, true))
		            {																	
			            tests->console->Printf(_L(" Dispositivo comandos AT accesible... \n \n"), 1 , true, true);	
			
			            XSTRING   string;
			            XSTRING   value;
                  bool      isPINresulto = false;

			            for(int c=0;c<10;c++)
				            {
					            string.Empty();
							
					            switch(c)
						            {
							            case    0 : if(dioatcmdgsm->GetManufactured(value)==DIOATCMD_ERROR_NONE)					  string.Format(_L(" Fabricante : %s"), value.Get());                           break;
							            case    1 : if(dioatcmdgsm->GetModel(value)==DIOATCMD_ERROR_NONE)									  string.Format(_L(" Modelo de terminal : %s"), value.Get());                           break;											
							            case    2 : if(dioatcmdgsm->GetIMEI(value)==DIOATCMD_ERROR_NONE)								  	string.Format(_L(" IMEI : %s"), value.Get());                           break;
							            case    3 : if(dioatcmdgsm->GetVersion(value)==DIOATCMD_ERROR_NONE)								  string.Format(_L(" Version : %s"), value.Get());                           break;	
														
                          case    4 : if(dioatcmdgsm->PIN_Is(isPINresulto)==DIOATCMD_ERROR_NONE)      string.Format(_L(" SIM PIN resuelto : %s"), isPINresulto?_L("Si"):_L("No"));       break;	 

                          case    5 : if(!isPINresulto)
                                        {
                                          //DIOATCMD_ERROR error;
                                          //error = dioatcmdgsm->PIN_Activate(ATCOMMAND_PIN, false);                                      
                                          //string.Format(_L(" SIM PIN desactivado   : %s [%s]"), ((error == DIOATCMD_ERROR_NONE)?_L("Si"):_L("No")), ATCOMMAND_PIN);     	                                                      

                                          bool isenter = false;
                                          if(dioatcmdgsm->PIN_Enter(ATCOMMAND_PIN, isenter)==DIOATCMD_ERROR_NONE) string.Format(_L(" SIM PIN introducido : %s [%s]"), (isenter?_L("Si"):_L("No")), ATCOMMAND_PIN);     	                                                      
                                        }
                                      break;


							            case    6 : { int RSSI = 0;
													              int BER  = 0;
																			
  													            if(dioatcmdgsm->GetSignalQuality(RSSI, BER)==DIOATCMD_ERROR_NONE)		  string.Format(_L(" Calidad de senal : (RSSI %d) (BER %d)"), RSSI, BER);																																							
	  											            }
		  										            break;		

							            case    7 : { bool avaible;

			  										            if(dioatcmdgsm->IsAvailableServiceGSM(avaible)==DIOATCMD_ERROR_NONE)	string.Format(_L(" Disp. Servicios GSM : %s"), avaible?_L("Si"):_L("No"));                           
				  								            }
					  							            break;

							            case    8 : if(dioatcmdgsm->GetIMSI(value)==DIOATCMD_ERROR_NONE)									  string.Format(_L(" IMSI : %s"), value.Get());   
						  						            break;													
																									

							            case    9 : { XBYTE support;
															
							  						            if(dioatcmdgsm->GetSMSSupport(support)==DIOATCMD_ERROR_NONE)				  string.Format(_L(" Soporte SMS : servicio %d, destino %s, origen %s, broadcast %s"), (support>>4), support&DIOATCMDGSM_SMSSUPPORT_MOVILETERMINATED ? _L("Si"):_L("No"), support&DIOATCMDGSM_SMSSUPPORT_MOVILEORIGINATED ? _L("Si"):_L("No"), support&DIOATCMDGSM_SMSSUPPORT_BROADCAST ? _L("Si"):_L("No"));																				
												              }
												              break;	
													
							            case   10 : { XBYTE format;
													              XBYTE support;
																																						
													              if(dioatcmdgsm->GetSMSFormat(format, false) ==DIOATCMD_ERROR_NONE) 
														              {
															              if(dioatcmdgsm->GetSMSFormat(support, true)==DIOATCMD_ERROR_NONE) 
																              {
																	              XSTRING strformat;
																	              XSTRING strsupport;

																	              strformat = _L("desconocido");
																	              if(format == DIOATCMDGSM_SMSFORMAT_PDU)  strformat = _L("PDU");
																	              if(format == DIOATCMDGSM_SMSFORMAT_TXT)  strformat = _L("Texto");

																	              if(support&DIOATCMDGSM_SMSFORMAT_PDU)		 strsupport = _L("PDU");
																	              if(support&DIOATCMDGSM_SMSFORMAT_TXT)     
																		              {
																			              if(!strsupport.IsEmpty()) strsupport += _L(" + ");
																			              strsupport += _L("Texto");
																		              }


																	              string.Format(_L(" Formato de SMS : %s (valido %s)"), strformat.Get(), strsupport.Get());																																							
																              }
														              }
												              }
												              break;	

							            case   11 : if(dioatcmdgsm->GetSMSCenter(value)==DIOATCMD_ERROR_NONE)						string.Format(_L(" Centro de mensajes : %s"), value.Get());        break;		
						            }
											
					            if(!string.IsEmpty()) 
                        { 
                          tests->console->Printf(string.Get());	
                          tests->console->Printf(_L("\n"));	
                        }
				            }												 
											
			            tests->console->Printf(_L(" Enviando mensaje : "));	

			            if(dioatcmdgsm->SendSMS(_L("64xxxxxx"), _L("0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ$%&/{}[]()\\*#@+-\"=;:.,_|")) == DIOATCMD_ERROR_NONE) 	 //  ¿?¡!																		
						             tests->console->Printf(_L("Ok.\n"));	
				            else tests->console->Printf(_L("Error!\n"));	
											 
																
			            dioatcmdgsm->End();

		            } else tests->console->Printf(_L(" Dispositivo de comandos AT NO accesible!\n"));	
									
	            GEN_DELETE dioatcmdgsm;
           }

          DIOFACTORY::GetInstance().DeleteStreamIO(diostream);
        }
			
      GEN_DELETE diostreamcfg;																					    
		}
								
	tests->console->Printf(_L("\n Terminada conexion AT.\n"), 1, true, true);	

	return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_SNMP(DEVTESTS_CONSOLE* tests)
* @brief      Runs the snmp test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_SNMP(DEVTESTS_CONSOLE* tests)
{  
  bool        status = false;

  #ifdef DIO_SNMP_ACTIVE

  XSTRING			string;		

	DIOSNMP* snmp = GEN_NEW DIOSNMP();
	if(snmp)  
    {	
	    status = snmp->Open(_L("47.61.135.23"), DIOSNMP_DEFAULT_PORT, false);
	    if(status)	
		    {	        		
          DIOSNMP_XBER xberout;

          snmp->SetVersion(DIOSNMP_VERSION_V2c);  
																	
			    status = snmp->Get(DIOSNMP_OPERATION_GETNEXTREQUEST, _L("public"), _L("1.3.6.1.2.1"), xberout); 
	
			    snmp->Close();
        }

      GEN_DELETE snmp;
		}     

  #endif   	
	
  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XFileJSON(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xfile json test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XFileJSON(DEVTESTS_CONSOLE* tests)
{
  XSTRING   envpath;      
  XPATH     pathJSON;
  XFILEJSON fileJSON;
  bool      status = true;

  GEN_XSYSTEM.GetEnviromentVariable(envpath);
  if(envpath.IsEmpty())
    {
      return false;
    }

  pathJSON.Set(envpath.Get());
  pathJSON.Slash_Add();
  pathJSON.Add(_L("Microsoft\\Edge\\User Data"));
  pathJSON.Slash_Add();
  pathJSON.Add(_L("Local State"));
     
  if(fileJSON.Open(pathJSON, false))
    {
      if(fileJSON.ReadAllFile())
        {
          if(fileJSON.DecodeAllLines())
            {
              XFILEJSONOBJECT* object = fileJSON.GetObj(_L("profile"));
              if(object) 
                { 
                  XVECTOR<XFILEJSONVALUE*>* values = object->GetValues();
                  if(values)
                    {
                      for(int c=0; c<values->GetSize(); c++)
                        {
                          XFILEJSONVALUE* value = values->Get(c);
                          if(value)
                            {
                              if(!value->GetName()->Compare(_L("info_cache"), true))
                                {        
                                  XVARIANT* variant = value->GetValue();
                          
                                  XSTRING profilename = ((XSTRING*)(variant->GetData()))->Get();

                                  break;                                            
                                } 
                            }                    
                        }
                    }
                }
            }
        }
    }

  /*  
  XFILEJSON         fileJSON;
  XFILEJSONOBJECT*  root;
  bool              status = false;

  root = fileJSON.GetRoot();
  if(!root)
    {
      root = GEN_NEW XFILEJSONOBJECT();
      if(!root) return false;

      fileJSON.SetRoot(root);
    }

  XFILEJSONOBJECT* first_obj = GEN_NEW XFILEJSONOBJECT();
  if(first_obj)
    {
       XFILEJSON_ADDVALUE(first_obj, _L("number1"), (int)10);
       XFILEJSON_ADDVALUE(first_obj, _L("string1"), (XCHAR*)_L("prueba"));
    }
  
  root->Add(_L("first_obj"), first_obj);

  XSTRING jsonString;
  fileJSON.EncodeAllLines(true);
  fileJSON.GetAllInOneLine(jsonString);   
  
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, jsonString.Get());

  XSTRING jsonstr;

  jsonstr.Add(_L("{\"webinv\":\"0\",\"sshinv\":\"0\",\"webinvPort\":\"30089\",\"sshinvPort\":\"40089\",\"servertime\":1706297258,\"action\":\"counters\",\"numPrinters\":1,\"printers\":[\"192.168.1.156\"]}"));

  fileJSON.DeleteAllLines();
  fileJSON.DeleteAllObjects();

  fileJSON.AddLine(jsonstr);
  status = fileJSON.DecodeAllLines();

  XFILEJSONVALUE* action_jsv       = fileJSON.GetValue(_L("action"));          
  XFILEJSONVALUE* wevinv_jsv       = fileJSON.GetValue(_L("webinv"));                              
  XFILEJSONVALUE* webinvport_jsv   = fileJSON.GetValue(_L("webinvPort"));
  XFILEJSONVALUE* sshinv_jsv       = fileJSON.GetValue(_L("sshinv"));
  XFILEJSONVALUE* sshinvport_jsv   = fileJSON.GetValue(_L("sshinvPort"));
  XFILEJSONVALUE* servertime_jsv   = fileJSON.GetValue(_L("servertime"));          

  XFILEJSONOBJECT* printerarray_jsv  = fileJSON.GetObj(_L("printers")); 
  XFILEJSONVALUE*  nprinters_jsv     = fileJSON.GetValue(_L("numPrinters"));   

  XDWORD nprinters = 0;

  if(nprinters_jsv) nprinters = nprinters_jsv->GetValueInteger();  

  if(printerarray_jsv)
    {
      if(nprinters < printerarray_jsv->GetValues()->GetSize())  nprinters = printerarray_jsv->GetValues()->GetSize();
    }
  */


  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XFileXML(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xfile xml test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XFileXML(DEVTESTS_CONSOLE* tests)
{
  XPATH       xpath;
  XFILEXML    xml;
  bool        status = false;

  GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpath);
  xpath.Slash_Add();
  xpath.Add(_L("example.xml"));

  if(xml.Open(xpath, true))
    {
      xml.ReadAndDecodeAllLines();

      XFILEXMLELEMENT* root           = xml.GetRoot();
      XFILEXMLELEMENT* nodewebservice = NULL;

      if(root)
        {
          for(int c=0; c<root->GetNElements(); c++)
            {
              nodewebservice = root->GetElement(c);
              if(nodewebservice)
                {
                
                }
            }
        }

      xml.Close();

      status = true;
    }

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XFileRIFF(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xfile riff test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XFileRIFF(DEVTESTS_CONSOLE* tests)
{
  XFILERIFF xfileRIFF;  
  XPATH     xpath;
  bool      status = false;

  GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpath);
  xpath.Slash_Add();
  xpath.Add(_L("example.avi"));

  if(xfileRIFF.Open(xpath.Get()))
    {
      status = xfileRIFF.ReadAllLists();

      xfileRIFF.Close();
    }

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOStreamUSBConnection(DEVTESTS_CONSOLE* tests)
* @brief      Runs the diostream usbconnection test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOStreamUSBConnection(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  DIOSTREAMUSBLOCALENUMDEVICES* enumdevices;
	DIOSTREAMDEVICEUSB*						device       = NULL;
  DIOSTREAMUSBCONFIG            diostreamcfg;
  DIOSTREAM*                    diostream    = NULL;
  XDWORD												PID          = 0xDF11;
	XDWORD												VID          = 0x0483;
  bool                          found        = false;    
  bool                          status       = false;


  tests->console->Printf(_L("\n\nBuscando dispositivo USB...\n"));

  while(!found)
    {
      enumdevices = (DIOSTREAMUSBLOCALENUMDEVICES*)GEN_DIOFACTORY.CreateStreamEnumDevices(DIOSTREAMENUMTYPE_USB_LOCAL);
	    if(!enumdevices) return false;	

	    enumdevices->Search();
      
      while(enumdevices->IsSearching())
       {
         GEN_XSLEEP.MilliSeconds(100);
       }
	
	    for(int c=0;c<(int)enumdevices->GetDevices()->GetSize();c++)
		    {				
			    device = (DIOSTREAMDEVICEUSB*)enumdevices->GetDevices()->Get(c);
			    if(device) 
				    {									    
					    if((device->GetProductID() == PID) && (device->GetVendorID() == VID))						    
                {																				
                  found = true;  
							    break;

						    } else device = NULL;
				    }
		    }

      if(tests->console->KBHit()) break;
    }

  if(!device) return false;
  if(!found)  return false;

  diostreamcfg.SetMode(DIOSTREAMMODE_CLIENT);	
  diostreamcfg.GetResource()->Set(device->GetResource()->Get());
  
  tests->console->Printf(_L("\nConnectando con USB device [%s]"), device->GetLocation()->Get());

  diostream = (DIOSTREAM*)GEN_DIOFACTORY.CreateStreamIO(&diostreamcfg);
  if(diostream)
    {
      if(diostream->Open())
        {
          status = diostream->WaitToConnected(1);

          tests->console->Printf(_L("\r\nConexion USB estado: %s"), status?_L("Connected!"):_L("Error!"));

          while(diostream->GetStatus()==DIOSTREAMSTATUS_CONNECTED)
            {
              /*                                                  
              tests->console->Printf    (_L("\r\n    Sending packet(%d)"), c++);

              diostream->WriteStr (_L("Hello Jello!\r\n"));
              diostream->WaitToFlushOutXBuffer();
              */
            }
      
          diostream->Close();

          status = true;
        }

      DIOFACTORY::GetInstance().DeleteStreamIO(diostream);
    }

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XFileDFU(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xfile dfu test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XFileDFU(DEVTESTS_CONSOLE* tests)
{
  XFILEDFU  xfileDFU;  
  XPATH     xpath;

  GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_FIRMWARE, xpath);
  xpath.Slash_Add();
  xpath.Add(_L("firmware.dfu"));

  if(xfileDFU.Open(xpath.Get()))
    {
      if(xfileDFU.ReadAll())
        {


        }

      xfileDFU.Close();
    }
  
  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_SystemHostFile(DEVTESTS_CONSOLE* tests)
* @brief      Runs the system host file test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_SystemHostFile(DEVTESTS_CONSOLE* tests)
{
  GEN_XSYSTEM.HostFile(true, _L("youtube.es"), _L("127.0.0.1"));

  GEN_XSYSTEM.HostFile(false, _L("youtube.es"), _L(""));

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_SystemBatteryLevel(DEVTESTS_CONSOLE* tests)
* @brief      Runs the system battery level test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_SystemBatteryLevel(DEVTESTS_CONSOLE* tests)
{
  bool    isincharge   = false;
  XBYTE   batterylevel = 0;
  bool    status;

  status = GEN_XSYSTEM.GetBatteryLevel(isincharge, batterylevel);  
  if(status)
    {
      XSTRING string;
      string.ConvertFromBoolean(isincharge, XSTRINGBOOLEANMODE_HUMAN);
      
      tests->console->Printf(_L("\n Is in charge : %s.\n"), string.Get());	
      tests->console->Printf(_L(" Battery level : %d%%.\n"), batterylevel);	
    }

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_LedNeoPixelWS2812B(DEVTESTS_CONSOLE* tests)
* @brief      Runs the led neo pixel ws2812 b test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_LedNeoPixelWS2812B(DEVTESTS_CONSOLE* tests)
{ 
  DIOLEDNEOPIXELWS2812B* ledneopixelws2812b = GEN_DIOFACTORY.CreateLedNeopixelWS2812B(); 
  if(!ledneopixelws2812b)  return false;

  ledneopixelws2812b->SetDataGPIOEntryID(DEVTESTS_CONSOLE_GPIOENTRYID_LED_NEOPIXEL);                                             
     
  if(ledneopixelws2812b->Ini(7))
    {       
      XBYTE data1[] = { 0xFF, 0x00, 0x00,    
                        0xFF, 0x00, 0x00,  
                        0xFF, 0x00, 0x00,   
                        0xFF, 0x00, 0x00,                            
                                                    
                        0xFF, 0x00, 0x00,  
                        0xFF, 0x00, 0x00,
                        0xFF, 0x00, 0x00,
                        0xFF, 0x00, 0x00,                                                                                  
                      };

      XBYTE data2[] = { 0x00, 0xFF, 0x00,    
                        0x00, 0xFF, 0x00,  
                        0x00, 0xFF, 0x00,   
                        0x00, 0xFF, 0x00,                            
                                                    
                        0x00, 0xFF, 0x00,  
                        0x00, 0xFF, 0x00,
                        0x00, 0xFF, 0x00,
                        0x00, 0xFF, 0x00,                                                                                  
                      };     

      XBYTE data3[] = { 0x00, 0x00, 0xFF,     
                        0x00, 0x00, 0xFF,   
                        0x00, 0x00, 0xFF,    
                        0x00, 0x00, 0xFF,                             
                                                     
                        0x00, 0x00, 0xFF,   
                        0x00, 0x00, 0xFF, 
                        0x00, 0x00, 0xFF, 
                        0x00, 0x00, 0xFF,                                                                                   
                      };

      XBYTE data4[] = { 0xFF, 0xFF, 0xFF,     
                        0xFF, 0xFF, 0xFF,   
                        0xFF, 0xFF, 0xFF,    
                        0xFF, 0xFF, 0xFF,                             
                                              
                        0xFF, 0xFF, 0xFF,   
                        0xFF, 0xFF, 0xFF, 
                        0xFF, 0xFF, 0xFF, 
                        0xFF, 0xFF, 0xFF,                                                                                   
                      };

      XBYTE data5[] = { 0x00, 0x00, 0x00,     
                        0xFF, 0x00, 0x00,   
                        0x00, 0xFF, 0x00,    
                        0x00, 0x00, 0xFF,                             
                                                           
                        0xFA, 0xF2, 0x04,   
                        0x3E, 0xF9, 0xF9,                           
                        0xFD, 0xB2, 0x03, 
                        0xFF, 0xFF, 0xFF,                                                                                   
                      };

      
      for(int c=0; c<3; c++)
        {
          ledneopixelws2812b->SendData(data1, sizeof(data1));
          GEN_XSLEEP.Seconds(1);                  

          ledneopixelws2812b->SendData(data2, sizeof(data2));
          GEN_XSLEEP.Seconds(1);  

          ledneopixelws2812b->SendData(data3, sizeof(data3));
          GEN_XSLEEP.Seconds(1);  
        }

      for(int d=0; d<3; d++)
        {            
          for(int c=0; c<255; c++)
            {
              ledneopixelws2812b->SetBrightnessLevel(c);          
              ledneopixelws2812b->SendData(data4, sizeof(data4));

              GEN_XSLEEP.MilliSeconds(1);                  
            }
      
          for(int c=255; c>=0; c--)
            {
              ledneopixelws2812b->SetBrightnessLevel(c);          
              ledneopixelws2812b->SendData(data4, sizeof(data4));

              GEN_XSLEEP.MilliSeconds(1);                  
            }
        } 


      ledneopixelws2812b->SetBrightnessLevel(128);          
      ledneopixelws2812b->SendData(data5, sizeof(data5));

      GEN_XSLEEP.Seconds(4);
      
      ledneopixelws2812b->End();
    }
  
  GEN_DIOFACTORY.DeleteLedNeopixelWS2812B(ledneopixelws2812b);
  
  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOPCap(DEVTESTS_CONSOLE* tests)
* @brief      Runs the diopcap test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOPCap(DEVTESTS_CONSOLE* tests)
{
	#ifdef DIO_PCAP_ACTIVE

	DIOPCAP*						 diopcap					 = NULL; 
	DIOPCAPNETINTERFACE* netinterface			 = NULL;  
	int                  indexnetinterface = 8;

	diopcap = GEN_DIOFACTORY.CreatePCap();
  if(!diopcap)  return false;

	if(diopcap->Ini())
    { 
			tests->console->Printf(_L("Interfaces de red disponibles: \n\n"));
      for(int c=0; c<(int)diopcap->GetNetInterfaces()->GetSize(); c++)
        {
          netinterface = diopcap->GetNetInterface(c);
          if(netinterface) 
            {          
              if(indexnetinterface == -1)
                {
                  if(netinterface->IsLoopBack())
                    {
                      indexnetinterface = c;                        
                    }
                }
                
               tests->console->Printf(_L("[%2d] %c %s, [%s]\n"), c, (indexnetinterface == c)?_C('*'):_C('-'), netinterface->GetName()->Get(), netinterface->GetDescription()->Get());						
            }
				}

			tests->console->Printf(_L("\n"));

			if(indexnetinterface != -1) 
				{
					if(diopcap->Capture_Start(indexnetinterface, true, 100)) 
						{
							while(!tests->console->KBHit())
								{
									int nsize = diopcap->Frames_Get()->GetSize();

									for(int c=0;c<nsize;c++) 
										{
											DIOPCAPFRAME* frame = diopcap->Frames_Get(c);
											if(!frame) break;

											if(tests->console->KBHit()) break;
									          
                      XSTRING string;  

                      if(!frame->GetSourceMAC()->IsZero())
                        {
                          frame->GetSourceMAC()->GetXString(string);

                          tests->console->Printf(_L("MACs [%s"), string.Get());
                        } 

                      if(!frame->GetTargetMAC()->IsZero())
                        {
                          frame->GetTargetMAC()->GetXString(string);

                          tests->console->Printf(_L(" > %s]"), string.Get());
                        }  

                      if(!frame->GetSourceIP()->IsEmpty())
                        {
                          XSTRING protocoltypestr;  

                          frame->GetProtocolTypeString(protocoltypestr);
                          frame->GetSourceIP()->GetXString(string);

                          tests->console->Printf(_L(" %-6s IPs [%15s"), protocoltypestr.Get(), string.Get());
                        }

                      if(!frame->GetTargetIP()->IsEmpty())
                        {
                          frame->GetTargetIP()->GetXString(string);

                          tests->console->Printf(_L(" > %15s]"), string.Get());
                        }

                      if(frame->GetSourcePort())
                        {                          
                          tests->console->Printf(_L(" Ports [%5d"), frame->GetSourcePort());
                        }

                      if(frame->GetTargetPort())
                        {                          
                          tests->console->Printf(_L(" > %5d]"), frame->GetTargetPort());
                        }

                      tests->console->Printf(_L(" header size: %d, playload size: %d"), frame->GetAllHeadersSize(), frame->GetDataPayLoadSize());
                      
                      tests->console->Printf(_L("\n"));                   
									
											diopcap->Frames_Delete(c);
										}
								
								}
							
							diopcap->Capture_End();
						}
			
				}	 
			
			diopcap->End();														
		}

	GEN_DIOFACTORY.DeletePCap(diopcap);

	#endif
  
	return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XLicense(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xlicense test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XLicense(DEVTESTS_CONSOLE* tests)
{
	XLICENSE* 	xlicense  = NULL;
	XLICENSEID  xlicenseID;	
	XBUFFER			licensefile;
	XBUFFER			license;
	XSTRING			string;
  bool        status = false;


  xlicense = GEN_NEW XLICENSE();
  if(!xlicense)		
    {
      return false;
    }

	if(xlicense->GenerateMachineID(xlicenseID))
		{
			xlicenseID.GetID()->GetToString(string);
			tests->console->Printf(_L(" ID licencia : %s \n"), string.Get()); 
			
			xlicense->Application_GetID()->Set(_L("GEN Copyright (C). All right reserved."));		
			xlicense->Generate(xlicenseID);
			xlicense->Get(string);
			tests->console->Printf(_L(" Licencia : %s \n"), string.Get()); 	

			XPATH		  xpathgeneric;
			XPATH		  xpath;
			DIOURL	  url;
      XSTRING   applicationID;
      XSTRING   expireddate;

      applicationID = _L("TEST Application");

      GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpath);
      xpath.Slash_Add();
      xpath.Add("test.lic");
      			
      CREATEMASTERLICENSE(xlicense, xpath, xlicenseID, applicationID, 10)

      CHECKLICENSEFULLLOCAL(xlicense, xpath, applicationID, status)   
			
      CHECKLICENSEFULLLOCALEXPIRE(xlicense, xpath, applicationID, status)   
		}

	return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XSerializable(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xserializable test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XSerializable(DEVTESTS_CONSOLE* tests)
{
  if(!tests->console) return false;

  XRAND*                xrand;
  XSERIALIZATIONMETHOD* serializationmethod;
  XBUFFER               buffer; 
  XFILEJSON             xfileJSON;      
  XSTRING               alllines;
  TESTSERIALIZABLE      testserializable;
  TESTSERIALIZABLE      testserializable2;

//serializationmethod = XSERIALIZABLE::CreateInstance(buffer);

  xrand = GEN_XFACTORY.CreateRand();
  if(!xrand)
    {
      return false;
    }

  serializationmethod = XSERIALIZABLE::CreateInstance(xfileJSON);


  testserializable.SetValue1(xrand->Max(10000));
  testserializable.GetString1()->Set(_L("hola radiola main"));

  testserializable.GetClassSer()->SetValue2(xrand->Max(10000));
  testserializable.GetClassSer()->GetString2()->Format(_L("Hola radiola class [%04X]"), xrand->Max(16384));

  for(int c=0; c<testserializable.GetVectorSer()->GetSize(); c++)
    {
      TESTSERIALIZABLE2* test = testserializable.GetVectorSer()->Get(c);
      if(test)
        {
          test->SetValue2(xrand->Max(10000)); 
          test->GetString2()->Format(_L("hola radiola vector %d [%04X]"), c+1, xrand->Max(16384));      
        }
    }


  testserializable.DoSerialize(serializationmethod);
  xfileJSON.EncodeAllLines(true);  
  xfileJSON.ShowTraceJSON(XTRACE_COLOR_BLUE);

  testserializable2.DoDeserialize(serializationmethod);
  xfileJSON.EncodeAllLines(true);  
  xfileJSON.ShowTraceJSON(XTRACE_COLOR_GREEN);

  GEN_DELETE serializationmethod;

  GEN_XFACTORY.DeleteRand(xrand);

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_InputSimulate(DEVTESTS_CONSOLE* tests)
* @brief      Runs the input simulate test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_InputSimulate(DEVTESTS_CONSOLE* tests)
{
  #ifdef INP_ACTIVE

  INPSIMULATE* inpsimulated = GEN_INPFACTORY.CreateSimulator();
  if(!inpsimulated)
    {
      return false;
    }

  inpsimulated->Key_Click(0x41);

  #endif

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_Scheduler(DEVTESTS_CONSOLE* tests)
* @brief      Runs the scheduler test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_Scheduler(DEVTESTS_CONSOLE* tests)
{
  XSCHEDULER*     xscheduler;
  XSCHEDULERTASK* xtask;
  XDATETIME       xdatetimecadence;
  XTIMER          xtimercadence;
  bool            status   = false;

  xscheduler = GEN_NEW XSCHEDULER();
  if(!xscheduler) 
    {
      return false;
    }

  xtask = GEN_NEW XSCHEDULERTASK(xscheduler);
  if(xtask) 
    {     
      xdatetimecadence.SetToZero();

      xtimercadence.Reset();
      xtimercadence.AddSeconds(5);

      xtimercadence.GetMeasureToDate(&xdatetimecadence);  

      xtask->SetNCycles(XSCHEDULER_CYCLEFOREVER, &xdatetimecadence);
      xtask->SetID(DEVTESTS_CONSOLE_TASKID_TEST);
      xtask->SetIsStartImmediatelyCycles(true);
      xtask->SetIsActive(true);

      status = xscheduler->Task_Add(xtask);      

      tests->SubscribeEvent(XEVENT_TYPE_SCHEDULER, xscheduler);

      if(xscheduler->Ini()) 
        {
           status = true;
        }
    }

  if(status)
    {
      GEN_XSLEEP.Seconds(2);

      xtask->StartConditionImmediately();

      GEN_XSLEEP.Seconds(18);
    }

  tests->UnSubscribeEvent(XEVENT_TYPE_SCHEDULER, xscheduler);
  GEN_DELETE xscheduler;
   
  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DynDNS(DEVTESTS_CONSOLE* tests)
* @brief      Runs the dyn dns test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DynDNS(DEVTESTS_CONSOLE* tests)
{	
  DIODYNDNS_MANAGER*  dyndnsmanager;
  bool							  status = false;	

  dyndnsmanager = GEN_NEW DIODYNDNS_MANAGER();
  if(!dyndnsmanager)
    {
      return false; 
    }

  #ifdef APPFLOW_CFG_DYNDNSMANAGER_ACTIVE
  for(XDWORD c=0; c<APPFLOW_CFG.DNSManager_GetURLs()->GetSize(); c++)
    {
      dyndnsmanager->AddDNS((*APPFLOW_CFG.DNSManager_GetURL(c)));
    }         
  #endif  

  dyndnsmanager->GetLogin()->Set(_L(""));
  dyndnsmanager->GetPassword()->Set(_L(""));
	
  status = dyndnsmanager->AssingAll();

  GEN_DELETE dyndnsmanager;
  
	return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_ID_IBAN(DEVTESTS_CONSOLE* tests)
* @brief      Runs the XID IBAN test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_ID_IBAN(DEVTESTS_CONSOLE* tests)
{
  XID_IBAN IBAN;
  bool     status = false;	

  if(!tests->console) 
    {
      return false;
    }

  
  status = IBAN.Set(_L("GB82 WEST 1234 5698 7654 32"));
  if(status)
    {

    }
  
  status = IBAN.Set(_L("ES90 0024 6912 50 1234567891"));
  if(status)
    {

    }

  // 
  
  for(int c=0; c<10000; c++)
    {
      XSTRING IBANstr;
      
      // ES1000492352082414205416
      IBANstr.AddFormat(_L("ES10 0049 2352 08 241420 %04d"), c);

      status = IBAN.Set(IBANstr.Get());

      if(status)
        {
          int a=0;
          a++;
        }

      tests->console->Printf(_L("IBAN : %s %20s %c"), IBAN.Get()->Get(), status?_L("Ok!"):_L("Error!"), status?_C('\n'):_C('\r')); 
      if(status)
        {  
          XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("IBAN : %s"), IBAN.Get()->Get()); 
        }
    }

  tests->console->Printf(_L(" \n")); 

  return status;
} 


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_Compress(DEVTESTS_CONSOLE* tests)
* @brief      Runs the compress test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_Compress(DEVTESTS_CONSOLE* tests)
{
  #define NAMEFILECMPINZIP _L("testcmp.txt")

  COMPRESSMANAGER*	manager     = NULL;
  COMPRESSBASE*			compressor  = NULL;    	
  XPATH             xpathcmpfile;
  XPATH             xpathcmpinzip;
  XPATH             xpathzipfile;  
	bool              status      = false;

 	manager = GEN_NEW COMPRESSMANAGER();
  if(manager)
    {
	    compressor = manager->Create(COMPRESSBASE_TYPE_ZIP);
      if(!compressor)
        {
          GEN_DELETE manager;
          return status;
        }    
    }

	XFILE* xfiletxt = XFACTORY::GetInstance().Create_File();
	if(!xfiletxt)
    { 
      delete(compressor);
	    delete(manager);

	    return status;
    }

  tests->console->Printf(_L("\nAdd file in Zip file: "));	

	XPATHSMANAGER::GetInstance().GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpathcmpfile);
	xpathcmpfile.Add(NAMEFILECMPINZIP);
	
	xpathcmpinzip.Add(NAMEFILECMPINZIP);

	XPATHSMANAGER::GetInstance().GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpathzipfile);
	xpathzipfile.Slash_Add();
	xpathzipfile.Add(_L("test.zip"));

								
	XFILEZIP* zipfile = GEN_NEW XFILEZIP();		
	if(zipfile) 
    {
	    status = zipfile->Open(xpathzipfile);
	    if(status)
		    {
			    zipfile->AddFile(xpathcmpfile, xpathcmpinzip);
			    zipfile->Close();
		    }
    }
	
	delete(zipfile);    	

  tests->console->Printf(_L("%s\n"), status?_L("Ok."): _L("Error!"));					 							

  tests->console->Printf(_L("Compress and decompress buffer: "));	

  XSTRING sentence;
  XBUFFER buffer;
  XBUFFER cmpbuffer;
  XBUFFER decmpbuffer;

  sentence = _L("I've seen things you people wouldn't believe." "Attack ships on fire off (the) shoulder of Orion." "I watched C-beams glitter in the dark near the Tannhäuser Gate." "All those moments will be lost in time, like tears in rain." "Time to die.");

  sentence.ConvertToUTF8(buffer, false);

  decmpbuffer.Resize(buffer.GetSize());
  
  status = compressor->Compress(buffer.Get(), buffer.GetSize(), &cmpbuffer);
  if(status)
    {
      XSTRING finalsentence;
      status = compressor->Decompress(cmpbuffer.Get(), cmpbuffer.GetSize(), &decmpbuffer);

      finalsentence.ConvertFromUTF8(decmpbuffer);

      status = !finalsentence.Compare(sentence, false)?true:false;
    }

  tests->console->Printf(_L("%s\n"), status?_L("Ok."): _L("Error!"));				

	delete(compressor);
	delete(manager);

	return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DIOStreamTCPIPServer(DEVTESTS_CONSOLE* tests)
* @brief      Runs the diostream tcpipserver test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DIOStreamTCPIPServer(DEVTESTS_CONSOLE* tests)
{  
  if(!tests->console) 
    {
      return false;
    }

  DIOSTREAMTCPIPCONFIG  diostreamcfg;
  DIOSTREAMTCPIPSERVER* diostream    = NULL;
  XSTRING               line;
  bool                  status       = false;

  diostreamcfg.GetRemoteURL()->Set(_L("127.0.0.1"));
  diostreamcfg.SetMode(DIOSTREAMMODE_SERVERMULTISOCKET);
  diostreamcfg.SetRemotePort(1200);

  line.Format(_L("Server [%s]: %d"), diostreamcfg.GetRemoteURL()->Get(), diostreamcfg.GetRemotePort());
  tests->console->Printf(_L(" %s\n"), line.Get());
  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, line.Get());

  diostream =  (DIOSTREAMTCPIPSERVER*)GEN_DIOFACTORY.CreateStreamIO(&diostreamcfg);
  if(!diostream) 
    {
      return false;
    }

  tests->SubscribeEvent(DIOSTREAM_XEVENT_TYPE_CONNECTED, diostream);
  tests->SubscribeEvent(DIOSTREAM_XEVENT_TYPE_DISCONNECTED , diostream);
  
  if(diostream->Open())
    {
      while(!tests->console->KBHit())
        {
          line.Format(_L("N Connections: %d [ %d / %d ] "), diostream->GetNumConnectedMultiSocketStreams(), diostream->GetNBytesRead(), diostream->GetNBytesWrite());  

          tests->console->Printf(_L(" %s\r"), line.Get());

          GEN_XSLEEP.MilliSeconds(50);
        }

      status = diostream->Close();

      line.Format(_L("Close connection: %s"), status?_L("Ok."):_L("Error!"));  
      tests->console->Printf(_L(" %s\n\n"), line.Get());
      XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), line.Get());                                 
    }

  tests->UnSubscribeEvent(DIOSTREAM_XEVENT_TYPE_CONNECTED, diostream);
  tests->UnSubscribeEvent(DIOSTREAM_XEVENT_TYPE_DISCONNECTED , diostream);

  GEN_DIOFACTORY.DeleteStreamIO(diostream);
  
  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_XPath(DEVTESTS_CONSOLE* tests)
* @brief      Runs the xpath test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_XPath(DEVTESTS_CONSOLE* tests)
{
  XPATH             xpath;
  XSTRING           drive;
  XVECTOR<XSTRING*> subpaths;
  XSTRING           name;
  XSTRING           ext;
  bool              status = false;

  xpath = _L("SOFTWARE\\Policies\\Microsoft\\Edge");

  status = xpath.Split(&drive, subpaths, NULL, NULL);

  return status;
}


#ifdef WINDOWS


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_WindowsACL(DEVTESTS_CONSOLE* tests)
* @brief      Runs the windows acl test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_WindowsACL(DEVTESTS_CONSOLE* tests)
{
  XWINDOWSACCESSCONTROLLISTS  ACList;
  XPATH                       xpathsection;
  XPATH                       namefile;
  bool                        status = false;

  GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpathsection);
  namefile.Create(3 , xpathsection.Get(), _L("scraperweb"), _L(".xml"));

  status = ACList.SetFileOnlyPermissionForSystemUser(namefile.Get());

  GEN_XSLEEP.Seconds(2);

  status = ACList.SetFilePermissionForEveryone(namefile.Get());

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_WindowsRegistry(DEVTESTS_CONSOLE* tests)
* @brief      Runs the windows registry test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_WindowsRegistry(DEVTESTS_CONSOLE* tests)
{
  XWINDOWSREGISTRYMANAGER registrymanager;
  XWINDOWSREGISTRYKEY     registrykey;
  bool                    status = false;

  // Property_Add(CTRLAGENT_PROPERTYRESTRICTOR_HKEY_LOCAL_MACHINE, _L("SOFTWARE\\Policies\\Microsoft\\Edge"), _L("HubsSidebarEnabled"), _L("Edge Hubs Sidebar"), 1);  

  status = registrymanager.CreateKey(HKEY_LOCAL_MACHINE, _L("SOFTWARE\\Policies\\Microsoft\\Edge\\prueba\\prueba2"), registrykey);
  if(status)
    {
     
      registrymanager.CloseKey(registrykey);
    }

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_WindowsWinget(DEVTESTS_CONSOLE* tests)
* @brief      Runs the windows winget test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_WindowsWinget(DEVTESTS_CONSOLE* tests)
{  
  XSTRING         jsonresult;
  bool            status = false;

  // status = GEN_WINGET.List(false, jsonresult);

  // status = GEN_WINGET.Find(_L("Xbox"), jsonresult);


  status = GEN_WINGET.ApplicationOperation(XWINDOWSWINGET_APPLICATIONOPERATION_UPDATEVERSION, _L("Microsoft.DotNet.DesktopRuntime.8"), true);


  return status;
}


#endif


#ifdef LINUX


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DBUS(DEVTESTS_CONSOLE* tests)
* @brief      Runs the dbus test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DBUS(DEVTESTS_CONSOLE* tests)
{
  bool                  status = false;

  #ifdef LINUX_DIO_DBUS_ACTIVE

  DIOLINUXDBUS_MESSAGE  message;  
  DIOLINUXDBUS_MESSAGE  reply;  
  

  DIOLINUXDBUS* dbus = GEN_NEW DIOLINUXDBUS();
  if(dbus)
    {
      if(dbus->Ini())
        {        
          //---------------------------------------------------------------------------------

          /*    
          message.GetDestination()->Set(_L("org.freedesktop.NetworkManager"));
          message.GetPath()->Set(_L("/org/freedesktop/NetworkManager"));
          message.GetIFace()->Set(_L("org.freedesktop.NetworkManager.Devices"));
          message.GetMethod()->Set(_L("GetAll"));
          status = message.Create();
          if(status)
            {              
              message.SetArgument(true);

              message.SetArgument(DIOLINUXDBUS_IFACE_PROPERTIES);
              message.SetArgument(DIOLINUXDBUS_IFACE_PROPERTIES);

              status = dbus->CallMethod(message, reply);                       
              if(status)
                {

                  reply.Delete();
                }   

               message.Delete();
            }
           else 
            {
              XTRACE_PRINTCOLOR(XTRACE_COLOR_RED, _L("[DBUS] Error create message ..."));
            }

          */

          //---------------------------------------------------------------------------------
          
          message.GetDestination()->Set(_L("org.freedesktop.NetworkManager"));
          message.GetPath()->Set(_L("/org/freedesktop/NetworkManager"));
          message.GetIFace()->Set(_L("org.freedesktop.NetworkManager"));
          message.GetMethod()->Set(_L("GetDevices"));

          status = message.Create();
          if(status)
            {              
              status = dbus->CallMethod(message, reply);                       
              if(status)
                { 
                  XVECTOR<XSTRING*> result;            

                  status = reply.GetResult(result);
                  if(status)
                    {
                      XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("[DBUS] Result:"));
                      for(int c=0; c<result.GetSize(); c++)
                        {
                          XTRACE_PRINTCOLOR((status?XTRACE_COLOR_BLUE:XTRACE_COLOR_RED), _L("%s"), result.Get(c)->Get());
                        }

                      result.DeleteContents();
                      result.DeleteAll();
                    }
                   else
                    {
                      XTRACE_PRINTCOLOR(XTRACE_COLOR_RED, _L("[DBUS] Error get result ..."));    
                    } 
                  
                  reply.Delete();
                }   

               message.Delete();
            }  
           else 
            {
              XTRACE_PRINTCOLOR(XTRACE_COLOR_RED, _L("[DBUS] Error create message ..."));
            }
          

          //---------------------------------------------------------------------------------


          status = dbus->End();      
        }
 
      GEN_DELETE dbus;
    }

  #endif 

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_NetWorkManager(DEVTESTS_CONSOLE* tests)
* @brief      Runs the net work manager test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_NetWorkManager(DEVTESTS_CONSOLE* tests)
{
  #ifdef LINUX_DIO_NETWORKMANAGER_ACTIVE

  DIOLINUXNETWORKMANAGER networkmanager;
  
  if(networkmanager.Ini()) 
    {

      XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Network Manager ] Activate ..."));    
      networkmanager.Enable(true);

      //networkmanager.Signal_Add(DIOLINUXNETWORKMANAGER_DEFAULT_DBUS_IFACE_MAIN  , _L("DeviceAdded"));
      //networkmanager.Signal_Add(DIOLINUXNETWORKMANAGER_DEFAULT_DBUS_IFACE_MAIN  , _L("DeviceRemoved"));
      networkmanager.Signal_Add(DIOLINUXNETWORKMANAGER_DEFAULT_DBUS_IFACE_MAIN, _L("PropertiesChanged"));

      //networkmanager.Signal_Add(DIOLINUXNETWORKMANAGER_DEFAULT_DBUS_IFACE_DEVICE, _L("PropertiesChanged"));
  

      switch(networkmanager.GetConnectionState())
        {
          case DIOLINUXNETWORKMANAGER_STATE_UNKNOWN            :   XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Network Manager] Get Connection state: networking state is unknown"));                            break;
          case DIOLINUXNETWORKMANAGER_STATE_ASLEEP             :   XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Network Manager] Get Connection state: networking is not enabled"));                              break; 
          case DIOLINUXNETWORKMANAGER_STATE_DISCONNECTED       :   XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Network Manager] Get Connection state: there is no active network connection"));                  break;
          case DIOLINUXNETWORKMANAGER_STATE_DISCONNECTING      :   XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Network Manager] Get Connection state: network connections are being cleaned up"));               break;
          case DIOLINUXNETWORKMANAGER_STATE_CONNECTING         :   XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Network Manager] Get Connection state: a network connection is being started"));                  break;
          case DIOLINUXNETWORKMANAGER_STATE_CONNECTED_LOCAL    :   XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Network Manager] Get Connection state: there is only local IPv4 and/or IPv6 connectivity"));      break;
          case DIOLINUXNETWORKMANAGER_STATE_CONNECTED_SITE     :   XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Network Manager] Get Connection state: there is only site-wide IPv4 and/or IPv6 connectivity"));  break;
          case DIOLINUXNETWORKMANAGER_STATE_CONNECTED_GLOBAL   :   XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Network Manager] Get Connection state: there is global IPv4 and/or IPv6 Internet connectivity")); break;
        }

      XVECTOR<DIOSTREAMDEVICEIP*> devices;

      networkmanager.GetDevices(devices);

      for(XDWORD c=0; c<devices.GetSize(); c++)
        {
          DIOSTREAMDEVICEIP* deviceIP = devices.Get(c);
          if(deviceIP) deviceIP->DebugPrintInfo();
        }

      devices.DeleteContents();
      devices.DeleteAll();
       
      while(!tests->console->KBHit())
				{				
          GEN_XSLEEP.MilliSeconds(100);              
        }

      networkmanager.End();
    }

  #endif

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_DeviceBusInputFile(DEVTESTS_CONSOLE* tests)
* @brief      Runs the device bus input file test.
* @ingroup    TESTS
*
* @param[in]  tests : test application instance used by the test.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_DeviceBusInputFile(DEVTESTS_CONSOLE* tests)
{
  INPDEVICE_TYPE             typedevice = INPDEVICE_TYPE_TOUCHSCREEN; 
  XVECTOR<INPLINUXDEVICEID*> devices;
  bool                       status     = false;
   
  /* 
  XFILETXT* xfiletxtdevices =  GEN_NEW XFILETXT();
  if(xfiletxtdevices)
    {
      XPATH xpathdevices;
      
      #ifdef LINUX
      xpathdevices = INPLINUXDEVICEID_HANDLEFILE;
      #else
      GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpathdevices);
      xpathdevices.Slash_Add();
      xpathdevices.Add(_L("devices"));      
      #endif
      
      if(xfiletxtdevices->Open(xpathdevices))
        {
          xfiletxtdevices->ReadAllFile();

          for(int c=0; c<xfiletxtdevices->GetNLines(); c++)
            {
              XSTRING* line = xfiletxtdevices->GetLine(c);
              if(line)
                {
                  int index = line.Find(_L("I:"), true);
                  if(index == 0)
                    {
                      INPLINUXDEVICEID* deviceID = GEN_NEW INPLINUXDEVICEID();
                      if(deviceID)
                        {
                          do{ line = xfiletxtdevices->GetLine(c);
                              if(!line) break;
                              if(line.GetSize() < 2) break;  

                              char typeline = (char)line.Get()[0];  
                              switch(typeline)
                                {    
                                  case  'I' : break;                                    

                                  case  'N' : { XSTRING name;

                                                name.AdjustSize(_MAXSTR);
                                                line.UnFormat(_L("N: Name=\"%s\""), name.Get());
                                                name.AdjustSize();      

                                                deviceID->GetName()->Set(name);
                                              }
                                              break;                                    

                                  case  'P' : break;                                    
                                  case  'S' : break;                                    
                                  case  'U' : break;                                    

                                  case  'H' : { XSTRING handlers;
                                                int     event_index = INPLINUXDEVICEID_INVALID;

                                                handlers.AdjustSize(_MAXSTR);
                                                line.UnFormat(_L("H: Handlers=%s"), handlers.Get());
                                                handlers.AdjustSize();      

                                                index = handlers.Find(_L("event"), true);
                                                if(index != XSTRING_NOTFOUND)
                                                  {
                                                    XSTRING eventstr;

                                                    handlers.Copy(index, eventstr);
                                                    eventstr.UnFormat(_L("event%d"), &event_index);

                                                    deviceID->SetEventIndex(event_index);
                                                  }                                                
                                              }
                                              break;        
                           
                                  case  'B' : { XCHAR* prefix[] = { _L("PROP=")  , 
                                                                    _L("EV=")    ,
                                                                    _L("KEY=")   ,
                                                                    _L("ABS=")   ,
                                                                    _L("REL=")   ,
                                                                    _L("MSC=")   
                                                                  };

                                                for(int d=0; d< (sizeof(prefix) / sizeof(XCHAR*)); d++)   
                                                  {
                                                    index = line.Find(prefix[d], true);
                                                    if(index != XSTRING_NOTFOUND)
                                                      {
                                                        switch(d)
                                                          {
                                                            case 0  : break;

                                                            case 1  : { XSTRING ev_str;

                                                                        ev_str.AdjustSize(_MAXSTR);
                                                                        line.Copy(index+3, ev_str);
                                                                        ev_str.AdjustSize();

                                                                        if(!ev_str.Compare(_L("120013"), true)) deviceID->SetType(INPDEVICE_TYPE_KEYBOARD);  
                                                                        if(!ev_str.Compare(_L("17"), true))     deviceID->SetType(INPDEVICE_TYPE_MOUSE);                                                                                                                        
                                                                        if(!ev_str.Compare(_L("b"), true))      deviceID->SetType(INPDEVICE_TYPE_TOUCHSCREEN);                                                                                                                        
                                                                      }
                                                                      break;

                                                            case 2  : break;
                                                            case 3  : break;
                                                            case 4  : break;
                                                            case 5  : break;
                                                          }
                                                      }
                                                  }  
                                              }
                                              break;                                                                      
                                }

                              c++;


                            } while(1);
 
                                
                          if((deviceID->GetEventIndex() != INPLINUXDEVICEID_INVALID) && 
                             (typedevice == deviceID->GetType()))
                            {            

                              devices.Add(deviceID);
               
                              #ifdef XTRACE_ACTIVE
                              XSTRING typestr;
   
                              switch(deviceID->GetType())
                                { 
                                                      default       :   
                                  case INPDEVICE_TYPE_NONE          : typestr = _L("Unkwown");       break;
                                  case INPDEVICE_TYPE_KEYBOARD      : typestr = _L("Keyboard");      break;
                                  case INPDEVICE_TYPE_MOUSE         : typestr = _L("Mouse");         break;
                                  case INPDEVICE_TYPE_JOSTICK       : typestr = _L("Jostick");       break;
                                  case INPDEVICE_TYPE_TOUCHSCREEN   : typestr = _L("TouchScreen");   break;
                                  case INPDEVICE_TYPE_WIIMOTE       : typestr = _L("WII Mote");      break;
                                }

                              XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Input Device] Event [%d] Type: %15s Device [%s]"), deviceID->GetEventIndex(), typestr.Get(), deviceID->GetName()->Get());                         
                              #endif                                               
                            } 
                           else GEN_DELETE deviceID;                                 
                        }   
                    }
                }
            }

          xfiletxtdevices->Close();
        }

      GEN_DELETE xfiletxtdevices;
    }

  */

  devices.DeleteContents();
  devices.DeleteAll();

  return status;
}

#endif


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_Hash(HASH* HASH, XBUFFER& input, XCHAR* leyend)
* @brief      Runs the hash test.
* @ingroup    TESTS
*
* @param[in]  HASH : hash instance used by the test.
* @param[in]  input : input buffer used by the test.
* @param[in]  leyend : legend text shown with the hash result.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_Hash(HASH* HASH, XBUFFER& input, XCHAR* leyend)
{
  if(!HASH) return false;

  XSTRING result;

  HASH->Do(input);

  HASH->GetResultString(result);

  console->Printf(_L("%-12s : %s\n"), leyend, result.Get());

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool DEVTESTS_CONSOLE::Test_WaitSound(SNDITEM* item)
* @brief      Runs the wait sound test.
* @ingroup    TESTS
*
* @param[in]  item : sound item used by the wait operation.
*
* @return     bool : true if it is successful.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool DEVTESTS_CONSOLE::Test_WaitSound(SNDITEM* item)
{
  #ifdef SND_ACTIVE
  APPFLOW_EXTENDED.ShowAll();
  devtests_console->Show_PlaySound();
    
  for(int c=0; c<10; c++)
    { 
      if(item)
        {             
          if(item->GetNTimesToPlay() == SNDFACTORY_UNDEFINED)
            {
              if(devtests_console->console->KBHit()) 
                {
                  devtests_console->console->GetChar();

                  return false;
                }
            }
        }

      GEN_XSLEEP.MilliSeconds(5);
    }
   #endif   
   return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         void DEVTESTS_CONSOLE::HandleEvent_Scheduler(XSCHEDULER_XEVENT* event)
* @brief      Handles scheduler events.
* @ingroup    TESTS
*
* @param[in]  event : event information to process.
*
* @return     void : does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
void DEVTESTS_CONSOLE::HandleEvent_Scheduler(XSCHEDULER_XEVENT* event)
{  
  switch(event->GetTask()->GetID())
    {
      case DEVTESTS_CONSOLE_TASKID_TEST  : { XSTRING string;

                                            event->GetDateTime()->GetDateTimeToString(XDATETIME_FORMAT_STANDARD, string);
                                            console->Printf(_L("%s: [Task] event ...\n"), string.Get());
                                          }
                                          break;
    } 
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         void DEVTESTS_CONSOLE::HandleEvent_Sound(SNDFACTORY_XEVENT* event)
* @brief      Handles sound events.
* @ingroup    TESTS
*
* @param[in]  event : event information to process.
*
* @return     void : does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
void DEVTESTS_CONSOLE::HandleEvent_Sound(SNDFACTORY_XEVENT* event)
{  
  #ifdef SND_ACTIVE
  switch(event->GetEventType())
    {
      case SNDFACTORY_XEVENT_TYPE_SOUND_INI     : 
      case SNDFACTORY_XEVENT_TYPE_SOUND_PLAY    : 
      case SNDFACTORY_XEVENT_TYPE_SOUND_PAUSE   : 
      case SNDFACTORY_XEVENT_TYPE_SOUND_STOP    : 
      case SNDFACTORY_XEVENT_TYPE_SOUND_END     : { XSTRING  typestr;
                                                    XSTRING  statusstr;
                                                    XSTRING* ID;  
                                                    
                                                    event->GetItem()->GetType(typestr);
                                                    event->GetItem()->GetStatus(statusstr);
                                                    ID = event->GetItem()->GetID();      

                                                    XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Sound] [%08X] %s (%s) -> %s"), event->GetItem(), typestr.Get(), ID->Get(), statusstr.Get());    
                                                  } 
                                                  break;
    }  
  #endif
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         void DEVTESTS_CONSOLE::HandleEvent_WebClient(DIOWEBCLIENT_XEVENT* event)
* @brief      Handles web client events.
* @ingroup    TESTS
*
* @param[in]  event : event information to process.
*
* @return     void : does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
void DEVTESTS_CONSOLE::HandleEvent_WebClient(DIOWEBCLIENT_XEVENT* event)
{
  XSTRING line;
  DIOURL  URLweb;

  if(event->GetURL()) URLweb = event->GetURL()->Get();

  switch(event->GetEventType())
    {
      case DIOWEBCLIENT_XEVENT_TYPE_OPENWEB         :
      case DIOWEBCLIENT_XEVENT_TYPE_WRITEHEADER     :
      case DIOWEBCLIENT_XEVENT_TYPE_SENDPOSTDATA    :
      case DIOWEBCLIENT_XEVENT_TYPE_HEADERERROR     :
      case DIOWEBCLIENT_XEVENT_TYPE_READHEADER      : { line.Format(_L("Inicializando descarga [%s]"), URLweb.Get());

                                                        console->PrintMessage(line.Get() , 4, true, false);
                                                        console->EraseToEndLine(line.GetSize()+4);
                                                        console->PrintMessage(_L("\r"), 0, false, false);
                                                      }
                                                      break;

      case DIOWEBCLIENT_XEVENT_TYPE_READBODYBLOCK   : { line.Format(_L("Descargando [%s] -> %d Kb "), URLweb.Get(), (event->GetDownloadSize() / 1024));

                                                        if(event->GetContentLenght()) line.AddFormat(_L("(%3.2f%%) "), event->GetOperationPercent());

                                                        line.AddFormat(_L("[%d Mbps] "), event->GetMBPSSpeed());

                                                        console->PrintMessage(line.Get() , 4, true, false);
                                                        console->EraseToEndLine(line.GetSize()+4);
                                                        console->PrintMessage(_L("\r"), 0, false, false);
                                                      }
                                                      break;

      case DIOWEBCLIENT_XEVENT_TYPE_CLOSEWEB        : console->PrintMessage(_L(" "), 0, false, true);
                                                      break;
    }
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         void DEVTESTS_CONSOLE::HandleEvent_DNSProtocol_MitM_Server(DIODNSPROTOCOL_MITM_SERVER_XEVENT* event)
* @brief      Handles DNS protocol MitM server events.
* @ingroup    TESTS
*
* @param[in]  event : event information to process.
*
* @return     void : does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
void DEVTESTS_CONSOLE::HandleEvent_DNSProtocol_MitM_Server(DIODNSPROTOCOL_MITM_SERVER_XEVENT* event)
{
  switch(event->GetEventType())
    {
      case DIODNSPROTOCOL_MITM_SERVER_XEVENT_TYPE_ASKDNS      : { XSTRING originIP;

                                                                  event->GetOriginIP()->GetXString(originIP);

                                                                  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Ask DNS Protocol] (%s)"), event->GetAskedURL()->Get()); 
                                                                  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, (*event->GetAskedBuffer())); 
                                                                }
                                                                break;

      case DIODNSPROTOCOL_MITM_SERVER_XEVENT_TYPE_ANSWERDNS   : { XSTRING originIP;

                                                                  event->GetOriginIP()->GetXString(originIP);

                                                                  XTRACE_PRINTCOLOR(XTRACE_COLOR_BLUE, _L("[Answer DNS Protocol] (%s)"), event->GetAskedURL()->Get()); 
                                                                  XTRACE_PRINTDATABLOCKCOLOR(XTRACE_COLOR_BLUE, (*event->GetAnsweredBuffer())); 
                                                                }
                                                                break;
    

    }
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         void DEVTESTS_CONSOLE::HandleEvent_DIOStream(DIOSTREAM_XEVENT* event)
* @brief      Handles DIO stream events.
* @ingroup    TESTS
*
* @param[in]  event : event information to process.
*
* @return     void : does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
void DEVTESTS_CONSOLE::HandleEvent_DIOStream(DIOSTREAM_XEVENT* event)
{
  if(!event) 
    {
      return;
    }

  switch(event->GetEventType())
    {
      case DIOSTREAM_XEVENT_TYPE_CONNECTED     : { 
                                                  int a=0;
                                                  a++;               
                                                }
                                                break;

      case DIOSTREAM_XEVENT_TYPE_DISCONNECTED  : { 
                                                  int a=0;
                                                  a++;               
                                                }
                                                break;
    }

}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         void DEVTESTS_CONSOLE::HandleEvent(XEVENT* xevent)
* @brief      Handles an event.
* @ingroup    TESTS
*
* @param[in]  xevent : event information to process.
*
* @return     void : does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
void DEVTESTS_CONSOLE::HandleEvent(XEVENT* xevent)
{
  if(!xevent) 
    {
      return;
    }

  switch(xevent->GetEventFamily())
    {
      case XEVENT_TYPE_SCHEDULER        : { XSCHEDULER_XEVENT* event = (XSCHEDULER_XEVENT*)xevent;
                                            if(!event) return;

                                            HandleEvent_Scheduler(event);
                                          }
                                          break;
      #ifdef SND_ACTIVE
      case XEVENT_TYPE_SOUND            : { SNDFACTORY_XEVENT* event = (SNDFACTORY_XEVENT*)xevent;
                                            if(!event) return;

                                            HandleEvent_Sound(event);
                                          }
                                          break;
      #endif

      case XEVENT_TYPE_WEBCLIENT        : { DIOWEBCLIENT_XEVENT* event = (DIOWEBCLIENT_XEVENT*)xevent;
                                            if(!event) return;

                                            HandleEvent_WebClient(event);
                                          }
                                          break;

      case XEVENT_TYPE_DIODNS           : { DIODNSPROTOCOL_MITM_SERVER_XEVENT* event = (DIODNSPROTOCOL_MITM_SERVER_XEVENT*)xevent;
                                            if(!event) return;

                                            HandleEvent_DNSProtocol_MitM_Server(event);
                                          }
                                          break;

      case XEVENT_TYPE_DIOSTREAM        : { DIOSTREAM_XEVENT* event = (DIOSTREAM_XEVENT*)xevent;
                                            if(!event) return;

                                            HandleEvent_DIOStream(event);
                                          }
                                          break;
    }
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         void DEVTESTS_CONSOLE::ThreadRunFunction(void* param)
* @brief      Runs the thread function.
* @ingroup    TESTS
*
* @param[in]  param : param value used by the operation.
*
* @return     void : does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
void DEVTESTS_CONSOLE::ThreadRunFunction(void* param)
{
  DEVTESTS_CONSOLE_XTHREADPARAM* threadparam = (DEVTESTS_CONSOLE_XTHREADPARAM*)param;
  if(!threadparam) return;

  //threadparam->devtest_console->xmutexthread->Lock();
  
  XTRACE_PRINTCOLOR(threadparam->index+1, _L("[%02d] Into Thread ...."), threadparam->index);

  /*
  switch(threadparam->index)
    {
      case 0  : GEN_XSLEEP.MilliSeconds(100);   break;
      case 1  : GEN_XSLEEP.MilliSeconds(600);   break;
      case 2  : GEN_XSLEEP.MilliSeconds(900);   break;
      case 3  : GEN_XSLEEP.MilliSeconds( 50);   break;
      case 4  : GEN_XSLEEP.MilliSeconds(250);   break;
      default : GEN_XSLEEP.MilliSeconds(150);   break;
    }  
  */

  //threadparam->devtest_console->xmutexthread->UnLock();
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         void DEVTESTS_CONSOLE::Clean()
* @brief      Cleans the object internal state.
* @ingroup    TESTS
*
* @return     void : does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
void DEVTESTS_CONSOLE::Clean()
{  
  xtimerupdateconsole         = NULL;

  xmutexthread                = NULL;
}
