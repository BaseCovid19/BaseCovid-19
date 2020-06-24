#include "Poblacion.h"
#include <iostream>
#include <string.h>
using namespace std;

Poblacion::Poblacion()
{
    nombrePaciente="";
    apellidoPaciente="";
    distrito="";
    sintoma="";
    antecedente="";
    edad=0;
    estado="Infectado";
    encontrado=false;
    nombre_aux="";
    estado_aux="";
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
    cout<<"Ingresa los sintomas que presenta el paciente: ";getline(cin,sintoma);
    cout<<"Ingresa los antecedentes medicos del paciente: ";getline(cin,antecedente);
    setNombre(nombrePaciente);setApellido(apellidoPaciente);setEdad(edad);setDistrito(distrito);setSintomas(sintoma);setAntecedentes(antecedente);
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

/// Manipulacion de registros de la clase Vulnerable
void Poblacion::registro_Paciente()
{
    //Poblacion::Registro();
    ofstream archivo;
    archivo.open("Pacientes_Vulnerables",ios::app|ios::out);
    if(archivo.fail()){cout<<"No pudo abrirse el archivo"; exit(1);}
    archivo<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;
    archivo.close();
}

void Poblacion::mostrar_Registro()
{
    ifstream leerfile;
    leerfile.open("Pacientes_Vulnerables",ios::in);
    if(leerfile.is_open())
    {
        cout<<"Registro de pacientes"<<endl;
        leerfile>>nombrePaciente;
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>sintoma>>antecedente>>estado;
            cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
            cout<<"Estado del paciente: "<<getEstado()<<endl;
            cout<<"Nombre: "<<getNombre()<<endl;
            cout<<"Apellido: "<<getApellido()<<endl;
            cout<<"Edad: "<<getEdad()<<endl;
            cout<<"Distrito: "<<getDistrito()<<endl;
            cout<<"Sintomas: "<<getSintomas()<<endl;
            cout<<"Antecedentes: "<<getAntecedente()<<endl;
            leerfile>>nombrePaciente;
        }
        leerfile.close();
    }else{cout<<"El archivo no pudo abrirse\n";}

}


void Poblacion::estado_Paciente()
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Pacientes_Vulnerables",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        cout<<"Ingresa el nombre del paciente: ";cin>>nombre_aux;
        cin.ignore();
        leerfile>>nombrePaciente; // lectura adelantada
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>sintoma>>antecedente>>estado;
            if(nombre_aux==nombrePaciente)
            {
                encontrado=true;
                cout<<"Datos del paciente: "<<endl;
                cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cout<<"Estado del paciente: "<<getEstado()<<endl;
                cout<<"Nombre: "<<getNombre()<<endl;
                cout<<"Apellido: "<<getApellido()<<endl;
                cout<<"Edad: "<<getEdad()<<endl;
                cout<<"Distrito: "<<getDistrito()<<endl;
                cout<<"Sintomas: "<<getSintomas()<<endl;
                cout<<"Antecedentes: "<<getAntecedente()<<endl;
                cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cout<<"Ingresa el estado en el que se encuentra el paciente: ";getline(cin,estado_aux);
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<sintoma<<" "<<antecedente<<" "<<estado_aux<<endl;// Una vez leido el nuevo estado, se le asigna el estado al nuevo archivo aux
                cout<<"El estado del paciente ha cambiado"<<endl;
            }
            else{
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;// Usar el archivo aux con la misma info
            }
            leerfile>>nombrePaciente;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}

    if(encontrado==false)
    {
        cout<<"No tenemos pacientes registrados con el nombre ingresado\n";
    }
    auxfile.close();
    leerfile.close();
    remove("Pacientes_Vulnerables");
    rename("Auxfile","Pacientes_Vulnerables");
    alta_Paciente();
}

void Poblacion::alta_Paciente()
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Pacientes_Vulnerables",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        leerfile>>nombrePaciente; // lectura adelantada
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>sintoma>>antecedente>>estado;
            if(estado=="Recuperado")
            {
                encontrado=true;
                cout<<"El paciente fue dado de alta"<<endl;
            }
            else{
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;// Usar el archivo aux con la misma info
            }
            leerfile>>nombrePaciente;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}
    auxfile.close();
    leerfile.close();
    remove("Pacientes_Vulnerables");
    rename("Auxfile","Pacientes_Vulnerables");
}

