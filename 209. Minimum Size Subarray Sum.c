int minSubArrayLen(int target, int* nums, int numsSize) {
    int i, left = 0, right = 0, sum = 0, result = INT_MAX;
    for(i = 0; i < numsSize; i++, right++){
        sum += *(nums + i);

        while(sum >= target && left <= right){
            if(right - left + 1 < result){
                result = right - left + 1;
                // printf("%d %d %d\n", left, right, result);
            }
            sum -= *(nums + left);
            left++;
        }
    }
    if(result == INT_MAX)   return 0;
    return result;
}
