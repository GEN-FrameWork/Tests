int main()
{
  string text;
  string tl;

  text = Scraper_GetArg("text");
  tl = Scraper_GetArg("tl");

  Scraper_SetResult("ok", "1");
  // Same pattern DevTests sees from the live API: space escapes around a %d mask.
  Scraper_SetResult("translation", "Hola%20%d%20world");
  Scraper_SetResult("detected", "en");
  return 1;
}
