#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person
{
      //Overload de << afin de pouvoir afficher un objet de la classe Person (une ref)
      friend std::ostream& operator<<(std::ostream& out, const Person& person);
    public:
      Person();
      Person(std::string& first_name_param, std::string& last_name_param);
      ~Person(); //Destructor déclaré

      //Getters
      std::string GetFirstName() const {
        return m_first_name;
      }

       std::string GetLastName() const {
        return m_last_name;
      }

      //Setters
       void SetFirstName(std::string fn){
         m_first_name = fn;
      }

       void SetLastName(std::string ln) {
         m_last_name = ln;
      }

    protected:
     std::string m_first_name{"Mysterious"};
     std::string m_last_name{"Person"};

};
#endif

