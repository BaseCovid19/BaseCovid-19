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
       vector<string> vecN;
       vector<string> vecA;
       int contadorPacientes;
       int contadorFallecidos;
       int contadorRecuperados;
       bool alta;
       bool muerto;
       bool recuperado;
       string medicoEncargado;

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
       void setMedico(string med);
       string getNombre();
       string getApellido();
       string getMedico();
       int getEdad();
       string getDistrito();
       string getSintomas();
       string getAntecedente();
       string getEstado();
       int getContador();
       int getContf();
       virtual string Registro();

       virtual void registro_Paciente();
       virtual void mostrar_Registro();
       virtual void estado_Paciente();// modifica el estado del paciente
       virtual void alta_Paciente();
       virtual void muerte_Paciente();

       virtual void orden_vector(int);
       virtual void buscar(int);
       void aumentar_contador();
       void crear_contador(); // Cuando pase algun error y se borre el archivo contador
       void reducir_contador();

       void crear_contf();
       void aumentar_contf();

       void crear_contr();
       void aumentar_contr();

       friend ostream& operator<<(ostream &output, const Poblacion &o);


};



#endif // POBLACION_H
