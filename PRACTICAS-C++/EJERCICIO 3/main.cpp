#include <iostream>
#include <vector>


const int tamano_tablero = 10;


void inicializar_tablero(std::vector<std::vector<int>> &tablero) {
    tablero = std::vector<std::vector<int>>(tamano_tablero, std::vector<int>(tamano_tablero, 0));
}


bool colocar_ficha(std::vector<std::vector<int>> &tablero, int fila, int columna, int tipo_ficha) {
    if (fila < 0 || fila >= tamano_tablero || columna < 0 || columna >= tamano_tablero) {
        std::cout << "Posicion fuera de los limites del tablero.\n";
        return false;
    }
    if (tablero[fila][columna] != 0) {
        std::cout << "La posicion ya está ocupada.\n";
        return false;
    }
    tablero[fila][columna] = tipo_ficha;
    return true;
}


bool verificar_linea(const std::vector<std::vector<int>> &tablero, int tipo_ficha) {

    for (int fila = 0; fila < tamano_tablero; ++fila) {
        for (int col = 0; col <= tamano_tablero - 4; ++col) {
            if (tablero[fila][col] == tipo_ficha && tablero[fila][col+1] == tipo_ficha &&
                tablero[fila][col+2] == tipo_ficha && tablero[fila][col+3] == tipo_ficha) {
                return true;
            }
        }
    }


    for (int fila = 0; fila <= tamano_tablero - 4; ++fila) {
        for (int col = 0; col < tamano_tablero; ++col) {
            if (tablero[fila][col] == tipo_ficha && tablero[fila+1][col] == tipo_ficha &&
                tablero[fila+2][col] == tipo_ficha && tablero[fila+3][col] == tipo_ficha) {
                return true;
            }
        }
    }


    for (int fila = 0; fila <= tamano_tablero - 4; ++fila) {
        for (int col = 0; col <= tamano_tablero - 4; ++col) {
            if (tablero[fila][col] == tipo_ficha && tablero[fila+1][col+1] == tipo_ficha &&
                tablero[fila+2][col+2] == tipo_ficha && tablero[fila+3][col+3] == tipo_ficha) {
                return true;
            }
        }
    }


    for (int fila = 3; fila < tamano_tablero; ++fila) {
        for (int col = 0; col <= tamano_tablero - 4; ++col) {
            if (tablero[fila][col] == tipo_ficha && tablero[fila-1][col+1] == tipo_ficha &&
                tablero[fila-2][col+2] == tipo_ficha && tablero[fila-3][col+3] == tipo_ficha) {
                return true;
            }
        }
    }

    return false;
}


void imprimir_tablero(const std::vector<std::vector<int>> &tablero) {
    for (const auto &fila : tablero) {
        for (int celda : fila) {
            std::cout << celda << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> tablero;
    inicializar_tablero(tablero);

    int fila, columna, tipo_ficha;
    char continuar;
    do {
        imprimir_tablero(tablero);

        std::cout << "Ingrese la fila (0-9) donde desea colocar la ficha: ";
        std::cin >> fila;
        std::cout << "Ingrese la columna (0-9) donde desea colocar la ficha: ";
        std::cin >> columna;
        std::cout << "Ingrese el tipo de ficha (1 o 2): ";
        std::cin >> tipo_ficha;

        if (colocar_ficha(tablero, fila, columna, tipo_ficha)) {
            if (verificar_linea(tablero, tipo_ficha)) {
                imprimir_tablero(tablero);
                std::cout << "¡El jugador con la ficha " << tipo_ficha << " ha ganado!\n";
                break;
            }
        }

        std::cout << "¿Desea continuar? (s/n): ";
        std::cin >> continuar;
    } while (continuar == 's' || continuar == 'S');

return 0;
}
