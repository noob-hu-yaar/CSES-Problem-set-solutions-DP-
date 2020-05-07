//Here, We use the bottom up DP approach to solve the question.

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
   long long int c,n,x;
    cin>>n>>x;
    
    vector<long long int> coins;
    
    for(int i=0;i<n;i++)
    {
        cin>>c;
        coins.push_back(c);
    }
    
    vector<long long int> dp(x+1,0);
    
    for(long long int i=1;i<=x;i++)
    {
        dp[i]=INT_MAX;
        for(long long int j=0;j<n;j++)
        {
            if(i-coins[j] >= 0)
            dp[i] = min(dp[i],dp[i-coins[j]]+1);
        }
    }
    
    cout << (dp[x] >= INT_MAX ? -1 : dp[x]) << endl;
    
}   