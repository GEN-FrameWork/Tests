/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowCheckResourcesHardware_XEvent.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWCHECKRESOURCESHARDWARE_XEVENT
* @brief      AppFlow unit tests for APPFLOWCHECKRESOURCESHARDWARE_XEVENT class
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

#include "APPFlowCheckResourcesHardware_XEvent.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_CHECKRESOURCESHARDWARE_ACTIVE
namespace TEST_APPFLOWCHECKRESOURCESHARDWARE_XEVENT
{


TEST(APPFLOWCHECKRESOURCESHARDWARE_XEVENT, MemFreeAndCPUUsageFields)
{
  APPFLOWCHECKRESOURCESHARDWARE_XEVENT event((XSUBJECT*)NULL);

  event.SetActualMemFree(4096, 25);

  XDWORD memfree_inbytes = 0;
  XBYTE  memfree_percent = 0;
  EXPECT_TRUE(event.GetActualMemFree(memfree_inbytes, memfree_percent));
  EXPECT_EQ(memfree_inbytes, (XDWORD)4096);
  EXPECT_EQ(memfree_percent, (XBYTE)25);

  int totalcpu = 55;
  int appcpu   = 12;
  event.SetActualTotalCPUUsage(totalcpu);
  event.SetActualAppCPUUsage(appcpu);

  EXPECT_EQ(event.GetActualTotalCPUUsage(), 55);
  EXPECT_EQ(event.GetActualAppCPUUsage(), 12);
}


}
#endif
#endif
#endif
