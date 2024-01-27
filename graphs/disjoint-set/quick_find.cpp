#include<iostream>
#include<vector>
using namespace std;

class UnionFind
{
    private:
        vector<int> root;
    
    public:
       
        UnionFind(int n)
        {
            for(int i=0; i<n; i++)
                root.push_back(i); 
        }

        int find(int x)
        {
            return root[x];
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
                for(int i=0; i<root.size(); i++)
                {
                    if(root[i] == rooty)
                        root[i] = rootx;
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