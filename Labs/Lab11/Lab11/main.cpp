#include "task1.h"
#include "mammal.h"
#include "dog.h"
#include "cat.h"
#include "horse.h"
#include "guineapig.h"

 int main ()
{
   Mammal* theArray[5];
   Mammal* ptr;
   int choice, i;
   for (i = 0; i<5; i++)
   {
      cout << "(1)dog (2)cat (3)horse (4)guinea pig: ";
      cin >> choice;
      switch (choice)
      {
         case 1: ptr = new Dog;
         break;
         case 2: ptr = new Cat;
         break;
         case 3: ptr = new Horse;
         break;
         case 4: ptr = new GuineaPig;
         break;
         default: ptr = new Mammal;
         break;
      }
      theArray[i] = ptr;
   }
   for (i=0;i<5;i++)
      theArray[i]->Speak();
   return 0;
}