class search2dmatrix{
    public boolean findtarget(int[][] matrix,int target){
        int rows = matrix.length;
        int cols = matrix[0].length;
        int low = 0;
        int high = rows*cols-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int mid_point = matrix[mid/cols][mid%cols];
            if(mid_point==target){
                return true;
            }else if(mid_point>target){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return false;
    }
    int[][] matrix = {{1,2,3,4,5},{6,7,8,9},{10,11,12,13}};
    int target = 11;

}