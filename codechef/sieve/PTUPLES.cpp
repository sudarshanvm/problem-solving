#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int main() {
	// your code goes here
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int num=1e6+1;
	vector<bool>isprime(num+1,true);
    isprime[0]=false;
    isprime[1]=false;
	for(int i=2;i*i<=num;i++)
	    {
	        if(isprime[i])
	        {

	            for(int j=i*i;j<=num;j+=i)
	                isprime[j]=false;
	        }
	    }

	   int ans[num]={0};
	   for(int i=2;i<=n;i++)
	    {
	    	if(isprime[i]&&isprime[i-2])
	    		ans[i]=ans[i-1]+1;
	    	else
	    		ans[i]=ans[i-1];
	    }

	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;  
	    cout<<ans[n]<<endl;
	}

}

