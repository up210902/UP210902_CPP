/*
Author: Karlo Antonio Ordaz de Vierna
Date: 5/11/2022
Description: Program for calculating the tax in a annual rent.
*/
#include <iostream>

using namespace std;
int main(){
    
    float PagoExtra, PagoInicial;
   
    cout << " What is your rent per year?\n ";
    cin >> PagoInicial;
    
    if (PagoInicial < 10000){
        PagoExtra =.05;
    }
    else if (PagoInicial >= 10000 & PagoInicial <20000 ){
        PagoExtra = .15;
    }
    else if (PagoInicial >= 20000 & PagoInicial <35000){
        PagoExtra = .20;
    }
    else if (PagoInicial >= 35000 & PagoInicial < 60000){
        PagoExtra = .30;
    }
    else if (PagoInicial >= 60000 ){
        PagoExtra = .45;
    }
    
    cout << "Your tax fee is : " << (PagoExtra*100) << "%" << endl << "The total amount of rent should be : " << (PagoInicial*PagoExtra) << endl;

    return 0;
}


