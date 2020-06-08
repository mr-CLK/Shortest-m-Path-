#include "path.h"

void path::addEdge(vector <pair<int, int> > adj[], int u,
    int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

void path::shortestPath(vector<pair<int, int> > adj[], int V, int src)
{
    priority_queue< iPair, vector <iPair>, greater<iPair> > pq;

    vector<int> dist(V, MAX);

    pq.push(make_pair(0, src));
    dist[src] = 0;

    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();

        for (auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[u] + weight)
            {
                dist[v] = dist[u] + weight;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    printf("Vertex Distance from Source\n");
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);
}