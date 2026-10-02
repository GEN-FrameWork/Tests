/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOApplicationUpdate.cpp
*
* @class      UNITTESTS_DATAIO_DIOAPPLICATIONUPDATE
* @brief      DataIO unit tests for DIOAPPLICATIONUPDATE class
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

#include "XPath.h"

#include "DIOApplicationUpdate.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
namespace TEST_DIOAPPLICATIONUPDATE
{


TEST(DIOAPPLICATIONUPDATE_VERSIONDATA, SetCompareCopy)
{
  DIOAPPLICATIONUPDATE_VERSIONDATA a;
  DIOAPPLICATIONUPDATE_VERSIONDATA b;

  a.SetVersion(1);
  a.SetSubVersion(2);
  a.SetSubVersionError(3);
  a.SetSystemMustBeInit(true);

  EXPECT_EQ(a.GetVersion(), (XDWORD)1);
  EXPECT_EQ(a.GetSubVersion(), (XDWORD)2);
  EXPECT_EQ(a.GetSubVersionError(), (XDWORD)3);
  EXPECT_TRUE(a.SystemMustBeInit());
  EXPECT_EQ(a.Compare(1, 2, 3), 0);

  EXPECT_TRUE(a.CopyTo(b));
  EXPECT_EQ(b.GetVersion(), (XDWORD)1);
}


TEST(DIOAPPLICATIONUPDATE, ConstructVersionsNoDownload)
{
  XPATH xpath(__L("."));
  DIOAPPLICATIONUPDATE update(1, 0, 0, __L("UnitTests_DataIO"), xpath);

  EXPECT_EQ(update.Application_GetVersion(), (XDWORD)1);
  EXPECT_EQ(update.GetApplicationSubversion(), (XDWORD)0);
  EXPECT_EQ(update.GetApplicationSubVersionError(), (XDWORD)0);
}


}
#endif
#endif
