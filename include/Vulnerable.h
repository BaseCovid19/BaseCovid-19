#ifndef VULNERABLE_H
#define VULNERABLE_H
#include "Poblacion.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;

class Vulnerable:public Poblacion
{
    private:
            string centroMedico;
            string direccionCentro;
            int telefonoCentro;
    public:
            Vulnerable();
            void imprimirOpciones();
            string centroRecomendado();
};

#endif // VULNERABLE_H
