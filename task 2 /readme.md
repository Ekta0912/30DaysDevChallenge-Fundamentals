#include <vector>
#include <iostream>
 int findMissingNumber(std::vector<int> & nums) {
int missing_num = nums.size();
for (int i=0; i < nums.size();i++) { 
missing_num^=i^nums[i];
}
return missing_num;
}

int main() {
std::vector<int>nums= {9,6,4,2,3,5,7,0,1 };
int missing_number = findMissingNumber(nums);
std::cout<<"The missing number is: " <<missing_number<<std::endl;
return 0;
}
