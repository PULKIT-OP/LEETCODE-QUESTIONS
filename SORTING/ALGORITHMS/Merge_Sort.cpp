// Question Link: 

void merge(vector<int> &arr, int l, int mid, int r){
    vector<int> result;

    int i = l;
    int j = mid+1;

    while(i <= mid && j <= r){
        if(arr[i] < arr[j]){
            result.push_back(arr[i]);
            i++;
        }
        else{
            result.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        result.push_back(arr[i]);
        i++;
    }
    while(j <= r){
        result.push_back(arr[j]);
        j++;
    }

    for(int k = l; k <= r; k++){
        arr[k] = result[k-l];
    }
}

void ms(vector<int> &arr, int l, int r){
    if(l >= r){
        return;
    }
    int mid = (r+l)/2;
    ms(arr, l, mid);
    ms(arr, mid+1, r);

    merge(arr, l, mid, r);
}

void mergeSort(vector < int > & arr, int n) {
    // Write your code here.
    return ms(arr, 0, n-1);
}
