/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlowMain.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOWMAIN
* @brief      AppFlow unit tests for APPFLOWMAIN class
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

#include "APPFlowMain.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
namespace TEST_APPFLOWMAIN
{


TEST(APPFLOWMAIN, HarnessProvidesNonNullApplication)
{
  // GEN_appmain is the process-wide APPFLOWMAIN; application is created by the test harness.
  APPFLOWBASE* application = GEN_appmain.GetApplication();
  ASSERT_NE(application, (APPFLOWBASE*)NULL);
}


TEST(APPFLOWBASE, ApplicationNameAndExitTypeString)
{
  APPFLOWBASE* application = GEN_appmain.GetApplication();
  ASSERT_NE(application, (APPFLOWBASE*)NULL);

  application->Application_SetName(__L("UnitTests_AppFlow"));
  ASSERT_NE(application->Application_GetName(), (XSTRING*)NULL);
  EXPECT_EQ(application->Application_GetName()->Compare(__L("UnitTests_AppFlow")), 0);

  application->SetExitType(APPFLOWBASE_EXITTYPE_BY_USER);
  EXPECT_EQ(application->GetExitType(), APPFLOWBASE_EXITTYPE_BY_USER);

  XSTRING exittypestring;
  EXPECT_TRUE(application->GetExitTypeString(exittypestring));
  EXPECT_FALSE(exittypestring.IsEmpty());

  application->SetExitType(APPFLOWBASE_EXITTYPE_UNKNOWN);
}


}
#endif
#endif
