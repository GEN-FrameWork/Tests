/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Databases_DB_SQL_Result.cpp
*
* @class      UNITTESTS_DATABASES_DB_SQL_RESULT
* @brief      Databases unit tests for DB_SQL_RESULT class
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

#include "UnitTests_Databases_DB_SQL_Result.h"

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
namespace TEST_DB_SQL_RESULT
{


TEST(UNITTESTS_DB_SQL_RESULT_CLASSNAME, SelectReturnsRowsWithExpectedValues)
{
#ifdef DB_SQLITE_ACTIVE
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
  EXPECT_TRUE(query->Bind(1, _L("alpha")));
  ASSERT_TRUE(db->Execute(query));
  EXPECT_TRUE(query->UnbindAll());

  EXPECT_TRUE(query->Bind(0, 2));
  EXPECT_TRUE(query->Bind(1, _L("beta")));
  ASSERT_TRUE(db->Execute(query));
  EXPECT_TRUE(query->UnbindAll());

  ASSERT_TRUE(query->Set(_L("SELECT * FROM t;")));
  ASSERT_TRUE(db->Execute(query));

  DB_SQL_RESULT* result = query->GetResult();
  ASSERT_NE(result, (DB_SQL_RESULT*)NULL);

  int rowcount = 0;

  while(result->HasNext())
    {
      ASSERT_TRUE(result->ProcessRow());

      DB_SQL_ROW* row = result->GetRow();
      ASSERT_NE(row, (DB_SQL_ROW*)NULL);

      if(rowcount == 0)
        {
          XSTRING name;

          EXPECT_EQ((int)row->Get(0), 1);
          name = (XCHAR*)row->Get(1);
          EXPECT_EQ(name.Compare(_L("alpha"), true), 0);
        }
       else if(rowcount == 1)
        {
          XSTRING name;

          EXPECT_EQ((int)row->Get(0), 2);
          name = (XCHAR*)row->Get(1);
          EXPECT_EQ(name.Compare(_L("beta"), true), 0);
        }

      rowcount++;
      result->Next();
    }

  EXPECT_EQ(rowcount, 2);

  GEN_DELETE query;
  UNITTESTS_DATABASES_HELPER::CloseAndDelete(db, connection);
#endif
}


}
#endif
#endif
