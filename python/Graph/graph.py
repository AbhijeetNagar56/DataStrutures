
# class graph:
#     def __init__(self, V, ud = False):
#         self.totalVertices = V
#         self.dir = ud
#         self.adjMatrix = [[0]*V for _ in range(V)]


#     def addEdge(self, src, des, wt = 1):
#         self.adjMatrix[src][des] = wt
#         if self.dir:
#             self.adjMatrix[des][src] = wt

    
    
#     def dis(self):
#         for r in self.adjMatrix:
#             print(r)



# g = graph(4, ud = True)

# g.addEdge(1,2)
# g.addEdge(2,3)

# g.dis()


# class GraphList:
#     def __init__(self, num_vertices):
#         self.V = num_vertices
#         self.adj_list = [[] for _ in range(self.V)]

#     def add_edge(self, u, v):
#         self.adj_list[u].append(v)

#     def print_graph(self):
#         for i in range(self.V):
#             print(f"{i}: {self.adj_list[i]}")

# # Usage
# g = GraphList(4)
# g.add_edge(0, 1)
# g.add_edge(1, 2)
# g.print_graph()


class GraphEdgeList:
    def __init__(self):
        self.edges = []

    def add_edge(self, u, v, weight=1):
        self.edges.append((u, v, weight))

    def print_graph(self):
        for edge in self.edges:
            print(edge)

# Usage
g = GraphEdgeList()
g.add_edge(0, 1, 5)
g.add_edge(1, 2, 3)
g.print_graph()
