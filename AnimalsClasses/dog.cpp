#include "dog.h"

using namespace std;

Dog::Dog() {
   name = "None";
   breed = "None";
   p_age = new int; // Dynamic memory allocation
   *p_age = 0;
}

Dog::Dog(string name_param, string breed_param, int age_param) {
   name = name_param;
   breed = breed_param;
   p_age = new int; // Memory allocated on the heap
   *p_age = age_param;
   cout << "Dog constructor called for " << name << "at " << this << endl;
}

//Setters : 3 methodes présentées : avec pointer, par reference, classique
//Exemple avec Chained call using pointers, dans ce cas on met Dog*
/*
Exemple avec Chained call using pointers, dans ce cas on met Dog* :

Dog* Dog::SetDogName(string name)
{
    //On met son pointeur caché devant l'adresse qui référence le name de l'instance
    //pour éviter la confusion avec le name crée temporairement, de la méthod.
    this->name = name;
    return this;
}

Dog* Dog::SetDogBreed(string breed)
{
    this->breed = breed;
    return this;
}

Dog* Dog::SetDogAge(int age)
{
    //p_age est déjà un pointeur qui contient une adresse, on veut accéder à la valeur qu'il
    //contient pour y affecter age à la place, on ajoute etoile pour accéder à la valeur
    *(this->p_age) = age;
    return this;
}
//******************************************************************************************************
Exemple avec passage par ref, dans ce cas on met Dog&
//diff avec pointer : ref doit être alias d'une variable, ne peut pas être réasigné
Dog& Dog::SetDogName(string name)
{
    //On met son pointeur caché devant l'adresse qui référence le name de l'instance
    //pour éviter la confusion avec le name crée temporairement, de la méthod.
    this->name = name;
    return *this;
}

Dog& Dog::SetDogBreed(string breed)
{
    this->breed = breed;
    return *this;
}

Dog& Dog::SetDogAge(int age)
{
    //p_age est déjà un pointeur qui contient une adresse, on veut accéder à la valeur qu'il
    //contient pour y affecter age à la place, on ajoute etoile pour accéder à la valeur
    *(this->p_age) = age;
    return *this;
}
*/
void Dog::SetDogName(string name)
{
    //On met son pointeur caché devant l'adresse qui référence le name de l'instance
    //pour éviter la confusion avec le name crée temporairement, de la méthod.
    this->name = name;
}

void Dog::SetDogBreed(string breed)
{
    this->breed = breed;
}

void Dog::SetDogAge(int age)
{
    //p_age est déjà un pointeur qui contient une adresse, on veut accéder à la valeur qu'il
    //contient pour y affecter age à la place, on ajoute etoile pour accéder à la valeur
    *(this->p_age) = age;
}
//End setters

//Getters
string Dog::GetDogName()
{
    return name;
}

string Dog::GetDogBreed()
{
    return breed;
}

int Dog::GetDogAge()
{
    return *p_age;
}

//End getters
void Dog::PrintInfo()
{
    cout << "Dog (" << this << ") : Name of the dog : " << name << endl;
    cout << "Breed : " << breed << endl;
    cout << "Age of the dog : " << *p_age << endl;
}

Dog::~Dog()
  {
     delete p_age; // Release memory
     cout << "Dog destructor called for " << name << "at " << this << endl;
  }
