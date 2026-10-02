/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Databases_DB_SQL_Factory.cpp
*
* @class      UNITTESTS_DATABASES_DB_SQL_FACTORY
* @brief      Databases unit tests for DB_SQL_FACTORY class
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

#include "UnitTests_Databases_DB_SQL_Factory.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "DB_SQL_Factory.h"
#include "DB_SQL_Database.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DB_SQL_ACTIVE
namespace TEST_DB_SQL_FACTORY
{


TEST(UNITTESTS_DB_SQL_FACTORY_CLASSNAME, CreateUnknownReturnsNull)
{
  EXPECT_EQ(DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_UNKNOWN), (DB_SQL_DATABASE*)NULL);
}


TEST(UNITTESTS_DB_SQL_FACTORY_CLASSNAME, CreateSqliteReturnsSqliteTypeAndName)
{
#ifdef DB_SQLITE_ACTIVE
  DB_SQL_DATABASE* db = DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_SQLITE);

  ASSERT_NE(db, (DB_SQL_DATABASE*)NULL);
  EXPECT_EQ(db->GetType(), DB_SQL_DATABASE_TYPE_SQLITE);

  XSTRING name;
  name = db->GetTypeName();
  EXPECT_EQ(name.Compare(__L("SQLite"), true), 0);

  GEN_DELETE db;
#else
  EXPECT_EQ(DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_SQLITE), (DB_SQL_DATABASE*)NULL);
#endif
}


TEST(UNITTESTS_DB_SQL_FACTORY_CLASSNAME, CreateMysqlReturnsNullWhenFeatureOff)
{
#ifndef DB_MYSQL_ACTIVE
  EXPECT_EQ(DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_MYSQL), (DB_SQL_DATABASE*)NULL);
#endif
}


TEST(UNITTESTS_DB_SQL_FACTORY_CLASSNAME, CreatePostgreSqlReturnsNullWhenFeatureOff)
{
#ifndef DB_POSTGRESQL_ACTIVE
  EXPECT_EQ(DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_POSTGRESQL), (DB_SQL_DATABASE*)NULL);
#endif
}


}
#endif
#endif
