#include<iostream>
using namespace std;

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,a,b,c;
	cin>>n;
	int count=0;
	for(int i=0;i<n;i++)
	{
		a=0; b=0; c=0;
		cin>>a>>b>>c;
		if(a+b+c>1)
			count++;
	}
	cout<<count<<endl;
	return 0;
}