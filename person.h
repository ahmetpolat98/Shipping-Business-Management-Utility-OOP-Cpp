#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class person{
    protected:
        string name, surname;

    public:
        person(string, string);
        //~person();
        void print(); //

};

person::person(string name, string surname)
    :name(name), surname(surname){}

void person::print(){
    cout << name << " " << surname;
}

#endif