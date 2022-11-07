/*
Author: Karlo Antonio Ordaz de Vierna
Date: 5/11/2022
Description: Program for calculating temperatura averages.
*/


#include <iostream>
using namespace std;

int main(){
    float temperatura, Temperaturaacumulada = 0;
    int contador = 1, temperaturaminima = 9999, temperaturamaxima = -9999;//Iniciamos la temepratura minima muy alta y la maxima muy baja para que el primer numero que meta el usuario tome el nuevo valor

    do
    {
        cout << "Whats the temperatura?\n";
        cin >> temperatura;
        Temperaturaacumulada +=temperatura;
        contador ++;
        if (temperatura <= temperaturaminima)//Checar si la temperatura ingresada es menor a la minima
        {
            temperaturaminima=temperatura;//Reemplazar
        }
        if (temperatura >= temperaturamaxima)//Checar si la temperatura ingresada es mayor a la maxima
        {
            temperaturamaxima=temperatura;//Reemplazar
        }
    } while (contador <=6);
    cout << "Average temperature: " << Temperaturaacumulada/6 <<"\n";
    cout << "Minium temperature: " << temperaturaminima<< "\n";
    cout << "Maxium temperature: " << temperaturamaxima << "\n";


    return 0;
}