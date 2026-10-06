/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowAlerts.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWALERTS
* @brief      AppFlow unit tests for APPFLOWALERTS class
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

#ifdef DIO_ALERTS_ACTIVE
#include "APPFlowAlerts.h"
#include "APPFlowCFG.h"
#endif


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_ALERTS_ACTIVE
#ifdef DIO_ALERTS_ACTIVE
namespace TEST_APPFLOWALERTS
{


TEST(APPFLOWALERTS, GetIsInstancedFalseThenGetAndDelWithoutSend)
{
  if(APPFLOWALERTS::GetIsInstanced())
    {
      APPFLOWALERTS::GetInstance().End();
      APPFLOWALERTS::DelInstance();
    }

  EXPECT_FALSE(APPFLOWALERTS::GetIsInstanced());

  APPFLOWALERTS& alerts = APPFLOWALERTS::GetInstance();
  EXPECT_TRUE(APPFLOWALERTS::GetIsInstanced());
  (void)alerts;

  EXPECT_TRUE(APPFLOWALERTS::DelInstance());
  EXPECT_FALSE(APPFLOWALERTS::GetIsInstanced());
}


TEST(APPFLOWALERTS, IniRejectsInactiveAlertsAndEnd)
{
  if(APPFLOWALERTS::GetIsInstanced())
    {
      APPFLOWALERTS::GetInstance().End();
      APPFLOWALERTS::DelInstance();
    }

  APPFLOWCFG cfg((XCHAR*)NULL);
  EXPECT_TRUE(cfg.DoVariableMapping());
  EXPECT_TRUE(cfg.DoDefault());

  // DoDefault leaves alerts inactive (Clean default); Ini must refuse before Send paths.
  #ifdef APPFLOW_CFG_ALERTS_ACTIVE
  EXPECT_FALSE(cfg.Alerts_IsActive());
  #endif

  int status[APPFLOW_ALERT_TYPE_MAX];
  APPFLOWALERTS& alerts = APPFLOWALERTS::GetInstance();
  EXPECT_FALSE(alerts.Ini(&cfg, _L("UnitTests_AppFlow"), 1, 0, 0, status));
  EXPECT_TRUE(alerts.End());

  EXPECT_TRUE(APPFLOWALERTS::DelInstance());
  EXPECT_TRUE(cfg.End());
}


TEST(APPFLOWALERTS, IniActiveWithoutChannelsThenEndWithoutSend)
{
  if(APPFLOWALERTS::GetIsInstanced())
    {
      APPFLOWALERTS::GetInstance().End();
      APPFLOWALERTS::DelInstance();
    }

  XSTRING cfgname;
  cfgname = _L("unittests_appflow_alerts");

  XSTRING cfgfilename;
  cfgfilename  = cfgname;
  cfgfilename += _L(".ini");

  ASSERT_TRUE(UNITTESTS_APPFLOW_HELPER::WriteOfflineAppFlowCfgAsset(cfgfilename.Get()));

  {
    APPFLOWCFG cfg(cfgname.Get());
    EXPECT_TRUE(cfg.DoVariableMapping());
    EXPECT_TRUE(cfg.DoDefault());
    EXPECT_TRUE(cfg.Load());
    EXPECT_TRUE(cfg.LoadReadjustment());

    #ifdef APPFLOW_CFG_ALERTS_ACTIVE
    ASSERT_TRUE(cfg.Alerts_IsActive());
    EXPECT_FALSE(cfg.Alerts_IsActiveSMTP());
    EXPECT_FALSE(cfg.Alerts_IsActiveUDP());
    #endif

    int status[APPFLOW_ALERT_TYPE_MAX];
    APPFLOWALERTS& alerts = APPFLOWALERTS::GetInstance();

    // Alerts overall active but no sender channel configured -> Ini returns false (no ACTIVE sender).
    EXPECT_FALSE(alerts.Ini(&cfg, _L("UnitTests_AppFlow"), 1, 0, 0, status));
    EXPECT_EQ(status[APPFLOW_ALERT_TYPE_SMTP], (int)APPFLOW_ALERT_STATUS_NOTACTIVATED);
    EXPECT_EQ(status[APPFLOW_ALERT_TYPE_SMS],  (int)APPFLOW_ALERT_STATUS_NOTACTIVATED);
    EXPECT_EQ(status[APPFLOW_ALERT_TYPE_WEB],  (int)APPFLOW_ALERT_STATUS_NOTACTIVATED);
    EXPECT_EQ(status[APPFLOW_ALERT_TYPE_UDP],  (int)APPFLOW_ALERT_STATUS_NOTACTIVATED);

    EXPECT_TRUE(alerts.End());
    EXPECT_TRUE(APPFLOWALERTS::DelInstance());
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
#endif
