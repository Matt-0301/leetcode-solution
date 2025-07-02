int maximumDifference(int* nums, int numsSize) {
    if(numsSize == 1)   return -1;
    int record = 0, result = 0;
    for(int i = 1; i < numsSize; i++){
        record += nums[i] - nums[i-1];
        if(record > 0 && record > result){
            result = record;
        }else if(record < 0){
            record = 0;
        }
    }

    if(result == 0) return -1;
    return result;
}
