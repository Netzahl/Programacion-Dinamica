#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <string>

using namespace std;

struct Persona {
    string nombre;
    int edad;
};

int main()
{
    Persona paciente;
    char tecla;

    do {
        system("cls");
        cout << "Nombre del Paciente: ";
        getline(cin, paciente.nombre);

        cout << "Edad: ";
        cin >> paciente.edad;
        cin.ignore();

        ofstream archivoPaciente("pacientes.txt", ios::app);

        if(archivoPaciente.is_open()){
            archivoPaciente << paciente.nombre << "," << paciente.edad << endl;
            archivoPaciente.close();
            cout << "Paciente guardado correctamente.\n";
        } else  {
            cout << "No se puede abrir el archivo.\n";
        }

        cout << "\nPresione ESC para salir o cualquier otra tecla para continuar.";
        tecla = _getch();

     }while(tecla != 27);

     system("cls");
     ifstream archivoPacienteLeer("pacientes.txt");

     string registro;
     while (getline(archivoPacienteLeer, registro)){
        cout << registro << endl;
     }
     return 0;
}
