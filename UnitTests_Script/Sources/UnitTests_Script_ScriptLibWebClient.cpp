/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibWebClient.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBWEBCLIENT
* @brief      Unit tests for SCRIPT_LIB_WEBCLIENT
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
#include "UnitTests_Script_ScriptLibWebClient.h"
#include "UnitTests_Script_TestHelpers.h"
#ifdef SCRIPT_LIB_WEBCLIENT_ACTIVE
#include "Script_Lib_WebClient.h"
#include "DIOWebClient.h"
#endif
#include "GEN_Control.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_LIB_WEBCLIENT_ACTIVE)
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBWEBCLIENT, UNITTESTS_SCRIPTLIBWEBCLIENT_CLASSNAME, SCRIPT_LIB_WEBCLIENT, SCRIPT_LIB_NAME_WEBCLIENT, _L("WebClient_Get"))

namespace TEST_SCRIPTLIBWEBCLIENT
{
TEST(UNITTESTS_SCRIPTLIBWEBCLIENT_CLASSNAME, RegistersAllWebClientHelpers)
{
  SCRIPT_LIB_WEBCLIENT library;
  SCRIPT script;

  ASSERT_TRUE(library.AddLibraryFunctions(&script));
  EXPECT_NE(script.GetLibraryFunction(_L("WebClient_Get")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("WebClient_Post")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("WebClient_GetToFile")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("WebClient_GetBody")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("WebClient_GetStatus")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("WebClient_GetHeader")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("WebClient_GetLastError")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("WebClient_SetLogin")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(_L("WebClient_DoStopHTTPError")), (SCRIPT_LIB_FUNCTION*)NULL);
}


TEST(UNITTESTS_SCRIPTLIBWEBCLIENT_CLASSNAME, GetRejectsMissingUrl)
{
  UNITTESTS_SCRIPT_ERRORCAPTURE script;
  SCRIPT_LIB_WEBCLIENT library;
  XVARIANT result;
  XVECTOR<XVARIANT*> params;

  Call_WebClient_Get(&library, &script, &params, &result);
  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);
  EXPECT_FALSE((bool)result);
}


TEST(UNITTESTS_SCRIPTLIBWEBCLIENT_CLASSNAME, BodyAndStatusEmptyBeforeRequest)
{
  SCRIPT script;
  SCRIPT_LIB_WEBCLIENT library;
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING body;

  Call_WebClient_GetBody(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(body));
  EXPECT_TRUE(body.IsEmpty());

  Call_WebClient_GetStatus(&library, &script, &params, &result);
  EXPECT_EQ((int)result, 0);
}


TEST(UNITTESTS_SCRIPTLIBWEBCLIENT_CLASSNAME, GetFailsOnUnreachableLocalPort)
{
  SCRIPT script;
  SCRIPT_LIB_WEBCLIENT library;
  XVARIANT url(_L("http://127.0.0.1:1/"));
  XVARIANT timeout(1);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;
  XSTRING body;

  params.Add(&url);
  params.Add(&timeout); // treated as headers string if string — pass empty header then timeout
  // Rebuild: url, headers "", timeout 1
  params.DeleteAll();
  XVARIANT headers(_L(""));
  params.Add(&url);
  params.Add(&headers);
  params.Add(&timeout);

  Call_WebClient_Get(&library, &script, &params, &result);
  EXPECT_FALSE((bool)result);

  Call_WebClient_GetBody(&library, &script, &params, &result);
  EXPECT_TRUE(result.ToString(body));
  EXPECT_TRUE(body.IsEmpty());

  Call_WebClient_GetLastError(&library, &script, &params, &result);
  EXPECT_NE((int)result, (int)DIOWEBCLIENT_ERROR_NONE);
}


TEST(UNITTESTS_SCRIPTLIBWEBCLIENT_CLASSNAME, SetLoginAndDoStopHTTPError)
{
  SCRIPT script;
  SCRIPT_LIB_WEBCLIENT library;
  XVARIANT user(_L("user"));
  XVARIANT password(_L("secret"));
  XVARIANT activate(false);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;

  params.Add(&user);
  params.Add(&password);
  Call_WebClient_SetLogin(&library, &script, &params, &result);
  EXPECT_TRUE((bool)result);

  params.DeleteAll();
  params.Add(&activate);
  Call_WebClient_DoStopHTTPError(&library, &script, &params, &result);
  EXPECT_TRUE((bool)result);
}


TEST(UNITTESTS_SCRIPTLIBWEBCLIENT_CLASSNAME, GetHeaderRequiresName)
{
  UNITTESTS_SCRIPT_ERRORCAPTURE script;
  SCRIPT_LIB_WEBCLIENT library;
  XVARIANT result;
  XVECTOR<XVARIANT*> params;

  Call_WebClient_GetHeader(&library, &script, &params, &result);
  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);
}


TEST(UNITTESTS_SCRIPTLIBWEBCLIENT_CLASSNAME, AutoRegisteredOnScriptWhenFeatureActive)
{
  SCRIPT script;

  ASSERT_TRUE(script.AddInternalLibraries());
  EXPECT_NE(script.GetLibraryFunction(_L("WebClient_Get")), (SCRIPT_LIB_FUNCTION*)NULL);
}
}
#endif
