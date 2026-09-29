/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibRand.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBRAND
* @brief      Unit tests for SCRIPT_LIB_RAND
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

#include "GEN_Defines.h"
#include "UnitTests_Script_ScriptLibRand.h"
#include "UnitTests_Script_TestHelpers.h"
#include "Script_Lib_Rand.h"
#include "GEN_Control.h"

#ifdef GOOGLETEST_ACTIVE
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBRAND, UNITTESTS_SCRIPTLIBRAND_CLASSNAME, SCRIPT_LIB_RAND, SCRIPT_LIB_NAME_RANDOM, __L("RandBetween"))

namespace TEST_SCRIPTLIBRAND
{
TEST(UNITTESTS_SCRIPTLIBRAND_CLASSNAME, OwnsRandomGenerator)
{
  SCRIPT_LIB_RAND library;
  EXPECT_NE(library.GetXRand(), (XRAND*)NULL);
}


TEST(UNITTESTS_SCRIPTLIBRAND_CLASSNAME, RandBetweenReturnsValueInsideInclusiveRange)
{
  SCRIPT script;
  SCRIPT_LIB_RAND library;
  XVARIANT minvalue(5);
  XVARIANT maxvalue(5);
  XVARIANT result;
  XVECTOR<XVARIANT*> params;

  params.Add(&minvalue);
  params.Add(&maxvalue);
  Call_RandBetween(&library, &script, &params, &result);
  EXPECT_EQ((int)result, 5);

  minvalue = 10;
  maxvalue = 20;
  for(int i = 0; i < 20; i++)
    {
      Call_RandBetween(&library, &script, &params, &result);
      int value = (int)result;
      EXPECT_GE(value, 10);
      EXPECT_LE(value, 20);
    }
}


TEST(UNITTESTS_SCRIPTLIBRAND_CLASSNAME, RandBetweenRejectsMissingArguments)
{
  SCRIPT_LIB_RAND                library;
  UNITTESTS_SCRIPT_ERRORCAPTURE  script;
  XVARIANT                       onlymin(1);
  XVARIANT                       result;
  XVECTOR<XVARIANT*>             params;

  params.Add(&onlymin);
  Call_RandBetween(&library, &script, &params, &result);
  EXPECT_EQ(script.GetLastError(), SCRIPT_ERRORCODE_INSUF_PARAMS);
}
}
#endif
