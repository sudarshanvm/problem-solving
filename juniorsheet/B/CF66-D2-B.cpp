#include<iostream>
using namespace std;

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];


	int i=n-2,count=0;
	int right[n]; right[n-1]=0;
	while(i>=0)
	{
		if(a[i]<a[i+1])
		{
			count=0;
			right[i]=0;
		}
		else
		{
			count++;
			right[i]=count;
		}
		i--;
	}

	int left[n]; left[0]=0; count=0;
	for(i=1;i<n;i++)
	{
		if(a[i]<a[i-1])
		{
			count=0;
			left[i]=0;
		}
		else
		{
			count++;
			left[i]=count;
		}
	}

	// for(int i=0;i<n;i++)
	// {
	// 	cout<<"left["<<i<<"]="<<left[i]<<", ";
	// 	cout<<"right["<<i<<"]="<<right[i]<<", ";
	// }

	int res=0;
	for(int i=0;i<n;i++)
		res=max(res, 1+left[i]+right[i]);


	cout<<res<<endl;
	return 0;
}