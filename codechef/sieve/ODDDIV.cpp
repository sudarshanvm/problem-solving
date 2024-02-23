#include<iostream>
#include<vector>
using namespace std;

int n=1e6;
vector< vector<int> >factors(n);

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for(int i=1;i<n;i++)
	{
        for(int j=i;j<n;j+=i)
	    	factors[j].push_back(i);
	}

	int t;
	cin>>t;
	while(t--)
	{
	    int l,r,k;
	    cin>>l>>r;
	    int res=0;
	   
	    for(int i=l;i<=r;i++)
	    	res+=factors[i].size()==k?1:0;
	    cout<<res<<endl;
	}


	return 0;
}
