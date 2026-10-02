/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Databases_DB_SQL_Variant.cpp
*
* @class      UNITTESTS_DATABASES_DB_SQL_VARIANT
* @brief      Databases unit tests for DB_SQL_VARIANT / DB_SQL_ROW
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

#include "UnitTests_Databases_DB_SQL_Variant.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "DB_SQL_Variant.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DB_SQL_ACTIVE
namespace TEST_DB_SQL_VARIANT
{


TEST(UNITTESTS_DB_SQL_VARIANT_CLASSNAME, DefaultFlagsAreNone)
{
  DB_SQL_VARIANT variant;

  ASSERT_NE(variant.GetFlags(), (DB_SQL_VARIANT_FLAGS*)NULL);
  EXPECT_EQ(*variant.GetFlags(), DB_SQL_VARIANT_FLAGS_NONE);
}


TEST(UNITTESTS_DB_SQL_VARIANT_CLASSNAME, SetFlagsRoundTrip)
{
  DB_SQL_VARIANT variant;
  DB_SQL_VARIANT_FLAGS flags = (DB_SQL_VARIANT_FLAGS)(DB_SQL_VARIANT_FLAGS_PRIMARY_KEY | DB_SQL_VARIANT_FLAGS_NOT_NULL);

  variant.SetFlags(flags);

  ASSERT_NE(variant.GetFlags(), (DB_SQL_VARIANT_FLAGS*)NULL);
  EXPECT_EQ(*variant.GetFlags(), flags);
}


TEST(UNITTESTS_DB_SQL_VARIANT_CLASSNAME, AssignIntegerAndReadBack)
{
  DB_SQL_VARIANT variant;

  variant = 42;

  EXPECT_EQ(variant.GetType(), (XVARIANT_TYPE)DB_SQL_VARIANT_TYPE_INTEGER);
  EXPECT_EQ((int)variant, 42);
}


TEST(UNITTESTS_DB_SQL_VARIANT_CLASSNAME, RowAddGetClear)
{
  DB_SQL_ROW      row;
  DB_SQL_VARIANT* variant = GEN_NEW DB_SQL_VARIANT();

  ASSERT_NE(variant, (DB_SQL_VARIANT*)NULL);

  (*variant) = 42;

  EXPECT_TRUE(row.Add(variant));
  EXPECT_EQ((int)row.Get(0), 42);

  row.Clear();

  EXPECT_EQ(row.Get(0).GetType(), (XVARIANT_TYPE)DB_SQL_VARIANT_TYPE_NULL);
}


TEST(UNITTESTS_DB_SQL_VARIANT_CLASSNAME, RowGetOutOfRangeReturnsEmptyVariant)
{
  DB_SQL_ROW row;

  EXPECT_EQ(row.Get(0).GetType(), (XVARIANT_TYPE)DB_SQL_VARIANT_TYPE_NULL);
  EXPECT_EQ(row.Get(99).GetType(), (XVARIANT_TYPE)DB_SQL_VARIANT_TYPE_NULL);
}


}
#endif
#endif
