//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
//author: soarbh srivastava
//wildcard matching string
//time complexity O(n^2)
//space complexity O(n^2)
//dp approach
//https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1#


// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wildStr, string patternStr)
    {
        int wildSize = wildStr.size();
        int patternSize = patternStr.size();
        
        vector<vector<int>> dp(wildSize + 1, vector<int> (patternSize + 1, 0));
        dp[wildSize][patternSize] = 1;
        
        for(int i = wildSize - 1; i > -1; i--){
            for(int j = patternSize - 1; j > -1; j--){
                if(wildStr[i] == '?')  
                    dp[i][j] = dp[i + 1][j + 1];
                else if(wildStr[i] == '*'){
                    if(i == wildSize - 1)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = dp[i + 1][j] or dp[i][j + 1];
                }
                else{
                    if(wildStr[i] == patternStr[j])
                        dp[i][j] = dp[i + 1][j + 1];
                    else
                        dp[i][j] = 0;
                }
            }
        }
        
        return dp[0][0];
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends