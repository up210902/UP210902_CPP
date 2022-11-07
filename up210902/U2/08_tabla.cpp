/*
Author: Karlo Antonio Ordaz de Vierna
Date: 5/11/2022
Description: Products table.
*/

#include <iostream>
using namespace std;

int main()
{
    int multiplicador, numerodeveces;

    cout << "Number to multiply\n"; // Numero a multiplicar X * 1, X * 2,...
    cin >> multiplicador;

    cout << "How many times do you wish to multiply is\n";
    cin >> numerodeveces; // Cuantas veces multiplicar el numero

    for (int i = 1; i <= numerodeveces; i++)
    {

        for (int j = 0; j <= 41; j++)
        {
            cout << "-";
        }
        cout << "\t\n";

        cout << "| " << multiplicador << "\t X \t" << i << "\t = \t" << multiplicador * i << "\t |\n";//Tabla
    }
    return 0;
}