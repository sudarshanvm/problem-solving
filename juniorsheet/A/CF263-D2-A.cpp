#include<iostream>
using namespace std;

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int a[5][5];
	int indi=0,indj=0;
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>a[i][j];
			if(a[i][j]==1)
			{
				indi=i; indj=j;
			}
		}
	}
	

	cout<<abs(2-indi)+abs(2-indj)<<endl;

	return 0;
}