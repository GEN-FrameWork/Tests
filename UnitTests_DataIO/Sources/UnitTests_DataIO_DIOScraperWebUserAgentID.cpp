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
  XSTRING                 ask(_L("ua-chrome-cache-key"));

  ASSERT_NE(entry, (DIOUSERAGENTID_RESULT*)NULL);
  EXPECT_TRUE(source.Set(_L("Chrome"), _L("120.0.0.0"), _L("Browser"), _L("Windows 10"), _L("Windows"), _L("10"), NULL, NULL));
  EXPECT_FALSE(source.IsEmpty());
  EXPECT_EQ(XSTRING(source.GetBrowser()).Compare(_L("Chrome")), 0);
  EXPECT_EQ(XSTRING(source.GetSO()).Compare(_L("Windows 10")), 0);

  EXPECT_TRUE(entry->CopyFrom(&source));
  EXPECT_TRUE(cache.Add(ask, entry));

  DIOUSERAGENTID_RESULT* cached = (DIOUSERAGENTID_RESULT*)cache.Get(ask);
  ASSERT_NE(cached, (DIOUSERAGENTID_RESULT*)NULL);
  EXPECT_EQ(XSTRING(cached->GetBrowser()).Compare(_L("Chrome")), 0);
  EXPECT_EQ(XSTRING(cached->GetBrowserVersion()).Compare(_L("120.0.0.0")), 0);
  EXPECT_TRUE(cache.DeleteAll());
}


}
#endif
#endif
#endif
