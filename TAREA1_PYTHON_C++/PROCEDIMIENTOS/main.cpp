#include <iostream>

using namespace std;

void sumar(int numero1,int numero2){
    int resultado = numero1 + numero2;
    cout <<"El resultado de la sUma es: "<< resultado << endl;
}

void saludar(string nombre){
    cout << "Hola mi nombre es: " << nombre << endl;
}


int main()
{
    int numero1 = 40;
    int numero2 = 20;

    sumar(numero1,numero2);

    string nombre = "Fidel";
    saludar(nombre);

    return 0;
}

