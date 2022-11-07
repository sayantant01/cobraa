class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int presum=0;
        int ans=0;
        map<int, int> mp;
        
    //insert an extra 0 because if a sum is divisible by k so we have to add it in the answer
        mp.insert({0,1}); 
        
        // we add the frequency of a remainder to the answer
        for(int i=0; i<n; i++){
            presum += nums[i];
            int temp=presum%k;
            if(temp<0)
            //if the remainder is negative then its positve complementary will be (rem+k) 
                temp += k;
            if(mp.find(temp) != mp.end()){
                ans += mp[temp];
                mp[temp]++;   
            }
            else
                mp[temp]=1;
        }
        return ans;
    }
};
