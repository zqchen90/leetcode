class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int rowlen = matrix.size();
		if(rowlen == 0)
			return 0;
		int collen = matrix[0].size();
		if(collen == 0)
			return 0;

		int maxArea = 0;
		if(matrix[0][0] == '1')
			maxArea = 1;

		int lurow = 0, lucol =0;
		int ldrow, rucol;
		for(lurow=0;lurow<rowlen;lurow++)
		{
			for(lucol=0;lucol<collen;lucol++)
			{
				if(matrix[lurow][lucol] == '0')
					continue;
				else{
					ldrow = lurow;
					rucol = lucol;
					int area;
					for(ldrow = lurow; ldrow<rowlen && matrix[ldrow][lucol] == '1'; ldrow++)
						for(rucol = lucol; rucol<collen && matrix[lurow][rucol] == '1'; rucol++){
							if(checkColAllOnes(matrix, rucol, lurow, ldrow)){
								area = (ldrow-lurow+1)*(rucol-lucol+1);
								maxArea = area>maxArea? area: maxArea;
							}
							else
								break;
						}
				}
			}
		}

		return maxArea;

    }

private:
	bool checkColAllOnes(vector<vector<char>> &matrix, int col, int rowbegin, int rowend){
		for(int i=rowbegin;i<=rowend;i++)
			if(matrix[i][col] == '0')
				return false;
		return true;
	}
};