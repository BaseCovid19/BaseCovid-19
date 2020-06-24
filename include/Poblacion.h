#ifndef POBLACION_H
#define POBLACION_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
using namespace std;


class Poblacion
{
   protected:
       string nombrePaciente;
       string apellidoPaciente;
       string distrito;
       string sintoma;
       string antecedente;
       int edad;
       string estado;
       bool encontrado;
       string nombre_aux,estado_aux;

   public:

       Poblacion();
       void setNombre(string miNombre);
       void setApellido(string miApellido);
       void setEdad(int miEdad);
       void setDistrito(string miDistrito);
       void setSintomas(string sintoma);
       void setAntecedentes(string antecedente);
       void setEstado(string _estado);
       string getNombre();
       string getApellido();
       int getEdad();
       string getDistrito();
       string getSintomas();
       string getAntecedente();
       string getEstado();
       string Sintomas();
       string AntecedentesMedicos();
       virtual string Registro();

       virtual void registro_Paciente();
       virtual void mostrar_Registro();
       virtual void estado_Paciente();// modifica el estado del paciente
       virtual void alta_Paciente();




};



#endif // POBLACION_H
