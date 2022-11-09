#include <iostream>
using namespace std;

struct Node {
    string n;
    Node* next;
};

struct Queue {
    Node* front, *rear;
    unsigned size;
};

void init(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
    queue->size = 0;
}

bool isEmpty(Queue *queue) {
  return (queue->front == NULL && queue->rear == NULL);
}

void push(Queue *queue, string value) {
  Node* newNode = new Node;
  if (newNode) {
    queue->size++;
    newNode->n = value;
    newNode->next = NULL;
    
    if (isEmpty(queue))                 
      queue->front = queue->rear = newNode;
    else {
      queue->rear->next = newNode;
      queue->rear = newNode;
    }
  }
}

void pop(Queue *queue) {
    if(!isEmpty(queue)) {
        Node *temp = queue->front;
        queue->front = queue->front->next;
        free(temp);

        if(queue->front == NULL) {
            queue->rear = NULL;
        }
        queue->size--;
    }
}

void printQueue(Queue *teller, Queue *cs) {
    cout << endl;
    Node* current = teller->front;
    int count = 1;
    while(current != NULL) {
        cout << current->n << " dilayani pada teller urutan ke " << count <<endl;
        current = current->next;
        count++;
    }
    cout << endl;
    current = cs->front;
    count = 1;
    while(current != NULL) {
        cout << current->n << " dilayani pada cs urutan ke " << count <<endl;
        current = current->next;
        count++;
    }
}

int main() {
    Queue teller;
    init(&teller);
    Queue cs;
    init(&cs);
    int x;
    cin >> x;
    while(x--){
        string n, m;
        cin >> n;
        cin >> m;
        if(m == "teller") push(&teller, n);
        else push(&cs, n);
    }
    printQueue(&teller, &cs);
    return 0;
}