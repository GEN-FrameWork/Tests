/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRPBitmapSequence.cpp
*
* @class      UNITTESTS_GRAPHIC_GRPBITMAPSEQUENCE
* @brief      Graphic unit tests for GRPBITMAPSEQUENCE class
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

#include "UnitTests_Graphic_GRPBitmapSequence.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPFactory.h"
#include "GRPBitmap.h"
#include "GRPBitmapSequence.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRPBITMAPSEQUENCE
{


TEST(UNITTESTS_GRPBITMAPSEQUENCE_CLASSNAME, AddFramesAndPlayStop)
{
  GRPBITMAPSEQUENCE sequence;

  GRPBITMAP* frame0 = GRPFACTORY::GetInstance().CreateBitmap(4, 4, GRPPROPERTYMODE_32_RGBA_8888);
  GRPBITMAP* frame1 = GRPFACTORY::GetInstance().CreateBitmap(4, 4, GRPPROPERTYMODE_32_RGBA_8888);
  ASSERT_NE(frame0, (GRPBITMAP*)NULL);
  ASSERT_NE(frame1, (GRPBITMAP*)NULL);

  EXPECT_TRUE(sequence.AddFrame(frame0));
  EXPECT_TRUE(sequence.AddFrame(frame1, 1, 2));
  EXPECT_EQ(sequence.GetNFrames(), 2);

  GRPBITMAPFRAME* frame = sequence.GetFrame(1);
  ASSERT_NE(frame, (GRPBITMAPFRAME*)NULL);
  EXPECT_EQ(frame->GetAjustX(), 1);
  EXPECT_EQ(frame->GetAjustY(), 2);

  EXPECT_NE(sequence.Play(1, false, false), (GRPBITMAPFRAME*)NULL);
  EXPECT_TRUE(sequence.IsPlaying());
  EXPECT_TRUE(sequence.Stop());
  EXPECT_FALSE(sequence.IsPlaying());

  EXPECT_TRUE(sequence.DelAllSequence(true));
  EXPECT_EQ(sequence.GetNFrames(), 0);
}


TEST(UNITTESTS_GRPBITMAPSEQUENCE_CLASSNAME, SetLoopsAndCopy)
{
  GRPBITMAPSEQUENCE sequence;

  GRPBITMAP* frame0 = GRPFACTORY::GetInstance().CreateBitmap(2, 2, GRPPROPERTYMODE_32_RGBA_8888);
  ASSERT_NE(frame0, (GRPBITMAP*)NULL);
  EXPECT_TRUE(sequence.AddFrame(frame0));

  EXPECT_TRUE(sequence.SetNLoops(3));
  EXPECT_EQ(sequence.GetNLoops(), 3);

  GRPBITMAPSEQUENCE* copy = sequence.Copy();
  ASSERT_NE(copy, (GRPBITMAPSEQUENCE*)NULL);
  EXPECT_EQ(copy->GetNFrames(), 1);

  EXPECT_TRUE(copy->DelAllSequence(true));
  GEN_DELETE copy;

  EXPECT_TRUE(sequence.DelAllSequence(true));
}


}
#endif
#endif
