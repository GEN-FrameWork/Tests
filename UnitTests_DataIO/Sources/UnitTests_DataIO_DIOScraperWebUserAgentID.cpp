/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_DataIO_DIOScraperWebUserAgentID.cpp
*
* @brief      DataIO unit tests for DIOUSERAGENTID_RESULT / cache behaviour
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
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

#include "DIOScraperWebCache.h"

#ifdef DIO_SCRAPERWEB_USERAGENTID_ACTIVE
#include "DIOScraperWebUserAgentID.h"
#endif


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef DIO_ACTIVE
#ifdef DIO_SCRAPERWEB_USERAGENTID_ACTIVE
namespace TEST_DIOSCRAPERWEBUSERAGENTID
{


TEST(DIOSCRAPERWEBUSERAGENTID, ResultSetCopyAndCache)
{
  DIOSCRAPERWEBCACHE      cache;
  DIOUSERAGENTID_RESULT   source;
  DIOUSERAGENTID_RESULT*  entry = GEN_NEW DIOUSERAGENTID_RESULT();
  XSTRING                 ask(__L("ua-chrome-cache-key"));

  ASSERT_NE(entry, (DIOUSERAGENTID_RESULT*)NULL);
  EXPECT_TRUE(source.Set(__L("Chrome"), __L("120.0.0.0"), __L("Browser"), __L("Windows 10"), __L("Windows"), __L("10"), NULL, NULL));
  EXPECT_FALSE(source.IsEmpty());
  EXPECT_EQ(XSTRING(source.GetBrowser()).Compare(__L("Chrome")), 0);
  EXPECT_EQ(XSTRING(source.GetSO()).Compare(__L("Windows 10")), 0);

  EXPECT_TRUE(entry->CopyFrom(&source));
  EXPECT_TRUE(cache.Add(ask, entry));

  DIOUSERAGENTID_RESULT* cached = (DIOUSERAGENTID_RESULT*)cache.Get(ask);
  ASSERT_NE(cached, (DIOUSERAGENTID_RESULT*)NULL);
  EXPECT_EQ(XSTRING(cached->GetBrowser()).Compare(__L("Chrome")), 0);
  EXPECT_EQ(XSTRING(cached->GetBrowserVersion()).Compare(__L("120.0.0.0")), 0);
  EXPECT_TRUE(cache.DeleteAll());
}


}
#endif
#endif
#endif
