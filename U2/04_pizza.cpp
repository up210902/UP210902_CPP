/*
Author: Karlo Antonio Ordaz de Vierna
Date: 5/11/2022
Description: Program for pizza ingredient.
*/

#include <iostream>
using namespace std;
int main()
{
    int ingrediente = 0;
    int iniciaen = -1;// Se inicia en -1 para que cuando el usuario teclee 1, se seleccione en realidad la posicion 0
    int seleccion = 0; 
    string ingredienteextra[5] = {"Pepper", "Tofu", "Pepperoni", "Ham", "Salmon"}, tipopizza[2] = {"Vegetarian", "Meat"};
    char response; // Vegetariana o Carne
    cout << "-----Welcome to Bella Napoli Pizzeria!----\n\n-----All our pizzas have mozzarella and tomato-----\n";
    cout << "Do you want a Vegetarian pizza(V) or a carnivore pizza(C)? (V/C)\n";
    cin >> response;
    if (response == 'V' || response == 'C') // La respuesta es valida si o no
    {
        if (response == 'V') // Vegetarianas
        {
            do
            {
                cout << "Extra ingredient: \n 1. Pepper\n 2. Tofu\n"; // Dowhile hasta ingrediente correcto
                cin >> ingrediente;
            } while (ingrediente < 1 || ingrediente > 2);
        } else if (response == 'C') // Carnivoras
        {
            do
            {
                cout << "Extra ingredient: \n 1. Pepperoni\n 2. Ham\n 3. Salmon\n"; // Dowhile hasta ingrediente correcto
                cin >> ingrediente;
            } while (ingrediente < 1 || ingrediente > 3);
            iniciaen = 1;  // Lugar de ingredientes de carne
            seleccion = 1; // Mostrar que la pizza es de carne
        } 
        cout << "Your " << tipopizza[seleccion] << " pizza has the following ingredients:\n Mozarella \n Tomato\n ";
        cout << ingredienteextra[ingrediente + iniciaen] << endl; // Ingrediente extra
    }
    else
    {
        cout << "You've inputted an invalid response, try again\n";
    }
    return 0;
}
