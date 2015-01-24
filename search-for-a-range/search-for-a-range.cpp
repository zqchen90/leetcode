class Solution {
public:
     vector<int> searchRange(int A[], int n, int target) {
        vector<int> re;
		int pos = BSearch(A,0,n-1,target);
		if(pos ==-1)
		{
			re.push_back(-1);
			re.push_back(-1);
			return re;
		}
		else
		{
			re.push_back(pos);
			re.push_back(pos);

			int i = pos-1;
			while(i>=0)
			{
				if(A[i] == target){
					re[0] = i;
					i--;
				}
				else
					break;
			}

			i = pos+1;
			while(i<n){
				if(A[i] == target){
					re[1] = i;
					i++;
				}
				else
					break;
			}
		}
		return re;
    }
    
private:
     int BSearch(int A[], int left, int right, int target){
        int middle = (left+right)/2;
        if(left>right)
            return -1;
        if(A[middle] == target)
            return middle;
        if(A[middle] > target)
            return BSearch(A, left, middle-1, target);
        else
            return BSearch(A, middle+1, right, target);
    }
};