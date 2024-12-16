import time

def findMedianSortedArrays(nums1, nums2):
    # Ensure nums1 is the smaller array
    if len(nums1) > len(nums2):
        nums1, nums2 = nums2, nums1

    m, n = len(nums1), len(nums2)
    low, high = 0, m

    while low <= high:
        i = (low + high) // 2  # Partition index for nums1
        j = (m + n + 1) // 2 - i  # Partition index for nums2

        # Elements on the left and right of the partition
        maxLeft1 = float('-inf') if i == 0 else nums1[i - 1]
        minRight1 = float('inf') if i == m else nums1[i]

        maxLeft2 = float('-inf') if j == 0 else nums2[j - 1]
        minRight2 = float('inf') if j == n else nums2[j]

        # Check if we have found the correct partition
        if maxLeft1 <= minRight2 and maxLeft2 <= minRight1:
            # If the combined length is odd, return the max of the left side
            if (m + n) % 2 == 1:
                return max(maxLeft1, maxLeft2)
            # If the combined length is even, return the average of the middle elements
            return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2
        elif maxLeft1 > minRight2:
            # Move left in nums1
            high = i - 1
        else:
            # Move right in nums1
            low = i + 1

# Example usage
nums1 = [1, 3]
nums2 = [2]

# Start timing
start_time = time.time()

# Run the function
result = findMedianSortedArrays(nums1, nums2)

# End timing
end_time = time.time()

# Print the result and the time taken
print("Median:", result)
print(f"Time taken: {end_time - start_time} seconds")
