/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowCFG.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWCFG
* @brief      AppFlow unit tests for APPFLOWCFG class
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

#include "UnitTests_AppFlow_Helper.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XString.h"
#include "XPath.h"

#include "APPFlowCFG.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_CFG_ACTIVE
namespace TEST_APPFLOWCFG
{


TEST(APPFLOWCFG, DoVariableMappingAndDoDefault)
{
  APPFLOWCFG cfg((XCHAR*)NULL);

  EXPECT_TRUE(cfg.DoVariableMapping());
  EXPECT_TRUE(cfg.DoDefault());

  #ifdef APPFLOW_CFG_GENERAL_ACTIVE
  EXPECT_EQ(cfg.GetShowDetailInfo(), (XWORD)0x0000);
  cfg.SetShowDetailInfo(0x000A);
  EXPECT_EQ(cfg.GetShowDetailInfo(), (XWORD)0x000A);
  #endif

  #ifdef APPFLOW_CFG_LOG_ACTIVE
  EXPECT_TRUE(cfg.Log_IsActive());
  #endif

  #ifdef APPFLOW_CFG_APPUPDATE_ACTIVE
  EXPECT_FALSE(cfg.ApplicationUpdate_IsActive());
  #endif

  #ifdef APPFLOW_CFG_INTERNETSERVICES_ACTIVE
  EXPECT_EQ(cfg.InternetServices_GetCheckInternetStatusCadence(), 30);
  #endif

  EXPECT_TRUE(cfg.End());
}


TEST(APPFLOWCFG, IniEndWithMinimalAsset)
{
  XSTRING cfgname;
  cfgname = __L("unittests_appflow_offline");

  XSTRING cfgfilename;
  cfgfilename  = cfgname;
  cfgfilename += __L(".ini");

  ASSERT_TRUE(UNITTESTS_APPFLOW_HELPER::WriteMinimalAppFlowCfgAsset(cfgfilename.Get()));

  {
    APPFLOWCFG cfg(cfgname.Get());

    #ifdef APPFLOW_CFG_REMOTEFILE_ACTIVE
    // DIOREMOTEFILECFG::Ini<T> needs T::GetInstance(); use explicit offline lifecycle.
    EXPECT_TRUE(cfg.DoVariableMapping());
    EXPECT_TRUE(cfg.DoDefault());
    EXPECT_TRUE(cfg.Load());
    EXPECT_TRUE(cfg.LoadReadjustment());
    EXPECT_TRUE(cfg.Save());
    #else
    EXPECT_TRUE(cfg.Ini<int>());
    #endif

    #ifdef APPFLOW_CFG_GENERAL_ACTIVE
    EXPECT_EQ(cfg.GetShowDetailInfo(), (XWORD)0);
    #endif

    EXPECT_TRUE(cfg.End());
  }

  XPATH xpath;
  if(UNITTESTS_APPFLOW_HELPER::BuildAssetPath(xpath, cfgfilename.Get()))
    {
      UNITTESTS_APPFLOW_HELPER::EraseAsset(xpath);
    }
}


TEST(APPFLOWCFG, LoadOfflineExtendedBlocks)
{
  XSTRING cfgname;
  cfgname = __L("unittests_appflow_offline_blocks");

  XSTRING cfgfilename;
  cfgfilename  = cfgname;
  cfgfilename += __L(".ini");

  ASSERT_TRUE(UNITTESTS_APPFLOW_HELPER::WriteOfflineAppFlowCfgAsset(cfgfilename.Get()));

  {
    APPFLOWCFG cfg(cfgname.Get());

    EXPECT_TRUE(cfg.DoVariableMapping());
    EXPECT_TRUE(cfg.DoDefault());
    EXPECT_TRUE(cfg.Load());
    EXPECT_TRUE(cfg.LoadReadjustment());

    #ifdef APPFLOW_CFG_LOG_ACTIVE
    EXPECT_TRUE(cfg.Log_IsActive());
    EXPECT_FALSE(cfg.Log_Backup_IsActive());
    EXPECT_EQ(cfg.Log_MaxSize(), 100);
    #endif

    #ifdef APPFLOW_CFG_INTERNETSERVICES_ACTIVE
    EXPECT_EQ(cfg.InternetServices_GetCheckInternetStatusCadence(), 0);
    EXPECT_EQ(cfg.InternetServices_GetCheckIPsChangeCadence(), 0);
    EXPECT_EQ(cfg.InternetServices_GetUpdateTimeByNTPCadence(), 0);
    EXPECT_TRUE(cfg.InternetServices_DoNotLetInternetConnectionMatter());
    #endif

    #ifdef APPFLOW_CFG_CHECKRESOURCESHARDWARE_ACTIVE
    EXPECT_EQ(cfg.CheckResourcesHardware_GetMemStatusCheckCadence(), 0);
    EXPECT_EQ(cfg.CheckResourcesHardware_GetTotalCPUUsageCheckCadence(), 0);
    EXPECT_EQ(cfg.CheckResourcesHardware_GetAppCPUUsageCheckCadence(), 0);
    #endif

    #ifdef APPFLOW_CFG_DIOLOCATION_ACTIVE
    ASSERT_NE(cfg.Location_GetStreet(), (XSTRING*)NULL);
    EXPECT_EQ(cfg.Location_GetStreet()->Compare(__L("UnitTest Street")), 0);
    EXPECT_EQ(cfg.Location_GetCity()->Compare(__L("UnitTestCity")), 0);
    EXPECT_EQ(cfg.Location_GetState()->Compare(__L("UT")), 0);
    EXPECT_EQ(cfg.Location_GetCountry()->Compare(__L("TC")), 0);
    EXPECT_EQ(cfg.Location_GetPostalCode(), 28001);
    #endif

    #ifdef APPFLOW_CFG_WEBSERVER_ACTIVE
    ASSERT_NE(cfg.WebServer_GetLocalAddress(), (XSTRING*)NULL);
    EXPECT_EQ(cfg.WebServer_GetLocalAddress()->Compare(__L("127.0.0.1")), 0);
    EXPECT_EQ(cfg.WebServer_GetPort(), 18080);
    EXPECT_EQ(cfg.WebServer_GetTimeoutToServerPage(), 5);
    EXPECT_FALSE(cfg.WebServer_IsAuthenticatedAccess());
    EXPECT_EQ(cfg.WebServer_GetLogin()->Compare(__L("unittest")), 0);
    EXPECT_EQ(cfg.WebServer_GetPassword()->Compare(__L("secret")), 0);
    #endif

    #ifdef APPFLOW_CFG_ALERTS_ACTIVE
    EXPECT_TRUE(cfg.Alerts_IsActive());
    EXPECT_FALSE(cfg.Alerts_IsActiveSMTP());
    EXPECT_FALSE(cfg.Alerts_IsActiveSMS());
    EXPECT_FALSE(cfg.Alerts_IsActiveWEB());
    EXPECT_FALSE(cfg.Alerts_IsActiveUDP());
    #endif

    #ifdef APPFLOW_CFG_APPUPDATE_ACTIVE
    EXPECT_FALSE(cfg.ApplicationUpdate_IsActive());
    EXPECT_EQ(cfg.ApplicationUpdate_GetPort(), 8080);
    EXPECT_EQ(cfg.ApplicationUpdate_GetURL()->Compare(__L("http://example.invalid/update")), 0);
    #endif

    EXPECT_TRUE(cfg.End());
  }

  XPATH xpath;
  if(UNITTESTS_APPFLOW_HELPER::BuildAssetPath(xpath, cfgfilename.Get()))
    {
      UNITTESTS_APPFLOW_HELPER::EraseAsset(xpath);
    }
}


}
#endif
#endif
#endif
