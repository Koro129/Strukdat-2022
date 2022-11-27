#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    bool** adjMatrix;
    int numVertices;
    string name[21] = {"Rumah", "Bangsri Car Wash", "Saung Teras Banyu", "Sekolah Tahfidz Plus", "Bakso Geger", "Aziz Rent Car", "Nasi Goreng", "Umahe Kopet", "Bengkel Baladika", "Masjid Jamie", "Ayam Geprek Bilal", "Ayam Geprek Ladziz", "Sumber Alfaria", "Kost Putri Iqbal", "Kost Pink", "Kedai Bismilah", "Super Mini", "Rizqi Cell", "TPQ", "PT SMJ", "PT TJE"};
    
public:
    // Initialize the matrix to zero
    Graph(int numVertices) {
        this->numVertices = numVertices;
        adjMatrix = new bool*[numVertices];
        for (int i = 0; i < numVertices; i++) {
            adjMatrix[i] = new bool[numVertices];
            for (int j = 0; j < numVertices; j++)
                adjMatrix[i][j] = false;
        }
      }
      
    void showName() {
        for(int i = 0; i < 21; i ++) cout << i << " = " << name[i] << endl;
    }
    
    // Add edges
    void addEdge(int i, int j) {
        adjMatrix[i][j] = true;
    }
    
    // Remove edges
    void removeEdge(int i, int j) {
        adjMatrix[i][j] = false;
    }
    
      // Print the martix
    void toString() {
        for (int i = 0; i < numVertices; i++) {
            cout << i << "\t: ";
            for (int j = 0; j < numVertices; j++) cout << adjMatrix[i][j] << " ";
            cout << "\n";
        }
    }
      
    void bfs(int s, int d) {
        vector<bool> visited(numVertices, false);
        vector<int> q;
        q.push_back(s);
        
        visited[s] = true;
        
        while (!q.empty()) {
            s = q[0];
            cout << name[s] << endl;
            if(s == d) return;
            q.erase(q.begin());
            for (int i = 0; i < numVertices; i++) {
                if (adjMatrix[s][i] == 1 && (!visited[i])) {
                    q.push_back(i);
                    visited[i] = true;
                }
            }
        }
    }
    ~Graph() {
        for (int i = 0; i < numVertices; i++) delete[] adjMatrix[i];
        delete[] adjMatrix;
    }
};

int main() {
    Graph g(21);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(4, 6);
    g.addEdge(4, 8);
    g.addEdge(6, 7);
    g.addEdge(8, 9);
    g.addEdge(9, 10);
    g.addEdge(10, 11);
    g.addEdge(10, 12);
    g.addEdge(11, 12);
    g.addEdge(11, 15);
    g.addEdge(11, 16);
    g.addEdge(12, 13);
    g.addEdge(12, 15);
    g.addEdge(13, 14);
    g.addEdge(16, 15);
    g.addEdge(16, 17);
    g.addEdge(17, 18);
    g.addEdge(17, 19);
    g.addEdge(19, 1);
    g.addEdge(19, 20);
    
    while(true){
        int x;
        cout << "1. List Node\n2. Adjacency Matrix\n3. Breadth First Search\nInput: ";
        cin >> x;
        if(x == 1) {
            cout << "List Node" << endl;
            g.showName();
        }
        else if(x == 2){
            cout << "Adjacency Matrix" << endl;
            g.toString();
        }
        else if(x == 3){
            cout << "Breadth First Search from Rumah\nDestination: ";
            int d;
            cin >> d;
            g.bfs(0, d);
        }
    }

}