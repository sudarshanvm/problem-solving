#include<iostream>
using namespace std;

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	int count = 0;
	int a[n];
	a[0]=0;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	
	int energy = 0;
	for(int i=1;i<=n;i++)
	{
		energy += a[i-1]-a[i];
		if(energy < 0)
		{
			count += abs(energy);
			energy = 0;
		}

		
	}

	cout<<count<<endl;
	
	return 0;
}
