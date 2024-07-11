class Solution {
public:
    // int sumofW8(vector<int>&arr1){//if want to use this function just pass arr from high in this function
    //     int sum=0;
    //     for(int i = 0; i<arr1.size(); i++){
    //         sum+=arr1[i];
    //     }
    //     return sum;

    // }
    int FounDays(vector<int> &arr, int cap){
        int day=1; int load = 0;
        for(int i=0; i<arr.size(); i++){
            if(load+arr[i]>cap){
                day++;
                load = arr[i];
            }else{
                load+=arr[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weight, int days) {
        int low = *max_element(weight.begin(),weight.end()), high= accumulate(weight.begin(),weight.end(),0);

        while(low<=high){
            int mid = (low+high)/2;
            int numberofd = FounDays(weight, mid);
            if(numberofd <= days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
        
    }
};
