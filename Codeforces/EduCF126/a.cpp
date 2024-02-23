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
		for(int i=0;i<n;i++)
			cin>>a[i];

		int first=-1;
		int i=0,k=n-1;
		while(a[i]==0)
			i++;
		while(a[k]==0)
			k--;
		int count=0;
		for(int j=i;j<k;j++)
			if(a[j]==0)
				count++;

		cout<<count<<endl;

	}
	
	return 0;
}