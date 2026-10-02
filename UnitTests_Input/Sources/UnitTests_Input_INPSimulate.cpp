/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Input_INPSimulate.cpp
*
* @class      UNITTESTS_INPUT_INPSIMULATE
* @brief      Input unit tests for INPSIMULATE class
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

#include "UnitTests_Input_INPSimulate.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "INPSimulate.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef INP_SIMULATE_ACTIVE
namespace TEST_INPSIMULATE
{


TEST(UNITTESTS_INPSIMULATE_CLASSNAME, EmptyLiteralReturnsZero)
{
  INPSIMULATE simulate;
  ALTERNATIVE_KEY altkey = ALTERNATIVE_KEY_SHIFT;

  EXPECT_EQ(simulate.GetKDBCodeByLiteral(__L(""), altkey), (XBYTE)0);
}


TEST(UNITTESTS_INPSIMULATE_CLASSNAME, LiteralAReturns0x41)
{
  INPSIMULATE simulate;
  ALTERNATIVE_KEY altkey = ALTERNATIVE_KEY_NONE;

  EXPECT_EQ(simulate.GetKDBCodeByLiteral(__L("A"), altkey), (XBYTE)0x41);
  EXPECT_EQ(altkey, ALTERNATIVE_KEY_NONE);
}


TEST(UNITTESTS_INPSIMULATE_CLASSNAME, LiteralEnterReturns0x0D)
{
  INPSIMULATE simulate;
  ALTERNATIVE_KEY altkey = ALTERNATIVE_KEY_NONE;

  EXPECT_EQ(simulate.GetKDBCodeByLiteral(__L("ENTER"), altkey), (XBYTE)0x0D);
  EXPECT_EQ(altkey, ALTERNATIVE_KEY_NONE);
}


TEST(UNITTESTS_INPSIMULATE_CLASSNAME, LiteralSpacebarReturns0x20)
{
  INPSIMULATE simulate;
  ALTERNATIVE_KEY altkey = ALTERNATIVE_KEY_NONE;

  EXPECT_EQ(simulate.GetKDBCodeByLiteral(__L("SPACEBAR"), altkey), (XBYTE)0x20);
  EXPECT_EQ(altkey, ALTERNATIVE_KEY_NONE);
}


TEST(UNITTESTS_INPSIMULATE_CLASSNAME, LiteralEscReturns0x1B)
{
  INPSIMULATE simulate;
  ALTERNATIVE_KEY altkey = ALTERNATIVE_KEY_NONE;

  EXPECT_EQ(simulate.GetKDBCodeByLiteral(__L("ESC"), altkey), (XBYTE)0x1B);
  EXPECT_EQ(altkey, ALTERNATIVE_KEY_NONE);
}


TEST(UNITTESTS_INPSIMULATE_CLASSNAME, LiteralExclamationRequiresShift)
{
  INPSIMULATE simulate;
  ALTERNATIVE_KEY altkey = ALTERNATIVE_KEY_NONE;

  EXPECT_EQ(simulate.GetKDBCodeByLiteral(__L("!"), altkey), (XBYTE)0x31);
  EXPECT_EQ(altkey, ALTERNATIVE_KEY_SHIFT);
}


TEST(UNITTESTS_INPSIMULATE_CLASSNAME, UnknownLiteralReturnsZero)
{
  INPSIMULATE simulate;
  ALTERNATIVE_KEY altkey = ALTERNATIVE_KEY_NONE;

  EXPECT_EQ(simulate.GetKDBCodeByLiteral(__L("NOT_A_REAL_KEY"), altkey), (XBYTE)0);
}


TEST(UNITTESTS_INPSIMULATE_CLASSNAME, BaseKeyPressUnPressClickReturnFalse)
{
  INPSIMULATE simulate;

  EXPECT_FALSE(simulate.Key_Press(0x41));
  EXPECT_FALSE(simulate.Key_UnPress(0x41));
  EXPECT_FALSE(simulate.Key_Click(0x41, 1));
}


TEST(UNITTESTS_INPSIMULATE_CLASSNAME, BaseMouseSetPosAndClickReturnFalse)
{
  INPSIMULATE simulate;

  EXPECT_FALSE(simulate.Mouse_SetPos(0, 0));
  EXPECT_FALSE(simulate.Mouse_Click(0, 0));
}


}
#endif
#endif
