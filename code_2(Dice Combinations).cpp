//Here, the sliding window concept is used. It is a space optimised code for the same,
//but i could not figure out why I am getting errors in some cases upon submission.

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n,k=6;
    cin>>n;
 
    vector<int> dp(n+1,0);
    dp[0]=dp[1]=1;
    
    for(int i=2;i<=k;i++)
    dp[i] = 2*dp[i-1];
 
    for(int i=k+1;i<=n;i++)
    dp[i] = 2*dp[i-1]-dp[i-k-1];
 
cout<<dp[n];
    return 0;
}