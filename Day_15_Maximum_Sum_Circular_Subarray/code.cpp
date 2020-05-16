class Solution {
public:
    int kadens(vector<int>&nums , int k){
        int local_sum = k*nums[0] ;
        int global_sum = k*nums[0] ;
        for (int i = 1 ; i < nums.size() ; i++){
            local_sum = max(local_sum+k*nums[i],k*nums[i]);
            global_sum = max(global_sum, local_sum);
        }
        return global_sum ;
    }
    int maxSubarraySumCircular(vector<int>& A) {
        int sum = accumulate(A.begin(),A.end(),0);
        int b = kadens(A,-1) ;
        int a = kadens(A,1) ;
        if (b == -1*sum) {
            return a;
        }
       return max(a,b+sum ) ;
    }
};