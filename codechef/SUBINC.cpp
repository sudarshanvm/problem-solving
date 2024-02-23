#include<iostream>
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
		int n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++)
			cin>>arr[i];

		int left=0,i=0;
		long long ans=0,cnt=0;
		for(i=0;i<n;i++){
            cnt++;
            if(i==n-1 || arr[i]>arr[i+1]){
                ans += (cnt*(cnt+1))/2;
                cnt=0;
            }
        }
        // ans += (cnt*(cnt+1))/2;
        cout << ans << endl;
	}
	
	return 0;
}