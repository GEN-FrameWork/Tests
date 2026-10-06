/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow_Helper.cpp
*
* @class      UNITTESTS_APPFLOW_HELPER
* @brief      Shared helpers for AppFlow unit tests
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

#include "UnitTests_AppFlow_Helper.h"

#include "XBuffer.h"
#include "XFactory.h"
#include "XFile.h"
#include "XPathsManager.h"
#include "XString.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

namespace UNITTESTS_APPFLOW_HELPER
{


bool BuildAssetPath(XPATH& out, XCHAR* filename)
{
  if(!filename) return false;

  if(!GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, out)) return false;

  out += filename;

  return true;
}


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


bool WriteMinimalAppFlowCfgAsset(XCHAR* cfgfilename)
{
  XSTRING body;
  body  = _L("[general]\r\n");
  body += _L("showdetailinfo=0\r\n");

  return WriteTextAsset(cfgfilename, body.Get());
}


bool WriteOfflineAppFlowCfgAsset(XCHAR* cfgfilename)
{
  XSTRING body;

  body  = _L("[general]\r\n");
  body += _L("showdetailinfo=0\r\n");

  body += _L("[check resources hardware]\r\n");
  body += _L("memstatuscheckcadenceseconds=0\r\n");
  body += _L("memstatuslimitpercent=10\r\n");
  body += _L("totalcpuusagecheckcadenceseconds=0\r\n");
  body += _L("totalcpuusagelimitpercent=90\r\n");
  body += _L("appcpuusageprocessname=\r\n");
  body += _L("appcpuusagecheckcadenceseconds=0\r\n");
  body += _L("appcpuusagelimitpercent=90\r\n");

  body += _L("[internet services]\r\n");
  body += _L("checkinternetstatuscadenceseconds=0\r\n");
  body += _L("donotletinternetconnectionmatter=si\r\n");
  body += _L("checkipschangecadenceseconds=0\r\n");
  body += _L("updatetimebyntpcadencehours=0\r\n");

  body += _L("[location]\r\n");
  body += _L("street=UnitTest Street\r\n");
  body += _L("city=UnitTestCity\r\n");
  body += _L("state=UT\r\n");
  body += _L("country=TC\r\n");
  body += _L("postalcode=28001\r\n");

  body += _L("[applicationupdate]\r\n");
  body += _L("isactive=no\r\n");
  body += _L("url=http://example.invalid/update\r\n");
  body += _L("port=8080\r\n");
  body += _L("checkcadenceminutes=0\r\n");
  body += _L("checktime=\r\n");
  body += _L("maxrestorations=1\r\n");

  body += _L("[webserver]\r\n");
  body += _L("localaddr=127.0.0.1\r\n");
  body += _L("port=18080\r\n");
  body += _L("timeouttoserverpage=5\r\n");
  body += _L("isauthenticatedaccess=no\r\n");
  body += _L("login=unittest\r\n");
  body += _L("password=secret\r\n");

  body += _L("[alerts]\r\n");
  body += _L("isactive=si\r\n");
  body += _L("smtp_isactive=no\r\n");
  body += _L("sms_isactive=no\r\n");
  body += _L("web_isactive=no\r\n");
  body += _L("udp_isactive=no\r\n");

  body += _L("[log]\r\n");
  body += _L("isactive=si\r\n");
  body += _L("backupisactive=no\r\n");
  body += _L("backupmaxfiles=1\r\n");
  body += _L("backupiscompress=no\r\n");
  body += _L("activesectionsID=Ini,General,Status,End\r\n");
  body += _L("levelmask=000F\r\n");
  body += _L("maxsize=100\r\n");
  body += _L("reductionpercent=10\r\n");

  return WriteTextAsset(cfgfilename, body.Get());
}


}
