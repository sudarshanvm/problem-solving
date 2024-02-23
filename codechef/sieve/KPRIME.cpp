#include<iostream>
#include<vector>
using namespace std;

const int n=1e6;
vector< vector<int> >factors(n);

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int factors[n]={0};
	for(int i=2;i<n;i++)
	{
		if(factors[i]==0)
        {
        	for(int j=i;j<n;j+=i)
        		factors[j]++;
        }
	}

	int t;
	cin>>t;
	while(t--)
	{
	    int l,r,k;
	    cin>>l>>r>>k;
	    int res=0;
	   
	    for(int i=l;i<=r;i++)
	    {
	    	if(factors[i]==k)
	    		res++;

	    }
	    cout<<res<<endl;
	}


	return 0;
}
