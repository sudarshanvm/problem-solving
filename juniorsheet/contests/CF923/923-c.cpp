#include<iostream>
#include<vector>
#include<unordered_set>
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
		int n,m,k;
		cin>>n>>m>>k;
		unordered_set<int>a,b,c;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			if(temp<=k)
			{
				a.insert(temp);
				c.insert(temp);
			}
		}

		for(int i=0;i<m;i++)
		{
			int temp;
			cin>>temp;
			if(temp<=k){
				c.insert(temp);
				b.insert(temp);
			}
		}
		
		if(c.size()>=k&&2*a.size()>=k&&2*b.size()>=k)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}
	
	return 0;
}