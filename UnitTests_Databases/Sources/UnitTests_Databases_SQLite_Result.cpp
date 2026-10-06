/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Databases_SQLite_Result.cpp
*
* @class      UNITTESTS_DATABASES_SQLITE_RESULT
* @brief      Databases unit tests for SQLITE_RESULT class
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

#include "UnitTests_Databases_SQLite_Result.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UnitTests_Databases_Helper.h"

#include "DB_SQL_Database.h"
#include "DB_SQL_Connection.h"
#include "DB_SQL_Query.h"
#include "DB_SQL_Result.h"
#include "DB_SQL_Variant.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DB_SQL_ACTIVE
#ifdef DB_SQLITE_ACTIVE
namespace TEST_SQLITE_RESULT
{


TEST(UNITTESTS_SQLITE_RESULT_CLASSNAME, GetNumColumnsMatchesSelect)
{
  DB_SQL_CONNECTION* connection = NULL;
  DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

  XCHAR* fields[] = { _L("id int PRIMARY KEY"), _L("name varchar(50)") };
  ASSERT_TRUE(db->Table_Create(_L("t"), fields, 2));

  DB_SQL_QUERY* query = db->CreateQuery();
  ASSERT_NE(query, (DB_SQL_QUERY*)NULL);

  ASSERT_TRUE(query->Set(_L("INSERT INTO t (id,name) VALUES (?,?);")));
  EXPECT_TRUE(query->Bind(0, 1));
  EXPECT_TRUE(query->Bind(1, _L("one")));
  ASSERT_TRUE(db->Execute(query));
  EXPECT_TRUE(query->UnbindAll());

  ASSERT_TRUE(query->Set(_L("SELECT id,name FROM t;")));
  ASSERT_TRUE(db->Execute(query));

  DB_SQL_RESULT* result = query->GetResult();
  ASSERT_NE(result, (DB_SQL_RESULT*)NULL);
  EXPECT_EQ(result->GetNumColumns(), (XQWORD)2);

  GEN_DELETE query;
  UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
}


TEST(UNITTESTS_SQLITE_RESULT_CLASSNAME, FirstHasNextProcessRowNavigates)
{
  DB_SQL_CONNECTION* connection = NULL;
  DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

  XCHAR* fields[] = { _L("id int PRIMARY KEY"), _L("name varchar(50)") };
  ASSERT_TRUE(db->Table_Create(_L("t"), fields, 2));

  DB_SQL_QUERY* query = db->CreateQuery();
  ASSERT_NE(query, (DB_SQL_QUERY*)NULL);

  ASSERT_TRUE(query->Set(_L("INSERT INTO t (id,name) VALUES (?,?);")));

  EXPECT_TRUE(query->Bind(0, 1));
  EXPECT_TRUE(query->Bind(1, _L("first")));
  ASSERT_TRUE(db->Execute(query));
  EXPECT_TRUE(query->UnbindAll());

  EXPECT_TRUE(query->Bind(0, 2));
  EXPECT_TRUE(query->Bind(1, _L("second")));
  ASSERT_TRUE(db->Execute(query));
  EXPECT_TRUE(query->UnbindAll());

  ASSERT_TRUE(query->Set(_L("SELECT id,name FROM t ORDER BY id;")));
  ASSERT_TRUE(db->Execute(query));

  DB_SQL_RESULT* result = query->GetResult();
  ASSERT_NE(result, (DB_SQL_RESULT*)NULL);

  // SQLite already stepped onto the first row during Execute; navigate with HasNext/ProcessRow/Next
  // (same pattern as SQLITE_DATABASE::GetTables). First() would call Next() again and skip a row.
  EXPECT_TRUE(result->HasNext());
  ASSERT_TRUE(result->ProcessRow());

  DB_SQL_ROW* row = result->GetRow();
  ASSERT_NE(row, (DB_SQL_ROW*)NULL);
  EXPECT_EQ((int)row->Get(0), 1);

  XSTRING name;
  name = (XCHAR*)row->Get(1);
  EXPECT_EQ(name.Compare(_L("first"), true), 0);

  EXPECT_TRUE(result->Next());
  EXPECT_TRUE(result->HasNext());
  ASSERT_TRUE(result->ProcessRow());

  row = result->GetRow();
  ASSERT_NE(row, (DB_SQL_ROW*)NULL);
  EXPECT_EQ((int)row->Get(0), 2);

  name = (XCHAR*)row->Get(1);
  EXPECT_EQ(name.Compare(_L("second"), true), 0);

  EXPECT_TRUE(result->Next());
  EXPECT_FALSE(result->HasNext());

  GEN_DELETE query;
  UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
}


}
#endif
#endif
#endif
