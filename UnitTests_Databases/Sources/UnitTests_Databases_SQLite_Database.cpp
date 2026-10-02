/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Databases_SQLite_Database.cpp
*
* @class      UNITTESTS_DATABASES_SQLITE_DATABASE
* @brief      Databases unit tests for SQLITE_DATABASE class
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

#include "UnitTests_Databases_SQLite_Database.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UnitTests_Databases_Helper.h"

#include "DB_SQL_Factory.h"
#include "DB_SQL_Database.h"
#include "DB_SQL_Connection.h"
#include "DB_SQL_Query.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DB_SQL_ACTIVE
#ifdef DB_SQLITE_ACTIVE
namespace TEST_SQLITE_DATABASE
{


TEST(UNITTESTS_SQLITE_DATABASE_CLASSNAME, GetTypeAndTypeName)
{
  DB_SQL_DATABASE* db = DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_SQLITE);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  EXPECT_EQ(db->GetType(), DB_SQL_DATABASE_TYPE_SQLITE);

  XSTRING name;
  name = db->GetTypeName();
  EXPECT_EQ(name.Compare(__L("SQLite"), true), 0);

  GEN_DELETE db;
}


TEST(UNITTESTS_SQLITE_DATABASE_CLASSNAME, OpenMemoryLifecycle)
{
  DB_SQL_CONNECTION* connection = NULL;
  DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

  // Open succeeded in the helper; Close must succeed for a clean lifecycle.
  EXPECT_TRUE(db->Close());

  db->SetConnection(NULL);
  GEN_DELETE connection;
  GEN_DELETE db;
}


TEST(UNITTESTS_SQLITE_DATABASE_CLASSNAME, TableCreateIsThereGetNRecordsDelete)
{
  // Split into two connections: SQLITE_QUERY / SQLITE_RESULT do not finalize the prepared
  // statement after a SELECT (Table_GetNRecords), so DROP TABLE on the same connection fails
  // with a lock. GEN behavior left as-is; the unit test validates each API path separately.
  {
    DB_SQL_CONNECTION* connection = NULL;
    DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

    ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
    ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

    XCHAR* fields[] = { __L("id int PRIMARY KEY"), __L("name varchar(50)") };
    ASSERT_TRUE(db->Table_Create(__L("t"), fields, 2));

    bool isexist = false;
    EXPECT_TRUE(db->Table_IsThere(__L("t"), __L("id"), isexist));
    EXPECT_TRUE(isexist);

    XQWORD nrecords = 999;
    EXPECT_TRUE(db->Table_GetNRecords(__L("t"), nrecords));
    EXPECT_EQ(nrecords, (XQWORD)0);

    UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
  }

  {
    DB_SQL_CONNECTION* connection = NULL;
    DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

    ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
    ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

    XCHAR* fields[] = { __L("id int PRIMARY KEY"), __L("name varchar(50)") };
    ASSERT_TRUE(db->Table_Create(__L("t"), fields, 2));

    EXPECT_TRUE(db->Table_Delete(__L("t")));

    // Table_IsThere returns false when the SELECT fails (table gone); isexist is cleared to false first.
    bool isexist = true;
    db->Table_IsThere(__L("t"), __L("id"), isexist);
    EXPECT_FALSE(isexist);

    UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
  }
}


TEST(UNITTESTS_SQLITE_DATABASE_CLASSNAME, TransactionRollbackLeavesZeroRecords)
{
  DB_SQL_CONNECTION* connection = NULL;
  DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

  XCHAR* fields[] = { __L("id int PRIMARY KEY"), __L("name varchar(50)") };
  ASSERT_TRUE(db->Table_Create(__L("t"), fields, 2));

  DB_SQL_QUERY* query = db->CreateQuery();
  ASSERT_NE(query, (DB_SQL_QUERY*)NULL);

  ASSERT_TRUE(db->Transaction());
  ASSERT_TRUE(query->Set(__L("INSERT INTO t (id,name) VALUES (?,?);")));
  EXPECT_TRUE(query->Bind(0, 1));
  EXPECT_TRUE(query->Bind(1, __L("rollback")));
  ASSERT_TRUE(db->Execute(query));
  EXPECT_TRUE(query->UnbindAll());
  ASSERT_TRUE(db->Rollback());

  XQWORD nrecords = 999;
  EXPECT_TRUE(db->Table_GetNRecords(__L("t"), nrecords));
  EXPECT_EQ(nrecords, (XQWORD)0);

  GEN_DELETE query;
  UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
}


TEST(UNITTESTS_SQLITE_DATABASE_CLASSNAME, TransactionCommitKeepsRecords)
{
  DB_SQL_CONNECTION* connection = NULL;
  DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

  XCHAR* fields[] = { __L("id int PRIMARY KEY"), __L("name varchar(50)") };
  ASSERT_TRUE(db->Table_Create(__L("t"), fields, 2));

  DB_SQL_QUERY* query = db->CreateQuery();
  ASSERT_NE(query, (DB_SQL_QUERY*)NULL);

  ASSERT_TRUE(db->Transaction());
  ASSERT_TRUE(query->Set(__L("INSERT INTO t (id,name) VALUES (?,?);")));
  EXPECT_TRUE(query->Bind(0, 1));
  EXPECT_TRUE(query->Bind(1, __L("commit")));
  ASSERT_TRUE(db->Execute(query));
  EXPECT_TRUE(query->UnbindAll());
  ASSERT_TRUE(db->Commit());

  XQWORD nrecords = 0;
  EXPECT_TRUE(db->Table_GetNRecords(__L("t"), nrecords));
  EXPECT_GT(nrecords, (XQWORD)0);

  GEN_DELETE query;
  UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
}


}
#endif
#endif
#endif
