#include <iostream>
#include <queue>
#include <limits>

using namespace std;

#define MAX_VERTICES 100

struct Edge {
    int vertex;
    int weight;
};

struct Graph {
    int numVertices;
    Edge* adjList[MAX_VERTICES];
    int adjListSize[MAX_VERTICES];
};

void addEdge(Graph* graph, int src, int dest, int weight) {
    if (graph->adjListSize[src] == 0) {
        graph->adjList[src] = new Edge[1];
    } else {
        Edge* temp = new Edge[graph->adjListSize[src] + 1];
        for (int i = 0; i < graph->adjListSize[src]; i++) {
            temp[i] = graph->adjList[src][i];
        }
        delete[] graph->adjList[src];
        graph->adjList[src] = temp;
    }
    graph->adjList[src][graph->adjListSize[src]] = {dest, weight};
    graph->adjListSize[src]++;
}

void dijkstra(Graph* graph, int startVertex) {
    int distances[MAX_VERTICES];
    for (int i = 0; i < graph->numVertices; i++) {
        distances[i] = numeric_limits<int>::max();
    }
    distances[startVertex] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, startVertex});

    while (!pq.empty()) {
        int currentVertex = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        for (int i = 0; i < graph->adjListSize[currentVertex]; i++) {
            int neighbor = graph->adjList[currentVertex][i].vertex;
            int weight = graph->adjList[currentVertex][i].weight;

            if (currentDistance + weight < distances[neighbor]) {
                distances[neighbor] = currentDistance + weight;
                pq.push({distances[neighbor], neighbor});
            }
        }
    }

    // Print the shortest distances from the start vertex to all other vertices
    for (int i = 0; i < graph->numVertices; i++) {
        cout << "Shortest distance from vertex " << startVertex << " to vertex " << i << ": " << distances[i] << endl;
    }
}

int main() {
    // Create a sample graph
    Graph graph;
    graph.numVertices = 5;

    // Add edges to the graph
    addEdge(&graph, 0, 1, 4);
    addEdge(&graph, 0, 2, 1);
    addEdge(&graph, 1, 3, 1);
    addEdge(&graph, 2, 1, 2);
    addEdge(&graph, 2, 3, 5);
    addEdge(&graph, 3, 4, 3);

    // Run Dijkstra's algorithm
    dijkstra(&graph, 0);

    return 0;
}