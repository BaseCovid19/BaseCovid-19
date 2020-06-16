#include "NoVulnerable.h"
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

NoVulnerable::NoVulnerable()
{
    familia="";
    ocupacion="";
    celular="";
}

void NoVulnerable::setFamilia(string _familia)
{
    familia=_familia;
}

void NoVulnerable::setOcupacion(string _ocupacion)
{
    ocupacion=_ocupacion;
}

void NoVulnerable::setCelular(string _celular)
{
    celular=_celular;
}

string NoVulnerable::getFamilia()
{
    return familia;
}

string NoVulnerable::getOcupacion()
{
    return ocupacion;
}

string NoVulnerable::getCelular()
{
    return celular;
}

string NoVulnerable::Registro()
{
    Poblacion::Registro();
    cout<<"Ingresa la ocupacion del paciente: ";getline(cin,ocupacion);
    cout<<"Ingresa el numero de celular: ";getline(cin,celular);
    cout<<"Ingresa el numero de familiares del paciente: ";getline(cin,familia);
    setFamilia(familia);setOcupacion(ocupacion);setCelular(celular);
}

string NoVulnerable::mostrarDatos()
{
    Poblacion::mostrarDatos();
    cout<<"Integrantes de la familia: "<<getFamilia()<<endl;
    cout<<"Ocupacion del paciente: "<<getOcupacion()<<endl;
    cout<<"Numero de telefono del paciente: "<<getCelular()<<endl;
    cout<<familia;
}





