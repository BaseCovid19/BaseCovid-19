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
    cout << "Ingrese su nombre de usuario: " << endl;cin>>a;
    cout << "Ingrese su contrasena: " << endl;cin>>b;
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
int main()
{
    if(acceder())
    {
    cout<<endl;
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
                    cout<<"3.Vector de pacientes\n";
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
                    else if(eleccion==3)// ESTAS FUNCIONES LAS USÉ PARA IR PROBANDO LOS CONTADORES, PORSIACA ALGO SALÍA MAL Y SE BORRABAN LOS ARCHIVOS
                    {
                        vulnerable.vector_nombres();
                        //vulnerable.crear_contr();
                        //vulnerable.aumentar_contr();
                        //vulnerable.crear_contf();
                        //vulnerable.aumentar_contf();
                        //vulnerable.crear_contador();
                        //vulnerable.aumentar_contador();
                        //vulnerable.reducir_contador();
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
                    cout<<"1.Pacientes vulnerables"<<endl;
                    cout<<"2.Pacientes no vulnerables"<<endl;
                    cin>>eleccion;
                    cin.ignore();
                    system("cls");
                    if(eleccion==1)
                    {
                        vulnerable.estado_Paciente();
                        return_menu();
                    }
                    else
                    {
                        noVulnerable.estado_Paciente();
                        return_menu();
                    }
                }
            }
            else if(eleccion==2){
                personal.elegirOpcion();
                return_menu();
            }
            else if(eleccion==3){return ;}
        }while(eleccion!=1||eleccion!=2);
    }

void return_menu()
{
    string volver;
    cout<<"\nPresiona v para volver al menu\n";getline(cin,volver);
    system("cls");
    if(volver=="v"){menu();}
}

