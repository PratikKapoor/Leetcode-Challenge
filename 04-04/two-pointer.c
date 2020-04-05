void moveZeroes(int* nums, int numsSize){
    int iter = 0;
    int i;
    
    for (i=0;i<numsSize; i++) {
        if (nums[i]!=0) {
            // Pointer 'iter' tracks all non-zero elements.
            nums[iter] = nums[i];
            
            // Make element 0 if it has been relocated.
            if (i!=iter) {
                nums[i] = 0;
            }
            
            // Increment pointer to next position.
            iter += 1;
        }
    }
    
    // Fill rest of the array with 0's.
    for (i=iter+1;i<numsSize;i++) {
        nums[i] = 0;
    }
    
    return nums;
}
