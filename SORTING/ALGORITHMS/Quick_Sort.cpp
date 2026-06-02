// Question Link: 


// Take a Pivot of your choice  --->  Then place it at its actual position ---> then solve for left and right half separatly through recursion
// METHOD 1: Pivot as Low    --->   Code Sutdio 360

int partition(vector<int> &arr, int low_idx, int high_idx){
    int i = low_idx;
    int j = high_idx;
    int pivot = arr[low_idx];

    while(i < j){
        while(arr[i] <= pivot && i <= high_idx-1){
            i++;
            // will find first element greater than pivot
        }
        while(arr[j] > pivot && j >= low_idx+1){
            j--;
            // will find first element smaller than pivot
        }
        if(i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low_idx], arr[j]);
    
    return j;
}

void qs(vector<int> &arr, int low, int high){
    if(low < high){
        int part = partition(arr, low, high);
        qs(arr, low, part-1);
        qs(arr, part+1, high);
    }
}

vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    int low = 0;
    int high = arr.size() - 1;

    qs(arr, low, high);

    return arr;
}



// METHOD 2: Pivot as High  ----> GFG

class Solution {
	public:
	void quickSort(vector<int>& arr, int low, int high) {
		// code here
		if (low < high) {
			int part = partition(arr, low, high);
			quickSort(arr, low, part - 1);
			quickSort(arr, part + 1, high);
		}
	}
	
	public:
	int partition(vector<int>& arr, int low, int high) {
		
		// code here
		int pivot = arr[high];
		int p = low;
		
		for (int i = low; i < high; i++) {
			if (arr[i] <= pivot) {
				swap(arr[i], arr[p]);
			    p++;
			}
		}
		
		swap(arr[p], arr[high]);
		return p;
	}
};
