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

int main(){
	
	char opcion;
	int max=100;
	int n=0;
	Producto producto[max];
	string buscar;
	do{
		cout << "*********************************************" << endl;
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
		cout << "--------------------------------------" << endl << endl;
		
		switch(opcion){
			case 'a':

				break;
				
			case 'b':

				break;
			
			case 'c':

				break;
				
			case 'd':
				
				break;
				
			case 'e':
				
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
