/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOCLIProtocol.cpp
*
* @class      UNITTESTS_DATAIO_DIOCLIPROTOCOL
* @brief      DataIO unit tests for DIOCLIPROTOCOL class
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

#include "DIOCLIProtocol.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_PROTOCOL_CLI_ACTIVE
namespace TEST_DIOCLIPROTOCOL
{


TEST(DIOCLIPROTOCOLCOMMAND, SetGetCommand)
{
  DIOCLIPROTOCOLCOMMAND cmd;

  EXPECT_TRUE(cmd.Set(_L("HELP"), 0));
  ASSERT_NE(cmd.GetCommand(), (XCHAR*)NULL);
  EXPECT_EQ(XSTRING(cmd.GetCommand()).Compare(_L("HELP")), 0);
  EXPECT_EQ(cmd.GetNParams(), 0);
}


TEST(DIOCLIPROTOCOLANSWER, OriginCommandAnswerStrings)
{
  DIOCLIPROTOCOLANSWER answer;

  answer.GetOriginID()->Set(_L("A"));
  answer.GetCommand()->Set(_L("CMD"));
  answer.GetAnswer()->Set(_L("ok"));

  EXPECT_EQ(answer.GetOriginID()->Compare(_L("A")), 0);
  EXPECT_EQ(answer.GetCommand()->Compare(_L("CMD")), 0);
  EXPECT_EQ(answer.GetAnswer()->Compare(_L("ok")), 0);
}


TEST(DIOCLIPROTOCOL, ConstructNotIniWithoutStream)
{
  DIOCLIPROTOCOL protocol;

  EXPECT_FALSE(protocol.IsIni());
}


}
#endif
#endif
#endif
