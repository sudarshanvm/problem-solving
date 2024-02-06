#include<iostream>
#include<unordered_map>
using namespace std;

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n,p;
	cin>>n>>p;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	p-=1;
	unordered_map<int,int>left;
	unordered_map<int,int>right;
	int i=0, count=1;
	while(count<n)
	{
		if(p-count>=0)
		{
			left[count]=a[p-count];
		}
		else
			left[count]=-1;
		count++;
	}

	count=1;
	while(count<n)
	{
		if(p+count<n)
		{
			right[count]=a[p+count];
		}
		else
			right[count]=-1;
		count++;
	}

	count=0;
	for(int i=0;i<n;i++)
	{
		// 1 & 1


		// 1 & 0

		// 1 -

		//0 & 1

		//0 & 0

		// - 1
		// cout<<"left["<<i<<"]="<<left[i]<<" right["<<i<<"]="<<right[i]<<endl;

		if(left[i]==1)
		{
			if(right[i]==1)
				count+=2;
			if(right[i]==-1)
				count++;
		}

		else if(right[i]==1)
		{
			if(left[i]==1)
				count+=2;
			if(left[i]==-1)
				count++;
		}
	}
	cout<<count+a[p]<<endl;
	return 0;
}