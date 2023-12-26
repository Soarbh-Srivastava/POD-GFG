//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 
//author : Soarbh Srivastava
// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > matrix, int n)
    {
        // code here
        if(n==1){
            return matrix[0][0];
        }
        int det=0;
        for(int i=0;i<n;++i){
            vector<vector<int>> submatrix(n-1,vector<int>(n-1,0));
            for(int j=1;j<n;++j){
                for(int k=0, col=0; k<n; ++k){
                    if(k!=i){
                        submatrix[j - 1][col++] = matrix[j][k];                    }
                }
            }
        det += (i%2==0 ? 1:-1)*matrix[0][i] *determinantOfMatrix(submatrix,n-1);
    }
    return det;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends