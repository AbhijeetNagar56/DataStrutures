graph = {
    'A': ['D'],
    'B': ['A', 'E', 'C'],
    'C': ['E'],
    'D': ['C', 'G'],
    'E': ['A'],
    'F': ['C'],
    'G': ['F', 'H'],
    'H': []
}

def bfs(graph, start):
    visited = []
    queue = [start]
    traversal = []

    while queue:
        vertex = queue.pop(0)  
        if vertex not in visited:
            visited.append(vertex)
            traversal.append(vertex)
            for n in graph[vertex]:
                if n not in visited and n not in queue:
                    queue.append(n)
    return traversal

def dfs(graph, start, visited=None, traversal=None):
    if visited==None:
        visited = []
    if traversal==None:
        traversal = []

    visited.append(start)
    traversal.append(start)

    for n in graph[start]:
        if n not in visited:
            dfs(graph, n, visited, traversal)

    return traversal

start = 'B'
print("BFS Traversal from", start, " is ", bfs(graph, start))
print("DFS Traversal from", start, " is ", dfs(graph, start))
