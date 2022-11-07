/*
Author: Karlo Antonio Ordaz de Vierna
Date: 5/11/2022
Description: Program for extra payment for good employees.
*/
#include <iostream>
using namespace std;

int main(){
    double desempeno, dineroextra;

    cout << "How well has the employee behaved:\n";
    cin >> desempeno;
    dineroextra = desempeno*2400;//Cantidad inicial de dinero
    
    if (desempeno == 0.0)
    {
        cout << "An unacceptable performance\n"; 
        cout << "Your extra money is  " << dineroextra; 
    }
    else if ((desempeno >= 0.6) && (desempeno <=1))
    {
        cout << "A meritorous performance\n";  
        cout << "Your extra money is  " << dineroextra; 
    } else if (desempeno == 0.4){
        cout << "An acceptable performance\n";
        cout << "Your extra money is  " << dineroextra; 
    }else{
        cout << "Invalid performance, try again.";
    }
    return 0;
}