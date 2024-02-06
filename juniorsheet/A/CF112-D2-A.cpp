#include<iostream>
using namespace std;

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	string a,b;
	cin>>a>>b;
	int res=0;
	for(int i=0;i<a.size();i++)
		if(tolower(a[i])<tolower(b[i]))
		{
			res=-1;
			break;
		}
		else if(tolower(a[i])>tolower(b[i]))
		{
			res=1;
			break;
		}
	cout<<res<<endl;
	return 0;
}