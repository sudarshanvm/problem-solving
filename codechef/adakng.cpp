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
		int r,c,k;
		cin>>r>>c>>k;
		int count=0;
		for(int x=1;x<9;x++)
		{
			for(int y=1;y<9;y++)
			{
				int a = abs(x-r);
				int b = abs(y-c);
				if(max(a,b)<=k)
					count++;
			}
		}
		cout<<count<<endl;
	}	
	return 0;
}
