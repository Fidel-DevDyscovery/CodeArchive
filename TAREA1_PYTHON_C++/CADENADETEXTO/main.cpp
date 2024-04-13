#include <iostream>

using namespace std;

int main()
{
    string nombre = "Fidel Acarapi";
    string apellido = nombre.substr(6,7);
    nombre[6] = 'M';

    cout << "Mi nombre es: " << nombre << " mi apellido es: " << apellido<< endl;

    return 0;
}
