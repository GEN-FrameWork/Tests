/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Sound_SNDFactory_XEvent.cpp
*
* @class      UNITTESTS_SOUND_SNDFACTORY_XEVENT
* @brief      Sound unit tests for SNDFACTORY_XEVENT class
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

#include "UnitTests_Sound_SNDFactory_XEvent.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "SNDFactory_XEvent.h"
#include "SNDItem.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef SND_ACTIVE
namespace TEST_SNDFACTORY_XEVENT
{


TEST(UNITTESTS_SNDFACTORY_XEVENT_CLASSNAME, ConstructWithNullSubject)
{
  SNDFACTORY_XEVENT event((XSUBJECT*)NULL);

  EXPECT_EQ(event.GetItem(), (SNDITEM*)NULL);
}


TEST(UNITTESTS_SNDFACTORY_XEVENT_CLASSNAME, SetGetItemRoundTrip)
{
  SNDFACTORY_XEVENT event((XSUBJECT*)NULL);
  SNDITEM           item;

  event.SetItem(&item);

  EXPECT_EQ(event.GetItem(), &item);
}


}
#endif
#endif
