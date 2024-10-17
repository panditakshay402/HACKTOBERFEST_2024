#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <vector>

using namespace std;

// Graph class representing a graph using an adjacency list
class Graph {
    map<char, list<char>> adj;  // Adjacency list representation (graph stored as map)
public:
    // Function to add an edge to the graph
    void addEdge(char u, char v);

    // Function to perform BFS from start state to goal state
    void BFS(char start, char goal);
};

// Function to add an edge to the graph
void Graph::addEdge(char u, char v) {
    adj[u].push_back(v);  // Add v to u's list
    adj[v].push_back(u);  // Add u to v's list (since the graph is undirected)
}

// Function to perform BFS from start state to goal state
void Graph::BFS(char start, char goal) {
    // Queue for BFS
    queue<char> q;

    // Map to keep track of visited nodes
    map<char, bool> visited;

    // Parent map to reconstruct the path from start to goal
    map<char, char> parent;

    // Mark the start node as visited and enqueue it
    visited[start] = true;
    q.push(start);

    bool found = false;  // To check if the goal state is found

    while (!q.empty()) {
        // Get the front node in the queue
        char current = q.front();
        q.pop();

        // Check if we have reached the goal
        if (current == goal) {
            found = true;
            break;
        }

        // Visit all the neighbors of the current node
        for (auto neighbor : adj[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                parent[neighbor] = current;  // Keep track of the path
                q.push(neighbor);
            }
        }
    }

    // If goal is found, reconstruct and print the path
    if (found) {
        cout << "Path from " << start << " to " << goal << ": ";
        vector<char> path;
        for (char at = goal; at != start; at = parent[at]) {
            path.push_back(at);
        }
        path.push_back(start);

        // Print the path in reverse (from start to goal)
        for (auto it = path.rbegin(); it != path.rend(); ++it) {
            cout << *it;
            if (it + 1 != path.rend()) cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "No path found from " << start << " to " << goal << endl;
    }
}

// Driver code
int main() {
    // Create the graph (tree structure)
    Graph g;
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('B', 'D');
    g.addEdge('B', 'E');
    g.addEdge('C', 'F');
    g.addEdge('E', 'H');
    g.addEdge('F', 'G');
    g.addEdge('G', 'J');
    g.addEdge('H', 'I');
    g.addEdge('H', 'K');
    g.addEdge('J', 'L');
    g.addEdge('I', 'M');
    g.addEdge('M', 'O');
    g.addEdge('L', 'P');
    g.addEdge('L', 'Q');
    g.addEdge('O', 'S');
    g.addEdge('P', 'N');
    g.addEdge('Q', 'R');
    g.addEdge('S', 'V');
    g.addEdge('S', 'T');
    g.addEdge('R', 'U');
    g.addEdge('V', 'X');
    g.addEdge('U', 'Y');
    g.addEdge('U', 'W');
    g.addEdge('W', 'Z'); 

    
    
    /*              A
                   / \
                  B   C
                 / \   \
                D  E   F
                   \   \
                   H   G
                  / \   \
                 I  K   J
                /        \
               M         L 
              /         / \
             O         P   Q
            /         /    \   
           S         N     R
          / \              \
         V   T              U
        /                  / \ 
       X                  W   Y 
                         /
                        Z 
    */


    // Perform BFS from start state 'A' to goal state 'H'
    char start = 'A';
    char goal = 'Z';
    cout << "Breadth First Search from " << start << " to " << goal << ":" << endl;
    g.BFS(start, goal);

    return 0;
}
