#include <iostream>
#include <string>
#include "dog.h"

using namespace std;

int main()
{
    Dog myDog("Medor","Labrador",2);

    myDog.PrintInfo();

    myDog.SetDogName("Pumba");
    myDog.SetDogBreed("Wire fox terrier");
    myDog.SetDogAge(4);


    //Chained call using pointers
    //myDog.SetDogName("Pumba")->SetDogBreed("Wire fox terrier")->SetDogAge(4);

    //Chained call using references
    //myDog.SetDogName("Pumba").SetDogBreed("Wire fox terrier").SetDogAge(4);

    myDog.PrintInfo();

    /* Le destruteur est appelé automatiquement :
    - When an object is passed by value to a function.
    - When a local object is returned from a function
    - When a local stack object goes out of scope (dies)
    - When a heap object is released with delete

    each class member function contain a hidden pointer called this. That pointer contains the
    address of the current object, for which  the method is being executed. This also applies
    to constructors and destructors.
    */
    return 0;
}
