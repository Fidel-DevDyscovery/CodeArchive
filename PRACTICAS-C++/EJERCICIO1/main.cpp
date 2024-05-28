#include <iostream>
#include <algorithm>

using namespace std;

const int estudiantes=5;
const int asignaturas=4;
//procedimiento prara calcular el promedio de las calificaciones de los estudiantes
void calcularpromedio(int calificaciones[][asignaturas]){
    for (int i=0; i<estudiantes; i++){
            int suma=0;

            for(int j=0; j<asignaturas; j++){
                suma = suma + calificaciones[i][j];
            }
            int promedio=suma/asignaturas;
            cout<<"El promedio del estudiante "<< i+1<<" es: "<<promedio<<endl;

    }

}

// procedimeinto para ordenar las calificaciones de los estudiantes de mayor a menor
void ordenar(int calificaciones[][asignaturas]){
    for (int i=0; i<estudiantes; i++){
        std::sort(calificaciones[i],calificaciones[i] + asignaturas, std::greater<int>());
    }
    cout<<"calificaiones ordenadas de los estudiantes"<<endl;
    for(int j=0; j<estudiantes; j++){
        for(int k=0; k<asignaturas; k++){
            cout<< calificaciones[j][k]<< ",";
        }
        cout<<endl;
    }
}

//funcion para encotrar la calificacion mas alta
int calificacionmasalta(int calificaciones[][asignaturas], int asignatura){
    int calificacionmaxima=calificaciones[0][asignatura];
    for(int i=0; i<estudiantes; i++){
        if(calificaciones[i][asignatura]>calificacionmaxima){
            calificacionmaxima=calificaciones[i][asignatura];
        }
    }
    return calificacionmaxima;
}


int main()
{
    int calificaciones[estudiantes][asignaturas]={{54, 90, 80, 100},
                                                  {56, 89, 45, 32},
                                                  {100, 43, 24, 34},
                                                  {32, 56, 34, 45},
                                                  {45, 86, 90, 99},
                                                 };

    calcularpromedio(calificaciones);
    ordenar(calificaciones);

    int asignatura;
    cout<<"INGRESE EL NUMERO DE ASIGNATURA PARA ENCONTRAR LA CALIFICACION MAS ALTA"<<endl;
    cin>>asignatura;
    if(asignatura>=0 && asignatura< asignaturas){
        int maximacalificacion=calificacionmasalta(calificaciones, asignatura);
        cout<<"La calificacion mas alta en la asignatura "<<asignatura<<" es "<<maximacalificacion<<endl;
    } else{
        cout<<"Numero de asignatura no valido! "<<endl;
    }

    return 0;
}
