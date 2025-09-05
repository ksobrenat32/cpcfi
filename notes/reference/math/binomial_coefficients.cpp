// Calculates binomial coefficients C(n, k) using precomputed factorials.
// Time complexity: O(1) with O(n) precomputation
// Space complexity: O(n) for precomputed tables

long long combinations(int total_items, int selected_items) {
    return factorials[total_items] *
           inverse_factorials[selected_items] % m *
           inverse_factorials[total_items - selected_items] % m;
}
