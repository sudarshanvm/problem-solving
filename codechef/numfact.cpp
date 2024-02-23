#include <iostream>
#include<vector>
#include<cmath>
#include<unordered_map>
using namespace std;

#define N 1000001
using namespace std;
vector<bool>isprime(N, true);
vector<int>primes;


//sieve template code
void init(){
    for(int i = 2; i*i <=N; i++){
        for(int j = i*i; j<=N; j+= i){
            isprime[j] = false;
        }
    }
    
    isprime[1] = isprime[0] = false;
    for(int i = 2; i<N; i++){
        if(isprime[i])
            primes.push_back(i);
    }
    
}

int main() {
	// your code goes here
	int t;
	cin>>t;
	init();
	while(t--)
	{
		int n;
		cin>>n;
	    int div[n];
        for(auto&it:div)
            cin>>it;
        
        unordered_map<int, int>mp;
        for(auto&it:div){
           
                if(isprime[it])
                {
                	mp[it]++;
                	continue;
                }
                for(int i = 2; i<=it; i++){
                    if( it%i == 0){
                        int temp = it;
                        if(isprime[i]){
                            while(temp%i == 0){
                                temp = temp/i;
                                mp[i]++;
                            }
                        }
                        
                        
                    }
                }
            // }
            
        }
	   
	   
	    int res=1;
	    for(auto p:mp)
	    {
	        int count = p.second;
	        int num = p.first;
	        //d(p^n)=n+1 => d(num^count)=count+1 
	        // cout<<num<<":"<<count<<endl;
	        res *= (count+1);
	        
	    }
	    
	    cout<<res<<endl;
	}

}
