from collections import deque

# BFS function
def bfs(graph, start):
    queue = deque([start])
    
    visited = [False] * len(graph)
    
    visited[start] = True
    
    traversal_order = []
    
    while queue:
        node = queue.popleft()
        
        traversal_order.append(node)
        
        for neighbor in graph[node]:
            if not visited[neighbor]:
                # Mark the neighbor as visited and enqueue it
                queue.append(neighbor)
                visited[neighbor] = True
    
    return traversal_order

# Example graph represented as an adjacency list
graph = [
    [1, 2],      # Neighbors of node 0
    [0, 3, 4],   # Neighbors of node 1
    [0, 5],      # Neighbors of node 2
    [1],         # Neighbors of node 3
    [1, 5],      # Neighbors of node 4
    [2, 4]       # Neighbors of node 5
]

# Perform BFS starting from node 0
start_node = 0
result = bfs(graph, start_node)

# Print the result of BFS traversal
print("BFS Traversal Order:", result)
