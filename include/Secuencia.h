///////////////////////////////////////////////////////////////////////////////
//
//
//
//
//
///////////////////////////////////////////////////////////////////////////////
#ifndef SECUENCIA
#define SECUENCIA


class Secuencia{
private:

    int *sec = 0;
    int capacidad = 0;
    int totalUtilizados = 0;

public:

//CONSTRUCTORES Y DESTRUCTORES
    Secuencia(void);
    Secuencia(int la_capacidad);
    ~Secuencia(void);


//AJUSTAR SECUENCIA

    void reservaMem(void);
    void reservaMem(int la_capacidad);
    void eliminaMem(void);
    void setValor(int valor, int pos);
    void rellenaSec(void);
    void clonar(const Secuencia & otro);
    void aniade(int valor);
    void aniade(const Secuencia & otro);

//OBTENER VALORES

    void muestraSec(void);
    int & getValor(int pos);
    int & getValor(int pos) const;
    int getCapacidad(void);
    int getCapacidad(void) const;
    int getTotalUtilizados(void);
    int getTotalUtilizados(void) const;

    bool esMayor(const Secuencia & otro); //Se basa unicamente en el tamaño
    bool esIgual(const Secuencia & otro); //Tienen que tener el mismo tam y números

};
#endif