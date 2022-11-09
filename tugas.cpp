// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

// Adjacency Matrix representation in C

#include <stdio.h>
#define V 5

// Initialize the matrix to zero
void init(int arr[][V]) {
  int i, j;
  for (i = 0; i < V; i++)
    for (j = 0; j < V; j++)
      arr[i][j] = 0;
}

// Add edges
void addEdge(int arr[][V], int i, int j) {
  arr[i][j] = 1;
  arr[j][i] = 1;
}

// Print the matrix
void printAdjMatrix(int arr[][V]) {
  int i, j;

  for (i = 0; i < V; i++) {
    cout << i << ": ";
    for (j = 0; j < V; j++) {
      cout << arr[i][j];
    }
    cout << endl;
  }
}

int main() {
  int adjMatrix[V][V];

  init(adjMatrix);
  addEdge(adjMatrix, 0, 1);
  addEdge(adjMatrix, 0, 2);
  addEdge(adjMatrix, 0, 3);
  addEdge(adjMatrix, 1, 2);
  addEdge(adjMatrix, 1, 4);
  addEdge(adjMatrix, 2, 3);
  addEdge(adjMatrix, 2, 4);
  addEdge(adjMatrix, 3, 4);

  printAdjMatrix(adjMatrix);

  return 0;
}