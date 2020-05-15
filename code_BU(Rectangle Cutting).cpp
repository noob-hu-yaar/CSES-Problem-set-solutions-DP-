

#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    fast_io;
    
    int a,b; //taking input
    cin>>a>>b;

    vector <vector<int>> dp(a+1,vector<int> (b+1)); //

    for(int i=0;i<=a;i++)
    {
        for(int j=0;j<=b;j++)
        {
            //Base Case
            if(i == j) //when i==j, it is already a square,so 0 cuts needed.
            dp[i][j] = 0;

            else
            {
                dp[i][j] = INT_MAX; //initially max

                for(int k=1;k<i;k++)
                dp[i][j] = min(dp[i][j], dp[k][j]+dp[i-k][j]+1); //check for min possible among all possible cuts in i (horizontally)

                for(int k=1;k<j;k++)
                dp[i][j] = min(dp[i][j], dp[i][k]+dp[i][j-k]+1); //check for min possible among all possible cuts in j (vertically)
            }
        }
    }
    cout<<dp[a][b]<<endl;

    return 0;
}
