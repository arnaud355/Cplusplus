#include "person.h"

Person::Person()
{

}

Person::Person(std::string& first_name_param, std::string& last_name_param)
    : m_first_name(first_name_param), m_last_name(last_name_param)
{

}

std::ostream& operator<<(std::ostream& out, const Person& person){
    out << "Person [" << person.m_first_name << " " << person.m_last_name << "]";
    return out;
}

Person::~Person()
{

}
