func singleNonDuplicate(nums []int) int {
    start := 0
    end := len(nums)-1
    var mid int
    for start != end {
        mid = start + (end-start)/2
        if ((end-start+1)/2)%2 == 1 {
            if nums[mid]==nums[mid+1] {
                end = mid -1
            }else if nums[mid] == nums[mid-1] {
                start = mid +1
            }else {
                return nums[mid]
            }
        }else {
            if nums[mid]==nums[mid-1] {
                end = mid -2
            }else if nums[mid] == nums[mid+1] {
                start = mid +2
            }else {
                return nums[mid]
            }
        }
    }
    return nums[start]
}
