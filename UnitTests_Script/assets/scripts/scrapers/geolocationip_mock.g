int main()
{
  string ip;
  ip = Scraper_GetArg("ip");
  Scraper_SetResult("ok", "1");
  Scraper_SetResult("country", "Testland");
  Scraper_SetResult("state", "State");
  Scraper_SetResult("city", "City");
  Scraper_SetResult("isp", "ISP");
  Scraper_SetResult("organization", "Org");
  Scraper_SetResult("latitude", "1.5");
  Scraper_SetResult("longitude", "2.5");
  return 1;
}
