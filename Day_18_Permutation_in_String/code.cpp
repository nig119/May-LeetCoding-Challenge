class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> arr1(26,0);
        for (auto c : s1){
            arr1[c-'a'] += 1;
        }
        vector<int> arr2(26,0);
        for (int i =0 ; i < s2.size() ; i++){
            arr2[s2[i]-'a'] += 1 ;
            int j = i-s1.size() ;
            if (j >= 0 )  arr2[s2[j] - 'a'] -= 1 ;
            if (arr1 == arr2) return true ;
        }
        return false;
    }
};