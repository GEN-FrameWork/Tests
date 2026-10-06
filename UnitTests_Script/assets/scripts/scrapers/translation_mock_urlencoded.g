int main()
{
  string text;
  string tl;

  text = Scraper_GetArg("text");
  tl = Scraper_GetArg("tl");

  Scraper_SetResult("ok", "1");
  // Simulated web-encoded translation: %20/%3A URL escapes; keep %s/%2d/%08X masks.
  Scraper_SetResult("translation", "Error%20%2d%20of%20%08X%20at%3A%20%s");
  Scraper_SetResult("detected", "en");
  return 1;
}
