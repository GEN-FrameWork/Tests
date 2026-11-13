/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_GRP2DCanvas.cpp
*
* @class      UNITTESTS_GRAPHIC_GRP2DCANVAS
* @brief      Graphic unit tests for GRP2DCANVAS class
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

#include "UnitTests_Graphic_GRP2DCanvas.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "GRPFactory.h"
#include "GRPProperties.h"
#include "GRP2DCanvas.h"
#include "GRP2DColor.h"
#include "GRPBitmap.h"
#include "XRect.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef GRP_ACTIVE
namespace TEST_GRP2DCANVAS
{

static GRPBITMAP* CaptureRectByGetPixel(GRP2DCANVAS* canvas, double rx, double ry, double rw, double rh)
{
  if(!canvas) return NULL;
  const int x0 = (int)rx;
  const int y0 = (int)ry;
  const int bw = (int)(rw + 0.5);
  const int bh = (int)(rh + 0.5);
  if(bw < 1 || bh < 1) return NULL;

  GRPBITMAP* bmp = GRPFACTORY::GetInstance().CreateBitmap(bw, bh, canvas->GetMode(), canvas->IsBufferInverse());
  if(!bmp) return NULL;

  for(int y = 0; y < bh; y++)
    {
      for(int x = 0; x < bw; x++)
        {
          GRP2DCOLOR* px = canvas->GetPixel((double)(x0 + x), (double)(y0 + y));
          if(px) bmp->PutPixel(x, y, px);
        }
    }
  return bmp;
}


static void ExpectBitmapMatchesGetPixel(GRP2DCANVAS* canvas, GRPBITMAP* via_getbitmap, double rx, double ry)
{
  ASSERT_NE(canvas, (GRP2DCANVAS*)NULL);
  ASSERT_NE(via_getbitmap, (GRPBITMAP*)NULL);

  const XDWORD bw = via_getbitmap->GetWidth();
  const XDWORD bh = via_getbitmap->GetHeight();
  ASSERT_GT(bw, 0u);
  ASSERT_GT(bh, 0u);

  // Dense sample: corners, center, and a mid-edge — enough to catch solid-poison vs real fill.
  const int samples[][2] =
    {
      { 0, 0 },
      { (int)bw - 1, 0 },
      { 0, (int)bh - 1 },
      { (int)bw - 1, (int)bh - 1 },
      { (int)bw / 2, (int)bh / 2 },
      { (int)bw / 2, 0 },
      { 0, (int)bh / 2 }
    };

  for(size_t i = 0; i < sizeof(samples) / sizeof(samples[0]); i++)
    {
      const int sx = samples[i][0];
      const int sy = samples[i][1];
      if(sx < 0 || sy < 0 || (XDWORD)sx >= bw || (XDWORD)sy >= bh) continue;

      GRP2DCOLOR_RGBA8* from_bmp = (GRP2DCOLOR_RGBA8*)via_getbitmap->GetPixel(sx, sy);
      GRP2DCOLOR_RGBA8* from_px  = (GRP2DCOLOR_RGBA8*)canvas->GetPixel(rx + (double)sx, ry + (double)sy);
      ASSERT_NE(from_bmp, (GRP2DCOLOR_RGBA8*)NULL) << "GetBitmap null at " << sx << "," << sy;
      ASSERT_NE(from_px,  (GRP2DCOLOR_RGBA8*)NULL) << "GetPixel null at " << sx << "," << sy;
      EXPECT_EQ(from_bmp->r, from_px->r) << "R mismatch at " << sx << "," << sy;
      EXPECT_EQ(from_bmp->g, from_px->g) << "G mismatch at " << sx << "," << sy;
      EXPECT_EQ(from_bmp->b, from_px->b) << "B mismatch at " << sx << "," << sy;
    }
}


TEST(UNITTESTS_GRP2DCANVAS_CLASSNAME, CreateBufferClearGetPixelAndFontSize)
{
  GRPPROPERTIES props;
  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(32, 24);

  GRP2DCANVAS* canvas = GRPFACTORY::GetInstance().CreateCanvas(&props);
  ASSERT_NE(canvas, (GRP2DCANVAS*)NULL);
  ASSERT_TRUE(canvas->Buffer_Create());
  EXPECT_NE(canvas->Buffer_Get(), (XBYTE*)NULL);

  GRP2DCOLOR_RGBA8 clearcolor(5, 6, 7, 255);
  canvas->Clear(&clearcolor);

  GRP2DCOLOR_RGBA8* pixel = (GRP2DCOLOR_RGBA8*)canvas->GetPixel(0, 0);
  ASSERT_NE(pixel, (GRP2DCOLOR_RGBA8*)NULL);
  EXPECT_EQ(pixel->r, 5);
  EXPECT_EQ(pixel->g, 6);
  EXPECT_EQ(pixel->b, 7);

  ASSERT_NE(canvas->Vectorfont_GetConfig(), (GRP2DCANVAS_VECTORFONT_CONFIG*)NULL);
  EXPECT_TRUE(canvas->Vectorfont_GetConfig()->SetSize(14.0));
  EXPECT_DOUBLE_EQ(canvas->Vectorfont_GetConfig()->GetSize(), 14.0);

  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteCanvas(canvas));
}


// Isolated repro for combo underlay poison: GetBitmap must match GetPixel for the same rect.
// Combo path forces a full-canvas GEN clip (left,bottom,right,top) before capture — include that.
TEST(UNITTESTS_GRP2DCANVAS_CLASSNAME, GetBitmapMatchesGetPixel_FullClipAndSubRect)
{
  const int canvas_w = 320;
  const int canvas_h = 200;

  GRPPROPERTIES props;
  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(canvas_w, canvas_h);

  GRP2DCANVAS* canvas = GRPFACTORY::GetInstance().CreateCanvas(&props);
  ASSERT_NE(canvas, (GRP2DCANVAS*)NULL);
  ASSERT_TRUE(canvas->Buffer_Create());

  // Page charcoal (XTM page-like); not named green.
  GRP2DCOLOR_RGBA8 page(24, 28, 36, 255);
  canvas->Clear(&page);

  XRECT clip_saved;
  canvas->GetClipBox(clip_saved);
  // Same GEN clip order used by ModalLayer_CaptureComboMenuBackdrop.
  canvas->SetClipBox(0.0, (double)canvas_h - 1.0, (double)canvas_w - 1.0, 0.0);

  const double rx = 40.0;
  const double ry = 30.0;
  const double rw = 180.0;
  const double rh = 90.0;

  GRPBITMAP* via_getbitmap = canvas->GetBitmap(rx, ry, rw, rh);
  ASSERT_NE(via_getbitmap, (GRPBITMAP*)NULL);

  ExpectBitmapMatchesGetPixel(canvas, via_getbitmap, rx, ry);

  GRPBITMAP* via_getpixel = CaptureRectByGetPixel(canvas, rx, ry, rw, rh);
  ASSERT_NE(via_getpixel, (GRPBITMAP*)NULL);
  EXPECT_EQ(via_getbitmap->GetWidth(),  via_getpixel->GetWidth());
  EXPECT_EQ(via_getbitmap->GetHeight(), via_getpixel->GetHeight());
  EXPECT_TRUE(via_getbitmap->Compare(via_getpixel));

  canvas->SetClipBox(clip_saved);

  GRPFACTORY::GetInstance().DeleteBitmap(via_getpixel);
  GRPFACTORY::GetInstance().DeleteBitmap(via_getbitmap);
  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteCanvas(canvas));
}


// Combo-like overhang size on a wide canvas (savedscreensize-scale proportion).
TEST(UNITTESTS_GRP2DCANVAS_CLASSNAME, GetBitmapMatchesGetPixel_WideCanvasOverhang)
{
  const int canvas_w = 960;
  const int canvas_h = 540;

  GRPPROPERTIES props;
  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(canvas_w, canvas_h);

  GRP2DCANVAS* canvas = GRPFACTORY::GetInstance().CreateCanvas(&props);
  ASSERT_NE(canvas, (GRP2DCANVAS*)NULL);
  ASSERT_TRUE(canvas->Buffer_Create());

  GRP2DCOLOR_RGBA8 page(24, 28, 36, 255);
  canvas->Clear(&page);

  // Paint a distinct band so a wrong memcpy/y-origin cannot silently match a solid clear.
  GRP2DCOLOR_RGBA8 band(80, 90, 100, 255);
  for(int y = 100; y < 220; y++)
    {
      for(int x = 200; x < 520; x++)
        {
          canvas->PutPixel((double)x, (double)y, &band);
        }
    }

  canvas->SetClipBox(0.0, (double)canvas_h - 1.0, (double)canvas_w - 1.0, 0.0);

  const double rx = 200.0;
  const double ry = 100.0;
  const double rw = 320.0;
  const double rh = 120.0;

  GRPBITMAP* via_getbitmap = canvas->GetBitmap(rx, ry, rw, rh);
  ASSERT_NE(via_getbitmap, (GRPBITMAP*)NULL);
  ExpectBitmapMatchesGetPixel(canvas, via_getbitmap, rx, ry);

  GRPBITMAP* via_getpixel = CaptureRectByGetPixel(canvas, rx, ry, rw, rh);
  ASSERT_NE(via_getpixel, (GRPBITMAP*)NULL);
  EXPECT_TRUE(via_getbitmap->Compare(via_getpixel));

  GRPFACTORY::GetInstance().DeleteBitmap(via_getpixel);
  GRPFACTORY::GetInstance().DeleteBitmap(via_getbitmap);
  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteCanvas(canvas));
}


// XTM savedscreensize-scale canvas: size alone must not make GetBitmap invent lime.
TEST(UNITTESTS_GRP2DCANVAS_CLASSNAME, GetBitmapMatchesGetPixel_XTMScreenSize)
{
  const int canvas_w = 1971;
  const int canvas_h = 1129;

  GRPPROPERTIES props;
  props.SetMode(GRPPROPERTYMODE_32_RGBA_8888);
  props.SetSize(canvas_w, canvas_h);

  GRP2DCANVAS* canvas = GRPFACTORY::GetInstance().CreateCanvas(&props);
  ASSERT_NE(canvas, (GRP2DCANVAS*)NULL);
  ASSERT_TRUE(canvas->Buffer_Create());

  GRP2DCOLOR_RGBA8 page(24, 28, 36, 255);
  canvas->Clear(&page);

  canvas->SetClipBox(0.0, (double)canvas_h - 1.0, (double)canvas_w - 1.0, 0.0);

  // Overhang-like rect in the lower content area (combo underlay scale).
  const double rx = 1200.0;
  const double ry = 400.0;
  const double rw = 280.0;
  const double rh = 220.0;

  GRPBITMAP* via_getbitmap = canvas->GetBitmap(rx, ry, rw, rh);
  ASSERT_NE(via_getbitmap, (GRPBITMAP*)NULL);
  ExpectBitmapMatchesGetPixel(canvas, via_getbitmap, rx, ry);

  GRP2DCOLOR_RGBA8* ctr = (GRP2DCOLOR_RGBA8*)via_getbitmap->GetPixel((int)via_getbitmap->GetWidth()/2,
                                                                     (int)via_getbitmap->GetHeight()/2);
  ASSERT_NE(ctr, (GRP2DCOLOR_RGBA8*)NULL);
  EXPECT_EQ(ctr->r, 24);
  EXPECT_EQ(ctr->g, 28);
  EXPECT_EQ(ctr->b, 36);

  GRPFACTORY::GetInstance().DeleteBitmap(via_getbitmap);
  EXPECT_TRUE(GRPFACTORY::GetInstance().DeleteCanvas(canvas));
}


}
#endif
#endif
