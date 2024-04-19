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
		int m[5]={0};
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			a[i]=temp%3;
			sum+=a[i];
			m[a[i]]++;
		}

		if(sum%3==0)
			cout<<0<<endl;
		else if(sum%3==1&&m[1])
			cout<<1<<endl;
		else if(sum%3==2)
			cout<<1<<endl;
		else
			cout<<2<<endl;
	}
	
	return 0;
}