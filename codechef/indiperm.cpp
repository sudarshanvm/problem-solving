#include<iostream>
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
		int n;
		cin>>n;

		int a[n];
		a[0] = n;
		for(int i=2;i<=n;i++)
			a[i-1] = i-1;

		for(int i=0;i<n;i++)
			cout<<a[i]<<" ";
		cout<<endl;
	}

	return 0;
}