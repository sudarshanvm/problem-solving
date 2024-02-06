#include<iostream>
using namespace std;

int main() 
{

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif

	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		int f=-1,l=-1;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='B')
			{
				if(f==-1)
				{
					f=i;
				l=i;
				}
				else
					l=i;
			}
		}
		
		cout<<l-f+1<<endl;
	}
	return 0;
}