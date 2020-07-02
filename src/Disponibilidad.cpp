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
                cout<< "Personal disponible: 50 personas"<<endl;
                break;
            }
            case 2:{
                cout<< "Personal disponible: 15 personas"<<endl;
                break;
            }
            case 3:{
                cout<< "Personal disponible: 6 personas"<<endl;
                break;
            }
            default:{
                cout<<"No hay esa opcion"<<endl;
            }
        }
    }
