#include "Poblacion.h"
#include <iostream>
#include <string.h>
using namespace std;

Poblacion::Poblacion(string miNombre,string miApellido,string miDistrito,string _sintoma,string _antecedente,int miEdad, string _estado)
{
    nombrePaciente=miNombre;
    apellidoPaciente=miApellido;
    distrito=miDistrito;
    sintoma=_sintoma;
    antecedente=_antecedente;
    edad=miEdad;
    estado=_estado;
}

void Poblacion::setNombre(string miNombre)
{
    nombrePaciente=miNombre;
}

void Poblacion::setApellido(string miApellido)
{
    apellidoPaciente=miApellido;
}

string Poblacion::getNombre()
{
    return nombrePaciente;
}

string Poblacion::getApellido()
{
    return apellidoPaciente;
}

string Poblacion::Registro()
{
    cout<<"°°°°Ingresa tu informacion°°°°"<<endl;
    cout<<"Ingresa el nombre del paciente: ";getline(cin,nombrePaciente);
    cout<<"Ingresa el apellido del paciente: ";getline(cin,apellidoPaciente);
    cout<<"Ingresa la edad del paciente: ";cin>>edad; cin.ignore();
    cout<<"Ingresa el distrito del paciente: ";getline(cin,distrito);
    setNombre(nombrePaciente);setApellido(apellidoPaciente);setEdad(edad);setDistrito(distrito);
}

string Poblacion::mostrarDatos()
{
    cout<<"DATOS DEL PACIENTE: \n";
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Apellido: "<<getApellido()<<endl;
    cout<<"Edad: "<<getEdad()<<endl;
    cout<<"Distrito: "<<getDistrito()<<endl;
}
string Poblacion::Sintomas()
{
    cout<<"Ingresa los sintomas que presenta el paciente: ";getline(cin,sintoma);
    setSintomas(sintoma);
    cout<<"Los sintomas que presenta el paciente son: "<<getSintomas()<<endl;
}

string Poblacion::AntecedentesMedicos()
{
    cout<<"Ingresa los antecedentes medicos del paciente: ";getline(cin,antecedente);
    setAntecedentes(antecedente);
    cout<<"Los antecedentes medicos del paciente son: "<<getAntecedente()<<endl;
}

void Poblacion::setSintomas(string _sintoma)
{
    sintoma=_sintoma;
}

void Poblacion::setEdad(int miEdad)
{
    edad=miEdad;
}

int Poblacion::getEdad()
{
    return edad;
}

void Poblacion::setDistrito(string miDistrito)
{
    distrito=miDistrito;
}

void Poblacion::setAntecedentes(string _antecedente)
{
    antecedente=_antecedente;
}

void Poblacion::setEstado(string _estado)
{
    estado=_estado;
}

string Poblacion::getDistrito()
{
    return distrito;
}

string Poblacion::getSintomas()
{
    return sintoma;
}

string Poblacion::getAntecedente()
{
    return antecedente;
}

string Poblacion::getEstado()
{
    return estado;
}
