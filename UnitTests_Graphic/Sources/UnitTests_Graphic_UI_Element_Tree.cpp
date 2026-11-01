/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_UI_Element_Tree.cpp
*
* @class      UNITTESTS_GRAPHIC_UI_ELEMENT_TREE
* @brief      Graphic unit tests for UI_ELEMENT_TREE
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

#include "UnitTests_Graphic_UI_Element_Tree.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#ifdef USERINTERFACE_ACTIVE
#include "UI_Element_Tree.h"
#endif


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
#ifdef USERINTERFACE_ACTIVE
namespace TEST_UI_ELEMENT_TREE
{


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, DefaultTypeDefaultsAndEmptyTree)
{
  UI_ELEMENT_TREE tree;

  EXPECT_EQ(tree.GetType(), UI_ELEMENT_TYPE_TREE);
  ASSERT_NE(tree.GetTypeString(), (XSTRING*)NULL);
  EXPECT_EQ(tree.GetTypeString()->Compare(_L("tree"), true), 0);

  EXPECT_EQ(tree.GetSizeFont(), (XDWORD)0);
  EXPECT_EQ(tree.GetRowHeight(), (double)UI_ELEMENT_TREE_DEFAULT_ROWHEIGHT);
  EXPECT_EQ(tree.GetIndentWidth(), (double)UI_ELEMENT_TREE_DEFAULT_INDENTWIDTH);
  EXPECT_EQ(tree.GetContentHeight(), 0.0);
  EXPECT_EQ(tree.GetContentWidth(), 0.0);
  EXPECT_EQ(tree.GetRootCount(), (XDWORD)0);
  EXPECT_EQ(tree.GetRoot(0), (UI_ELEMENT_TREE_NODE*)NULL);
  EXPECT_EQ(tree.GetSelected(), (UI_ELEMENT_TREE_NODE*)NULL);
  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)0);
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, AddNodeBuildsUnlimitedNesting)
{
  UI_ELEMENT_TREE tree;

  UI_ELEMENT_TREE_NODE* root = tree.AddNode(NULL, _L("All"));
  ASSERT_NE(root, (UI_ELEMENT_TREE_NODE*)NULL);
  EXPECT_EQ(root->text.Compare(_L("All"), true), 0);
  EXPECT_EQ(root->father, (UI_ELEMENT_TREE_NODE*)NULL);
  EXPECT_FALSE(root->expanded);
  EXPECT_EQ(tree.GetRootCount(), (XDWORD)1);

  UI_ELEMENT_TREE_NODE* node = root;
  for(int c=0; c<10; c++)
    {
      UI_ELEMENT_TREE_NODE* child = tree.AddNode(node, _L("level"));
      ASSERT_NE(child, (UI_ELEMENT_TREE_NODE*)NULL);
      EXPECT_EQ(child->father, node);
      node = child;
    }

  EXPECT_EQ(tree.GetNodeDepth(root), (XDWORD)0);
  EXPECT_EQ(tree.GetNodeDepth(node), (XDWORD)10);
  EXPECT_TRUE(root->HasChildren());
  EXPECT_FALSE(node->HasChildren());

  UI_ELEMENT_TREE_NODE* second = tree.AddNode(NULL, _L("Second"));
  ASSERT_NE(second, (UI_ELEMENT_TREE_NODE*)NULL);
  EXPECT_EQ(tree.GetRootCount(), (XDWORD)2);
  EXPECT_EQ(tree.GetRoot(1), second);
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, AddNodeRejectsForeignFather)
{
  UI_ELEMENT_TREE tree;
  UI_ELEMENT_TREE other;

  UI_ELEMENT_TREE_NODE* foreign = other.AddNode(NULL, _L("x"));
  ASSERT_NE(foreign, (UI_ELEMENT_TREE_NODE*)NULL);

  EXPECT_EQ(tree.AddNode(foreign, _L("child")), (UI_ELEMENT_TREE_NODE*)NULL);
  EXPECT_EQ(tree.GetRootCount(), (XDWORD)0);
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, ClearDeletesEverything)
{
  UI_ELEMENT_TREE tree;

  UI_ELEMENT_TREE_NODE* root  = tree.AddNode(NULL, _L("All"));
  UI_ELEMENT_TREE_NODE* child = tree.AddNode(root, _L("c"));
  tree.AddNode(child, _L("g"));
  tree.Expand(root);
  tree.SetSelected(child);
  tree.SetContentHeight(99.0);

  ASSERT_TRUE(tree.Clear());

  EXPECT_EQ(tree.GetRootCount(), (XDWORD)0);
  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)0);
  EXPECT_EQ(tree.GetSelected(), (UI_ELEMENT_TREE_NODE*)NULL);
  EXPECT_EQ(tree.GetContentHeight(), 0.0);
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, ExpandCollapseAffectsVisibleCount)
{
  UI_ELEMENT_TREE tree;

  UI_ELEMENT_TREE_NODE* root = tree.AddNode(NULL, _L("All"));
  UI_ELEMENT_TREE_NODE* a    = tree.AddNode(root, _L("A"));
  UI_ELEMENT_TREE_NODE* b    = tree.AddNode(root, _L("B"));
  tree.AddNode(a, _L("A1"));
  tree.AddNode(a, _L("A2"));

  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)1);                 // collapsed root

  EXPECT_TRUE(tree.Expand(root));
  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)3);                 // All, A, B
  EXPECT_FALSE(tree.Expand(root));                                 // already expanded

  EXPECT_TRUE(tree.Expand(a));
  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)5);                 // All, A, A1, A2, B
  EXPECT_EQ(tree.GetVisibleNode(2)->text.Compare(_L("A1"), true), 0);
  EXPECT_EQ(tree.GetVisibleNode(4), b);
  EXPECT_EQ(tree.GetVisibleRowOfNode(b), 4);

  EXPECT_FALSE(tree.Expand(b));                                    // leaf cannot expand

  EXPECT_TRUE(tree.Collapse(a));
  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)3);
  EXPECT_EQ(tree.GetVisibleRowOfNode(b), 2);

  EXPECT_TRUE(tree.Collapse(root));
  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)1);
  EXPECT_EQ(tree.GetVisibleRowOfNode(b), -1);
  EXPECT_FALSE(tree.Collapse(root));
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, ToggleFlipsExpansionOnlyForParents)
{
  UI_ELEMENT_TREE tree;

  UI_ELEMENT_TREE_NODE* root = tree.AddNode(NULL, _L("All"));
  UI_ELEMENT_TREE_NODE* leaf = tree.AddNode(root, _L("leaf"));

  EXPECT_FALSE(tree.Toggle(leaf));
  EXPECT_FALSE(tree.Toggle(NULL));

  EXPECT_TRUE(tree.Toggle(root));
  EXPECT_TRUE(root->expanded);
  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)2);

  EXPECT_TRUE(tree.Toggle(root));
  EXPECT_FALSE(root->expanded);
  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)1);
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, SelectionAndCollapseMovesSelectionUp)
{
  UI_ELEMENT_TREE tree;

  UI_ELEMENT_TREE_NODE* root = tree.AddNode(NULL, _L("All"));
  UI_ELEMENT_TREE_NODE* a    = tree.AddNode(root, _L("A"));
  UI_ELEMENT_TREE_NODE* a1   = tree.AddNode(a, _L("A1"));

  tree.Expand(root);
  tree.Expand(a);

  EXPECT_TRUE(tree.SetSelected(a1));
  EXPECT_EQ(tree.GetSelected(), a1);

  EXPECT_TRUE(tree.Collapse(a));                                   // hides a1: selection moves to a
  EXPECT_EQ(tree.GetSelected(), a);

  EXPECT_TRUE(tree.SetSelected(NULL));
  EXPECT_EQ(tree.GetSelected(), (UI_ELEMENT_TREE_NODE*)NULL);

  UI_ELEMENT_TREE other;
  UI_ELEMENT_TREE_NODE* foreign = other.AddNode(NULL, _L("x"));
  EXPECT_FALSE(tree.SetSelected(foreign));
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, RemoveNodeDropsSubtreeAndSelection)
{
  UI_ELEMENT_TREE tree;

  UI_ELEMENT_TREE_NODE* root = tree.AddNode(NULL, _L("All"));
  UI_ELEMENT_TREE_NODE* a    = tree.AddNode(root, _L("A"));
  UI_ELEMENT_TREE_NODE* a1   = tree.AddNode(a, _L("A1"));
  UI_ELEMENT_TREE_NODE* b    = tree.AddNode(root, _L("B"));

  tree.Expand(root);
  tree.Expand(a);
  tree.SetSelected(a1);
  ASSERT_EQ(tree.GetVisibleRowCount(), (XDWORD)4);

  EXPECT_TRUE(tree.RemoveNode(a));
  EXPECT_EQ(tree.GetSelected(), (UI_ELEMENT_TREE_NODE*)NULL);
  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)2);                 // All, B
  EXPECT_EQ(tree.GetVisibleNode(1), b);

  EXPECT_FALSE(tree.RemoveNode(NULL));

  EXPECT_TRUE(tree.RemoveNode(root));
  EXPECT_EQ(tree.GetRootCount(), (XDWORD)0);
  EXPECT_EQ(tree.GetVisibleRowCount(), (XDWORD)0);
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, HitTestExpandBoxAndNode)
{
  UI_ELEMENT_TREE tree;

  UI_ELEMENT_TREE_NODE* root = tree.AddNode(NULL, _L("All"));
  UI_ELEMENT_TREE_NODE* a    = tree.AddNode(root, _L("A"));
  UI_ELEMENT_TREE_NODE* leaf = tree.AddNode(root, _L("leaf"));
  tree.AddNode(a, _L("A1"));
  tree.Expand(root);

  double row_h = tree.GetRowHeight();

  // Row 0 (root, depth 0): box centre at (BoxCenterX(0), PAD_Y + row_h/2).
  double y0 = UI_ELEMENT_TREE_PADDING_Y + (row_h / 2.0f);
  double y1 = y0 + row_h;
  double y2 = y1 + row_h;

  EXPECT_EQ(tree.HitTestExpandBox(tree.GetBoxCenterX(0), y0), root);
  EXPECT_EQ(tree.HitTestExpandBox(tree.GetBoxCenterX(0) + 30.0, y0), (UI_ELEMENT_TREE_NODE*)NULL);
  EXPECT_EQ(tree.HitTestExpandBox(tree.GetBoxCenterX(1), y1), a);            // depth 1 parent
  EXPECT_EQ(tree.HitTestExpandBox(tree.GetBoxCenterX(1), y2), (UI_ELEMENT_TREE_NODE*)NULL);   // leaf has no box
  EXPECT_EQ(tree.HitTestExpandBox(tree.GetBoxCenterX(0), 0.0), (UI_ELEMENT_TREE_NODE*)NULL);  // above rows
  EXPECT_EQ(tree.HitTestExpandBox(tree.GetBoxCenterX(0), y2 + 10 * row_h), (UI_ELEMENT_TREE_NODE*)NULL); // below rows

  EXPECT_EQ(tree.HitTestNode(tree.GetTextX(1) + 5.0, y2), leaf);
  EXPECT_EQ(tree.HitTestNode(tree.GetBoxCenterX(1), y2), (UI_ELEMENT_TREE_NODE*)NULL);       // left of the label
  EXPECT_EQ(tree.HitTestRow(y1), a);
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, HitTestHonoursScrollDisplacement)
{
  UI_ELEMENT_TREE tree;

  UI_ELEMENT_TREE_NODE* root = tree.AddNode(NULL, _L("All"));
  for(int c=0; c<10; c++) tree.AddNode(root, _L("n"));
  tree.Expand(root);

  double row_h = tree.GetRowHeight();

  // The displacement is only reported on an active axis: resolve the policy for a 100px viewport (content is taller).
  tree.GetVisibleRowCount();
  tree.Scroll_SetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL, UI_OVERFLOW_AUTO);
  tree.Scroll_ResolvePolicy(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL, 100.0, tree.GetContentHeight());
  ASSERT_TRUE(tree.Scroll_GetActive(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL));

  tree.Scroll_SetDisplacement(UI_PROPERTY_SCROLLEABLE_TYPE_VERTICAL, -(2.0 * row_h));    // scrolled 2 rows down

  // The root row is now above the viewport; the first visible row at y=PAD_Y is row index 2.
  EXPECT_EQ(tree.HitTestRow(UI_ELEMENT_TREE_PADDING_Y + (row_h / 2.0f)), tree.GetVisibleNode(2));
  EXPECT_EQ(tree.HitTestExpandBox(tree.GetBoxCenterX(0), UI_ELEMENT_TREE_PADDING_Y + (row_h / 2.0f) - (2.0 * row_h)), (UI_ELEMENT_TREE_NODE*)NULL); // off-screen row y<0
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, HitTestHonoursHorizontalScrollDisplacement)
{
  UI_ELEMENT_TREE tree;

  UI_ELEMENT_TREE_NODE* root = tree.AddNode(NULL, _L("All"));
  tree.AddNode(root, _L("child-with-a-very-long-label-for-overflow"));
  tree.GetVisibleRowCount();                                                   // root visible (collapsed)

  tree.SetContentWidth(500.0);
  tree.Scroll_SetOverflow(UI_PROPERTY_SCROLLEABLE_TYPE_HORIZONTAL, UI_OVERFLOW_AUTO);
  tree.Scroll_ResolvePolicy(UI_PROPERTY_SCROLLEABLE_TYPE_HORIZONTAL, 200.0, tree.GetContentWidth());
  ASSERT_TRUE(tree.Scroll_GetActive(UI_PROPERTY_SCROLLEABLE_TYPE_HORIZONTAL));

  double y0 = UI_ELEMENT_TREE_PADDING_Y + (tree.GetRowHeight() / 2.0f);
  double cx = tree.GetBoxCenterX(0);

  EXPECT_EQ(tree.HitTestExpandBox(cx, y0), root);

  tree.Scroll_SetDisplacement(UI_PROPERTY_SCROLLEABLE_TYPE_HORIZONTAL, -40.0f);

  // Drawn [+] box moved left with hdisp; unscrolled cx must miss, scrolled cx must hit.
  EXPECT_EQ(tree.HitTestExpandBox(cx, y0), (UI_ELEMENT_TREE_NODE*)NULL);
  EXPECT_EQ(tree.HitTestExpandBox(cx - 40.0, y0), root);
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, ClickAtTogglesOnBoxAndSelectsOnLabel)
{
  UI_ELEMENT_TREE tree;

  UI_ELEMENT_TREE_NODE* root = tree.AddNode(NULL, _L("All"));
  UI_ELEMENT_TREE_NODE* a    = tree.AddNode(root, _L("A"));

  double y0 = UI_ELEMENT_TREE_PADDING_Y + (tree.GetRowHeight() / 2.0f);
  double y1 = y0 + tree.GetRowHeight();

  EXPECT_TRUE(tree.ClickAt(tree.GetBoxCenterX(0), y0));            // expand
  EXPECT_TRUE(root->expanded);
  EXPECT_EQ(tree.GetSelected(), (UI_ELEMENT_TREE_NODE*)NULL);      // box click does not select

  EXPECT_TRUE(tree.ClickAt(tree.GetTextX(1) + 4.0, y1));           // select label
  EXPECT_EQ(tree.GetSelected(), a);
  EXPECT_FALSE(tree.ClickAt(tree.GetTextX(1) + 4.0, y1));          // same selection: no change

  EXPECT_TRUE(tree.ClickAt(tree.GetBoxCenterX(0), y0));            // collapse
  EXPECT_FALSE(root->expanded);
  EXPECT_EQ(tree.GetSelected(), root);                             // a became hidden: selection moves up to the collapsed node
}


TEST(UNITTESTS_UI_ELEMENT_TREE_CLASSNAME, PropertySettersRoundTripAndClamp)
{
  UI_ELEMENT_TREE tree;

  tree.SetSizeFont(12);
  tree.SetRowHeight(24.0);
  tree.SetIndentWidth(20.0);

  EXPECT_EQ(tree.GetSizeFont(), (XDWORD)12);
  EXPECT_EQ(tree.GetRowHeight(), 24.0);
  EXPECT_EQ(tree.GetIndentWidth(), 20.0);

  tree.SetRowHeight(0.0);
  EXPECT_EQ(tree.GetRowHeight(), 1.0);

  tree.SetIndentWidth(1.0);
  EXPECT_EQ(tree.GetIndentWidth(), (double)(UI_ELEMENT_TREE_BOXSIZE + 2.0f));
}


} // namespace TEST_UI_ELEMENT_TREE
#endif // USERINTERFACE_ACTIVE
#endif // GOOGLETEST_ACTIVE
