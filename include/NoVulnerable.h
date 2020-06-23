#ifndef NOVULNERABLE_H
#define NOVULNERABLE_H
#include "Poblacion.h"
#include <vector>
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
using namespace std;

class NoVulnerable:public Poblacion
{
    private:
        string familia;
        string ocupacion;
        string celular;
    public:
        NoVulnerable();
        void setFamilia(string);
        void setOcupacion(string);
        void setCelular(string);
        string getFamilia();
        string getOcupacion();
        string getCelular();
        string Registro();
        void registro_Paciente();
        void mostrar_Registro();
        void estado_Paciente();// modifica el estado del paciente
        void alta_Paciente();
};

#endif // NOVULNERABLE_H

