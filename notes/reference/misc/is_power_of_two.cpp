// Description: Checks if a number is a power of two using bitwise operations.
// Time Complexity: O(1)
// Space Complexity: O(1)
bool isPowerOfTwo(int number) {
    return (number > 0) && ((number & (number - 1)) == 0);
}