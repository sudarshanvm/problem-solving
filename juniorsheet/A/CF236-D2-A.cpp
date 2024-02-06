#include<iostream>
#include<set>
using namespace std;

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	set<char> s;
	string a;
	cin>>a;
	for(char c:a)
		s.insert(c);

	string res=s.size()%2==1?"IGNORE HIM!":"CHAT WITH HER!";
	cout<<res<<endl;
	
	return 0;
}