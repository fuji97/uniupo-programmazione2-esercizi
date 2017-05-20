#include "list.h"
#include "stdlib.h"
#include "stdio.h"

/**
* @PARAM: -
* @RETURN: Il puntatore all'elemento List creato
*/
List createNode() {
    return malloc(sizeof(List*));
}

/**
* @PARAM: int data: il valore da assegnare all'elemento della lista
* @PARAM: List next: il puntatore all'elemento successivo della lista, NULL se ultimo
* @RETURN: Il puntatore all'elemento List creato
*/
List createValueNode(int data, List next) {
    List list = createNode();
    list->data = data;
    list->next = next;
    return list;
}

/**
* @PARAM: int data: il valore da assegnare all'elemento della lista
* @RETURN: Il puntatore all'elemento List creato
*/
List createNullNode(int data) {
    return createValueNode(data, NULL);
}

/**
* @PARAM: int arr[]: Puntatore all'array da usare come sorgente dei dati
* @PARAM: int size: la dimensione dell'array
* @RETURN: Il puntatore all'elemento alla testa della List creata
*/
List createListFromArray(int arr[], int size) {
    List out = NULL;
    List tail = NULL;
    int i;
    for (i = 0; i < size; i++) {
        if (out == NULL) {
            out = createNode();
            out->data = arr[i];
            out->next = NULL;
            tail = out;
        } else {
            tail->next = createNode();
            tail = tail->next;
            tail->data = arr[i];
            tail->next = NULL;
        }
    }
    
    return out;
}

/**
* @PARAM: List list: puntatore alla lista che si vuole stampare
* @RETURN: -
*/
void printList(List list) {
    if (list == NULL)
        return;
        
    while (list != NULL) {
        printf("%d\t", list->data);
        list = list->next;
    }
    printf("\n");
}

/**
* @PARAM: char path[]: il percorso al file da utilizzare
* @RETURN: Il puntatore alla testa della lista creata
*/
List listFromFile(char path[]) {
    int data;

    FILE *fp = fopen(path, "r");

    List startL = NULL;
    List nextL = NULL;

    if (fp == NULL) {
        printf("Errore nell’apertura del file\n");
        return startL;
    }
    
    while (fscanf(fp, "%d", &data) != EOF) {
        if (startL == NULL) {
            startL = createNode();
            startL->data = data;
            nextL = startL;
        } else {
            nextL->next = createNode();
            nextL = nextL->next;
            nextL->data = data;
        }
    }
    nextL->next = NULL; // concluso il ciclo il campo next dell'ultimo nodo e' settato a NULL
    
    fclose(fp); // Chiudo il File

    return startL; // restituisce il puntatore alla testa della lista
}

/**
* @PARAM: List list: puntatore alla testa della List da scrivere
* @PARAM: char path[]: il percorso al file da creare
* @RETURN: -
*/
void listToFile(List list, char path[]) {
    FILE *fp = fopen(path, "w");
    
    if (fp == NULL) {
        printf("Errore nell’apertura del file\n");
        return;
    }
    
    while(list != NULL) {
        fprintf(fp, "%d\n", list->data);
        list = list->next;
    }
    
    fclose(fp);
}

/**
* @PARAM: List *list: puntatore al puntatore della testa della List su cui operare
* @PARAM: int val: valore da inserire in testa alla lista
* @RETURN: L'elemento pushato
*/
List pushNode(List *list, int val) {
    // Controllo se il puntatore al puntatore o il puntare sono NULL
    if (list == NULL) return NULL;
    if (*list == NULL) return NULL;
    
    List node = createValueNode(val, *list);
    *list = node;
    
    return node;
}

/**
* @PARAM: List *list: puntatore al puntatore della testa della List su cui operare
* @RETURN: L'elemento pullato
*/
List pullNode(List *list) {
    // Controllo se il puntatore al puntatore o il puntare sono NULL
    if (list == NULL) return NULL;
    if (*list == NULL) return NULL;
    
    List node = *list;
    *list = (*list)->next;
    return node;
}

/**
* @PARAM: List *list: puntatore al puntatore della testa della List su cui operare
* @RETURN: Il valore dell'elemento estratto dalla testa della List
* @NOTE: ATTENZIONE: Questo metodo andrà anche ad eliminare il nodo estratto ritornando solo il valore
*/
int pullValue(List *list) {
    // Controllo se il puntatore al puntatore o il puntare sono NULL
    if (list == NULL) return NULL;
    if (*list == NULL) return NULL;
    
    List node = *list;
    *list = (*list)->next;
    int ret = node->data;
    free(node);
    return ret;
}

/**
* @PARAM: List list: puntatore alla testa della List su cui operare
* @PARAM: int index: posizione in cui inserire l'elemento (>0)
* @PARAM: int val: l'elemento da inserire nella List
* @RETURN: Il nodo inserito
* @NOTE: Non puoi inserire elementi in testa con questo metodo, usa piuttosto pushNode()
*/
List addNodeToIndex(List list, int index, int val) {
    // Controllo se List è NULL
    if (list == NULL || index < 1) return NULL;
    
    int i;
    for (i = 1; list->next != NULL; i++) {
        if (i == index) {
            List node = createValueNode(val, list->next);
            list->next = node;
            return node;
        }
        list = list->next;
    }
    
    // Aggiungi l'elemento in coda alla List se l'indice non esiste
    List node = createValueNode(val, list->next);
    list->next = node;
    return node;
}

/**
* @PARAM: List list: puntatore alla testa lista da leggere
* @PARAM: int index: indice del nodo da leggere
* @RETURN: Il nodo presente all'indice indicato
*/
List getNodeIndex(List list, int index) {
    // Controllo se List è vuota
    if (list == NULL) return NULL;
    
    int i;
    for (i = 0; list != NULL; i++) {
        if (i == index)
            return list;
        list = list->next;
    }
    
    return NULL;
}

/**
* @PARAM: List list: puntatore alla testa lista da leggere
* @PARAM: int index: indice del nodo da leggere
* @RETURN: Il valore del nodo presente all'indice indicato, 0 se non esiste
*/
int getValueIndex(List list, int index) {
    List node = getNodeIndex(list, index);
    if (node == NULL) {
        return FALSE;
    } else {
        return node->data;
    }
}

/**
* @PARAM: List list: puntatore alla testa della List su cui operare
* @PARAM: int index: posizione in cui inserire l'elemento (>0)
* @RETURN: TRUE(1) se la rimozione è avvenuta con successo, altrimenti FALSE(0)
* @NOTE: Non puoi rimuovere la testa con questo metodo, usa piuttosto pullNode()
*/
int removeNodeIndex(List list, int index) {
    if (list == NULL || index < 1) return FALSE;
    
    int i;
    for (i = 1; list->next != NULL; i++) {
        if (i == index) {
            List node = list->next;
            list->next = node->next;
            free(node);
            return TRUE;
        }
        list = list->next;
    }
    
    return FALSE;   // Elemento non trovato
}

/**
* @PARAM: List list1: puntatore alla testa della prima List da concatenare
* @PARAM: List list2: puntatore alla testa della seconda List da concatenare
* @RETURN: Puntatore alla testa della nuova lista
*/
List concatList(List list1, List list2) {
    List head = NULL;
    List tail = NULL;
    
    while (list1 != NULL) {
        if (head == NULL) {
            head = createNullNode(list1->data);
            tail = head;
        } else {
            tail = tail->next = createNullNode(list1->data);
        }
        list1 = list1->next;
    }
    
    while (list2 != NULL) {
        if (head == NULL) {
            head = createNullNode(list2->data);
            tail = head;
        } else {
            tail = tail->next = createNullNode(list2->data);
        }
        list2 = list2->next;
    }
    
    return head;
}