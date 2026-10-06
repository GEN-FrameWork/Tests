/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Sound_SNDFactory.cpp
*
* @class      UNITTESTS_SOUND_SNDFACTORY
* @brief      Sound unit tests for SNDFACTORY class
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

#include "UnitTests_Sound_SNDFactory.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "SNDFactory.h"
#include "SNDItem.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef SND_ACTIVE
namespace TEST_SNDFACTORY
{


class UNITTESTS_SOUND_STUBFACTORY : public SNDFACTORY
{
  public:

    bool Ini()
    {
      soundactive = true;
      return true;
    }
};


TEST(UNITTESTS_SNDFACTORY_CLASSNAME, InactiveCreateItemReturnsNull)
{
  SNDFACTORY::DelInstance();

  SNDFACTORY& factory = SNDFACTORY::GetInstance();

  EXPECT_FALSE(factory.IsSoundActive());
  EXPECT_EQ(factory.CreateItem(440, 1000), (SNDITEM*)NULL);
  EXPECT_EQ(factory.CreateItem(_L("x.wav")), (SNDITEM*)NULL);
  EXPECT_FALSE(factory.Sound_Play(NULL));

  SNDFACTORY::DelInstance();
}


TEST(UNITTESTS_SNDFACTORY_CLASSNAME, StubIniCreateNoteItemAndPlayStatus)
{
  SNDFACTORY::DelInstance();

  UNITTESTS_SOUND_STUBFACTORY* stub = GEN_NEW UNITTESTS_SOUND_STUBFACTORY();
  ASSERT_NE(stub, (UNITTESTS_SOUND_STUBFACTORY*)NULL);
  ASSERT_TRUE(SNDFACTORY::SetInstance(stub));

  EXPECT_TRUE(SNDFACTORY::GetInstance().Ini());
  EXPECT_TRUE(SNDFACTORY::GetInstance().IsSoundActive());

  SNDITEM* item = SNDFACTORY::GetInstance().CreateItem(440, 1000);
  ASSERT_NE(item, (SNDITEM*)NULL);

  ASSERT_NE(SNDFACTORY::GetInstance().GetItems(), (XVECTOR<SNDITEM*>*)NULL);
  EXPECT_EQ(SNDFACTORY::GetInstance().GetItems()->GetSize(), (XDWORD)1);

  EXPECT_TRUE(SNDFACTORY::GetInstance().Sound_Play(item));
  EXPECT_EQ(item->GetStatus(), SNDITEM_STATUS_INI);

  EXPECT_TRUE(SNDFACTORY::GetInstance().DeleteAllItems());

  SNDFACTORY::DelInstance();
}


TEST(UNITTESTS_SNDFACTORY_CLASSNAME, MasterVolumeSetGet)
{
  SNDFACTORY::DelInstance();

  SNDFACTORY& factory = SNDFACTORY::GetInstance();

  EXPECT_TRUE(factory.MasterVolume_Set(50));
  EXPECT_EQ(factory.MasterVolume_Get(), 50);

  SNDFACTORY::DelInstance();
}


}
#endif
#endif
