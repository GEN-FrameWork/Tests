/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOStreamUARTConfig.cpp
*
* @class      UNITTESTS_DATAIO_DIOSTREAMUARTCONFIG
* @brief      DataIO unit tests for DIOSTREAMUARTCONFIG class
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

#include "DIOStreamUARTConfig.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_STREAMUART_ACTIVE
namespace TEST_DIOSTREAMUARTCONFIG
{


TEST(DIOSTREAMUARTCONFIG, SettersAndFromToString)
{
  DIOSTREAMUARTCONFIG cfg;
  XSTRING             text;

  EXPECT_EQ(cfg.GetType(), DIOSTREAMTYPE_UART);

  cfg.SetPort(1);
  EXPECT_EQ(cfg.GetPort(), 1);

  cfg.GetLocalDeviceName()->Set(__L("COM1"));
  cfg.SetBaudRate(115200);
  cfg.SetDataBits(DIOSTREAMUARTDATABIT_8);
  cfg.SetParity(DIOSTREAMUARTPARITY_NONE);
  cfg.SetStopBits(DIOSTREAMUARTSTOPBITS_ONE);
  cfg.SetFlowControl(DIOSTREAMUARTFLOWCONTROL_NONE);

  EXPECT_EQ(cfg.GetBaudRate(), 115200);
  EXPECT_EQ(cfg.GetDataBits(), DIOSTREAMUARTDATABIT_8);

  EXPECT_TRUE(cfg.GetToString(text));
  EXPECT_FALSE(text.IsEmpty());

  // SetFromString expects device,baud,databits,parity,stopbits,flowcontrol
  // (GetToString omits stopbits — use a canonical string for the round-trip).
  DIOSTREAMUARTCONFIG cfg2;
  XSTRING             fromstr(__L("COM1,115200,8,N,1,NONE"));
  EXPECT_TRUE(cfg2.SetFromString(fromstr));
  EXPECT_EQ(cfg2.GetBaudRate(), 115200);
  EXPECT_EQ(cfg2.GetDataBits(), DIOSTREAMUARTDATABIT_8);
  EXPECT_EQ(cfg2.GetParity(), DIOSTREAMUARTPARITY_NONE);
}


}
#endif
#endif
#endif
