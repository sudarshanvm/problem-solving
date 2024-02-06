#include<iostream>
#include<vector>
using namespace std;

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin>>n;
	string s;
	cin>>s;
	int a=0,b=0;
	for(auto c:s)
		if(c=='A')
			a++;
		else
			b++;

	if(a>b)
		cout<<"Anton";
	else if(b>a)
		cout<<"Danik";
	else
		cout<<"Friendship";

	
	return 0;
}