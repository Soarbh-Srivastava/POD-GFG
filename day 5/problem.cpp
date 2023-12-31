//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
//author: soarbh srivastava

class Solution {
public:
    bool isPossible(int N, int coins[]) {
        int total_coins = 0;
        for (int i = 0; i < N; ++i) {
            total_coins += coins[i];
        }

        bool dp[N + 1][total_coins + 1];

        for (int i = 0; i <= N; ++i) {
            for (int j = 0; j <= total_coins; ++j) {
                dp[i][j] = false;
            }
        }

        for (int i = 0; i <= N; ++i) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= total_coins; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j >= coins[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j - coins[i - 1]];
                }
            }
        }

        for (int j = total_coins; j > 0; --j) {
            if (dp[N][j] && (j % 20 == 0 || j % 24 == 0 || j == 2024)) {
                return true;
            }
        }

        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int coins[N];
        for(int i=0 ; i<N ; i++)
            cin>>coins[i];

        Solution ob;
        cout << ob.isPossible(N,coins) << endl;
    }
    return 0;
}
// } Driver Code Ends