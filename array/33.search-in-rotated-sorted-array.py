class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        if len(nums) == 0:
            return -1
        low, high = 0, len(nums) - 1
        while low < high :
            mid = (low + high) / 2
            if nums[mid] < nums[high]:
                if target > nums[low] and target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1
            else:
                if target >= nums[low] and target < nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
        if nums[low] == target:
            return low
        else:
            return -1
