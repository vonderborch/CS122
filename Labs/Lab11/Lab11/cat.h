#ifndef CAT_H
#define CAT_H

#include "mammal.h"

class Cat:public Mammal
{
	public:
		Cat (void);
        ~Cat(void);

        void Move() const;
        void Speak() const;
	protected:
        int itsAge;
};

Cat::Cat():itsAge(1)
{
      cout << "Cat constructor..." << endl;
}
Cat::~Cat(void)
{
      cout << "Cat destructor..." << endl;
}
 
void Cat::Move() const
{
      cout << "Cat moves a step!" << endl;
}
 
void Cat::Speak() const
{
      cout << "What does a Cat speak? Meow!" << endl;
}

#endif