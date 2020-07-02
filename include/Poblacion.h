#ifndef POBLACION_H
#define POBLACION_H
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <algorithm>
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
       vector<string> vec;
       int contadorPacientes;
       int contadorFallecidos;
       int contadorRecuperados;
       bool alta;
       bool muerto;
       bool recuperado;

   public:

       Poblacion();
       void setNombre(string miNombre);
       void setApellido(string miApellido);
       void setEdad(int miEdad);
       void setDistrito(string miDistrito);
       void setSintomas(string sintoma);
       void setAntecedentes(string antecedente);
       void setEstado(string _estado);
       void setContador(int cont);
       void setContf(int contf);
       string getNombre();
       string getApellido();
       int getEdad();
       string getDistrito();
       string getSintomas();
       string getAntecedente();
       string getEstado();
       int getContador();
       int getContf();
       string Sintomas();
       string AntecedentesMedicos();
       virtual string Registro();

       virtual void registro_Paciente();
       virtual void mostrar_Registro();
       virtual void estado_Paciente();// modifica el estado del paciente
       virtual void alta_Paciente();
       virtual void muerte_Paciente();

       void vector_nombres();
       void aumentar_contador();
       void crear_contador(); // Cuando pase algun error y se borre el archivo contador
       void reducir_contador();

       void crear_contf();
       void aumentar_contf();

       void crear_contr();
       void aumentar_contr();



};



#endif // POBLACION_H
