//To Upper and Lower
transform(s.begin(), s.end(), s.begin(), ::toupper);
transform(s.begin(), s.end(), s.begin(), ::tolower);

// From i to the end
string a = s.substr(i);
// From i to j
string a = s.substr(i,j);

int a;
int b;
int c;
char comma;
char colon;

// Createa a stringstream object
stringstream ss(fullString);
// Extract the strings
ss >> a >> colon >> b >> comma >> c;
