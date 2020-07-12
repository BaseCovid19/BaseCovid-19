#include "Vulnerable.h"
#include <iostream>
#include <string.h>
#include <fstream>
#include <vector>
using namespace std;


Vulnerable::Vulnerable()
{
   centroMedico="";
   direccionCentro="";
   telefonoCentro=0;
   estado_aux="";
}

void Vulnerable::imprimirOpciones(){
        cout<<endl;
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
            this->centroMedico = "C.S. Cerro Colorado";
            this->direccionCentro = "Avenida Villa Hermosa 320 Urbanizacion La Libertad";
            this->telefonoCentro = 250783;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 2:{
            this->centroMedico = "C.S. Francisco Bolognesi";
            this->direccionCentro = "Calle 20 de abril 204 p.j. Fco. Bolognesi";
            this->telefonoCentro = 459180;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 3:{
            this->centroMedico= "C.S. Alto Selva Alegre";
            this->direccionCentro = "Av. Espania 301";
            this->telefonoCentro = 266688;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 4:{
            this->centroMedico= "C.S. Edificadores Misti";
            this->direccionCentro = "Calle Ricardo Palma 305-307";
            this->telefonoCentro = 266729;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 5:{
            this->centroMedico="C.S. Mariano Melgar";
            this->direccionCentro = "Calle Ica 303";
            this->telefonoCentro = 453795;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 6:{
            this->centroMedico="C.S. Ampliacion Paucarpata";
            this->direccionCentro = "Av. Kennedy Ruiz";
            this->telefonoCentro = 497226;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 7:{
            this->centroMedico= "C.S. Characato";
            this->direccionCentro = "Av. Socabaya s/n";
            this->telefonoCentro = 448608;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 8:{
            this->centroMedico= "C.S Javier Llosa Garcia";
            this->direccionCentro = "Cordova 125";
            this->telefonoCentro = 442495;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 9:{
            this->centroMedico= "C.S. Victor Raul Hinojosa Llerena";
            this->direccionCentro = "Calle Venezuela Mz.22-A LT.1";
            this->telefonoCentro = 486537;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 10:{
            this->centroMedico= "C.S. San Martin de Socabaya";
            this->direccionCentro = "Av. Socabaya 300";
            this->telefonoCentro = 438638;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 11:{
            this->centroMedico= "C.S. Tiabaya";
            this->direccionCentro = "Calle Paz Soldan s/n";
            this->telefonoCentro = 439402;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 12:{
            this->centroMedico= "C.S. Yanahuara";
            this->direccionCentro = "Esquina Espinar y Ugarte s/n";
            this->telefonoCentro = 253672;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 13:{
            this->centroMedico= "C.S. Yanahuara";
            this->direccionCentro = "Esquina Espinar y Ugarte s/n";
            this->telefonoCentro = 253672;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }
        case 14:{
            this->centroMedico= "Hospital Regional Honorio Delgado";
            this->direccionCentro = "Av. Daniel Alcides Carrión 505";
            this->telefonoCentro = 231818;
            cout<<endl;
            cout<< "El paciente debe ir al Centro Medico: "<<centroMedico<<endl;
            cout<< "La direccion es: "<< direccionCentro<<endl;
            cout<< "Puede llamar al numero: "<<telefonoCentro<<endl;
            break;
        }

        default:{
                cout<<"No hay esa opcion"<<endl;
        }
    }
}








