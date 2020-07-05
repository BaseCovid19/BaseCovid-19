#include "Vulnerable.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;


Vulnerable::Vulnerable()
{
   centroMedico="";
   direccionCentro="":
   telefonoCentro=0;
   estado_aux="";
}


/*void Vulnerable::setCentroMedico(string centroM)
{
    centroMedico=centroM;
}

string Vulnerable::getCentroMedico()
{
    return centroMedico;
}*/

void Vulnerable::imprimirOpciones(){
        cout<< "Elija el distrito en donde vive: "<<endl;
        cout<< "1.Cerro Colorado" <<endl;
        cout<< "2.Cayma" <<endl;
        cout<< "3.Alto Selva Alegre" <<endl;
        cout<< "4.Miraflores" <<endl;
        cout<< "5.Mariano Melgar" <<endl;
        cout<< "6.Paucarpata" <<endl;
        cout<< "7.Sabandia" <<endl;
        cout<< "8.Hunter" <<endl;
        cout<< "9.JLBYR" <<endl;
        cout<< "10.Socabaya" <<endl;
        cout<< "11.Tiabaya" <<endl;
        cout<< "12.Sachaca" <<endl;
        cout<< "13.Yanahuara" <<endl;
        cout<< "14.Arequipa" <<endl;
}

string Vulnerable::centroRecomendado()
{
    int eleccion;
    imprimirOpciones();
    cin>>eleccion;
    cin.ignore();
    system("cls");
    switch (eleccion){
        case 1:{
            this->centroMedico = "MR Cerro Colorado";
            this->direccionCentro = "Avenida Villa Hermosa 320 Urbanizacion La Libertad";
            this->telefonoCentro = 054250783;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 2:{
            this->centroMedico = "MR Francisco Bolognesi";
            this->direccionCentro = "Calle 20 de abril 204 p.j. Fco. Bolognesi";
            this->telefonoCentro = 054459180;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        /*case 3:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 4:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 5:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 6:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 7:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 8:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 9:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 10:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 11:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 12:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 13:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 14:{
            this->centroMedico=
            this->direccionCentro =;
            this->telefonoCentro =;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }*/
        default:{
                cout<<"No hay esa opcion"<<endl;
        }
    }
}








