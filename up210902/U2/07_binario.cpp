/*
Author: Karlo Antonio Ordaz de Vierna
Date: 5/11/2022
Description: Decimal to binary.
*/

#include <iostream>

using namespace std;

int main()
{
    int contador = 1;
    int numero = 0;
    string resultado;//Para que se imprima correctamente el binario
    cout << "Enter the number: ";
    cin >> numero;

    if (numero > 0)
    {
        while (numero != 0)
        {
            resultado = (numero % 2 == 0) ? "0" + resultado : "1" + resultado;
            numero /= 2;
        }
        cout << "The number in binary is " << resultado << endl;
    }
    else if (numero == 0)
    {
        cout << "The number in binary is 0 \n";
    }
    else
    {
        cout << "Invalid number \n";
    }
    return 0;
}