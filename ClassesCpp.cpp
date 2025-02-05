#include <iostream>
#include <stack>
#include <queue>
#include <limits.h>
#include <vector>
#include <functional>
#include <set>

using namespace std;


// Add an edge to the adjacency matrix
void addEdge(vector<vector<int>>& adjMatrix, int u, int v) {
    adjMatrix[u][v] = 1;
    cout << "Adding edge: [" << u << "," << v << "]" << endl;
}

// Print the adjacency matrix
void printGraph(const vector<vector<int>>& adjMatrix) {
    for (const auto& row : adjMatrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Depth-First Search (DFS)
void dfs(int vertex, vector<vector<int>>& adjMatrix) {
    int vertices = adjMatrix.size();
    cout << "AdjMatrix size: " << adjMatrix.size() << endl;
    cout << endl;

    vector<bool> visited(vertices, false);
    visited[vertex] = true; // Mark the current vertex as visited
    cout << vertex << " "; // Print the vertex

    // Explore all neighbors of the current vertex
    for (int neighbor = 0; neighbor < adjMatrix.size(); neighbor++) {
        if (adjMatrix[vertex][neighbor] != 0 && !visited[neighbor]) {
            dfs(neighbor, adjMatrix); // Recursively call DFS
        }
    }
}


void dfsIterative(int start, const vector<vector<int>>& adjMatrix){
    int vertices = adjMatrix.size();
    vector<bool> visited(vertices, false);
    stack<int> stack;

    stack.push(start);
    while(!stack.empty()){
        int vertex = stack.top();
        stack.pop();
        cout << "Current index is: " << "[" << vertex << "]" << "[0]"<< endl;
        cout << endl;

        if(!visited[vertex]){

            visited[vertex] = true;
            cout << endl;
            
            

            for(int neighbour = vertices-1; neighbour >= 0; neighbour --){
                if (adjMatrix[vertex][neighbour] !=0 && !visited[neighbour]){
                    stack.push(neighbour);
                    cout << "Current index is: " << "[" << vertex << "]" << "[" << neighbour << "]"<< endl;
                    cout << endl;
                }
            }
        }
    }
}

void bfs(int start, const vector<vector<int>>& adjMatrix){
    int vertices = adjMatrix.size();
    cout << "AdjMatrix size: " << adjMatrix.size() << endl;
    cout << endl;
    vector<bool> visited(vertices, false);
    queue<int> queue;

    queue.push(start);
    visited[start] = true;

    while (!queue.empty()){
        int vertex = queue.front();
        cout << endl;
        
        queue.pop();	
        cout << "Current index is: " << "[" << vertex << "]" << "[0]"<< endl;
    //    cout << "Visiting index: [" << vertex << "]" << endl;

        for(int neighbour = 0;neighbour < vertices; neighbour++){
            if(adjMatrix[vertex][neighbour] == 1 && !visited[neighbour]){
                queue.push(neighbour);
                visited[neighbour] = true;
                cout << "Current index is: " << "[" << vertex << "]" << "[" << neighbour << "]"<< endl;
                cout << endl;
              //  cout << "Adding to queue: [" << neighbour << "] from [" << vertex << "]" << endl;
            }
        }
    }
}

void bfsWithSelfLoops(int start, const vector<vector<int>>& adjMatrix) {
    int vertices = adjMatrix.size();
    vector<bool> visited(vertices, false);
    set<pair<int, int>> visitedEdges; // Track visited edges
    queue<int> queue;

    queue.push(start);
    visited[start] = true;  // Mark start node as visited

    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();

        // Perform operation at the exact index (vertex)
        cout << "Visiting index: [" << vertex << "]" << endl;

        // Traverse neighbors, including self-loops
        for (int neighbour = 0; neighbour < vertices; neighbour++) {
            if (adjMatrix[vertex][neighbour] == 1) { // If there's an edge
                // Print every visited edge (even if the node is already visited)
                if (visitedEdges.find({vertex, neighbour}) == visitedEdges.end()) {
                    cout << "  Visiting edge: [" << vertex << "," << neighbour << "]" << endl;
                    visitedEdges.insert({vertex, neighbour});
                }

                // Only enqueue if not visited yet
                if (!visited[neighbour]) {
                    queue.push(neighbour);
                    visited[neighbour] = true;
                }
            }
        }
    }
}


bool isCyclicUtil(int vertex, const vector<vector<int>>& adjMatrix, vector<bool> &visited, vector<bool> &recStack) {
    // Add starting vertex to visited and recursion stack
    visited[vertex] = true;
    recStack[vertex] = true;
    
    // Find neighbours of the current vertex
    for (int neighbour = 0; neighbour < adjMatrix.size(); neighbour++) {
        if (adjMatrix[vertex][neighbour] == 1) { // If there's an edge
        // if neighbour is not visited, then recurse on it
            if (!visited[neighbour]) {
                if (isCyclicUtil(neighbour, adjMatrix, visited, recStack))
                    return true;
            }
            // if neighbour is already visited and present in recursion stack, then cycle exists
            else if (recStack[neighbour]) {
                return true;  // Cycle detected
            }
        }
    }

    recStack[vertex] = false;  // Remove vertex from recursion stack
    return false;
}
bool isCyclic(const vector<vector<int>>& adjMatrix) {
    int vertices = adjMatrix.size();
    vector<bool> visited(vertices, false);
    vector<bool> recStack(vertices, false);

    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            if (isCyclicUtil(i, adjMatrix, visited, recStack))
                return true;
        }
    }

    return false;
}
int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adjMatrix(V, vector<int>(V, 0));

    // Add edges to the graph
    addEdge(adjMatrix, 0, 0);
    addEdge(adjMatrix, 0, 1);
    addEdge(adjMatrix, 0, 2);

    addEdge(adjMatrix, 1, 0);
    addEdge(adjMatrix, 1, 1);
    addEdge(adjMatrix, 1, 2);

    addEdge(adjMatrix, 2, 0);
    addEdge(adjMatrix, 2, 1);
    addEdge(adjMatrix, 2, 2);

    addEdge(adjMatrix, 4, 4);

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    printGraph(adjMatrix);
    cout << endl;
//    dfsIterative(0, adjMatrix);

    // Perform DFS traversal
  //  cout << "DFS Traversal starting from vertex 0: ";
  //  dfs(0, adjMatrix);
    cout << endl;
    
    // Perform BFS traversal
    cout << "BFS Traversal starting from vertex 0: ";
    cout << endl;
    cout << endl;
    bfs(0, adjMatrix);
    cout << endl;
    cout << endl;
    bfsWithSelfLoops(0, adjMatrix);
    cout << endl;

 //   if (isCyclic(adjMatrix))
//     cout << "The graph contains a cycle." << endl;
  //  else
  //      cout << "The graph does not contain a cycle." << endl;

    return 0;
}
