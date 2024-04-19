#include<iostream>
#include<algorithm>
using namespace std;

int minOps(string s) {
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) {
	    if (s[i] - '0' == i % 2) {
	        ++cnt;
	    }
	}
	return min(cnt, int(s.size() - cnt));
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
		cin>>n;
		string s;
		cin>>s;

    	cout<<minOps(s)<<endl;

	}
	
	return 0;
}
