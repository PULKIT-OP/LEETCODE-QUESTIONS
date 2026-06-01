// Question Link: https://www.geeksforgeeks.org/problems/selection-sort/1

// Selection Sort ----> SELECTION OF SMALLEST then swap with starting node then move forward
// TC: O(N^2)
class Solution {
	public:
	// Function to perform selection sort on the given array.
	void selectionSort(vector<int> &arr) {
		// code here
		int n = arr.size();
		int min = 0;
		for (int i = 0; i < n; i++) {
		    min = i;
			for (int j = i + 1; j < n; j++) {
				if (arr[j] < arr[min]) {
					min = j;
				}
			}
			swap(arr[i], arr[min]);
		}
	}
};
