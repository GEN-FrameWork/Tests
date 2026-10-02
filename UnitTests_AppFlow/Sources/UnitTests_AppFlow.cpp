/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_AppFlow.cpp
*
* @class      UNITTESTS_APPFLOW
* @brief      AppFlow unit tests application
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

#include "UnitTests_AppFlow.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "VersionFrameWork.h"

#include "XTranslation_GEN.h"
#include "XTranslation.h"

#include "XThreadListNonPreemptive.h"

#ifdef APPFLOW_ALERTS_ACTIVE
#include "APPFlowAlerts.h"
#endif

#ifdef APPFLOW_EXTENDED_ACTIVE
#include "APPFlowExtended.h"
#endif

#ifdef APPFLOW_LOG_ACTIVE
#include "APPFlowLog.h"
#endif

#ifdef GRP_ACTIVE
#include "GRPFactory.h"
#endif

#ifdef INP_ACTIVE
#include "INPFactory.h"
#include "INPManager.h"
#endif

#ifdef DIO_ACTIVE
#include "DIOFactory.h"
#endif


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/

APPLICATIONCREATEINSTANCE(UNITTESTS_APPFLOW, unittests)


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/


UNITTESTS_APPFLOW::UNITTESTS_APPFLOW()
{
  Clean();
}


UNITTESTS_APPFLOW::~UNITTESTS_APPFLOW()
{
  Clean();
}


bool UNITTESTS_APPFLOW::AppProc_Ini()
{
  GEN_SET_VERSION(APPLICATION_NAMEAPP, APPLICATION_NAMEFILE, APPLICATION_VERSION, APPLICATION_SUBVERSION, APPLICATION_SUBVERSIONERR, APPLICATION_OWNER, APPLICATION_YEAROFCREATION)

  XTRACE_SETAPPLICATIONNAME(APPLICATION_NAMEAPP);
  XTRACE_SETAPPLICATIONVERSION(APPLICATION_VERSION, APPLICATION_SUBVERSION, APPLICATION_SUBVERSIONERR);

  GEN_XPATHSMANAGER.AdjustRootPathDefault(APPLICATION_DIRECTORYMAIN);

  GEN_XPATHSMANAGER.CreateAllPathSectionOnDisk();

  XTRACE_ADDTARGET(XTRACE_TYPE_NET, GEN_XTRACE_NET_DEFAULT_01);
  XTRACE_ADDTARGET(XTRACE_TYPE_NET, __L("*:10001"));

  XTRACE_CLEARSCREEN;
  XTRACE_CLEARMSGSSTATUS;

  { XPATH xpathsection;
    XPATH xpath;
    GEN_XPATHSMANAGER.GetPathOfSection(XPATHSMANAGERSECTIONTYPE_ROOT, xpathsection);
    xpath.Create(3, xpathsection.Get(), APPLICATION_NAMEFILE, XTRANSLATION_NAMEFILEEXT);

    if(!GEN_XTRANSLATION.Ini(xpath))
      {
        return false;
      }

    GEN_XTRANSLATION.SetActual(XLANGUAGE_ISO_639_3_CODE_ENG);
  }

  return true;
}


bool UNITTESTS_APPFLOW::AppProc_FirstUpdate()
{
  return true;
}


bool UNITTESTS_APPFLOW::AppProc_Update()
{
  return false;
}


bool UNITTESTS_APPFLOW::AppProc_LastUpdate()
{
  return true;
}


bool UNITTESTS_APPFLOW::AppProc_End()
{
  #ifdef APPFLOW_ALERTS_ACTIVE
  if(APPFLOWALERTS::GetIsInstanced())
    {
      APPFLOWALERTS::GetInstance().End();
      APPFLOWALERTS::DelInstance();
    }
  #endif

  #ifdef APPFLOW_EXTENDED_ACTIVE
  if(APPFLOWEXTENDED::GetIsInstanced())
    {
      APPFLOWEXTENDED::GetInstance().APPEnd();
      APPFLOWEXTENDED::DelInstance();
    }
  #endif

  #ifdef APPFLOW_LOG_ACTIVE
  if(APPFLOWLOG::GetIsInstanced())
    {
      APPFLOWLOG::GetInstance().End();
      APPFLOWLOG::DelInstance();
    }
  #endif

  #ifdef INP_ACTIVE
  if(INPMANAGER::GetIsInstanced())
    {
      INPMANAGER::DelInstance();
    }
  INPFACTORY::DelInstance();
  #endif

  #ifdef GRP_ACTIVE
  GRPFACTORY::DelInstance();
  #endif

  #ifdef DIO_ACTIVE
  DIOFACTORY::DelInstance();
  #endif

  XTHREADLISTNONPREEMPTIVE::DelInstance();

  return true;
}


void UNITTESTS_APPFLOW::Clean()
{

}
