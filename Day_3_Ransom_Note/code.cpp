class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> arr(128,0);
        for (auto c : magazine) {
            arr[(int)c] +=1;
        }
        for (auto c : ransomNote) {
            if(arr[(int)c] >0){
                arr[(int)c] -= 1;
            }else return false;
        }
        return true;
    }
};