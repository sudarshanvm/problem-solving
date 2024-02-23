// #include<iostream>
// #include<unordered_map>
// #include<vector>
// using namespace std;

// #define ll long long
// void solve(int a, int b, int* count, int* pre)
// {
	
//     if (b == a)
//     {
//         cout << "NO\n";
//        return;
//     }
//     ll co = count[b] - count[a - 1];
//     ll dif = b - a + 1 - co;
//     ll sum = pre[b] - pre[a - 1];
//     //   cout<<sum<<"\n";
//     ll remSum = sum - co;
//     remSum -= dif;
//   //  cout << remSum << "\n";
//     ll rem = b - a + 1 - co;

//     if (remSum < co)
//     {
//         cout << "NO\n";
//     }
//     else
//         cout << "YES\n";
// }


// int main() 
// {

// #ifndef ONLINE_JUDGE
// 	freopen("input.txt", "r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
// 	int t;
// 	cin>>t;
// 	while(t--)
// 	{
// 		int n,l,r,q,i;
// 		cin>>n>>q;
		

// 		int a[n + 1], count[n + 1], pre[n + 1];
//         a[0] = count[0] = 0, pre[n + 1] = 0;
//         for (i = 1; i <= n; i++)
//         {
//             cin >> a[i];
//             pre[i] = pre[i - 1] + a[i];
//             count[i] = count[i - 1];
//             if (a[i] == 1)
//                 count[i]++;

//             //  cout << count[i] << " ";
//         }

// 		for(int i=0;i<q;i++)
// 		{
// 			cin>>l>>r;
// 			solve(l,r,pre,count);
// 		}
// 	}
	
// 	return 0;
// }