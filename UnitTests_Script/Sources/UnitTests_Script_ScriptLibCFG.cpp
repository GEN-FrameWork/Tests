/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibCFG.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBCFG
* @brief      Unit tests for SCRIPT_LIB_CFG
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
#include "UnitTests_Script_ScriptLibCFG.h"
#include "UnitTests_Script_TestHelpers.h"
#ifdef SCRIPT_LIB_CFG_ACTIVE
#include "Script_Lib_CFG.h"
#endif
#include "GEN_Control.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_LIB_CFG_ACTIVE)
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBCFG, UNITTESTS_SCRIPTLIBCFG_CLASSNAME, SCRIPT_LIB_CFG, SCRIPT_LIB_NAME_CFG, __L("GetFileCFGValue"))

namespace TEST_SCRIPTLIBCFG
{
TEST(UNITTESTS_SCRIPTLIBCFG_CLASSNAME, StoresExternalConfiguration)
{
  SCRIPT_LIB_CFG library;
  EXPECT_EQ(library.GetXFileCFG(), (XFILECFG*)NULL);
  library.SetXFileCFG((XFILECFG*)0x1);
  EXPECT_EQ(library.GetXFileCFG(), (XFILECFG*)0x1);
}
}
#endif
