#include<iostream>
#include<algorithm>
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
		int a,b;
		cin>>a>>b;


		int ah=a, bh=b;
		int ra=0, rb=0, remainder;
		while(a != 0) {
		    remainder = a % 10;
		    ra = ra * 10 + remainder;
		    a /= 10;
	  	}

	  	while(b != 0) {
		    remainder = b % 10;
		    rb = rb * 10 + remainder;
		    b /= 10;
	  	}

	  	cout<<"a: "<<ah<<" ra: "<<ra<<" b: "<<bh<<" rb: "<<rb<<endl;
	  	ah = max(ah,ra);
	  	bh = min(bh, rb);
	  	
	  	if(ah>bh)
	  		cout<<"YES"<<endl;
	  	else
	  		cout<<"NO"<<endl;
	}
	
	return 0;
}