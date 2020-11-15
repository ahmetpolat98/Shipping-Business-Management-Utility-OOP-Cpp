#include <iostream>
#include <string>

using namespace std;

#include "business.h"

void printMenu(string, string);

int main(){

    string name, address;
    int count_owner, menu_select = -1;

    cout << "Welcome to the business creation program. " << endl;
    cout << "What would you like your company name to be?(just a word): ";
    cin >> name;
    cout << "What would you like your company address to be?(just a word): ";
    cin >> address;
    cout << "How many owners does the company have?(must be greater than 0):";
    cin >> count_owner;

    business b1(name, address, count_owner);

    while (menu_select != 0)
    {
        printMenu(name, address);
        cin >> menu_select;

        switch (menu_select)
        {
        case 1:
            b1.hireCourier();
            break;

        case 2:
            b1.fireCourier();
            break;

        case 3:
            b1.listCourier();
            break;

        case 4:
            b1.listOwner();
            break;

        case 5:
            b1.calculateShipmentCapacity();
            break;

        case 0:
            break;

        default:
            cout << "invalid entry" << endl;
            break;
        }   

    }

    return 0;
}

void printMenu(string name, string address){
    cout << "--------------------------" << endl;
    cout << "---Welcome to " << name << "(" << address << ") company management page---" << endl;
    cout << "Please select what do you want to do: " << endl;
    cout << "1. Hire courier" << endl;
    cout << "2. Fire courier" << endl;
    cout << "3. List couriers" << endl;
    cout << "4. List owners" << endl;
    cout << "5. Calculate shipment capacity" << endl;
    cout << "0. Exit" << endl;
    cout << endl << "Enter: " ;
}