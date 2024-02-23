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
		int x,y;
		cin>>x>>y;
		int gaps=x-1;
		cout<<y/gaps<<endl;
	}
	
	return 0;
}