#include "NoVulnerable.h"
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

NoVulnerable::NoVulnerable()
{
    familia="";
    ocupacion="";
    celular="";
}

void NoVulnerable::setFamilia(string _familia)
{
    familia=_familia;
}

void NoVulnerable::setOcupacion(string _ocupacion)
{
    ocupacion=_ocupacion;
}

void NoVulnerable::setCelular(string _celular)
{
    celular=_celular;
}

string NoVulnerable::getFamilia()
{
    return familia;
}

string NoVulnerable::getOcupacion()
{
    return ocupacion;
}

string NoVulnerable::getCelular()
{
    return celular;
}

string NoVulnerable::Registro()
{
    Poblacion::Registro();
    cout<<"Ingresa la ocupacion del paciente: ";getline(cin,ocupacion);
    cout<<"Ingresa el numero de celular: ";getline(cin,celular);
    cout<<"Ingresa la cantidad de familiares que viven con el paciente: ";getline(cin,familia);
    setFamilia(familia);setOcupacion(ocupacion);setCelular(celular);
}

void NoVulnerable::registro_Paciente()
{
    ofstream archivo;
    archivo.open("Pacientes_NoVulnerables",ios::app|ios::out);
    if(archivo.fail()){cout<<"No pudo abrirse el archivo"; exit(1);}
    archivo<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<familia<<" "<<ocupacion<<" "<<celular<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;
    archivo.close();
    Poblacion::aumentar_contador();
}

void NoVulnerable::mostrar_Registro()
{
    ifstream leerfile,leercont,leercontf,leercontr;
    leerfile.open("Pacientes_NoVulnerables",ios::in);
    leercont.open("Contador",ios::in);
    leercontf.open("Contador_Fallecidos",ios::in);
    leercontr.open("Contador_Recuperados",ios::in);
    if(leercont.is_open())
    {
        leercont>>contadorPacientes;
        cout<<"Numero de pacientes infectados: "<<contadorPacientes<<endl;
        leercont.close();
    }
    if(leercontf.is_open()) // LEE NUMERO DE FALLECIDOS
    {
        leercontf>>contadorFallecidos;
        cout<<"Numero de fallecidos: "<<contadorFallecidos<<endl;
        leercontf.close();
    }
    if(leercontr.is_open()) // LEE NUMERO DE REGISTRADOS
    {
        leercontr>>contadorRecuperados;
        cout<<"Numero de recuperados: "<<contadorRecuperados<<endl;
        leercontr.close();
    }
    if(leerfile.is_open())
    {
        cout<<"Registro de pacientes"<<endl;
        leerfile>>nombrePaciente;
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>familia>>ocupacion>>celular>>sintoma>>antecedente>>estado;
            cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
            cout<<"Estado del paciente: "<<getEstado()<<endl;
            cout<<"Nombre: "<<getNombre()<<endl;
            cout<<"Apellido: "<<getApellido()<<endl;
            cout<<"Edad: "<<getEdad()<<endl;
            cout<<"Distrito: "<<getDistrito()<<endl;
            cout<<"Integrantes en la familia: "<<getFamilia()<<endl;
            cout<<"Ocupacion: "<<getOcupacion()<<endl;
            cout<<"Numero de celular: "<<getCelular()<<endl;
            cout<<"Sintomas: "<<getSintomas()<<endl;
            cout<<"Antecedentes: "<<getAntecedente()<<endl;
            leerfile>>nombrePaciente;
        }
        leerfile.close();
    }else{cout<<"El archivo no pudo abrirse\n";}
}

void NoVulnerable::estado_Paciente() // agregando...
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Pacientes_NoVulnerables",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        cout<<"Ingresa el nombre del paciente: ";cin>>nombre_aux;
        cin.ignore();
        leerfile>>nombrePaciente; // lectura adelantada
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>familia>>ocupacion>>celular>>sintoma>>antecedente>>estado;
            if(nombre_aux==nombrePaciente)
            {
                encontrado=true;
                cout<<"Datos del paciente: "<<endl;
                cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cout<<"Estado del paciente: "<<getEstado()<<endl;
                cout<<"Nombre: "<<getNombre()<<endl;
                cout<<"Apellido: "<<getApellido()<<endl;
                cout<<"Edad: "<<getEdad()<<endl;
                cout<<"Distrito: "<<getDistrito()<<endl;
                cout<<"Integrantes en la familia: "<<getFamilia()<<endl;
                cout<<"Ocupacion: "<<getOcupacion()<<endl;
                cout<<"Numero de celular: "<<getCelular()<<endl;
                cout<<"Sintomas: "<<getSintomas()<<endl;
                cout<<"Antecedentes: "<<getAntecedente()<<endl;
                cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cout<<"Ingresa el estado en el que se encuentra el paciente: ";getline(cin,estado_aux);
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<familia<<" "<<ocupacion<<" "<<celular<<" "<<sintoma<<" "<<antecedente<<" "<<estado_aux<<endl;// Una vez leido el nuevo estado, se le asigna el estado al nuevo archivo aux
                cout<<"El estado del paciente ha cambiado"<<endl;
            }
            else{
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<familia<<" "<<ocupacion<<" "<<celular<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;// Usar el archivo aux con la misma info
            }
            leerfile>>nombrePaciente;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}

    if(encontrado==false)
    {
        cout<<"No tenemos pacientes registrados con el nombre ingresado\n";
    }
    auxfile.close();
    leerfile.close();
    remove("Pacientes_NoVulnerables");
    rename("Auxfile","Pacientes_NoVulnerables");
    NoVulnerable::alta_Paciente();
    NoVulnerable::muerte_Paciente();
}

void NoVulnerable::alta_Paciente()
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Pacientes_NoVulnerables",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        leerfile>>nombrePaciente; // lectura adelantada
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>familia>>ocupacion>>celular>>sintoma>>antecedente>>estado;
            if(estado=="Recuperado")
            {
                alta=true;
                cout<<"El paciente fue dado de alta"<<endl;
            }
            else{
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<familia<<" "<<ocupacion<<" "<<celular<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;// Usar el archivo aux con la misma info
            }
            leerfile>>nombrePaciente;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}
    auxfile.close();
    leerfile.close();
    remove("Pacientes_NoVulnerables");
    rename("Auxfile","Pacientes_NoVulnerables");

    if(alta)// alta == true
    {
        reducir_contador();
        aumentar_contr();
    }
}

void NoVulnerable::muerte_Paciente()
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Pacientes_NoVulnerables",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        leerfile>>nombrePaciente; // lectura adelantada
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>familia>>ocupacion>>celular>>sintoma>>antecedente>>estado;
            if(estado=="Fallecido")
            {
                muerto=true;
                cout<<"El paciente ha fallecido"<<endl;
            }
            else{
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<familia<<" "<<ocupacion<<" "<<celular<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;// Usar el archivo aux con la misma info
            }
            leerfile>>nombrePaciente;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}
    auxfile.close();
    leerfile.close();
    remove("Pacientes_NoVulnerables");
    rename("Auxfile","Pacientes_NoVulnerables");

    if(muerto)
    {
        reducir_contador();
        aumentar_contf();
    }
}






