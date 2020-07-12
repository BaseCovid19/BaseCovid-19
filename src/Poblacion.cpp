#include "Poblacion.h"
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

Poblacion::Poblacion()
{
    this->nombrePaciente="";
    this->apellidoPaciente="";
    this->distrito="";
    this->sintoma="";
    this->antecedente="";
    this->edad=0;
    this->estado="Infectado";
    this->encontrado=false;
    this->nombre_aux="";
    this->estado_aux="";
    this->contadorPacientes=0;
    this->contadorFallecidos=0;
    this->contadorRecuperados=0;
    this->alta=false;
    this->muerto=false;
    this->recuperado=false;
    this->medicoEncargado="";
}

void Poblacion::setNombre(string miNombre)
{
    this->nombrePaciente=miNombre;
}

void Poblacion::setApellido(string miApellido)
{
    this->apellidoPaciente=miApellido;
}
string Poblacion::getNombre()
{
    return nombrePaciente;
}

string Poblacion::getApellido()
{
    return apellidoPaciente;
}

string Poblacion::Registro()
{
    cout<<"°°°°Ingresa tu informacion°°°°"<<endl;
    cout<<"Ingresa el nombre del paciente: ";getline(cin,nombrePaciente);
    cout<<"Ingresa el apellido del paciente: ";getline(cin,apellidoPaciente);
    cout<<"Ingresa la edad del paciente: ";cin>>edad; cin.ignore();
    cout<<"Ingresa el distrito del paciente: ";getline(cin,distrito);
    cout<<"Ingresa los sintomas que presenta el paciente: ";getline(cin,sintoma);
    cout<<"Ingresa los antecedentes medicos del paciente: ";getline(cin,antecedente);
    setNombre(nombrePaciente);setApellido(apellidoPaciente);setEdad(edad);setDistrito(distrito);setSintomas(sintoma);setAntecedentes(antecedente);
}

string Poblacion::Sintomas()
{
    cout<<"Ingresa los sintomas que presenta el paciente: ";getline(cin,sintoma);
    setSintomas(sintoma);
    cout<<"Los sintomas que presenta el paciente son: "<<getSintomas()<<endl;
}

string Poblacion::AntecedentesMedicos()
{
    cout<<"Ingresa los antecedentes medicos del paciente: ";getline(cin,antecedente);
    setAntecedentes(antecedente);
    cout<<"Los antecedentes medicos del paciente son: "<<getAntecedente()<<endl;
}

void Poblacion::setSintomas(string _sintoma)
{
    this->sintoma=_sintoma;
}

void Poblacion::setEdad(int miEdad)
{
    this->edad=miEdad;
}

int Poblacion::getEdad()
{
    return edad;
}

void Poblacion::setDistrito(string miDistrito)
{
    this->distrito=miDistrito;
}

void Poblacion::setAntecedentes(string _antecedente)
{
    this->antecedente=_antecedente;
}

void Poblacion::setEstado(string _estado)
{
    this->estado=_estado;
}

void Poblacion::setMedico(string med)
{
    this->medicoEncargado=med;
}

string Poblacion::getMedico()
{
    return medicoEncargado;
}
string Poblacion::getDistrito()
{
    return distrito;
}

string Poblacion::getSintomas()
{
    return sintoma;
}

string Poblacion::getAntecedente()
{
    return antecedente;
}

string Poblacion::getEstado()
{
    return estado;
}

void Poblacion::setContador(int cont)
{
    this->contadorPacientes=cont;
}

int Poblacion::getContador()
{
    return contadorPacientes;
}

void Poblacion::setContf(int contf)
{
    this->contadorFallecidos=contf;
}

int Poblacion::getContf()
{
    return contadorFallecidos;
}

/// Manipulacion de registros de la clase Vulnerable
void Poblacion::registro_Paciente()
{
    //Poblacion::Registro();
    ofstream archivo;
    archivo.open("Pacientes_Vulnerables",ios::app|ios::out);
    if(archivo.fail()){cout<<"No pudo abrirse el archivo"; exit(1);}
    archivo<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;
    archivo.close();
    aumentar_contador();
}

void Poblacion::mostrar_Registro()
{
    ifstream leerfile, leercont,leercontf,leercontr;
    leerfile.open("Pacientes_Vulnerables",ios::in);
    leercont.open("Contador",ios::in);
    leercontf.open("Contador_Fallecidos",ios::in);
    leercontr.open("Contador_Recuperados",ios::in);

    if(leercont.is_open()) // LEE PACIENTES NUMERO DE PAC. REGISTRADOS
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
            leerfile>>apellidoPaciente>>edad>>distrito>>sintoma>>antecedente>>estado;
            cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
            cout<<"Estado del paciente: "<<getEstado()<<endl;
            cout<<"Nombre: "<<getNombre()<<endl;
            cout<<"Apellido: "<<getApellido()<<endl;
            cout<<"Edad: "<<getEdad()<<endl;
            cout<<"Distrito: "<<getDistrito()<<endl;
            cout<<"Sintomas: "<<getSintomas()<<endl;
            cout<<"Antecedentes: "<<getAntecedente()<<endl;
            leerfile>>nombrePaciente;
        }
        leerfile.close();
    }else{cout<<"El archivo no pudo abrirse\n";}

}


void Poblacion::estado_Paciente()
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Pacientes_Vulnerables",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        cout<<"Ingresa el nombre del paciente: ";cin>>nombre_aux;
        cin.ignore();
        leerfile>>nombrePaciente; // lectura adelantada
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>sintoma>>antecedente>>estado;
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
                cout<<"Sintomas: "<<getSintomas()<<endl;
                cout<<"Antecedentes: "<<getAntecedente()<<endl;
                cout<<"°°°°°°°°°°°°°°°°°°°°°°°"<<endl;
                cout<<"Ingresa el estado en el que se encuentra el paciente: ";getline(cin,estado_aux);
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<sintoma<<" "<<antecedente<<" "<<estado_aux<<endl;// Una vez leido el nuevo estado, se le asigna el estado al nuevo archivo aux
                cout<<"El estado del paciente ha cambiado"<<endl;
            }
            else{
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;// Usar el archivo aux con la misma info
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
    remove("Pacientes_Vulnerables");
    rename("Auxfile","Pacientes_Vulnerables");
    alta_Paciente();
    muerte_Paciente();
}

void Poblacion::alta_Paciente()
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Pacientes_Vulnerables",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        leerfile>>nombrePaciente; // lectura adelantada
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>sintoma>>antecedente>>estado;
            if(estado=="Recuperado")
            {
                alta=true;
                cout<<"El paciente fue dado de alta"<<endl;
            }
            else{
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;// Usar el archivo aux con la misma info
            }
            leerfile>>nombrePaciente;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}
    auxfile.close();
    leerfile.close();
    remove("Pacientes_Vulnerables");
    rename("Auxfile","Pacientes_Vulnerables");

    if(alta)// alta == true
    {
        reducir_contador();
        aumentar_contr();
    }
}

void Poblacion::muerte_Paciente()
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Pacientes_Vulnerables",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        leerfile>>nombrePaciente; // lectura adelantada
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>sintoma>>antecedente>>estado;
            if(estado=="Fallecido")
            {
                muerto=true;
                cout<<"El paciente ha fallecido"<<endl;
            }
            else{
                auxfile<<nombrePaciente<<" "<<apellidoPaciente<<" "<<edad<<" "<<distrito<<" "<<sintoma<<" "<<antecedente<<" "<<estado<<endl;// Usar el archivo aux con la misma info
            }
            leerfile>>nombrePaciente;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}
    auxfile.close();
    leerfile.close();
    remove("Pacientes_Vulnerables");
    rename("Auxfile","Pacientes_Vulnerables");

    if(muerto)
    {
        reducir_contador();
        aumentar_contf();
    }
}


// Se aniade esto a la funcion registro

void Poblacion::orden_vector(int elec)
{
    ifstream leerfile;
    leerfile.open("Pacientes_Vulnerables",ios::in);
    if(leerfile.is_open())
    {
        leerfile>>nombrePaciente;
        while(!leerfile.eof())
        {
            leerfile>>apellidoPaciente>>edad>>distrito>>sintoma>>antecedente>>estado;
            vecN.push_back(nombrePaciente);
            vecA.push_back(apellidoPaciente);
            leerfile>>nombrePaciente;
        }
        leerfile.close();
    }else{cout<<"El archivo no pudo abrirse\n";}
    int orden=0;
    if(elec==1)
    {
        cout<<"1. Orden ascendente\n";
        cout<<"2. Orden descendente\n";
        cin>>orden;
        cin.ignore();
        system("cls");
        if(orden==1)
        {
            cout<<"Orden ascendente\n";
            sort(vecN.begin(),vecN.end());
                for(unsigned int i=0;i<vecN.size();i++)
            {
                cout<<"Paciente "<<i+1<<": "<<vecN[i]<<endl;
            }
        }
        else if(orden==2)
        {
            cout<<"Orden descendente\n";
            sort(vecN.begin(),vecN.end(),greater<string>()); // ordenamiento de nombres descendente
            for(unsigned int i=0;i<vecN.size();i++)
            {
                cout<<"Paciente "<<i+1<<": "<<vecN[i]<<endl;
            }
        }
    }

    else if(elec==2)
    {
        cout<<"1. Orden ascendente\n";
        cout<<"2. Orden descendente\n";
        cin>>orden;
        cin.ignore();
        system("cls");
        if(orden==1)
        {
            cout<<"Orden oscendente\n";
            sort(vecA.begin(),vecA.end());
                for(unsigned int i=0;i<vecA.size();i++)
            {
                cout<<"Paciente "<<i+1<<": "<<vecA[i]<<endl;
            }
        }
        else if(orden==2)
        {
            cout<<"Orden descendente\n";
            sort(vecA.begin(),vecA.end(),greater<string>()); // ordenamiento de nombres descendente
            for(unsigned int i=0;i<vecA.size();i++)
            {
                cout<<"Paciente "<<i+1<<": "<<vecA[i]<<endl;
            }
        }
    }
}


void Poblacion::crear_contador()
{
    ofstream contador;
    contador.open("Contador",ios::app|ios::out);
    if(contador.fail()){cout<<"No pudo abrirse el archivo"; exit(1);}
    contador<<contadorPacientes<<endl;
    contador.close();

    aumentar_contador();
}

void Poblacion::aumentar_contador()
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Contador",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        leerfile>>contadorPacientes; // lectura adelantada
        while(!leerfile.eof())
        {
            int contadorPacientes_aux=contadorPacientes+1;
            {
                auxfile<<contadorPacientes_aux<<endl;
            }
            leerfile>>contadorPacientes;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}
    auxfile.close();
    leerfile.close();
    remove("Contador");
    rename("Auxfile","Contador");
}

void Poblacion::reducir_contador()// Infectados
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Contador",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        leerfile>>contadorPacientes; // lectura adelantada
        while(!leerfile.eof())
        {
            int contadorPacientes_aux=contadorPacientes-1;
            {
                auxfile<<contadorPacientes_aux<<endl;
            }
            leerfile>>contadorPacientes;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}
    auxfile.close();
    leerfile.close();
    remove("Contador");
    rename("Auxfile","Contador");
}

// FUNCIONES PARA CONTADOR DE FALLECIDO
void Poblacion::crear_contf()
{
    ofstream contador;
    contador.open("Contador_Fallecidos",ios::app|ios::out);
    if(contador.fail()){cout<<"No pudo abrirse el archivo"; exit(1);}
    contador<<contadorFallecidos<<endl;
    contador.close();

    //aumentar_contf();
}

void Poblacion::aumentar_contf()
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Contador_Fallecidos",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        leerfile>>contadorFallecidos; // lectura adelantada
        while(!leerfile.eof())
        {
            int contadorFallecidos_aux=contadorFallecidos+1;
            {
                auxfile<<contadorFallecidos_aux<<endl;
            }
            leerfile>>contadorFallecidos;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}
    auxfile.close();
    leerfile.close();
    remove("Contador_Fallecidos");
    rename("Auxfile","Contador_Fallecidos");
}

// CONTADOR DE RECUPERADOS
void Poblacion::crear_contr()
{
    ofstream contador;
    contador.open("Contador_Recuperados",ios::app|ios::out);
    if(contador.fail()){cout<<"No pudo abrirse el archivo"; exit(1);}
    contador<<contadorRecuperados<<endl;
    contador.close();

}

void Poblacion::aumentar_contr()
{
    ofstream auxfile;
    ifstream leerfile;
    auxfile.open("Auxfile",ios::app|ios::out);
    leerfile.open("Contador_Recuperados",ios::in);
    if(auxfile.is_open()&&leerfile.is_open())
    {
        leerfile>>contadorRecuperados; // lectura adelantada
        while(!leerfile.eof())
        {
            int contadorRecuperados_aux=contadorRecuperados+1;
            {
                auxfile<<contadorRecuperados_aux<<endl;
            }
            leerfile>>contadorRecuperados;
        }
    }
    else{cout<<"El archivo no pudo abrirse\n";}
    auxfile.close();
    leerfile.close();
    remove("Contador_Recuperados");
    rename("Auxfile","Contador_Recuperados");
}

ostream& operator<<(ostream &output, const Poblacion &o) {
    output << "Nombre del medico que ha ingresado a la base: " << o.medicoEncargado; // Prueba de sobrecarga
    return output;
}


