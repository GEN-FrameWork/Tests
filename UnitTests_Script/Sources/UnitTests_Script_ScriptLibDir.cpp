/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibDir.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBDIR
* @brief      Unit tests for SCRIPT_LIB_DIR
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
#include "UnitTests_Script_ScriptLibDir.h"
#include "UnitTests_Script_TestHelpers.h"
#include "Script_Lib_Dir.h"
#include "GEN_Control.h"

#ifdef GOOGLETEST_ACTIVE
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBDIR, UNITTESTS_SCRIPTLIBDIR_CLASSNAME, SCRIPT_LIB_DIR, SCRIPT_LIB_NAME_DIR, _L("IsItExists"))

namespace TEST_SCRIPTLIBDIR
{
TEST(UNITTESTS_SCRIPTLIBDIR_CLASSNAME, RegistersReadAndWriteFunctions)
{
  SCRIPT script;
  SCRIPT_LIB_DIR library;
  ASSERT_TRUE(library.AddLibraryFunctions(&script));
  EXPECT_NE(script.GetLibraryFunction(_L("IsItExists")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("MakeDir")), (SCRIPT_LIB_FUNCTION*)NULL);
}


TEST(UNITTESTS_SCRIPTLIBDIR_CLASSNAME, IsItExistsReturnsFalseForMissingPath)
{
  SCRIPT script;
  SCRIPT_LIB_DIR library;
  XVARIANT path(_L("Z:/UnitTests_Script/this_path_should_not_exist_42"));
  XVARIANT result(true);
  XVECTOR<XVARIANT*> params;

  params.Add(&path);
  Call_IsItExists(&library, &script, &params, &result);
  EXPECT_FALSE((bool)result);
}


TEST(UNITTESTS_SCRIPTLIBDIR_CLASSNAME, IsItExistsRejectsMissingArgument)
{
  SCRIPT_LIB_DIR                 library;
  UNITTESTS_SCRIPT_ERRORCAPTURE  script;
  XVARIANT                       result;
  XVECTOR<XVARIANT*>             params;

  Call_IsItExists(&library, &script, &params, &result);
  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);
}
}
#endif
