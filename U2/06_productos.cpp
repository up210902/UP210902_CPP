/*
Author: Karlo Antonio Ordaz de Vierna
Date: 5/11/2022
Description: Check sales.
*/

#include <iostream>
using namespace std;

int main()
{

    int precio = 0;
    int cantidad = 0;
    int montototal = 0;
    do
    {
        cout << "How many products did you sell\n";
        cin >> cantidad;
        if (cantidad > 0)
        {
            cout << "Price of each product individually\n";
            cin >> precio;
        }
        else
        {
            cout << "Invalid amount\n";
        }
        montototal += precio * cantidad;

    } while (cantidad != 0); // End loop if the amount is 0

    cout << "Congratulations, you earned : $" << montototal;

    return 0;
}