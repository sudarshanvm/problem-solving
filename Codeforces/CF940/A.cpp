#include<iostream>
#include<unordered_map>
#include<vector>
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
		vector<int>a;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			a.push_back(temp);
		}

		if(n<3)
			cout<<0<<endl;
		else
		{
			unordered_map<int,int>m;
			for(int i=0;i<n;i++)
				m[a[i]]++;

			int res=0;
			for (auto it = m.begin(); it != m.end(); ++it)
			{

				res += it->second/3;
			}
			cout<<res<<endl;
		}
	}

	return 0;
}