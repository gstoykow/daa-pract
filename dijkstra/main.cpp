#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> Conn;
typedef pair<ll, vector<Conn> > node;
#define MAX_N 10001
#define MAX_M 100001

struct orderByCost
{
    bool operator()(Conn const &c1, Conn const &c2)
    {
        return c1.second > c2.second;
    }
};

void print_path(vector<ll>& parents, ll from,ll counter=0)
{
 if(from == -1) {
     cout<<counter<<endl;
     return ;
 }
    print_path(parents,parents[from],counter+1);
    cout<<from<<" ";
}

void dijkstra(vector<node> &graph)
{

    vector<bool> visited(graph.size());

    vector<ll> parents(graph.size());

    vector<ll> curr_ws(graph.size());

    for (ll i = 0; i < graph.size(); i++){
        curr_ws[i] = LONG_MAX;
        parents[i] = -1;
    }

    curr_ws[0] = 0;


    priority_queue<Conn, vector<Conn>, orderByCost> pq;

    pq.push({0, 0});

    while (!pq.empty()) {
        Conn next = pq.top();
        pq.pop();
        ll U = next.first, w = next.second;
        visited[U] = true;

        for (ll i = 0; i < graph[U].second.size(); i++) {
            Conn link = graph[U].second[i];

            ll V = link.first;
            ll W = link.second;

            ll setaa =  w + W + (((w % graph[U].first) == 0) ? 0 :(graph[U].first - (w % graph[U].first)));
            if (visited[V] == false && curr_ws[V] > setaa) {
                curr_ws[V] = setaa;
                parents[V] = U;
                pq.push({V, curr_ws[V]});
            }
        }
    }

    ll curr = graph.size() -1;

    if(parents[curr] == -1){
        cout<<-1<<endl;
    }else{
        cout<<curr_ws[curr]<<endl;
        print_path(parents,graph.size()-1);
    }

}

int main()
{

    ll N, M;

    cin >> N >> M;
    vector<node> data(N);

    for (ll i = 0; i < N; i++) {
        ll K;
        cin >> K;
        data[i] = {K, vector<Conn>()};
    }


    for (ll i = 0; i < M; i++) {
        ll U, V, W;
        cin >> U >> V >> W;
        data[U].second.push_back({V, W});
    }

    dijkstra(data);

    return 0;
}