///////////////////////////////////////////////////////////////////////////////
//
//  Made by Carlos Salas
//  mail: csalaseiroa@correo.ugr.es or ca
//
//
///////////////////////////////////////////////////////////////////////////////
#ifndef SECUENCIA
#define SECUENCIA

typedef double TipoDato;	// Tipo de los elementos de la estructura dinámica

class Secuencia{
private:

    TipoDato *sec = 0;
    int capacidad = 0;
    int totalUtilizados = 0;

    void reservaMem(void);
    void reservaMem(int la_capacidad);
    void eliminaMem(void);

public:

//CONSTRUCTORES Y DESTRUCTORES
    Secuencia(void);
    Secuencia(int la_capacidad);
    ~Secuencia(void);


//AJUSTAR SECUENCIA

    void setValor(TipoDato valor, int pos);
    void rellenaSec(void);
    void clonar(const Secuencia & otro);
    void aniade(TipoDato valor);
    void aniade(const Secuencia & otro);
    

//OBTENER VALORES

    void muestraSec(void);
    TipoDato & getValor(int pos);
    TipoDato & getValor(int pos) const;
    int getCapacidad(void);
    int getCapacidad(void) const;
    int getTotalUtilizados(void);
    int getTotalUtilizados(void) const;

    bool esMayor(const Secuencia & otro); //Se basa unicamente en el tamaño
    bool esIgual(const Secuencia & otro); //Tienen que tener el mismo tam y números


//SOBRECARGA OPERADORES

    TipoDato & operator [] (int pos);

    void operator = (const Secuencia & otro);

    Secuencia & operator +(void);
    Secuencia operator +(const Secuencia & otro);   //apendiza, no suma valores
    Secuencia operator -(void);

};
#endif