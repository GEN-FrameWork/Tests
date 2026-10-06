/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibMath.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBMATH
* @brief      Unit tests for SCRIPT_LIB_MATH
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

#include "GEN_Defines.h"
#include "UnitTests_Script_ScriptLibMath.h"
#include "UnitTests_Script_TestHelpers.h"
#include "Script_Lib_Math.h"
#include "GEN_Control.h"

#ifdef GOOGLETEST_ACTIVE
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBMATH, UNITTESTS_SCRIPTLIBMATH_CLASSNAME, SCRIPT_LIB_MATH, SCRIPT_LIB_MATH_NAME, _L("Abs"))

namespace TEST_SCRIPTLIBMATH
{
TEST(UNITTESTS_SCRIPTLIBMATH_CLASSNAME, AbsoluteValue)
{
  SCRIPT script;
  SCRIPT_LIB_MATH library;
  XVARIANT value(-17);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  params.Add(&value);
  Call_Abs(&library, &script, &params, &result);
  EXPECT_EQ((int)result, 17);
}


TEST(UNITTESTS_SCRIPTLIBMATH_CLASSNAME, AbsoluteValueOfPositiveIsUnchanged)
{
  SCRIPT script;
  SCRIPT_LIB_MATH library;
  XVARIANT value(9);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  params.Add(&value);
  Call_Abs(&library, &script, &params, &result);
  EXPECT_EQ((int)result, 9);
}


TEST(UNITTESTS_SCRIPTLIBMATH_CLASSNAME, AbsoluteValueRejectsMissingArgument)
{
  SCRIPT_LIB_MATH                library;
  UNITTESTS_SCRIPT_ERRORCAPTURE  script;
  XVARIANT                       result;
  XVECTOR<XVARIANT*>             params;

  Call_Abs(&library, &script, &params, &result);
  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);
}
}
#endif
