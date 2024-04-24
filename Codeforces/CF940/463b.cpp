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
	for(int i=0;i<n;i++)
		cin>>a[i];

	count = a[0];
	energy = 0;
	for(int i=1;i<n;i++)
	{
		if(a[i]>a[i-1])
		{
			int diff = a[i]-a[i-1];
			if(energy < diff)
			{
				diff = diff - energy;

				count += diff;
			}
		}

		energy += a[i-1]-a[i];
	}

	cout<<count<<endl;
	
	return 0;
}
