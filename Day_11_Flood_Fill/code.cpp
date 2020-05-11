class Solution {
public:
    void rec(vector<vector<int>>&img , int sr, int sc, int newColor, int oldColor,
             vector<vector<bool>>&visited){
        if(sr== -1 || sr == img.size() || sc == -1 || sc == img[0].size() ||
           visited[sr][sc] || img[sr][sc] != oldColor) return;
        visited[sr][sc] = true ;
        vector<vector<int>> mov = {{0,1},{1,0},{-1,0},{0,-1}} ;
        img[sr][sc] = newColor ;
        for (auto v : mov){
                rec(img,sr+v[0],sc+v[1],newColor,oldColor,visited);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        vector<vector<int>> out(image.begin(),image.end());
        vector<vector<bool>> visited(image.size(), vector<bool>(image[0].size(),false)) ;
        rec(out,sr,sc,newColor, out[sr][sc],visited);
        return out ;
    }
};
