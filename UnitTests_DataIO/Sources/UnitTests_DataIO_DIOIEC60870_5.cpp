/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOIEC60870_5.cpp
*
* @class      UNITTESTS_DATAIO_DIOIEC60870_5
* @brief      DataIO unit tests for DIOIEC60870_5 class
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

#include "XDateTime.h"

#include "DIOIEC60870_5.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_IEC60870_5_ACTIVE
namespace TEST_DIOIEC60870_5
{


TEST(DIO_C_TR_AA_RESULT, PowerSettersOffline)
{
  DIO_C_TR_AA_RESULT result;

  EXPECT_TRUE(result.SetActiveImport(100));
  EXPECT_EQ(result.GetActiveImport(), 100);
  EXPECT_TRUE(result.SetActiveExport(50));
  EXPECT_EQ(result.GetActiveExport(), 50);
  EXPECT_TRUE(result.SetTotalActivePower(150));
  EXPECT_EQ(result.GetTotalActivePower(), 150);
  EXPECT_TRUE(result.SetTotalPowerFactor(0.95f));
}


TEST(DIOIEC60870_5, ConstructNullStreamNoConnect)
{
  DIOIEC60870_5 iec((DIOSTREAM*)NULL);

  EXPECT_TRUE(true);
}


TEST(DIOIEC60870_5, TimeLabelTypeARoundTrip)
{
  DIOIEC60870_5 iec((DIOSTREAM*)NULL);
  XDATETIME     dt;
  XBYTE         buffer[DIOIEC60870_5_SIZEMAXTIMELABELTYPEA];
  bool          rate   = false;
  bool          vi     = false;
  bool          summer = false;

  dt.SetToZero();
  EXPECT_TRUE(iec.SetTimeLabelTypeA(dt, false, false, false, buffer));
  EXPECT_TRUE(iec.GetTimeLabelTypeA(buffer, rate, vi, summer, dt));
}


}
#endif
#endif
#endif
