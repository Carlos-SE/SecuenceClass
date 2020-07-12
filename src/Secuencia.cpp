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
	sec = new TipoDato [capacidad];
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

void Secuencia :: setValor(TipoDato valor, int pos){
	sec[pos] = valor;
}

void Secuencia :: rellenaSec(void){
	TipoDato valor;
	totalUtilizados = 0;

	cout << "Introduzca los valores de la secuencia \
	hasta completar la memoria o hasta introducir un nº negativo:";
	cin >> valor;

	while(valor >= 0 && totalUtilizados < getCapacidad()){	//cambiar esto si TipoDato = char
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

void Secuencia :: aniade(TipoDato valor){
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


TipoDato & Secuencia :: getValor(int pos){
	return sec[pos];
}
TipoDato & Secuencia :: getValor(int pos) const{
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



//sobrecarga operadores

TipoDato & Secuencia :: operator [] (int pos){
	return(getValor(pos));
}


void Secuencia :: operator = (const Secuencia & otro){
	clonar(otro);
}


Secuencia & Secuencia :: operator + (void){
	return(*this);
}
Secuencia Secuencia :: operator + (const Secuencia & otro){
	Secuencia aux;
	aux = (*this);

	aux.aniade(otro);

	return aux;
}

Secuencia Secuencia :: operator - (void){
	Secuencia aux;
	aux = (*this);

	for(int i = 0; i < aux.getTotalUtilizados(); i++){
		aux.setValor((-1)*aux.getValor(i), i);
	}

	return aux;
}