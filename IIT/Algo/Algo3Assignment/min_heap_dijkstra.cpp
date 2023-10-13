#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = INT_MAX;

struct Edge {
    int to;
    int weight;

    Edge(int _to, int _weight) : to(_to), weight(_weight) {}
};

void insert(vector<int> &heap, int x) {
    // Insert element at end
    heap.push_back(x);

    // Adjust the heap
    int index = heap.size() - 1;
    while (index >= 1) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        } else
            return;
    }
}

void extract_min(vector<int> &heap) {
    // Swap first node with last node
    int size = heap.size();

    // Check for an empty heap
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return;
    }

    int temp = heap[0];
    heap[0] = heap[size - 1];
    heap[size - 1] = temp;

    // Pop last element
    heap.pop_back();
    size = heap.size();

    // Adjust the heap
    int index = 0;

    while (index < (size / 2)) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        if (left < size && (heap[index] > heap[left] || (right < size && heap[index] > heap[right]) && heap[left] < heap[right])) {
            int t = heap[index];
            heap[index] = heap[left];
            heap[left] = t;
            index = left;
        } else if (right < size && heap[index] > heap[left] && heap[index] > heap[right]) {
            int t = heap[index];
            heap[index] = heap[right];
            heap[right] = t;
            index = right;
        } else
            return;
    }
    return;
}

void decrease_key(vector<int> &heap, int index, int x) {
    if (index >= heap.size())
        return;
    heap[index] = x;

    // Adjust the heap
    while (index >= 1) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            int temp = heap[parent];
            heap[parent] = heap[index];
            heap[index] = temp;
            index = parent;
        } else
            return;
    }
}

void delete_val(vector<int> &heap, int index) {
    decrease_key(heap, index, INT_MIN);
    extract_min(heap);
}

vector<int> dijkstra(vector<vector<Edge>>& graph, int start) {
    int n = graph.size();
    vector<int> distance(n, INF);
    vector<bool> visited(n, false);

    // Create a custom min-heap using your functions
    vector<int> heap;

    distance[start] = 0;
    insert(heap, start);

    while (!heap.empty()) {
        int u = heap[0];
        extract_min(heap);

        if (visited[u]) continue;
        visited[u] = true;

        for (const Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;

            if (distance[u] + weight < distance[v]) {
                distance[v] = distance[u] + weight;
                insert(heap, v);
            }
        }
    }
    return distance;
}


int main() {
    int n, m;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);

    cout << "Enter the edges (from to weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        graph[from].emplace_back(to, weight);
    }

    int start;
    cout << "Enter the starting node: ";
    cin >> start;

    vector<int> distances = dijkstra(graph, start);

    cout << "Shortest distances from node " << start << " to all other nodes:" << endl;
    for (int i = 0; i < n; ++i) {
        if (distances[i] == INF) {
            cout << "Node " << i << ": Infinity" << endl;
        } else {
            cout << "Node " << i << ": " << distances[i] << endl;
        }
    }

    return 0;
}
/*
Sample input : 

no of node : 5
no of edges : 8

0 1 3
0 2 1
1 2 2
1 3 1
2 3 2
1 4 1
3 4 6
2 4 1
Enter the starting node: 0

sample output :

Shortest distances from node 0 to all other nodes:
Node 0: 0
Node 1: 3
Node 2: 1
Node 3: 3
Node 4: 2
*/