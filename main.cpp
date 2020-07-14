#include <iostream>
#include <string>
#include <vector>
#include "Poblacion.h"
#include "Vulnerable.h"
#include "NoVulnerable.h"
#include "Disponibilidad.h"
#include <stdlib.h>
#include <fstream>
using namespace std;

bool acceder(string a="",string b=""){
    string usuario="MINSA",contrasenia="123456";
    cout << "Ingrese su nombre de usuario: " << endl;cin>>a;cin.ignore();
    cout << "Ingrese su contrasena: " << endl;cin>>b;cin.ignore();
    system("cls");
    return (a==usuario&&b==contrasenia);
}

void imprimirLista()
{
    cout<<"1.Datos del paciente"<<endl;
    cout<<"2.Personal medico"<<endl;
    cout<<"3.SALIR"<<endl;
}

void menu();
void return_menu();
Poblacion medico;
string med;
int main()
{
    if(acceder())
    {
    cout<<"Nombre del medico: ";
    getline(cin,med);
    medico.setMedico(med);
    system("cls");
    menu();

    }
    return 0;

}

void menu(){
    Poblacion paciente;
    Vulnerable vulnerable;
    NoVulnerable noVulnerable;
    Disponibilidad personal;
    int eleccion;
    string verificacion;
    cout<<medico<<endl;
    imprimirLista();
    cin>>eleccion;
    cin.ignore();
    system("cls");
    switch (eleccion){
        case 1:{
            cout<<"1.Mostrar pacientes registrados\n";
            cout<<"2.Registrar paciente\n";
            cout<<"3.Actualizar estado de los pacientes\n";
            int eleccion1;
            cin>>eleccion1;
            cin.ignore();
            system("cls");
            switch (eleccion1){
                case 1:{
                    cout<<"1.Pacientes vulnerables\n";
                    cout<<"2.Pacientes no vulnerables\n";
                    cout<<"3.Vector de pacientes\n";
                    cout<<"4.Busqueda de pacientes\n";
                    int eleccion2;
                    cin>>eleccion2;
                    cin.ignore();
                    system("cls");
                    switch (eleccion2){
                        case 1:{
                            vulnerable.mostrar_Registro();
                            return_menu();
                        }
                        case 2:{
                            noVulnerable.mostrar_Registro();
                            return_menu();
                        }
                        case 3:{// VECTOR DE NOMBRES Y APELLIDOS
                            cout<<"1. Pacientes vulnerables\n";
                            cout<<"2. Pacientes no vulnerables\n";
                            int eleccion3;
                            cin>>eleccion3;
                            cin.ignore();
                            system("cls");
                            switch (eleccion3){
                                case 1:{
                                    cout<<"1. Ordenar por nombre\n";
                                    cout<<"2. Ordenar por apellido\n";
                                    int eleccion4;
                                    cin>>eleccion4;
                                    cin.ignore();
                                    system("cls");
                                    vulnerable.orden_vector(eleccion4);
                                    return_menu();
                                }
                                case 2:{
                                    cout<<"1. Ordenar por nombre\n";
                                    cout<<"2. Ordenar por apellido\n";
                                    int eleccion5;
                                    cin>>eleccion5;
                                    cin.ignore();
                                    system("cls");
                                    noVulnerable.orden_vector(eleccion5);
                                    return_menu();
                                }
                            }
                        }
                        case 4:{// VECTOR DE NOMBRES Y APELLIDOS
                            cout<<"1. Pacientes vulnerables\n";
                            cout<<"2. Pacientes no vulnerables\n";
                            int eleccion7;
                            cin>>eleccion7;
                            cin.ignore();
                            system("cls");
                            switch (eleccion7){
                                case 1:{
                                    cout<<"1. Ordenar por nombre\n";
                                    cout<<"2. Ordenar por apellido\n";
                                    int eleccion8;
                                    cin>>eleccion8;
                                    cin.ignore();
                                    system("cls");
                                    vulnerable.buscar(eleccion8);
                                    return_menu();
                                }
                                case 2:{
                                    cout<<"1. Ordenar por nombre\n";
                                    cout<<"2. Ordenar por apellido\n";
                                    int eleccion9;
                                    cin>>eleccion9;
                                    cin.ignore();
                                    system("cls");
                                    noVulnerable.buscar(eleccion9);
                                    return_menu();
                                }
                            }
                        }
                    }
                }
                case 2:{
                    cout<<"El paciente presenta alguno de los siguientes factores de riesgo?\n";
                    cout<<"Embarazo, Enfermedad cardiovacular, Diabetes, Enfermedad hepatica\n";
                    cout<<"Enfermedad cronica neurologica o neuromuscular, Pos parto, Enfermedad renal\n";
                    cout<<"Inmunodeficiencia,Cancer, Enfermedad pulmonar cronica, Es mayor de 60 anios\n";
                    string riesgo;
                    getline(cin,riesgo);
                    system("cls");
                    if(riesgo=="SI"||riesgo=="Si"||riesgo=="si"){
                            vulnerable.Registro();
                            vulnerable.registro_Paciente();
                            vulnerable.centroRecomendado();
                            return_menu();
                    }
                    else if((riesgo=="NO"||riesgo=="No"||riesgo=="no")){
                            noVulnerable.Registro();
                            noVulnerable.registro_Paciente();
                            return_menu();
                    }

                }
                case 3:{ // Actualizar el estado del paciente
                    cout<<"1.Pacientes vulnerables"<<endl;
                    cout<<"2.Pacientes no vulnerables"<<endl;
                    int eleccion6;
                    cin>>eleccion6;
                    cin.ignore();
                    system("cls");
                    switch (eleccion6){
                        case 1:{
                            vulnerable.estado_Paciente();
                            return_menu();
                        }
                        case 2:{
                            noVulnerable.estado_Paciente();
                            return_menu();
                        }
                    }
                }
            }
        }
        case 2:{
            personal.elegirOpcion();
            return_menu();
        }
        case 3:{
            return ;
        }
        default:{
                cout<<"No hay esa opcion"<<endl;
        }
    }
}

void return_menu()
{
    string volver;
    cout<<"\nPresiona v para volver al menu\n";getline(cin,volver);
    system("cls");
    if(volver=="v"){menu();}
}


