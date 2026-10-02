/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_XUtils_XTraceServer.cpp
*
* @class      UNITTESTS_XUTILS_XTRACESERVER
* @brief      XUtils unit tests for XTraceServer class
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

#include "UnitTests_XUtils_XTraceServer.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XTrace.h"
#include "XTraceServer.h"
#include "XFactory.h"
#include "XDateTime.h"
#include "XBuffer.h"
#include "XString.h"
#include "XSleep.h"
#include "XThreadCollected.h"

#if defined(DIO_ACTIVE) && defined(DIO_STREAMUDP_ACTIVE)
#include "DIOFactory.h"
#include "DIOStreamUDPConfig.h"
#include "DIOStreamUDP.h"
#endif



/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"




/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/



/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/


#if defined(GOOGLETEST_ACTIVE) && defined(DIO_ACTIVE) && defined(DIO_STREAMUDP_ACTIVE)

namespace TEST_XTRACESERVER
{

static const XWORD UNITTESTS_XTRACESERVER_PORT = 29111;


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         static bool SendTracePacket(XWORD port, XDWORD sequence, XCHAR* text)
* @brief      Builds an XTRACE packet and sends it by UDP to 127.0.0.1:port.
* @ingroup    UNIT TEST
*
* --------------------------------------------------------------------------------------------------------------------*/
static bool SendTracePacket(XWORD port, XDWORD sequence, XCHAR* text)
{
  if(!XTRACE::instance) return false;
  if(!text) return false;

  DIOSTREAMUDPCONFIG  udpcfg;
  DIOSTREAMUDP*       udpclient = NULL;
  XDATETIME           xtime;
  XBUFFER             packet;
  XSTRING             address(__L("127.0.0.1"));
  bool                status = false;

  udpcfg.SetMode(DIOSTREAMMODE_CLIENT);
  udpcfg.SetIsUsedDatagrams(true);
  udpcfg.GetRemoteURL()->Set(address);
  udpcfg.SetRemotePort(port);

  udpclient = (DIOSTREAMUDP*)GEN_DIOFACTORY.CreateStreamIO(&udpcfg);
  if(!udpclient) return false;

  if(udpclient->Open())
    {
      xtime.Read();

      if(XTRACE::instance->SetTraceTextToXBuffer(0, 0x7F000001, XTRACE_COLOR_GREEN, sequence, &xtime, text, packet))
        {
          if(udpclient->WriteDatagram(address, port, packet))
            {
              udpclient->WaitToWriteDatagramsEmpty(1000);
              status = true;
            }
        }

      udpclient->Close();
    }

  GEN_DIOFACTORY.DeleteStreamIO(udpclient);

  return status;
}


TEST(UNITTESTS_XTRACESERVER_CLASSNAME, DefaultStateIsClosedAndEmpty)
{
  ACTIVATEXTHREADGROUP(XTHREADGROUPID_DIOSTREAM);

  XTRACESERVER server;

  EXPECT_FALSE(server.IsOpen());
  EXPECT_FALSE(server.IsOpenUDP());
  EXPECT_EQ(server.GetCount(), (XDWORD)0);
  EXPECT_EQ(server.GetDroppedCount(), (XDWORD)0);

  XTRACESERVER_MSG msg;
  EXPECT_FALSE(server.Pop(msg));
  EXPECT_FALSE(server.Peek(0, msg));
  EXPECT_FALSE(server.WaitPop(msg, 0));
}


TEST(UNITTESTS_XTRACESERVER_CLASSNAME, IniOpensUdpAndEndCloses)
{
  ACTIVATEXTHREADGROUP(XTHREADGROUPID_DIOSTREAM);

  XTRACESERVER server;

  ASSERT_TRUE(server.Ini(UNITTESTS_XTRACESERVER_PORT));
  EXPECT_TRUE(server.IsOpen());
  EXPECT_TRUE(server.IsOpenUDP());

  EXPECT_TRUE(server.End());
  EXPECT_FALSE(server.IsOpen());
  EXPECT_FALSE(server.IsOpenUDP());
}


TEST(UNITTESTS_XTRACESERVER_CLASSNAME, ReceivesUdpPacketsAndPopsInOrder)
{
  ACTIVATEXTHREADGROUP(XTHREADGROUPID_DIOSTREAM);

  XTRACESERVER     server;
  XTRACESERVER_MSG msg1;
  XTRACESERVER_MSG msg2;
  XSTRING          marker1(__L("UNITTEST_XTRACESERVER_MSG1"));
  XSTRING          marker2(__L("UNITTEST_XTRACESERVER_MSG2"));

  ASSERT_TRUE(server.Ini((XWORD)(UNITTESTS_XTRACESERVER_PORT + 1)));
  GEN_XSLEEP.MilliSeconds(50);

  ASSERT_TRUE(SendTracePacket((XWORD)(UNITTESTS_XTRACESERVER_PORT + 1), 11, marker1.Get()));
  ASSERT_TRUE(SendTracePacket((XWORD)(UNITTESTS_XTRACESERVER_PORT + 1), 22, marker2.Get()));
  GEN_XSLEEP.MilliSeconds(100);

  ASSERT_TRUE(server.WaitPop(msg1, 3000));
  ASSERT_TRUE(server.WaitPop(msg2, 3000));

  EXPECT_EQ(msg1.sequence, (XDWORD)11);
  EXPECT_EQ(msg2.sequence, (XDWORD)22);
  EXPECT_NE(msg1.text.Find(marker1.Get(), true), XSTRING_NOTFOUND);
  EXPECT_NE(msg2.text.Find(marker2.Get(), true), XSTRING_NOTFOUND);
  EXPECT_EQ(server.GetCount(), (XDWORD)0);

  server.End();
}


TEST(UNITTESTS_XTRACESERVER_CLASSNAME, PeekDoesNotRemoveAndClearEmptiesQueue)
{
  ACTIVATEXTHREADGROUP(XTHREADGROUPID_DIOSTREAM);

  XTRACESERVER     server;
  XTRACESERVER_MSG peekmsg;
  XTRACESERVER_MSG popmsg;
  XSTRING          marker(__L("UNITTEST_XTRACESERVER_PEEK"));
  XWORD            port = (XWORD)(UNITTESTS_XTRACESERVER_PORT + 2);

  ASSERT_TRUE(server.Ini(port));
  GEN_XSLEEP.MilliSeconds(50);

  ASSERT_TRUE(SendTracePacket(port, 7, marker.Get()));
  GEN_XSLEEP.MilliSeconds(100);

  ASSERT_GE(server.GetCount(), (XDWORD)1);
  ASSERT_TRUE(server.Peek(0, peekmsg));
  EXPECT_EQ(server.GetCount(), (XDWORD)1);
  EXPECT_NE(peekmsg.text.Find(marker.Get(), true), XSTRING_NOTFOUND);

  EXPECT_TRUE(server.Clear());
  EXPECT_EQ(server.GetCount(), (XDWORD)0);
  EXPECT_FALSE(server.Pop(popmsg));

  server.End();
}


TEST(UNITTESTS_XTRACESERVER_CLASSNAME, BoundedQueueDropsOldest)
{
  ACTIVATEXTHREADGROUP(XTHREADGROUPID_DIOSTREAM);

  XTRACESERVER     server;
  XTRACESERVER_MSG msg;
  XWORD            port = (XWORD)(UNITTESTS_XTRACESERVER_PORT + 3);

  ASSERT_TRUE(server.Ini(port));
  server.SetMaxMessages(2);
  EXPECT_EQ(server.GetMaxMessages(), (XDWORD)2);

  GEN_XSLEEP.MilliSeconds(50);

  ASSERT_TRUE(SendTracePacket(port, 1, __L("DROP_A")));
  ASSERT_TRUE(SendTracePacket(port, 2, __L("DROP_B")));
  ASSERT_TRUE(SendTracePacket(port, 3, __L("DROP_C")));
  GEN_XSLEEP.MilliSeconds(150);

  EXPECT_LE(server.GetCount(), (XDWORD)2);
  EXPECT_GE(server.GetDroppedCount(), (XDWORD)1);

  ASSERT_TRUE(server.WaitPop(msg, 3000));
  EXPECT_EQ(msg.text.Find(__L("DROP_A"), true), XSTRING_NOTFOUND);

  server.End();
}


TEST(UNITTESTS_XTRACESERVER_CLASSNAME, WaitPopTimesOutWhenEmpty)
{
  ACTIVATEXTHREADGROUP(XTHREADGROUPID_DIOSTREAM);

  XTRACESERVER     server;
  XTRACESERVER_MSG msg;

  ASSERT_TRUE(server.Ini((XWORD)(UNITTESTS_XTRACESERVER_PORT + 4)));
  EXPECT_FALSE(server.WaitPop(msg, 200));
  EXPECT_EQ(server.GetCount(), (XDWORD)0);

  server.End();
}


}

#endif
