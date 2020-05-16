//Space optimised solution.
//O(2 x len_s1) space complexity

#include <bits/stdc++.h> 
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std; 

int main() 
{ 
    fast_io;
  	
	string s1,s2; //input taken
	cin>>s1>>s2;

	int len_s1 = s1.size();
	int len_s2 = s2.size(); 

	//initialise a dp array with all 0.
	int dp[2][len_s1 + 1]; 
	memset(dp, 0, sizeof(dp)); 

	for (int j = 0; j <= len_s1; j++) //when len_s2 = 0, we need to remove all of s2
		dp[0][j] = j; 

	for (int i = 1; i <= len_s2; i++) //start looping over all elements of the s2 string
	{ 
		for (int j = 0; j <= len_s1; j++) 
		{ 
			if (j == 0) 
				dp[i % 2][j] = i; //when all of s1 is empty, fill s1

			else if (s1[j - 1] == s2[i - 1]) 
				dp[i % 2][j] = dp[(i - 1) % 2][j - 1]; //last element is same,so no changed needed
			
			else  
				dp[i % 2][j] = 1 + min(dp[(i - 1) % 2][j],	min(dp[i % 2][j - 1], dp[(i - 1) % 2][j - 1]));
			 //case 1 = insert 
			 //case 2 = remove
			 //case 3 = replace
		} 
	} 
	//modulo taken to store values in odd and even places
	cout << dp[len_s2 % 2][len_s1] << endl; 

	return 0; 
} 
