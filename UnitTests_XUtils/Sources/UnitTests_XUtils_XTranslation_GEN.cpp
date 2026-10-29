/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_XUtils_XTranslation_GEN.cpp
*
* @class      UNITTESTS_XUTILS_XTRANSLATION_GEN
* @brief      XUtils unit tests for XTranslation_GEN class
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

#include "UnitTests_XUtils_XTranslation_GEN.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XTranslation_GEN.h"
#include "XTranslation.h"
#include "XLanguage_ISO_639_3.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/


#ifdef GOOGLETEST_ACTIVE
namespace TEST_XTRANSLATION_GEN
{


TEST(UNITTESTS_XTRANSLATION_GEN_CLASSNAME, GetInstanceCreatesAndReturnsSameReference)
{
  XTRANSLATION_GEN& instance1 = XTRANSLATION_GEN::GetInstance();
  EXPECT_TRUE(XTRANSLATION_GEN::GetIsInstanced());

  XTRANSLATION_GEN& instance2 = XTRANSLATION_GEN::GetInstance();
  EXPECT_EQ(&instance1, &instance2);
}


TEST(UNITTESTS_XTRANSLATION_GEN_CLASSNAME, DelInstanceTwice)
{
  XTRANSLATION_GEN::GetInstance(); // ensure instanced

  EXPECT_TRUE(XTRANSLATION_GEN::DelInstance());
  EXPECT_FALSE(XTRANSLATION_GEN::GetIsInstanced());
  EXPECT_FALSE(XTRANSLATION_GEN::DelInstance());

  // The constructor self-populates its whole built-in catalogue (calls Sentences_AddAll()
  // unconditionally), so simply asking for the instance again leaves it in the same, fully
  // populated state as before - safe for the rest of this shared test binary.
  XTRANSLATION_GEN::GetInstance();
  EXPECT_TRUE(XTRANSLATION_GEN::GetIsInstanced());
  EXPECT_NE(XTRANSLATION_GEN::GetInstance().Sentence_Get(XTRANSLATION_GEN_ID_OK, XLANGUAGE_ISO_639_3_CODE_ENG), nullptr);
}


TEST(UNITTESTS_XTRANSLATION_GEN_CLASSNAME, SentenceDefaultConstructionIsZeroedAndPublicCleanIsCallableDirectly)
{
  XTRANSLATION_GEN_SENTENCE sentence;

  EXPECT_EQ(sentence.ID, (XDWORD)0);
  EXPECT_EQ(sentence.codelanguage, (XDWORD)0);
  EXPECT_EQ(sentence.sentence, (XCHAR*)NULL);
  EXPECT_EQ(sentence.fixed, (XDWORD)0);

  // Unlike every other reviewed class in this codebase, Clean() is public here
  // (XTranslation_GEN.h line 122) instead of private, so external code - including this test - can
  // call it directly on a live object.
  sentence.ID = 42;
  sentence.Clean();
  EXPECT_EQ(sentence.ID, (XDWORD)0);
}


TEST(UNITTESTS_XTRANSLATION_GEN_CLASSNAME, IsLanguageAvailableReflectsTheBuiltInCatalogue)
{
  EXPECT_TRUE(XTRANSLATION_GEN::GetInstance().IsLanguageAvailable(XLANGUAGE_ISO_639_3_CODE_ENG));
  EXPECT_TRUE(XTRANSLATION_GEN::GetInstance().IsLanguageAvailable(XLANGUAGE_ISO_639_3_CODE_SPA));
  EXPECT_TRUE(XTRANSLATION_GEN::GetInstance().IsLanguageAvailable(XLANGUAGE_ISO_639_3_CODE_FRE));
  EXPECT_TRUE(XTRANSLATION_GEN::GetInstance().IsLanguageAvailable(XLANGUAGE_ISO_639_3_CODE_GER));
  EXPECT_TRUE(XTRANSLATION_GEN::GetInstance().IsLanguageAvailable(XLANGUAGE_ISO_639_3_CODE_CHI));
  EXPECT_FALSE(XTRANSLATION_GEN::GetInstance().IsLanguageAvailable(XLANGUAGE_ISO_639_3_CODE_JPN));
}


TEST(UNITTESTS_XTRANSLATION_GEN_CLASSNAME, SentenceGetFindsKnownBuiltInEntriesByIDAndLanguage)
{
  XTRANSLATION_GEN_SENTENCE* ok_eng = XTRANSLATION_GEN::GetInstance().Sentence_Get(XTRANSLATION_GEN_ID_OK, XLANGUAGE_ISO_639_3_CODE_ENG);
  ASSERT_NE(ok_eng, nullptr);
  EXPECT_STREQ(ok_eng->sentence, _L("Ok"));

  XTRANSLATION_GEN_SENTENCE* ok_spa = XTRANSLATION_GEN::GetInstance().Sentence_Get(XTRANSLATION_GEN_ID_OK, XLANGUAGE_ISO_639_3_CODE_SPA);
  ASSERT_NE(ok_spa, nullptr);
  EXPECT_STREQ(ok_spa->sentence, _L("Correcto"));

  XTRANSLATION_GEN_SENTENCE* ok_fre = XTRANSLATION_GEN::GetInstance().Sentence_Get(XTRANSLATION_GEN_ID_OK, XLANGUAGE_ISO_639_3_CODE_FRE);
  ASSERT_NE(ok_fre, nullptr);
  EXPECT_STREQ(ok_fre->sentence, _L("Correct"));

  XTRANSLATION_GEN_SENTENCE* ok_ger = XTRANSLATION_GEN::GetInstance().Sentence_Get(XTRANSLATION_GEN_ID_OK, XLANGUAGE_ISO_639_3_CODE_GER);
  ASSERT_NE(ok_ger, nullptr);
  EXPECT_STREQ(ok_ger->sentence, _L("Korrekt"));

  XTRANSLATION_GEN_SENTENCE* ok_chi = XTRANSLATION_GEN::GetInstance().Sentence_Get(XTRANSLATION_GEN_ID_OK, XLANGUAGE_ISO_639_3_CODE_CHI);
  ASSERT_NE(ok_chi, nullptr);
  EXPECT_STREQ(ok_chi->sentence, _L("\u6b63\u786e"));
}


TEST(UNITTESTS_XTRANSLATION_GEN_CLASSNAME, SentenceGetReturnsNullForUnknownIDOrLanguagePair)
{
  EXPECT_EQ(XTRANSLATION_GEN::GetInstance().Sentence_Get(999999, XLANGUAGE_ISO_639_3_CODE_ENG), nullptr);
  EXPECT_EQ(XTRANSLATION_GEN::GetInstance().Sentence_Get(XTRANSLATION_GEN_ID_OK, XLANGUAGE_ISO_639_3_CODE_JPN), nullptr);
}


TEST(UNITTESTS_XTRANSLATION_GEN_CLASSNAME, SentenceAddRejectsZeroIDZeroLanguageOrNullSentence)
{
  EXPECT_FALSE(XTRANSLATION_GEN::GetInstance().Sentence_Add(0, XLANGUAGE_ISO_639_3_CODE_ENG, _L("text"), 0));
  EXPECT_FALSE(XTRANSLATION_GEN::GetInstance().Sentence_Add(90001, 0, _L("text"), 0));
  EXPECT_FALSE(XTRANSLATION_GEN::GetInstance().Sentence_Add(90001, XLANGUAGE_ISO_639_3_CODE_ENG, NULL, 0));
}


TEST(UNITTESTS_XTRANSLATION_GEN_CLASSNAME, SentenceAddAndGetRoundTripOnAFreshIDThenRejectsDuplicate)
{
  // A high, otherwise-unused ID so this does not collide with the real built-in catalogue.
  // The entry stays in the XTRANSLATION_GEN singleton; it is not copied into XTRANSLATION.
  const XDWORD freshID = 9600;

  EXPECT_EQ(XTRANSLATION_GEN::GetInstance().Sentence_Get(freshID, XLANGUAGE_ISO_639_3_CODE_ENG), nullptr);

  EXPECT_TRUE(XTRANSLATION_GEN::GetInstance().Sentence_Add(freshID, XLANGUAGE_ISO_639_3_CODE_ENG, _L("Fresh sentence"), 0));

  XTRANSLATION_GEN_SENTENCE* added = XTRANSLATION_GEN::GetInstance().Sentence_Get(freshID, XLANGUAGE_ISO_639_3_CODE_ENG);
  ASSERT_NE(added, nullptr);
  EXPECT_STREQ(added->sentence, _L("Fresh sentence"));

  // Sentence_Add refuses to add a second entry for the same (ID, codelanguage) pair.
  EXPECT_FALSE(XTRANSLATION_GEN::GetInstance().Sentence_Add(freshID, XLANGUAGE_ISO_639_3_CODE_ENG, _L("Replacement"), 0));
}


TEST(UNITTESTS_XTRANSLATION_GEN_CLASSNAME, GetSentenceAndGEN_TLFollowTheActiveLanguage)
{
  XTRANSLATION_GEN& gen = XTRANSLATION_GEN::GetInstance();
  XDWORD previous = gen.GetActual();

  if(previous != (XDWORD)XLANGUAGE_ISO_639_3_CODE_ENG)
    {
      EXPECT_TRUE(gen.SetActual(XLANGUAGE_ISO_639_3_CODE_ENG));
    }

  EXPECT_EQ(gen.GetActual(), (XDWORD)XLANGUAGE_ISO_639_3_CODE_ENG);
  // Already active → success (no-op), same contract as XTRANSLATION::SetActual(code).
  EXPECT_TRUE(gen.SetActual(XLANGUAGE_ISO_639_3_CODE_ENG));
  EXPECT_STREQ(gen.GetSentence(XTRANSLATION_GEN_ID_OK), _L("Ok"));
  EXPECT_STREQ(GEN_TL(XTRANSLATION_GEN_ID_OK), _L("Ok"));

  EXPECT_TRUE(gen.SetActual(XLANGUAGE_ISO_639_3_CODE_SPA));
  EXPECT_STREQ(GEN_TL(XTRANSLATION_GEN_ID_OK), _L("Correcto"));
  EXPECT_STREQ(gen.GetSentence(999999), _L("--"));

  EXPECT_FALSE(gen.SetActual(XLANGUAGE_ISO_639_3_CODE_JPN));
  EXPECT_EQ(gen.GetActual(), (XDWORD)XLANGUAGE_ISO_639_3_CODE_SPA);

  if(gen.GetActual() != previous)
    {
      EXPECT_TRUE(gen.SetActual(previous));
    }
}


TEST(UNITTESTS_XTRANSLATION_GEN_CLASSNAME, SentencesDeleteAllClearsCatalogueAndReturnsFalseWhenAlreadyEmpty)
{
  EXPECT_TRUE(XTRANSLATION_GEN::GetInstance().Sentences_DeleteAll());
  EXPECT_EQ(XTRANSLATION_GEN::GetInstance().Sentence_Get(XTRANSLATION_GEN_ID_OK, XLANGUAGE_ISO_639_3_CODE_ENG), nullptr);
  EXPECT_FALSE(XTRANSLATION_GEN::GetInstance().Sentences_DeleteAll());

  // Restore the built-in catalogue for the rest of this shared test binary.
  EXPECT_TRUE(XTRANSLATION_GEN::GetInstance().Sentences_AddAll());
  EXPECT_NE(XTRANSLATION_GEN::GetInstance().Sentence_Get(XTRANSLATION_GEN_ID_OK, XLANGUAGE_ISO_639_3_CODE_ENG), nullptr);
}


}
#endif

