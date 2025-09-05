// Description: A collection of functions for basic 2D geometric operations on points.
// Time Complexity: O(1) for point operations, O(N) for is_convex.
// Space Complexity: O(1).

#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <algorithm>

typedef double T;
typedef std::complex<T> Point;
#define x real()
#define y imag()

// Calculates the squared magnitude of a point (vector).
T squared_magnitude(Point p){return p.x*p.x+p.y*p.y;}

// Returns the sign of a number.
int sign(T val){
    return (T(0)<val)-(T(0)>val);
}

// Translates a point by a vector.
Point translate(Point p, Point translation_vector){return p+translation_vector;}

// Scales a point around a center by a factor.
Point scale(Point p, Point center, T factor){return center+(p-center)*factor;}

// Rotates a point by an angle in radians around the origin.
Point rotate(Point p, T angle_radians){return p*polar(1.0,angle_radians);}

// Returns a perpendicular vector (rotated by 90 degrees).
Point perpendicular(Point p){return Point({-p.y,p.x});}

// Computes f(r) given f(p) and f(q) for a linear function f.
Point linear_interpolation(Point p, Point q, Point r, Point fp, Point fq){
    return fp+(r-p)*(fq-fp)/(q-p);
}

// Calculates the dot product of two vectors.
T dot_product(Point v, Point w){ return v.x*w.x+v.y*w.y;}

// Calculates the 2D cross product of two vectors.
T cross_product(Point v, Point w){ return v.x*w.y-v.y*w.x;}

// Checks if two vectors are perpendicular.
bool are_perpendicular(Point v, Point w){return dot_product(v,w)==0;}

// Calculates the angle between two vectors in radians.
double angle_between(Point v, Point w){
    return acos(std::clamp(dot_product(v,w)/abs(v)/abs(w),-1.0,1.0));
}

// Determines orientation of three ordered points (a,b,c).
// > 0 for counter-clockwise, < 0 for clockwise, 0 for collinear.
T orientation(Point a, Point b, Point c){return cross_product(b-a,c-a);}

// Checks if a point p is within the angle formed by rays (a,b) and (a,c).
bool is_in_angle(Point a, Point b, Point c, Point p){
    if(orientation(a,b,c)<0) std::swap(b,c);
    return sign(orientation(a,b,p))*sign(orientation(a,c,p))<=0;
}

// Checks if a polygon is convex.
bool is_convex(const std::vector<Point>& polygon){
    bool has_positive_orientation=false, has_negative_orientation=false;
    int n = polygon.size();
    if (n <= 2) return true;
    for(int i=0; i<n; i++){
        T orient = orientation(polygon[i], polygon[(i+1)%n], polygon[(i+2)%n]);
        if(orient>0) has_positive_orientation=true;
        if(orient<0) has_negative_orientation=true;
    }
    return !(has_positive_orientation && has_negative_orientation);
}
