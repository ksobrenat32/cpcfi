//=========== String Manipulation Snippets ===========

// Description: Converts a string to uppercase.
// Time Complexity: O(N), where N is the length of the string.
// Space Complexity: O(1) for in-place modification.
transform(str.begin(), str.end(), str.begin(), ::toupper);

// Description: Converts a string to lowercase.
// Time Complexity: O(N), where N is the length of the string.
// Space Complexity: O(1) for in-place modification.
transform(str.begin(), str.end(), str.begin(), ::tolower);

// Description: Extracts a substring from a starting index to the end.
// Time Complexity: O(L), where L is the length of the substring.
// Space Complexity: O(L).
string suffix = original_string.substr(start_index);

// Description: Extracts a substring of a given length from a starting index.
// Time Complexity: O(L), where L is the length of the substring.
// Space Complexity: O(L).
string substring = original_string.substr(start_index, length);

// Description: Parses variables from a string using a stringstream.
// Time Complexity: O(N), where N is the length of the string to be parsed.
// Space Complexity: O(N) to store the string in the stream.
int hours, minutes, seconds;
char separator1, separator2;
string time_str = "12:34,56";
stringstream ss(time_str);
ss >> hours >> separator1 >> minutes >> separator2 >> seconds;

// Description: Creates a string by repeating a character a number of times.
// Time Complexity: O(n), where n is the length of the resulting string.
// Space Complexity: O(n).
string repeated_char_string(length, character);
