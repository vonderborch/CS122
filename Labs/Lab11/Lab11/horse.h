#ifndef HORSE_H
#define HORSE_H

#include "mammal.h"

class Horse:public Mammal
{
	public:
		Horse (void);
        ~Horse(void);

        void Move() const;
        void Speak() const;
	protected:
        int itsAge;
};

Horse::Horse():itsAge(1)
{
      cout << "Horse constructor..." << endl;
}
Horse::~Horse(void)
{
      cout << "Horse destructor..." << endl;
}
 
void Horse::Move() const
{
      cout << "Horse moves a step!" << endl;
}
 
void Horse::Speak() const
{
      cout << "What does a Horse speak? Neigh!" << endl;
}

#endif