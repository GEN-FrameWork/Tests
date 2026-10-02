/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOCoreProtocol_CFG.cpp
*
* @class      UNITTESTS_DATAIO_DIOCOREPROTOCOL_CFG
* @brief      DataIO unit tests for DIOCOREPROTOCOL_CFG class
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

#include "DIOCoreProtocol_CFG.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_COREPROTOCOL_ACTIVE
namespace TEST_DIOCOREPROTOCOL_CFG
{


TEST(DIOCOREPROTOCOL_CFG, DefaultsAndSetters)
{
  DIOCOREPROTOCOL_CFG cfg;

  cfg.SetIsServer(true);
  EXPECT_TRUE(cfg.GetIsServer());

  cfg.SetIsCompressHeader(true);
  cfg.SetIsCompressContent(true);
  cfg.SetIsEncapsulatedBase64(false);
  cfg.SetMinSizeCompressContent(200);
  cfg.SetIsCipher(false);

  EXPECT_TRUE(cfg.GetIsCompressHeader());
  EXPECT_TRUE(cfg.GetIsCompressContent());
  EXPECT_FALSE(cfg.GetIsEncapsulatedBase64());
  EXPECT_EQ(cfg.GetMinSizeCompressContent(), (XDWORD)200);
  EXPECT_FALSE(cfg.GetIsCipher());

  cfg.SetTimeOutNoResponse(7);
  cfg.SetTimeToEliminateConnectionDisconnect(8);
  cfg.SetTimeToCheckConnection(90);
  cfg.SetNTrysToCheckConnection(4);

  EXPECT_EQ(cfg.GetTimeOutNoResponse(), (XDWORD)7);
  EXPECT_EQ(cfg.GetTimeToEliminateConnectionDisconnect(), (XDWORD)8);
  EXPECT_EQ(cfg.GetTimeToCheckConnection(), (XDWORD)90);
  EXPECT_EQ(cfg.GetNTrysToCheckConnection(), (XDWORD)4);

  EXPECT_TRUE(cfg.BusMode_Activate(true, 40, 200));
  EXPECT_TRUE(cfg.BusMode_IsActive());
  EXPECT_EQ(cfg.BusMode_GetTimeOutBusFree(), (XDWORD)40);
  EXPECT_EQ(cfg.BusMode_GetTimeOutSendData(), (XDWORD)200);
}


}
#endif
#endif
#endif
