
//For better understanding,one can refer to the comment based code uploaded for the same using a different technique.
//code_BinarySearch( for comment based )

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
 
int find(job a[],ll i)
{
    for(ll j=i-1;j>=0;j--)
    {
        if(a[j].finish < a[i].start)
        return j;
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
