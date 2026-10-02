/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Sound_SNDPlayCFG.cpp
*
* @class      UNITTESTS_SOUND_SNDPLAYCFG
* @brief      Sound unit tests for SNDPLAYCFG class
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

#include "UnitTests_Sound_SNDPlayCFG.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "SNDPlayCFG.h"
#include "SNDFactory.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef SND_ACTIVE
namespace TEST_SNDPLAYCFG
{


TEST(UNITTESTS_SNDPLAYCFG_CLASSNAME, DefaultVolumeAndPitchAreUndefined)
{
  SNDPLAYCFG cfg;

  EXPECT_EQ(cfg.GetVolume(), SNDFACTORY_UNDEFINED);
  EXPECT_FLOAT_EQ(cfg.GetPitch(), (float)SNDFACTORY_UNDEFINED);
}


TEST(UNITTESTS_SNDPLAYCFG_CLASSNAME, SetGetVolumePitch)
{
  SNDPLAYCFG cfg;

  cfg.SetVolume(75);
  cfg.SetPitch(1.25f);

  EXPECT_EQ(cfg.GetVolume(), 75);
  EXPECT_FLOAT_EQ(cfg.GetPitch(), 1.25f);
}


TEST(UNITTESTS_SNDPLAYCFG_CLASSNAME, CopyToCopyFromRoundTrip)
{
  SNDPLAYCFG source;
  SNDPLAYCFG via_copyto;
  SNDPLAYCFG via_copyfrom;

  source.SetVolume(40);
  source.SetPitch(0.5f);

  EXPECT_TRUE(source.CopyTo(via_copyto));
  EXPECT_EQ(via_copyto.GetVolume(), 40);
  EXPECT_FLOAT_EQ(via_copyto.GetPitch(), 0.5f);

  EXPECT_TRUE(via_copyfrom.CopyFrom(source));
  EXPECT_EQ(via_copyfrom.GetVolume(), 40);
  EXPECT_FLOAT_EQ(via_copyfrom.GetPitch(), 0.5f);
}


}
#endif
#endif
