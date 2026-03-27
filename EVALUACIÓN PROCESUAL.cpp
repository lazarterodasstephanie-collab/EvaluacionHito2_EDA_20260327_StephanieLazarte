#include <iostream>
#include <string>
using namespace std;

// Estructura del nodo para registro de estudiante 
struct Nodo {
    string nombre;
    string codigo;
    Nodo* prev;
    Nodo* next;
};

struct Lista {
    Nodo* head;  // primero en llegar (se atiende primero)
    Nodo* tail;  // último en llegar  (se agrega aquí)
    int   tamanio;

    Lista() : head(nullptr), tail(nullptr), tamanio(0) {}
};

//  1. Registrar estudiante (agrega al FINAL) 
void registrar(Lista& lista, string nombre, string codigo) {
    Nodo* nuevo = new Nodo();
    nuevo->nombre = nombre;
    nuevo->codigo = codigo;
    nuevo->prev   = nullptr;
    nuevo->next   = nullptr;

    if (lista.tail == nullptr) {
        // Lista vacía: el nuevo es head y tail
        lista.head = nuevo;
        lista.tail = nuevo;
    } else {
        // Enlazar al final
        nuevo->prev      = lista.tail;
        lista.tail->next = nuevo;
        lista.tail       = nuevo;
    }
    lista.tamanio++;
    cout << "\n Estudiante registrado correctamente.\n";
}

// 2. Atiende al estudiante 
void atender(Lista& lista) {
    if (lista.head == nullptr) {
        cout << "\n No hay estudiantes en espera.\n";
        return;
    }

    Nodo* atendido = lista.head;
    cout << "\n** Atendiendo *************************\n";
    cout << "  Nombre : " << atendido->nombre << "\n";
    cout << "  Codigo : " << atendido->codigo << "\n";
    cout << "*****************************************\n";

    lista.head = atendido->next;
    if (lista.head != nullptr) {
        lista.head->prev = nullptr;
    } else {
        lista.tail = nullptr;  // la lista quedó vacía
    }

    delete atendido;
    lista.tamanio--;
}

// 3. Mostrar al estudiantes q esta en espera 
void mostrar(const Lista& lista) {
    if (lista.head == nullptr) {
        cout << "\n No hay estudiantes en espera.\n";
        return;
    }

    cout << "\n** Estudiantes en espera *************\n";
    Nodo* actual = lista.head;
    int pos = 1;
    while (actual != nullptr) {
        cout << "  " << pos << ". " << actual->nombre
             << " | " << actual->codigo << "\n";
        actual = actual->next;
        pos++;
    }
    cout << "****************************************\n";
}

// 4. Buscar estudiante por nombre 
void buscar(const Lista& lista, string nombre) {
    if (lista.head == nullptr) {
        cout << "\n La lista esta vacia.\n";
        return;
    }

    Nodo* actual = lista.head;
    int pos = 1;
    bool encontrado = false;

    while (actual != nullptr) {
        if (actual->nombre == nombre) {
            cout << "\n  Estudiante encontrado:\n";
            cout << "  Posicion : " << pos << "\n";
            cout << "  Nombre   : " << actual->nombre << "\n";
            cout << "  Codigo   : " << actual->codigo << "\n";
            encontrado = true;
            break;
        }
        actual = actual->next;
        pos++;
    }

    if (!encontrado) {
        cout << "\n Estudiante no encontrado.\n";
    }
}