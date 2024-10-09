## String manipulation

### Convert char to int

```c++
int i = c - '0';
```

### To upper and to lower case

```c++
transform(s.begin(), s.end(), s.begin(), ::toupper);
transform(s.begin(), s.end(), s.begin(), ::tolower);
```

### Substrings

```c++
// From i to the end
string a = s.substr(i);
// From i to j
string a = s.substr(i,j);
```

### Find a char

Print the position.

```c++
int l = s.find(c);
```

If not found.

```c++
if( s.find(c) != string::npos ){
    // YES
} else {
    // NO
}
```

### Substrings with steroids

This is a way to extract the values from a string that has a specific format. For example, if the string is "1:2,3" and we want to extract the values 1, 2 and 3.

```c++
int a;
int b;
int c;
char comma;
char colon;

// Createa a stringstream object
stringstream ss(fullString);
// Extract the strings
ss >> a >> colon >> b >> comma >> c;
```

### ASCII table

![ASCII TABLE](https://upload.wikimedia.org/wikipedia/commons/thumb/d/dd/ASCII-Table.svg/2522px-ASCII-Table.svg.png)

