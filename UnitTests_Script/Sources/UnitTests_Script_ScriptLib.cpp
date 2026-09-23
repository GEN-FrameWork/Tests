/**-------------------------------------------------------------------------------------------------------------------
* @file       UnitTests_Script_ScriptLib.cpp
* @brief      Unit tests for SCRIPT_LIB
* @ingroup    TESTS
* --------------------------------------------------------------------------------------------------------------------*/
#include "GEN_Defines.h"
#include "UnitTests_Script_ScriptLib.h"
#include "UnitTests_Script_TestHelpers.h"
#include "GEN_Control.h"

#ifdef GOOGLETEST_ACTIVE
namespace TEST_SCRIPTLIB
{

TEST(UNITTESTS_SCRIPTLIB_CLASSNAME, ConvertsSupportedVariantTypes)
{
  SCRIPT_LIB library(__L("Test"));
  XVARIANT integer(25);
  XVARIANT real(2.5f);
  XVARIANT text(__L("value"));
  int convertedinteger = 0;
  float convertedreal = 0.0f;
  XSTRING convertedtext;

  EXPECT_TRUE(library.GetParamConverted(&integer, convertedinteger));
  EXPECT_EQ(convertedinteger, 25);
  EXPECT_TRUE(library.GetParamConverted(&real, convertedreal));
  EXPECT_FLOAT_EQ(convertedreal, 2.5f);
  EXPECT_TRUE(library.GetParamConverted(&text, convertedtext));
  EXPECT_EQ(convertedtext.Compare(__L("value")), 0);
  EXPECT_FALSE(library.GetParamConverted(NULL, convertedinteger));
}


TEST(UNITTESTS_SCRIPTLIB_CLASSNAME, ConvertsBooleanAndNumericAliases)
{
  SCRIPT_LIB library(__L("Test"));
  XVARIANT boolean(true);
  XVARIANT integer(7);
  XVARIANT real(3.5);
  bool convertedboolean = false;
  int convertedinteger = 0;
  double converteddouble = 0.0;
  XDWORD converteddword = 0;

  EXPECT_TRUE(library.GetParamConverted(&boolean, convertedboolean));
  EXPECT_TRUE(convertedboolean);
  EXPECT_TRUE(library.GetParamConverted(&integer, convertedinteger));
  EXPECT_EQ(convertedinteger, 7);
  EXPECT_TRUE(library.GetParamConverted(&real, converteddouble));
  EXPECT_DOUBLE_EQ(converteddouble, 3.5);
  EXPECT_TRUE(library.GetParamConverted(&integer, converteddword));
  EXPECT_EQ(converteddword, (XDWORD)7);
}


TEST(UNITTESTS_SCRIPTLIB_CLASSNAME, RejectsIncompatibleTargetTypes)
{
  SCRIPT_LIB library(__L("Test"));
  XVARIANT text(__L("not-a-number"));
  int convertedinteger = 0;
  bool convertedboolean = false;

  EXPECT_FALSE(library.GetParamConverted(&text, convertedinteger));
  EXPECT_FALSE(library.GetParamConverted(&text, convertedboolean));
}

}
#endif
