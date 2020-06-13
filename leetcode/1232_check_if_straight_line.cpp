/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 
Constraints:
2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        int n = coordinates.size();
        
        //base case:- when there are only two points
        if(n==2)
            return true;
        
        //for cases > 2
        //consider first two points then the slope of line formed by these two lines is
        //(y2-y1)/(x2-x1)
        //now i will iterate through points no. 3 to n and calculate slope for each point 'i' 
        //the slope that i will calculate, one point will always be fixed e.g point no. 0
        //e.g calculate slope point (0,1), (0,2),(0,3),(0,4).....(0,n)
        //the all slope must be equal for the points to be in a staright line
        
        //e.g (y2-y1)/(x2-x1) = (yi-y1)/(xi-x1)
        //rewriting above equation to avoid divide by zero error
        
        //(y2-y1)*(xi-x1) = (yi-y1)*(x2-x1)
        
        
        //here y2-y1 is equal to y_diff
        int y_diff = coordinates[1][1] - coordinates[0][1];
        //and x2-x1 is x_diff
        int x_diff = coordinates[1][0] - coordinates[0][0];
        
        for(int i=2; i<n; i++){
            
            if(y_diff*(coordinates[i][0]-coordinates[0][0]) != x_diff*(coordinates[i][1]-coordinates[0][1]))
                return false;
        }
        
        return true;
        
        
        
    }
};
