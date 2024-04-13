#include <iostream>

using namespace std;

int main()
{

    cout << "Introducir nota: " << endl;

    int nota;
    cin >> nota;
    cout << "Mi nota es: " << nota<< endl;
    cin.ignore();

    string nombre;
    cout << "Introducir nombre: " << endl;
    getline(cin,nombre);

    cout << "Mi nombre es: " << nombre << endl;

    return 0;
}
