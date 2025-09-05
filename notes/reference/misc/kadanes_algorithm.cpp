// Description: Finds the maximum subarray sum in an array of integers.
// Time Complexity: O(N)
// Space Complexity: O(1)
long long maxSubarraySum(const std::vector<int>& numbers) {
    long long max_so_far = -1e18; // Use a very small number for initialization
    long long current_max = 0;

    for (int number : numbers) {
        current_max += number;
        if (max_so_far < current_max) {
            max_so_far = current_max;
        }
        if (current_max < 0) {
            current_max = 0;
        }
    }
    return max_so_far;
}
