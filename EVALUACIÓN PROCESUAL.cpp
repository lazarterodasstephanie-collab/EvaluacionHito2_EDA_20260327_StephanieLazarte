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