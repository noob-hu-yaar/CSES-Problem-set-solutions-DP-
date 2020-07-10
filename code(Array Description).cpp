

#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define sp(j) fijed<<setprecision(j)
#define p_q priority_queue
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int mod = 1e9 + 7;

int fun(vector<int>& v,int n,int m)
{
    int dp[n+1][m+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i == 1)
            {
                if(v[i]==0 || v[i]==j)
                dp[i][j] = 1;
                else
                dp[i][j] = 0;
            }
            else
            {
                if(v[i]==0 || v[i]==j)
                dp[i][j] = ((dp[i-1][j-1] + dp[i-1][j])%mod + dp[i-1][j+1])%mod;
                else
                dp[i][j] = 0;
            }
        }
    }

    int res = 0;
    for(int i=1;i<=m;i++)
    {
        res += dp[n][i];
        res %= mod;
    }

    return res;
}

int main()
{
    fast_io;

    int n,m;
    cin>>n>>m;

    vector<int> v(n+1);
    for(int i=1;i<=n;i++)
    cin>>v[i];

    cout<<fun(v,n,m)<<endl;

    return 0;
}
