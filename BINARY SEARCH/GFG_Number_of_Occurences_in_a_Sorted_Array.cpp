// Question Link: https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1


// METHOD 1: Finding out First Occurence of the target and Last Occurence then calculating number of occurence if exist   ---->   Binary Search
class Solution {
	public:
	int countFreq(vector<int>& nums, int target) {
		// code here
		int s = 0;
		int e = nums.size() - 1;
		int start = -1;
		int end = -1;
		// Starting position
		while (s <= e) {
			int mid = s + (e - s)/2;
			if (nums[mid] == target) {
				start = mid;
				e = mid - 1; // may be there exist a smaller index of this number so just trying to checkout that bitch.
			}
			else if (nums[mid] > target) {
				e = mid - 1;
			}
			else if (nums[mid] < target) {
				s = mid + 1;
			}
		}
		
		// Ending Position
		s = 0;
		e = nums.size() - 1;
		while (s <= e) {
			int mid = s + (e - s)/2;
			if (nums[mid] == target) {
				end = mid;
				s = mid + 1; // may be there exist a greater index of that nubmer x, so just trying to check that bitch out.
			}
			else if (nums[mid] > target) {
				e = mid - 1;
			}
			else if (nums[mid] < target) {
				s = mid + 1;
			}
		}
		
		if(start != -1 && end != -1){
		    return end - start + 1;
		}
		return 0;
	}
};
