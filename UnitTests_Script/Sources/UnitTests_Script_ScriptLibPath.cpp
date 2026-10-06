/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibPath.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBPATH
* @brief      Unit tests for SCRIPT_LIB_PATH
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
#include "UnitTests_Script_ScriptLibPath.h"
#include "UnitTests_Script_TestHelpers.h"
#include "Script_Lib_Path.h"
#include "GEN_Control.h"

#ifdef GOOGLETEST_ACTIVE
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBPATH, UNITTESTS_SCRIPTLIBPATH_CLASSNAME, SCRIPT_LIB_PATH, SCRIPT_LIB_NAME_PATH, _L("GetNameScript"))

namespace TEST_SCRIPTLIBPATH
{
TEST(UNITTESTS_SCRIPTLIBPATH_CLASSNAME, GetNameScriptReturnsConfiguredFileName)
{
  SCRIPT script;
  SCRIPT_LIB_PATH library;
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING text;

  (*script.GetPath()) = _L("C:/scripts/folder/demo.g");
  Call_GetNameScript(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(text));
  EXPECT_EQ(text.Compare(_L("demo")), 0);
}


TEST(UNITTESTS_SCRIPTLIBPATH_CLASSNAME, GetPathScriptReturnsDriveAndDirectory)
{
  SCRIPT script;
  SCRIPT_LIB_PATH library;
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING text;

  (*script.GetPath()) = _L("C:/scripts/folder/demo.g");
  Call_GetPathScript(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(text));
  EXPECT_NE(text.Find(_L("scripts"), false), XSTRING_NOTFOUND);
}
}
#endif
