class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> vote (N,0);
        for(auto v : trust){
            vote[v[0]-1] = -1 ;
            if(vote[v[1]-1] != -1 ) {
                vote[v[1]-1] ++; 
            }
        }
        for(int i = 0 ; i < N ; i++){
            if(vote[i] == N-1) return i+1;
        }
        return -1;
    }
};