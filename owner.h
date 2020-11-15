#ifndef OWNER_H
#define OWNER_H

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class owner:public person{
    private:
        float ownership;

    public:
        owner(string, string, float);
        owner();
        //~owner();
        void print(); //
        void setNameSurname(string, string);
        void setOwnership(float);
    
};

owner::owner():person("name", "surname"){
    ownership = 100;
}

owner::owner(string name, string surname, float ownership)
    :person(name, surname), ownership(ownership){}

void owner::print(){
    person::print();
    cout << " ownership: " << ownership << endl;
}

void owner::setNameSurname(string name, string surname){
    this->name = name;
    this->surname = surname;
}

void owner::setOwnership(float x){
    this->ownership = x;
}

#endif