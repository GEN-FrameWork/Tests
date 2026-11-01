/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_UI_Element_PropertyList.cpp
*
* @class      UNITTESTS_GRAPHIC_UI_ELEMENT_PROPERTYLIST
* @brief      Graphic unit tests for UI_ELEMENT_PROPERTYLIST
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

#include "UnitTests_Graphic_UI_Element_PropertyList.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#ifdef USERINTERFACE_ACTIVE
#include "UI_Element_PropertyList.h"
#endif


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef USERINTERFACE_ACTIVE
namespace TEST_UI_ELEMENT_PROPERTYLIST
{


TEST(UNITTESTS_UI_ELEMENT_PROPERTYLIST_CLASSNAME, DefaultTypeDefaultsAndEmptyRows)
{
  UI_ELEMENT_PROPERTYLIST list;

  EXPECT_EQ(list.GetType(), UI_ELEMENT_TYPE_PROPERTYLIST);
  ASSERT_NE(list.GetTypeString(), (XSTRING*)NULL);
  EXPECT_EQ(list.GetTypeString()->Compare(_L("propertylist"), true), 0);

  EXPECT_EQ(list.GetSizeFont(), (XDWORD)0);
  EXPECT_EQ(list.GetRowCount(), (XDWORD)0);
  EXPECT_EQ(list.GetRow(0), (UI_ELEMENT_PROPERTYLIST_ROW*)NULL);
  EXPECT_EQ(list.GetNameColumnWidth(), (double)UI_ELEMENT_PROPERTYLIST_DEFAULT_NAMECOLUMNWIDTH);
  EXPECT_EQ(list.GetRowHeight(), (double)UI_ELEMENT_PROPERTYLIST_DEFAULT_ROWHEIGHT);
  EXPECT_EQ(list.GetHeaderHeight(), (double)UI_ELEMENT_PROPERTYLIST_DEFAULT_HEADERHEIGHT);
  EXPECT_EQ(list.GetContentHeight(), 0.0);
  EXPECT_FALSE(list.IsSplitDragging());

  EXPECT_EQ(list.GetHeaderName()->Compare(_L("Name"), true), 0);
  EXPECT_EQ(list.GetHeaderValue()->Compare(_L("Value"), true), 0);
}


TEST(UNITTESTS_UI_ELEMENT_PROPERTYLIST_CLASSNAME, AddStoresRowsAndGetRowReturnsThem)
{
  UI_ELEMENT_PROPERTYLIST list;

  ASSERT_TRUE(list.Add(_L("User"), _L("alice")));
  ASSERT_TRUE(list.Add(_L("Domain"), _L("corp")));
  ASSERT_EQ(list.GetRowCount(), (XDWORD)2);

  UI_ELEMENT_PROPERTYLIST_ROW* row = list.GetRow(1);
  ASSERT_NE(row, (UI_ELEMENT_PROPERTYLIST_ROW*)NULL);
  EXPECT_EQ(row->name.Compare(_L("Domain"), true), 0);
  EXPECT_EQ(row->value.Compare(_L("corp"), true), 0);

  EXPECT_EQ(list.GetRow(2), (UI_ELEMENT_PROPERTYLIST_ROW*)NULL);
}


TEST(UNITTESTS_UI_ELEMENT_PROPERTYLIST_CLASSNAME, ClearEmptiesRowsAndContentHeight)
{
  UI_ELEMENT_PROPERTYLIST list;

  ASSERT_TRUE(list.Add(_L("a"), _L("1")));
  list.SetContentHeight(77.0);
  ASSERT_EQ(list.GetRowCount(), (XDWORD)1);

  ASSERT_TRUE(list.Clear());
  EXPECT_EQ(list.GetRowCount(), (XDWORD)0);
  EXPECT_EQ(list.GetContentHeight(), 0.0);
  EXPECT_EQ(list.GetRow(0), (UI_ELEMENT_PROPERTYLIST_ROW*)NULL);
}


TEST(UNITTESTS_UI_ELEMENT_PROPERTYLIST_CLASSNAME, SetValueUpdatesExistingOrAppends)
{
  UI_ELEMENT_PROPERTYLIST list;

  ASSERT_TRUE(list.Add(_L("Status"), _L("idle")));
  ASSERT_TRUE(list.SetValue(_L("status"), _L("running")));
  ASSERT_EQ(list.GetRowCount(), (XDWORD)1);
  EXPECT_EQ(list.GetRow(0)->value.Compare(_L("running"), true), 0);

  ASSERT_TRUE(list.SetValue(_L("Other"), _L("x")));
  ASSERT_EQ(list.GetRowCount(), (XDWORD)2);
}


TEST(UNITTESTS_UI_ELEMENT_PROPERTYLIST_CLASSNAME, SetNameColumnWidthClampsToMinAndMax)
{
  UI_ELEMENT_PROPERTYLIST list;

  list.GetBoundaryLine()->width  = 400.0;
  list.GetBoundaryLine()->height = 170.0;

  list.SetNameColumnWidth(10.0);
  EXPECT_EQ(list.GetNameColumnWidth(), (double)UI_ELEMENT_PROPERTYLIST_MIN_COLUMNWIDTH);

  list.SetNameColumnWidth(5000.0);
  EXPECT_EQ(list.GetNameColumnWidth(), 400.0 - (double)UI_ELEMENT_PROPERTYLIST_MIN_COLUMNWIDTH);

  list.SetNameColumnWidth(150.0);
  EXPECT_EQ(list.GetNameColumnWidth(), 150.0);
}


TEST(UNITTESTS_UI_ELEMENT_PROPERTYLIST_CLASSNAME, HitTestSplitterAndDrag)
{
  UI_ELEMENT_PROPERTYLIST list;

  list.GetBoundaryLine()->width  = 400.0;
  list.GetBoundaryLine()->height = 170.0;
  list.SetNameColumnWidth(200.0);

  EXPECT_TRUE(list.HitTestSplitter(200.0, 10.0, 400.0, 170.0));
  EXPECT_TRUE(list.HitTestSplitter(202.0, 100.0, 400.0, 170.0));
  EXPECT_FALSE(list.HitTestSplitter(100.0, 10.0, 400.0, 170.0));
  EXPECT_FALSE(list.HitTestSplitter(200.0, -1.0, 400.0, 170.0));
  EXPECT_FALSE(list.HitTestSplitter(200.0, 171.0, 400.0, 170.0));

  EXPECT_FALSE(list.Split_DragTo(250.0));                        // not dragging yet
  EXPECT_EQ(list.GetNameColumnWidth(), 200.0);

  ASSERT_TRUE(list.Split_BeginDrag());
  EXPECT_TRUE(list.IsSplitDragging());
  EXPECT_TRUE(list.Split_DragTo(260.0));
  EXPECT_EQ(list.GetNameColumnWidth(), 260.0);
  EXPECT_TRUE(list.Split_DragTo(1.0));
  EXPECT_EQ(list.GetNameColumnWidth(), (double)UI_ELEMENT_PROPERTYLIST_MIN_COLUMNWIDTH);

  EXPECT_TRUE(list.Split_EndDrag());
  EXPECT_FALSE(list.IsSplitDragging());
  EXPECT_FALSE(list.Split_EndDrag());
}


TEST(UNITTESTS_UI_ELEMENT_PROPERTYLIST_CLASSNAME, PropertySettersRoundTrip)
{
  UI_ELEMENT_PROPERTYLIST list;

  list.SetSizeFont(12);
  list.SetRowHeight(30.0);
  list.SetHeaderHeight(32.0);
  list.SetHeaderCaptions(_L("Key"), _L("Data"));

  EXPECT_EQ(list.GetSizeFont(), (XDWORD)12);
  EXPECT_EQ(list.GetRowHeight(), 30.0);
  EXPECT_EQ(list.GetHeaderHeight(), 32.0);
  EXPECT_EQ(list.GetHeaderName()->Compare(_L("Key"), true), 0);
  EXPECT_EQ(list.GetHeaderValue()->Compare(_L("Data"), true), 0);
}


TEST(UNITTESTS_UI_ELEMENT_PROPERTYLIST_CLASSNAME, ContentHeightIsRowsOnlyNotHeader)
{
  // Skin Draw_PropertyList stores row-band height only; the sticky header is outside the scroll viewport.
  UI_ELEMENT_PROPERTYLIST list;

  list.SetRowHeight(22.0);
  list.SetHeaderHeight(26.0);
  ASSERT_TRUE(list.Add(_L("a"), _L("1")));
  ASSERT_TRUE(list.Add(_L("b"), _L("2")));
  ASSERT_TRUE(list.Add(_L("c"), _L("3")));

  const double rows_only = ((double)list.GetRowCount() * list.GetRowHeight()) + 4.0;
  list.SetContentHeight(rows_only);

  EXPECT_EQ(list.GetContentHeight(), rows_only);
  EXPECT_NE(list.GetContentHeight(), rows_only + list.GetHeaderHeight());
}


} // namespace TEST_UI_ELEMENT_PROPERTYLIST
#endif // USERINTERFACE_ACTIVE
#endif // GOOGLETEST_ACTIVE
