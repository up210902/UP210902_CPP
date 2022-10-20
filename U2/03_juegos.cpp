/*

Escribir un programa para una empresa que tiene salas de juegos para todas las edades y
quiere calcular de forma automática el precio que debe cobrar a sus clientes por entrar. El
programa debe preguntar al usuario la edad del cliente y mostrar el precio de la entrada. Si
el cliente es menor de 4 años puede entrar gratis, si tiene entre 4 y 18 años debe pagar $5 y
si es mayor de 18 años, $10

*/


#include <iostream>
using namespace std;

int main(){
    int edad,PrecioEntrada;

    cout << " How old are you ? " << endl;      
    cin >> edad;

    if ((edad == 1 || edad <4))
    {
        cout << "You enter free congratulations !! " << endl;
    }   
    else if (edad >= 4 && edad < 18)
    {
        cout << "You have to pay $5 dollars " <<endl;
    }
    else
    {
        cout << "You have to pay $10 dollars " <<endl;
    }               

    return 0;
}