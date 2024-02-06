#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define int long long
signed main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,m;
	cin>>n>>m;
	vector<pair<int,int> > a;

	for(int i=0;i<m;i++)
	{
		int ta, tb;
		cin>>ta>>tb;
		a.push_back(make_pair(tb,ta));
	}


	sort(a.begin(), a.end(), greater<pair<int,int> >());

	int matches=0;
	int count=0;
	int i=0;
	while(count<n)
	{
		int matches_left = n-count;
		if(i>=a.size())
			break;
		if(a[i].second<=matches_left)
		{
			matches += (a[i].first*a[i].second);
			count += a[i].second;
		}
		else
		{
			matches += (matches_left*a[i].first);
			count += matches_left;
		}
		i++;
	}

	cout<<matches<<endl;

	return 0;
}