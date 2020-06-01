class Solution {
public:
    int minDistance(string word1, string word2) {
        if (word1.size()==0){
            return word2.size() ;
        }
        if (word2.size() == 0){
            return word1.size();
        }
        vector<vector<int>> DP (word1.size(), vector<int>(word2.size(),0)) ;
        for(int i = 0 ;i < word1.size() ; i++){
            for(int j = 0 ; j < word2.size(); j++){
                if(i==0 && j==0){
                    DP[i][j] = (word1[i]==word2[j])?0:1 ;
                    continue;
                }
                if (i==0){
                    if(word1[i]==word2[j]){
                        DP[i][j] = j ;
                    }else {
                        DP[i][j] = 1+min(DP[i][j-1], j) ;
                    }
                    continue;
                }
                if (j==0){
                    if(word1[i]==word2[j]){
                        DP[i][j] = i ;
                    }else {
                        DP[i][j] = 1+min(DP[i-1][j], i) ;
                    }
                    continue;
                }
                if(word1[i]==word2[j]){
                    DP[i][j] = DP[i-1][j-1] ;
                }else {
                    DP[i][j] = 1+min(DP[i-1][j-1],min(DP[i-1][j],DP[i][j-1])) ;
                }
            }
        }
        return DP[word1.size()-1][word2.size()-1];
    }
};
