/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Input_INPFactory.cpp
*
* @class      UNITTESTS_INPUT_INPFACTORY
* @brief      Input unit tests for INPFACTORY class
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

#include "UnitTests_Input_INPFactory.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "INPFactory.h"
#include "INPDevice.h"
#include "INPSimulate.h"
#include "INPCapture.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_INPFACTORY
{


TEST(UNITTESTS_INPFACTORY_CLASSNAME, GetInstanceIsInstanced)
{
  INPFACTORY& factory = INPFACTORY::GetInstance();

  EXPECT_TRUE(INPFACTORY::GetIsInstanced());
  EXPECT_EQ(&factory, &INPFACTORY::GetInstance());
}


TEST(UNITTESTS_INPFACTORY_CLASSNAME, CreateDeviceWithNullParamDoesNotCrash)
{
  INPFACTORY& factory = INPFACTORY::GetInstance();

  INPDEVICE* device = factory.CreateDevice(INPDEVICE_TYPE_KEYBOARD, NULL);
  if(device)
    {
      EXPECT_TRUE(factory.DeleteDevice(device));
    }
}


#ifdef INP_SIMULATE_ACTIVE
TEST(UNITTESTS_INPFACTORY_CLASSNAME, CreateSimulatorAndDelete)
{
  INPFACTORY& factory = INPFACTORY::GetInstance();

  INPSIMULATE* simulator = factory.CreateSimulator();
  if(simulator)
    {
      ALTERNATIVE_KEY altkey = ALTERNATIVE_KEY_NONE;
      EXPECT_EQ(simulator->GetKDBCodeByLiteral(__L("A"), altkey), (XBYTE)0x41);
      EXPECT_EQ(altkey, ALTERNATIVE_KEY_NONE);

      EXPECT_TRUE(factory.DeleteSimulator(simulator));
    }
}
#endif


#ifdef INP_CAPTURE_ACTIVE
TEST(UNITTESTS_INPFACTORY_CLASSNAME, CreateCaptureAndDelete)
{
  INPFACTORY& factory = INPFACTORY::GetInstance();

  INPCAPTURE* capture = factory.CreateCapture();
  if(capture)
    {
      // Do not call Activate — offline / no OS hooks.
      EXPECT_TRUE(factory.DeleteCapture(capture));
    }
}
#endif


}
#endif
