/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibSystem.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBSYSTEM
* @brief      Unit tests for SCRIPT_LIB_SYSTEM
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
#include "UnitTests_Script_ScriptLibSystem.h"
#include "UnitTests_Script_TestHelpers.h"
#ifdef SCRIPT_LIB_SYSTEM_ACTIVE
#include "Script_Lib_System.h"
#include "XSystem.h"
#endif
#include "GEN_Control.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_LIB_SYSTEM_ACTIVE)
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBSYSTEM, UNITTESTS_SCRIPTLIBSYSTEM_CLASSNAME, SCRIPT_LIB_SYSTEM, SCRIPT_LIB_SYSTEM_NAME, __L("System_GetType"))

namespace TEST_SCRIPTLIBSYSTEM
{
TEST(UNITTESTS_SCRIPTLIBSYSTEM_CLASSNAME, RegistersPlatformAdaptationFunctions)
{
  SCRIPT            script;
  SCRIPT_LIB_SYSTEM library;

  ASSERT_TRUE(library.AddLibraryFunctions(&script));
  EXPECT_NE(script.GetLibraryFunction(__L("System_GetType")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_GetOperativeSystemID")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_GetHardwareType")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_IsWindows")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_IsLinux")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_IsAndroid")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_GetLanguageSO")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_GetUser")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_GetDomain")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_GetFreeMemoryPercent")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_GetPathExecApplication")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("System_GetEnviromentVar")), (SCRIPT_LIB_FUNCTION*)NULL);
}


TEST(UNITTESTS_SCRIPTLIBSYSTEM_CLASSNAME, GetTypeMatchesPlatform)
{
  SCRIPT_LIB_SYSTEM  library;
  SCRIPT             script;
  XVARIANT           result;
  XVECTOR<XVARIANT*> params;
  XSTRING            type;

  Call_System_GetType(&library, &script, &params, &result);
  ASSERT_TRUE(result.ToString(type));

  switch(GEN_XSYSTEM.GetPlatform())
    {
      case XSYSTEM_PLATFORM_WINDOWS         : EXPECT_EQ(type.Compare(__L("Windows")), 0);         break;
      case XSYSTEM_PLATFORM_LINUX           : EXPECT_EQ(type.Compare(__L("Linux")), 0);           break;
      case XSYSTEM_PLATFORM_LINUX_EMBEDDED  : EXPECT_EQ(type.Compare(__L("LinuxEmbedded")), 0);  break;
      case XSYSTEM_PLATFORM_ANDROID         : EXPECT_EQ(type.Compare(__L("Android")), 0);         break;
      case XSYSTEM_PLATFORM_STM32           : EXPECT_EQ(type.Compare(__L("STM32")), 0);           break;
      case XSYSTEM_PLATFORM_ESP32           : EXPECT_EQ(type.Compare(__L("ESP32")), 0);           break;
      case XSYSTEM_PLATFORM_SAMD5XE5X       : EXPECT_EQ(type.Compare(__L("SAMD5xE5x")), 0);       break;
                      default               : EXPECT_EQ(type.GetSize(), 0);                       break;
    }
}


TEST(UNITTESTS_SCRIPTLIBSYSTEM_CLASSNAME, IsWindowsAndIsLinuxAreExclusiveOnDesktop)
{
  SCRIPT_LIB_SYSTEM  library;
  SCRIPT             script;
  XVARIANT           iswindows;
  XVARIANT           islinux;
  XVECTOR<XVARIANT*> params;

  Call_System_IsWindows(&library, &script, &params, &iswindows);
  Call_System_IsLinux(&library, &script, &params, &islinux);

  switch(GEN_XSYSTEM.GetPlatform())
    {
      case XSYSTEM_PLATFORM_WINDOWS         : EXPECT_TRUE((bool)iswindows);
                                              EXPECT_FALSE((bool)islinux);
                                              break;

      case XSYSTEM_PLATFORM_LINUX           :
      case XSYSTEM_PLATFORM_LINUX_EMBEDDED  : EXPECT_FALSE((bool)iswindows);
                                              EXPECT_TRUE((bool)islinux);
                                              break;

                      default               : break;
    }
}


TEST(UNITTESTS_SCRIPTLIBSYSTEM_CLASSNAME, GetHardwareTypeReturnsNonEmpty)
{
  SCRIPT_LIB_SYSTEM  library;
  SCRIPT             script;
  XVARIANT           result;
  XVECTOR<XVARIANT*> params;
  XSTRING            hardware;

  Call_System_GetHardwareType(&library, &script, &params, &result);
  ASSERT_TRUE(result.ToString(hardware));
  EXPECT_GT(hardware.GetSize(), 0);
}


TEST(UNITTESTS_SCRIPTLIBSYSTEM_CLASSNAME, GetFreeMemoryPercentInRange)
{
  SCRIPT_LIB_SYSTEM  library;
  SCRIPT             script;
  XVARIANT           result;
  XVECTOR<XVARIANT*> params;
  int                percent;

  Call_System_GetFreeMemoryPercent(&library, &script, &params, &result);
  percent = (int)result;
  EXPECT_GE(percent, 0);
  EXPECT_LE(percent, 100);
}


TEST(UNITTESTS_SCRIPTLIBSYSTEM_CLASSNAME, GetPathExecApplicationRejectsMissingArgument)
{
  SCRIPT_LIB_SYSTEM              library;
  UNITTESTS_SCRIPT_ERRORCAPTURE  script;
  XVARIANT                       result;
  XVECTOR<XVARIANT*>             params;

  Call_System_GetPathExecApplication(&library, &script, &params, &result);
  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);
}


TEST(UNITTESTS_SCRIPTLIBSYSTEM_CLASSNAME, GetEnviromentVarRejectsMissingArgument)
{
  SCRIPT_LIB_SYSTEM              library;
  UNITTESTS_SCRIPT_ERRORCAPTURE  script;
  XVARIANT                       result;
  XVECTOR<XVARIANT*>             params;

  Call_System_GetEnviromentVar(&library, &script, &params, &result);
  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);
}
}
#endif
