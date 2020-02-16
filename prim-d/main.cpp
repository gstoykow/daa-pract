#include <iostream>
#include <vector>
#include <iostream>
#include <climits>
#include <queue>

#define wu pair<int,int>

using namespace std;

void add_edge(vector<wu> graph[], int u, int w, int v)
{
    graph[v].emplace_back(make_pair(w,u));
    graph[u].emplace_back(make_pair(w,v));
}

void bford(vector<wu> graph[],int V, int E, int s)
{
    vector<int> dist(V,INT_MAX);

    dist[s] = 0;

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

}

void dijkstra(vector<wu> graph[], int V, int s)
{
    //vector<bool> visited(V,0);
    vector<int> dist(V , INT_MAX);

    priority_queue<wu,vector<wu>,greater<wu>> pq;

    dist[s] = 0;
    pq.push(make_pair(0,s));

    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for(int i = 0; i < graph[u].size(); i++)
        {
            int v = graph[u][i].second;
            int w = graph[u][i].first;

            if(dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v],v));
            }
        }
    }

    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

}

void prim(vector<wu> graph[], int V, int s) {
    vector<bool> visited(V, 0);
    vector<int> dist(V, INT_MAX);
    vector<int> parents(V, -1);

    priority_queue<wu, vector<wu >, greater<wu>> pq;

    dist[s] = 0;
    pq.push(make_pair(0, s));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        visited[u] = 1;

        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].second;
            int w = graph[u][i].first;

            if (visited[v] == 0 && dist[v] > w) {
                dist[v] = w;
                parents[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parents[i], i);
}



int main() {

    int V, E;
    cin >> V >> E;

    vector<wu> graph[V];

    for (int i = 0; i < E; ++i)
    {
    int u , w,  v;
    cin >> u >> w >> v;
    add_edge(graph, u, w, v);
    }

    prim(graph,V,0);

    return 0;
}