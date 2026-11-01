/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_UI_Element_Console.cpp
*
* @class      UNITTESTS_GRAPHIC_UI_ELEMENT_CONSOLE
* @brief      Graphic unit tests for UI_ELEMENT_CONSOLE
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

#include "UnitTests_Graphic_UI_Element_Console.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#ifdef USERINTERFACE_ACTIVE
#include "UI_Color.h"
#include "UI_Element_Console.h"
#endif


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef USERINTERFACE_ACTIVE
namespace TEST_UI_ELEMENT_CONSOLE
{


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, DefaultTypeDefaultsAndEmptyBuffer)
{
  UI_ELEMENT_CONSOLE console;

  EXPECT_EQ(console.GetType(), UI_ELEMENT_TYPE_CONSOLE);
  ASSERT_NE(console.GetTypeString(), (XSTRING*)NULL);
  EXPECT_EQ(console.GetTypeString()->Compare(_L("console"), true), 0);

  EXPECT_EQ(console.GetSizeFont(), (XDWORD)0);
  EXPECT_EQ(console.GetLineSpacing(), (XDWORD)UI_ELEMENT_CONSOLE_DEFAULT_LINESPACING);
  EXPECT_TRUE(console.IsWordWrap());
  EXPECT_EQ(console.GetMaxLines(), (XDWORD)UI_ELEMENT_CONSOLE_DEFAULT_MAXLINES);
  EXPECT_EQ(console.GetMaxLinesOff(), (XDWORD)UI_ELEMENT_CONSOLE_DEFAULT_MAXLINES_OFF);
  EXPECT_TRUE(console.GetAutoscroll());
  EXPECT_EQ(console.GetContentHeight(), 0.0);
  EXPECT_EQ(console.GetLineCount(), (XDWORD)0);
  EXPECT_EQ(console.GetLine(0), (UI_ELEMENT_CONSOLE_LINE*)NULL);
  EXPECT_FALSE(console.ConsumeAutoscrollPending());

  XSTRING emptytext;
  ASSERT_TRUE(console.GetText(emptytext));
  EXPECT_TRUE(emptytext.IsEmpty());
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, PrintAddsBlackLineAndSetsAutoscrollPending)
{
  UI_ELEMENT_CONSOLE console;

  ASSERT_TRUE(console.Print(_L("hello")));
  ASSERT_EQ(console.GetLineCount(), (XDWORD)1);

  UI_ELEMENT_CONSOLE_LINE* line = console.GetLine(0);
  ASSERT_NE(line, (UI_ELEMENT_CONSOLE_LINE*)NULL);
  EXPECT_EQ(line->text.Compare(_L("hello"), true), 0);
  EXPECT_EQ(line->colorindex, (XBYTE)UI_ELEMENT_CONSOLE_COLOR_BLACK);
  EXPECT_FALSE(line->rgb.IsValid());

  EXPECT_TRUE(console.ConsumeAutoscrollPending());
  EXPECT_FALSE(console.ConsumeAutoscrollPending());
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, PrintColorStoresIndex)
{
  UI_ELEMENT_CONSOLE console;

  ASSERT_TRUE(console.PrintColor(UI_ELEMENT_CONSOLE_COLOR_RED, _L("alert")));
  ASSERT_EQ(console.GetLineCount(), (XDWORD)1);

  UI_ELEMENT_CONSOLE_LINE* line = console.GetLine(0);
  ASSERT_NE(line, (UI_ELEMENT_CONSOLE_LINE*)NULL);
  EXPECT_EQ(line->text.Compare(_L("alert"), true), 0);
  EXPECT_EQ(line->colorindex, (XBYTE)UI_ELEMENT_CONSOLE_COLOR_RED);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, PrintfAndPrintColorfFormatPayload)
{
  UI_ELEMENT_CONSOLE console;

  ASSERT_TRUE(console.Printf(_L("n=%d"), 7));
  ASSERT_TRUE(console.PrintColorf(UI_ELEMENT_CONSOLE_COLOR_GREEN, _L("%s-%d"), _L("ok"), 3));
  ASSERT_EQ(console.GetLineCount(), (XDWORD)2);

  EXPECT_EQ(console.GetLine(0)->text.Compare(_L("n=7"), true), 0);
  EXPECT_EQ(console.GetLine(0)->colorindex, (XBYTE)UI_ELEMENT_CONSOLE_COLOR_BLACK);

  EXPECT_EQ(console.GetLine(1)->text.Compare(_L("ok-3"), true), 0);
  EXPECT_EQ(console.GetLine(1)->colorindex, (XBYTE)UI_ELEMENT_CONSOLE_COLOR_GREEN);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, PrintRGBUsesRgbOverrideIndex)
{
  UI_ELEMENT_CONSOLE console;
  UI_COLOR           color;

  color.SetRed(10);
  color.SetGreen(20);
  color.SetBlue(30);
  color.SetAlpha(255);
  color.SetValid(true);

  ASSERT_TRUE(console.PrintRGB(color, _L("rgb")));
  ASSERT_EQ(console.GetLineCount(), (XDWORD)1);

  UI_ELEMENT_CONSOLE_LINE* line = console.GetLine(0);
  ASSERT_NE(line, (UI_ELEMENT_CONSOLE_LINE*)NULL);
  EXPECT_EQ(line->colorindex, (XBYTE)UI_ELEMENT_CONSOLE_COLOR_RGB);
  EXPECT_TRUE(line->rgb.IsValid());
  EXPECT_EQ(line->rgb.GetRed(), 10);
  EXPECT_EQ(line->rgb.GetGreen(), 20);
  EXPECT_EQ(line->rgb.GetBlue(), 30);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, MultilinePayloadSplitsWithoutTrailingEmpty)
{
  UI_ELEMENT_CONSOLE console;

  ASSERT_TRUE(console.Print(_L("a\nb\r\nc\n")));
  ASSERT_EQ(console.GetLineCount(), (XDWORD)3);

  EXPECT_EQ(console.GetLine(0)->text.Compare(_L("a"), true), 0);
  EXPECT_EQ(console.GetLine(1)->text.Compare(_L("b"), true), 0);
  EXPECT_EQ(console.GetLine(2)->text.Compare(_L("c"), true), 0);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, EmptyStringAddsSingleEmptyLine)
{
  UI_ELEMENT_CONSOLE console;

  ASSERT_TRUE(console.Print(_L("")));
  ASSERT_EQ(console.GetLineCount(), (XDWORD)1);
  EXPECT_TRUE(console.GetLine(0)->text.IsEmpty());
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, ClearEmptiesBufferAndContentHeight)
{
  UI_ELEMENT_CONSOLE console;

  ASSERT_TRUE(console.Print(_L("one")));
  console.SetContentHeight(42.0);
  ASSERT_EQ(console.GetLineCount(), (XDWORD)1);

  ASSERT_TRUE(console.Clear());
  EXPECT_EQ(console.GetLineCount(), (XDWORD)0);
  EXPECT_EQ(console.GetContentHeight(), 0.0);
  EXPECT_EQ(console.GetLine(0), (UI_ELEMENT_CONSOLE_LINE*)NULL);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, MaxLinesTrimsOldestEntries)
{
  UI_ELEMENT_CONSOLE console;

  console.SetMaxLines(2);
  EXPECT_EQ(console.GetMaxLines(), (XDWORD)2);

  ASSERT_TRUE(console.Print(_L("1")));
  ASSERT_TRUE(console.Print(_L("2")));
  ASSERT_TRUE(console.Print(_L("3")));

  ASSERT_EQ(console.GetLineCount(), (XDWORD)2);
  EXPECT_EQ(console.GetLine(0)->text.Compare(_L("2"), true), 0);
  EXPECT_EQ(console.GetLine(1)->text.Compare(_L("3"), true), 0);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, SetMaxLinesClampsToOneAndTrimsExisting)
{
  UI_ELEMENT_CONSOLE console;

  ASSERT_TRUE(console.Print(_L("a")));
  ASSERT_TRUE(console.Print(_L("b")));
  ASSERT_TRUE(console.Print(_L("c")));

  console.SetMaxLines(0);
  EXPECT_EQ(console.GetMaxLines(), (XDWORD)1);
  ASSERT_EQ(console.GetLineCount(), (XDWORD)1);
  EXPECT_EQ(console.GetLine(0)->text.Compare(_L("c"), true), 0);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, AutoscrollOffDoesNotSetPending)
{
  UI_ELEMENT_CONSOLE console;

  console.SetAutoscroll(false);
  ASSERT_TRUE(console.Print(_L("quiet")));
  EXPECT_FALSE(console.ConsumeAutoscrollPending());
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, PrintNullOrEmptyMaskFails)
{
  UI_ELEMENT_CONSOLE console;

  EXPECT_FALSE(console.Print(NULL));
  EXPECT_FALSE(console.Printf(NULL));
  EXPECT_FALSE(console.PrintColor(UI_ELEMENT_CONSOLE_COLOR_BLUE, NULL));
  EXPECT_FALSE(console.PrintColorf(UI_ELEMENT_CONSOLE_COLOR_BLUE, NULL));
  EXPECT_EQ(console.GetLineCount(), (XDWORD)0);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, PropertySettersRoundTrip)
{
  UI_ELEMENT_CONSOLE console;

  console.SetSizeFont(14);
  console.SetLineSpacing(4);
  console.SetWordWrap(false);
  console.SetContentHeight(99.5);

  EXPECT_EQ(console.GetSizeFont(), (XDWORD)14);
  EXPECT_EQ(console.GetLineSpacing(), (XDWORD)4);
  EXPECT_FALSE(console.IsWordWrap());
  EXPECT_EQ(console.GetContentHeight(), 99.5);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, GetTextExportsJoinedLines)
{
  UI_ELEMENT_CONSOLE console;
  XSTRING            text;

  ASSERT_TRUE(console.Print(_L("one")));
  ASSERT_TRUE(console.Print(_L("two")));
  ASSERT_TRUE(console.Print(_L("three")));
  ASSERT_TRUE(console.GetText(text));
  EXPECT_EQ(text.Compare(_L("one\ntwo\nthree"), true), 0);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, FindLineByIDAndSubstring)
{
  UI_ELEMENT_CONSOLE console;

  ASSERT_TRUE(console.Print(_L("alpha")));
  ASSERT_TRUE(console.Print(_L("bravo")));
  ASSERT_TRUE(console.Print(_L("charlie")));

  XDWORD id0 = console.GetLine(0)->id;
  XDWORD id2 = console.GetLine(2)->id;

  EXPECT_EQ(console.FindLineByID(id0), 0);
  EXPECT_EQ(console.FindLineByID(id2), 2);
  EXPECT_EQ(console.FindLineByID(0), NOTFOUND);
  EXPECT_EQ(console.FindLineByID(999999), NOTFOUND);

  EXPECT_EQ(console.FindLine(_L("avo"), true), 1);
  EXPECT_EQ(console.FindLine(_L("CHARLIE"), true), 2);
  EXPECT_EQ(console.FindLine(_L("CHARLIE"), false), NOTFOUND);
  EXPECT_EQ(console.FindLine(_L("avo"), true, 2), NOTFOUND);
  EXPECT_EQ(console.FindLine(NULL), NOTFOUND);
}


TEST(UNITTESTS_UI_ELEMENT_CONSOLE_CLASSNAME, MaxLinesOffCapsWhileAutoscrollOff)
{
  UI_ELEMENT_CONSOLE console;

  console.SetMaxLines(2);
  console.SetMaxLinesOff(3);
  EXPECT_EQ(console.GetMaxLines(), (XDWORD)2);
  EXPECT_EQ(console.GetMaxLinesOff(), (XDWORD)3);

  console.SetAutoscroll(false);
  ASSERT_TRUE(console.Print(_L("1")));
  ASSERT_TRUE(console.Print(_L("2")));
  ASSERT_TRUE(console.Print(_L("3")));
  ASSERT_TRUE(console.Print(_L("4")));

  ASSERT_EQ(console.GetLineCount(), (XDWORD)3);
  EXPECT_EQ(console.GetLine(0)->text.Compare(_L("2"), true), 0);
  EXPECT_EQ(console.GetLine(2)->text.Compare(_L("4"), true), 0);

  console.SetAutoscroll(true);
  ASSERT_EQ(console.GetLineCount(), (XDWORD)2);
  EXPECT_EQ(console.GetLine(0)->text.Compare(_L("3"), true), 0);
  EXPECT_EQ(console.GetLine(1)->text.Compare(_L("4"), true), 0);
}


} // namespace TEST_UI_ELEMENT_CONSOLE
#endif // USERINTERFACE_ACTIVE
#endif // GOOGLETEST_ACTIVE
