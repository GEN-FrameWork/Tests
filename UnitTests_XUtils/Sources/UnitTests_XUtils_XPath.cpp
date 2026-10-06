/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_XUtils_XPath.cpp
*
* @class      UNITTESTS_XUTILS_XPATH
* @brief      XUtils unit tests for XPath class
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

#include "UnitTests_XUtils_XPath.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "XPath.h"
#include "XPathsManager.h"
#include "XVector.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/


#ifdef GOOGLETEST_ACTIVE
namespace TEST_XPATH
{


TEST(UNITTESTS_XPATH_CLASSNAME, ConstructorsBuildExpectedContent)
{
  XPATH xpathchar("hello/world");
  EXPECT_STREQ(xpathchar.Get(), _L("hello/world"));

  XPATH xpathwide(_L("wide/path"));
  EXPECT_STREQ(xpathwide.Get(), _L("wide/path"));

  XPATH xpathcopy(xpathwide);
  EXPECT_STREQ(xpathcopy.Get(), _L("wide/path"));

  XSTRING sourcestring(_L("from/string"));
  XPATH   xpathfromstring(sourcestring);
  EXPECT_STREQ(xpathfromstring.Get(), _L("from/string"));

  XPATH xpathempty;
  EXPECT_TRUE(xpathempty.IsEmpty());
}


TEST(UNITTESTS_XPATH_CLASSNAME, AssignmentOperatorsOverwriteContent)
{
  XPATH xpath;

  xpath = "assigned/char";
  EXPECT_STREQ(xpath.Get(), _L("assigned/char"));

  xpath = _L("assigned/wide");
  EXPECT_STREQ(xpath.Get(), _L("assigned/wide"));

  XPATH other(_L("other/value"));
  xpath = other;
  EXPECT_STREQ(xpath.Get(), _L("other/value"));

  XSTRING stringvalue(_L("string/value"));
  xpath = stringvalue;
  EXPECT_STREQ(xpath.Get(), _L("string/value"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, PlusEqualsOperatorsAppendContent)
{
  XPATH xpath(_L("base"));

  xpath += "/char";
  EXPECT_STREQ(xpath.Get(), _L("base/char"));

  xpath += _L("/wide");
  EXPECT_STREQ(xpath.Get(), _L("base/char/wide"));

  XPATH appended(_L("/more"));
  xpath += appended;
  EXPECT_STREQ(xpath.Get(), _L("base/char/wide/more"));

  XSTRING stringappend(_L("/tail"));
  xpath += stringappend;
  EXPECT_STREQ(xpath.Get(), _L("base/char/wide/more/tail"));

  xpath += _C('!');
  EXPECT_STREQ(xpath.Get(), _L("base/char/wide/more/tail!"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, ComparisonOperatorsAgainstXPath)
{
  XPATH lower(_L("aaa"));
  XPATH higher(_L("bbb"));
  XPATH same(_L("aaa"));

  EXPECT_TRUE(lower  < higher);
  EXPECT_TRUE(higher > lower);
  EXPECT_TRUE(lower  <= same);
  EXPECT_TRUE(lower  >= same);
  EXPECT_TRUE(lower  == same);
  EXPECT_TRUE(lower  != higher);
  EXPECT_FALSE(lower == higher);
}


TEST(UNITTESTS_XPATH_CLASSNAME, ComparisonOperatorsAgainstXString)
{
  XPATH   xpath(_L("aaa"));
  XSTRING higher(_L("bbb"));
  XSTRING same(_L("aaa"));

  EXPECT_TRUE(xpath <  higher);
  EXPECT_TRUE(xpath <= same);
  EXPECT_TRUE(xpath >= same);
  EXPECT_TRUE(xpath == same);
  EXPECT_TRUE(xpath != higher);
  EXPECT_FALSE(xpath > higher);
}


TEST(UNITTESTS_XPATH_CLASSNAME, IndexOperatorClampsOutOfRangePositions)
{
  XPATH xpath(_L("abc"));

  EXPECT_EQ(xpath[0], _C('a'));
  EXPECT_EQ(xpath[1], _C('b'));
  EXPECT_EQ(xpath[2], _C('c'));

  // Negative position clamps to the first character (per source, not a documented contract).
  EXPECT_EQ(xpath[-1], _C('a'));

  // Out-of-range clamps to the last character.
  EXPECT_EQ(xpath[100], _C('c'));

  XPATH xpathempty;
  EXPECT_EQ(xpathempty[0], (XCHAR)0);
}


TEST(UNITTESTS_XPATH_CLASSNAME, SplitExtractsDriveXpathNameAndExt)
{
  XPATH   xpath(_L("C:\\folder\\sub\\file.txt"));
  XSTRING drive;
  XPATH   xpathpart;
  XSTRING name;
  XSTRING ext;

  EXPECT_TRUE(xpath.Split(&drive, &xpathpart, &name, &ext));

  EXPECT_STREQ(drive.Get(), _L("C:"));
  EXPECT_STREQ(xpathpart.Get(), _L("\\folder\\sub\\"));
  EXPECT_STREQ(name.Get(), _L("file"));
  EXPECT_STREQ(ext.Get(), _L(".txt"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, SplitOnEmptyPathReturnsFalse)
{
  XPATH xpath;

  EXPECT_FALSE(xpath.Split(NULL, NULL, NULL, NULL));
}


TEST(UNITTESTS_XPATH_CLASSNAME, GetDriveGetPathAndGetDriveAndPath)
{
  XPATH   xpath(_L("C:\\folder\\sub\\file.txt"));
  XSTRING drive;
  XSTRING path;
  XSTRING drivepath;

  EXPECT_TRUE(xpath.GetDrive(drive));
  EXPECT_STREQ(drive.Get(), _L("C:"));

  EXPECT_TRUE(xpath.GetPath(path));
  EXPECT_STREQ(path.Get(), _L("\\folder\\sub\\"));

  EXPECT_TRUE(xpath.GetDriveAndPath(drivepath));
  EXPECT_STREQ(drivepath.Get(), _L("C:\\folder\\sub\\"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, GetNamefileVariantsAndExt)
{
  XPATH   xpath(_L("C:\\folder\\sub\\file.txt"));
  XSTRING pathnamefile;
  XSTRING pathnamefileext;
  XSTRING namefile;
  XSTRING namefileext;
  XSTRING ext;

  EXPECT_TRUE(xpath.GetPathAndNamefile(pathnamefile));
  EXPECT_STREQ(pathnamefile.Get(), _L("\\folder\\sub\\file"));

  EXPECT_TRUE(xpath.GetPathAndNamefileExt(pathnamefileext));
  EXPECT_STREQ(pathnamefileext.Get(), _L("\\folder\\sub\\file.txt"));

  EXPECT_TRUE(xpath.GetNamefile(namefile));
  EXPECT_STREQ(namefile.Get(), _L("file"));

  EXPECT_TRUE(xpath.GetNamefileExt(namefileext));
  EXPECT_STREQ(namefileext.Get(), _L("file.txt"));

  EXPECT_TRUE(xpath.GetExt(ext));
  EXPECT_STREQ(ext.Get(), _L(".txt"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, GetPathInSequenceReturnsEachSlashDelimitedSegment)
{
  XPATH   xpath(_L("/tmp/alpha/beta"));
  XSTRING part;

  EXPECT_TRUE(xpath.GetPathInSequence(0, part));
  EXPECT_STREQ(part.Get(), _L(""));

  EXPECT_TRUE(xpath.GetPathInSequence(1, part));
  EXPECT_STREQ(part.Get(), _L("tmp"));

  EXPECT_TRUE(xpath.GetPathInSequence(2, part));
  EXPECT_STREQ(part.Get(), _L("alpha"));

  // NOTE (source behavior, not a bug we fix): the final segment ("beta") is only ever
  // yielded when it is followed by a slash. Since this path has no trailing slash, requesting
  // the index past the last slash falls through the loop, empties pathpart and returns false -
  // "beta" itself is never reported as a found segment. Callers relying on this (e.g.
  // XLINUXDIR::Make's recursive directory creation) must account for this off-by-one.
  EXPECT_FALSE(xpath.GetPathInSequence(3, part));
  EXPECT_TRUE(part.IsEmpty());
}


TEST(UNITTESTS_XPATH_CLASSNAME, SetOnlyVariantsMutateInPlace)
{
  // BUG (XPath.cpp, every SetOnlyXXX() method, e.g. SetOnlyDrive() around line 840-851):
  // each of these methods builds its result in a *local* XSTRING, calls Set(string) to update
  // `this` (which deep-copies - so the XPATH object itself ends up correct), and then does
  // `return string.Get();` - returning a pointer into that local's buffer. The local is
  // destroyed (freeing its buffer) during stack unwind before the caller ever reads through
  // that pointer, so the returned `const XCHAR*` is a dangling/use-after-free pointer, not a
  // usable string - confirmed empirically (it prints as garbage bytes here). We do NOT read
  // the return value for that reason; we only assert the well-defined side effect, which is
  // that `this` (the XPATH object) itself ends up holding the correct value.
  XPATH xpath(_L("C:\\folder\\sub\\file.txt"));
  XPATH original(xpath);

  xpath = original; xpath.SetOnlyDrive();             EXPECT_STREQ(xpath.Get(), _L("C:"));
  xpath = original; xpath.SetOnlyPath();               EXPECT_STREQ(xpath.Get(), _L("\\folder\\sub\\"));
  xpath = original; xpath.SetOnlyDriveAndPath();       EXPECT_STREQ(xpath.Get(), _L("C:\\folder\\sub\\"));
  xpath = original; xpath.SetOnlyPathAndNamefile();    EXPECT_STREQ(xpath.Get(), _L("\\folder\\sub\\file"));
  xpath = original; xpath.SetOnlyPathAndNamefileExt(); EXPECT_STREQ(xpath.Get(), _L("\\folder\\sub\\file.txt"));
  xpath = original; xpath.SetOnlyNamefile();           EXPECT_STREQ(xpath.Get(), _L("file"));
  xpath = original; xpath.SetOnlyNamefileExt();        EXPECT_STREQ(xpath.Get(), _L("file.txt"));
  xpath = original; xpath.SetOnlyExt();                EXPECT_STREQ(xpath.Get(), _L(".txt"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, DeleteDriveRemovesLeadingDriveLetter)
{
  XPATH xpath(_L("C:\\folder\\file.txt"));

  EXPECT_TRUE(xpath.DeleteDrive());
  EXPECT_STREQ(xpath.Get(), _L("\\folder\\file.txt"));

  // No drive present: GetSize() <= 2 short path rejected.
  XPATH shortpath(_L("ab"));
  EXPECT_FALSE(shortpath.DeleteDrive());

  // No ':' at position 1.
  XPATH nodrive(_L("folder/file.txt"));
  EXPECT_FALSE(nodrive.DeleteDrive());
}


TEST(UNITTESTS_XPATH_CLASSNAME, DeleteExtStripsExtensionKeepingPathAndName)
{
  XPATH xpath(_L("C:\\folder\\file.txt"));

  EXPECT_TRUE(xpath.DeleteExt());
  EXPECT_STREQ(xpath.Get(), _L("\\folder\\file"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, SlashHaveAtLast)
{
  XPATH withslash(_L("folder/"));
  XPATH withoutslash(_L("folder"));

  EXPECT_TRUE(withslash.Slash_HaveAtLast());
  EXPECT_FALSE(withoutslash.Slash_HaveAtLast());
}


TEST(UNITTESTS_XPATH_CLASSNAME, SlashAddAppendsSlashMatchingMajorityStyle)
{
  XPATH forwardstyle(_L("folder/sub"));
  EXPECT_TRUE(forwardstyle.Slash_Add());
  EXPECT_STREQ(forwardstyle.Get(), _L("folder/sub/"));

  // Calling again on an already-terminated path is a documented no-op (returns false).
  EXPECT_FALSE(forwardstyle.Slash_Add());
  EXPECT_STREQ(forwardstyle.Get(), _L("folder/sub/"));

  XPATH backslashstyle(_L("folder\\sub"));
  EXPECT_TRUE(backslashstyle.Slash_Add());
  // Slash_Add() normalizes after adding, so the trailing separator becomes '/' even though the
  // majority-style vote chose '\' (Slash_Normalize() runs unconditionally after the Add()).
  EXPECT_STREQ(backslashstyle.Get(), _L("folder/sub/"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, SlashNormalizeConvertsBackslashesToForwardByDefault)
{
  XPATH mixed(_L("folder\\sub\\file"));

  EXPECT_TRUE(mixed.Slash_Normalize());
  EXPECT_STREQ(mixed.Get(), _L("folder/sub/file"));

  EXPECT_TRUE(mixed.Slash_Normalize(true));
  EXPECT_STREQ(mixed.Get(), _L("folder\\sub\\file"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, SlashDeleteRemovesTrailingSeparator)
{
  XPATH withslash(_L("folder/sub/"));

  EXPECT_TRUE(withslash.Slash_Delete());
  EXPECT_STREQ(withslash.Get(), _L("folder/sub"));
  EXPECT_FALSE(withslash.Slash_HaveAtLast());

  // No trailing separator: documented no-op (returns false).
  EXPECT_FALSE(withslash.Slash_Delete());
}


TEST(UNITTESTS_XPATH_CLASSNAME, AddToNameFilePrefixAndSuffix)
{
  XPATH prefixed(_L("folder/sub/file.txt"));
  EXPECT_TRUE(prefixed.AddToNameFile(true, (XCHAR*)_L("pre_")));
  EXPECT_STREQ(prefixed.Get(), _L("folder/sub/pre_file.txt"));

  XPATH suffixed(_L("folder/sub/file.txt"));
  EXPECT_TRUE(suffixed.AddToNameFile(false, (XCHAR*)_L("_v2")));
  EXPECT_STREQ(suffixed.Get(), _L("folder/sub/file_v2.txt"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, CreateJoinsSegmentsWithNormalizedSlash)
{
  XPATH xpath;

  EXPECT_TRUE(xpath.Create(3, _L("folder"), _L("sub"), _L("file.txt")));
  EXPECT_STREQ(xpath.Get(), _L("folder/sub/file.txt"));

  // A segment starting with '.' (e.g. a bare extension continuation) does not get a separator
  // forced in front of it.
  XPATH xpathwithdot;
  EXPECT_TRUE(xpathwithdot.Create(2, _L("file"), _L(".txt")));
  EXPECT_STREQ(xpathwithdot.Get(), _L("file.txt"));

  // Empty elements among the varargs are skipped entirely.
  XPATH xpathskipsempty;
  EXPECT_TRUE(xpathskipsempty.Create(3, _L("folder"), _L(""), _L("file.txt")));
  EXPECT_STREQ(xpathskipsempty.Get(), _L("folder/file.txt"));
}


TEST(UNITTESTS_XPATH_CLASSNAME, CreateWithSectionPrependsRootSection)
{
  // Relies on the ROOT path section already being configured by the application's own
  // AppProc_Ini() (AdjustRootPathDefault), exactly as UnitTests_XUtils.cpp does for real.
  ASSERT_TRUE(XPATHSMANAGER::GetIsInstanced());

  XPATH xpathroot;
  ASSERT_TRUE(GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpathroot));

  XPATH xpath;
  EXPECT_TRUE(xpath.Create(XPATHSMANAGERSECTIONTYPE_ROOT, 2, _L("subdir"), _L("file.dat")));

  XSTRING expected;
  expected  = xpathroot.Get();
  expected += _L("subdir/file.dat");

  EXPECT_STREQ(xpath.Get(), expected.Get());
}


TEST(UNITTESTS_XPATH_CLASSNAME, SplitWithSubpathsVectorPopulatesEachComponent)
{
  XPATH             xpath(_L("/alpha/beta/gamma.txt"));
  XVECTOR<XSTRING*> subpaths;
  XSTRING           name;
  XSTRING           ext;

  EXPECT_TRUE(xpath.Split(NULL, subpaths, &name, &ext));

  // NOTE (source behavior): the intermediate xpath ("/alpha/beta/") ends in a separator, and
  // the tokenizer loop treats the position exactly at GetSize() as a delimiter too (it reads
  // one past the last real character, which XSTRING::operator[] clamps back to that last
  // character - the separator itself - so the trailing-separator branch fires twice), so a
  // trailing empty XSTRING* is appended in addition to the two real segments.
  ASSERT_EQ(subpaths.GetSize(), (XDWORD)3);
  EXPECT_STREQ(subpaths.Get(0)->Get(), _L("alpha"));
  EXPECT_STREQ(subpaths.Get(1)->Get(), _L("beta"));
  EXPECT_STREQ(subpaths.Get(2)->Get(), _L(""));

  // BUG (XPath.cpp, XPATH::Split(XSTRING*, XVECTOR<XSTRING*>&, XSTRING*, XSTRING*), around
  // line 1417-1470): this overload extracts the name/ext into *local* `_name`/`_ext` variables
  // (via the 4-pointer Split() it calls internally) but never copies them into the caller's
  // `name`/`ext` out-parameters - the `name`/`ext` pointers passed in are only ever consulted
  // for a null-check (deciding whether to fold the name into the path), never written to. So
  // both out-parameters are always left exactly as the caller passed them in (empty here),
  // confirmed empirically - not the "gamma"/".txt" a caller would reasonably expect.
  EXPECT_STREQ(name.Get(), _L(""));
  EXPECT_STREQ(ext.Get(), _L(""));

  // The vector owns heap-allocated XSTRING* elements (GEN_NEW'd inside Split) - the caller is
  // responsible for freeing them; clean up here to avoid leaking in the test itself.
  subpaths.DeleteContents();
  subpaths.DeleteAll();
}


}
#endif
