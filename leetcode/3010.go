//problem: https://leetcode.com/problems/divide-an-array-into-subarrays-with-minimum-cost-i/
func minimumCost(nums []int) int {
    res := nums[0]
    nums = nums[1:]
    sort.Ints(nums)
    
    res += nums[0] + nums[1]

    return res

}
