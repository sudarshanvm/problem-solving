def assign_values(N, A, B):
    # Create a dictionary to count the number of edges for each vertex
    edge_count = {}
    for i in range(len(A)):
        edge_count[A[i]] = edge_count.get(A[i], 0) + 1
        edge_count[B[i]] = edge_count.get(B[i], 0) + 1
    
    # Sort vertices by their edge count in descending order
    sorted_vertices = sorted(edge_count.keys(), key=lambda x: edge_count[x], reverse=True)
    
    # Assign values to vertices starting from the highest edge count
    assigned_values = {}
    value = N
    for vertex in sorted_vertices:
        assigned_values[vertex] = value
        value -= 1
    
    # Create a dictionary to map vertices to their assigned values
    edge_weights_sum = sum(assigned_values[A[i]] + assigned_values[B[i]] for i in range(len(A)))

    vertex_values = {}
    for i in range(len(A)):
        vertex_values[A[i]] = assigned_values[A[i]]
        vertex_values[B[i]] = assigned_values[B[i]]
    
    return vertex_values, edge_weights_sum

# Example usage:
N1 = 5
A1 = [2, 2, 1, 2]
B1 = [1, 3, 4, 4]
print("Example 1:", assign_values(N1, A1, B1))  # Output: ({2: 5, 1: 4, 3: 2, 4: 3}, 31)

N2 = 3
A2 = [1]
B2 = [3]
print("Example 2:", assign_values(N2, A2, B2))  # Output:({1: 3, 3: 2}, 5)
