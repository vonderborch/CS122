// .h part
#include <iostream>
 
using std::cin;
using std::cout;
using std::endl;
 
class Base
{
      public:
            virtual void testFunction ();
};
 
class Derived : public Base
{
      public:
            void testFunction ();
};

// .cpp part
 
void Base::testFunction ()
{
    cout << "Base class" << endl;
}
 
void Derived::testFunction ()
{
    cout << "Derived class" << endl;
}