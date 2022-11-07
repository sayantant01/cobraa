class Solution {
public:
    int search(vector<int>& nums, int target) {
       int p = findPivotElement(nums);
        int n =nums.size();
        int ans = BinarySearch(nums ,  0, p,  target);
        if(ans != -1){
            return ans ;
            
        }
        else 
            {ans = BinarySearch(nums ,  p+1,n-1,target);
            return ans;
            }
    }
    
    
    
    int findPivotElement(vector<int>& nums){
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<=end){
            int mid = start + (end - start)/2;
            if ( mid<end && nums[mid]>nums[mid+1]){
                return mid;
            }
            if(mid > start && nums [mid] < nums[mid-1]){
                return mid-1;
            }
            if(nums[start] > nums[mid]){
                end = mid-1;
            }
            else {
                start=mid+1;
            }
        }
        return -1;
        
    }
    
    
    int BinarySearch(vector<int>& nums ,  int start , int end , int target){
        int n = nums.size();
        int s = start;
        int e = end;
        while(s<=e){
           int mid = s + (e- s)/2;
           if(nums[mid]>target){
               e=mid-1;
           }
            else if(nums[mid]<target){
                s=mid+1;
            }
            else {
                return mid;
            }         
        }
        return -1;
        
    }
};
