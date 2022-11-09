#include <iostream>
using namespace std;

// node
struct Node {
  string label;
  Node *left, *right;
};

// variabel pointer global
Node *root, *newNode;

void createNewTree(string label) {
    root = new Node();
    root->label = label;
    root->left = NULL;
    root->right = NULL;
}

// insert Left
Node *insertLeft(string label, Node *node) {
    newNode = new Node();
    newNode->label = label;
    newNode->left = NULL;
    newNode->right = NULL;
    node->left = newNode;
    return newNode;
}

// insert right
Node *insertRight(string label, Node *node) {
    newNode = new Node();
    newNode->label = label;
    newNode->left = NULL;
    newNode->right = NULL;
    node->right = newNode;
    return newNode;
}

// update
void update(string label, Node *node) {
    string temp = node->label;
    node->label = label;
    cout << "\nUbah node " << temp << " menjadi " << label << endl;
}

// Tranversal
// preOrder
void preOrder(Node *node = root) {
    if( node != NULL ){
      cout << node->label << ", ";
      preOrder(node->left);
      preOrder(node->right);
    }
}

// inOrder
void inOrder(Node *node = root) {
    if( node != NULL ){
      inOrder(node->left);
      cout << node->label << ", ";
      inOrder(node->right);
    }
}

// postOrder
void postOrder(Node *node = root) {
    if( node != NULL ){
      postOrder(node->left);
      postOrder(node->right);
      cout << node->label << ", ";
    }
}

int main() {
  createNewTree("Wareng");

  Node *nodeB, *nodeC, *nodeD, *nodeE, *nodeF, *nodeG, *nodeH, *nodeI, *nodeJ, *nodeK;
  nodeB = insertLeft("Alwi + Chulasoh", root);
  nodeC = insertRight("Canggah", root);
  nodeD = insertLeft("Abdul Manan + Rugayah", nodeB);
  nodeE = insertRight("Buyut", nodeB);
  nodeF = insertLeft("Bunyamin + Salamah", nodeE);
  nodeG = insertRight("Umi Kulsum + Rasiwan", nodeE);
  nodeH = insertLeft("Agus + Arlina", nodeG);
  nodeI = insertRight("Sugeng + Sairurotun", nodeG);
  nodeJ = insertLeft("Ilham", nodeH);
  nodeK = insertRight("Oziel", nodeH);
  
  cout << "\nPreOrder :" << endl;
  preOrder();
  cout << "\n" << endl;
  cout << "InOrder :" << endl;
  inOrder();
  cout << "\n" << endl;
  cout << "PostOrder :" << endl;
  postOrder();
  cout << "\n" << endl; 

  update("Chunainah + Masduki", nodeE);

  cout << "\nPreOrder :" << endl;
  preOrder();
  cout << "\n" << endl;
  cout << "InOrder :" << endl;
  inOrder();
  cout << "\n" << endl;
  cout << "PostOrder :" << endl;
  postOrder();
  cout << "\n" << endl;  
}