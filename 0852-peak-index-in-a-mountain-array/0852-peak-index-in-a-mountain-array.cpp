class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int st=1;
        int end=arr.size()-2;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]>arr[mid-1]){
                //inc-right mai dhundo
                st=mid+1;
            }
            else{
                //left mai dhundo if in decreasing order
                end=mid-1;
            }
        }
        return -1;
    }
};