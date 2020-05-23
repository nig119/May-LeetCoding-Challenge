class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char>> arr (128, make_pair(0,(char)0)) ;
        for (auto c : s) {
            arr[c].first +=1 ;
            arr[c].second = c ;
        }
        sort(arr.begin(),arr.end());
        string out = "" ;
        for (int j = 127 ; j >=0 ; j--) {
            pair<int,char> p = arr[j] ;
            for (int i = 0 ; i < p.first ; i++) {
                out += p.second;
            }
        }
        return out;
    }
};