#ifndef BUSINESS_H
#define BUSINESS_H

#include <iostream>
#include <string>
#include "owner.h"
#include "courier.h"

using namespace std;

class business{
    private:
        string name, address;

        owner *owner_list;
        int count_owner;
        float ownership_rate;
        
        courier *courier_head;
        int count_courier;
        int total_shipment_capacity;

    public:
        business(string, string, int);
        //~business();
        void hireCourier();
        void fireCourier();
        void listCourier();
        void calculateShipmentCapacity();

        void listOwner();

        void print(); //
};

business::business(string name, string address, int howManyOwner)
    :name(name), address(address){
    courier_head = NULL;
    count_courier = 0;
    total_shipment_capacity = 0;

    count_owner = howManyOwner;
    ownership_rate = 100 / howManyOwner;

    owner_list = new owner[howManyOwner];
    string owner_name, owner_surname;
    
    for(int i = 0; i < howManyOwner; i++){
        cout << "Please enter " << i+1 << ". owner's name: ";
        cin >> owner_name;
        cout << "Please enter " << i+1 << ". owner's surname: ";
        cin >> owner_surname;

        owner_list[i].setNameSurname(owner_name, owner_surname);
        owner_list[i].setOwnership(ownership_rate);
    }
}

void business::print(){
    cout << name << address << endl;
}

void business::hireCourier(){

    string name, surname, vehicle;

    cout << "Please enter the courier's name:" << endl;
    cin >> name;
    cout << "Please enter the courier's surname:" << endl;
    cin >> surname;
    cout << "Please enter the courier's vehicle(car, motorcycle, bicycle):" << endl;
    cin >> vehicle;

    if (count_courier == 0)
    {
        courier_head = new courier(name, surname, vehicle);
        count_courier += 1;
    }
    else
    {
        courier *iter = courier_head;
        while (iter->next != NULL)
        {
            iter = iter->next;
        }
        iter->next = new courier(name, surname, vehicle);
        count_courier += 1;
    }
    cout << "Hire is successful" << endl;
}

void business::fireCourier(){

    string name, surname;
    bool checkExist = false;

    cout << "Who would you like to fire?" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "Surname: ";
    cin >> surname;

    courier delCourier(name, surname, "vehicle");

    courier *iter = courier_head;

    if (courier_head->isSame(delCourier))
    {
        courier *temp_head = courier_head;
        courier_head = courier_head->next;
        delete temp_head;
        checkExist = true;
    } 
    else{
        while (iter->next != NULL)
        {
            if (iter->next->isSame(delCourier))
            {
                courier *temp = iter->next;
                iter->next = iter->next->next;
                delete temp;
                checkExist = true;
            }
            else
            {
                iter = iter->next;
            }        
        }
    }
    if (!checkExist)
    {
        cout << "ERROR The courier you want to delete was not found." << endl;
    }
    else
    {
        count_courier -= 1;
    }   
}

void business::listCourier(){
    cout << "--------------------------" << endl;
    cout << "Total number of couriers: " << count_courier << endl;

    courier *iter = courier_head;

    int i = 1;

    while (iter != NULL)
    {
        cout << i << ". ";
        iter->print();
        iter = iter->next;
        i += 1;
    }   
}

void business::calculateShipmentCapacity(){

    courier *iter = courier_head;

    while (iter != NULL)
    {
        total_shipment_capacity += iter->capacity;
        iter = iter->next;
    }
    cout << "--------------------------" << endl;
    cout << "Total shipment capacity: " << total_shipment_capacity << endl;
}

void business::listOwner(){
    cout << "---------Owners:-----------" << endl;
    for (int i = 0; i < count_owner; i++)
    {
        cout << i+1 << ". ";
        owner_list[i].print();
    }
    
}

#endif