#ifndef COURIER_H
#define COURIER_H

#include <iostream>
#include <string>
#include "person.h"

using namespace std;

class courier:public person{
    friend class business; //
    private:
        string vehicle;
        int capacity;
        courier *next;

    public:
        courier(string, string, string);
        //~courier();
        void print();
        bool isSame(courier);

};

courier::courier(string name, string surname, string vehicle)
    :person(name, surname){
        if(vehicle == "car"){
            this->vehicle = vehicle;
            this->capacity = 200;
        }
        else if(vehicle == "motorcycle"){
            this->vehicle = vehicle;
            this->capacity = 35;
        }
        else if(vehicle == "bicycle"){
            this->vehicle = vehicle;
            this->capacity = 10;
        }
        else
        {
            this->vehicle = "invalid name";
            this->capacity = 0;
        }
        next = NULL;
    }

void courier::print(){
    person::print();
    cout << " vehicle: " << vehicle << endl;
    //cout << "capacity: " << capacity << endl;
}

//this func could be operator overloading
bool courier::isSame(courier temp){
    if(this->name == temp.name && this->surname == temp.surname){
        return true;
    }
    else
    {
        return false;
    }
}


#endif