#include <iostream>
#include <map>
#include <list>
#include <vector>

using namespace std;


class Graph {
    map<char, list<char>> adj;
public:
    
    void addEdge(char u, char v);

    bool DFS(char start, char goal, map<char, bool>& visited, map<char, char>& parent);

    void findPathDFS(char start, char goal);
};

void Graph::addEdge(char u, char v) {
    adj[u].push_back(v);  
    adj[v].push_back(u);  
}

bool Graph::DFS(char current, char goal, map<char, bool>& visited, map<char, char>& parent) {
    visited[current] = true;  

    
    if (current == goal) {
        return true;
    }

    
    for (auto neighbor : adj[current]) {
        if (!visited[neighbor]) {
            parent[neighbor] = current;
            if (DFS(neighbor, goal, visited, parent)) {
                return true;  // Stop DFS once the goal is found
            }
        }
    }

    return false;
}

// Function to find and print the path from start to goal using DFS
void Graph::findPathDFS(char start, char goal) {
    
    map<char, bool> visited;

    map<char, char> parent;

    // Perform DFS from the start node
    if (DFS(start, goal, visited, parent)) {
        // If goal is found, reconstruct the path
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

int main() {
    // Create the graph (tree structure)
    Graph g;
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('B', 'E');
    g.addEdge('B', 'D');
    g.addEdge('C', 'F');
    g.addEdge('D', 'H');
    g.addEdge('F', 'G');
    g.addEdge('H', 'K');
    g.addEdge('H', 'J');
    g.addEdge('G', 'L');
    g.addEdge('G', 'I');
    g.addEdge('G', 'M');
    g.addEdge('I', 'R');
    g.addEdge('P', 'Q');
    g.addEdge('P', 'S');
    g.addEdge('M', 'O');
    g.addEdge('O', 'V');
    g.addEdge('R', 'U');
    g.addEdge('S', 'T');
    g.addEdge('U', 'N');
    g.addEdge('U', 'W');
    g.addEdge('T', 'X');
    g.addEdge('W', 'Y');
    g.addEdge('X', 'Z');
    g.addEdge('Y', 'Z');

/*
                A
              / \
             B   C
            / \   \
           D   E   F
           \        \
            H        G
           / \     / | \
          K  J    L  I  M 
         /           /  \
        P           R    O
       / \         /      \
      Q   S       U        V
           \     / \          
           T    W   N
           \   /
           X  Y
            \/
            Z

*/
    // Perform DFS from start state 'A' to goal state 'H'
    char start = 'A';
    char goal = 'Z';
    cout << "Depth First Search from " << start << " to " << goal << ":" << endl;
    g.findPathDFS(start, goal);

    return 0;
}
