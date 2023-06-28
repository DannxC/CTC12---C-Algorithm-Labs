#include <TspSolver.h>
#include <queue>
#include <vector>
#include <stack>
#include <list>

// Edge class
class Edge {
public:
    int u, v, w; // u is from ; v is to ; w is weight

    // Constructor
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->w = w;
    }

    // This operator is defined to order edges in a priority queue.
    // It is reversed because in std::priority_queue, the element with the highest value is considered the highest priority.
    // - We prioritize edges with lower weights.
    // - For ties in weight, the edge from the vertex with a lower index has priority.
    // - If there is still a tie, the edge to the vertex with the lower index has priority.
    bool operator < (const Edge& other) const {
        if (this->w != other.w)
            return this->w > other.w; // Prioritize lower weight
        else if (this->u != other.u)
            return this->u > other.u; // If weights are equal, prioritize lower 'from' vertex index
        else
            return this->v > other.v; // If 'from' vertex indices are also equal, prioritize lower 'to' vertex index
    }
};


// Graph class (Undirected Graph)
class Graph {
public:
    std::vector<std::vector<Edge>> adjList;
    int numVertex;
    bool isTree;

    // Constructor with TspReader (this is for first graph with all cities connected)
    Graph(TspReader& reader) {
        this->numVertex = reader.getNumCities();
        this->isTree = false;

        std::vector<City> cities = std::vector<City>(numVertex);
        reader.copyCitiesVector(cities); // Copy all cities from the reader
        
        this->adjList.resize(this->numVertex); // Initialize adjacency list

        // Adding cities to our adjacency list
        for (int i = 0; i < this->numVertex; i++) {
            this->adjList[i].reserve(this->numVertex); // Reserve space for numVertex edges in each vector of the adjacency list
            for (int j = i + 1; j < this->numVertex; j++)
                this->addEdge(i, j, cities[i].disti(cities[j]));
        }
    }

    // Constructor with number of vertices (this is for the MST - minimum spanning tree)
    Graph(int numVertices) {
        this->numVertex = numVertices;
        this->isTree = false;
        this->adjList.resize(numVertex);
    }

    // Add edge (bi-dicrectional) into adjList (<u, v> and <v, u>) with weight w for both
    void addEdge(int u, int v, int w) {
        this->adjList[u].push_back(Edge(u, v, w)); // Add edge to list for u
        this->adjList[v].push_back(Edge(v, u, w)); // Add edge to list for v
    }

    // Prim Algorithm for minimum spanning tree
    // get MST from otherGraph
    void primMST(Graph& otherGraph) {
        std::vector<bool> visited(otherGraph.numVertex, false);
        std::priority_queue<Edge> pq;

        // Start from vertex 0
        visited[0] = true;
        for (Edge& edge : otherGraph.adjList[0])
            pq.push(edge);

        // Aux
        int count = 0;

        // Continue checking for MST's neighbor edges with the lowest weight values first
        while (!pq.empty()) {
            Edge neighborEdge = pq.top(); pq.pop();

            // Discard visited vertices - update their status if they haven't been visited yet
            if (visited[neighborEdge.v]) 
                continue;
            visited[neighborEdge.v] = true;
            count++;

            // Add edge to MST
            this->addEdge(neighborEdge.u, neighborEdge.v, neighborEdge.w);

            // Add all edges that connect to the latest vertex and have unvisited destinations to the priority queue
            for (Edge& edge : otherGraph.adjList[neighborEdge.v])
                if (!visited[edge.v])
                    pq.push(edge);
            
            // Stop when all cities are already visited
            if (this->numVertex == count + 1) break;
        }

        this->isTree = true;
    }

    // Fill the percourse vector with the cycle we should get from the tree
    // Allways starting with the root, then finding the shorter path from it's neighbor to make a visit first (DFS)
    void generateCycle(std::vector<int> &percourse) {
        if (!this->isTree) return;  // Only can generate cycles from trees

        // Initialize visited list and DFS stack
        std::vector<bool> visitedDFS(this->numVertex, false);
        std::stack<int> dfsStack;
        
        // Start DFS traversal from the first vertex (0 index)
        dfsStack.push(0);

        while (!dfsStack.empty()) {
            // Get the top vertex from the DFS stack
            int u = dfsStack.top(); dfsStack.pop();

            // If the vertex has been visited, skip to the next iteration
            if (visitedDFS[u]) 
                continue;

            // Mark the vertex as visited
            visitedDFS[u] = true;

            // Use reverse iterators (rbegin and rend) to traverse the adjacency list in reverse order.
            // rbegin points to the last element, and rend represents a position one step before the first element.
            for (auto it = this->adjList[u].rbegin(); it != this->adjList[u].rend(); it++)
                if (!visitedDFS[it->v])
                    dfsStack.push(it->v);  // We push the vertex, not the edge itself

            // Add current vertex to the percourse list, adjusting index to be 1-based rather than 0-based
            percourse.push_back(u + 1);
        }
    }
};


void TspSolver::solve(TspReader &tr, std::vector<int> &percourse) {
    // Construct Graph
    Graph graph = Graph(tr);

    // MST (minimum spanning tree) - Prim's Algorithm
    Graph MST(graph.numVertex);
    MST.primMST(graph);

    // Generating Cycle in our percourse vector
    MST.generateCycle(percourse);
}