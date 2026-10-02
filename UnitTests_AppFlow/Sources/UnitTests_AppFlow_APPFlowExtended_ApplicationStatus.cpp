/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowExtended_ApplicationStatus.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWEXTENDED_APPLICATIONSTATUS
* @brief      AppFlow unit tests for APPFLOWEXTENDED_APPLICATIONSTATUS class
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

#include "APPFlowCFG.h"
#include "APPFlowExtended_ApplicationStatus.h"
#include "XFileJSON.h"
#include "XSerializable.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_EXTENDED_APPLICATIONSTATUS_ACTIVE
namespace TEST_APPFLOWEXTENDED_APPLICATIONSTATUS
{


TEST(APPFLOWEXTENDED_APPLICATIONSTATUS, SetMemoryAndSerializeDeserialize)
{
  APPFLOWCFG cfg((XCHAR*)NULL);
  APPFLOWEXTENDED_APPLICATIONSTATUS status(&cfg);

  status.SetMemoryTotal(2048);
  status.SetMemoryFree(1024);
  status.SetMemoryFreePercent(50);

  EXPECT_EQ(status.GetMemoryTotal(), (XDWORD)2048);
  EXPECT_EQ(status.GetMemoryFree(), (XDWORD)1024);
  EXPECT_EQ(status.GetMemoryFreePercent(), (XDWORD)50);

  ASSERT_NE(status.GetOSVersion(), (XSTRING*)NULL);
  ASSERT_NE(status.GetAppVersion(), (XSTRING*)NULL);
  ASSERT_NE(status.GetAverange(), (XSTRING*)NULL);
  ASSERT_NE(status.GetCheckResourcesHardware(), (APPFLOWCHECKRESOURCESHARDWARE*)NULL);

  status.GetOSVersion()->Set(__L("UnitTestOS"));
  status.GetAppVersion()->Set(__L("1.2.3"));
  status.GetAverange()->Set(__L("avg"));

  XFILEJSON filejson;
  XSERIALIZATIONMETHOD* method = XSERIALIZABLE::CreateInstance(filejson);
  ASSERT_NE(method, (XSERIALIZATIONMETHOD*)NULL);

  EXPECT_TRUE(status.DoSerialize(method));

  APPFLOWEXTENDED_APPLICATIONSTATUS restored(&cfg);
  restored.SetSerializationMethod(method);
  EXPECT_TRUE(restored.DoDeserialize(method));

  EXPECT_EQ(restored.GetMemoryTotal(), (XDWORD)2048);
  EXPECT_EQ(restored.GetMemoryFree(), (XDWORD)1024);
  EXPECT_EQ(restored.GetMemoryFreePercent(), (XDWORD)50);
  EXPECT_EQ(restored.GetOSVersion()->Compare(__L("UnitTestOS")), 0);
  EXPECT_EQ(restored.GetAppVersion()->Compare(__L("1.2.3")), 0);
  EXPECT_EQ(restored.GetAverange()->Compare(__L("avg")), 0);

  GEN_DELETE method;
}


TEST(APPFLOWEXTENDED_APPLICATIONSTATUS, CreateResponseContainsSerializedFields)
{
  APPFLOWCFG cfg((XCHAR*)NULL);
  APPFLOWEXTENDED_APPLICATIONSTATUS status(&cfg);

  status.SetMemoryTotal(4096);
  status.SetMemoryFree(2048);
  status.SetMemoryFreePercent(50);
  status.GetOSVersion()->Set(__L("CreateResponseOS"));

  XSTRING response;
  EXPECT_TRUE(status.CreateResponse(&response));
  EXPECT_FALSE(response.IsEmpty());
  EXPECT_NE(response.Find(__L("memorytotal"), true), XSTRING_NOTFOUND);
  EXPECT_NE(response.Find(__L("CreateResponseOS"), true), XSTRING_NOTFOUND);
  EXPECT_FALSE(status.CreateResponse(NULL));
}


}
#endif
#endif
#endif
