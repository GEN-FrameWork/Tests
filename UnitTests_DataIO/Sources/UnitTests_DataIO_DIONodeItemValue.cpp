/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIONodeItemValue.cpp
*
* @class      UNITTESTS_DATAIO_DIONODEITEMVALUE
* @brief      DataIO unit tests for DIONODEITEMVALUE class
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

#include "UnitTests_DataIO_Helper.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XString.h"

#include "DIONodeItemValue.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_NODES_ACTIVE
namespace TEST_DIONODEITEMVALUE
{


TEST(DIONODEITEMVALUE, TypeModeAndChangeFlag)
{
  DIONODEITEMVALUE value;
  XSTRING          modestring;
  XSTRING          description;

  value.SetType(DIONODEITEMVALUE_TYPE_TEMPERATURE);
  EXPECT_EQ(value.GetType(), (XDWORD)DIONODEITEMVALUE_TYPE_TEMPERATURE);

  value.SetMode(DIONODEITEMVALUE_MODE_READWRITE);
  EXPECT_EQ(value.GetMode(), DIONODEITEMVALUE_MODE_READWRITE);
  value.GetModeString(modestring);
  EXPECT_FALSE(modestring.IsEmpty());

  value.SetValueHasChanged(true);
  EXPECT_TRUE(value.ValueHasChanged());

  ASSERT_NE(value.GetValue(), (XVARIANT*)NULL);
  ASSERT_NE(value.GetUnitFormat(), (DIONODEITEMVALUEUNITFORMAT*)NULL);

  EXPECT_TRUE(value.GetDescription(description));
}


}
#endif
#endif
#endif
