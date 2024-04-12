#include <iostream>

using namespace std;

int main()
{
    double num1 = 98.34;
    double num2 = 10.23;

    char signo ='+';
    cout<<"INGRESE UNA OPERACION A REALIZAR: "<<endl;
    cin>> signo;

       switch(signo){
        case '+':
            cout<<"La suma es "<< num1 + num2<<endl;
            break;

        case '-':
            cout<<"La resta es "<< num1 - num2<<endl;
            break;
        case '*':
            cout<<"La multiplicacion es "<< num1 * num2<<endl;
            break;
        case '/':
            cout<<"La divicion es "<< num1 / num2<<endl;
            break;

        default:
            cout<<"valor incorrecto "<<endl;
        break;
    }

    return 0;
}
