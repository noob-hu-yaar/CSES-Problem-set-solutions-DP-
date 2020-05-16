


#include <bits/stdc++.h> 
#define ll long long
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 

int main()
{
    fast_io;

    ll n;
    cin>>n; //taking input

    vector <ll> dp(n+1,INT_MAX); //dp[i] stores min ways to make i=0
    dp[0] = 0; 
    
    for(ll i=0;i<=n;i++) // iterate all elements from 0 to n
    {
        for(char s : to_string(i)) // change the number to string, and iterate over all elements of the string to find min steps
        {
            dp[i] = min(dp[i], dp[i-(s-'0')]+1);
        }
    } 

    cout<<dp[n]<<endl;
    return 0;
}
