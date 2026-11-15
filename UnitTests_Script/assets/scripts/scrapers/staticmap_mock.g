// Mock static map scraper for unit tests (no network).
// Contract mirrors staticmap.g: args latitude/longitude/outpath (+ optional size/zoom);
// results ok/path/provider. The C++ facade still requires a non-empty file at outpath —
// the unit test creates that stub before calling DIOSCRAPERWEBSTATICMAP::Get.

int main()
{
  string outpath;
  string lat;
  string lon;

  outpath = Scraper_GetArg("outpath");
  lat     = Scraper_GetArg("latitude");
  lon     = Scraper_GetArg("longitude");

  Scraper_SetResult("ok", "0");

  if(IsEmptyString(outpath))
    {
      return 0;
    }

  if(IsEmptyString(lat) || IsEmptyString(lon))
    {
      return 0;
    }

  Scraper_SetResult("path", outpath);
  Scraper_SetResult("provider", "mock");
  Scraper_SetResult("ok", "1");
  return 1;
}
