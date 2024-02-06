#include<iostream>
using namespace std;

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a,b;
	cin>>a>>b;
	int count=0;
	while(a<=b)
	{
		if(a<=b)
			count++;
		a=a*3;
		b=b*2;


	}
	
	cout<<count<<endl;
	return 0;
}