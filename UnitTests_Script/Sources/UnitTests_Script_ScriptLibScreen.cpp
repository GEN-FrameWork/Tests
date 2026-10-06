/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibScreen.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBSCREEN
* @brief      Unit tests for SCRIPT_LIB_SCREEN
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
#include "UnitTests_Script_ScriptLibScreen.h"
#include "UnitTests_Script_TestHelpers.h"
#ifdef SCRIPT_LIB_SCREEN_ACTIVE
#include "Script_Lib_Screen.h"
#include "XPath.h"
#include "XProcessManager.h"
#include "XSleep.h"
#include "XSystem.h"
#endif
#include "GEN_Control.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_LIB_SCREEN_ACTIVE)
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBSCREEN, UNITTESTS_SCRIPTLIBSCREEN_CLASSNAME, SCRIPT_LIB_SCREEN, SCRIPT_LIB_NAME_SCREEN, _L("Screen_GetPosX"))

namespace TEST_SCRIPTLIBSCREEN
{
TEST(UNITTESTS_SCRIPTLIBSCREEN_CLASSNAME, StoresBitmapSearchConfiguration)
{
  SCRIPT_LIB_SCREEN library;
  library.BmpFindCFG_SetDiffLimitPercent(9);
  library.BmpFindCFG_SetPixelMargin(4);
  EXPECT_EQ(library.BmpFindCFG_GetDiffLimitPercent(), (XBYTE)9);
  EXPECT_EQ(library.BmpFindCFG_GetPixelMargin(), (XBYTE)4);
}


TEST(UNITTESTS_SCRIPTLIBSCREEN_CLASSNAME, RegistersGetPosXY)
{
  SCRIPT            script;
  SCRIPT_LIB_SCREEN library;

  ASSERT_TRUE(library.AddLibraryFunctions(&script));
  EXPECT_NE(script.GetLibraryFunction(_L("Screen_GetPosX")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("Screen_GetPosY")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("Screen_GetPosXY")), (SCRIPT_LIB_FUNCTION*)NULL);
}


TEST(UNITTESTS_SCRIPTLIBSCREEN_CLASSNAME, GetPosRejectsMissingArguments)
{
  SCRIPT_LIB_SCREEN              library;
  UNITTESTS_SCRIPT_ERRORCAPTURE  script;
  XVARIANT                       result;
  XVECTOR<XVARIANT*>             params;

  Call_Screen_GetPosX(&library, &script, &params, &result);
  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);

  script.ResetLastError();
  Call_Screen_GetPosY(&library, &script, &params, &result);
  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);

  script.ResetLastError();
  Call_Screen_GetPosXY(&library, &script, &params, &result);
  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);
}


TEST(UNITTESTS_SCRIPTLIBSCREEN_CLASSNAME, GetPosYDoesNotDependOnGetPosXGlobalState)
{
  SCRIPT_LIB_SCREEN  library;
  SCRIPT             script;
  XVARIANT           appname(_L("UnitTests_Script_MissingApp_42.exe"));
  XVARIANT           title(_L("MissingWindowTitle_42"));
  XVARIANT           outx(0);
  XVARIANT           outy(0);
  XVARIANT           resultx;
  XVARIANT           resulty;
  XVARIANT           resultxy;
  XVECTOR<XVARIANT*> params;

  params.Add(&appname);
  params.Add(&title);
  params.Add(&outy);

  Call_Screen_GetPosY(&library, &script, &params, &resulty);
  EXPECT_EQ((int)resulty, (int)SCRIPT_LIB_SCREEN_POSSTATUS_NOTFOUND);
  EXPECT_EQ((int)outy, 0);

  params.DeleteAll();
  params.Add(&appname);
  params.Add(&title);
  params.Add(&outx);

  Call_Screen_GetPosX(&library, &script, &params, &resultx);
  EXPECT_EQ((int)resultx, (int)SCRIPT_LIB_SCREEN_POSSTATUS_NOTFOUND);
  EXPECT_EQ((int)outx, 0);

  params.DeleteAll();
  params.Add(&appname);
  params.Add(&title);
  params.Add(&outx);
  params.Add(&outy);

  Call_Screen_GetPosXY(&library, &script, &params, &resultxy);
  EXPECT_EQ((int)resultxy, (int)SCRIPT_LIB_SCREEN_POSSTATUS_NOTFOUND);
  EXPECT_EQ((int)outx, 0);
  EXPECT_EQ((int)outy, 0);
}


#ifdef WINDOWS
TEST(UNITTESTS_SCRIPTLIBSCREEN_CLASSNAME, GetPosXYFindsNotepadWindowOnWindows)
{
  SCRIPT_LIB_SCREEN      library;
  SCRIPT                 script;
  XVARIANT               resultxy;
  XVARIANT               resulty;
  XVARIANT               outx(0);
  XVARIANT               outy(0);
  XVECTOR<XVARIANT*>     params;
  XSTRING                windowtitle;
  SCRIPT_LIB_SCREEN_POS  pos;
  bool                   found = false;

  GEN_XPROCESSMANAGER.Application_Terminate(_L("notepad.exe"));
  GEN_XSLEEP.MilliSeconds(300);

  ASSERT_TRUE(GEN_XPROCESSMANAGER.Application_Execute(_L("C:\\Windows\\System32\\notepad.exe")));

  for(int attempt = 0; attempt < 40; attempt++)
    {
      XVECTOR<XPROCESS*> applist;

      if(GEN_XPROCESSMANAGER.Application_GetRunningList(applist, true))
        {
          for(XDWORD c = 0; c < applist.GetSize(); c++)
            {
              XPROCESS* process = applist.Get(c);
              if(!process) continue;
              if(!process->GetName()) continue;
              if(process->GetName()->Find(_L("notepad.exe"), true) == XSTRING_NOTFOUND) continue;
              if(!process->GetWindowHandle()) continue;
              if(!process->GetWindowTitle()) continue;
              if(process->GetWindowTitle()->IsEmpty()) continue;

              windowtitle = (*process->GetWindowTitle());
              found = true;
              break;
            }
        }

      applist.DeleteContents();
      applist.DeleteAll();

      if(found) break;
      GEN_XSLEEP.MilliSeconds(250);
    }

  if(!found)
    {
      GEN_XPROCESSMANAGER.Application_Terminate(_L("notepad.exe"));
      GTEST_SKIP() << "notepad window not ready";
    }

  {
    XVARIANT appname(_L("notepad.exe"));
    XVARIANT title(windowtitle.Get());

    params.Add(&appname);
    params.Add(&title);

    ASSERT_TRUE(Script_Lib_Screen_ResolvePos(&library, &script, &params, pos, 0));
    EXPECT_TRUE(pos.IsOk());

    params.Add(&outy);
    Call_Screen_GetPosY(&library, &script, &params, &resulty);
    EXPECT_EQ((int)resulty, (int)SCRIPT_LIB_SCREEN_POSSTATUS_OK);
    EXPECT_EQ((int)outy, pos.y);

    params.DeleteAll();
    params.Add(&appname);
    params.Add(&title);
    params.Add(&outx);
    params.Add(&outy);
    Call_Screen_GetPosXY(&library, &script, &params, &resultxy);
  }

  GEN_XPROCESSMANAGER.Application_Terminate(_L("notepad.exe"));

  EXPECT_EQ((int)resultxy, (int)SCRIPT_LIB_SCREEN_POSSTATUS_OK);
  EXPECT_EQ((int)outx, pos.x);
  EXPECT_EQ((int)outy, pos.y);
}
#endif


#ifdef LINUX
TEST(UNITTESTS_SCRIPTLIBSCREEN_CLASSNAME, GetPosAPIsAreIndependentOnLinux)
{
  SCRIPT_LIB_SCREEN  library;
  SCRIPT             script;
  XVARIANT           appname(_L("bash"));
  XVARIANT           title(_L("UnitTests_Script_NoSuchWindow_42"));
  XVARIANT           outx(0);
  XVARIANT           outy(0);
  XVARIANT           resultx;
  XVARIANT           resulty;
  XVARIANT           resultxy;
  XVECTOR<XVARIANT*> params;

  params.Add(&appname);
  params.Add(&title);
  params.Add(&outy);
  Call_Screen_GetPosY(&library, &script, &params, &resulty);

  params.DeleteAll();
  params.Add(&appname);
  params.Add(&title);
  params.Add(&outx);
  Call_Screen_GetPosX(&library, &script, &params, &resultx);

  params.DeleteAll();
  params.Add(&appname);
  params.Add(&title);
  params.Add(&outx);
  params.Add(&outy);
  Call_Screen_GetPosXY(&library, &script, &params, &resultxy);

  EXPECT_EQ((int)resultx, (int)SCRIPT_LIB_SCREEN_POSSTATUS_NOTFOUND);
  EXPECT_EQ((int)resulty, (int)SCRIPT_LIB_SCREEN_POSSTATUS_NOTFOUND);
  EXPECT_EQ((int)resultxy, (int)SCRIPT_LIB_SCREEN_POSSTATUS_NOTFOUND);
  EXPECT_EQ((int)outx, 0);
  EXPECT_EQ((int)outy, 0);
}
#endif

}  // namespace TEST_SCRIPTLIBSCREEN
#endif
