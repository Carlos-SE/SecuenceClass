#include <iostream>
#include "Secuencia.h"


using namespace std;

//CONSTRUCTORES Y DESTRUCTORES
Secuencia :: Secuencia(void){
    reservaMem();
}
Secuencia :: Secuencia(int la_capacidad){
	reservaMem(la_capacidad);
}
Secuencia :: ~Secuencia(void){
	eliminaMem();
}

//AJUSTAR SECUENCIA

void Secuencia :: reservaMem(void){
	sec = new int [capacidad];
}
void Secuencia :: reservaMem(int la_capacidad){

	capacidad = la_capacidad;
	reservaMem();
}
void Secuencia :: eliminaMem(void){
	totalUtilizados = 0;
	capacidad = 0;
	if(sec != 0){
		delete [] sec;
	}
}

void Secuencia :: setValor(int valor, int pos){
	sec[pos] = valor;
}

void Secuencia :: rellenaSec(void){
	int valor;
	totalUtilizados = 0;

	cout << "Introduzca los valores de la secuencia \
	hasta completar la memoria o hasta el primer número negativo:";
	cin >> valor;

	while(valor >= 0 && totalUtilizados < getCapacidad()){
		setValor(valor, totalUtilizados);
		totalUtilizados++;
		cin >> valor;
	}

}

void Secuencia :: clonar(const Secuencia & otro){
	reservaMem(otro.getCapacidad());
	totalUtilizados = 0;

	for(int i = 0; i < otro.getTotalUtilizados(); i++){
		setValor(otro.getValor(i),i);
		totalUtilizados++;
	}
}

void Secuencia :: aniade(int valor){
	int pos = getTotalUtilizados();

	if(pos < getCapacidad()){
		totalUtilizados++;
		setValor(valor, pos);
	}
}

void Secuencia :: aniade(const Secuencia & otro){
	int a_aniadir = otro.getTotalUtilizados();
	int contador = 0;
	int pos = getTotalUtilizados();

	for(int i = pos; i < getCapacidad() 
	&& contador < a_aniadir; i++){
		aniade(otro.getValor(contador));
		contador++;
	}
}

//OBTENER VALORES

void Secuencia :: muestraSec(void){
	for(int i = 0; i < getTotalUtilizados(); i++){
		cout << getValor(i) << " ";
	}
	cout << endl;
}


int & Secuencia :: getValor(int pos){
	return sec[pos];
}
int & Secuencia :: getValor(int pos) const{
	return sec[pos];
}

int Secuencia :: getCapacidad(void){
	return capacidad;
}
int Secuencia :: getCapacidad(void) const{
	return capacidad;
}

int Secuencia :: getTotalUtilizados(void){
	return totalUtilizados;
}
int Secuencia :: getTotalUtilizados(void)const{
	return totalUtilizados;
}

bool Secuencia :: esMayor(const Secuencia & otro){
	return(capacidad > otro.getCapacidad());
}

bool Secuencia :: esIgual(const Secuencia & otro){
	bool iguales = false;

	if(capacidad == otro.getCapacidad() && totalUtilizados == otro.getTotalUtilizados()){
		iguales = true;
	}

	for (int i = 0; i < totalUtilizados && iguales; i++){
		if(getValor(i) != otro.getValor(i)){
			iguales = false;
		}
	}

	return iguales;
}