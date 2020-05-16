

#include <bits/stdc++.h> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 

int add(vector<int> p)
{
    int s = 0;
    for(int i=0;i<p.size();i++)
    s += p[i];
    
    return s;
}

int main()
{
    fast_io;

    int n;
    cin>>n;

    vector<int> coins(n);
    for(int&i : coins)
    cin>>i;

    int sum = add(coins);

    int dp[sum+1];
    memset(dp,-1,sizeof(dp));

    dp[0] = 1;
    for(int i=0;i<n;i++)
    {
        for(int j=sum-coins[i];j>=0;j--)
        {
            if(dp[j] != -1)
            dp[j+coins[i]] = 1;
        }
    }
    vector<int> v;
    for(int i=1;i<=sum;i++)
    {
        if(dp[i] != -1)
        v.push_back(i);
    }

    cout<<v.size()<<endl;

    for(int i=0;i<v.size();i++)
    cout<<v[i]<<" ";

    return 0;
}
//