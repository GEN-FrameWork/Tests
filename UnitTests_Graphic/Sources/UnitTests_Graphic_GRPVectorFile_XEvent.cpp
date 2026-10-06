/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPVectorFile_XEvent.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPVECTORFILE_XEVENT
* @brief      Graphic unit tests for GRPVECTORFILE_XEVENT class
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

#include "UnitTests_Graphic_GRPVectorFile_XEvent.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPVectorFile_XEvent.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_VECTOR_FILE_ACTIVE
namespace TEST_GRPVECTORFILE_XEVENT
{


TEST(UNITTESTS_GRPVECTORFILE_XEVENT_CLASSNAME, ConstructSetTypePathAndMsg)
{
  GRPVECTORFILE_XEVENT event(NULL, GRPVECTORFILE_XEVENTTYPE_UNKNOWN);

  event.SetType(GRPVECTORFILETYPE_SVG);
  EXPECT_EQ(event.GetType(), GRPVECTORFILETYPE_SVG);

  ASSERT_NE(event.GetPath(), (XPATH*)NULL);
  event.GetPath()->Set(_L("assets/sample.svg"));
  EXPECT_EQ(event.GetPath()->Compare(_L("assets/sample.svg")), 0);

  ASSERT_NE(event.GetMsg(), (XSTRING*)NULL);
  event.GetMsg()->Set(_L("unit test msg"));
  EXPECT_EQ(event.GetMsg()->Compare(_L("unit test msg")), 0);
}


}
#endif
#endif
#endif
