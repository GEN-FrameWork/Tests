/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOURL.cpp
*
* @class      UNITTESTS_DATAIO_DIOURL
* @brief      DataIO unit tests for DIOURL class
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

#include "UnitTests_DataIO_Helper.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XString.h"

#include "DIOURL.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
namespace TEST_DIOURL
{


TEST(DIOURL, ConstructFromLiteralAndIsAURL)
{
  DIOURL url(_L("http://example.local/path/file.txt"));

  EXPECT_FALSE(url.IsEmpty());
  EXPECT_TRUE(url.HaveHTTPID());
}


TEST(DIOURL, AddDeleteHTTPID)
{
  DIOURL url(_L("example.local/index.html"));

  EXPECT_FALSE(url.HaveHTTPID());
  EXPECT_TRUE(url.AddHTTPID());
  EXPECT_TRUE(url.HaveHTTPID());
  EXPECT_TRUE(url.DeleteHTTPID());
  EXPECT_FALSE(url.HaveHTTPID());
}


TEST(DIOURL, GetExtensionAndFileName)
{
  DIOURL  url(_L("http://host/dir/page.html"));
  XSTRING extension;
  XSTRING filename;

  EXPECT_TRUE(url.GetExtension(extension));
  EXPECT_EQ(extension.Compare(_L(".html"), true), 0);
  EXPECT_TRUE(url.GetFileName(filename));
  EXPECT_EQ(filename.Compare(_L("page.html"), true), 0);
}


TEST(DIOURL, HostGetTypeIPv4AndDNS)
{
  EXPECT_EQ(DIOURL::Host_GetType(_L("192.168.0.1")), DIOURL_HOSTTYPE_IPV4);
  EXPECT_EQ(DIOURL::Host_GetType(_L("example.local")), DIOURL_HOSTTYPE_DNS);
}


TEST(DIOURL, SlashNormalize)
{
  DIOURL url(_L("http://host/path"));

  EXPECT_TRUE(url.Slash_Add());
  EXPECT_TRUE(url.Slash_Normalize());
}


TEST(DIOURL, DecodeUnsafeCharsPercent20ToSpace)
{
  DIOURL  url(_L("Hello%20world"));
  XSTRING decoded;

  ASSERT_TRUE(url.DecodeUnsafeCharsToString(decoded));
  EXPECT_EQ(decoded.Compare(_L("Hello world")), 0);
}


TEST(DIOURL, DecodeUnsafeCharsLeavesPrintfMasksUntouched)
{
  DIOURL  url(_L("Error%20%s%20code%20%d"));
  XSTRING decoded;

  ASSERT_TRUE(url.DecodeUnsafeCharsToString(decoded));
  // %s / %d are not valid %HH escapes → preserved; %20 → space
  EXPECT_EQ(decoded.Compare(_L("Error %s code %d")), 0);
}


TEST(DIOURL, DecodeUnsafeCharsDecodesAmbiguousPercent2dAsHex)
{
  DIOURL  url(_L("count%2d"));
  XSTRING decoded;

  ASSERT_TRUE(url.DecodeUnsafeCharsToString(decoded));
  // Pure URL decode: %2d is valid hex for '-' (printf mask protection lives in
  // DIOSCRAPERWEBTRANSLATION::DecodeTranslationText, not in DIOURL).
  EXPECT_EQ(decoded.Compare(_L("count-")), 0);
}


TEST(DIOURL, DecodeUnsafeCharsRejectsPartialPercentAtEnd)
{
  DIOURL  url(_L("end%"));
  XSTRING decoded;

  ASSERT_TRUE(url.DecodeUnsafeCharsToString(decoded));
  EXPECT_EQ(decoded.Compare(_L("end%")), 0);
}


}
#endif
#endif
