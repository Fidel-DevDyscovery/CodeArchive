#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>


void ingresarDistancias(int distancias[][5], int numCiudades) {
    for (int i = 0; i < numCiudades; ++i) {
        for (int j = 0; j < numCiudades; ++j) {
            if (i == j) {
                distancias[i][j] = 0;
            } else {
                std::cout << "Ingrese la distancia de la ciudad " << i + 1 << " a la ciudad " << j + 1 << ": ";
                std::cin >> distancias[i][j];
            }
        }
    }
}


void ordenarCiudades(int distancias[][5], int numCiudades, std::vector<int> &orden) {
    std::vector<int> distanciasTotales(numCiudades, 0);

    for (int i = 0; i < numCiudades; ++i) {
        for (int j = 0; j < numCiudades; ++j) {
            distanciasTotales[i] += distancias[i][j];
        }
    }

    orden.resize(numCiudades);
    for (int i = 0; i < numCiudades; ++i) {
        orden[i] = i;
    }

    std::sort(orden.begin(), orden.end(), [&distanciasTotales](int a, int b) {
        return distanciasTotales[a] < distanciasTotales[b];
    });
}


int buscarDistanciaMinima(int distancias[][5], int ciudad1, int ciudad2) {
    return distancias[ciudad1][ciudad2];
}


void imprimirDatos(int distancias[][5], int numCiudades, const std::vector<int> &orden) {
    std::cout << "\nMatriz de distancias:\n";
    for (int i = 0; i < numCiudades; ++i) {
        for (int j = 0; j < numCiudades; ++j) {
            std::cout << std::setw(4) << distancias[i][j] << " ";
        }
        std::cout << "\n";
    }

    std::cout << "\nCiudades ordenadas por su distancia total a las demas:\n";
    for (int i = 0; i < numCiudades; ++i) {
        int totalDistancia = std::accumulate(distancias[orden[i]], distancias[orden[i]] + numCiudades, 0);
        std::cout << "Ciudad " << orden[i] + 1 << " (Distancia total: " << totalDistancia << ")\n";
    }
}

int main() {
    const int numCiudades = 5;
    int distancias[numCiudades][numCiudades];

    ingresarDistancias(distancias, numCiudades);

    std::vector<int> orden;
    ordenarCiudades(distancias, numCiudades, orden);

    imprimirDatos(distancias, numCiudades, orden);

    int ciudad1, ciudad2;
    std::cout << "Ingrese el numero de la primera ciudad en (1 a " << numCiudades << "): ";
    std::cin >> ciudad1;
    std::cout << "Ingrese el numero de la segunda ciudad en (1 a " << numCiudades << "): ";
    std::cin >> ciudad2;

    int distanciaMinima = buscarDistanciaMinima(distancias, ciudad1 - 1, ciudad2 - 1);
    std::cout << "La distancia minima entre la ciudad " << ciudad1 << " y la ciudad " << ciudad2 << " es: " << distanciaMinima << "\n";

return 0;
}
