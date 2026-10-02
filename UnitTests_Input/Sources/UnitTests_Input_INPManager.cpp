/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Input_INPManager.cpp
*
* @class      UNITTESTS_INPUT_INPMANAGER
* @brief      Input unit tests for INPMANAGER class
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

#include "UnitTests_Input_INPManager.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "INPManager.h"
#include "INPDevice.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE

class UNITTESTS_INPUT_STUBDEVICE : public INPDEVICE
{
  public:

    UNITTESTS_INPUT_STUBDEVICE()
    {
      created = true;
      SetType(INPDEVICE_TYPE_KEYBOARD);
    }
};


namespace TEST_INPMANAGER
{


TEST(UNITTESTS_INPMANAGER_CLASSNAME, DelInstanceIsolationAndGetIsInstancedFalse)
{
  INPMANAGER::DelInstance();

  EXPECT_FALSE(INPMANAGER::GetIsInstanced());
}


TEST(UNITTESTS_INPMANAGER_CLASSNAME, GetInstance)
{
  INPMANAGER::DelInstance();

  INPMANAGER& manager = INPMANAGER::GetInstance();

  EXPECT_TRUE(INPMANAGER::GetIsInstanced());
  EXPECT_EQ(&manager, &INPMANAGER::GetInstance());

  INPMANAGER::DelInstance();
}


TEST(UNITTESTS_INPMANAGER_CLASSNAME, AddDeviceNullFalse)
{
  INPMANAGER::DelInstance();

  INPMANAGER& manager = INPMANAGER::GetInstance();

  EXPECT_FALSE(manager.AddDevice(NULL));

  INPMANAGER::DelInstance();
}


TEST(UNITTESTS_INPMANAGER_CLASSNAME, AddDeviceStubAndGetNDevices)
{
  INPMANAGER::DelInstance();

  INPMANAGER& manager = INPMANAGER::GetInstance();

  UNITTESTS_INPUT_STUBDEVICE* stub = GEN_NEW UNITTESTS_INPUT_STUBDEVICE();
  ASSERT_NE(stub, (UNITTESTS_INPUT_STUBDEVICE*)NULL);

  EXPECT_TRUE(manager.AddDevice(stub));
  EXPECT_EQ(manager.GetNDevices(), 1);

  INPMANAGER::DelInstance();
}


TEST(UNITTESTS_INPMANAGER_CLASSNAME, GetDeviceByIndexAndType)
{
  INPMANAGER::DelInstance();

  INPMANAGER& manager = INPMANAGER::GetInstance();

  UNITTESTS_INPUT_STUBDEVICE* stub = GEN_NEW UNITTESTS_INPUT_STUBDEVICE();
  ASSERT_NE(stub, (UNITTESTS_INPUT_STUBDEVICE*)NULL);

  EXPECT_TRUE(manager.AddDevice(stub));

  EXPECT_EQ(manager.GetDevice(0), (INPDEVICE*)stub);
  EXPECT_EQ(manager.GetDevice(INPDEVICE_TYPE_KEYBOARD), (INPDEVICE*)stub);
  EXPECT_EQ(manager.GetDevice(INPDEVICE_TYPE_MOUSE), (INPDEVICE*)NULL);

  INPMANAGER::DelInstance();
}


TEST(UNITTESTS_INPMANAGER_CLASSNAME, Update)
{
  INPMANAGER::DelInstance();

  INPMANAGER& manager = INPMANAGER::GetInstance();

  EXPECT_FALSE(manager.Update());

  UNITTESTS_INPUT_STUBDEVICE* stub = GEN_NEW UNITTESTS_INPUT_STUBDEVICE();
  ASSERT_NE(stub, (UNITTESTS_INPUT_STUBDEVICE*)NULL);

  EXPECT_TRUE(manager.AddDevice(stub));
  EXPECT_TRUE(manager.Update());

  INPMANAGER::DelInstance();
}


TEST(UNITTESTS_INPMANAGER_CLASSNAME, DelDevice)
{
  INPMANAGER::DelInstance();

  INPMANAGER& manager = INPMANAGER::GetInstance();

  UNITTESTS_INPUT_STUBDEVICE* stub = GEN_NEW UNITTESTS_INPUT_STUBDEVICE();
  ASSERT_NE(stub, (UNITTESTS_INPUT_STUBDEVICE*)NULL);

  EXPECT_TRUE(manager.AddDevice(stub));
  EXPECT_TRUE(manager.DelDevice(stub));
  EXPECT_EQ(manager.GetNDevices(), 0);

  INPMANAGER::DelInstance();
}


TEST(UNITTESTS_INPMANAGER_CLASSNAME, DeleteAllDevices)
{
  INPMANAGER::DelInstance();

  INPMANAGER& manager = INPMANAGER::GetInstance();

  UNITTESTS_INPUT_STUBDEVICE* stub = GEN_NEW UNITTESTS_INPUT_STUBDEVICE();
  ASSERT_NE(stub, (UNITTESTS_INPUT_STUBDEVICE*)NULL);

  EXPECT_TRUE(manager.AddDevice(stub));
  EXPECT_TRUE(manager.DeleteAllDevices());
  EXPECT_EQ(manager.GetNDevices(), 0);
  EXPECT_FALSE(manager.DeleteAllDevices());

  INPMANAGER::DelInstance();
}


TEST(UNITTESTS_INPMANAGER_CLASSNAME, DelInstanceTeardown)
{
  INPMANAGER::DelInstance();

  INPMANAGER::GetInstance();
  EXPECT_TRUE(INPMANAGER::GetIsInstanced());

  EXPECT_TRUE(INPMANAGER::DelInstance());
  EXPECT_FALSE(INPMANAGER::GetIsInstanced());
}


}
#endif
