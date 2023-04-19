/* 
Tarea de PIlas #2da
 Angel Malaver CI:30310383, Idiar Chacin CI:30217559, Valeria Salcedo CI:30270659, Victoria Acosta CI: 30106795
																																															*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


typedef struct pelifericos{
    char marca[50];
    char tipo[50];
    char formato[50];
    char Modelo[50];
    char color[50];
    int precioenD;
    int cantenstock;
    int disponible; 
}pelifericos;


typedef struct nodo{
    pelifericos *dato;
    struct nodo *Siguiente;
}Nodo;


typedef struct pila{
    Nodo *tope;
    int total; 
}Pila;  

pelifericos *Crearpelifericos(char marca[50],char tipo[50],char formato[50],char Modelo[50],char color[50],int precioenD,int cantenstock,int disponible);
Nodo *CrearNodo(pelifericos *pelifericos);
Pila *CrearPila();
int EstaVacia(Pila *pila);
void Insertar(Pila *pila, Nodo *nodo);
void Imprimir(Pila *pila);
void EliminarElemento(Pila *pila);

int main(){
    Pila *pila = CrearPila();
    pelifericos *tel1 = Crearpelifericos("Magegee", "teclado", "alambrico", "mkbox", "negro con gris", 60, 3, 0);
    Nodo *nodo1 = CrearNodo(tel1);
    Insertar(pila,nodo1);

    pelifericos *tel2 = Crearpelifericos("Magegee", "teclado", "alambrico", "Star61", "negro con gris", 60, 0, 0);
    Nodo *nodo2 = CrearNodo(tel2);
    Insertar(pila,nodo2);

    pelifericos *tel3 = Crearpelifericos("Magegee", "teclado", "alambrico", "Star61", "blanco con vino", 60, 7, 1);
    Nodo *nodo3 = CrearNodo(tel3);
    Insertar(pila,nodo3);

    pelifericos *tel4 = Crearpelifericos("E-yooso", "teclado", "alambrico", "k-620", "negro", 50, 2, 1);
    Nodo *nodo4 = CrearNodo(tel4);
    Insertar(pila,nodo4);

    pelifericos *tel5 = Crearpelifericos("E-yooso", "teclado", "alambrico", "k-662", "negro", 55, 0, 0);
    Nodo *nodo5 = CrearNodo(tel5);
    Insertar(pila,nodo5);

    Insertar(pila, CrearNodo( Crearpelifericos("Fantech", "mouse", "alambrico", "Phanton", "negro", 20, 6, 1) ) );

    Insertar(pila, CrearNodo( Crearpelifericos("Fantech", "mouse", "alambrico", "Crypto", "negro", 20, 4, 1) ) );

    Insertar(pila, CrearNodo( Crearpelifericos("Fantech", "mouse", "alambrico", "Crypto", "Rosado", 20, 0, 0) ) );

    Imprimir(pila);

    EliminarElemento(pila);
    EliminarElemento(pila);
    EliminarElemento(pila);

    printf("\n");
    printf("\nAhora luego de haber eliminado 3 elementos\n");
    printf("\n");
    Imprimir(pila);


    return 0;
}

pelifericos *Crearpelifericos(char marca[50],char tipo[50],char formato[50],char Modelo[50],char color[50],int precioenD,int cantenstock,int disponible){
    pelifericos *aux = (pelifericos*)malloc(sizeof(pelifericos));
    strcpy(aux->marca, marca);
    strcpy(aux->tipo, tipo);
    strcpy(aux->formato, formato);
    strcpy(aux->Modelo, Modelo);
    strcpy(aux->color, color);
    aux->precioenD = precioenD;
    aux->cantenstock = cantenstock;
    aux->disponible = disponible;
    return aux;
}

Nodo *CrearNodo(pelifericos *pelifericos){
    Nodo *aux = (Nodo*)malloc(sizeof(Nodo));
    aux->dato = pelifericos;
    aux->Siguiente = NULL;

}

Pila *CrearPila(){
    Pila *aux = (Pila*)malloc(sizeof(Pila));
    aux->tope = NULL;
    aux->total = 0;
    return aux;
}

int EstaVacia(Pila *pila){
    if(pila->total == 0){
        return 1;
    }else{
        return 0;
    }
}

void Insertar(Pila *pila, Nodo *aux){
    if(EstaVacia(pila)){
        pila->tope = aux;
    }else{
        aux->Siguiente = pila->tope;
        pila->tope = aux;
    }

    pila->total++;
}

void Imprimir(Pila *pila){
    Nodo *aux = pila->tope;
    pelifericos *t;
    while(aux != NULL){
        t = aux->dato;

        printf("La marca es: %s\n", t->marca);
        printf("El tipo es: %s\n", t->tipo);
        printf("El formato del preliferico: %s\n", t->formato);
        printf("El modelo del producto: %s\n", t->Modelo);
        printf("El color del equipo es: %s\n", t->color);
        printf("El precio del equipo es: %d $\n", t->precioenD);
        printf("La cantidad en stock: %d \n", t->cantenstock);

        if(t->disponible){
            printf("El pelifericos SI  esta en stock\n");
        }else{
            printf("El pelifericos NO  esta en stock\n");
        }
 
        printf("\n\n");

        aux = aux->Siguiente;
    }
}

void EliminarElemento(Pila *pila){
    if(pila->tope == NULL){
        printf("No se pudo eliminar, la pila se encuentra vacia\n");
    }else{
        Nodo *aux = pila->tope;
        pila->tope = pila->tope->Siguiente;
        free(aux->dato);
        free(aux);
        pila->total--;
    }
}