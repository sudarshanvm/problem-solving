#include<iostream>
#include<cmath>
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
		for(int i=0;i<n;i++)
			cin>>a[i];

		int sum=0;
		for(int i=0;i<n;i++)
			sum+=abs(a[i]);

		cout<<sum<<endl;
	}
	
	return 0;
}