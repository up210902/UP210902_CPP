/*
Author: Karlo Antonio Ordaz de Vierna
Date: 5/11/2022
Description: Find root in a graph using biseccion methor.
*/
#include <iomanip>//Para no imprimir tantas decimales
#include <iostream>
#include <cmath>
using namespace std;

float biseccion(float num){
    //Con la ecuacion y=x²-x-12
    return pow(num,2)-num-12;
}
void lineas(){//Funcion para imprimir lineas en la tabla de forma más facil
    for (int i = 0; i < 177; i++)
    {
        cout << "_";
    }
    cout << "\n";
}

int main(){
    int contador=1;
    float a,b,c,ya,yb,yc;
    cout << "FORMULA x²+x-12 \n";
    cout << "GIVE ME A";
    cin >> a;
    cout << "GIVE ME B";
    cin >> b;
    c = (a+b)/2;
    ya = biseccion(a);//Usar una fucnion float para calcular la biseccion en a,b,c
    yb = biseccion(b);
    yc = biseccion(c);
    if ((yb * ya < 0) || (ya * yc < 0) || (yc * yb < 0)){//Primero checar si hay raiz entre los numeros
    cout << "| Repetition # \t|\t A \t\t|\t B\t\t|\t C \t\t|\t f(A) \t\t\t|\t f(B) \t\t\t|\t f(C) \t\t| \n";//Encabezado
    lineas();
    cout << "| \t" << contador << "\t|\t" << fixed << setprecision(3) << a << "\t\t|\t" << b << "\t\t|\t" << c << "\t\t|\t" << ya << "\t\t\t|\t" << yb << "\t\t\t|\t" << yc << "\t\t|\n"; //First data before anything
    lineas();

        while (yc >= 0.01 || yc <= -0.01)
        {
            if ((yc > 0 && ya < 0) || (ya > 0 && yc < 0))//B ahora actua como C para que se vaya cortando a la mitad
            {
                b = c;
            }
            else
            {
                a = c;
            }
            if (a == b)//Si es igual que b salte del loop
            {
                break;
            }
            
            c = (a+b)/2;
            ya = biseccion(a);
            yb = biseccion(b);
            yc = biseccion(c);
            contador++;
            cout << "| \t" << contador << "\t|\t" << fixed << setprecision(3)/* Para no imprimir tantos decimales*/ << a << "\t\t|\t" << b << "\t\t|\t" << c << "\t\t|\t" << ya << "\t\t\t|\t" << yb << "\t\t\t|\t" << yc << "\t\t|\n";
            lineas();
        }
    cout << "The root is approximately " << setprecision(1) <<  c;
    }
    else //No hay raiz
    {
        cout << "There's no root between the numbers";
    }
    return 0;
}