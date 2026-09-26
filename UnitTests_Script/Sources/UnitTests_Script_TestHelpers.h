/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script_TestHelpers.h
* @brief      Common helpers for Script unit tests
* @ingroup    TESTS
*
* @copyright  EndoraSoft. All rights reserved.
*
* @class      UNITTESTS_SCRIPT_ERRORCAPTURE
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
#pragma once

/*---- INCLUDES ------------------------------------------------------------------------------------------------------*/

#include "gtest/gtest.h"

#include "Script.h"
#include "Script_Lib.h"

/*---- INLINE FUNCTIONS + PROTOTYPES ---------------------------------------------------------------------------------*/

class UNITTESTS_SCRIPT_ERRORCAPTURE : public SCRIPT
{
  public:

    UNITTESTS_SCRIPT_ERRORCAPTURE() : lasterror(SCRIPT_ERRORCODE_NONE) { }

    bool HaveError(int errorcode)
    {
      lasterror = errorcode;
      return SCRIPT::HaveError(errorcode);
    }

    int GetLastError() const
    {
      return lasterror;
    }

    void ResetLastError()
    {
      lasterror = SCRIPT_ERRORCODE_NONE;
    }

  private:

    int lasterror;
};

inline void UnitTests_Script_DummyFunction(SCRIPT_LIB* library, SCRIPT* script, XVECTOR<XVARIANT*>* params, XVARIANT* returnvalue)
{
  if(returnvalue) (*returnvalue) = 1;
}


inline void UnitTests_Script_ExpectLibraryRegistration(SCRIPT_LIB& library, XCHAR* expectedID, XCHAR* functionname)
{
  SCRIPT script;

  ASSERT_NE(library.GetID(), (XSTRING*)NULL);
  EXPECT_EQ(library.GetID()->Compare(expectedID), 0);
  EXPECT_FALSE(library.AddLibraryFunctions(NULL));
  EXPECT_TRUE(library.AddLibraryFunctions(&script));
  EXPECT_NE(script.GetLibraryFunction(functionname), (SCRIPT_LIB_FUNCTION*)NULL);
}


#define UNITTESTS_SCRIPT_LIBRARY_REGISTRATION_TEST(testnamespace, classname, librarytype, libraryID, functionname) \
namespace testnamespace                                                                                                  \
{                                                                                                                        \
  TEST(classname, IdentityAndRegistration)                                                                                \
  {                                                                                                                      \
    librarytype library;                                                                                                 \
    UnitTests_Script_ExpectLibraryRegistration(library, libraryID, functionname);                                        \
  }                                                                                                                      \
}

