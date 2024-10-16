# DFS function
def dfs(graph, node, visited):
    visited[node] = True
    
    print(node, end=' ')
    
    for neighbor in graph[node]:
        if not visited[neighbor]:
            dfs(graph, neighbor, visited)

graph = [
    [1, 2],      # Neighbors of node 0
    [0, 3, 4],   # Neighbors of node 1
    [0, 5],      # Neighbors of node 2
    [1],         # Neighbors of node 3
    [1, 5],      # Neighbors of node 4
    [2, 4]       # Neighbors of node 5
]

visited = [False] * len(graph)

# Perform DFS starting from node 0
start_node = 0
print("DFS Traversal Order:", end=' ')
dfs(graph, start_node, visited)
