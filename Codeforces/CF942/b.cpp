#include<iostream>
#include<string>
using namespace std;

string solve(int n, string coins) {
    int upCount = 0;

    // Count the number of facing-up coins
    for (char c : coins) {
        if (c == 'U') {
            upCount++;
        }
    }

    // If there are odd number of facing-up coins, Alice wins
    if (upCount % 2 == 1) {
        return "YES";
    } else {
        return "NO";
    }
}



int main() 
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n;
        cin>>s;
        cout<<solve(n,s)<<endl;
    }
    
    return 0;
}