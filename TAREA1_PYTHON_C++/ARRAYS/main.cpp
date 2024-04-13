#include <iostream>

using namespace std;

int main()
{
// array ya lleno
    int nota[] = {23,45,76,34};

    cout << "Mi nota es: " << nota[2] << endl;
// array vacio

    int notas[10] = {};

    notas[2] = 30;

    cout << "Mi nota es: " << notas[2] << endl;


    return 0;
}
