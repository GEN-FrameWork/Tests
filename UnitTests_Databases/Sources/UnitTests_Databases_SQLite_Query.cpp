/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Databases_SQLite_Query.cpp
*
* @class      UNITTESTS_DATABASES_SQLITE_QUERY
* @brief      Databases unit tests for SQLITE_QUERY class
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

#include "UnitTests_Databases_SQLite_Query.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UnitTests_Databases_Helper.h"

#include "DB_SQL_Database.h"
#include "DB_SQL_Connection.h"
#include "DB_SQL_Query.h"
#include "DB_SQL_Result.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DB_SQL_ACTIVE
#ifdef DB_SQLITE_ACTIVE
namespace TEST_SQLITE_QUERY
{


TEST(UNITTESTS_SQLITE_QUERY_CLASSNAME, ExecuteSelectOneReturnsResult)
{
  DB_SQL_CONNECTION* connection = NULL;
  DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

  DB_SQL_QUERY* query = db->CreateQuery();
  ASSERT_NE(query, (DB_SQL_QUERY*)NULL);

  ASSERT_TRUE(query->Set(__L("SELECT 1;")));
  ASSERT_TRUE(db->Execute(query));

  DB_SQL_RESULT* result = query->GetResult();
  ASSERT_NE(result, (DB_SQL_RESULT*)NULL);
  EXPECT_TRUE(result->HasNext());

  GEN_DELETE query;
  UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
}


TEST(UNITTESTS_SQLITE_QUERY_CLASSNAME, ExecuteInvalidSqlFailsGracefully)
{
  DB_SQL_CONNECTION* connection = NULL;
  DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

  DB_SQL_QUERY* query = db->CreateQuery();
  ASSERT_NE(query, (DB_SQL_QUERY*)NULL);

  ASSERT_TRUE(query->Set(__L("NOT VALID SQL ;;;")));
  EXPECT_FALSE(db->Execute(query));

  GEN_DELETE query;
  UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
}


}
#endif
#endif
#endif
