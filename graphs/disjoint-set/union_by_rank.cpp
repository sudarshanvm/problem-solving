#include<iostream>
#include<vector>
using namespace std;

class UnionFind
{
    private:
        vector<int> root;
        vector<int> rank;
    
    public:
       
        UnionFind(int n)
        {
            for(int i=0; i<n; i++)
                {
                    rank.push_back(1);
                    root.push_back(i); 
                }
        }

        int find(int x)
        {
            if(x==root[x])
                return root[x];
            return find(root[x]);
        }

        bool connected(int x, int y)
        {
            return find(x) == find(y);
        }

        void unionSet(int x, int y)
        {
            int rootx = find(x);
            int rooty = find(y);

            if(rootx != rooty)
            {
                if(rank[rootx] > rank[rooty])
                    root[rooty] = rootx;
                else if(rank[rootx] < rank[rooty])
                    root[rootx] = rooty;
                else
                {
                    root[rooty] = rootx;
                    rank[rootx] += 1;
                }

            }
        }

};


int main()
{
    int n=10;
    cout<<boolalpha;
    // cout<<"Enter no. of vertices: ";
    // cin>>n;
    UnionFind uf(n);

    uf.unionSet(1, 2);
    uf.unionSet(2, 5);
    uf.unionSet(5, 6);
    uf.unionSet(6, 7);
    uf.unionSet(3, 8);
    uf.unionSet(8, 9);

    cout << uf.connected(1, 5) << endl;  // true
    cout << uf.connected(5, 7) << endl;  // true
    cout << uf.connected(4, 9) << endl;  // false
    // 1-2-5-6-7 3-8-9-4
    uf.unionSet(9, 4);
    cout << uf.connected(4, 9) << endl;  // true


    return 0;
}