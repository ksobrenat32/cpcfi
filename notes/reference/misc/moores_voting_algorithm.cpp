// Description: Finds the majority element in a sequence in linear time and constant space.
// Time Complexity: O(N)
// Space Complexity: O(1)
int majorityElement(const std::vector<int>& numbers) {
    int candidate = 0;
    int votes = 0;

    // Find a candidate for the majority element
    for (int number : numbers) {
        if (votes == 0) {
            candidate = number;
            votes = 1;
        } else if (candidate == number) {
            votes++;
        } else {
            votes--;
        }
    }

    // Verify if the candidate is the majority element
    int count = 0;
    for (int number : numbers) {
        if (number == candidate) {
            count++;
        }
    }

    if (count > numbers.size() / 2) {
        return candidate;
    }

    // Return a sensible default if no majority element is found
    // This part depends on the problem constraints.
    // For example, throw an exception or return a special value.
    return -1; // Assuming -1 is not a valid element in the array.
}
