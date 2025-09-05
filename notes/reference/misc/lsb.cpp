// Description: Finds the least significant bit of a number using bitwise operations.
// Time Complexity: O(1)
// Space Complexity: O(1)
int getLeastSignificantBit(int number) {
    return number & -number;
}