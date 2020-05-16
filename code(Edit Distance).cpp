

#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    fast_io;

    string s1,s2;
    cin>>s1>>s2; //taking input

    int len_s1 = s1.size();
    int len_s2 = s2.size();
    int dp[len_s1+1][len_s2+1];

    for(int i=0;i<=len_s1;i++)
    {
        for(int j=0;j<=len_s2;j++)
        {
            if(i == 0)
            dp[i][j] = j; //when s1 is empty, we just have to copy j elements of string s2

            else if(j == 0)
            dp[i][j] = i; // when s2 is empty, we just have to remove i elements present in s1.

            else if(s1[i-1] == s2[j-1])
            dp[i][j] = dp[i-1][j-1]; // if the last element is same in both s1 & s2, just copy the previous dp value. No more changes needed

            else
            {
                dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                //case1 = dp[i][j-1] = when we insert an element in s1. 
                //After insertion, we calculate the dp[for the rest of s1(i)][for the rest of s2 other than the last element which is inserted in s1(j-1)].

                //case2 = dp[i-1][j] = when we remove element from s1. We calculate dp[rest of s1(i-1)][rest of s2(j)]

                //case3 = dp[i-1][j-1] = when element of s1 is replaced. 

                //calculate min of the three. 1 is added as each case counts to 1 operation
            }
        }
    }

    cout<<dp[len_s1][len_s2]<<endl;
    return 0;
}
