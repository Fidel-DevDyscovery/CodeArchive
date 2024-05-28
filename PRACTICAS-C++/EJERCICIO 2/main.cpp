#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


struct producto {
    std::string codigo;
    std::string nombre;
    int cantidad;
};


void agregar_producto(std::vector<producto> &inventario, const std::string &codigo, const std::string &nombre, int cantidad) {
    inventario.push_back({codigo, nombre, cantidad});
}

void ordenar_inventario(std::vector<producto> &inventario) {
    std::sort(inventario.begin(), inventario.end(), [](const producto &a, const producto &b) {
        return a.nombre < b.nombre;
    });
}


int buscar_producto(const std::vector<producto> &inventario, const std::string &codigo) {
    for (size_t i = 0; i < inventario.size(); ++i) {
        if (inventario[i].codigo == codigo) {
            return i;
        }
    }
    return -1;
}


bool realizar_venta(std::vector<producto> &inventario, const std::string &codigo, int cantidad) {
    int indice = buscar_producto(inventario, codigo);
    if (indice != -1 && inventario[indice].cantidad >= cantidad) {
        inventario[indice].cantidad -= cantidad;
        return true;
    }
    return false;
}


bool recibir_stock(std::vector<producto> &inventario, const std::string &codigo, int cantidad) {
    int indice = buscar_producto(inventario, codigo);
    if (indice != -1) {
        inventario[indice].cantidad += cantidad;
        return true;
    }
    return false;
}


void mostrar_inventario(const std::vector<producto> &inventario) {
    std::cout << "Codigo\tNombre\tCantidad\n";
    for (const auto &prod : inventario) {
        std::cout << prod.codigo << "\t" << prod.nombre << "\t" << prod.cantidad << "\n";
    }
}

int main() {
    std::vector<producto> inventario;

    int opcion;
    do {
        std::cout << "1. Agregar producto\n2. Ordenar inventario\n3. Buscar producto\n4. Realizar venta\n5. Recibir stock\n6. Mostrar inventario\n7. Salir\n";
        std::cout << "Seleccione una opcion: ";
        std::cin >> opcion;

        if (opcion == 1) {
            std::string codigo, nombre;
            int cantidad;
            std::cout << "Ingrese el codigo del producto: ";
            std::cin >> codigo;
            std::cout << "Ingrese el nombre del producto: ";
            std::cin >> nombre;
            std::cout << "Ingrese la cantidad en stock: ";
            std::cin >> cantidad;
            agregar_producto(inventario, codigo, nombre, cantidad);
        } else if (opcion == 2) {
            ordenar_inventario(inventario);
            std::cout << "Inventario ordenado.\n";
        } else if (opcion == 3) {
            std::string codigo;
            std::cout << "Ingrese el codigo del producto a buscar: ";
            std::cin >> codigo;
            int indice = buscar_producto(inventario, codigo);
            if (indice != -1) {
                std::cout << "Producto encontrado: " << inventario[indice].nombre << " - Cantidad: " << inventario[indice].cantidad << "\n";
            } else {
                std::cout << "Producto no encontrado.\n";
            }
        } else if (opcion == 4) {
            std::string codigo;
            int cantidad;
            std::cout << "Ingrese el codigo del producto a vender: ";
            std::cin >> codigo;
            std::cout << "Ingrese la cantidad a vender: ";
            std::cin >> cantidad;
            if (realizar_venta(inventario, codigo, cantidad)) {
                std::cout << "Venta realizada con exito.\n";
            } else {
                std::cout << "Venta fallida. Verifique el codigo o la cantidad en stock.\n";
            }
        } else if (opcion == 5) {
            std::string codigo;
            int cantidad;
            std::cout << "Ingrese el codigo del producto a recibir: ";
            std::cin >> codigo;
            std::cout << "Ingrese la cantidad a recibir: ";
            std::cin >> cantidad;
            if (recibir_stock(inventario, codigo, cantidad)) {
                std::cout << "Stock actualizado con exito.\n";
            } else {
                std::cout << "Actualizacion fallida. Verifique el codigo del producto.\n";
            }
        } else if (opcion == 6) {
            mostrar_inventario(inventario);
        }
    } while (opcion != 7);

return 0;
}
