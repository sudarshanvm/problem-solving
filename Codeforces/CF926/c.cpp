#include<iostream>
using namespace std;

string solve(int k, int x, int a)
{
	if(a >= x * (k - 1) + 1)
	{
		if(x>=a-1)
			return "NO";
		else
			return "YES";
	}
		
	return "NO";
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
		int k,x,a;
		cin>>k>>x>>a;
		int max_win_coins = (x * (k - 1));

        // If Sasha has enough coins to win at least once
        if (a >= max_win_coins + 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
	}

	return 0;
}