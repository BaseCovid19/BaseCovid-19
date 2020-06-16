#include <iostream>
#include <string>
#include <vector>
#include "Poblacion.h"
#include "Vulnerable.h"
#include "NoVulnerable.h"
#include <stdlib.h>
#include <fstream>
using namespace std;

void imprimirLista()
{
    cout<<"1.Datos del paciente"<<endl;
    cout<<"2.Sintomas"<<endl;
    cout<<"3.Antecedentes"<<endl;
    cout<<"4.Personal medico"<<endl;
    cout<<"5.SALIR"<<endl;
}

void menu();

int main()
{
    menu();
    return 0;
}

void menu(){
    Poblacion paciente;
    Vulnerable vulnerable;
    NoVulnerable noVulnerable;
        int eleccion;
        string verificacion;
        do
        {
            imprimirLista();
            cin>>eleccion;
            cin.ignore();
            system("cls");
            if(eleccion==1)
            {
                cout<<"1.Mostrar pacientes registrados\n";
                cout<<"2.Resgistrar paciente\n";
                cin>>eleccion;
                cin.ignore();
                if(eleccion==1)
                {
                    vulnerable.mostrar_Registro();
                }
                if(eleccion==2){
                    cout<<"El paciente tiene mas de 60 anios?   SI/NO \n";
                    getline(cin,verificacion);
                    system("cls");
                    if(verificacion=="SI"||verificacion=="Si"||verificacion=="si")
                    {
                            vulnerable.Registro(); system("cls");
                            vulnerable.mostrarDatos();
                            vulnerable.registro_Paciente();
                            vulnerable.centroRecomendado();
                            menu();
                    }
                    else if(verificacion=="NO"||verificacion=="No"||verificacion=="no")
                    {
                        noVulnerable.Registro();
                        noVulnerable.mostrarDatos();
                    }
                }
            }
            else if(eleccion==2){paciente.Sintomas();}
            else if(eleccion==3){paciente.AntecedentesMedicos();}
            else if(eleccion==5){return;}
        }while(eleccion!=1||eleccion!=2||eleccion!=3||eleccion!=4);
    }
