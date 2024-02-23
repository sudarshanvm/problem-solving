#include<iostream>
#include<vector>
#include<map>
using namespace std;

#define ll long long

void ans(map<ll, pair<ll, ll> > &mp, ll last, ll rest, ll m, ll s)
{
 for(auto i: mp){
	        rest+=(i.first-last)*s;
	        last=i.first;
	        ll sum = i.second.first+i.second.second;
	        rest-=sum;
	        if(rest<0){
	            cout<<"NO\n";
	            return ;
	        }
	    }
	    cout<<"YES\n";
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin>>t;
    while(t--)
    {
    	ll m,s;
    	cin>>m>>s;
    	ll rest=0;
    	map<ll, pair<ll, ll> > mp;

	    vector<pair<ll, ll> > v(m);
	    for(auto &i: v) cin>>i.second;
	    for(auto &i: v) cin>>i.first;

	    for(auto i: v){
	        if(i.first<0){
	            mp[(i.first*=-1)].first=i.second;
	        }
	        else{
	            mp[i.first].second=i.second;
	        }
	    }

	    ll last = 0;

	    ans(mp,last,rest,m,s);
    }
}