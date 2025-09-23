"""
Kahn's algorithm for topological sorting of a Directed Acyclic Graph (DAG).
"""
from collections import deque

def kahns_topological_sort(num_vertices, edges):
    """
    Performs a topological sort on a directed graph using Kahn's algorithm.

    A topological sort is a linear ordering of vertices such that for every directed
    edge from vertex u to vertex v, u comes before v in the ordering. This algorithm
    can also be used to detect cycles in a graph.

    Args:
        num_vertices (int): The number of vertices in the graph (labeled 0 to n-1).
        edges (list of tuple): A list of tuples, where each tuple (u, v) represents
                               a directed edge from u to v.

    Returns:
        list: A list of vertices in topologically sorted order. If the graph
              contains a cycle, it returns an empty list.

    Time complexity: O(V + E), where V is the number of vertices and E is the number of edges.
    Space complexity: O(V + E) for the adjacency list, in-degree array, and queue.
    """
    adj = [[] for _ in range(num_vertices)]
    in_degree = [0] * num_vertices

    for u, v in edges:
        adj[u].append(v)
        in_degree[v] += 1

    # Initialize a queue with all vertices that have an in-degree of 0.
    queue = deque([i for i in range(num_vertices) if in_degree[i] == 0])

    topological_order = []

    while queue:
        u = queue.popleft()
        topological_order.append(u)

        # "Remove" u from the graph by decrementing the in-degree of its neighbors.
        for v in adj[u]:
            in_degree[v] -= 1
            # If a neighbor's in-degree becomes 0, add it to the queue.
            if in_degree[v] == 0:
                queue.append(v)

    # If the number of nodes in the sort is not equal to the total number of vertices,
    # the graph has a cycle.
    if len(topological_order) == num_vertices:
        return topological_order
    else:
        # The graph has a cycle, so a topological sort is not possible.
        return []
