#include "Disponibilidad.h"
#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

    Disponibilidad::Disponibilidad(){
        cantidad = 0;
    }

    void Disponibilidad::imprimirOpciones(){
        cout<< "Elija el tipo de Centro de Salud: "<<endl;
        cout<< "1.Hospital" <<endl;
        cout<< "2.Microred" <<endl;
        cout<< "3.Puesto de Salud" <<endl;
    }
    void Disponibilidad::elegirOpcion(){
        int eleccion;
        imprimirOpciones();
        cin>>eleccion;
        cin.ignore();
        system("cls");
        switch (eleccion){
            case 1:{
                this->cantidad=50;
                cout<< "Personal disponible: "<<cantidad"<<endl;
                break;
            }
            case 2:{
                this->cantidad=15;
                cout<< "Personal disponible: "<<cantidad"<<endl;
                break;
            }
            case 3:{
                this->cantidad=6;
                cout<< "Personal disponible: "<<cantidad"<<endl;
                break;
            }
            default:{
                cout<<"No hay esa opcion"<<endl;
            }
        }
    }
