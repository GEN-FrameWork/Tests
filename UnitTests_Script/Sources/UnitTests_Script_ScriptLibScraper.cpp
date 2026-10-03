/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_ScriptLibScraper.cpp
*
* @class      UNITTESTS_SCRIPT_SCRIPTLIBSCRAPER
* @brief      Unit tests for SCRIPT_LIB_SCRAPER / DIOSCRAPERSCRIPT / typed PublicIP + Geo facades
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
#include "UnitTests_Script_ScriptLibScraper.h"
#include "UnitTests_Script_TestHelpers.h"

#if defined(SCRIPT_LIB_SCRAPER_ACTIVE) && defined(DIO_SCRAPERWEB_ACTIVE)
#include "Script_Lib_Scraper.h"
#include "DIOScraperScript.h"
#include "DIOIP.h"
#ifdef DIO_SCRAPERWEB_PUBLICIP_ACTIVE
#include "DIOScraperWebPublicIP.h"
#endif
#ifdef DIO_SCRAPERWEB_GEOLOCATIONIP_ACTIVE
#include "DIOScraperWebGeolocationIP.h"
#endif
#ifdef DIO_SCRAPERWEB_WEATHER_ACTIVE
#include "DIOScraperWebWeather.h"
#endif
#ifdef DIO_SCRAPERWEB_TRANSLATION_ACTIVE
#include "DIOScraperWebTranslation.h"
#endif
#ifdef DIO_SCRAPERWEB_MACMANUFACTURER_ACTIVE
#include "DIOScraperWebMACManufacturer.h"
#endif
#ifdef DIO_SCRAPERWEB_USERAGENTID_ACTIVE
#include "DIOURL.h"
#include "DIOScraperWebUserAgentID.h"
#endif
#endif

#include "GEN_Control.h"

#if defined(GOOGLETEST_ACTIVE) && defined(SCRIPT_LIB_SCRAPER_ACTIVE) && defined(DIO_SCRAPERWEB_ACTIVE)
UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(TEST_SCRIPTLIBSCRAPER, UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, SCRIPT_LIB_SCRAPER, SCRIPT_LIB_NAME_SCRAPER, __L("Scraper_SetResult"))

namespace TEST_SCRIPTLIBSCRAPER
{

TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, RegistersAllScraperHelpers)
{
  SCRIPT_LIB_SCRAPER library;
  SCRIPT             script;

  ASSERT_TRUE(library.AddLibraryFunctions(&script));
  EXPECT_NE(script.GetLibraryFunction(__L("Scraper_GetArg")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("Scraper_GetArgInt")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("Scraper_SetResult")), (SCRIPT_LIB_FUNCTION*)NULL);
  EXPECT_NE(script.GetLibraryFunction(__L("Scraper_GetResult")), (SCRIPT_LIB_FUNCTION*)NULL);
}


TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, ArgResultRoundTripViaBridge)
{
  DIOSCRAPERSCRIPT   runner;
  SCRIPT_LIB_SCRAPER library;
  SCRIPT             script;
  XVARIANT           name(__L("timeout"));
  XVARIANT           result;
  XVECTOR<XVARIANT*> params;
  XSTRING            value;
  int                timeout = 0;

  runner.SetArgInt(__L("timeout"), 7);
  library.SetContext(&runner);
  ASSERT_TRUE(library.AddLibraryFunctions(&script));

  params.Add(&name);
  Call_Scraper_GetArgInt(&library, &script, &params, &result);
  EXPECT_EQ((int)result, 7);

  params.DeleteAll();
  XVARIANT key(__L("ip"));
  XVARIANT ipvalue(__L("203.0.113.10"));
  params.Add(&key);
  params.Add(&ipvalue);
  Call_Scraper_SetResult(&library, &script, &params, &result);
  EXPECT_TRUE((bool)result);

  ASSERT_TRUE(runner.GetResult(__L("ip"), value));
  EXPECT_EQ(value.Compare(__L("203.0.113.10")), 0);

  ASSERT_TRUE(runner.GetArgInt(__L("timeout"), timeout));
  EXPECT_EQ(timeout, 7);
}


TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, RunnerExecutesMockPublicIPScript)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          ip;

  runner.SetArgInt(__L("timeout"), 5);
  ASSERT_TRUE(runner.Run(__L("scrapers/publicip_mock.g")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("ip"), ip));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_EQ(ip.Compare(__L("203.0.113.10")), 0);
}


#ifdef DIO_SCRAPERWEB_PUBLICIP_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, PublicIPFacadeUsesMockScriptAndCache)
{
  DIOSCRAPERWEBPUBLICIP scraper;
  DIOIP                 ip;
  DIOIP                 ipcached;
  XSTRING               text;

  ASSERT_TRUE(scraper.SetScriptPath(__L("scrapers/publicip_mock.g")));
  ASSERT_TRUE(scraper.Get(ip, 5, NULL, true));
  ip.GetXString(text);
  EXPECT_EQ(text.Compare(__L("203.0.113.10")), 0);

  // Second call must hit cache (same ask key) without needing the script again.
  ASSERT_TRUE(scraper.Get(ipcached, 5, NULL, true));
  text.Empty();
  ipcached.GetXString(text);
  EXPECT_EQ(text.Compare(__L("203.0.113.10")), 0);
}
#endif


#ifdef DIO_SCRAPERWEB_GEOLOCATIONIP_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, GeolocationFacadeUsesMockScript)
{
  DIOSCRAPERWEBGEOLOCATIONIP scraper;
  DIOGEOLOCATIONIP_RESULT    geo;
  DIOIP                      ip;

  ip.Set(__L("203.0.113.10"));
  ASSERT_TRUE(scraper.SetScriptPath(__L("scrapers/geolocationip_mock.g")));
  ASSERT_TRUE(scraper.Get(ip, geo, 5, NULL, true));
  EXPECT_EQ(XSTRING(geo.GetCountry()).Compare(__L("Testland")), 0);
  EXPECT_EQ(XSTRING(geo.GetCity()).Compare(__L("City")), 0);
  EXPECT_FLOAT_EQ(geo.GetLatitude(), 1.5f);
  EXPECT_FLOAT_EQ(geo.GetLongitude(), 2.5f);
}


TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveGeolocationScriptParsesIpApiJson)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          country;
  XSTRING          city;

  runner.SetArg(__L("ip"), __L("8.8.8.8"));
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/geolocationip.g")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("country"), country));
  ASSERT_TRUE(runner.GetResult(__L("city"), city));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(country.IsEmpty());
  EXPECT_FALSE(city.IsEmpty());
}


#ifdef SCRIPT_JAVASCRIPT_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LivePublicIPAndGeoScriptsInJavascript)
{
  DIOSCRAPERSCRIPT pubrunner;
  DIOSCRAPERSCRIPT georunner;
  XSTRING          ok;
  XSTRING          ip;
  XSTRING          country;

  pubrunner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(pubrunner.Run(__L("scrapers/publicip.js")));
  ASSERT_TRUE(pubrunner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(pubrunner.GetResult(__L("ip"), ip));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(ip.IsEmpty());

  georunner.SetArg(__L("ip"), ip);
  georunner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(georunner.Run(__L("scrapers/geolocationip.js")));
  ok.Empty();
  ASSERT_TRUE(georunner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(georunner.GetResult(__L("country"), country));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(country.IsEmpty());
}
#endif


#ifdef SCRIPT_LUA_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LivePublicIPAndGeoScriptsInLua)
{
  DIOSCRAPERSCRIPT pubrunner;
  DIOSCRAPERSCRIPT georunner;
  XSTRING          ok;
  XSTRING          ip;
  XSTRING          country;

  pubrunner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(pubrunner.Run(__L("scrapers/publicip.lua")));
  ASSERT_TRUE(pubrunner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(pubrunner.GetResult(__L("ip"), ip));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(ip.IsEmpty());

  georunner.SetArg(__L("ip"), ip);
  georunner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(georunner.Run(__L("scrapers/geolocationip.lua")));
  ok.Empty();
  ASSERT_TRUE(georunner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(georunner.GetResult(__L("country"), country));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(country.IsEmpty());
}
#endif

#endif


#ifdef DIO_SCRAPERWEB_WEATHER_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, WeatherFacadeUsesMockScriptAndCache)
{
  DIOSCRAPERWEBWEATHER scraper;
  DIOWEATHER_RESULT    weather;
  DIOWEATHER_RESULT    cached;
  XSTRING              location(__L("Madrid"));

  ASSERT_TRUE(scraper.SetScriptPath(__L("scrapers/weather_mock.g")));
  ASSERT_TRUE(scraper.Get(location, true, weather, 5, NULL, true));
  EXPECT_EQ(XSTRING(weather.GetCondition()).Compare(__L("Clear")), 0);
  EXPECT_FLOAT_EQ(weather.GetTemperature(), 21.5f);
  EXPECT_FLOAT_EQ(weather.GetHumidity(), 55.0f);

  ASSERT_TRUE(scraper.Get(location, true, cached, 5, NULL, true));
  EXPECT_EQ(XSTRING(cached.GetCondition()).Compare(__L("Clear")), 0);
  EXPECT_FLOAT_EQ(cached.GetTemperature(), 21.5f);
}


TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveWeatherScriptParsesOpenMeteo)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          condition;
  XSTRING          temperature;
  XSTRING          humidity;

  runner.SetArg(__L("location"), __L("Madrid"));
  runner.SetArgInt(__L("celsius"), 1);
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/weather.g")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("condition"), condition));
  ASSERT_TRUE(runner.GetResult(__L("temperature"), temperature));
  ASSERT_TRUE(runner.GetResult(__L("humidity"), humidity));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(condition.IsEmpty());
  EXPECT_FALSE(temperature.IsEmpty());
  EXPECT_FALSE(humidity.IsEmpty());
}


#ifdef SCRIPT_JAVASCRIPT_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveWeatherScriptInJavascript)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          temperature;

  runner.SetArg(__L("location"), __L("Madrid"));
  runner.SetArgInt(__L("celsius"), 1);
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/weather.js")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("temperature"), temperature));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(temperature.IsEmpty());
}
#endif


#ifdef SCRIPT_LUA_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveWeatherScriptInLua)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          temperature;

  runner.SetArg(__L("location"), __L("Madrid"));
  runner.SetArgInt(__L("celsius"), 1);
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/weather.lua")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("temperature"), temperature));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(temperature.IsEmpty());
}
#endif
#endif


#ifdef DIO_SCRAPERWEB_TRANSLATION_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, TranslationFacadeUsesMockScriptAndCache)
{
  DIOSCRAPERWEBTRANSLATION scraper;
  DIOTRANSLATION_RESULT    result;
  DIOTRANSLATION_RESULT    cached;
  XSTRING                  text(__L("Hello world"));
  XSTRING                  sl(__L("en"));
  XSTRING                  tl(__L("es"));

  ASSERT_TRUE(scraper.SetScriptPath(__L("scrapers/translation_mock.g")));
  ASSERT_TRUE(scraper.Get(text, sl, tl, result, 5, NULL, true));
  EXPECT_EQ(XSTRING(result.GetTranslation()).Compare(__L("Hola Mundo")), 0);
  EXPECT_EQ(XSTRING(result.GetSourceLanguage()).Compare(__L("en")), 0);

  ASSERT_TRUE(scraper.Get(text, sl, tl, cached, 5, NULL, true));
  EXPECT_EQ(XSTRING(cached.GetTranslation()).Compare(__L("Hola Mundo")), 0);
}


TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveTranslationScriptUsesGoogleFree)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          translation;

  runner.SetArg(__L("text"), __L("Hello world"));
  runner.SetArg(__L("sl"), __L("auto"));
  runner.SetArg(__L("tl"), __L("es"));
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/translation.g")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("translation"), translation));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(translation.IsEmpty());
}


#ifdef SCRIPT_JAVASCRIPT_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveTranslationScriptInJavascript)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          translation;

  runner.SetArg(__L("text"), __L("Hello world"));
  runner.SetArg(__L("sl"), __L("auto"));
  runner.SetArg(__L("tl"), __L("es"));
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/translation.js")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("translation"), translation));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(translation.IsEmpty());
}
#endif


#ifdef SCRIPT_LUA_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveTranslationScriptInLua)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          translation;

  runner.SetArg(__L("text"), __L("Hello world"));
  runner.SetArg(__L("sl"), __L("auto"));
  runner.SetArg(__L("tl"), __L("es"));
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/translation.lua")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("translation"), translation));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(translation.IsEmpty());
}
#endif
#endif


#ifdef DIO_SCRAPERWEB_MACMANUFACTURER_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, MACManufacturerFacadeUsesMockScriptAndCache)
{
  DIOSCRAPERWEBMACMANUFACTURER scraper;
  DIOMACMANUFACTURED_RESULT    result;
  DIOMACMANUFACTURED_RESULT    cached;
  DIOMAC                       mac;
  XSTRING                      macstring(__L("00:1B:63:84:45:E6"));

  mac.Set(macstring);
  ASSERT_TRUE(scraper.SetScriptPath(__L("scrapers/macmanufacturer_mock.g")));
  ASSERT_TRUE(scraper.Get(mac, result, 5, NULL, true));
  EXPECT_EQ(XSTRING(result.GetManufacturer()).Compare(__L("Apple, Inc.")), 0);

  ASSERT_TRUE(scraper.Get(mac, cached, 5, NULL, true));
  EXPECT_EQ(XSTRING(cached.GetManufacturer()).Compare(__L("Apple, Inc.")), 0);
}


TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveMACManufacturerScriptParsesVendor)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          manufacturer;

  runner.SetArg(__L("mac"), __L("00:1B:63:84:45:E6"));
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/macmanufacturer.g")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("manufacturer"), manufacturer));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(manufacturer.IsEmpty());
}


#ifdef SCRIPT_JAVASCRIPT_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveMACManufacturerScriptInJavascript)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          manufacturer;

  runner.SetArg(__L("mac"), __L("00:1B:63:84:45:E6"));
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/macmanufacturer.js")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("manufacturer"), manufacturer));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(manufacturer.IsEmpty());
}
#endif


#ifdef SCRIPT_LUA_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveMACManufacturerScriptInLua)
{
  DIOSCRAPERSCRIPT runner;
  XSTRING          ok;
  XSTRING          manufacturer;

  runner.SetArg(__L("mac"), __L("00:1B:63:84:45:E6"));
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/macmanufacturer.lua")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("manufacturer"), manufacturer));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(manufacturer.IsEmpty());
}
#endif
#endif


#ifdef DIO_SCRAPERWEB_USERAGENTID_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, UserAgentIDFacadeUsesMockScriptAndCache)
{
  DIOSCRAPERWEBUSERAGENTID scraper;
  DIOUSERAGENTID_RESULT    result;
  DIOUSERAGENTID_RESULT    cached;
  XSTRING                  ua(__L("Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/120.0.0.0"));

  ASSERT_TRUE(scraper.SetScriptPath(__L("scrapers/useragentid_mock.g")));
  ASSERT_TRUE(scraper.Get(ua, result, 5, NULL, true));
  EXPECT_EQ(XSTRING(result.GetBrowser()).Compare(__L("Chrome")), 0);
  EXPECT_EQ(XSTRING(result.GetSO()).Compare(__L("Windows 10")), 0);

  ASSERT_TRUE(scraper.Get(ua, cached, 5, NULL, true));
  EXPECT_EQ(XSTRING(cached.GetBrowser()).Compare(__L("Chrome")), 0);
}


TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveUserAgentIDScriptParsesBrowser)
{
  DIOSCRAPERSCRIPT runner;
  DIOURL           uaencoded;
  XSTRING          ok;
  XSTRING          browser;

  uaencoded.EncodeUnsafeCharsFromString(__L("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"));
  runner.SetArg(__L("ua"), uaencoded.Get());
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/useragentid.g")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("browser"), browser));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(browser.IsEmpty());
}


#ifdef SCRIPT_JAVASCRIPT_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveUserAgentIDScriptInJavascript)
{
  DIOSCRAPERSCRIPT runner;
  DIOURL           uaencoded;
  XSTRING          ok;
  XSTRING          browser;

  uaencoded.EncodeUnsafeCharsFromString(__L("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"));
  runner.SetArg(__L("ua"), uaencoded.Get());
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/useragentid.js")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("browser"), browser));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(browser.IsEmpty());
}
#endif


#ifdef SCRIPT_LUA_ACTIVE
TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, LiveUserAgentIDScriptInLua)
{
  DIOSCRAPERSCRIPT runner;
  DIOURL           uaencoded;
  XSTRING          ok;
  XSTRING          browser;

  uaencoded.EncodeUnsafeCharsFromString(__L("Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36"));
  runner.SetArg(__L("ua"), uaencoded.Get());
  runner.SetArgInt(__L("timeout"), 15);
  ASSERT_TRUE(runner.Run(__L("scrapers/useragentid.lua")));
  ASSERT_TRUE(runner.GetResult(__L("ok"), ok));
  ASSERT_TRUE(runner.GetResult(__L("browser"), browser));
  EXPECT_EQ(ok.Compare(__L("1")), 0);
  EXPECT_FALSE(browser.IsEmpty());
}
#endif
#endif


TEST(UNITTESTS_SCRIPTLIBSCRAPER_CLASSNAME, NotAutoRegisteredOnScript)
{
  SCRIPT script;

  ASSERT_TRUE(script.AddInternalLibraries());
  EXPECT_EQ(script.GetLibraryFunction(__L("Scraper_SetResult")), (SCRIPT_LIB_FUNCTION*)NULL);
}

}
#endif
