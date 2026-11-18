/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_XUtils_XClipboard.cpp
*
* @class      UNITTESTS_XUTILS_XCLIPBOARD
* @brief      XUtils unit tests for XClipboard class
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
/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Defines.h"


/*---- INCLUDES ------------------------------------------------------------------------------------------------------*/

#include "UnitTests_XUtils_XClipboard.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XClipboard.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/


#ifdef GOOGLETEST_ACTIVE
#ifdef XCLIPBOARD_ACTIVE
namespace TEST_XCLIPBOARD
{


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         static void EnsureXClipboardInstance()
* @brief      Asserts the XCLIPBOARD singleton is already installed by application bootstrap.
* @ingroup    UNIT TEST
*
* --------------------------------------------------------------------------------------------------------------------*/
static void EnsureXClipboardInstance()
{
  ASSERT_TRUE(XCLIPBOARD::GetIsInstanced()) << "XCLIPBOARD must already be installed by "
                                                "this application's own bootstrap before any "
                                                "test runs (XCLIPBOARD_ACTIVE is defined "
                                                "for this build) -- tests must not construct a "
                                                "platform-specific XCLIPBOARD subclass "
                                                "directly.";
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         static void RestoreClipboardText(bool hadprevious, XSTRING& previous)
* @brief      Restores prior clipboard contents after a test mutates the OS clipboard.
* @ingroup    UNIT TEST
*
* --------------------------------------------------------------------------------------------------------------------*/
static void RestoreClipboardText(bool hadprevious, XSTRING& previous)
{
  if(hadprevious)
    {
      GEN_XCLIPBOARD.SetText(previous);
    }
  else
    {
      GEN_XCLIPBOARD.Clear();
    }
}


TEST(UNITTESTS_XCLIPBOARD_CLASSNAME, SetInstanceNull)
{
  EXPECT_FALSE(XCLIPBOARD::SetInstance(NULL));
}


TEST(UNITTESTS_XCLIPBOARD_CLASSNAME, InstanceLifecycle)
{
  EnsureXClipboardInstance();

  XCLIPBOARD* originalinstance = &XCLIPBOARD::GetInstance();

  XCLIPBOARD* testinstance = GEN_NEW XCLIPBOARD();
  EXPECT_NE(testinstance, nullptr);

  EXPECT_TRUE(XCLIPBOARD::SetInstance(testinstance));
  EXPECT_TRUE(XCLIPBOARD::GetIsInstanced());
  EXPECT_EQ(&XCLIPBOARD::GetInstance(), testinstance);

  // Base class stubs return false (platform backends are required for real clipboard I/O).
  XSTRING text;
  text = _L("base");
  EXPECT_FALSE(GEN_XCLIPBOARD.SetText(text));
  EXPECT_FALSE(GEN_XCLIPBOARD.GetText(text));
  EXPECT_FALSE(GEN_XCLIPBOARD.Clear());
  EXPECT_FALSE(GEN_XCLIPBOARD.HasText());

  EXPECT_TRUE(XCLIPBOARD::SetInstance(originalinstance));
  GEN_DELETE testinstance;
}


TEST(UNITTESTS_XCLIPBOARD_CLASSNAME, DelInstanceTwice)
{
  EnsureXClipboardInstance();

  XCLIPBOARD* originalinstance = &XCLIPBOARD::GetInstance();

  XCLIPBOARD* testinstance = GEN_NEW XCLIPBOARD();
  EXPECT_NE(testinstance, nullptr);

  EXPECT_TRUE(XCLIPBOARD::SetInstance(testinstance));

  EXPECT_TRUE(XCLIPBOARD::DelInstance());
  EXPECT_FALSE(XCLIPBOARD::DelInstance());

  EXPECT_TRUE(XCLIPBOARD::SetInstance(originalinstance));
}


TEST(UNITTESTS_XCLIPBOARD_CLASSNAME, SetGetTextRoundTrip)
{
  EnsureXClipboardInstance();

  XSTRING previous;
  bool    hadprevious = GEN_XCLIPBOARD.GetText(previous);

  XSTRING text;
  text = _L("GEN XClipboard unit test");

  if(!GEN_XCLIPBOARD.SetText(text))
    {
      GTEST_SKIP() << "System clipboard unavailable (no display / access denied).";
    }

  EXPECT_TRUE(GEN_XCLIPBOARD.HasText());

  XSTRING got;
  EXPECT_TRUE(GEN_XCLIPBOARD.GetText(got));
  EXPECT_STREQ(got.Get(), text.Get());

  RestoreClipboardText(hadprevious, previous);
}


TEST(UNITTESTS_XCLIPBOARD_CLASSNAME, SetGetTextUnicode)
{
  EnsureXClipboardInstance();

  XSTRING previous;
  bool    hadprevious = GEN_XCLIPBOARD.GetText(previous);

  XSTRING text;
  text = _L("áéíóú ñ © 日本語");

  if(!GEN_XCLIPBOARD.SetText(text))
    {
      GTEST_SKIP() << "System clipboard unavailable (no display / access denied).";
    }

  XSTRING got;
  EXPECT_TRUE(GEN_XCLIPBOARD.GetText(got));
  EXPECT_STREQ(got.Get(), text.Get());

  RestoreClipboardText(hadprevious, previous);
}


TEST(UNITTESTS_XCLIPBOARD_CLASSNAME, SetTextEmpty)
{
  EnsureXClipboardInstance();

  XSTRING previous;
  bool    hadprevious = GEN_XCLIPBOARD.GetText(previous);

  XSTRING marker;
  marker = _L("before-empty");
  if(!GEN_XCLIPBOARD.SetText(marker))
    {
      GTEST_SKIP() << "System clipboard unavailable (no display / access denied).";
    }

  XSTRING empty;
  EXPECT_TRUE(GEN_XCLIPBOARD.SetText(empty));

  XSTRING got;
  if(GEN_XCLIPBOARD.GetText(got))
    {
      EXPECT_TRUE(got.IsEmpty());
    }
  else
    {
      // Some backends treat empty clipboard as "no text".
      EXPECT_FALSE(GEN_XCLIPBOARD.HasText());
    }

  RestoreClipboardText(hadprevious, previous);
}


TEST(UNITTESTS_XCLIPBOARD_CLASSNAME, Clear)
{
  EnsureXClipboardInstance();

  XSTRING previous;
  bool    hadprevious = GEN_XCLIPBOARD.GetText(previous);

  XSTRING text;
  text = _L("clear-me");

  if(!GEN_XCLIPBOARD.SetText(text))
    {
      GTEST_SKIP() << "System clipboard unavailable (no display / access denied).";
    }

  EXPECT_TRUE(GEN_XCLIPBOARD.Clear());

  XSTRING got;
  if(GEN_XCLIPBOARD.GetText(got))
    {
      EXPECT_TRUE(got.IsEmpty());
    }

  RestoreClipboardText(hadprevious, previous);
}


TEST(UNITTESTS_XCLIPBOARD_CLASSNAME, HasTextAfterSet)
{
  EnsureXClipboardInstance();

  XSTRING previous;
  bool    hadprevious = GEN_XCLIPBOARD.GetText(previous);

  XSTRING text;
  text = _L("has-text");

  if(!GEN_XCLIPBOARD.SetText(text))
    {
      GTEST_SKIP() << "System clipboard unavailable (no display / access denied).";
    }

  EXPECT_TRUE(GEN_XCLIPBOARD.HasText());

  RestoreClipboardText(hadprevious, previous);
}


}
#endif // XCLIPBOARD_ACTIVE
#endif // GOOGLETEST_ACTIVE

