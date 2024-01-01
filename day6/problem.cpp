//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

//author : Soarbh Srivastava
//#2024 #1 POTD
// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
    if (nums.size() % 2 != 0) {
        return false;
    }

    unordered_map<int, int> remainderFreq;

    for (int num : nums) {
        int remainder = num % k;
        remainderFreq[remainder]++;
    }
    
    if (remainderFreq[0] % 2 != 0) {
        return false;
    }
    
    for (int i = 1; i <= k / 2; ++i) {
        if (i != k - i && remainderFreq[i] != remainderFreq[k - i]) {
            return false;
        }
    }

    return true;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends