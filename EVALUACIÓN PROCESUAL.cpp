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
    Nodo* head;
    Nodo* tail;
    int tamanio;
};
// 1. Registrar estudiante (agrega al FINAL) 
void registrar(Lista& lista, string nombre, string codigo) {
    Nodo* nuevo = new Nodo();
    nuevo->nombre = nombre;
    nuevo->codigo = codigo;
    nuevo->prev = nullptr;
    nuevo->next = nullptr;

    lista.tail->next = nuevo;
    lista.tail = nuevo;
    lista.tamanio++;
    cout << "\n Estudiante registrado correctamente.\n";
}