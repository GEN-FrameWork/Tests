/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowLog.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWLOG
* @brief      AppFlow unit tests for APPFLOWLOG class
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

#include "APPFlowLog.h"
#include "APPFlowCFG.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_LOG_ACTIVE
namespace TEST_APPFLOWLOG
{


TEST(APPFLOWLOG, GetIsInstancedFalseThenGetAndDelWithoutIni)
{
  if(APPFLOWLOG::GetIsInstanced())
    {
      APPFLOWLOG::GetInstance().End();
      APPFLOWLOG::DelInstance();
    }

  EXPECT_FALSE(APPFLOWLOG::GetIsInstanced());

  APPFLOWLOG& log = APPFLOWLOG::GetInstance();
  EXPECT_TRUE(APPFLOWLOG::GetIsInstanced());
  (void)log;

  EXPECT_TRUE(APPFLOWLOG::DelInstance());
  EXPECT_FALSE(APPFLOWLOG::GetIsInstanced());
}


TEST(APPFLOWLOG, IniAndEndWithDefaultCfg)
{
  if(APPFLOWLOG::GetIsInstanced())
    {
      APPFLOWLOG::GetInstance().End();
      APPFLOWLOG::DelInstance();
    }

  APPFLOWCFG cfg((XCHAR*)NULL);
  EXPECT_TRUE(cfg.DoVariableMapping());
  EXPECT_TRUE(cfg.DoDefault());

  #ifdef APPFLOW_CFG_LOG_ACTIVE
  ASSERT_TRUE(cfg.Log_IsActive());
  #endif

  APPFLOWLOG& log = APPFLOWLOG::GetInstance();
  EXPECT_TRUE(log.Ini(&cfg, _L("UnitTests_AppFlow")));
  EXPECT_TRUE(log.End());

  EXPECT_TRUE(APPFLOWLOG::DelInstance());
  EXPECT_TRUE(cfg.End());

  XPATH xpath;
  if(UNITTESTS_APPFLOW_HELPER::BuildAssetPath(xpath, _L("UnitTests_AppFlow.log")))
    {
      UNITTESTS_APPFLOW_HELPER::EraseAsset(xpath);
    }
}


}
#endif
#endif
#endif
