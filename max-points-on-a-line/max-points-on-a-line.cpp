/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        int pointscount = points.size();
        if(pointscount <= 2)
            return pointscount;
        int maxP = 2;
        int deltax, deltay;
		
		int defaultP = 2;
        
        for(int i=0; i<pointscount;i++)
		{
            for(int j=i+1; j<pointscount;j++)
            {
                int P;
				deltax = points[i].x - points[j].x;
                deltay = points[i].y - points[j].y;

				if(deltax == 0 && deltay ==0){
					defaultP++;
					P = defaultP;
					if(P>maxP){
						maxP = P;
						if(j == pointscount-1)
							maxP--;
					}
					continue;
				}

				P = defaultP;

                for(int k = j+1;k<pointscount;k++){
                    if(deltax == 0){
						if( points[k].x == points[i].x){
							P++;
							continue;
						}
						else
							continue;
					}
                    if(deltay == 0){
						if(points[k].y == points[i].y){
						    P++;
							continue;
						}
                    else
                        continue;
					}

                    if(isOnLine(points[k],points[i], points[j],deltax,deltay))
                        P++;
				}
                if(P>maxP)
                    maxP = P;
            }
			defaultP = 2;
		}
        return maxP;
    }
private:
    bool isOnLine(Point p, Point pref1, Point pref2, int deltax, int deltay){
        if(deltax*(p.y - pref1.y) - deltay * (p.x - pref1.x) == 0 && deltax*(p.y - pref2.y) - deltay * (p.x - pref2.x) == 0)
            return true;
        else
            return false;
    }
};