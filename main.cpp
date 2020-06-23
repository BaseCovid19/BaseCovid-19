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
void return_menu();
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
                cout<<"3.Actualizar estado de los pacientes\n";
                cin>>eleccion;
                cin.ignore();
                system("cls");
                if(eleccion==1)
                {
                    cout<<"1.Pacientes vulnerables\n";
                    cout<<"2.Pacientes no vulnerables\n";
                    cin>>eleccion;
                    cin.ignore();
                    system("cls");
                    if(eleccion==1){
                        vulnerable.mostrar_Registro();
                        return_menu();
                    }
                    else if(eleccion==2){
                        noVulnerable.mostrar_Registro();
                        return_menu();
                    }
                }
                else if(eleccion==2){
                    cout<<"El paciente tiene mas de 60 anios?   SI/NO \n";
                    getline(cin,verificacion);
                    system("cls");
                    if(verificacion=="SI"||verificacion=="Si"||verificacion=="si")
                    {
                            vulnerable.Registro();
                            if(vulnerable.getEdad()<60){
                                    cout<<"Edad incorrecta, vuelva a ingresar\n";
                                return_menu();
                            }
                            else{
                                vulnerable.registro_Paciente();
                                vulnerable.centroRecomendado();
                                return_menu();}

                    }
                    else if(verificacion=="NO"||verificacion=="No"||verificacion=="no")
                    {
                            noVulnerable.Registro();
                            if(noVulnerable.getEdad()>60){
                                cout<<"Edad incorrecta, vuelva a ingresar\n";
                                return_menu();
                            }
                            else{
                                noVulnerable.registro_Paciente();
                                return_menu();
                            }
                    }
                }
                else if(eleccion==3) // Actualizar el estado del paciente
                {
                    vulnerable.estado_Paciente();
                    return_menu();
                }
            }
            else if(eleccion==2){paciente.Sintomas();}
            else if(eleccion==3){paciente.AntecedentesMedicos();}
            else if(eleccion==5){return ;}
        }while(eleccion!=1||eleccion!=2||eleccion!=3||eleccion!=4);
    }

void return_menu()
{
    string volver;
    cout<<"\nPresiona v para volver al menu\n";getline(cin,volver);
    system("cls");
    if(volver=="v"){menu();}
}
