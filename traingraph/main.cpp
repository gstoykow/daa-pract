#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void add_edge(vector<int> graph[], int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void init_graph(vector<int> graph[], int E)
{
    for (int i = 0; i < E ; i++) {
        int u, v;
        cin >> u >> v;
        add_edge(graph,u,v);
    }
}

bool BFS(vector<int> graph[], int sv, int d, int V, int pred[], int dist[])
{
   queue<int> q;

   bool visited[V];

    for (int i = 0; i < V ; ++i) {
        visited[i] = false;
        pred[i] = -1;
        dist[i] = 999999;
    }

    dist[sv] = 0;
    visited[sv] = true;

    q.push(sv);

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i = 0; i < graph[u].size() ; i++)
        {
            int v = graph[u][i];

            if(visited[v] == false)
            {
                visited[v] = true;
                dist[v] = dist[u] + 1;
                pred[v] = u;

                q.push(v);

                if(v == sv) return true;
            }
        }

    }

    return false;
}

void shortest_distance(vector<int> graph[], int sv, int d, int V)
{
    int pred[V];
    int dist[V];

    if(!BFS(graph,sv,d,V,pred,dist))return;

    vector<int> path;
    int c = d;
    while(pred[c] != -1)
    {
        path.push_back(pred[c]);
        c = pred[c];
    }

    cout << "Shortest path length is : "
         << dist[d];

    cout << "\nPath is::\n";
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << " ";

}

void DFS(vector<int> graph[], int s, bool visited[])
{
    if(visited[s]) return;

    visited[s] = true;

    for(int i = 0; i < graph[s].size(); i++)
    {
        int v = graph[s][i];
        DFS(graph,v,visited);
    }
}

int sgcount (vector<int> graph[], int V)
{
    bool visited[V];

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
    }

    int t = 0;

    for(int i = 0; i < V ; i++)
    {
        if(!visited[i])
        {
            t++;
            DFS(graph,i,visited);
        }
        else i++;
    }

    return t;
}

int main() {

    //int V, E;
    //cin>>V >> E;

    cout<<(0 || 1);

    //vector<int> graph[V];
    //init_graph(graph,E);

    //cout<<sgcount(graph,V);
    //hortest_distance(graph,0,V-1,V);


    return 0;
}