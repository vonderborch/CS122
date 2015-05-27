#ifndef GPIG_H
#define GPIG_H

#include "mammal.h"

class GuineaPig:public Mammal
{
	public:
		GuineaPig (void);
        ~GuineaPig(void);

        void Move() const;
        void Speak() const;
	protected:
        int itsAge;
};

GuineaPig::GuineaPig():itsAge(1)
{
      cout << "Guinea Pig constructor..." << endl;
}
GuineaPig::~GuineaPig(void)
{
      cout << "Guinea Pig destructor..." << endl;
}
 
void GuineaPig::Move() const
{
      cout << "Guinea Pig moves a step!" << endl;
}
 
void GuineaPig::Speak() const
{
      cout << "What does a Guinea Pig speak? Weep!" << endl;
}

#endif