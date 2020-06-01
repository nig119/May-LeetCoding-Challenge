class Solution {
public:
    bool rec(unordered_map<int,vector<int>> &umap,vector<int> &visited,int index){
        if (visited[index]==1){
            return false;
        }
        visited[index] = 1 ;
        for( auto v : umap[index]){
            if (visited[v]!=2){
                if (!rec(umap,visited,v)){
                    return false;
                }
            }
        }
        visited[index] = 2 ;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> umap ;
        for(auto v : prerequisites){
            umap[v[1]].push_back(v[0]) ;
        }
        vector<int> visited(numCourses,0);
        for(int i = 0 ; i < numCourses; i++){
            if(visited[i] != 2 ){
                if (!rec(umap,visited,i)){
                    return false;
                }
            }
        }
        return true;
    }
};
