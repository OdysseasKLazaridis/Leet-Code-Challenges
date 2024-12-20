from typing import List
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numMap = {}  # Dictionary to store number-to-index mappings
        n = len(nums)  # Length of the input list

        # Step 1: Build a hash table with number as key and index as value
        for i in range(n):
            numMap[nums[i]] = i  # Maps each number to its index

        # Step 2: Find the complement (target - current number)
        for i in range(n):
            complement = target - nums[i]  # Calculate the complement for the current number
            if complement in numMap and numMap[complement] != i:  # Check if the complement exists in the map and isn't the same element
                return [i, numMap[complement]]  # Return the indices of the two numbers that sum up to the target

        return []  # If no solution is found, return an empty list


# Main function for testing
def main():
    solution = Solution()  # Create an instance of the Solution class
    
    # Test case 1: Regular case with solution
    nums1 = [2, 7, 11, 15]
    target1 = 9
    print(f'Test case 1: {nums1}, Target: {target1}')
    print('Result:', solution.twoSum(nums1, target1))  # Expected output: [0, 1]
    
    # Test case 2: No solution case
    nums2 = [1, 2, 3, 4]
    target2 = 10
    print(f'Test case 2: {nums2}, Target: {target2}')
    print('Result:', solution.twoSum(nums2, target2))  # Expected output: []
    
    # Test case 3: Case with multiple solutions
    nums3 = [3, 2, 4]
    target3 = 6
    print(f'Test case 3: {nums3}, Target: {target3}')
    print('Result:', solution.twoSum(nums3, target3))  # Expected output: [1, 2]
    
    # Test case 4: Case where numbers are negative
    nums4 = [-1, -2, -3, -4, -5]
    target4 = -8
    print(f'Test case 4: {nums4}, Target: {target4}')
    print('Result:', solution.twoSum(nums4, target4))  # Expected output: [2, 4]
    
    # Test case 5: Case with one element, no solution
    nums5 = [1]
    target5 = 2
    print(f'Test case 5: {nums5}, Target: {target5}')
    print('Result:', solution.twoSum(nums5, target5))  # Expected output: []

# Run the main function
if __name__ == '__main__':
    main()