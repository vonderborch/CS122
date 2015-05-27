#include "stdafx.h"
#include "pa7a.h"

// CIPHER BASE
Cipher::Cipher (bool setEncoded, string setText, string setCipherKey, string setBreakKey)
{
	this->isEncoded = setEncoded;
	this->mText = setText;
	this->cipherKey = setCipherKey;
	this->breakKey = setBreakKey;
}

void Cipher::setCipher (string setCipherKey)
{
	this->cipherKey = setCipherKey;
}

void Cipher::setBCipher (string setBCipherKey)
{
	this->breakKey = setBCipherKey;
}

void Cipher::setMText (string text)
{
   this->mText = text;
   for (int i = 0; i < (this->mText.length()); i++)
   {
      this->mText[i] = toupper(this->mText[i]);
   }
}

string Cipher::getMText ()
{
	return this->mText;
}
string Cipher::getBCipher ()
{
	return this->breakKey;
}

// CAESAR
Caesar::Caesar ()
{
	this->isEncoded = false;
	this->mText = "";
	this->cipherKey = "";
	this->breakKey = "";
}

bool Caesar::encode (void)
{
	bool hasEncoded = false;
	int tempKey = (atoi ((this->cipherKey).c_str()) % 26);
	if (this->isEncoded)
	{
		tempKey = -tempKey;
	}
	if (this->isEncoded != true)
	{
		this->isEncoded = true;

		for (int i = 0; i < (this->mText.length()); i++)
		{
			if (isalpha (this->mText[i]))
			{
				int letter = this->mText[i] + tempKey;
				mText[i] = letter <= 'Z' ? letter : letter - 26;
			}
		}

		hasEncoded = true;
	}
	return hasEncoded;
}

bool Caesar::decode (void)
{
	bool hasDecoded = false;
	int tempKey = (atoi ((this->cipherKey).c_str()) % 26);
	if (this->isEncoded)
	{
		tempKey = -tempKey;
	}
	if (this->isEncoded == true)
	{
		this->isEncoded = false;

		for (int i = 0; i < (this->mText.length()); i++)
		{
			if (isalpha (this->mText[i]))
			{
				int letter = this->mText[i] + tempKey;
				mText[i] = letter < 'A' ? letter + 26 : letter;
			}
		}

		hasDecoded = true;
	}
	return hasDecoded;
}

bool Caesar::breakCode (void)
{
	bool hasDecoded = false;
	if (this->breakKey == "")
	{
		this->breakKey = "1";
	}
	int tempKey = (atoi ((this->breakKey).c_str()) % 26);
	this->isEncoded = false;

	for (int i = 0; i < (this->mText.length()); i++)
	{
		if (isalpha (this->mText[i]))
		{
			int letter = this->mText[i] + tempKey;
			mText[i] = letter <= 'Z' ? letter : letter - 26;
		}
	}
	this->breakKey = "1";

	//itoa (tempKey, (this->breakKey).c_str(), 10);

	hasDecoded = true;
	return hasDecoded;
}

// SUBSTITUTION
Substitution::Substitution ()
{
	this->isEncoded = false;
	this->mText = "";
	this->cipherKey = "";
	this->breakKey = "";
}

bool Substitution::encode (void)
{
	bool hasDecoded = false;

	if (this->isEncoded != true)
	{
		for (int i = 0; i < (this->mText.length()); i++)
		{
			if (isalpha (this->mText[i]))
			{
				int letter = (this->mText[i]) - 65;
				mText[i] = this->cipherKey[letter];
			}
		}
		this->isEncoded = true;
		hasDecoded = true;
	}

	return hasDecoded;
}

bool Substitution::decode (void)
{
	bool hasDecoded = false;

	if (this->isEncoded == true)
	{
		for (int i = 0; i < (this->mText.length()); i++)
		{
			if (isalpha (this->mText[i]))
			{
				int letter = 0;
				for (int j = 0; j < 26; j++)
				{
					if (mText[i] == cipherKey[j])
					{
						letter = j;
					}
				}
				mText[i] = (char)(letter + 65);
			}
		}
		this->isEncoded = false;
		hasDecoded = true;
	}
	return hasDecoded;
}

bool Substitution::breakCode (void)
{
	bool hasDecoded = false;

	return hasDecoded;
}