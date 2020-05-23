class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<pair<int,int>>> dp (matrix.size(),
                        vector<pair<int,int>>(matrix[0].size(),make_pair(0,0)));
        int i = matrix.size()-1 ;
        int j = matrix[0].size()-1 ;
        dp[i][j].first = (matrix[i][j] == 1) ? 1 : 0 ;
        dp[i][j].second  = (matrix[i][j] == 1) ? 1 : 0 ;
        for (int i = matrix.size()-2 ; i >=0 ; i--){
            int j =  matrix[0].size()-1 ;
            dp[i][j].first += (matrix[i][j] == 1) ? 1 : 0 ;
            dp[i][j].first += dp[i+1][j].first ;
            dp[i][j].second += (matrix[i][j] == 1) ? 1 : 0 ;
        }
        for (int j = matrix[0].size()-2 ; j >=0 ; j--){
            int i =  matrix.size()-1 ;
            dp[i][j].first += (matrix[i][j] == 1) ? 1 : 0 ;
            dp[i][j].first += dp[i][j+1].first ;
            dp[i][j].second += (matrix[i][j] == 1) ? 1 : 0 ;
        }

        for(int i = matrix.size()-2 ; i >=0 ; i--){
            for (int j = matrix[0].size()-2 ; j >=0 ; j--){
                dp[i][j].first += dp[i][j+1].first + dp[i+1][j].first - dp[i+1][j+1].first ;
                dp[i][j].second = (matrix[i][j]==1) ? 1+min(min(dp[i+1][j].second,dp[i][j+1].second), dp[i+1][j+1].second):0 ;
                dp[i][j].first += dp[i][j].second ;
            }
        }
        return dp[0][0].first;
    }
};
