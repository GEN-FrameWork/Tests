/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPVideoFile.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPVIDEOFILE
* @brief      Graphic unit tests for GRPVIDEOFILE class
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

#include "UnitTests_Graphic_GRPVideoFile.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPVideoFile.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_VIDEO_FILE_ACTIVE
namespace TEST_GRPVIDEOFILE
{


TEST(UNITTESTS_GRPVIDEOFILE_CLASSNAME, PropertysDefaultsAndOpenMissing)
{
  GRPVIDEOFILE_PROPERTYS props;

  EXPECT_EQ(props.width, 0u);
  EXPECT_EQ(props.height, 0u);
  EXPECT_EQ(props.nframes, 0u);
  EXPECT_EQ(props.framerate, 0u);

  GRPVIDEOFILE videofile;
  EXPECT_FALSE(videofile.Open(_L("unittests_graphic_missing_no_such.avi")));
}


}
#endif
#endif
#endif
