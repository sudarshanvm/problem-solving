#include<iostream>
#include<vector>
using namespace std;

int find(int k) {
	if(k<=2)
	{
		return 2;
	}
    int largest_power_of_2 = 1;
    while (largest_power_of_2 * 2 <= k) {
        largest_power_of_2 *= 2;
    }
    return largest_power_of_2;
}


vector<int> findSequence(int n, int k) {
    vector<int> sequence;
    int sum=0;
    int orig = k;
    
   if(n==1)
   	{
   		vector<int>temp;
   		temp.push_back(k);
   		return temp;
   	}
    
	int large = find(k)-1;
	sequence.push_back(large);
	
	k -=large;
	sequence.push_back(k);

    
    

    while (sequence.size() < n) {
        sequence.push_back(0);
    }

    return sequence;
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
		int n, k;
	    cin >> n >> k;

	    vector<int> sequence = findSequence(n, k);
	    for(auto s:sequence)
	    	cout<<s<<" ";
	    cout<<endl;

	}


	return 0;
}
