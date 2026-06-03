// Question Link: https://www.geeksforgeeks.org/problems/rotation4723/1

// METHOD 1: Binary Search 

class Solution {
	public:
	int findKRotation(vector<int> &nums) {
		// Code Here
		int s = 0;
		int e = nums.size() - 1;
		
		int ans = 0;
		int mini = INT_MAX;
		
		while (s <= e) {
			if (nums[s] <= nums[e]) {
				if(nums[s] < mini){
				    mini = nums[s];
				    ans = s;
				}
				break;
			}
			int mid = s + (e - s)/2;
			// Left half sorted??
			if (nums[s] <= nums[mid]) {
				if (nums[s] < mini) {
					mini = nums[s];
					ans = s;
				}
				s = mid + 1;
			}
			else {
				// Right half sorted??
				e = mid - 1;
				if (nums[mid] < mini) {
					mini = nums[mid];
					ans = mid;
				}
			}
		}
		
		return ans;
	}
};
