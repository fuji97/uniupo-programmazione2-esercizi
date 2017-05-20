#include <stdio.h>
#include <list.h>

/*
List foo(List l1) {
    List out = NULL;
    List tail = NULL;
    
    if (l1 == NULL)
        return NULL;
        
    if (l1->next == NULL)
        return out;
        
    while(l1->next->next != NULL) {
        if (l1->data == l1->next->data + l1->next->next->data) {
            List p = createNode();
            p->data = l1->data;
            p->next = NULL;
            if (out == NULL) {
                out = p;
                tail = out;
            } else {
                tail->next = p;
                tail = tail->next;
            }
        }
        l1 = l1->next;
    }
    
    return out;
}

List commonValueOrderedList(List l1, List l2) {
    if (l1 == NULL || l2 == NULL) {
        return NULL;
    }
    
    if (l1->data == l2->data) {
        List node = createNode();
        node->data = l1->data;
        node->next = commonValueOrderedList(l1->next, l2->next);
        return node;
    } else if (l1->data > l2->data) {
        return commonValueOrderedList(l1, l2->next);
    } else {
        return commonValueOrderedList(l1->next, l2);
    }
}

int main_old() {

    int arr1[] = {1, 3, 5, 6, 9, 37};
    int size1 = 6;
    int arr2[] = {2, 3, 7, 9, 17, 22, 37};
    int size2 = 7;
    
    List list1 = createListFromArray(arr1, size1);
    List list2 = createListFromArray(arr2, size2);
    printList(commonValueOrderedList(list1, list2));

    
    List l1 = listFromFile("data/uno.txt");
    List l2 = listFromFile("data/due.txt");
    printList(l1);
    printList(l2);
    
    List somma = NULL;
    List sommaTail = NULL;
    
    while(l1 != NULL) {
        if (somma == NULL) {
            somma = createNode();
            somma->data = l1->data + l2->data;
            somma->next = NULL;
            sommaTail = somma;
        } else {
            sommaTail = sommaTail->next = createNode();
            sommaTail->data = l1->data + l2->data;
            sommaTail->next = NULL;
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    
    printList(somma);
    listToFile(somma, "data/risultato.txt");
}
*/

int main() {
    int arr1[] = {1, 3, 5, 6, 9, 37};
    int size1 = 6;
    int arr2[] = {2, 3, 7, 9, 17, 22, 37};
    int size2 = 7;
    
    List list1 = createListFromArray(arr1, size1);
    List list2 = createListFromArray(arr2, size2);
    printList(list1);
    pushNode(&list1, 7);
    printList(list1);
    printf("Elemento pullato: %d\n", pullNode(&list1)->data);
    printList(list1);
    addNodeToIndex(list1, 3, 55);
    printList(list1);
    printf("Elemento all'indice 4: %d\n",getNodeIndex(list1, 4)->data);
    printf("Elemento all'indice 4 (diretto): %d\n",getValueIndex(list1, 4));
    removeNodeIndex(list1, 2);
    printList(list1);
    List concat = concatList(list1, list2);
    printList(concat);
}