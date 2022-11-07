/*
Author: Karlo Antonio Ordaz de Vierna
Date: 5/11/2022
Description: Program for calculating entry price based on age.
*/

#include <iostream>
using namespace std;

int main(){
    int edad,precio;
    cout << " How old are you ? \n";      
    cin >> edad;

    if ((edad == 1 || edad <4))//If the kid has less then 3 years, free entry
    {
        precio = 0;
    }   
    else if (edad >= 4 && edad < 18)//If the kid has less than 18, $5
    {
        precio = 5;
    }
    else//If the client has more than 18, $10
    {
        precio = 10;
    }               
    cout << "Your entry price is: $" << precio << " thanks for visiting us!\n";
    return 0;
}