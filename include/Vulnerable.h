#ifndef VULNERABLE_H
#define VULNERABLE_H
#include "Poblacion.h"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class Vulnerable:public Poblacion
{
    private:
            string centroMedico;
    public:
            Vulnerable();
            void setCentroMedico(string);
            string getCentroMedico();
            string centroRecomendado();
            void registro_Paciente();
            void mostrar_Registro();
};

#endif // VULNERABLE_H
