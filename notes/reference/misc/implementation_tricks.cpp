// Description: Reads a line of text from standard input.
// Time Complexity: O(L), where L is the length of the line.
// Space Complexity: O(L), to store the line.
string s;
getline(cin, s);

// Description: Reads all lines from standard input until EOF.
// Time Complexity: O(N*L), where N is the number of lines and L is the average line length.
// Space Complexity: O(L), for the current line being read.
while(getline(cin, s));

// Description: Prints a number with leading zeros to a specified width.
// Time Complexity: O(W), where W is the width of the output.
// Space Complexity: O(1).
cout << setw(n) << setfill('0') << x << endl;