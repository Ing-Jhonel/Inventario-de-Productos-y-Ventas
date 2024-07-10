#include <iostream>
using namespace std;

struct Producto{
	string nombre;
	float precio;
};

struct Venta{
	int idVenta;
	string producto;
	int cantidad;
	float precioTotal;	
};

void mostrarProductos(Producto producto[], int n){
	for(int i=0; i<n; i++){
		cout << "		PRODUCTO " << i+1 << endl << endl
			 << "*Nombre: " << producto[i].nombre << endl
			 << "*Precio: $" << producto[i].precio << endl << endl;
	}
}

void buscarProducto(Producto producto[], int n, string name){
	
	int aux=0;
	for(int i=0; i<n; i++){
		if(producto[i].nombre==name){
			cout << "***PRODUCTO ENCONTRADO***" << endl
				 << "--------------------" << endl << endl
				 << "		PRODUCTO " << i+1 << endl << endl
				 << "Nombre: " << producto[i].nombre << endl
				 << "Precio: $" << producto[i].precio << endl;
			aux=1;
		} 
	}
	if(aux!=1){
		cout << "PRODUCTO NO ENCONTRADO.";
	}
}

void eliminarProducto(Producto producto[], int &n, int indice) {
    if (indice>=0 && indice<n) {
        for (int i=indice; i<n-1; i++) {
            producto[i]=producto[i+1];
        }
        n--;
    } else {
        cout << "Indice no vแlido" << endl;
    }
}

int main(){
	
	char opcion;
	int max=100;
	int n=0;
	Producto producto[max];
	string buscar;
	int numero;
	do{
		cout << "บบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบบ" << endl << endl;
		cout << "MENU PRINCIPAL" << endl << endl;
		cout 	<< "A) Registrar un nuevo producto." << endl
				<< "B) Listar los productos registrados." << endl
				<< "C) Buscar un producto por nombre." << endl
				<< "D) Actualizar los datos de un producto." << endl
				<< "E) Eliminar un producto." << endl
				<< "F) Registrar una venta." << endl
				<< "G) Listar las ventas realizadas." << endl
				<< "H) Calcular el total de ventas realizadas." << endl
				<< "S) Salir del programa."<< endl << endl;
		cout << "Elija una opcion: ";
		cin >> opcion;
		cout << endl;
		cout << "------------------------------------------------" << endl << endl;
		
		switch(opcion){
			case 'a':
				if(n<max){
					cout << "REGISTRANDO NUEVO PRODUCTO..." << endl << endl;
					cout << "Nombre: ";
					if(n>=0) cin.ignore();				
					getline(cin, producto[n].nombre);
					cout << "Precio: $";
					cin >> producto[n].precio;
					cout << endl
			 			 << "************** PRODUCTO REGISTRADO **************";
					n++;
					break;
				} else{
					cout << "Llego al limite, elimine y agregue otros productos.";
				}
				
				break;
				
			case 'b':
				if(n>0){
				 	cout << ">>>>>>>>>>>>> PRODUCTOS REGISTRADOS <<<<<<<<<<<<" << endl << endl;
					mostrarProductos(producto, n);
				} else {
					cout << "---> No hay productos disponibles <---";
				}
				
				break;
			
			case 'c':
				if(n>0){
					cout << "Buscar: ";
					cin >> buscar;
					cout << endl;
					buscarProducto(producto, n, buscar);
				} else {
					cout << "No hay productos disponibles.";
				}
				
				break;
				
			case 'd':
				if(n>=0){
					mostrarProductos(producto, n);
					cout << "-----------------------------" << endl
						 << "Indique el # del producto: ";
					cin >> numero;
					cout << "-----------------------------" << endl << endl;
					cout << "		PRODUCTO " << numero << ": " << endl << endl;
					cout << "Nombre: ";
					cin >> producto[numero-1].nombre;
					cout << "Precio: $";
					cin >> producto[numero-1].precio;
					cout << "***PRODUCTO ACTUALIZADO***";
				} else {
					cout << "No hay productos disponibles.";
				}
				break;
				
			case 'e':
				if (n > 0) {
                    mostrarProductos(producto, n);
                    cout << "Indique el # del producto: ";
                    cin >> numero;
                    eliminarProducto(producto, n, numero - 1);
                    cout << "***PRODUCTO ELIMINADO***";
                } else {
                    cout << "No hay contactos para eliminar." << endl;
                }
				break;
				
			case 'f':
				
				break;
				
			case 'g':
				
				break;
			
			case 'h':
				
				break;
		}
		cout << endl << endl;
	} while(opcion!='s');
 	return 0;
}
