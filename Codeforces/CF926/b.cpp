#include<iostream>
#include<vector>
using namespace std;

int solve(int n, int k) {
    if(k==4*n-2||k%2)
    	return k/2+1;
    
    return k/2;
}


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
		int n,k;
		cin>>n>>k;
		cout<<solve(n,k)<<"\n";
	}
	
	return 0;
}

