/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibTrace.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBTRACE
* @brief      Unit tests for SCRIPT_LIB_TRACE
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
#include "UnitTests_Script_ScriptLibTrace.h"
#include "UnitTests_Script_TestHelpers.h"
#include "Script_Lib_Trace.h"
#include "GEN_Control.h"

#ifdef GOOGLETEST_ACTIVE
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBTRACE, UNITTESTS_SCRIPTLIBTRACE_CLASSNAME, SCRIPT_LIB_TRACE, SCRIPT_LIB_NAME_TRACE, __L("TracePrintColor"))

TEST(UNITTESTS_SCRIPTLIBTRACE_CLASSNAME, PrintColorRejectsMissingMask)
{
  SCRIPT_LIB_TRACE               library;
  UNITTESTS_SCRIPT_ERRORCAPTURE  script;
  XVECTOR<XVARIANT*>             params;
  XVARIANT                       color(1);
  XVARIANT                       result;

  params.Add(&color);
  Call_TracePrintColor(&library, &script, &params, &result);

  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);

  params.DeleteAll();
}


TEST(UNITTESTS_SCRIPTLIBTRACE_CLASSNAME, ClearScreenAcceptsItsSingleArgument)
{
  SCRIPT_LIB_TRACE               library;
  UNITTESTS_SCRIPT_ERRORCAPTURE  script;
  XVECTOR<XVARIANT*>             params;
  XVARIANT                       recursive(false);
  XVARIANT                       result;

  params.Add(&recursive);
  Call_TraceClearScreen(&library, &script, &params, &result);

  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_NONE);

  params.DeleteAll();
}
#endif
