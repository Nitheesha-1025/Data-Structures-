#include <iostream>
#include <vector>
using namespace std;
class graph{
    private:
    int v;
    vector<vector<pair<int,int>>> adj;
    vector<tuple<int,int,int>> edge;
    public:
    graph(int vertices):v(vertices){
        adj.resize(v);
    }
    int addedge(int,int,int);
    int prims();
    int findparent(vector<int>& parent,int u);
    int kruskals();
    int dijksta(int src);
};
int main(){
    int vertices;
    cout<<"Enter number of vertices:";
    cin>>vertices;
    graph g1(vertices);
    while(1){
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Add Edge\n";
        cout << "2. Prim's MST\n";
        cout << "3. Kruskal's MST\n";
        cout << "4. Dijkstra's Shortest Path\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            int u, v, w;
                cout << "Enter edge (u v weight): ";
                cin >> u >> v >> w;
                g1.addedge(u,v,w);
                break;
            case 2:
            g1.prims();
            break;
            case 3:
            g1.kruskals();
            break;
            case 4:
            int src;
            cout << "Enter source vertex: ";
            cin >> src;
            g1.dijksta(src);
            break;
            case 5:
            return 0;
            default:
            cout<<"Invalid choice\n";
        }
    }
    return 0;
}
int graph:: addedge(int u,int V,int w){
    if(u>=v || V>=v || u<0 || V<0){
        cout<<"Invalid vertex\n";
        return 0;
    }
    adj[u].push_back({V,w});
    adj[V].push_back({u,w});
    edge.push_back({u,V,w});
    return 1;
}
int graph::prims(){
    vector <bool> visited(v.false);
    vector <int>parent(v,-1);
    vector<bool> key(v,INF);
    key[0] = 0;
    pq.push({0,0});
    while(!pq.empty(())){
        int u = pq.top().second;
        pq.pop();
        if(visted[u]) {
            continue;
        }
        visited[u] = true;
        for(auto [h,weight] : adj[u]){
            if(!visited[h] && weight < key[h]){
                key[h] = weight;
                parent[h] = u;
                pq.push({key[h],h});
            }
        }
    }
}
int graph::findparent(vector<int>& parent,int u){
    if(parent[u] != u){
        parent[u] = findparent(parent,parent[u]);
    }
    return parent[u];
}
int graph::kruskals(){
    sort(edges.begin(),edges.end());
    vector<int> parent(v);
    for(int i=0;i<v;i++){
        parent[i] = i;
    }
    vector <pair<int,int>> mst;
    for(auto [w,u,v] :edges){
        int pu = findparent(parent,u);
        int pv = findparent(parent,v);
        if(pu != pv){
            mst.push_back({u,v});
            parent[pu] = pv;
        }
    }
}
int graph::dijksta(int src){
    if(src >= v || src < 0){
        cout<<"Invalid source vertex\n";
        return;
    }
    vector <int> dist(v,INF);
    dist[src] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
    pq.push({0,src});
    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        for(auto[v,w];adj[u]){
            if(dist[v] > d+w){
                dist[v] = d+w;
                pq.push({dist[v],v});
            }
        }
    }
}