func majorityElement(nums []int) int {
    num := -1
    count := 0
    for _,k := range nums{
        if count == 0 {
            num = k
            count++
        }else {
            if k == num {
                count++
            }else {
                count--
            }
        }
    }
    return num
}
