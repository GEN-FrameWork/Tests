/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPVectorFile.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPVECTORFILE
* @brief      Graphic unit tests for GRPVECTORFILE class
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

#include "UnitTests_Graphic_GRPVectorFile.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XString.h"

#include "GRPVectorFile.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_VECTOR_FILE_ACTIVE
namespace TEST_GRPVECTORFILE
{


TEST(UNITTESTS_GRPVECTORFILE_CLASSNAME, CreateInstanceSvgFromContentAndTypeText)
{
  EXPECT_NE(GRPVECTORFILE::GetTypeText(GRPVECTORFILETYPE_UNKNOWN), (XCHAR*)NULL);
  EXPECT_EQ(XSTRING(GRPVECTORFILE::GetTypeText(GRPVECTORFILETYPE_UNKNOWN)).Compare(_L("Unknown")), 0);

  #ifdef GRP_VECTOR_FILE_SVG_ACTIVE
  EXPECT_EQ(XSTRING(GRPVECTORFILE::GetTypeText(GRPVECTORFILETYPE_SVG)).Compare(_L("SVG")), 0);

  XSTRING content;
  content  = _L("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"10\" height=\"10\">");
  content += _L("<rect x=\"0\" y=\"0\" width=\"10\" height=\"10\" fill=\"#00FF00\"/>");
  content += _L("</svg>");

  GRPVECTORFILE* vectorfile = GRPVECTORFILE::CreateInstance(GRPVECTORFILETYPE_SVG, content);
  ASSERT_NE(vectorfile, (GRPVECTORFILE*)NULL);
  EXPECT_EQ(vectorfile->GetType(), GRPVECTORFILETYPE_SVG);

  delete vectorfile;
  #endif

  #ifdef GRP_VECTOR_FILE_DXF_ACTIVE
  EXPECT_EQ(XSTRING(GRPVECTORFILE::GetTypeText(GRPVECTORFILETYPE_DXF)).Compare(_L("DXF")), 0);

  GRPVECTORFILE* dxfempty = GRPVECTORFILE::CreateInstance(GRPVECTORFILETYPE_DXF);
  ASSERT_NE(dxfempty, (GRPVECTORFILE*)NULL);
  EXPECT_EQ(dxfempty->GetType(), GRPVECTORFILETYPE_DXF);
  delete dxfempty;
  #endif
}


}
#endif
#endif
#endif
