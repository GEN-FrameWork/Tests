/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOCheckTCPIPConnections.cpp
*
* @class      UNITTESTS_DATAIO_DIOCHECKTCPIPCONNECTIONS
* @brief      DataIO unit tests for DIOCHECKTCPIPCONNECTIONS class
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

#include "UnitTests_DataIO_Helper.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XString.h"

#include "DIOCheckTCPIPConnections.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_CHECKCONNECTIONS_ACTIVE
namespace TEST_DIOCHECKTCPIPCONNECTIONS
{


TEST(DIOCHECKTCPIPCONNECTION, SetURLAndFlagsWithoutCheck)
{
  DIOCHECKTCPIPCONNECTION connection;

  EXPECT_TRUE(connection.Set(_L("127.0.0.1")));
  ASSERT_NE(connection.GetURL(), (DIOURL*)NULL);
  EXPECT_FALSE(connection.GetURL()->IsEmpty());

  connection.SetIsConnected(false);
  EXPECT_FALSE(connection.IsConnected());

  connection.SetNChecks(0);
  EXPECT_EQ(connection.GetNChecks(), (XDWORD)0);
  EXPECT_EQ(connection.IncNChecks(), (XDWORD)1);

  connection.SetElapsedTime(5);
  EXPECT_EQ(connection.GetElapsedTime(), (XDWORD)5);
}


TEST(DIOCHECKTCPIPCONNECTION_CUT, MeasureSecondsCopy)
{
  DIOCHECKTCPIPCONNECTION_CUT a;
  DIOCHECKTCPIPCONNECTION_CUT b;

  a.SetMeasureNSeconds(12);
  EXPECT_EQ(a.GetMeasureNSeconds(), 12);
  EXPECT_TRUE(a.CopyTo(&b));
  EXPECT_EQ(b.GetMeasureNSeconds(), 12);
}


TEST(DIOCHECKTCPIPCONNECTIONS, SetupWithoutIniRun)
{
  // Offline: do not Ini/Run (would spawn check thread / ping).
  DIOCHECKTCPIPCONNECTIONS checks;

  checks.Setup(10, false, false);
  EXPECT_EQ(checks.GetTimeConnectionChecks(), 10);
  EXPECT_TRUE(checks.Connections_DeleteAll());
}


}
#endif
#endif
#endif
