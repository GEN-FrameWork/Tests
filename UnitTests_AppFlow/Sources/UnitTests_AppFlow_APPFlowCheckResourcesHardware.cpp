/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowCheckResourcesHardware.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWCHECKRESOURCESHARDWARE
* @brief      AppFlow unit tests for APPFLOWCHECKRESOURCESHARDWARE class
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

#include "APPFlowCheckResourcesHardware.h"
#include "APPFlowCFG.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_CHECKRESOURCESHARDWARE_ACTIVE
namespace TEST_APPFLOWCHECKRESOURCESHARDWARE
{


TEST(APPFLOWCHECKRESOURCESHARDWARE, ConstructGettersWithoutIni)
{
  APPFLOWCHECKRESOURCESHARDWARE check;

  // mem_* are populated by Update(), not Clean(); CPU accumulators are zeroed in Clean().
  EXPECT_EQ(check.GetCPUTotalCPUUsageAverange(), 0);
  EXPECT_EQ(check.GetCPUTotalCPUUsageMax(), 0);
  EXPECT_EQ(check.GetCPUAppCPUUsageAverange(), 0);
  EXPECT_EQ(check.GetCPUAppCPUUsageMax(), 0);

  EXPECT_TRUE(check.End());
}


TEST(APPFLOWCHECKRESOURCESHARDWARE, IniWithZeroCadenceCreatesSchedulerWithoutTasks)
{
  APPFLOWCFG cfg((XCHAR*)NULL);
  EXPECT_EQ(cfg.CheckResourcesHardware_GetMemStatusCheckCadence(), 0);
  EXPECT_EQ(cfg.CheckResourcesHardware_GetTotalCPUUsageCheckCadence(), 0);
  EXPECT_EQ(cfg.CheckResourcesHardware_GetAppCPUUsageCheckCadence(), 0);

  APPFLOWCHECKRESOURCESHARDWARE check;
  EXPECT_TRUE(check.Ini(&cfg));
  EXPECT_TRUE(check.End());
  EXPECT_TRUE(cfg.End());
}


}
#endif
#endif
#endif
