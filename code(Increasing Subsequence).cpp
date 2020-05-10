

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int LongestIncreasingSubsequenceLength(vector<ll int>& v)  
{  
    if (v.size() == 0)  
        return 0;  
  
    vector<ll int> tail(v.size(), 0);  
    ll int length = 1;  
  
    tail[0] = v[0];  
      
    for (ll int i = 1; i < v.size(); i++) 
    {  
  
            //  binary search   
            
        auto b = tail.begin(), e = tail.begin() + length; 
        auto it = lower_bound(b, e, v[i]);  
              
        
        if (it == tail.begin() + length) 
        tail[length++] = v[i];  
        else   
        *it = v[i];  
    }  
  
    return length;  
}  
  
int main()  
{  
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll int n;
    cin>>n;

    vector<ll int> v(n);
    for(ll int&i : v)
    cin>>i;

     
    cout << LongestIncreasingSubsequenceLength(v) <<endl; 
             
    return 0;  
}