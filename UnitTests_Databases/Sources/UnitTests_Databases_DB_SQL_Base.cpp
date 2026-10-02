/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Databases_DB_SQL_Base.cpp
*
* @class      UNITTESTS_DATABASES_DB_SQL_BASE
* @brief      Databases unit tests for DB_SQL_Base defines
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

#include "UnitTests_Databases_DB_SQL_Base.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "DB_SQL_Base.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DB_SQL_ACTIVE
namespace TEST_DB_SQL_BASE
{


TEST(UNITTESTS_DB_SQL_BASE_CLASSNAME, DatabaseTypeEnumValuesAreDistinct)
{
  EXPECT_EQ(DB_SQL_DATABASE_TYPE_UNKNOWN, 0);
  EXPECT_EQ(DB_SQL_DATABASE_TYPE_SQLITE, DB_SQL_DATABASE_TYPE_UNKNOWN + 1);
  EXPECT_EQ(DB_SQL_DATABASE_TYPE_MYSQL, DB_SQL_DATABASE_TYPE_SQLITE + 1);
  EXPECT_EQ(DB_SQL_DATABASE_TYPE_POSTGRESQL, DB_SQL_DATABASE_TYPE_MYSQL + 1);

  EXPECT_NE(DB_SQL_DATABASE_TYPE_UNKNOWN, DB_SQL_DATABASE_TYPE_SQLITE);
  EXPECT_NE(DB_SQL_DATABASE_TYPE_SQLITE, DB_SQL_DATABASE_TYPE_MYSQL);
  EXPECT_NE(DB_SQL_DATABASE_TYPE_MYSQL, DB_SQL_DATABASE_TYPE_POSTGRESQL);
}


TEST(UNITTESTS_DB_SQL_BASE_CLASSNAME, MysqlOkMacroIsZero)
{
  EXPECT_EQ(DB_SQL_MYSQL_OK, 0);
}


}
#endif
#endif
