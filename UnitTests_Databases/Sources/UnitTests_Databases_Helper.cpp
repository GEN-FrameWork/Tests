/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Databases_Helper.cpp
*
* @class      UNITTESTS_DATABASES_HELPER
* @brief      Shared helpers for Databases unit tests (not a gtest suite)
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

#include "UnitTests_Databases_Helper.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#if defined(DB_SQL_ACTIVE) && defined(DB_SQLITE_ACTIVE)

namespace UNITTESTS_DATABASES_HELPER
{


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         DB_SQL_DATABASE* OpenSQLiteMemory(DB_SQL_CONNECTION** out_connection)
* @brief      Create an in-memory SQLite database via the factory and open it.
* @ingroup    UNIT TEST
*
* @param[out] out_connection : Receives the created connection (may be NULL on failure).
*
* @return     DB_SQL_DATABASE* : Opened database, or NULL on failure.
*
* --------------------------------------------------------------------------------------------------------------------*/
DB_SQL_DATABASE* OpenSQLiteMemory(DB_SQL_CONNECTION** out_connection)
{
  if(out_connection) (*out_connection) = NULL;

  DB_SQL_DATABASE* db = DB_SQL_FACTORY::Create(DB_SQL_DATABASE_TYPE_SQLITE);
  if(!db) return NULL;

  DB_SQL_CONNECTION* connection = db->CreateConnection();
  if(!connection)
    {
      GEN_DELETE db;
      return NULL;
    }

  connection->SetOption(__L("PATH")     , __L(""));
  connection->SetOption(__L("DATABASE") , __L(":memory:"));

  if(!db->Open())
    {
      db->SetConnection(NULL);
      GEN_DELETE connection;
      GEN_DELETE db;
      return NULL;
    }

  if(out_connection) (*out_connection) = connection;

  return db;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         void CloseAndDelete(DB_SQL_DATABASE* db, DB_SQL_CONNECTION* connection)
* @brief      Close the database, detach the connection, and delete both objects.
* @ingroup    UNIT TEST
*
* @param[in]  db : Database to close and delete (may be NULL).
* @param[in]  connection : Connection to delete (may be NULL).
*
* @return     void : does not return anything.
*
* --------------------------------------------------------------------------------------------------------------------*/
void CloseAndDelete(DB_SQL_DATABASE* db, DB_SQL_CONNECTION* connection)
{
  if(db)
    {
      db->Close();
      db->SetConnection(NULL);
    }

  GEN_DELETE connection;
  GEN_DELETE db;
}


}

#endif
