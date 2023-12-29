//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
//author: soarbh srivastava


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k)
	{
	     if (n % k != 0) {
            return 0;
        } else {
            unordered_map<string, int> mapping;
            for (int i = 0; i < n; i += k) {
                mapping[s.substr(i, k)]++; // Count occurrences of substrings
            }
            if (mapping.size() == 1) {
                return 1; // All substrings are the same
            }
            if (mapping.size() == 2) {
                for (auto x : mapping) {
                    if (x.second == 1) {
                        return 1; // Two different substrings, one occurs only once
                    }
                }
            }
            return 0; // No pattern found
        }
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends