#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definición de la estructura de datos
typedef struct {
    char nombre[50];
    char actor[50];
    int edad;
} Personaje;

// Definición del nodo de la cola
typedef struct Nodo {
    Personaje personaje;
    struct Nodo* siguiente;
} Nodo;

// Función para crear un nodo
Nodo* crearNodo(Personaje personaje) {
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->personaje = personaje;
    nodo->siguiente = NULL;
    return nodo;
}

// Función para agregar un elemento a la cola
void agregarElemento(Nodo** cabeza, Nodo** cola, Personaje personaje) {
    Nodo* nodo = crearNodo(personaje);
    if (*cabeza == NULL) {
        *cabeza = nodo;
        *cola = nodo;
    } else {
        (*cola)->siguiente = nodo;
        *cola = nodo;
    }
}

// Función para borrar un elemento de la cola
void borrarElemento(Nodo** cabeza) {
    if (*cabeza == NULL) {
        printf("La cola esta vacia.\n");
    } else {
        Nodo* temp = *cabeza;
        *cabeza = (*cabeza)->siguiente;
        free(temp);
    }
}

// Función para recorrer los elementos de la cola y mostrarlos
void mostrarElementos(Nodo* cabeza) {
    if (cabeza == NULL) {
        printf("La cola esta vacia.\n");
    } else {
        Nodo* actual = cabeza;
        while (actual != NULL) {
            printf("Nombre: %s\n", actual->personaje.nombre);
            printf("Actor: %s\n", actual->personaje.actor);
            printf("Edad: %d\n", actual->personaje.edad);
            printf("\n");
            actual = actual->siguiente;
        }
    }
}

int main() {
    Nodo* cabeza = NULL;
    Nodo* cola = NULL;

    // Agregar personajes a la cola
    Personaje personaje1 = {"Rachel Green", "Jennifer Aniston", 26};
    agregarElemento(&cabeza, &cola, personaje1);

    Personaje personaje2 = {"Monica Geller", "Courteney Cox", 30};
    agregarElemento(&cabeza, &cola, personaje2);

    Personaje personaje3 = {"Phoebe Buffay", "Lisa Kudrow", 32};
    agregarElemento(&cabeza, &cola, personaje3);

    Personaje personaje4 = {"Joey Tribbiani", "Matt LeBlanc", 28};
    agregarElemento(&cabeza, &cola, personaje4);

    Personaje personaje5 = {"Chandler Bing", "Matthew Perry", 29};
    agregarElemento(&cabeza, &cola, personaje5);

    // Mostrar los elementos de la cola
    printf("Personajes en la cola:\n");
    mostrarElementos(cabeza);

    // Borrar un elemento de la cola
    printf("Borrando un elemento de la cola...\n");
    borrarElemento(&cabeza);

    // Mostrar los elementos de la cola nuevamente
    printf("Personajes en la cola despues de borrar un elemento:\n");
    mostrarElementos(cabeza);

    return 0;
}
