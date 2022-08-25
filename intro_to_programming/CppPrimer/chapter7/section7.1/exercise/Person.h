#include <string>
#include <iostream>
#ifndef __PERSON_H
#define __PERSON_H

struct Person
{
    friend std::istream &
    read(std::istream &, Person &);

    friend std::ostream &
    print(std::ostream &, const Person &);

private:
    std::string name;
    std::string address;

public:
    Person() = default;
    Person(const std::string &name, const std::string address) : name(name), address{address} {}

    std::string getName() { return name; }
    std::string getAddress() const { return address; }
};

std::istream &
read(std::istream &, Person &);

std::ostream &
print(std::ostream &, const Person &);

#endif