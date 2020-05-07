//Here, We use the Top Down DP approach to solve the question.
// Note that this code gives TLE. Uploading it just for understanding purpose.


#include <bits/stdc++.h>
using namespace std;

int fun(long long int x,vector<long long int> coins,long long int n,vector<long long int> dp)
{
    //Base case
    if(x==0)
    return 0;
    
    //Lookup
    if(dp[x] != 0)
    return dp[x];
    
    //Rec case
    long long int ans=INT_MAX;
    
    for(long long int i=0;i<n;i++)
    {
        if(x-coins[i] >= 0)
        {
            long long int s = fun(x-coins[i],coins,n,dp);
            ans = min(ans,s+1);
        }
    }
    
    return dp[x] = ans;
}
 
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
    
   
    
    cout << (fun(x,coins,n,dp) >= INT_MAX ? -1 : fun(x,coins,n,dp)) << endl;
    
    return 0;
}