/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowUpdate.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWUPDATE
* @brief      AppFlow unit tests for APPFLOWUPDATE / APPFLOWUPDATE_CFG classes
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

#include "APPFlowUpdate.h"
#include "APPFlowCFG.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_UPDATE_ACTIVE
namespace TEST_APPFLOWUPDATE
{


TEST(APPFLOWUPDATE_CFG, SettersCopyWithoutDownload)
{
  APPFLOWUPDATE_CFG a;
  APPFLOWUPDATE_CFG b;

  a.GetURL()->Set(_L("http://example.invalid/update"));
  a.Set_Port(8080);
  a.GetAppName()->Set(_L("UnitTests_AppFlow"));
  a.GetPathRootApp()->Set(_L("."));
  a.GetAppVersion()->SetVersion(1);
  a.GetAppVersion()->SetSubVersion(2);
  a.GetAppVersion()->SetSubVersionError(3);
  a.SetDolog(false);

  EXPECT_EQ(a.GetURL()->Compare(_L("http://example.invalid/update")), 0);
  EXPECT_EQ(a.Get_Port(), (XDWORD)8080);
  EXPECT_EQ(a.GetAppName()->Compare(_L("UnitTests_AppFlow")), 0);
  EXPECT_FALSE(a.GetDolog());

  EXPECT_TRUE(b.CopyFrom(&a));
  EXPECT_EQ(b.GetURL()->Compare(_L("http://example.invalid/update")), 0);
  EXPECT_EQ(b.Get_Port(), (XDWORD)8080);
  EXPECT_EQ(b.GetAppName()->Compare(_L("UnitTests_AppFlow")), 0);
  EXPECT_EQ(b.GetPathRootApp()->Compare(_L(".")), 0);
  EXPECT_EQ(b.GetAppVersion()->GetVersion(), (XDWORD)1);
  EXPECT_EQ(b.GetAppVersion()->GetSubVersion(), (XDWORD)2);
  EXPECT_EQ(b.GetAppVersion()->GetSubVersionError(), (XDWORD)3);
  EXPECT_FALSE(b.GetDolog());

  APPFLOWUPDATE_CFG c;
  EXPECT_TRUE(a.CopyTo(&c));
  EXPECT_EQ(c.GetURL()->Compare(_L("http://example.invalid/update")), 0);
  EXPECT_EQ(c.Get_Port(), (XDWORD)8080);
  EXPECT_EQ(c.GetAppName()->Compare(_L("UnitTests_AppFlow")), 0);
}


TEST(APPFLOWUPDATE, GetIsInstancedFalseThenGetAndDelWithoutDo)
{
  if(APPFLOWUPDATE::GetIsInstanced())
    {
      APPFLOWUPDATE::GetInstance().End();
      APPFLOWUPDATE::DelInstance();
    }

  EXPECT_FALSE(APPFLOWUPDATE::GetIsInstanced());

  APPFLOWUPDATE& update = APPFLOWUPDATE::GetInstance();
  EXPECT_TRUE(APPFLOWUPDATE::GetIsInstanced());
  EXPECT_EQ(update.GetDIOAPPFlowUpdate(), (DIOAPPLICATIONUPDATE*)NULL);

  EXPECT_TRUE(APPFLOWUPDATE::DelInstance());
  EXPECT_FALSE(APPFLOWUPDATE::GetIsInstanced());
}


TEST(APPFLOWUPDATE, IniInactiveSkipsDownload)
{
  if(APPFLOWUPDATE::GetIsInstanced())
    {
      APPFLOWUPDATE::GetInstance().End();
      APPFLOWUPDATE::DelInstance();
    }

  APPFLOWCFG cfg((XCHAR*)NULL);
  EXPECT_TRUE(cfg.DoVariableMapping());
  EXPECT_TRUE(cfg.DoDefault());

  #ifdef APPFLOW_CFG_APPUPDATE_ACTIVE
  EXPECT_FALSE(cfg.ApplicationUpdate_IsActive());
  #endif

  APPFLOWUPDATE_CFG updatecfg;
  updatecfg.GetURL()->Set(_L("http://example.invalid/update"));
  updatecfg.GetAppName()->Set(_L("UnitTests_AppFlow"));
  updatecfg.GetPathRootApp()->Set(_L("."));

  APPFLOWUPDATE& update = APPFLOWUPDATE::GetInstance();
  EXPECT_TRUE(update.Ini(&cfg, &updatecfg));
  EXPECT_EQ(update.GetDIOAPPFlowUpdate(), (DIOAPPLICATIONUPDATE*)NULL);

  EXPECT_TRUE(update.End());
  EXPECT_TRUE(APPFLOWUPDATE::DelInstance());
  EXPECT_TRUE(cfg.End());
}


}
#endif
#endif
#endif
