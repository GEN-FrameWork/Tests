/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Script.cpp
*
* @class      UNITTESTS_SCRIPT
* @brief      Script unit tests application
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

#include "UnitTests_Script.h"

#ifdef GOOGLETEST_ACTIVE
#include "gtest/gtest.h"
#endif

#include "VersionFrameWork.h"

#include "XTranslation_GEN.h"
#include "XTranslation.h"

#include "XThreadListNonPreemptive.h"



/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"



/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/

APPLICATIONCREATEINSTANCE(UNITTESTS_SCRIPT, unittests)



/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/


/**-------------------------------------------------------------------------------------------------------------------
* 
* @fn         UNITTESTS_SCRIPT::UNITTESTS_SCRIPT()
* @brief      Constructor of class
* @ingroup    TESTS
* 
* --------------------------------------------------------------------------------------------------------------------*/
UNITTESTS_SCRIPT::UNITTESTS_SCRIPT()
{
  Clean();
}


/**-------------------------------------------------------------------------------------------------------------------
* 
* @fn         UNITTESTS_SCRIPT::~UNITTESTS_SCRIPT()
* @brief      Destructor of class
* @ingroup    TESTS
* 
* --------------------------------------------------------------------------------------------------------------------*/
UNITTESTS_SCRIPT::~UNITTESTS_SCRIPT()
{
  Clean();
}


/**-------------------------------------------------------------------------------------------------------------------
* 
* @fn         bool UNITTESTS_SCRIPT::AppProc_Ini()
* @brief      App Proc Ini
* @ingroup    TESTS
* 
* @return     bool : true if is succesful.
* 
* --------------------------------------------------------------------------------------------------------------------*/
bool UNITTESTS_SCRIPT::AppProc_Ini()
{
  GEN_SET_VERSION(APPLICATION_NAMEAPP, APPLICATION_NAMEFILE, APPLICATION_VERSION, APPLICATION_SUBVERSION, APPLICATION_SUBVERSIONERR, APPLICATION_OWNER, APPLICATION_YEAROFCREATION)

  XTRACE_SETAPPLICATIONNAME(APPLICATION_NAMEAPP);
  XTRACE_SETAPPLICATIONVERSION(APPLICATION_VERSION, APPLICATION_SUBVERSION, APPLICATION_SUBVERSIONERR);

  GEN_XPATHSMANAGER.AdjustRootPathDefault(APPLICATION_DIRECTORYMAIN);
  GEN_XPATHSMANAGER.AddPathSection(XPATHSMANAGERSECTIONTYPE_SCRIPTS, APPFLOW_DEFAULT_DIRECTORY_SCRIPTS);
  // Scraper scripts live under assets/scripts/scrapers; unit tests pass "scrapers/<file>"
  // so SCRAPERS root must be the scripts directory (not scripts/scrapers).
  GEN_XPATHSMANAGER.AddPathSection(XPATHSMANAGERSECTIONTYPE_SCRAPERS, APPFLOW_DEFAULT_DIRECTORY_SCRIPTS);
  GEN_XPATHSMANAGER.CreateAllPathSectionOnDisk();

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
* 
* @fn         bool UNITTESTS_SCRIPT::AppProc_FirstUpdate()
* @brief      App Proc First Update
* @ingroup    TESTS
* 
* @return     bool : true if is succesful.
* 
* --------------------------------------------------------------------------------------------------------------------*/
bool UNITTESTS_SCRIPT::AppProc_FirstUpdate()
{
  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
* 
* @fn         bool UNITTESTS_SCRIPT::AppProc_Update()
* @brief      App Proc Update
* @ingroup    TESTS
* 
* @return     bool : true if is succesful.
* 
* --------------------------------------------------------------------------------------------------------------------*/
bool UNITTESTS_SCRIPT::AppProc_Update()
{
  return false;
}


/**-------------------------------------------------------------------------------------------------------------------
* 
* @fn         bool UNITTESTS_SCRIPT::AppProc_LastUpdate()
* @brief      App Proc Last Update
* @ingroup    TESTS
* 
* @return     bool : true if is succesful.
* 
* --------------------------------------------------------------------------------------------------------------------*/
bool UNITTESTS_SCRIPT::AppProc_LastUpdate()
{
  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
* 
* @fn         bool UNITTESTS_SCRIPT::AppProc_End()
* @brief      App Proc End
* @ingroup    TESTS
* 
* @return     bool : true if is succesful.
* 
* --------------------------------------------------------------------------------------------------------------------*/
bool UNITTESTS_SCRIPT::AppProc_End()
{
  XTHREADLISTNONPREEMPTIVE::DelInstance();

  return true;
}


/**-------------------------------------------------------------------------------------------------------------------
* 
* @fn         void UNITTESTS_SCRIPT::Clean()
* @brief      Clean
* @ingroup    TESTS
* 
* --------------------------------------------------------------------------------------------------------------------*/
void UNITTESTS_SCRIPT::Clean()
{

}
