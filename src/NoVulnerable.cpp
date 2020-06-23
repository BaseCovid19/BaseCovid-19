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


void NoVulnerable::registro_Paciente()
{
    ofstream archivo;
    archivo.open("Pacientes_NoVulnerables",ios::app|ios::out);
    if(archivo.fail()){cout<<"No pudo abrirse el archivo"; exit(1);}
    archivo<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<familia<<" "<<ocupacion<<" "<<celular<<" "<<estado<<endl;
    archivo.close();
}

void NoVulnerable::mostrar_Registro()
{
    ifstream leerfile;
    leerfile.open("Pacientes_NoVulnerables",ios::in);
    if(leerfile.is_open())
    {
        cout<<"Registro de pacientes"<<endl;
        leerfile>>nombrePaciente;
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente;
            leerfile>>edad;
            leerfile>>distrito;
            leerfile>>familia;
            leerfile>>ocupacion;
            leerfile>>celular;
            leerfile>>estado;
            cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
            cout<<"Estado del paciente: "<<getEstado()<<endl;
            cout<<"Nombre: "<<getNombre()<<endl;
            cout<<"Apellido: "<<getApellido()<<endl;
            cout<<"Edad: "<<getEdad()<<endl;
            cout<<"Distrito: "<<getDistrito()<<endl;
            cout<<"Integrantes en la familia: "<<getFamilia()<<endl;
            cout<<"Ocupacion: "<<getOcupacion()<<endl;
            cout<<"Numero de celular: "<<getCelular()<<endl;
            leerfile>>nombrePaciente;
        }
        leerfile.close();
    }else{cout<<"El archivo no pudo abrirse\n";}

}






