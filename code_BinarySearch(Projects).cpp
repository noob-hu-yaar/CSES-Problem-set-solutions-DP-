

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
struct job
{
    ll start,finish,money;
};
 
bool comp(job j1,job j2)
{
    return (j1.finish < j2.finish);
}
 
int find(job a[],ll ind)
{
    ll l = 0,h = ind-1;
 
    while(l <= h)
    {
        ll mid = (l+h)/2;
        if(a[mid].finish < a[ind].start)
        {
            if(a[mid+1].finish < a[ind].start)
            l = mid + 1;
 
            else
            return mid;
        }
 
        else
        h = mid - 1;
 
    }
    return -1;
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n;
    cin>>n;
 
    struct job a[n];
    for(ll i=0;i<n;i++)
    cin>>a[i].start>>a[i].finish>>a[i].money;
 
    sort(a,a+n,comp);
 
    ll *dp = new ll[n];
    dp[0] = a[0].money;
 
    for(ll i=1;i<n;i++)
    {
        ll temp = a[i].money;
        ll search = find(a,i);
        if(search != -1)
        temp += dp[search];
 
        dp[i] = max(dp[i-1],temp);
    }
 
    cout<<dp[n-1]<<endl;
    delete[] dp;
 
    return 0;
 
}