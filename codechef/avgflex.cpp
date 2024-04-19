#include<bits/stdc++.h>
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
		int n;
		cin>>n;
		vector<int> a(n);
		for(int i=0;i<n;i++)
			cin>>a[i];

		int count=0, index=0;
		sort(a.begin(), a.end());
		for(int i=0;i<n;i++)
		{
			index = upper_bound(a.begin(), a.end(), a[i]) - a.begin();
			if(index > n-index)
				count++;

		}

		cout<<count<<endl;
	}
	
	return 0;
}