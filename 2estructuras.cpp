#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

struct Venta {
    int idVenta;
    string producto;
    int cantidad;
    float precioTotal;    
};

void mostrarProductos(Producto producto[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "        PRODUCTO " << i + 1 << endl << endl
             << "*Nombre: " << producto[i].nombre << endl
             << "*Precio: $" << producto[i].precio << endl << endl;
    }
}

void buscarProducto(Producto producto[], int n, string name) {
    int aux = 0;
    for (int i = 0; i < n; i++) {
        if (producto[i].nombre == name) {
            cout << "***PRODUCTO ENCONTRADO***" << endl
                 << "--------------------" << endl << endl
                 << "        PRODUCTO " << i + 1 << endl << endl
                 << "Nombre: " << producto[i].nombre << endl
                 << "Precio: $" << producto[i].precio << endl;
            aux = 1;
        }
    }
    if (aux != 1) {
        cout << "PRODUCTO NO ENCONTRADO.";
    }
}

void eliminarProducto(Producto producto[], int &n, int indice) {
    if (indice >= 0 && indice < n) {
        for (int i = indice; i < n - 1; i++) {
            producto[i] = producto[i + 1];
        }
        n--;
    } else {
        cout << "Indice no válido" << endl;
    }
}

int main() {
    srand(time(NULL));
    char opcion;
    const int max = 100;
    int n = 0;
    Producto producto[max];
    string buscar;
    int numero = 0;
    int minimo = 10000;
    const int maxVentas = 100; // Cambia este valor a algo razonable
    Venta venta[maxVentas];
    int m = 0;

    do {
        cout << "ººººººººººººººººººººººººººººººººººººººººººººººººº" << endl << endl;
        cout << "MENU PRINCIPAL" << endl << endl;
        cout << "A) Registrar un nuevo producto." << endl
             << "B) Listar los productos registrados." << endl
             << "C) Buscar un producto por nombre." << endl
             << "D) Actualizar los datos de un producto." << endl
             << "E) Eliminar un producto." << endl
             << "F) Registrar una venta." << endl
             << "G) Listar las ventas realizadas." << endl
             << "H) Calcular el total de ventas realizadas." << endl
             << "S) Salir del programa." << endl << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;
        cout << endl;
        cout << "------------------------------------------------" << endl << endl;

        switch (opcion) {
            case 'a':
                if (n < max) {
                    cout << "REGISTRANDO NUEVO PRODUCTO..." << endl << endl;
                    cout << "Nombre: ";
                    cin.ignore();
                    getline(cin, producto[n].nombre);
                    cout << "Precio: $";
                    cin >> producto[n].precio;
                    cout << endl << "************** PRODUCTO REGISTRADO **************" << endl;
                    n++;
                } else {
                    cout << "Llego al limite, elimine y agregue otros productos." << endl;
                }
                break;

            case 'b':
                if (n > 0) {
                    cout << ">>>>>>>>>>>>> PRODUCTOS REGISTRADOS <<<<<<<<<<<<" << endl << endl;
                    mostrarProductos(producto, n);
                } else {
                    cout << "---> No hay productos disponibles <---" << endl;
                }
                break;

            case 'c':
                if (n > 0) {
                    cout << "Buscar: ";
                    cin.ignore();
                    getline(cin, buscar);
                    cout << endl;
                    buscarProducto(producto, n, buscar);
                } else {
                    cout << "No hay productos disponibles." << endl;
                }
                break;

            case 'd':
                if (n > 0) {
                    mostrarProductos(producto, n);
                    cout << "-----------------------------" << endl
                         << "Indique el # del producto: ";
                    cin >> numero;
                    if (numero > 0 && numero <= n) {
                        cout << "-----------------------------" << endl << endl;
                        cout << "        PRODUCTO " << numero << ": " << endl << endl;
                        cout << "Nombre: ";
                        cin.ignore();
                        getline(cin, producto[numero - 1].nombre);
                        cout << "Precio: $";
                        cin >> producto[numero - 1].precio;
                        cout << "***PRODUCTO ACTUALIZADO***" << endl;
                    } else {
                        cout << "Número de producto no válido." << endl;
                    }
                } else {
                    cout << "No hay productos disponibles." << endl;
                }
                break;

            case 'e':
                if (n > 0) {
                    mostrarProductos(producto, n);
                    cout << "Indique el # del producto: ";
                    cin >> numero;
                    if (numero > 0 && numero <= n) {
                        eliminarProducto(producto, n, numero - 1);
                        cout << "***PRODUCTO ELIMINADO***" << endl;
                    } else {
                        cout << "Número de producto no válido." << endl;
                    }
                } else {
                    cout << "No hay productos para eliminar." << endl;
                }
                break;

            case 'f':
				if (n > 0) {
                    cout << "<<<<<<<<<<< REGISTRO DE VENTAS <<<<<<<<<<<<" << endl << endl;
                    mostrarProductos(producto, n);
                    cout << "Indique el producto a vender: ";
                    cin >> numero;
                    if (numero > 0 && numero <= n) {
                        cout << "Indique la cantidad: ";
                        cin >> venta[m].cantidad;
                        venta[m].idVenta = minimo + (rand() % (maxVentas - minimo + 1));
                        venta[m].producto = producto[numero - 1].nombre;
                        venta[m].precioTotal = (venta[m].cantidad) * (producto[numero - 1].precio);
                        cout << "************** FACTURA DE LA VENTA **************" << endl << endl;
                        cout << "ID: " << venta[m].idVenta << endl;
                        cout << "PRODUCTO: " << venta[m].producto << endl;
                        cout << "CANTIDAD: " << venta[m].cantidad << endl;
                        cout << "PRECIO TOTAL: $" << venta[m].precioTotal << endl << endl;
                        m++;
                    } else {
                        cout << "Número de producto no válido." << endl;
                    }
                } else {
                    cout << "No hay productos disponibles." << endl;
                }
                break;

            case 'g':

                break;

            case 'h':

                break;

            case 's':

                break;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
        cout << endl << endl;
    } while (opcion != 's');

    return 0;
}

