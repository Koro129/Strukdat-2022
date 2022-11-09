#include <iostream>
using namespace std;

struct Node{
    int n;
    Node *next;
    Node *prev;
};

struct List{
    Node *head;
    Node *tail;
};
Node *cur;
void init(List *list){
    list->head = NULL;
    list->tail = NULL;
}

int countL(List *list){
    int count = 0;
    cur = list->head;
     do{
        count++;
        cur = cur->next;    
    }
    while(cur != list->head);
    return count;
}

void printL(List *list){
    cout << "[";
    cur = list->head;
    do{
        if(cur->next == list->head ) cout << cur->n << "]"<< endl;
        else cout << cur->n << ", ";
        cur = cur->next;
    }
    while(cur != list->head);
}

void printRev(List *list){
    cout << "[";
    cur = list->tail;
    do{
        if(cur->prev == list->tail ) cout << cur->n << "]"<< endl;
        else cout << cur->n << ", ";
        cur = cur->prev;
    }
    while(cur != list->tail);
}

void addFirst(List *list, int n){
    Node *newNode = new Node;
    newNode->n = n;
    newNode->next = list->head;
    newNode->prev = list->tail;
    list->head->prev = newNode;
    list->head = newNode;
    list->tail->next = list->head;
}

void addMid(List *list, int n, int pos){
    if(pos < 1 || pos > countL(list)) cout << "Tidak ada posisi tersebut" << endl;
    else if(pos == 1) cout << "Bukan posisi tengah" << endl;
    else{
        Node *newNode = new Node();
        newNode->n = n;
        
        //Transversing
        int count = 1;
        cur = list->head;
        while (count < pos-1){
            cur = cur->next;
            count++;
        }
        newNode->next = cur->next;
        newNode->prev = cur;
        cur->next->prev = newNode;
        cur->next = newNode;
    }
}

void addLast(List *list, int n){
    Node *newNode = new Node;
    newNode->n = n;
    newNode->next = list->head;
    newNode->prev = list->tail;
    if (list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
        list->head->prev = list->tail;
    }
}

int main(){
    List list;
    init(&list);
    addLast(&list, 1);
    addLast(&list, 2);
    addFirst(&list, 3);
    addMid(&list, 4, 2);
    addLast(&list, 5);
    printL(&list);
    printRev(&list);
}