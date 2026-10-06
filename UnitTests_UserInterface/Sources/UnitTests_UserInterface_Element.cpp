/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_UserInterface_Element.cpp
*
* @brief      UserInterface unit tests for UI_ELEMENT (core identity / visibility / tree)
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @class      UNITTESTS_USERINTERFACE_ELEMENT
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

#include "UnitTests_UserInterface_Element.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "UI_Element.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

#ifdef GOOGLETEST_ACTIVE
namespace TEST_UI_ELEMENT
{


TEST(UNITTESTS_UI_ELEMENT_CLASSNAME, DefaultTypeIsUnknownAndVisibleByDefault)
{
  UI_ELEMENT element;

  EXPECT_EQ(element.GetType(), UI_ELEMENT_TYPE_UNKNOWN);
  EXPECT_TRUE(element.IsVisible());
  EXPECT_EQ(element.GetFather(), (UI_ELEMENT*)NULL);
  ASSERT_NE(element.GetName(), (XSTRING*)NULL);
  EXPECT_TRUE(element.GetName()->IsEmpty());
}


TEST(UNITTESTS_UI_ELEMENT_CLASSNAME, SetTypeAndNameRoundTrip)
{
  UI_ELEMENT element;

  element.SetType(UI_ELEMENT_TYPE_BUTTON);
  element.GetName()->Set(_L("ok_button"));

  EXPECT_EQ(element.GetType(), UI_ELEMENT_TYPE_BUTTON);
  EXPECT_EQ(element.GetName()->Compare(_L("ok_button"), true), 0);
}


TEST(UNITTESTS_UI_ELEMENT_CLASSNAME, VisibilityToggleRoundTrips)
{
  UI_ELEMENT element;

  element.SetVisible(false);
  EXPECT_FALSE(element.IsVisible());
  element.SetVisible(true);
  EXPECT_TRUE(element.IsVisible());
}


TEST(UNITTESTS_UI_ELEMENT_CLASSNAME, ClassNamesParseAndHasClassMatchesTokens)
{
  UI_ELEMENT element;

  element.SetClassNames(_L("card flex-row primary"));
  EXPECT_TRUE(element.HasClass(_L("card")));
  EXPECT_TRUE(element.HasClass(_L("flex-row")));
  EXPECT_TRUE(element.HasClass(_L("primary")));
  EXPECT_FALSE(element.HasClass(_L("missing")));
}


TEST(UNITTESTS_UI_ELEMENT_CLASSNAME, FatherAndComposeTreeLinkWithoutOwningDuplicatesOnDeleteAll)
{
  UI_ELEMENT* parent = new UI_ELEMENT();
  UI_ELEMENT* child  = new UI_ELEMENT();

  parent->GetName()->Set(_L("parent"));
  child->GetName()->Set(_L("child"));

  child->SetFather(parent);
  parent->GetComposeElements()->Add(child);

  EXPECT_EQ(child->GetFather(), parent);
  ASSERT_EQ(parent->GetComposeElements()->GetSize(), 1);
  EXPECT_EQ(parent->GetComposeElements()->Get(0), child);

  // DeleteAllComposeElements owns and deletes the children.
  ASSERT_TRUE(parent->DeleteAllComposeElements());
  EXPECT_TRUE(parent->GetComposeElements()->IsEmpty());

  delete parent;
}


} // namespace TEST_UI_ELEMENT
#endif // GOOGLETEST_ACTIVE
