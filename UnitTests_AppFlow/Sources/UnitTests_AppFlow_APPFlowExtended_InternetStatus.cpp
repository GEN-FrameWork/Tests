/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowExtended_InternetStatus.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWEXTENDED_INTERNETSTATUS
* @brief      AppFlow unit tests for APPFLOWEXTENDED_INTERNETSTATUS class
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
#include "APPFlowExtended_InternetStatus.h"
#include "XFileJSON.h"
#include "XSerializable.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
#ifdef APPFLOW_EXTENDED_INTERNETSTATUS_ACTIVE
namespace TEST_APPFLOWEXTENDED_INTERNETSTATUS
{


TEST(APPFLOWEXTENDED_INTERNETSTATUS, SetLatencyAndSerializeDeserialize)
{
  // Cadences stay 0 (Clean defaults) so InternetServices::Ini starts scheduler without net tasks.
  APPFLOWCFG cfg((XCHAR*)NULL);
  APPFLOWEXTENDED_INTERNETSTATUS status(&cfg);

  status.SetLatency(123);
  EXPECT_EQ(status.GetLatency(), (XDWORD)123);

  ASSERT_NE(status.GetLocalIP(), (XSTRING*)NULL);
  ASSERT_NE(status.GetPublicIP(), (XSTRING*)NULL);
  ASSERT_NE(status.GetInternetServices(), (APPFLOWINTERNETSERVICES*)NULL);

  status.GetLocalIP()->Set(_L("192.0.2.10"));
  status.GetPublicIP()->Set(_L("203.0.113.5"));

  XFILEJSON filejson;
  XSERIALIZATIONMETHOD* method = XSERIALIZABLE::CreateInstance(filejson);
  ASSERT_NE(method, (XSERIALIZATIONMETHOD*)NULL);

  EXPECT_TRUE(status.DoSerialize(method));

  APPFLOWEXTENDED_INTERNETSTATUS restored(&cfg);
  restored.SetSerializationMethod(method);
  EXPECT_TRUE(restored.DoDeserialize(method));

  EXPECT_EQ(restored.GetLatency(), (XDWORD)123);
  EXPECT_EQ(restored.GetLocalIP()->Compare(_L("192.0.2.10")), 0);
  EXPECT_EQ(restored.GetPublicIP()->Compare(_L("203.0.113.5")), 0);

  GEN_DELETE method;
}


TEST(APPFLOWEXTENDED_INTERNETSTATUS, CreateResponseContainsSerializedFields)
{
  APPFLOWCFG cfg((XCHAR*)NULL);
  APPFLOWEXTENDED_INTERNETSTATUS status(&cfg);

  status.SetLatency(77);
  status.GetLocalIP()->Set(_L("192.0.2.77"));
  status.GetPublicIP()->Set(_L("198.51.100.77"));

  XSTRING response;
  EXPECT_TRUE(status.CreateResponse(&response));
  EXPECT_FALSE(response.IsEmpty());
  EXPECT_NE(response.Find(_L("latencyms"), true), XSTRING_NOTFOUND);
  EXPECT_NE(response.Find(_L("192.0.2.77"), true), XSTRING_NOTFOUND);
  EXPECT_NE(response.Find(_L("198.51.100.77"), true), XSTRING_NOTFOUND);
  EXPECT_FALSE(status.CreateResponse(NULL));
}


}
#endif
#endif
#endif
