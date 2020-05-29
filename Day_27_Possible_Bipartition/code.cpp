class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<bool>> graph(N, vector<bool>(N, false));
        for ( auto v : dislikes){
            graph[v[0]-1][v[1]-1] = true ;
            graph[v[1]-1][v[0]-1] = true;
        }
        vector<int> visited (N, 0);
        queue<int> q ;

        for (int i =0 ; i < N ; i++){
            if (visited[i] == 0) {
                visited[i] = 1 ;
                q.push(i);
                while(!q.empty()){
                    int k = q.front();
                    for(int j = 0 ; j < N ; j++){
                        if(graph[k][j]){
                            if (visited[j] == 0 ){
                                visited[j] = -1*visited[k] ;
                                q.push(j);
                            }else if (visited[j] == visited[k]){
                                return false ;
                            }
                        }
                    }
                    q.pop() ;
                }
            }
        }

        return true;
    }
};
