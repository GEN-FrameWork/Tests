/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibFunction.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBFUNCTION
* @brief      Unit tests for SCRIPT_LIB_FUNCTION
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
#include "UnitTests_Script_ScriptLibFunction.h"
#include "UnitTests_Script_TestHelpers.h"
#include "GEN_Control.h"

#ifdef GOOGLETEST_ACTIVE
namespace TEST_SCRIPTLIBFUNCTION
{

TEST(UNITTESTS_SCRIPTLIBFUNCTION_CLASSNAME, StoresAndUpdatesDescriptor)
{
  SCRIPT_LIB first(__L("First"));
  SCRIPT_LIB second(__L("Second"));
  SCRIPT_LIB_FUNCTION function(&first, __L("Function"), UnitTests_Script_DummyFunction);

  EXPECT_EQ(function.GetLibrary(), &first);
  EXPECT_EQ(function.GetName()->Compare(__L("Function")), 0);
  SCRFUNCIONLIBRARY expectedfunction = UnitTests_Script_DummyFunction;

  EXPECT_EQ(function.GetFunctionLibrary(), expectedfunction);
  EXPECT_FALSE(function.SetLibrary(NULL));
  EXPECT_TRUE(function.SetLibrary(&second));
  EXPECT_EQ(function.GetLibrary(), &second);
  EXPECT_TRUE(function.SetFunctionLibrary(NULL));
  EXPECT_EQ(function.GetFunctionLibrary(), (SCRFUNCIONLIBRARY)NULL);
}

}
#endif
