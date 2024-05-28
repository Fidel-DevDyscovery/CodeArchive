#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

const int NUM_ESTUDIANTES = 5;
const int NUM_MATERIAS = 3;


void inicializarNotas(int notas[NUM_ESTUDIANTES][NUM_MATERIAS]) {
    srand(time(0));

    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        for (int j = 0; j < NUM_MATERIAS; ++j) {
            notas[i][j] = rand() % 101;
        }
    }
}


void calcularPromedios(int notas[NUM_ESTUDIANTES][NUM_MATERIAS], double promedios[NUM_ESTUDIANTES]) {
    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        int suma = 0;
        for (int j = 0; j < NUM_MATERIAS; ++j) {
            suma += notas[i][j];
        }
        promedios[i] = static_cast<double>(suma) / NUM_MATERIAS;
    }
}


void ordenarNotas(int notas[NUM_ESTUDIANTES][NUM_MATERIAS]) {
    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        for (int j = 0; j < NUM_MATERIAS - 1; ++j) {
            for (int k = 0; k < NUM_MATERIAS - j - 1; ++k) {
                if (notas[i][k] < notas[i][k + 1]) {
                    std::swap(notas[i][k], notas[i][k + 1]);
                }
            }
        }
    }
}


void buscarNotas(int notas[NUM_ESTUDIANTES][NUM_MATERIAS], int materia, int &notaMaxima, int &notaMinima) {
    notaMaxima = notas[0][materia];
    notaMinima = notas[0][materia];

    for (int i = 1; i < NUM_ESTUDIANTES; ++i) {
        if (notas[i][materia] > notaMaxima) {
            notaMaxima = notas[i][materia];
        }
        if (notas[i][materia] < notaMinima) {
            notaMinima = notas[i][materia];
        }
    }
}

void visualizarDatos(int notas[NUM_ESTUDIANTES][NUM_MATERIAS], double promedios[NUM_ESTUDIANTES], int materia) {
    std::cout << "Notas de los estudiantes:\n";
    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        std::cout << "Estudiante " << i + 1 << ": ";
        for (int j = 0; j < NUM_MATERIAS; ++j) {
            std::cout << std::setw(4) << notas[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nPromedios de los estudiantes:\n";
    for (int i = 0; i < NUM_ESTUDIANTES; ++i) {
        std::cout << "Estudiante " << i + 1 << ": " << std::fixed << std::setprecision(2) << promedios[i] << "\n";
    }

    int notaMaxima, notaMinima;
    buscarNotas(notas, materia, notaMaxima, notaMinima);

    std::cout << "\nNotas de la materia " << materia + 1 << ":\n";
    std::cout << "Nota mas alta: " << notaMaxima << "\n";
    std::cout << "Nota mas baja: " << notaMinima << "\n";
}

int main() {
    int notas[NUM_ESTUDIANTES][NUM_MATERIAS];
    double promedios[NUM_ESTUDIANTES];

    inicializarNotas(notas);
    calcularPromedios(notas, promedios);
    ordenarNotas(notas);

    int materia;
    std::cout << "Ingrese el numero de la materia (0 a 2): ";
    std::cin >> materia;

    visualizarDatos(notas, promedios, materia);

return 0;
}
