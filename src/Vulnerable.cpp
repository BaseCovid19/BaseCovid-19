#include "Vulnerable.h"
#include <iostream>
#include <string.h>
#include <fstream>
using namespace std;


Vulnerable::Vulnerable()
{
   centroMedico="";
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
    ofstream archivo;
    archivo.open("Pacientes_Vulnerables",ios::app|ios::out);
    if(archivo.fail()){cout<<"No pudo abrirse el archivo"; exit(1);}
    archivo<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<endl;
    archivo.close();
}

void Vulnerable::mostrar_Registro()
{
    ifstream leerfile;
    leerfile.open("Pacientes_Vulnerables",ios::in);
    if(leerfile.is_open())
    {
        cout<<"Registro de paciente"<<endl;
        leerfile>>nombrePaciente;
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente;
            leerfile>>edad;
            leerfile>>distrito;
            cout<<"Nombre: "<<nombrePaciente<<endl;
            cout<<"Apellido: "<<apellidoPaciente<<endl;
            cout<<"Edad: "<<edad<<endl;
            cout<<"Distrito: "<<distrito<<endl;
            leerfile>>nombrePaciente;
        }
        leerfile.close();
    }else{cout<<"El archivo no pudo abrirse\n";}

}






