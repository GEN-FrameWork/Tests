/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibWindow.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBWINDOW
* @brief      Unit tests for SCRIPT_LIB_WINDOW
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
#include "UnitTests_Script_ScriptLibWindow.h"
#include "UnitTests_Script_TestHelpers.h"
#ifdef SCRIPT_LIB_WINDOW_ACTIVE
#include "Script_Lib_Window.h"
#endif
#include "GEN_Control.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_LIB_WINDOW_ACTIVE)
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBWINDOW, UNITTESTS_SCRIPTLIBWINDOW_CLASSNAME, SCRIPT_LIB_WINDOW, SCRIPT_LIB_NAME_WINDOW, __L("Window_GetPosX"))

namespace TEST_SCRIPTLIBWINDOW
{
TEST(UNITTESTS_SCRIPTLIBWINDOW_CLASSNAME, StoresBitmapSearchConfiguration)
{
  SCRIPT_LIB_WINDOW library;
  library.BmpFindCFG_SetDiffLimitPercent(9);
  library.BmpFindCFG_SetPixelMargin(4);
  EXPECT_EQ(library.BmpFindCFG_GetDiffLimitPercent(), (XBYTE)9);
  EXPECT_EQ(library.BmpFindCFG_GetPixelMargin(), (XBYTE)4);
}
}
#endif
