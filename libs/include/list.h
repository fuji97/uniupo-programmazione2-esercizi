#ifndef _LIST_H_
#define _LIST_H_

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* next;
} *List;

List createNode();
List createListFromArray(int arr[], int size);
void printList(List list);
List listFromFile(char path[]);
void listoToFile(List list, char path[]);
List pushNode(List *list, int val);
List pullNode(List *list);
List addNodeToIndex(List list, int index, int val);
List getNodeIndex(List list, int index);
int getValueIndex(List list, int index);
int removeNodeIndex(List list, int index);
List concatList(List list1, List list2);

#endif