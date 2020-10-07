class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()){  //保证数组1为元素较少的数组
            return findMedianSortedArrays(nums2, nums1);
        }
        int len = nums1.size() + nums2.size();
        int mid = len/2 + 1;
        bool is_even = (len%2) == 0;
        if(is_even){
            if(nums1.size() == 0){ // 数组1为空的情况
                return (nums2[mid-2]+nums2[mid-1])/2.0;
            }
            if(nums1.size() == nums2.size() && nums1[0]>=nums2[nums2.size()-1]){
                //两个数组长度相同时考虑数组1无元素在左段的情况
                return (nums2[nums2.size()-1]+nums1[0])/2.0;
            }
            if(nums1.size() != nums2.size() && nums1[0]>=nums2[mid-1]){
                //两个数组长度不相同，但是数组1无左段元素情况
                return (nums2[mid-2]+nums2[mid-1])/2.0;
            }
        }
        else{
            if(nums1.size() == 0){
                return nums2[mid-1]*1.0;
            }
            if(nums1[0]>=nums2[mid-1]){
                //两个数组长度不相等时考虑数组1无左段元素情况
                return nums2[mid-1] * 1.0;
            }
        }
        double result;
        int i, j;  //i和j分别用来扫描数组一和数组二，i和j分别为左段的最后一个元素。
        //这样导致的一个结果是，数组1中一定有元素分到了左段，因此需单独考虑数组1中左段无元素
        int low = 0; 
        int high = nums1.size()-1;
        
        while(low <= high){  
            i = (low+high)/2;
            j = mid -i -2;
            if(i+1 >= nums1.size()){
                //
                break;
            }
            if(j+1 >= nums2.size()){
                if(nums2[j] <= nums1[i+1]){  //如果j指向最后一个元素时满足条件
                    break;
                }
                else{  //不满足条件的话，把i向右移
                    low = i + 1;
                    continue;
                }
            }
            if(nums2[j]>nums1[i+1]){
                low = i+1;
            }
            else if(nums1[i]>nums2[j+1]){
                high = i-1;
            }
            else{
                break;
            }
        }
        if(is_even){         
            int tmp1, tmp2;
            if(i>=1){
                tmp1 = nums1[i-1] > nums2[j] ? nums1[i-1] : nums2[j];
            }
            else{
                tmp1 = nums2[j];
            }
            if(j >= 1){
                tmp2 = nums1[i] > nums2[j-1] ? nums1[i] : nums2[j-1];
            }
            else{
                tmp2 = nums1[i];
            }
            result = (tmp1 + tmp2)/2.0;
            return result;
        }
        else{       
            result = nums1[i] > nums2[j] ? nums1[i] : nums2[j];
            return result;
        }
       
    }
};
