/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPVectorFileSVG.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPVECTORFILESVG
* @brief      Graphic unit tests for GRPVECTORFILESVG class
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

#include "UnitTests_Graphic_GRPVectorFileSVG.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XString.h"

#include "GRPVectorFileSVG.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_VECTOR_FILE_SVG_ACTIVE
namespace TEST_GRPVECTORFILESVG
{


TEST(UNITTESTS_GRPVECTORFILESVG_CLASSNAME, LoadMinimalSvgOkAndGetRoot)
{
  XSTRING content;
  content  = _L("<svg xmlns=\"http://www.w3.org/2000/svg\" width=\"32\" height=\"32\">");
  content += _L("<rect x=\"0\" y=\"0\" width=\"32\" height=\"32\" fill=\"#0000FF\"/>");
  content += _L("</svg>");

  GRPVECTORFILESVG svg;
  EXPECT_EQ(svg.Load(content), GRPVECTORFILERESULT_OK);
  EXPECT_NE(svg.GetRoot(), (GRPVECTORFILESVGOBJ*)NULL);
}


TEST(UNITTESTS_GRPVECTORFILESVG_CLASSNAME, LoadBadContentNotOk)
{
  XSTRING content(_L("not-an-svg-document"));

  GRPVECTORFILESVG svg;
  EXPECT_NE(svg.Load(content), GRPVECTORFILERESULT_OK);
}


}
#endif
#endif
#endif
