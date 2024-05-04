#include<bits/stdc++.h>
using namespace std;

bool solve(int n, int* a, int* b) {
   

   	for(int i=0;i<n;i++)
   	{
   		if(a[i]>b[i])
   			return false;
   	}

   	return true;

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
		int n;
		cin>>n;
		int a[n],b[n];
		int count = 0;
		for(int i=0;i<n;i++)
			cin>>a[i];
		
		for(int i=0;i<n;i++)
		{	
			cin>>b[i];
			
		}

		int res=0;
		while(!solve(n,a,b))
		{
			a[n-1]=0;
			sort(a,a+n);
			res++;
		}

		cout<<res<<endl;

	}
	
	return 0;
}

// #include <iostream>