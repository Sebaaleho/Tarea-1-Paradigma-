#include <iostream>
#include <string>

using namespace std;

const int MAX = 100;

class Pregunta {
public:
    int id;
    string enunciado;
    string solucion;
    string tipo; // Opcion Multiple o Verdadero/Falso
    int nivel;   // Nivel (1-6)
    int tiempo;  // en minutos

    void mostrar() {
        cout << "ID: " << id << endl;
        cout << "Pregunta: " << enunciado << endl;
        cout << "Respuesta esperada: " << solucion << endl;
        cout << "Tipo: " << tipo << endl;
        cout << "Nivel: " << nivel << endl;
        cout << "Tiempo: " << tiempo << " min" << endl;
        cout << "--------------------------" << endl;
    }
};

class Evaluacion {
private:
    Pregunta preguntas[MAX];
    int total;

public:
    Evaluacion() {
        total = 0;
    }

    void agregar(Pregunta p) {
        if (total < MAX) {
            preguntas[total] = p;
            total++;
            cout << "Pregunta agregada" << endl;
        } else {
            cout << "No se pueden agregar mas preguntas" << endl;
        }
    }

    void eliminar(int id) {
        bool encontrado = false;
        for (int i = 0; i < total; i++) {
            if (preguntas[i].id == id) {
                for (int j = i; j < total - 1; j++) {
                    preguntas[j] = preguntas[j + 1];
                }
                total--;
                encontrado = true;
                cout << "Pregunta eliminada" << endl;
                break;
            }
        }
        if (!encontrado) {
            cout << "Pregunta no encontrada" << endl;
        }
    }

    void editar(int id) {
        for (int i = 0; i < total; i++) {
            if (preguntas[i].id == id) {
                cin.ignore();
                cout << "Nuevo enunciado: ";
                getline(cin, preguntas[i].enunciado);
                cout << "Nueva respuesta: ";
                getline(cin, preguntas[i].solucion);
                cout << "Nuevo tipo: ";
                getline(cin, preguntas[i].tipo);
                cout << "Nuevo nivel (1-6): ";
                cin >> preguntas[i].nivel;
                cout << "Nuevo tiempo (min): ";
                cin >> preguntas[i].tiempo;
                cout << "Pregunta actualizada" << endl;
                return;
            }
        }
        cout << "No se encontro la pregunta" << endl;
    }

    void mostrarTodo() {
        cout << "\n--- Preguntas ---\n";
        for (int i = 0; i < total; i++) {
            preguntas[i].mostrar();
        }
    }

    int tiempoTotal() {
        int suma = 0;
        for (int i = 0; i < total; i++) {
            suma += preguntas[i].tiempo;
        }
        return suma;
    }
};

int main() {
    Evaluacion eval;
    int opcion;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Agregar pregunta\n";
        cout << "2. Eliminar pregunta\n";
        cout << "3. Editar pregunta\n";
        cout << "4. Mostrar todo\n";
        cout << "5. Ver tiempo total\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                Pregunta p;
                cout << "ID: ";
                cin >> p.id;
                cin.ignore();
                cout << "Enunciado: ";
                getline(cin, p.enunciado);
                cout << "Respuesta esperada: ";
                getline(cin, p.solucion);
                cout << "Tipo (OM/VF): ";
                getline(cin, p.tipo);
                cout << "Nivel (1-6): ";
                cin >> p.nivel;
                cout << "Tiempo estimado (min): ";
                cin >> p.tiempo;
                eval.agregar(p);
                break;
            }
            case 2: {
                int id;
                cout << "ID a eliminar: ";
                cin >> id;
                eval.eliminar(id);
                break;
            }
            case 3: {
                int id;
                cout << "ID a editar: ";
                cin >> id;
                eval.editar(id);
                break;
            }
            case 4:
                eval.mostrarTodo();
                break;
            case 5:
                cout << "Tiempo total estimado: " << eval.tiempoTotal() << " min\n";
                break;
            case 0:
                cout << "Saliendo\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }

    } while (opcion != 0);

    return 0;
}