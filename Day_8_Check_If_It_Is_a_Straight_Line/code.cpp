class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0] ;
        int y1 = coordinates[0][1] ;
        int incx = coordinates[1][0]-x1 ;
        int incy = coordinates[1][1]-y1 ;
        for(int i = 2 ; i < coordinates.size() ; i++){
            if ((coordinates[i][1]-y1)*incx != incy*(coordinates[i][0]-x1)) {
                return false ;
            }
        }
        return true ;
    }
};