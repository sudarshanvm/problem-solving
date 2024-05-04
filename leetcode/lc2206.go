//problem: https://leetcode.com/problems/divide-array-into-equal-pairs/
func divideArray(nums []int) bool {
    sort.Ints(nums)
    for i:=0; i<len(nums)-1; i+=2 {
        if nums[i] != nums[i+1] {
            return false
        }
           
    }

    return true
}
