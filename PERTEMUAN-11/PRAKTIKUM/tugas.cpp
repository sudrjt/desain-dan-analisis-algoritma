#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>


using namespace std;

const int INF = numeric_limits<int>::max();

struct Edge {
    int to;
    int weight;

    Edge(int t, int w) : to(t), weight(w) {}
};

pair<vector<int>, vector<int> > dijkstra(int startNode, int numNodes, const vector<vector<Edge> >& adj) {
    vector<int> dist(numNodes + 1, INF);
    vector<int> parent(numNodes + 1, 0);

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    dist[startNode] = 0;
    pq.push(make_pair(0, startNode));

    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u]) {
            continue;
        }

        for (vector<Edge>::const_iterator it = adj[u].begin(); it != adj[u].end(); ++it) {
            const Edge& edge = *it;
            int v = edge.to;
            int weight = edge.weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return make_pair(dist, parent);
}

void printPath(int startNode, int endNode, const vector<int>& parent) {
    if (endNode == startNode) {
        cout << startNode;
        return;
    }
    if (parent[endNode] == 0) {
        cout << "No path";
        return;
    }

    vector<int> path;
    int current = endNode;
    while (current != 0) {
        path.push_back(current);
        if (current == startNode) break;
        current = parent[current];
    }
    reverse(path.begin(), path.end());

    for (size_t i = 0; i < path.size(); ++i) {
        cout << path[i];
        if (i < path.size() - 1) {
            cout << " -> ";
        }
    }
}


int main() {
    int numNodes = 6;

    vector<vector<Edge> > adj(numNodes + 1);

    adj[1].push_back(Edge(2, 7));
    adj[1].push_back(Edge(3, 9));
    adj[1].push_back(Edge(6, 14));

    adj[2].push_back(Edge(1, 7));
    adj[2].push_back(Edge(3, 10));
    adj[2].push_back(Edge(4, 15));

    adj[3].push_back(Edge(1, 9));
    adj[3].push_back(Edge(2, 10));
    adj[3].push_back(Edge(4, 11));
    adj[3].push_back(Edge(6, 2));

    adj[4].push_back(Edge(2, 15));
    adj[4].push_back(Edge(3, 11));
    adj[4].push_back(Edge(5, 6));

    adj[5].push_back(Edge(4, 6));
    adj[5].push_back(Edge(6, 9));

    adj[6].push_back(Edge(1, 14));
    adj[6].push_back(Edge(3, 2));
    adj[6].push_back(Edge(5, 9));

    int startNode = 1;

    pair<vector<int>, vector<int> > result = dijkstra(startNode, numNodes, adj);
    vector<int> distances = result.first;
    vector<int> parents = result.second;

    cout << "Shortest distances from Node " << startNode << ":\n";
    for (int i = 1; i <= numNodes; ++i) {
        cout << "To Node " << i << ": ";
        if (distances[i] == INF) {
            cout << "No path\n";
        } else {
            cout << distances[i] << " (Path: ";
            printPath(startNode, i, parents);
            cout << ")\n";
        }
    }

    return 0;
}
