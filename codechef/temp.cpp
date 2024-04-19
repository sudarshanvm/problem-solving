#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
using namespace std;
int recommend(vector<int> a, vector<int> b)
{
	int common = 0;
	unordered_map<int,bool> temp;
	for(auto i: a)
		temp[i]=true;
	
	for(auto i: b)
		if(temp[i])
			common++;

	return common;
}


vector<int> getRecommendedFriends(int n, vector<vector<int> >& a)
{
    unordered_map<int, vector<int> > m;
    for (auto& v : a)
    {
        int user = v[0];
        int frd = v[1];
        
        m[user].push_back(frd);
        m[frd].push_back(user);
    }

    for(int i=0;i<a.size();i++)
    {
    	vector<int> temp = m[i];
    	for(int j=0; j<m[i].size(); j++)
    		cout<<temp[j]<<" ";
    	cout<<endl;
    }

    vector<int> res;
    for (int i=0;i<a.size();i++)
    {
        int mx_common = -1, r = 0;
        for (int j=0;j<a.size();j++)
        {
            if(i!=j)
            {
            	 int common = recommend(m[i], m[j]);
                if (common > mx_common)
                {
                    r = j;
                    mx_common = common;
                }	
            }
               
            
        }
        
        res.push_back(r);
    }
    
    return res; 
}


int main() 
{

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,m,f;
	cin>>n>>m>>f;
	vector< vector<int> > a;
	for(int i=0;i<m;i++)
	{
		int t1,t2;
		cin>>t1>>t2;
		vector<int> pair;
		pair.push_back(t1); // Push t1 into the vector
        pair.push_back(t2); // Push t2 into the vector
        a.push_back(pair);
	}

	vector<int> res = getRecommendedFriends(n, a);
	for(auto r:res)
		cout<<r<<endl;
	
	return 0;
}









// vector<int> getRecommendedFriends(int n, vector< vector<int> > a)
// {

// 	unordered_map<int, vector<int> > m;
// 	for(int i=0;i<a.size();i++)
// 	{
// 		int user = a[i][0];
// 		int frd = a[i][1];
// 		m[user].push_back(frd);
// 		m[frd].push_back(user);
// 	}

// 	// for each user , find the user with most common friends
// 	vector<int> res;
// 	for (int i=0;i<a.size();i++)
// 	{
// 		int mx_common = 0, r=0;
// 		for(int j=i+1;j<a.size();j++)
// 		{
// 			int common = recommend(m[i],m[j]);
// 			if(common > mx_common)
// 			{
// 				r = j;
// 				mx_common = common;
// 			}
// 		}
// 		res.push_back(r);
// 	}

// 	return res;

// }