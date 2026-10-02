/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOStream.cpp
*
* @class      UNITTESTS_DATAIO_DIOSTREAM
* @brief      DataIO unit tests for DIOSTREAM class
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

#include "DIOStream.h"
#include "DIOStreamConfig.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_STREAMTCPIP_ACTIVE
namespace TEST_DIOSTREAM
{


class UNITTESTS_DATAIO_STUBSTREAM : public DIOSTREAM
{
  public:

    UNITTESTS_DATAIO_STUBSTREAM()
    {
      config = NULL;
    }

    DIOSTREAMCONFIG* GetConfig()
    {
      return config;
    }

    bool SetConfig(DIOSTREAMCONFIG* cfg)
    {
      config = cfg;
      return true;
    }

    bool Open()
    {
      return false;
    }

    bool Close()
    {
      return true;
    }

  private:

    DIOSTREAMCONFIG* config;
};


TEST(DIOSTREAM, StubStatusAndTypeWithoutOpen)
{
  UNITTESTS_DATAIO_STUBSTREAM stream;
  DIOSTREAMCONFIG             cfg;

  EXPECT_TRUE(stream.SetConfig(&cfg));
  EXPECT_EQ(stream.GetConfig(), &cfg);

  stream.SetType(DIOSTREAMTYPE_TCPIP);
  EXPECT_EQ(stream.GetType(), DIOSTREAMTYPE_TCPIP);

  stream.SetStatus(DIOSTREAMSTATUS_DISCONNECTED);
  EXPECT_TRUE(stream.IsDisconnected());
  EXPECT_FALSE(stream.IsConnected());

  stream.SetIsBlockRead(true);
  EXPECT_TRUE(stream.IsBlockRead());
  stream.SetIsBlockWrite(false);
  EXPECT_FALSE(stream.IsBlockWrite());

  stream.SetLastDIOError(DIOSTREAMERROR_UNKNOWN);
  EXPECT_EQ(stream.PeekLastDIOError(), DIOSTREAMERROR_UNKNOWN);
}


}
#endif
#endif
#endif
