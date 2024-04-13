#include <iostream>

using namespace std;

int sumar(int numero1,int numero2){
    int resultado = numero1 + numero2;
    return resultado;
}


int main()
{
    int numero1 = 50;
    int numero2 = 20;

    int suma;
    int suma2;
    int suma3;
    suma = sumar(numero1,numero2);
    suma2 = sumar(84,6);
    suma3 = sumar(numero1,10);

    cout << "La suma es: " << suma << endl;
    cout << "La suma es: " << suma2 << endl;
    cout << "La suma es: " << suma3 << endl;

    return 0;
}
