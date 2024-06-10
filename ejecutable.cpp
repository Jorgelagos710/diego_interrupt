#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h> // Incluye la biblioteca para la función sleep

using namespace std;

// Función para simular el retardo (delay)
void delay(int seconds) {
    cout << "Modo monitor: Simulando interrupción del sistema..." << endl;
    sleep(seconds); // Utiliza la función sleep para pausar el programa durante 'seconds' segundos
    cout << "Modo usuario: Retomando ejecución." << endl;
}

int main() {
    ifstream archivo("archivo.txt");
    string linea;
    string siguienteLinea;

    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo." << endl;
        return 1;
    }

    cout << "Modo usuario: Iniciando lectura del archivo." << endl;
    while (getline(archivo, linea)) {
        if (linea.find("write") != string::npos) {
            cout << "Modo usuario: Se encontró la instrucción 'write'." << endl;

            // Leer la siguiente línea y guardarla en una variable
            if (getline(archivo, siguienteLinea)) {
                cout << "Modo usuario: Guardando la siguiente línea para continuar después del delay." << endl;
            } else {
                siguienteLinea = "";
            }

            // Simular la interrupción del sistema con un retardo de 5 segundos
            delay(5);

            // Continuar la ejecución con la siguiente línea guardada
            if (!siguienteLinea.empty()) {
                cout << "Modo usuario: Continuando con la línea guardada: " << siguienteLinea << endl;
                // Aquí puedes procesar la línea guardada si es necesario
            }
        } else {
            // Procesar la línea normalmente
            cout << "Modo usuario: Leyendo línea: " << linea << endl;
        }
    }

    archivo.close();
    cout << "Modo usuario: Lectura del archivo finalizada." << endl;

    return 0;
}
