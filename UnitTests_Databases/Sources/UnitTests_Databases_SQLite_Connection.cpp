/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Databases_SQLite_Connection.cpp
*
* @class      UNITTESTS_DATABASES_SQLITE_CONNECTION
* @brief      Databases unit tests for SQLITE_CONNECTION class
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

#include "UnitTests_Databases_SQLite_Connection.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UnitTests_Databases_Helper.h"

#include "DB_SQL_Factory.h"
#include "DB_SQL_Database.h"
#include "DB_SQL_Connection.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DB_SQL_ACTIVE
#ifdef DB_SQLITE_ACTIVE
namespace TEST_SQLITE_CONNECTION
{


TEST(UNITTESTS_SQLITE_CONNECTION_CLASSNAME, ConnectDisconnectViaDatabaseOpenClose)
{
  DB_SQL_CONNECTION* connection = NULL;
  DB_SQL_DATABASE*   db         = UNITTESTS_DATABASES_HELPER::OpenSQLiteMemory(&connection);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

  // Helper Open() already connected; CloseAndDelete disconnects once then frees both.
  UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
}


TEST(UNITTESTS_SQLITE_CONNECTION_CLASSNAME, ConnectFailsWithoutPathOption)
{
  DB_SQL_DATABASE* db = DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_SQLITE);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);

  DB_SQL_CONNECTION* connection = db->CreateConnection();
  ASSERT_NE(connection, (DB_SQL_CONNECTION*)NULL);

  EXPECT_TRUE(connection->SetOption(_L("DATABASE"), _L(":memory:")));
  EXPECT_FALSE(db->Open());

  db->SetConnection(NULL);
  GEN_DELETE connection;
  GEN_DELETE db;
}


}
#endif
#endif
#endif
