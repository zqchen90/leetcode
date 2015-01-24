class Solution {
public:
    int singleNumber(int A[], int n) {
        // find max
		int max = A[0];
		int min = A[0];
		if(n>1)
		{
			for(int i=1;i<n;i++){
				max = max>A[i]?max:A[i];
				min = min<A[i]?min:A[i];
			}
		}

		// init bitmap
		int len = (max-min+1)/4+1;
		char* bitmap = new char[len];
		for(int i=0;i<len;i++)
			bitmap[i]=0;

		// find
		for(int i=0;i<n;i++){
			setBitmap(bitmap, A[i]-min);
		}
		for(int i=0;i<n;i++){
			if(isSingle(bitmap, A[i]-min))
				return A[i];
		}
		
		return -1;
    }
private:
	void setBitmap(char* bitmap, int index){
		int arrayidx = index/4;
		int bitidx1 = index%4 * 2, bitidx2 = bitidx1 +1;
		char op1 = 1<<bitidx1, op2 = 1<<(bitidx2);
		bool flagRep = false;

		bool flag1 = (bitmap[arrayidx] & op1) >0;
		bool flag2 = (bitmap[arrayidx] & op2) >0;

		if(!flag1 && !flag2)
		{
			bitmap[arrayidx] = bitmap[arrayidx] | op1;
		}
		if(flag1 && !flag2)
		{
			bitmap[arrayidx] = bitmap[arrayidx] | op2;
		}
	}

	bool isSingle(char* bitmap, int index){
		int arrayidx = index/4;
		int bitidx1 = index%4 * 2, bitidx2 = bitidx1 +1;
		char op1 = 1<<bitidx1, op2 = 1<<(bitidx2);
		bool flagRep = false;

		bool flag1 = (bitmap[arrayidx] & op1)!=0;
		bool flag2 = (bitmap[arrayidx] & op2) !=0;

		if(flag1 && !flag2)
			return true;
		return false;
	}

};