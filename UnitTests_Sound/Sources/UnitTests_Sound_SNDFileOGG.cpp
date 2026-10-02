/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Sound_SNDFileOGG.cpp
*
* @class      UNITTESTS_SOUND_SNDFILEOGG
* @brief      Sound unit tests for SNDFILEOGG class
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

#include "UnitTests_Sound_SNDFileOGG.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "SNDFile.h"
#include "UnitTests_Sound_Helper.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef SND_ACTIVE
namespace TEST_SNDFILEOGG
{


TEST(UNITTESTS_SNDFILEOGG_CLASSNAME, CreateMissingOggReturnsNull)
{
  XPATH xpath;

  ASSERT_TRUE(UNITTESTS_SOUND_HELPER::BuildAssetPath(xpath, __L("unittests_sound_missing_ogg.ogg")));
  EXPECT_EQ(SNDFILE::Create(xpath), (SNDFILE*)NULL);
}


TEST(UNITTESTS_SNDFILEOGG_CLASSNAME, CreateWithOggExtensionRequiresExistingFile)
{
  XPATH xpath;

  // Offline-safe Create path only: missing .ogg must not invent a loadable object.
  ASSERT_TRUE(UNITTESTS_SOUND_HELPER::BuildAssetPath(xpath, __L("unittests_sound_requires_existing.ogg")));
  EXPECT_EQ(SNDFILE::Create(xpath), (SNDFILE*)NULL);
}


}
#endif
#endif
