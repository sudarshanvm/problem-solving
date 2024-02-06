#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

char solve(int count, unordered_map<char,int> &m)
{
	for(auto ele:m)
	{
		if(ele.second==count)
			return ele.first;
	}
	return 'a';
}

string reconstructString(vector<int>& trace, unordered_map<char,int> &m) {
    string result;
    char currentChar = 'a';

    for (int i = 0; i < trace.size(); i++) {
        char temp=solve(trace[i],m);
        result+=temp;
        m[temp]++;
    }

    return result;
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
		vector<int>a;
		unordered_map<char,int>m;
		for(char c='z';c>='a';c--)
			m[c]=0;
		for(int i=0;i<n;i++)
		{
			int temp;
			cin>>temp;
			a.push_back(temp);
		}
		
		string res = reconstructString(a, m);
		cout<<res<<endl;
	}

	
	return 0;
}
