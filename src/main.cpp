#include <iostream>
#include "Secuencia.h"

using namespace std;

int main(void){

    Secuencia sec1, sec2(100);

    cout << "Cap sec1: " << sec1.getCapacidad() << "\tCap sec2: " << sec2.getCapacidad() << endl;

    sec2.setValor(1,0);
    sec2.rellenaSec();
    sec2.muestraSec();
    sec2.setValor(70,0);
    sec2.muestraSec();

    cout << "sec2 es mayo sec1: " << sec2.esMayor(sec1) << endl;


    sec1.clonar(sec2);
    cout << "Son iguales: " << sec1.esIgual(sec2) << endl;
    sec1.muestraSec();

    sec2.aniade(777);
    sec2.muestraSec();
    cout << "Son iguales: " << sec1.esIgual(sec2) << endl;

    sec2.aniade(sec1);
    sec2.muestraSec();
    cout << "sec2 es mayo sec1: " << sec2.esMayor(sec1) << endl;

    Secuencia sec3;

    sec3=sec2;
    sec3.muestraSec();

    sec3= +sec2;
    sec3.muestraSec();

    sec3= -sec2;
    sec3.muestraSec();

    sec3[2] = 99;
    sec3.muestraSec();
    cout << sec3[2] << endl;

    sec1 = sec1+sec3;
    sec1.muestraSec();


    return 0;
}