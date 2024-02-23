#include<iostream>
#include<unordered_map>
using namespace std;



int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	unsigned long long a[135];
	if(n>=130)
	{
		cout<<"Yes"<<"\n";
		return 0;
	}
	for(int i=0;i<n;i++)
	{	cin>>a[i];
		
	}


	for (int i=0;i<n;++i)
 
		for (int j=i+1;j<n;++j)
 
			for (int k=j+1;k<n;++k)
 
				for (int l=k+1;l<n;++l)
 
				if ((a[i]^a[j]^a[k]^a[l])==0){
 
					cout<<"Yes\n";
 
					return 0;
 
				}
 
	cout<<"No\n";
	
	
	return 0;
}