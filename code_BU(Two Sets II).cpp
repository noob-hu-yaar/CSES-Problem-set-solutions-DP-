#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,mod=1e9+7;
    cin>>n;

    int S = n*(n+1)/2; //calculate total sum 1 to n
    int s = S/2; // total sum / 2 = requires sum of each subset

    vector<vector<int>> dp(n+1,vector<int>(s+1,0)); //2D vector declared
    //dp[i][sum] = no. of ways to make sum using numbers 0 to i

    
        dp[0][0] = 1;// number of ways to make 0 using 0 = 1

        for(int sum=0;sum<=s;sum++)
        {
            
            for(int i=1;i<n;i++)//till n-1 as we permanently put n into a particular subset to avoid repeats
            {
                dp[i][sum] = dp[i-1][sum];
                if(sum - i >= 0)
                {
                    dp[i][sum] = dp[i-1][sum] + dp[i-1][sum-i];
                    // ways = (either not include that number keeping the sum same) or (include the number decreasing sum by i.)
                    dp[i][sum] %= mod;
                }
            }
        }
        (S%2 != 0) ? (cout<<0<<endl) : (cout<<dp[n-1][s]<<endl); //if S is odd, it is not possible to divide it into 2 equal subsets, so print 0.
    
    return 0;
}
