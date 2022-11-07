class Solution{   
public:
    //Function to partition the array around the range such 
    //that array is divided into three parts.
    void threeWayPartition(vector<int>& array,int a, int b)
    {
        int left=0,mid=0,right=array.size()-1;
        
            while(mid<=right){
            if(array[mid]<a){
                swap(array[mid],array[left]);
                left++;
                mid++;
            }
            else if(array[mid]>=a && array[mid]<=b){
                mid++;
            }
            else if(array[mid]>b){
                swap(array[mid],array[right]);
                right--;
            }
            }
        
    
        
    }
};
