#ifndef DOG_H
#define DOG_H

#include "mammal.h"

class Dog:public Mammal
{
	public:
		Dog (void);
        ~Dog(void);

        void Move() const;
        void Speak() const;
	protected:
        int itsAge;
};

Dog::Dog():itsAge(1)
{
      cout << "Dog constructor..." << endl;
}
Dog::~Dog(void)
{
      cout << "Dog destructor..." << endl;
}
 
void Dog::Move() const
{
      cout << "Dog moves a step!" << endl;
}
 
void Dog::Speak() const
{
      cout << "What does a Dog speak? Woof!" << endl;
}

#endif