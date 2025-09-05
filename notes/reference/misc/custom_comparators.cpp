// Description: A custom comparator to sort objects by a specific property.
// Time Complexity: O(1)
// Space Complexity: O(1)
bool compareEdgesByWeight(const Edge &edge_a, const Edge &edge_b) {
    return edge_a.weight < edge_b.weight;
}
