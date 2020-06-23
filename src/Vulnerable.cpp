#include "Vulnerable.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;


Vulnerable::Vulnerable()
{
   centroMedico="";
   estado_aux="";
}


void Vulnerable::setCentroMedico(string centroM)
{
    centroMedico=centroM;
}

string Vulnerable::getCentroMedico()
{
    return centroMedico;
}

string Vulnerable::centroRecomendado()
{
    cout<<"\nEl paciente debe asistir al Hospital Goyeneche\n";
}

void Vulnerable::registro_Paciente()
{
    //Poblacion::Registro();
    ofstream archivo;
    archivo.open("Pacientes_Vulnerables",ios::app|ios::out);
    if(archivo.fail()){cout<<"No pudo abrirse el archivo"; exit(1);}
    archivo<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<estado<<endl;
    archivo.close();
}

void Vulnerable::mostrar_Registro()
{
    ifstream leerfile;
    leerfile.open("Pacientes_Vulnerables",ios::in);
    if(leerfile.is_open())
    {
        cout<<"Registro de pacientes"<<endl;
        leerfile>>nombrePaciente;
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente;
            leerfile>>edad;
            leerfile>>distrito;
            leerfile>>estado;
            cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
            cout<<"Estado del paciente: "<<getEstado()<<endl;
            cout<<"Nombre: "<<getNombre()<<endl;
            cout<<"Apellido: "<<getApellido()<<endl;
            cout<<"Edad: "<<getEdad()<<endl;
            cout<<"Distrito: "<<getDistrito()<<endl;
            leerfile>>nombrePaciente;
        }
        leerfile.close();
    }else{cout<<"El archivo no pudo abrirse\n";}

}


void Vulnerable::estado_Paciente()
{
    ofstream auxfile;
    ifstream leerfile;
    bool encontrado=false;
    string nombre_aux,estado_aux;
    auxfile.open("auxfile.txt",ios::app|ios::out);
    leerfile.open("Pacientes_Vulnerables",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        cout<<"Ingresa el nombre del paciente: ";cin>>nombre_aux;
        cin.ignore();
        leerfile>>nombrePaciente; // lectura adelantada
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>estado;
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
                cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cout<<"Ingresa el estado en el que se encuentra el paciente: ";getline(cin,estado_aux);
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<estado_aux<<endl;// Una vez leido el nuevo estado, se le asigna el estado al nuevo archivo aux
                cout<<"El estado del paciente ha cambiado"<<endl;
            }
            else{
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<estado<<endl;// Usar el archivo aux con la misma info
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
    remove("Pacientes_Vulnerables.txt");// se renombra el archivo aux con el original
    rename("auxfile.txt","Pacientes_Vulnerables.txt");
}






