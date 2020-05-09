#include <iostream>
#include <string.h>

using namespace std;

struct Nodo{
	char nombre[100];
	int edad;
	bool ingresoIzq;
	Nodo *predecesor, *sucesor;
};

void insertar(Nodo **frenteIzq, Nodo **frenteDer);
void imprimirCola(Nodo **cabecera, char titulo[50]);

int main(int argc, char** argv) {
	Nodo *frenteIzq = NULL, *frenteDer = NULL;
	
	insertar(&frenteIzq, &frenteDer);
	return 0;
}


void insertar(Nodo **frenteIzq, Nodo **frenteDer){
	Nodo *nuevo;
	char resp, titulo[50];
	int cantidadPersonas = 1;
	
	do{		
		nuevo = new Nodo;
		
		if(nuevo){
			cout << endl << "Registro de persona numero " << cantidadPersonas;
			cout << endl << "Ingrese el nombre: ";
			cin >> nuevo->nombre;
			cout << "Ingrese la edad: ";
			cin >> nuevo->edad;
			
			nuevo->sucesor = nuevo->predecesor = NULL;
				
			if((*frenteIzq) == NULL && (*frenteDer) == NULL){ //cola vacia
				(*frenteDer) = (*frenteIzq) = nuevo;
				cout << "\t**Primer usuario registrado con exito";				
			}else{
				if(nuevo->edad > (*frenteIzq)->edad){ //ingresa por el lado izquierdo (primera posicion)
					nuevo->ingresoIzq = true;
					nuevo->sucesor = *frenteIzq;
					(*frenteIzq)->predecesor = nuevo;
					nuevo->predecesor = NULL;
					*frenteIzq = nuevo;
					cout << "\t**Usuario registrado con exito, edad mayor al resto de la cola -> ingresa al inicio de la cola";
				}else{ //ingresa por el lado derecho (ultima posicion)
					nuevo->ingresoIzq = false;
					nuevo->predecesor = *frenteDer;
					(*frenteDer)->sucesor = nuevo;
					nuevo->sucesor = NULL;
					*frenteDer = nuevo;
					cout << "\t**Usuario registrado con exito, edad menor al resto de la cola -> ingresa al final de la cola";
				}
			}
		}else{
			cout << "No hay Memoria";
		}
		cantidadPersonas++;
		cout << endl << endl << "Desea ingresar un nuevo valor en la lista? Y/N ";
		cin >> resp;
	}while(resp == 'y' || resp == 'Y');
	
	strcpy(titulo, "Cola ingresada");
	imprimirCola(frenteIzq, titulo);
}

void imprimirCola(Nodo **cabecera, char titulo[50]){
	Nodo *actual = *cabecera;
	
	cout << endl << endl << " ** "<< titulo <<" ** " << endl;
	while(actual->sucesor != NULL){
		cout << actual->nombre << ": " << actual->edad << " , ";
		actual = actual->sucesor;
		if(actual->sucesor == NULL){
				cout << actual->nombre << ": " << actual->edad << " , ";
		}
	}
}
