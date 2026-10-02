/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_Helper.h
*
* @class      UNITTESTS_GRAPHIC_HELPER
* @brief      Shared helpers for Graphic unit tests (not a gtest suite)
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
#pragma once

/*---- INCLUDES ------------------------------------------------------------------------------------------------------*/

#include "XPath.h"


/*---- DEFINES & ENUMS  ----------------------------------------------------------------------------------------------*/


/*---- CLASS ---------------------------------------------------------------------------------------------------------*/

namespace UNITTESTS_GRAPHIC_HELPER
{

  // Build path under assets: GEN_XPATHSMANAGER GetPathOfSection ROOT + filename
  bool BuildAssetPath(XPATH& out, XCHAR* filename);

  // Erase file at xpath (no-op success if missing)
  bool EraseAsset(XPATH& xpath);

  // Write UTF16/XCHAR text content to ROOT + filename via XFILE (UTF-8 bytes on disk)
  bool WriteTextAsset(XCHAR* filename, XCHAR* content);

}


/*---- INLINE FUNCTIONS + PROTOTYPES ---------------------------------------------------------------------------------*/
