/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOWebHeader.cpp
*
* @class      UNITTESTS_DATAIO_DIOWEBHEADER
* @brief      DataIO unit tests for DIOWEBHEADER class
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

#include "DIOWebHeader.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#if defined(DIO_WEBCLIENT_ACTIVE) || defined(DIO_WEBSERVER_ACTIVE)
namespace TEST_DIOWEBHEADER
{


TEST(DIOWEBHEADER, AddLinesGetFieldAndDelete)
{
  DIOWEBHEADER header;
  XSTRING      line1(__L("HTTP/1.1 200 OK"));
  XSTRING      line2;

  line2  = __L("Content-Type: text/plain");
  EXPECT_TRUE(header.AddLine(line1));
  EXPECT_TRUE(header.AddLine(line2));
  EXPECT_TRUE(header.AddLine(__L("Content-Length: 4")));

  ASSERT_NE(header.GetLines(), (XVECTOR<XSTRING*>*)NULL);
  EXPECT_EQ(header.GetLines()->GetSize(), (XDWORD)3);

  XCHAR* value = header.GetFieldValue(__L("Content-Length"));
  ASSERT_NE(value, (XCHAR*)NULL);
  EXPECT_EQ(XSTRING(value).Compare(__L("4")), 0);

  XSTRING all;
  EXPECT_TRUE(header.GetLines(all));
  EXPECT_FALSE(all.IsEmpty());

  EXPECT_TRUE(header.DeleteAllLines());
  EXPECT_EQ(header.GetLines()->GetSize(), (XDWORD)0);
}


}
#endif
#endif
#endif
