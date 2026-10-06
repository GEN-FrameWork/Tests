/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOCoreProtocol_Header.cpp
*
* @class      UNITTESTS_DATAIO_DIOCOREPROTOCOL_HEADER
* @brief      DataIO unit tests for DIOCOREPROTOCOL_HEADER class
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

#include "DIOCoreProtocol_Header.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_COREPROTOCOL_ACTIVE
namespace TEST_DIOCOREPROTOCOL_HEADER
{


TEST(DIOCOREPROTOCOL_HEADER, SettersAndCopyCompare)
{
  DIOCOREPROTOCOL_HEADER a;
  DIOCOREPROTOCOL_HEADER b;

  a.SetMessageType(DIOCOREPROTOCOL_HEADER_MESSAGETYPE_REQUEST);
  a.SetOperation(DIOCOREPROTOCOL_HEADER_OPERATION_COMMAND);
  a.GetOperationParam()->Set(_L("ping"));
  a.SetContentType(DIOCOREPROTOCOL_HEADER_CONTENTTYPE_TEXT);
  a.SetBlockIndex(1);
  a.SetBlockAmount(2);
  a.SetContentSize(10);
  a.SetContentCompressSize(0);
  a.SetContentCRC32(0x12345678);

  EXPECT_EQ(a.GetMessageType(), DIOCOREPROTOCOL_HEADER_MESSAGETYPE_REQUEST);
  EXPECT_EQ(a.GetOperation(), DIOCOREPROTOCOL_HEADER_OPERATION_COMMAND);
  EXPECT_EQ(a.GetOperationParam()->Compare(_L("ping")), 0);
  EXPECT_EQ(a.GetContentType(), DIOCOREPROTOCOL_HEADER_CONTENTTYPE_TEXT);
  EXPECT_EQ(a.GetBlockIndex(), (XDWORD)1);
  EXPECT_EQ(a.GetBlockAmount(), (XDWORD)2);
  EXPECT_EQ(a.GetContentSize(), (XDWORD)10);
  EXPECT_EQ(a.GetContentCRC32(), (XDWORD)0x12345678);

  EXPECT_TRUE(a.CopyTo(&b));
  EXPECT_TRUE(a.Compare(&b));
}


}
#endif
#endif
#endif
