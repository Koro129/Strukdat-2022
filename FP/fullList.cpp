#include<bits/stdc++.h>
using namespace std;

class Graph {
private:
    clock_t startTime, endTime;
    int V;
    vector<list<int>> adj;
    map<pair<int,int>, int> weight;
    vector<int> data;
    vector<int> dist;
    vector<int> shortest;
    string name[21] = {"Rumah", "Bangsri Car Wash", "Saung Teras Banyu", "Sekolah Tahfidz Plus", "Bakso Geger", "Aziz Rent Car", "Nasi Goreng", "Umahe Kopet", "Bengkel Baladika", "Masjid Jamie", "Ayam Geprek Bilal", "Ayam Geprek Ladziz", "Sumber Alfaria", "Kost Putri Iqbal", "Kost Pink", "Kedai Bismilah", "Super Mini", "Rizqi Cell", "TPQ", "PT SMJ", "PT TJE"};
public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    
    void showName() {
        cout << "List Node" << endl;
        for(int i = 0; i < 21; i ++) cout << i << " = " << name[i] << endl;
    }
    
    void addEdge(int u, int v, int w) {
        adj[u].push_back(v);
        weight.insert({make_pair(u,v), w});
    }
    
    int minDist(vector<int> dist, vector<bool> vis) {
            int min = INT_MAX;
            int min_index = INT_MAX;
            for (int i = 0; i < V; i++)
            {
                if(!vis[i] && dist[i] < min) {
                    min = dist[i];
                    min_index = i;
                }
            }

            return min_index;
        }

    void dijkstra(int source, int flag) {
        dist.resize(V, INT_MAX);
        data.resize(V, 0);
        vector<bool> vis (V, false);
        
        dist[source] = 0;

        for (int itv = 0; itv < V ; itv++) {
            int min = minDist(dist, vis);
            vis[min] = true;
            list<int>::iterator it;
            for(it = adj[min].begin(); it != adj[min].end(); ++it) {
                if (
                    weight[make_pair(min, *it)] &&
                    !vis[*it] && 
                    dist[min] + weight[make_pair(min, *it)]  < dist[*it]
                    ) {
                    dist[*it] = dist[min] + weight[make_pair(min, *it)];
                    data[*it] = min;
                }
            }
        }
        if(flag) {
            cout << "to\tdist" << endl;
            for (int i = 0; i < V; i++) {
                cout << i << "\t";
                cout << dist[i] << endl;
            }
        }
    }

    void bfs(int source, int flag) {
        dist.resize(V, INT_MAX);
        data.resize(V, 0);
        vector<bool> visited;
        visited.resize(V,false);

        queue<int> q;
        
        dist[source] = 0;
        visited[source] = true;
        q.push(source);

        while(!q.empty()) {
            int cur = q.front();
            for (auto it: adj[cur]) {
                if(weight[make_pair(cur, it)] + dist[cur] < dist[it]){
                    dist[it] = weight[make_pair(cur, it)] + dist[cur];
                    data[it] = cur;
                    q.push(it);
                }
            }
            q.pop();
        }
        if(flag) {
            cout << "to\tdist" << endl;
            for (int i = 0; i < V; i++) {
                cout << i << "\t";
                cout << dist[i] << endl;
            }
        }
    }

    void dfs(int start, int end, vector<int> path, vector<bool> visited, int currWeight, int flag) {
        if(start == end) {
            path.push_back(end);
            if(currWeight < dist[end] ) {
                dist[end] = currWeight;
                shortest = path;
            }
                
            if(flag) {
                cout << currWeight << " ";
                for (int i = 0; i < path.size(); i++)
                    cout <<  path[i] << " ";
                cout << endl;
            }
        }
            
        visited[start] = true;
        path.push_back(start);
        list<int>::iterator it;
        for ( it = adj[start].begin(); it != adj[start].end(); it++) {
            if(!visited[*it]){
                int wtemp = currWeight;
                wtemp += weight[make_pair(start, *it)];
                dfs(*it, end, path, visited, wtemp, flag);
            }
        }
    }
    
    void shortestDijkstra(int start, int dest) {
        startTime = clock();
        dijkstra(start, 0);
        shortest.push_back(dest);
        int cur = dest;
        while(true) {
            shortest.push_back(data[cur]);
            cur = data[cur];
            if(cur == start) break;
        }
        cout << "Weight = " << dist[dest] << endl;
        toPrint(0);
    }
    
    void shortestBfs(int start, int dest) {
        startTime = clock();
        bfs(start, 0);
        shortest.push_back(dest);
        int cur = dest;
        while(true){
            shortest.push_back(data[cur]);
            cur = data[cur];
            if(cur == start) break;
        }
        cout << "Weight = " << dist[dest] << endl;
        toPrint(0);
    }
    
    void shortestDfs(int start, int dest, int flag) {
        startTime = clock();
        vector<int> path;
        vector<bool> visited (V, false);
        dist.resize(V, INT_MAX);
        data.resize(V, 0);
        if(!flag) dfs(start, dest, path, visited, 0, 1);
        else {
            dfs(start, dest, path, visited, 0, 0);
            reverse(shortest.begin(), shortest.end());
            toPrint(0);
        }
        
        
    }
    
    void toPrint(int flag) {
        if(flag) {
            cout << "Adjacency List" << endl;
            for (int i = 0; i < V; i++) {
                cout << i << " --> ";
                for (auto adjecent: adj[i]) 
                    cout << adjecent << "(" << weight[make_pair(i, adjecent)] << ") ";
            cout << "/\n";
            }
        }
        else {
            for (auto ir = shortest.rbegin(); ir != shortest.rend(); ++ir) cout << name[*ir] << endl;
            shortest.clear();
            dist.clear();
            data.clear();
            endTime = clock();
            double time_taken = double(endTime - startTime) / double(CLOCKS_PER_SEC);
            cout << "Time taken by program is : " << fixed << time_taken << setprecision(5);
            cout << " sec " << endl;
        }
    }
};


 
int main() {

    Graph g(21);
    g.addEdge(0, 4, 1);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(3, 0, 2);
    g.addEdge(4, 5, 3);
    g.addEdge(4, 6, 1);
    g.addEdge(4, 8, 3);
    g.addEdge(4, 16, 25);
    g.addEdge(6, 7, 1);
    g.addEdge(8, 9, 2);
    g.addEdge(9, 10, 3);
    g.addEdge(10, 11, 2);
    g.addEdge(10, 12, 1);
    g.addEdge(11, 12, 2);
    g.addEdge(11, 15, 1);
    g.addEdge(11, 16, 3);
    g.addEdge(12, 13, 1);
    g.addEdge(12, 15, 3);
    g.addEdge(13, 14, 2);
    g.addEdge(16, 15, 1);
    g.addEdge(16, 17, 2);
    g.addEdge(17, 18, 3);
    g.addEdge(17, 19, 2);
    g.addEdge(19, 1, 3);
    g.addEdge(19, 20, 1);
    
    while(true){
        int x;
        cout << "1. List Node\n2. Adjacency List\n3. Shortest Path with BFS\n4. Shortest Path with DFS\n5. Shortest Path with Dijkstra\nInput: ";
        cin >> x;
        if(x == 1) {
            g.showName();
        }
        else if(x == 2){
            g.toPrint(1);
        }
        else if(x == 3){
            cout << "Shortest Path with BFS\n";
            int start, dest;
            cout << "From: ";
            cin >> start;
            cout << "Destination: ";
            cin >> dest;
            g.shortestBfs(start, dest);
        }
        else if(x == 4){
            cout << "Shortest Path with DFS\n";
            int start, dest;
            cout << "From: ";
            cin >> start;
            cout << "Destination: ";
            cin >> dest;
            g.shortestDfs(start, dest, 1);
        }
        else if(x == 5){
            cout << "Shortest Path with Dijkstra\n";
            int start, dest;
            cout << "From: ";
            cin >> start;
            cout << "Destination: ";
            cin >> dest;
            g.shortestDijkstra(start, dest);
        }
    }
    
    return 0;
}