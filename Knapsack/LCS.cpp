#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void printDpTable();

string s,t;
int dp[1010][1010];


int main(void) {
    cin >> s >> t;
    cout << s << endl;
    cout << t << endl;

    for (int i=0; i<s.length(); i++) {
        for (int j=0; j<t.length(); j++) {
            if ( s[i] == t[j] ) {
                dp[i+1][j+1] = dp[i][j] + 1;
            } else {
                dp[i+1][j+1] = max( dp[i+1][j], dp[i][j+1] );
            }
        }
    }
    printDpTable();
}

void printDpTable() {
    for (int i=0; i<=s.length(); i++) {
        for (int j=0; j<=t.length(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

