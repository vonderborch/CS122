#ifndef PA7A_H
#define PA7A_H

#include "stdafx.h"
#include <ctype.h>
#include <fstream>
#include <string>
#include <sstream>
#include <msclr\marshal_cppstd.h>

using namespace System;
using namespace msclr::interop;
using std::ctype;
using std::string;
using std::stringstream;
using std::endl;
using std::ifstream;
using std::ofstream;
using std::ios;

class Cipher
{
	public:
	Cipher (bool setEncoded = false, string setText = "", string setCipherKey = "", string setBreakKey = "");

		void setCipher (string setCipherKey);
		void setBCipher (string setBCipherKey);
		void setMText (string text);
		string getMText ();
		string getBCipher ();

	protected:
		bool isEncoded;
		string mText;
		string cipherKey;
		string breakKey;
};

class Caesar: public Cipher
{
	public:
		Caesar ();

		//bool dencode (void);
		bool encode (void);
		bool decode (void);
		bool breakCode (void);
};

class Substitution: public Cipher
{
	public:
		Substitution ();

		bool encode (void);
		bool decode (void);
		bool breakCode (void);
};

#endif