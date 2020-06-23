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






