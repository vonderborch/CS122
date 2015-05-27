//////////////////////////////////////////////////////////////////////
/// \class         Ceasar
/// \author        jackrh
/// \date          3/22/2007
/// \brief         Short description and purpose of this class
/// \invariant
///                -#  First class invariant
///                -#  Next class invariant, .....
/// REVISION HISTORY:
/// Date           Comment on what was changed.
///
////////////////////////////////////////////////////////////////////////

#include "Ceasar.h"// class implemented
// PUBLIC 

Ceasar::Ceasar()
{
   this->mMessage = " ";
   this->mEncoded = false;
   this->mShift   = 0;
}


void Ceasar::encode()
{
   if ( false == mEncoded )
   {
      mEncoded = true;
      for (unsigned i = 0; i < mMessage.length(); ++i)
      {
         if ( isalpha( mMessage[i]) )
         {
            unsigned letter  = mMessage[i] + mShift;
            mMessage[i] = letter <= 'Z' ? letter : letter - 26;  
            // 26 is the number of letters in the alphabit.
         }
      }
   }
}

void Ceasar::decode()
{
   if ( true == mEncoded )
   {
      mEncoded = false;
      for (unsigned i = 0; i < mMessage.length(); ++i)
      {
         if ( isalpha( mMessage[i]) )
         {
            unsigned letter  = mMessage[i] - mShift;
            mMessage[i] = letter < 'A' ? letter + 26 : letter;  
            // 26 is the number of letters in the alphabit.
         }
      }
   }
}

void Ceasar::setShift(unsigned shift)
{
   if ( 0 < shift && shift < 26 )
   {
       mShift = shift;
   }
   // we will eventually throw an exception here.  
}

void Ceasar::setMessage(string message)
{
   this->mMessage = message; 
   for (unsigned i = 0; i < mMessage.length(); ++i)
   {
      mMessage[i] = toupper(mMessage[i]);
   }
}


string Ceasar::getMessage()
{
   return this->mMessage;
}