//
//Author: Daniel Dabic
//
////////////////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Contains coordinates and alpha angle value(point to OX) and operator < for std::sort().
struct Point {
    int x;
    int y;
    double alpha;	

    Point(int X, int Y) : x(X), y(Y) { alpha = -1;}

    bool operator<(const Point &temp) const {
        return (alpha < temp.alpha);
    }
};

//Return the lowerst point. If there are more than 1, return right one.
Point lowestPointSearch(vector <Point> &v);

//Center all points to point 'a'
void center(Point a, vector <Point> &v, vector <Point>& vS);

//Set alpha angle to every element of vector.
void setAlpha(vector <Point> &v);

//left the farest linear points
vector<Point> leftTheFarest(vector <Point> v);

//Return square of distance from point 'a' to point 'b'
int distance(Point a, Point b);

//Create convex hull border of points
vector<Point> createBorder(vector<Point> v);

//Return 0 if c-point is in AB-line, return 2 if C-point is on left side of AB-line, rerun 1 if C is on right side. 
int direction(Point a, Point b, Point c);

//v - BigLaterns, vS- SmallLaterns. Return count of vS included in any v triangles.
int smallLaternChecker(vector <Point> v, vector <Point> vS);


////////////////////////////////////////////////////////
int main()
{
    vector <Point> points;
    vector <Point> pointsSmall;

    int largeSkyLaterns, smallSkyLaterns;
    
    cin >> largeSkyLaterns;
    for (int i = 0; i < largeSkyLaterns; i++) {
        int tempX,tempY;
        cin >> tempX>>tempY;

        Point tempPoint(tempX,tempY);
        points.push_back(tempPoint);
    }

    cin >> smallSkyLaterns;
    for (int i = 0; i < smallSkyLaterns; i++) {
        int tempX, tempY;
        cin >> tempX >> tempY;

        Point tempPoint(tempX, tempY);
        pointsSmall.push_back(tempPoint);
    }

    Point lowestPoint=lowestPointSearch(points);
    center(lowestPoint,points,pointsSmall);
    setAlpha(points);

    sort(points.begin(), points.end());
    points = leftTheFarest(points);

    if (points.size() < 3) {
        return 0;
    }

    points = createBorder(points);

    cout << smallLaternChecker(points, pointsSmall);

    return 0;
}
////////////////////////////////////////////////////////////////////////

int distance(Point a, Point b)
{
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

vector<Point> createBorder(vector<Point> v)
{
    vector <Point> STACK;

    STACK.push_back(v[0]);
    STACK.push_back(v[1]);
    STACK.push_back(v[2]);

    for (unsigned int i = 3; i < v.size(); i++) {
        while (direction(STACK[STACK.size()-2], STACK.back(), v[i]) != 2)
            STACK.pop_back();
        STACK.push_back(v[i]);
    }

    return STACK;
}

int direction(Point a, Point b, Point c) {
    int temp = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (temp == 0)
        return 0;
    else if (temp > 0)
        return 1;
    else
        return 2;
}

int smallLaternChecker(vector<Point> v, vector<Point> vS)
{
    vector <Point> included;

    
    //edges count
    for (unsigned int i = 0; i < v.size() - 1; i++) {

        //0 to last wia border
        for (unsigned int j = 0; j < vS.size(); j++) {
            int temp=direction(v[i], v[i + 1], vS[j]);
            if (temp != 1) //included
                included.push_back(vS[j]);
        }
        vS = included;
        included.clear();
    }
    //last to 0
    for (unsigned int j = 0; j < vS.size(); j++) {
        int temp = direction(v.back(), v[0], vS[j]);
        if (temp != 1) //included
            included.push_back(vS[j]);
    }
    vS = included;

    int counter = (int)vS.size();
    return counter;
}

void center(Point a, vector<Point>& v, vector<Point>& vS)
{
    for (unsigned int i = 0; i < v.size(); i++)
    {
        v[i].x -= a.x;
        v[i].y -= a.y;
    }
    for (unsigned int i = 0; i < vS.size(); i++)
    {
        vS[i].x -= a.x;
        vS[i].y -= a.y;
    }
}

void setAlpha(vector<Point> &v)
{
    for (unsigned int i = 0; i < v.size();i++){

        double result=-1.0;
        int divider = abs(v[i].x) + abs(v[i].y);

        if (v[i].x == 0 && v[i].y == 0) 
            result = 0.0;

        else if (v[i].x >= 0) 
            result = (double)v[i].y / divider;

        else if (v[i].x < 0) 
            result = 2 - ((double)v[i].y / divider);

        v[i].alpha = result;
    }
}

vector<Point> leftTheFarest(vector <Point> v)
{
    vector <Point> finalVector;
    vector <Point> holder;
    Point zero(0,0);

    finalVector.push_back(v[0]);
    for (unsigned int i = 1; i < v.size(); i++) {
        if (finalVector[finalVector.size()-1].alpha == v[i].alpha) {

            int dst1 = distance(zero, finalVector[finalVector.size() - 1]);
            int dst2 = distance(zero, v[i]);

            if (dst1 < dst2) {
                finalVector.pop_back();
                finalVector.push_back(v[i]);
            }
        }
        else finalVector.push_back(v[i]);
    }
    return finalVector;
}

Point lowestPointSearch(vector <Point> &v)
{
    vector <Point> temp;
    temp.push_back(v[0]);

    for (unsigned int i = 1; i < v.size(); i++) {
        if (temp[0].y > v[i].y) {
            while (!temp.empty())
                temp.pop_back();
            temp.push_back(v[i]);
        }
        else if(temp[0].y==v[i].y)
            temp.push_back(v[i]);
    }

    //Every point here has the same Y, we are finding the samllest X coord.
    if (temp.size() != 1) {
        Point answer(temp[0].x, temp[0].y);
        for (unsigned int i = 1; i < temp.size(); i++) {
            if (answer.x > temp[i].x) {
                answer.x = temp[i].x; 
            }
        }
        return answer;
    }
    else return Point(temp[0].x,temp[0].y);
}


