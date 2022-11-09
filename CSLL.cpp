#include <iostream>
using namespace std;

struct Node{
    int n;
    Node *next;
};

struct List{
    Node *head;
    Node *tail;
};
Node *cur;
void init(List *list){
    list->head = NULL;
    list->tail = list->head;
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

void addFirst(List *list, int n){
    Node *newNode = new Node;
    newNode->n = n;
    newNode->next = list->head;
    list->head = newNode;
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
        cur->next = newNode;
    }
}

void addLast(List *list, int n){
    Node *newNode = new Node;
    newNode->n = n;
    newNode->next = NULL;
    if (list->head == NULL){
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
        list->tail->next = list->head;
    }
}

int main(){
    List list;
    init(&list);
    addLast(&list, 1);
    addFirst(&list, 2);
    addLast(&list, 3);
    addMid(&list, 4, 3);
    addLast(&list, 5);
    printL(&list);
}