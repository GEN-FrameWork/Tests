/**-------------------------------------------------------------------------------------------------------------------
*
* @file       UnitTests_Sound_Helper.cpp
*
* @class      UNITTESTS_SOUND_HELPER
* @brief      Shared helpers for Sound unit tests (not a gtest suite)
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

#include "UnitTests_Sound_Helper.h"

#include "XFactory.h"
#include "XFile.h"
#include "XPathsManager.h"
#include "XBuffer.h"


/*---- PRECOMPILATION INCLUDES ---------------------------------------------------------------------------------------*/

#include "GEN_Control.h"


/*---- GENERAL VARIABLE ----------------------------------------------------------------------------------------------*/


/*---- CLASS MEMBERS -------------------------------------------------------------------------------------------------*/

namespace UNITTESTS_SOUND_HELPER
{


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         static void AppendLE16(XBUFFER& buffer, XWORD value)
* @brief      Append a little-endian 16-bit value to buffer.
* @ingroup    UNIT TEST
*
* --------------------------------------------------------------------------------------------------------------------*/
static void AppendLE16(XBUFFER& buffer, XWORD value)
{
  XBYTE bytes[2];

  bytes[0] = (XBYTE)(value & 0xFF);
  bytes[1] = (XBYTE)((value >> 8) & 0xFF);

  buffer.Add(bytes, 2);
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         static void AppendLE32(XBUFFER& buffer, XDWORD value)
* @brief      Append a little-endian 32-bit value to buffer.
* @ingroup    UNIT TEST
*
* --------------------------------------------------------------------------------------------------------------------*/
static void AppendLE32(XBUFFER& buffer, XDWORD value)
{
  XBYTE bytes[4];

  bytes[0] = (XBYTE)(value & 0xFF);
  bytes[1] = (XBYTE)((value >> 8) & 0xFF);
  bytes[2] = (XBYTE)((value >> 16) & 0xFF);
  bytes[3] = (XBYTE)((value >> 24) & 0xFF);

  buffer.Add(bytes, 4);
}


/**-------------------------------------------------------------------------------------------------------------------
*
* @fn         bool WriteTinyPcmWav(XCHAR* xpath)
* @brief      Write a minimal valid mono 16-bit PCM WAV (44100 Hz, few samples) to xpath.
* @ingroup    UNIT TEST
*
* @param[in]  xpath : Destination file path.
*
* @return     bool : true if the operation is successful; otherwise false.
*
* --------------------------------------------------------------------------------------------------------------------*/
bool WriteTinyPcmWav(XCHAR* xpath)
{
  if(!xpath) return false;

  const XWORD  channels      = 1;
  const XDWORD samplerate    = 44100;
  const XWORD  bitspersample = 16;
  const XWORD  blockalign    = (XWORD)(channels * (bitspersample / 8));
  const XDWORD byterate      = samplerate * blockalign;
  const XDWORD nsamples      = 8;
  const XDWORD datasize      = nsamples * blockalign;
  const XDWORD fmtsize       = 16;
  const XDWORD riffsize      = 4 + (8 + fmtsize) + (8 + datasize);

  XBUFFER wav;

  wav.Add((XBYTE*)"RIFF", 4);
  AppendLE32(wav, riffsize);
  wav.Add((XBYTE*)"WAVE", 4);

  wav.Add((XBYTE*)"fmt ", 4);
  AppendLE32(wav, fmtsize);
  AppendLE16(wav, 1);              // PCM
  AppendLE16(wav, channels);
  AppendLE32(wav, samplerate);
  AppendLE32(wav, byterate);
  AppendLE16(wav, blockalign);
  AppendLE16(wav, bitspersample);

  wav.Add((XBYTE*)"data", 4);
  AppendLE32(wav, datasize);

  for(XDWORD c=0; c<nsamples; c++)
    {
      AppendLE16(wav, (XWORD)0);
    }

  XFILE* xfile = GEN_XFACTORY.Create_File();
  if(!xfile) return false;

  bool status = false;

  if(xfile->Create(xpath))
    {
      status = xfile->Write(wav.Get(), wav.GetSize());
      xfile->Close();
    }

  GEN_XFACTORY.Delete_File(xfile);

  return status;
}


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


}
