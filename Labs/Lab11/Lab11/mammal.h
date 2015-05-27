#ifndef MAMMAL_H
#define MAMMAL_H
 
#include <iostream>
 
using std::cout;
using std::endl;
 
class Mammal
{
      public:
            Mammal(void);
            ~Mammal(void);
 
            virtual void Move() const;
            virtual void Speak() const;
 
      protected:
            int itsAge;
};

Mammal::Mammal(void):itsAge(1)
{
      cout << "Mammal constructor..." << endl;
}
 
Mammal::~Mammal(void)
{
      cout << "Mammal destructor..." << endl;
}
 
void Mammal::Move() const
{
      cout << "Mammal moves a step!" << endl;
}
 
void Mammal::Speak() const
{
      cout << "What does a mammal speak? Mammilian!" << endl;
}

#endif