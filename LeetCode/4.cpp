class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
        double result;
        bool is_even = (len % 2) == 0;
        int mid = (len+1) / 2;
        
        if(nums1.size() == 0){  // 如果数组1为空
            if(is_even){
                return (nums2[mid] + nums2[mid-1])/2.0;
            }
            else{
                return nums2[mid-1]/1.0;
            }
        }
        if(nums2.size() == 0){  // 如果数组2为空
            if(is_even){
                return (nums1[mid] + nums1[mid-1])/2.0;
            }
            else{
                return nums1[mid-1]/1.0;
            }
        }
        int tmp1, tmp2;
        int i = 0;  // 不断扫描nums1
        int j = 0;  // 不断扫描nums2
        int count = 0;  // 记录已经扫描过的元素的个数
        bool flag;  //标识当前指向位nums1(true)或nums2(false)
        while(i <= nums1.size() || j <= nums2.size()){
            if(i >= nums1.size()){  // 如果nums1扫描完了
                j++;
                count++;
                flag = false;
            }
            else if(j >= nums2.size()){  // 如果nums2扫描完了
                i++;
                count++;
                flag = true;
            }
            else if(nums1[i] <= nums2[j]){
                i++;
                count++;
                flag = true;
            }
            else{
                j++;
                count++;
                flag = false;
            }
            if(count == mid){  //扫描到最中间的元素
                if(is_even){  // 如果总数为偶数个，则需再取一个元素计算平均
                    if(flag){  // 如果此时指向的为nums1数组
                        int tmp;
                        if(j >= nums2.size()){  //nums2已经扫描完，则取nums1[i-1]和nums2[i]的平均
                            tmp = nums1[i];  
                        }
                        else{  // 如果nums2尚未扫描完，则取nums1[i]和nums2[j]中的较小者，与nums1[i-1]做平均
                            if(i >= nums1.size()){  //nums1[i]为nums1数组中的最后一个元素
                                tmp = nums2[j];
                            }
                            else{
                                tmp = nums1[i]<nums2[j] ? nums1[i] : nums2[j];
                            }
                        }
                        result = (nums1[i-1] + tmp) / 2.0;
                    }
                    else{  // 如果此时指向nums2的数组
                        int tmp;
                        if(i >= nums1.size()){  //nums1已经扫描完，则取nums2[j-1]和nums2[j]的平均
                            tmp = nums2[j];  
                        }
                        else{  // 如果nums1尚未扫描完，则取nums1[i]和nums2[j]中的较小者，与nums2[j-1]做平均
                            if(j >= nums2.size()){  //nums1[i]为nums1数组中的最后一个元素
                                tmp = nums1[i];
                            }
                            else{
                                tmp = nums1[i]<nums2[j] ? nums1[i] : nums2[j];
                            }
                        }
                        result = (nums2[j-1] + tmp) / 2.0;
                    }
                }
                else{  // 如果总数为奇数个
                    if(flag){
                        result = nums1[i-1] * 1.0;
                    }
                    else{
                        result = nums2[j-1] * 1.0;
                    }
                }
                break;
            }

        }
        return result;
    }
};
