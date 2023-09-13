#ifndef DOG_H
#define DOG_H

#include <iostream>
#include <string>

class Dog
{
    public:
      Dog();
      Dog(std::string name_param, std::string breed_param, int age_param);
      ~Dog(); //Destructor déclaré

        //Setters
      /*
      Dog* SetDogName(std::string name);

      Dog* SetDogBreed(std::string breed);

      Dog* SetDogAge(int age);
      */
      void SetDogName(std::string name);

      void SetDogBreed(std::string breed);

      void SetDogAge(int age);


        //Getters
      std::string GetDogName();

      std::string GetDogBreed();

      int GetDogAge();


      void PrintInfo();

    private:
     std::string name;
     std::string breed;
     int *p_age{nullptr};
};
#endif

