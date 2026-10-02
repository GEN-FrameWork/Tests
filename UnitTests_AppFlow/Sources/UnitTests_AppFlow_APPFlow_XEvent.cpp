/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_APPFlow_XEvent.cpp
*
* @class      UNITTESTS_APPFLOW_APPFLOW_XEVENT
* @brief      AppFlow unit tests for APPFLOW_XEVENT class
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

#include "APPFlow_XEvent.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef APPFLOW_ACTIVE
namespace TEST_APPFLOW_XEVENT
{


TEST(APPFLOW_XEVENT, ConstructAndChangeStatusType)
{
  APPFLOW_XEVENT event((XSUBJECT*)NULL, APPFLOW_XEVENT_TYPE_CHANGESTATUSTYPE);

  EXPECT_EQ(event.GetEventType(), APPFLOW_XEVENT_TYPE_CHANGESTATUSTYPE);
  EXPECT_EQ(event.GetChangeStatusType(), XSYSTEM_CHANGESTATUSTYPE_NONE);

  event.SetChangeStatusType(XSYSTEM_CHANGESTATUSTYPE_REBOOT);
  EXPECT_EQ(event.GetChangeStatusType(), XSYSTEM_CHANGESTATUSTYPE_REBOOT);

  event.SetChangeStatusType(XSYSTEM_CHANGESTATUSTYPE_SUSPEND);
  EXPECT_EQ(event.GetChangeStatusType(), XSYSTEM_CHANGESTATUSTYPE_SUSPEND);
}


}
#endif
#endif
