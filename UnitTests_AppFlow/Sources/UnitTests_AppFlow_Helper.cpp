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
  body  = __L("[general]\r\n");
  body += __L("showdetailinfo=0\r\n");

  return WriteTextAsset(cfgfilename, body.Get());
}


bool WriteOfflineAppFlowCfgAsset(XCHAR* cfgfilename)
{
  XSTRING body;

  body  = __L("[general]\r\n");
  body += __L("showdetailinfo=0\r\n");

  body += __L("[check resources hardware]\r\n");
  body += __L("memstatuscheckcadenceseconds=0\r\n");
  body += __L("memstatuslimitpercent=10\r\n");
  body += __L("totalcpuusagecheckcadenceseconds=0\r\n");
  body += __L("totalcpuusagelimitpercent=90\r\n");
  body += __L("appcpuusageprocessname=\r\n");
  body += __L("appcpuusagecheckcadenceseconds=0\r\n");
  body += __L("appcpuusagelimitpercent=90\r\n");

  body += __L("[internet services]\r\n");
  body += __L("checkinternetstatuscadenceseconds=0\r\n");
  body += __L("donotletinternetconnectionmatter=si\r\n");
  body += __L("checkipschangecadenceseconds=0\r\n");
  body += __L("updatetimebyntpcadencehours=0\r\n");

  body += __L("[location]\r\n");
  body += __L("street=UnitTest Street\r\n");
  body += __L("city=UnitTestCity\r\n");
  body += __L("state=UT\r\n");
  body += __L("country=TC\r\n");
  body += __L("postalcode=28001\r\n");

  body += __L("[applicationupdate]\r\n");
  body += __L("isactive=no\r\n");
  body += __L("url=http://example.invalid/update\r\n");
  body += __L("port=8080\r\n");
  body += __L("checkcadenceminutes=0\r\n");
  body += __L("checktime=\r\n");
  body += __L("maxrestorations=1\r\n");

  body += __L("[webserver]\r\n");
  body += __L("localaddr=127.0.0.1\r\n");
  body += __L("port=18080\r\n");
  body += __L("timeouttoserverpage=5\r\n");
  body += __L("isauthenticatedaccess=no\r\n");
  body += __L("login=unittest\r\n");
  body += __L("password=secret\r\n");

  body += __L("[alerts]\r\n");
  body += __L("isactive=si\r\n");
  body += __L("smtp_isactive=no\r\n");
  body += __L("sms_isactive=no\r\n");
  body += __L("web_isactive=no\r\n");
  body += __L("udp_isactive=no\r\n");

  body += __L("[log]\r\n");
  body += __L("isactive=si\r\n");
  body += __L("backupisactive=no\r\n");
  body += __L("backupmaxfiles=1\r\n");
  body += __L("backupiscompress=no\r\n");
  body += __L("activesectionsID=Ini,General,Status,End\r\n");
  body += __L("levelmask=000F\r\n");
  body += __L("maxsize=100\r\n");
  body += __L("reductionpercent=10\r\n");

  return WriteTextAsset(cfgfilename, body.Get());
}


}
