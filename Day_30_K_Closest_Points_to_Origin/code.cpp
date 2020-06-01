class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto comp = [](vector<int> point1,vector<int> point2){
            return point1[0]*point1[0] + point1[1]*point1[1] < point2[0]*point2[0] + point2[1]*point2[1] ;
        };
       sort(points.begin(),points.end(),comp);
        vector<vector<int>> out (points.begin(),points.begin()+K) ;
        return out;
    }
};