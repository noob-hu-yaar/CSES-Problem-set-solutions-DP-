//Here, We use the bottom up DP approach to solve the question.

#include <bits/stdc++.h>
//#define mod 1000000007
using namespace std;
 
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
 
  int n;
  int mod = 1e9+7;
  cin >> n;
  
  vector<int> dp(n+1,0);
  
  dp[0] = 1;
  
  for (int i = 1; i <= n; i++)
  {
     // dp[i]=0;
    for (int j = 1; j <= 6 ; j++)
    {
        if( i-j >= 0)
        {
      dp[i] += dp[i-j] ;
      dp[i] = dp[i] % mod;
        }
    }
  }
  cout << dp[n] << endl;
 
    return 0;
    
}