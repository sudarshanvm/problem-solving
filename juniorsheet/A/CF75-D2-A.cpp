#include<iostream>
using namespace std;

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int a,b;
	cin>>a>>b;
	int c= a+b;
	string as=to_string(a), bs=to_string(b), cs=to_string(c);
	string x,y,z;
	for(auto ch:as)
		if(ch!='0')
			x+=ch;

	for(auto ch:bs)
		if(ch!='0')
			y+=ch;

	for(auto ch:cs)
		if(ch!='0')
			z+=ch;
	int c1 = stoi(z);
	int c2 = stoi(x)+stoi(y);
	// cout<<"x-y-z:"<<x<<" "<<y<<" "<<z<<endl;
	// cout<<"c1: "<<c1<<"c2: "<<c2<<endl;
	string ans = c1==c2?"YES":"NO";
	cout<<ans<<endl;
	return 0;
}