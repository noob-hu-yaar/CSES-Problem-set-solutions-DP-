

#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
struct job
{
    ll start,finish,money;
};
 
bool comp(job j1,job j2)//comparator func used to sort according to the finish times.
{
    return (j1.finish < j2.finish);
}
 
int find(job a[],ll ind)//Find the latest job that comes before the job no. i.
{
    ll l = 0,h = ind-1;
 
    while(l <= h)//Binary Search
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
    //Fast io.
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    ll n;
    cin>>n;
 
    struct job a[n];
    for(ll i=0;i<n;i++) //taking input
    cin>>a[i].start>>a[i].finish>>a[i].money;
 
    sort(a,a+n,comp);// sort based on finish time
 
    ll *dp = new ll[n];
    dp[0] = a[0].money;
 
    for(ll i=1;i<n;i++)
    {
        ll temp = a[i].money; //temp = stores money of project i.
        ll search = find(a,i); 
        if(search != -1)
        temp += dp[search];
 
        dp[i] = max(dp[i-1],temp); //store the max between the dp[i-1] and temp
        //we have basically stored the max between 2 cases. i) if project i is included. ii) if project i is excluded.
     
    }
 
    cout<<dp[n-1]<<endl;
    delete[] dp;
 
    return 0;
 
}
