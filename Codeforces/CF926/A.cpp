#include<iostream>
#include<algorithm>
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
		sort(a,a+n);
		int sum=0;
		for(int i=1;i<n;i++)
			sum+=a[i]-a[i-1];
		cout<<sum<<"\n";
	}
	
	return 0;
}