//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
        // code here
    bool isValidSplit(int arr[], int N, int K, int mid) {
        int currentSum = 0;
        int subarrayCount = 0;

        for (int i = 0; i < N; i++) {
            if (arr[i] > mid) {
                return false;
            }

            currentSum += arr[i];
            if (currentSum > mid) {
                subarrayCount++;
                currentSum = arr[i];
            }
        }
        subarrayCount++;

        return subarrayCount <= K;
    }


    int splitArray(int arr[], int N, int K) {
        int minPossibleSum = 0, maxPossibleSum = 0;

        for (int i = 0; i < N; i++) {
            minPossibleSum = max(minPossibleSum, arr[i]);
            maxPossibleSum += arr[i];
        }

        int result = maxPossibleSum;
        while (minPossibleSum <= maxPossibleSum) {
            int mid = (minPossibleSum + maxPossibleSum) / 2;
            if (isValidSplit(arr, N, K, mid)) {
                result = mid;
                maxPossibleSum = mid - 1;
            } else {
                minPossibleSum = mid + 1;
            }
        }

        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends