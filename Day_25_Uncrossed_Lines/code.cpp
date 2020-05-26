class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        vector<vector<int>> DP (A.size() +1 , vector<int>(B.size() +1 , 0)) ;
        
        for (int i = 1 ; i< A.size()+1 ; i ++){
            for (int j = 1 ; j < B.size()+1 ; j++){
               int k = (A[i-1]==B[j-1])? 1 :0 ; 
                DP[i][j] = max (max(DP[i-1][j], DP[i][j-1]), k + DP[i-1][j-1]) ;
            }
        }
        return DP[A.size()][B.size()] ;
    }
};