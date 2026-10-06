/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptCache.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTCACHE
* @brief      Unit tests for SCRIPT_CACHE
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

#include "GEN_Defines.h"
#include "UnitTests_Script_ScriptCache.h"
#include "UnitTests_Script_TestHelpers.h"
#include "Script_Cache.h"
#include "GEN_Control.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_CACHE_ACTIVE)
namespace TEST_SCRIPTCACHE
{

static XDWORD UnitTests_ScriptCache_GenerateListID(SCRIPT_CACHE& cache, XVECTOR<XSTRING*>* listscripts)
{
  XSTRING combined;

  if(!listscripts) return 0;

  for(XDWORD index = 0; index < listscripts->GetSize(); index++)
    {
      XSTRING* entry = listscripts->Get(index);
      if(!entry) continue;

      if(!combined.IsEmpty()) combined += _L("|");
      combined += entry->Get();
    }

  return cache.GenerateID(combined);
}


TEST(UNITTESTS_SCRIPTCACHE_CLASSNAME, IdentifierIsDeterministic)
{
  SCRIPT_CACHE& cache = SCRIPT_CACHE::GetInstance();
  XSTRING key(_L("same-key"));

  EXPECT_EQ(cache.GenerateID(key), cache.GenerateID(key));
  EXPECT_NE(cache.GenerateID(key), (XDWORD)0);
}


TEST(UNITTESTS_SCRIPTCACHE_CLASSNAME, AddGetSetDeleteLifecycle)
{
  SCRIPT_CACHE& cache = SCRIPT_CACHE::GetInstance();
  XSTRING key(_L("unit-cache-entry"));
  XSTRING value(_L("first"));
  XSTRING replacement(_L("second"));
  XDWORD id = cache.GenerateID(key);

  cache.Cache_Del(id);
  ASSERT_TRUE(cache.Cache_Add(id, &value));
  ASSERT_NE(cache.Cache_Get(id), (XSTRING*)NULL);
  EXPECT_EQ(cache.Cache_Get(id)->Compare(_L("first")), 0);

  EXPECT_TRUE(cache.Cache_Set(id, &replacement));
  EXPECT_EQ(cache.Cache_Get(id)->Compare(_L("second")), 0);
  EXPECT_TRUE(cache.Cache_Del(id));
  EXPECT_EQ(cache.Cache_Get(id), (XSTRING*)NULL);
}


TEST(UNITTESTS_SCRIPTCACHE_CLASSNAME, ListKeyUsesEveryOrderedName)
{
  SCRIPT_CACHE& cache = SCRIPT_CACHE::GetInstance();
  XSTRING first(_L("one.g"));
  XSTRING secondA(_L("two.g"));
  XSTRING secondB(_L("other.g"));
  XVECTOR<XSTRING*> listA;
  XVECTOR<XSTRING*> listB;

  listA.Add(&first);
  listA.Add(&secondA);
  listB.Add(&first);
  listB.Add(&secondB);

  EXPECT_NE(UnitTests_ScriptCache_GenerateListID(cache, &listA), UnitTests_ScriptCache_GenerateListID(cache, &listB));
}

}
#endif
