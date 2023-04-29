// Problem link:
// https://codeforces.com/group/qhNeDJ317x/contest/440974/problem/F

#include <bits/stdc++.h>
using namespace std;

#define FO(i, b)  for (int i = 0; i < (b); i++)

void fixTime(string time, double delay){

    int delsec = floor(delay);
    int delmsec = int((delay - delsec) * 1000 + 0.5) ;

    int hour;
    int min;
    int sec;
    int milsec;
    char colon, comma;

    // create a stringstream object from the time string
    stringstream ss(time);

    // extract hours, minutes, seconds, and milliseconds from the stringstream
    ss >> hour >> colon >> min >> colon >> sec >> comma >> milsec;

    // Add milliseconds
    milsec += delmsec;
    while(milsec >= 1000){
        sec += 1;
        milsec -= 1000;
    }

    // Add seconds
    sec += delsec;
    while(sec >= 60){
        min += 1;
        sec -= 60;
    }

    // Add minutes
    while(min >= 60){
        hour += 1;
        min -= 60;
    }

    // Print in the format
    cout << setw(2) << setfill('0') << hour << ":";
    cout << setw(2) << setfill('0') << min << ":";
    cout << setw(2) << setfill('0') << sec << ",";
    cout << setw(3) << setfill('0') << milsec;
}

inline void solve(){
    int N; cin >> N;
    double delay; cin >> delay;

    string start;
    string finish;

    // tmp string to return the same
    string tmp;

    FO(i,N){
        // number of char
        cin >> tmp; cout << tmp << endl;
        
        cin >> start;
        fixTime(start,delay);

        // Space between times
        cin >> tmp; cout << " --> "; 

        cin >> finish;
        fixTime(finish,delay);

        // space
        getline(cin,tmp);

        // line 1
        getline(cin,tmp);
        cout << endl << tmp << endl;

        // line 2
        getline(cin,tmp);
        if( ! tmp.empty()){
            // Print the second line and print empty line
            cout << tmp << endl << endl;
            getline(cin,tmp);
        } else {
            // Just print one empty line
            cout << endl;
        }
    }
}

int main(){
    solve();
    return 0;
}
