#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>


const int dias = 7;
const int mediciones_dia = 4;


std::vector<double> calcular_promedio_diario(const std::vector<std::vector<double>> &temperaturas) {
    std::vector<double> promedio_diario(dias, 0.0);

    for (int dia = 0; dia < dias; ++dia) {
        double suma = 0.0;
        for (int medicion = 0; medicion < mediciones_dia; ++medicion) {
            suma += temperaturas[dia][medicion];
        }
        promedio_diario[dia] = suma / mediciones_dia;
    }

    return promedio_diario;
}


void ordenar_temperaturas_diarias(std::vector<std::vector<double>> &temperaturas) {
    for (int dia = 0; dia < dias; ++dia) {
        std::sort(temperaturas[dia].begin(), temperaturas[dia].end());
    }
}


void buscar_dias_extremos(const std::vector<std::vector<double>> &temperaturas, int &dia_max, int &dia_min) {
    double temp_max = temperaturas[0][0];
    double temp_min = temperaturas[0][0];
    dia_max = 0;
    dia_min = 0;

    for (int dia = 0; dia < dias; ++dia) {
        for (int medicion = 0; medicion < mediciones_dia; ++medicion) {
            if (temperaturas[dia][medicion] > temp_max) {
                temp_max = temperaturas[dia][medicion];
                dia_max = dia;
            }
            if (temperaturas[dia][medicion] < temp_min) {
                temp_min = temperaturas[dia][medicion];
                dia_min = dia;
            }
        }
    }
}


void mostrar_resultados(const std::vector<std::vector<double>> &temperaturas) {
    auto promedio_diario = calcular_promedio_diario(temperaturas);
    int dia_max, dia_min;
    buscar_dias_extremos(temperaturas, dia_max, dia_min);

    std::cout << "Temperaturas promedio diarias:\n";
    for (int dia = 0; dia < dias; ++dia) {
        std::cout << "Dia " << dia + 1 << ": " << std::fixed << std::setprecision(2) << promedio_diario[dia] << "°C\n";
    }

    std::cout << "\nDia con la temperatura mas alta: Dia " << dia_max + 1 << "\n";
    std::cout << "Dia con la temperatura mas baja: Dia " << dia_min + 1 << "\n";
}

int main() {
    std::vector<std::vector<double>> temperaturas(dias, std::vector<double>(mediciones_dia));


    for (int dia = 0; dia < dias; ++dia) {
        std::cout << "Ingrese las temperaturas para el dia " << dia + 1 << " (manana, mediodia, tarde, noche):\n";
        for (int medicion = 0; medicion < mediciones_dia; ++medicion) {
            std::cin >> temperaturas[dia][medicion];
        }
    }

    ordenar_temperaturas_diarias(temperaturas);
    mostrar_resultados(temperaturas);

return 0;
}
