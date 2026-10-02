/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Sound_SNDItem.cpp
*
* @class      UNITTESTS_SOUND_SNDITEM
* @brief      Sound unit tests for SNDITEM class
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

#include "UnitTests_Sound_SNDItem.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "SNDItem.h"
#include "SNDNote.h"
#include "SNDPlayCFG.h"
#include "SNDFactory.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef SND_ACTIVE
namespace TEST_SNDITEM
{


TEST(UNITTESTS_SNDITEM_CLASSNAME, DefaultTypeUnknownStatusNone)
{
  SNDITEM item;

  EXPECT_EQ(item.GetType(), SNDITEM_TYPE_UNKNOWN);
  EXPECT_EQ(item.GetStatus(), SNDITEM_STATUS_NONE);
}


TEST(UNITTESTS_SNDITEM_CLASSNAME, TypeAndStatusStringMaps)
{
  SNDITEM item;
  XSTRING text;

  item.SetType(SNDITEM_TYPE_FILE);
  EXPECT_TRUE(item.GetType(text));
  EXPECT_EQ(text.Compare(__L("File"), true), 0);

  item.SetType(SNDITEM_TYPE_NOTE);
  EXPECT_TRUE(item.GetType(text));
  EXPECT_EQ(text.Compare(__L("Note"), true), 0);

  item.SetStatus(SNDITEM_STATUS_NONE);
  EXPECT_TRUE(item.GetStatus(text));
  EXPECT_EQ(text.Compare(__L("None"), true), 0);

  item.SetStatus(SNDITEM_STATUS_PLAY);
  EXPECT_TRUE(item.GetStatus(text));
  EXPECT_EQ(text.Compare(__L("Play"), true), 0);

  item.SetStatus(SNDITEM_STATUS_INI);
  EXPECT_TRUE(item.GetStatus(text));
  EXPECT_EQ(text.Compare(__L("Ini"), true), 0);

  item.SetStatus(SNDITEM_STATUS_PAUSE);
  EXPECT_TRUE(item.GetStatus(text));
  EXPECT_EQ(text.Compare(__L("Pause"), true), 0);

  item.SetStatus(SNDITEM_STATUS_STOP);
  EXPECT_TRUE(item.GetStatus(text));
  EXPECT_EQ(text.Compare(__L("Stop"), true), 0);

  item.SetStatus(SNDITEM_STATUS_END);
  EXPECT_TRUE(item.GetStatus(text));
  EXPECT_EQ(text.Compare(__L("End"), true), 0);
}


TEST(UNITTESTS_SNDITEM_CLASSNAME, CountersAndPlayTimes)
{
  SNDITEM item;

  EXPECT_EQ(item.GetNTimesPlayed(), (XDWORD)0);
  item.AddOneNTimesPlayed();
  EXPECT_EQ(item.GetNTimesPlayed(), (XDWORD)1);

  item.SetNTimesToPlay(3);
  EXPECT_EQ(item.GetNTimesToPlay(), 3);

  item.SetCounterPlay(2);
  EXPECT_EQ(item.GetCounterPlay(), 2);

  item.SetPlayingTime(100);
  EXPECT_EQ(item.GetPlayingTime(), (XDWORD)100);

  item.SetCurrentPlayingTime(50);
  EXPECT_EQ(item.GetCurrentPlayingTime(), (XDWORD)50);
}


TEST(UNITTESTS_SNDITEM_CLASSNAME, PlayCFGRoundTrip)
{
  SNDITEM    item;
  SNDPLAYCFG cfg;

  cfg.SetVolume(60);
  cfg.SetPitch(1.5f);

  EXPECT_TRUE(item.SetPlayCFG(cfg));
  ASSERT_NE(item.GetPlayCFG(), (SNDPLAYCFG*)NULL);
  EXPECT_EQ(item.GetPlayCFG()->GetVolume(), 60);
  EXPECT_FLOAT_EQ(item.GetPlayCFG()->GetPitch(), 1.5f);
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         TEST(UNITTESTS_SNDITEM_CLASSNAME, DurationFromAttachedNote)
* @brief      SNDITEM::~SNDITEM() GEN_DELETEs soundnote/soundfile when set, so the GEN_NEW note
*             must not be deleted by the test after SetSoundNote -- ownership transfers to the item.
* @ingroup    UNIT TEST
*
* --------------------------------------------------------------------------------------------------------------------*/
TEST(UNITTESTS_SNDITEM_CLASSNAME, DurationFromAttachedNote)
{
  SNDITEM  item;
  SNDNOTE* note = GEN_NEW SNDNOTE();

  ASSERT_NE(note, (SNDNOTE*)NULL);

  note->SetDuration(500);
  item.SetSoundNote(note);
  item.SetType(SNDITEM_TYPE_NOTE);

  EXPECT_EQ(item.GetDuration(), (XDWORD)500);
  // note is owned by item; destructor deletes it.
}


TEST(UNITTESTS_SNDITEM_CLASSNAME, GetTimerPlayNonNull)
{
  SNDITEM item;

  EXPECT_NE(item.GetTimerPlay(), (XTIMER*)NULL);
}


}
#endif
#endif
