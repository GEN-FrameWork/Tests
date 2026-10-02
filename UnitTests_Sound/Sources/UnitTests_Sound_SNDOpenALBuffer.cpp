/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Sound_SNDOpenALBuffer.cpp
*
* @class      UNITTESTS_SOUND_SNDOPENALBUFFER
* @brief      Sound unit tests for SNDOPENALBUFFER class
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

#include "UnitTests_Sound_SNDOpenALBuffer.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "SNDOpenALBuffer.h"
#include "XBuffer.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef SND_ACTIVE
namespace TEST_SNDOPENALBUFFER
{


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         TEST(UNITTESTS_SNDOPENALBUFFER_CLASSNAME, GenerateNoteFillsBuffer)
* @brief      GenerateNote(freq,duration,samplerate) fills xbuffer via Add(XWORD) only -- no Create()/Assign(),
*             so no OpenAL device/source is touched. Return value is sample count; GetSize() is bytes.
* @ingroup    UNIT TEST
*
* --------------------------------------------------------------------------------------------------------------------*/
TEST(UNITTESTS_SNDOPENALBUFFER_CLASSNAME, GenerateNoteFillsBuffer)
{
  SNDOPENALBUFFER buffer;

  XDWORD samples = buffer.GenerateNote(440, 1000, 44100);

  EXPECT_EQ(samples, (XDWORD)44100);
  ASSERT_NE(buffer.GetXBuffer(), (XBUFFER*)NULL);
  EXPECT_GT(buffer.GetXBuffer()->GetSize(), (XDWORD)0);
}


TEST(UNITTESTS_SNDOPENALBUFFER_CLASSNAME, GenerateNoteRejectsZeroFrequencyOrDuration)
{
  SNDOPENALBUFFER buffer;

  EXPECT_EQ(buffer.GenerateNote(0, 1000, 44100), (XDWORD)0);
  EXPECT_EQ(buffer.GenerateNote(440, 0, 44100), (XDWORD)0);
}


}
#endif
#endif
