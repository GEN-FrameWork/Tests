/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOWebServer_QueryStrings.cpp
*
* @class      UNITTESTS_DATAIO_DIOWEBSERVER_QUERYSTRINGS
* @brief      DataIO unit tests for DIOWEBSERVER_QUERYSTRINGS class
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

#include "DIOWebServer_QueryStrings.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_WEBSERVER_ACTIVE
namespace TEST_DIOWEBSERVER_QUERYSTRINGS
{


TEST(DIOWEBSERVER_QUERYSTRINGS, AddGetDelParam)
{
  DIOWEBSERVER_QUERYSTRINGS qs;

  EXPECT_TRUE(qs.AddParam(__L("name"), __L("value")));
  EXPECT_TRUE(qs.AddParam(__L("n"), 42));
  EXPECT_EQ(qs.GetNParams(), 2);

  XSTRING* value = qs.GetParam(__L("name"));
  ASSERT_NE(value, (XSTRING*)NULL);
  EXPECT_EQ(value->Compare(__L("value")), 0);

  EXPECT_TRUE(qs.DelParam(__L("name")));
  EXPECT_EQ(qs.GetNParams(), 1);
  EXPECT_TRUE(qs.DelAllParam());
  EXPECT_EQ(qs.GetNParams(), 0);
}


TEST(DIOWEBSERVER_QUERYSTRINGS, ParseFromLocalURLString)
{
  DIOWEBSERVER_QUERYSTRINGS qs;
  XSTRING                   url(__L("http://localhost/page?alpha=1&beta=two"));

  EXPECT_EQ(qs.GetParamsFromURL(url), 2);
  ASSERT_NE(qs.GetParam(__L("alpha")), (XSTRING*)NULL);
  EXPECT_EQ(qs.GetParam(__L("alpha"))->Compare(__L("1")), 0);
  ASSERT_NE(qs.GetParam(__L("beta")), (XSTRING*)NULL);
  EXPECT_EQ(qs.GetParam(__L("beta"))->Compare(__L("two")), 0);

  XSTRING built;
  EXPECT_TRUE(qs.CreateURLFromParams(built));
  EXPECT_FALSE(built.IsEmpty());
}


}
#endif
#endif
#endif
