/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Databases_DB_SQL_Database.cpp
*
* @class      UNITTESTS_DATABASES_DB_SQL_DATABASE
* @brief      Databases unit tests for DB_SQL_DATABASE class
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

#include "UnitTests_Databases_DB_SQL_Database.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UnitTests_Databases_Helper.h"

#include "DB_SQL_Factory.h"
#include "DB_SQL_Database.h"
#include "DB_SQL_Connection.h"
#include "DB_SQL_Variant.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DB_SQL_ACTIVE
namespace TEST_DB_SQL_DATABASE
{


TEST(UNITTESTS_DB_SQL_DATABASE_CLASSNAME, OpenWithoutConnectionFails)
{
#ifdef DB_SQLITE_ACTIVE
  DB_SQL_DATABASE* db = DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_SQLITE);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  EXPECT_FALSE(db->Open());

  GEN_DELETE db;
#endif
}


TEST(UNITTESTS_DB_SQL_DATABASE_CLASSNAME, CreateVariantReturnsNonNull)
{
#ifdef DB_SQLITE_ACTIVE
  DB_SQL_DATABASE* db = DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_SQLITE);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);

  DB_SQL_VARIANT* variant = db->CreateVariant();
  ASSERT_NE(variant, (DB_SQL_VARIANT*)NULL);

  GEN_DELETE variant;
  GEN_DELETE db;
#endif
}


TEST(UNITTESTS_DB_SQL_DATABASE_CLASSNAME, ErrorAndClearPreviousErrors)
{
#ifdef DB_SQLITE_ACTIVE
  DB_SQL_DATABASE* db = DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_SQLITE);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);

  db->Error(_L("boom"));

  XSTRING last;
  last = db->GetLastError();
  EXPECT_EQ(last.Compare(_L("boom"), true), 0);

  db->ClearPreviousErrors();

  last = db->GetLastError();
  EXPECT_EQ(last.Compare(_L(""), true), 0);

  GEN_DELETE db;
#endif
}


TEST(UNITTESTS_DB_SQL_DATABASE_CLASSNAME, IsTransactionStartedFalseUntilTransaction)
{
#ifdef DB_SQLITE_ACTIVE
  DB_SQL_CONNECTION* connection = NULL;
  DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

  EXPECT_FALSE(db->IsTransactionStarted());
  EXPECT_TRUE(db->Transaction());
  EXPECT_TRUE(db->IsTransactionStarted());
  EXPECT_TRUE(db->Commit());
  EXPECT_FALSE(db->IsTransactionStarted());

  UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
#endif
}


}
#endif
#endif
