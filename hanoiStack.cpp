#include <iostream>
using namespace std;

struct Node {
    int n;
    Node* next;
};

struct Stack {
    Node* top;
    unsigned size;
};

void init(Stack* stack) {
    stack->top = NULL;
    stack->size = 0;
}

bool isEmpty(Stack* stack) {
    return (stack->top == NULL);
}

void push(Stack* stack, int n) {
    Node* newNode = new Node;

    if(newNode) {
        newNode->n = n;

        if(isEmpty(stack)) newNode->next = NULL;
        else newNode->next = stack->top;

        stack->top = newNode;
        stack->size++;
    }
}

void pop(Stack *stack) {
    if(!isEmpty(stack)) {
        Node *temp = stack->top;
        stack->top = stack->top->next;
        free(temp);
        stack->size--;
    }
}

void display(Stack *stack1, Stack *stack2, Stack *stack3) {
    cout << "\n\nTiang 1: ";
    Node* current = stack1->top;
    while(current != NULL) {
        cout << current->n << " ";
        current = current->next;
    }
    cout << "\nTiang 2: ";
    current = stack2->top;
    while(current != NULL) {
        cout << current->n << " ";
        current = current->next;
    }
    cout << "\nTiang 3: ";
    current = stack3->top;
    while(current != NULL) {
        cout << current->n << " ";
        current = current->next;
    }
}

void hanoi(int n, Stack *from, Stack *to, Stack *aux, Stack *stack1, Stack *stack2, Stack *stack3){
    if(n==1){
        pop(from);
        push(to, n);
        display(stack1, stack2, stack3);
        return;
    }
    hanoi(n-1, from, aux, to, stack1, stack2, stack3);
    pop(from);
    push(to, n);
    display(stack1, stack2, stack3);
    hanoi(n-1, aux, to, from, stack1, stack2, stack3);
}

int main(){
    Stack tiang1;
    init(&tiang1);
    Stack tiang2;
    init(&tiang2);
    Stack tiang3;
    init(&tiang3);
    int n;
    cout << "Masukkan piring: ";
    cin >> n;
    for(int i=n; i>0; i--){
        push(&tiang1, i);
    }
    display(&tiang1, &tiang2, &tiang3);
    hanoi(n, &tiang1, &tiang3, &tiang2, &tiang1, &tiang2, &tiang3);
}