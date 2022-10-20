#include <iostream>
using namespace std;

int main(){
    double score;
    double performance;

    cout << "introduce your score"<< endl;
    cin >> score;
    performance = score*2400;
    

    //evaluar funciones para puntuacion 

    if (score == 0.0)
    {
        cout << "your performance are unacceptable" << endl; 
    }
    else if (((score==0.4)||(score >= 0.6))&&(score <=1))
    {
        if ((score >= 0.6) && (score <=1))
    {
        cout << "your performance are meritorious" << endl;  
    } else{
        cout << "your performance are acceptable" << endl;
        
    }
    }
    cout << "your performance (money) is to  " << performance; 
    return 0;
}