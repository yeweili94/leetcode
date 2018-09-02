class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: bool
        """
        if len(nums) <= 0:
            return false
        low, high = 0, len(nums) - 1
        while low < high:
            mid = (low + high) / 2
            if nums[mid] == target:
                return true
            if nums[mid] < nums[high]:
                if target > nums[mid] and target <= nums[high]:
                    low = mid + 1
                else:
                    high = mid - 1
            elif nums[mid] > nums[high]:
                if target >= nums[low] and target < nums[mid]:
                    high = mid - 1
                else:
                    low = mid + 1
            else:
                high--
        if target == nums[low]:
            return true
        else:
            return false
