/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Sound_SNDFileWAV.cpp
*
* @class      UNITTESTS_SOUND_SNDFILEWAV
* @brief      Sound unit tests for SNDFILEWAV class
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

#include "UnitTests_Sound_SNDFileWAV.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XFactory.h"
#include "XFile.h"
#include "XPath.h"

#include "SNDFile.h"
#include "UnitTests_Sound_Helper.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef SND_ACTIVE
namespace TEST_SNDFILEWAV
{


static void RemoveIfExists(XPATH& xpath)
{
  XFILE* xfile = GEN_XFACTORY.Create_File();
  if(xfile)
    {
      if(xfile->Exist(xpath)) xfile->Erase(xpath);
      GEN_XFACTORY.Delete_File(xfile);
    }
}


TEST(UNITTESTS_SNDFILEWAV_CLASSNAME, LoadTinyWavSucceeds)
{
  XPATH xpath;

  ASSERT_TRUE(UNITTESTS_SOUND_HELPER::BuildAssetPath(xpath, _L("unittests_sound_tiny.wav")));
  RemoveIfExists(xpath);

  ASSERT_TRUE(UNITTESTS_SOUND_HELPER::WriteTinyPcmWav(xpath.Get()));

  // SNDFILE::Create() requires the file to exist and calls LoadFile() internally;
  // a non-NULL result means LoadFile succeeded for this tiny PCM WAV.
  SNDFILE* sndfile = SNDFILE::Create(xpath);
  ASSERT_NE(sndfile, (SNDFILE*)NULL);

  EXPECT_GE(sndfile->GetChannels(), (XWORD)1);
  EXPECT_GT(sndfile->GetSampleRate(), (XDWORD)0);

  GEN_DELETE sndfile;
  RemoveIfExists(xpath);
}


TEST(UNITTESTS_SNDFILEWAV_CLASSNAME, LoadCorruptOrMissingFails)
{
  XPATH missing;

  ASSERT_TRUE(UNITTESTS_SOUND_HELPER::BuildAssetPath(missing, _L("unittests_sound_corrupt_missing.wav")));
  EXPECT_EQ(SNDFILE::Create(missing), (SNDFILE*)NULL);

  XPATH corrupt;

  ASSERT_TRUE(UNITTESTS_SOUND_HELPER::BuildAssetPath(corrupt, _L("unittests_sound_corrupt.wav")));
  RemoveIfExists(corrupt);

  XFILE* xfile = GEN_XFACTORY.Create_File();
  ASSERT_NE(xfile, (XFILE*)NULL);

  ASSERT_TRUE(xfile->Create(corrupt));
  XBYTE junk[] = { 'n','o','t',' ','a',' ','w','a','v' };
  EXPECT_TRUE(xfile->Write(junk, sizeof(junk)));
  xfile->Close();
  GEN_XFACTORY.Delete_File(xfile);

  EXPECT_EQ(SNDFILE::Create(corrupt), (SNDFILE*)NULL);

  RemoveIfExists(corrupt);
}


}
#endif
#endif
