#include<bits/stdc++.h>
using namespace std;

class Graph{
private:
    int V;
    vector<list<int>> adj;
    string name[21] = {"Rumah", "Bangsri Car Wash", "Saung Teras Banyu", "Sekolah Tahfidz Plus", "Bakso Geger", "Aziz Rent Car", "Nasi Goreng", "Umahe Kopet", "Bengkel Baladika", "Masjid Jamie", "Ayam Geprek Bilal", "Ayam Geprek Ladziz", "Sumber Alfaria", "Kost Putri Iqbal", "Kost Pink", "Kedai Bismilah", "Super Mini", "Rizqi Cell", "TPQ", "PT SMJ", "PT TJE"};
public:
    Graph(int V){
        this->V = V;
        adj.resize(V);
    }
    
    void showName() {
        cout << "List Node" << endl;
        for(int i = 0; i < 21; i ++) cout << i << " = " << name[i] << endl;
    }
    
    void addEdge(int v, int w){
        adj[v].push_back(w);
    }
    
    void toPrint() {
        cout << "Adjacency List" << endl;
        for (int i = 0; i < V; i++) {
            cout << i << " --> ";
            for (auto adjecent: adj[i]) cout << adjecent << " ";
        cout << "/\n";
        }
    }

    void bfs(int s, int d) {
        vector<bool> visited;
        visited.resize(V,false);

        list<int> queue;
     
        visited[s] = true;
        queue.push_back(s);
     
        while(!queue.empty()){
            s = queue.front();
            cout << name[s] << endl;
            if (s == d) return;
            queue.pop_front();
            for (auto adjecent: adj[s]){
                if (!visited[adjecent]){
                    visited[adjecent] = true;
                    queue.push_back(adjecent);
                }
            }
        }
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
        cout << "1. List Node\n2. Adjacency List\n3. Breadth First Search\nInput: ";
        cin >> x;
        if(x == 1) {
            g.showName();
        }
        else if(x == 2){
            g.toPrint();
        }
        else if(x == 3){
            cout << "Breadth First Search from Rumah\nDestination: ";
            int d;
            cin >> d;
            g.bfs(0, d);
        }
    }
 
    return 0;
}
