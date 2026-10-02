/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Graphic_Helper.cpp
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
/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Defines.h"


/*---- INCLUDES ------------------------------------------------------------------------------------------------------*/

#include "UnitTests_Graphic_Helper.h"

#include "XBuffer.h"
#include "XFactory.h"
#include "XFile.h"
#include "XPathsManager.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

namespace UNITTESTS_GRAPHIC_HELPER
{


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool BuildAssetPath(XPATH& out, XCHAR* filename)
* @brief      Build path under assets ROOT section + filename.
* @ingroup    UNIT TEST
*
* @param[out] out : Receives the full path.
* @param[in]  filename : File name to append.
*
* @return     bool : true if the operation is successful; otherwise false.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool BuildAssetPath(XPATH& out, XCHAR* filename)
{
  if(!filename) return false;

  if(!GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, out)) return false;

  out += filename;

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool EraseAsset(XPATH& xpath)
* @brief      Erase an asset file at xpath.
* @ingroup    UNIT TEST
*
* @param[in]  xpath : Full path of the file to erase.
*
* @return     bool : true if the operation is successful; otherwise false.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool EraseAsset(XPATH& xpath)
{
  if(xpath.IsEmpty()) return false;

  XFILE* xfile = GEN_XFACTORY.Create_File();
  if(!xfile) return false;

  bool status = true;

  if(xfile->Exist(xpath))
    {
      status = xfile->Erase(xpath);
    }

  GEN_XFACTORY.Delete_File(xfile);

  return status;
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool WriteTextAsset(XCHAR* filename, XCHAR* content)
* @brief      Write XCHAR text content to ROOT + filename as UTF-8 via XFILE.
* @ingroup    UNIT TEST
*
* @param[in]  filename : File name under assets ROOT.
* @param[in]  content : Text content (XCHAR / UTF16 on Windows).
*
* @return     bool : true if the operation is successful; otherwise false.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool WriteTextAsset(XCHAR* filename, XCHAR* content)
{
  if(!filename) return false;
  if(!content)  return false;

  XPATH xpath;
  if(!BuildAssetPath(xpath, filename)) return false;

  XSTRING text(content);
  XBUFFER utf8;

  if(!text.ConvertToUTF8(utf8, false)) return false;

  XFILE* xfile = GEN_XFACTORY.Create_File();
  if(!xfile) return false;

  bool status = false;

  if(xfile->Create(xpath))
    {
      status = xfile->Write(utf8.Get(), utf8.GetSize());
      xfile->Close();
    }

  GEN_XFACTORY.Delete_File(xfile);

  return status;
}


}
