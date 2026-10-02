/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPVideoFileAVI.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPVIDEOFILEAVI
* @brief      Graphic unit tests for GRPVIDEOFILEAVI class
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

#include "UnitTests_Graphic_GRPVideoFileAVI.h"
#include "UnitTests_Graphic_Helper.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include <string.h>

#include "GRPVideoFileAVI.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
#ifdef GRP_VIDEO_FILE_AVI_ACTIVE
namespace TEST_GRPVIDEOFILEAVI
{


TEST(UNITTESTS_GRPVIDEOFILEAVI_CLASSNAME, CreateAddFrameCloseOpenGetDataFrame)
{
  XPATH xpath;
  ASSERT_TRUE(UNITTESTS_GRAPHIC_HELPER::BuildAssetPath(xpath, __L("unittests_graphic_tiny.avi")));
  UNITTESTS_GRAPHIC_HELPER::EraseAsset(xpath);

  GRPVIDEOFILE_PROPERTYS props;
  props.width     = 4;
  props.height    = 4;
  props.framerate = 25;

  GRPVIDEOFILEAVI avi;
  bool            created = avi.Create(xpath.Get(), props);

  if(created)
    {
      XDWORD framesize = props.width * props.height * 3;
      XBYTE* frame     = GEN_NEW XBYTE[framesize];
      ASSERT_NE(frame, (XBYTE*)NULL);
      memset(frame, 0x7F, framesize);

      EXPECT_TRUE(avi.AddFrame(frame, framesize));
      EXPECT_TRUE(avi.Close());

      GEN_DELETE_ARRAY frame;

      GRPVIDEOFILEAVI reader;
      ASSERT_TRUE(reader.Open(xpath.Get()));

      XDWORD sizeframe = 0;
      XBYTE* data      = reader.GetDataFrame(0, sizeframe);
      EXPECT_NE(data, (XBYTE*)NULL);
      EXPECT_GT(sizeframe, 0u);
      if(data) GEN_DELETE_ARRAY data;

      EXPECT_TRUE(reader.Close());
    }
   else
    {
      EXPECT_FALSE(avi.Open(__L("unittests_graphic_missing_no_such.avi")));
      EXPECT_TRUE(avi.Close());
    }

  UNITTESTS_GRAPHIC_HELPER::EraseAsset(xpath);
}


TEST(UNITTESTS_GRPVIDEOFILEAVI_CLASSNAME, OpenMissingFalse)
{
  GRPVIDEOFILEAVI avi;
  EXPECT_FALSE(avi.Open(__L("unittests_graphic_missing_no_such.avi")));
}


}
#endif
#endif
#endif
