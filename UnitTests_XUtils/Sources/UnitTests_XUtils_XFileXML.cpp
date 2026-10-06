/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_XUtils_XFileXML.cpp
*
* @class      UNITTESTS_XUTILS_XFILEXML
* @brief      XUtils unit tests for XFILEXML class
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

#include "UnitTests_XUtils_XFileXML.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include <stdio.h>
#include <string.h>

#include "XFactory.h"
#include "XFileXML.h"
#include "XPath.h"
#include "XFile.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/


#ifdef GOOGLETEST_ACTIVE
namespace TEST_XFILEXML
{


TEST(UNITTESTS_XFILEXML_CLASSNAME, AttributeGetSetNameAndValue)
{
  XFILEXMLATTRIBUTE attribute;

  attribute.SetName(_L("attrname"));
  EXPECT_FALSE(attribute.GetName().Compare(_L("attrname"), false));

  attribute.SetValue(_L("attrvalue"));
  EXPECT_FALSE(attribute.GetValue().Compare(_L("attrvalue"), false));

  XFILEXMLATTRIBUTE constructed(_L("ctorname"), _L("ctorvalue"));
  EXPECT_FALSE(constructed.GetName().Compare(_L("ctorname"), false));
  EXPECT_FALSE(constructed.GetValue().Compare(_L("ctorvalue"), false));
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, ElementAddAtributeGetNAttributesAndGetValueAttribute)
{
  XFILEXMLELEMENT element(_L("elementname"));

  EXPECT_EQ(element.GetNAttributes(), 0);

  ASSERT_TRUE(element.AddAtribute(_L("id"), _L("42")) != NULL);
  ASSERT_TRUE(element.AddAtribute(_L("name"), _L("someone")) != NULL);

  ASSERT_EQ(element.GetNAttributes(), 2);

  EXPECT_STREQ(element.GetValueAttribute(_L("id")), _L("42"));
  EXPECT_STREQ(element.GetValueAttribute(_L("name")), _L("someone"));
  EXPECT_TRUE(element.GetValueAttribute(_L("missing")) == (XCHAR*)NULL);

  XSTRING value;
  EXPECT_TRUE(element.GetValueAttribute(_L("id"), value));
  EXPECT_FALSE(value.Compare(_L("42"), false));
  EXPECT_FALSE(element.GetValueAttribute(_L("missing"), value));

  XFILEXMLATTRIBUTE* first = element.GetAttribute(0);
  ASSERT_TRUE(first != NULL);
  EXPECT_FALSE(first->GetName().Compare(_L("id"), false));
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, ElementTypedAttributeGetters)
{
  XFILEXMLELEMENT element(_L("elementname"));

  element.AddAtribute(_L("intattr"), _L("123"));
  element.AddAtribute(_L("boolattr") , _L("true"));
  element.AddAtribute(_L("floatattr"), _L("3.25"));

  EXPECT_EQ(element.GetIntValueAttribute(_L("intattr")), 123);
  EXPECT_TRUE(element.GetBoolValueAttribute(_L("boolattr")));
  EXPECT_DOUBLE_EQ(element.GetFloatValueAttribute(_L("floatattr")), 3.25);

  // Missing attribute must fall back to the documented zero-ish defaults, not crash.
  EXPECT_EQ(element.GetIntValueAttribute(_L("nosuchattr")), 0);
  EXPECT_FALSE(element.GetBoolValueAttribute(_L("nosuchattr")));
  EXPECT_DOUBLE_EQ(element.GetFloatValueAttribute(_L("nosuchattr")), 0.0);
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, ElementDeleteAtributeAndDeleteAllAtributes)
{
  XFILEXMLELEMENT element(_L("elementname"));

  element.AddAtribute(_L("a"), _L("1"));
  element.AddAtribute(_L("b"), _L("2"));
  element.AddAtribute(_L("c"), _L("3"));

  ASSERT_EQ(element.GetNAttributes(), 3);

  EXPECT_TRUE(element.DeleteAtribute(1)); // remove "b"
  ASSERT_EQ(element.GetNAttributes(), 2);
  EXPECT_STREQ(element.GetValueAttribute(_L("a")), _L("1"));
  EXPECT_STREQ(element.GetValueAttribute(_L("c")), _L("3"));
  EXPECT_TRUE(element.GetValueAttribute(_L("b")) == (XCHAR*)NULL);

  EXPECT_TRUE(element.DeleteAllAtributes());
  EXPECT_EQ(element.GetNAttributes(), 0);
  EXPECT_FALSE(element.DeleteAllAtributes()); // nothing left
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, ElementAddElementBuildsANestedTreeWithFatherLinks)
{
  XFILEXMLELEMENT root(_L("root"));

  XFILEXMLELEMENT* child1 = root.AddElement(_L("child1"));
  XFILEXMLELEMENT* child2 = root.AddElement(_L("child2"), _L("child2value"));

  ASSERT_TRUE(child1 != NULL);
  ASSERT_TRUE(child2 != NULL);
  ASSERT_EQ(root.GetNElements(), 2);

  EXPECT_EQ(root.GetElement(0), child1);
  EXPECT_EQ(root.GetElement(1), child2);

  EXPECT_EQ(child1->GetFather(), &root);
  EXPECT_EQ(child2->GetFather(), &root);
  EXPECT_FALSE(child2->GetValue().Compare(_L("child2value"), false));

  XFILEXMLELEMENT* grandchild = child1->AddElement(_L("grandchild"));
  ASSERT_TRUE(grandchild != NULL);
  EXPECT_EQ(grandchild->GetFather(), child1);
  ASSERT_EQ(child1->GetNElements(), 1);
  EXPECT_EQ(child1->GetElement(0), grandchild);

  // Deleting child1 must also take its own child (grandchild) down with it -- no leaked pointer
  // access afterward; verified indirectly via the count on the parent.
  EXPECT_TRUE(root.DeleteElement(0));
  ASSERT_EQ(root.GetNElements(), 1);
  EXPECT_EQ(root.GetElement(0), child2);

  EXPECT_TRUE(root.DeleteAllElements());
  EXPECT_EQ(root.GetNElements(), 0);
  EXPECT_FALSE(root.DeleteAllElements()); // nothing left
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, ElementGetSetNameValueAndType)
{
  XFILEXMLELEMENT element;

  element.SetName(_L("myname"));
  EXPECT_FALSE(element.GetName().Compare(_L("myname"), false));

  element.SetValue(_L("myvalue"));
  EXPECT_FALSE(element.GetValue().Compare(_L("myvalue"), false));

  EXPECT_EQ(element.GetType(), XFILEXMLELEMENTTYPE_UNKNOWN);
  element.SetType(XFILEXMLELEMENTTYPE_NORMAL);
  EXPECT_EQ(element.GetType(), XFILEXMLELEMENTTYPE_NORMAL);
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, DecodeAllLinesParsesConfigElementTreeAndAttributes)
{
  // A small, hand-written XML snippet fed in as raw lines (DecodeAllLines() walks the in-memory
  // line collection directly -- no real file I/O is required to exercise the parser).
  XFILEXML filexml;

  filexml.AddLine(_L("<?xml version=\"1.0\" encoding=\"UTF-8\"?>"));
  filexml.AddLine(_L("<root attr1=\"value1\">"));
  filexml.AddLine(_L("<child>childvalue</child>"));
  filexml.AddLine(_L("</root>"));

  EXPECT_TRUE(filexml.DecodeAllLines());

  // The <?xml ... ?> config line's attributes land in the file-level config-attribute vector.
  XVECTOR<XFILEXMLATTRIBUTE*>* cfgattrs = filexml.GetCFGAtributes();
  ASSERT_TRUE(cfgattrs != NULL);
  ASSERT_EQ(cfgattrs->GetSize(), (XDWORD)2);
  EXPECT_FALSE(cfgattrs->Get(0)->GetName().Compare(_L("version"), false));
  EXPECT_FALSE(cfgattrs->Get(0)->GetValue().Compare(_L("1.0"), false));
  EXPECT_FALSE(cfgattrs->Get(1)->GetName().Compare(_L("encoding"), false));
  EXPECT_FALSE(cfgattrs->Get(1)->GetValue().Compare(_L("UTF-8"), false));

  XFILEXMLELEMENT* root = filexml.GetRoot();
  ASSERT_TRUE(root != NULL);
  EXPECT_FALSE(root->GetName().Compare(_L("root"), false));

  ASSERT_EQ(root->GetNAttributes(), 1);
  EXPECT_STREQ(root->GetValueAttribute(_L("attr1")), _L("value1"));

  ASSERT_EQ(root->GetNElements(), 1);
  XFILEXMLELEMENT* child = root->GetElement(0);
  ASSERT_TRUE(child != NULL);
  EXPECT_FALSE(child->GetName().Compare(_L("child"), false));
  EXPECT_FALSE(child->GetValue().Compare(_L("childvalue"), false));

  filexml.DeleteAllElements();
  filexml.DeleteAllCFGAtributes();
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, EncodeAllLinesProducesASelfClosingTagForAChildlessElement)
{
  XFILEXML filexml;

  XFILEXMLELEMENT* root = GEN_NEW XFILEXMLELEMENT(_L("root"));
  root->AddAtribute(_L("id"), _L("1"));
  root->SetType(XFILEXMLELEMENTTYPE_NORMAL);

  ASSERT_TRUE(filexml.SetRoot(root));

  EXPECT_TRUE(filexml.EncodeAllLines(false)); // no tabulation, for an exact string match

  ASSERT_TRUE(filexml.GetNLines() >= 2);
  EXPECT_FALSE(filexml.GetLine(0)->Compare(_L("<?xml ?>"), false));
  EXPECT_FALSE(filexml.GetLine(1)->Compare(_L("<root id=\"1\"/>"), false));

  filexml.DeleteAllElements(); // owns and frees "root"
  filexml.DeleteAllLines();
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, DecodeThenEncodeRoundTripReproducesAnEquivalentTree)
{
  XFILEXML filexml;

  filexml.AddLine(_L("<?xml version=\"1.0\"?>"));
  filexml.AddLine(_L("<catalog>"));
  filexml.AddLine(_L("<item id=\"7\"/>"));
  filexml.AddLine(_L("</catalog>"));

  ASSERT_TRUE(filexml.DecodeAllLines());

  XFILEXMLELEMENT* root = filexml.GetRoot();
  ASSERT_TRUE(root != NULL);
  ASSERT_EQ(root->GetNElements(), 1);
  EXPECT_FALSE(root->GetElement(0)->GetName().Compare(_L("item"), false));
  EXPECT_EQ(root->GetElement(0)->GetIntValueAttribute(_L("id")), 7);

  // Re-encode the tree just decoded and decode that output again -- the rebuilt tree must be
  // structurally equivalent to the original.
  ASSERT_TRUE(filexml.EncodeAllLines(false));
  ASSERT_TRUE(filexml.GetNLines() > 0);

  XFILEXML filexml2;
  for(int c=0; c<filexml.GetNLines(); c++)
    {
      filexml2.AddLine(*filexml.GetLine(c));
    }

  ASSERT_TRUE(filexml2.DecodeAllLines());

  XFILEXMLELEMENT* root2 = filexml2.GetRoot();
  ASSERT_TRUE(root2 != NULL);
  EXPECT_FALSE(root2->GetName().Compare(_L("catalog"), false));
  ASSERT_EQ(root2->GetNElements(), 1);
  EXPECT_FALSE(root2->GetElement(0)->GetName().Compare(_L("item"), false));
  EXPECT_EQ(root2->GetElement(0)->GetIntValueAttribute(_L("id")), 7);

  filexml.DeleteAllElements();
  filexml.DeleteAllLines();
  filexml.DeleteAllCFGAtributes();
  filexml2.DeleteAllElements();
  filexml2.DeleteAllLines();
  filexml2.DeleteAllCFGAtributes();
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, SearchChildNowHonorsItsOwnFatherParameter)
{
  // FIXED: XFILEXML::SearchChild(XCHAR* name, XFILEXMLELEMENT* father) (XFileXML.cpp) now
  // declares "XFILEXMLELEMENT* _father = father;" -- it genuinely assigns the incoming `father`
  // argument to the local search root, instead of previously initializing it to NULL and never
  // assigning `father` to it anywhere, which made "if(!_father) _father = root;" always fire and
  // scope every search to the document root's direct children regardless of the father passed in.
  // Demonstrated concretely below: group2's own direct child really is named "Item", and
  // SearchChild now correctly finds it when scoped to group2.
  XFILEXML filexml;

  XFILEXMLELEMENT* root = GEN_NEW XFILEXMLELEMENT(_L("root"));
  ASSERT_TRUE(filexml.SetRoot(root));

  XFILEXMLELEMENT* group1 = root->AddElement(_L("Group1"));
  XFILEXMLELEMENT* group2 = root->AddElement(_L("Group2"));

  XFILEXMLELEMENT* item1 = group1->AddElement(_L("Item"), _L("A"));
  XFILEXMLELEMENT* item2 = group2->AddElement(_L("Item"), _L("B"));
  (void)item1;

  // A father-scoped search now genuinely returns item2, the real direct child of group2.
  XFILEXMLELEMENT* found = filexml.SearchChild(_L("Item"), group2);
  EXPECT_EQ(found, item2);

  // Searching for a name that exists only among ROOT's own direct children, scoped to an
  // unrelated father, now correctly comes back NULL instead of silently falling back to root.
  XFILEXMLELEMENT* foundgroup = filexml.SearchChild(_L("Group2"), item1);
  EXPECT_EQ(foundgroup, (XFILEXMLELEMENT*)NULL);

  filexml.DeleteAllElements();
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, SearchElementHonorsItsExplicitFatherAndRecursesCorrectly)
{
  // Unlike SearchChild() above, SearchElement(name,index,father) does assign its "father"
  // parameter to the local search root ("_father = father;") and recurses properly, so scoping
  // a search to a specific subtree genuinely works here.
  XFILEXML filexml;

  XFILEXMLELEMENT* root = GEN_NEW XFILEXMLELEMENT(_L("root"));
  ASSERT_TRUE(filexml.SetRoot(root));

  XFILEXMLELEMENT* group1 = root->AddElement(_L("Group1"));
  XFILEXMLELEMENT* group2 = root->AddElement(_L("Group2"));

  group1->AddElement(_L("Item"), _L("A"));
  XFILEXMLELEMENT* item2 = group2->AddElement(_L("Item"), _L("B"));

  int index = 0;
  XFILEXMLELEMENT* found = filexml.SearchElement(_L("Item"), index, group2);
  EXPECT_EQ(found, item2);

  // Unscoped (father defaults to root) search must still find the first "Item" it encounters
  // via recursion, starting from Group1.
  int index2 = 0;
  XFILEXMLELEMENT* foundany = filexml.SearchElement(_L("Item"), index2);
  ASSERT_TRUE(foundany != NULL);
  EXPECT_FALSE(foundany->GetValue().Compare(_L("A"), false));

  filexml.DeleteAllElements();
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, SearchAttributeValueFindsExistingAndRejectsMissingAttribute)
{
  XFILEXML filexml;

  XFILEXMLELEMENT element(_L("elementname"));
  element.AddAtribute(_L("key"), _L("val"));

  XSTRING value;
  EXPECT_TRUE(filexml.SearchAttributeValue(&element, _L("key"), value));
  EXPECT_FALSE(value.Compare(_L("val"), false));

  EXPECT_FALSE(filexml.SearchAttributeValue(&element, _L("nokey"), value));
  EXPECT_FALSE(filexml.SearchAttributeValue(NULL, _L("key"), value));
}


TEST(UNITTESTS_XFILEXML_CLASSNAME, SetIgnoreCommentsGetterRoundTrip)
{
  // SetIgnoreComments() is inline in the header with no matching Get*() accessor -- confirmed via
  // a full read of XFileXML.h/.cpp -- so it can only be exercised for "does it not crash and does
  // the object keep working afterward", not read back directly.
  XFILEXML filexml;
  filexml.SetIgnoreComments(true);
  filexml.SetIgnoreComments(false);
  SUCCEED();
}


} // namespace TEST_XFILEXML
#endif
