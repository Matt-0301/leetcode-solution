bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    int size = matrixSize * (*matrixColSize);
    int left = 0, right = size-1, mid = (left + right) / 2;
    int row, col;
    while(left <= right){
        // printf("left = %d, right = %d, mid = %d, target = %d\n", left, right, mid, target);
        row = mid / (*matrixColSize);
        col = mid % (*matrixColSize);
        // printf("row = %d, col = %d, val = %d\n", row, col, *(*(matrix+row)+col));
        if(*(*(matrix+row)+col) < target){
            left = mid + 1;
        }else if(*(*(matrix+row)+col) == target){
            return true;
        }else{
            right = mid - 1;
        }

        mid = (left + right) / 2;
    }
    return false;
}
