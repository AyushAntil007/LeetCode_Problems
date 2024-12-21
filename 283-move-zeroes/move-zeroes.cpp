class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();

        //brute force

    //    vector<int>temp;
    //    for(int i=0;i<n;i++){         //store non zero elt
    //     if(nums[i]!=0){
    //         temp.push_back(nums[i]);
    //     }
    //    }
    //    for(int i=0;i<temp.size();i++){  //place non zero elt in front
    //         nums[i]=temp[i];
    //    }
    //    for(int i=temp.size();i<n;i++){   //fill zero at end
    //     nums[i]=0;
    //    }


    //optimal solution

    int index=0;
    for(int j=0;j<n;j++){     //two pointer approach
        if(nums[j]!=0){
            nums[index]=nums[j];
            index++;
        }
    }
    for(int i=index;i<n;i++){
        nums[i]=0;
    }

    }
};