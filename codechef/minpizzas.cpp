#include<bits/stdc++.h>
using namespace std;

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
		long long n,k;
		cin>>n>>k;

// 		long long lcm = (n*k)/__gcd(n,k);
		long long l = lcm(n,k);
		cout<<l/k<<endl;
	
	}

	return 0;
}