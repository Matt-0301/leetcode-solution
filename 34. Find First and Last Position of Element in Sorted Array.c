/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int *result = (int*)malloc(2*sizeof(int));
    *(result + 0) = -1;
    *(result + 1) = -1;
    *returnSize = 2;
    if(numsSize == 0)   return result;
    int left, right, mid;
    for(int i = 0; i < 2; i++){
        left = 0;
        right = numsSize - 1;
        mid = (left + right) / 2;

        while(left <= right){
            if(*(nums + mid) < target){
                left = mid + 1;
            }else if(*(nums + mid) == target){
                if(i == 0){ // check First position
                    right = mid - 1;
                }else{ // check last position
                    left = mid + 1;
                }
            }else{
                right = mid - 1;
            }

            mid = (left + right) / 2;
        }
        // printf("%d %d\n", left, right);
        if(i == 0 && (left >= numsSize || *(nums + left) != target))  return result;
        else if(i == 0 && *(nums + left) == target)  *(result + i) = left;
        else    *(result + i) = right;
    }
    return result;
}   
