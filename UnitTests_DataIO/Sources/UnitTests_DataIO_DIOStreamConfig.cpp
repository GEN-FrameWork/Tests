/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOStreamConfig.cpp
*
* @class      UNITTESTS_DATAIO_DIOSTREAMCONFIG
* @brief      DataIO unit tests for DIOSTREAMCONFIG class
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

#include "DIOStreamConfig.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
namespace TEST_DIOSTREAMCONFIG
{


TEST(DIOSTREAMCONFIG, DefaultsAndSetters)
{
  DIOSTREAMCONFIG cfg;

  cfg.SetType(DIOSTREAMTYPE_UDP);
  EXPECT_EQ(cfg.GetType(), DIOSTREAMTYPE_UDP);

  cfg.SetMode(DIOSTREAMMODE_CLIENT);
  EXPECT_EQ(cfg.GetMode(), DIOSTREAMMODE_CLIENT);
  EXPECT_FALSE(cfg.IsServer());

  cfg.SetMode(DIOSTREAMMODE_SERVER);
  EXPECT_TRUE(cfg.IsServer());

  cfg.SetIsTLS(false);
  EXPECT_FALSE(cfg.IsTLS());

  cfg.SetSizeBufferSO(4096);
  EXPECT_EQ(cfg.GetSizeBufferSO(), (XDWORD)4096);

  cfg.SetThreadWaitYield(5);
  EXPECT_EQ(cfg.GetThreadWaitYield(), (XDWORD)5);

  cfg.SetPollInterval(20);
  EXPECT_EQ(cfg.GetPollInterval(), (XDWORD)20);
}


}
#endif
#endif
