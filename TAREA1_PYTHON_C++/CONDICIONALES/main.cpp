#include <iostream>

using namespace std;

int main()
{
    int numero1 = 12;
    int numero2 = 12;

    if(numero1 == numero2){
        cout << "Ambos son iguales" << endl;
    }else{
        if(numero2 > numero1){
            cout << "El numero mayor es: " << numero2 << endl;
        }else{
            cout << "El numero mayor es: " << numero1 << endl;
        }
    }

    return 0;
}
