#include <bits/stdc++.h>
using namespace std;

/*
	--check for corner cases first
	--try to avoid floating point operations
*/
const double EPS = 1e-9;
const double pi = acos(-1.0);

//try to use point_i whenever possible
struct point_i {
	int x, y;
	point_i() {x = y = 0;}
	point_i(int _x, int _y): x(_x), y(_y) {}
};

struct point {
	double x, y;
	point() {x = y = 0.0;}
	point(double _x, double _y) : x(_x), y(_y) {}

	// operator overloading to sort the points
	bool operator < (point other) const {
		if (fabs(x - other.x) > EPS)
			return x < other.x;
		return y < other.y;
	}

	// to check if the points are equal
	bool operator == (point other) const {
		return (fabs(x - other.x) < EPS && (fabs(y - other.y) < EPS));
	}
};

//euclidean distance
double dist(point p1, point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

// convert degree to radian
double DEG_to_RAD(double theta) {
	return theta * pi / 180.0;
}

// rotate a point by theta degree
point rotate (point p, double theta) { //theta is in degree
	double rad = DEG_to_RAD(theta);
	return point(p.x * cos(rad) - p.y * sin(rad),
	             p.x * sin(rad) + p.y * cos(rad));
	//don't know how it works
}

struct line {
	double a, b, c;
	// ax + by + c = 0, but b = 1.0, so y = -ax - c,
	// 								 or m = -a, c = -c
};

line pointsToLine (point p1, point p2) {
	line l;
	if (fabs(p1.x - p2.x) < EPS) { // vertical line
		l.a = 1.0; l.b = 0.0 ; l.c = -p1.x;
	} else {
		l.a = -(double)(p1.y = p2.y) / (p1.x - p2.x);
		l.b = 1.0;
		l.c = -(double)(l.a * p1.x) - p1.y;
	}
}

// vector
struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}
vec scale(vec v, double s) { // nonnegative s = [<1 .. 1 .. >1]
	// shorter.same.longer
	return vec(v.x * s, v.y * s);
}
point translate(point p, vec v) { // translate p according to v
	return point(p.x + v.x , p.y + v.y);
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

// returns the distance from p to the line defined by
// two points a and b (a and b must be different)
// the closest point is stored in the 4th parameter (byref)
double distToLine(point p, point a, point b, point &c) {
// formula: c = a + u * ab
	vec ap = toVec(a, p), ab = toVec(a, b);
	double u = dot(ap, ab) / norm_sq(ab);
	c = translate(a, scale(ab, u)); // translate a to c
	return dist(p, c);
} // Euclidean distance between p and c

double angle(point a, point o, point b) { // returns angle aob in rad
	vec oa = toVec(o, a), ob = toVec(o, b);
	return acos(dot(oa, ob) / sqrt(norm_sq(oa) * norm_sq(ob)));
}

double cross(vec a, vec b) { return a.x * b.y - a.y * b.x; }

// note: to accept collinear points, we have to change the ‘> 0’
// returns true if point r is on the left side of line pq
//counter clock wise test
bool ccw(point p, point q, point r) {
	return cross(toVec(p, q), toVec(p, r)) > 0;
}

//polygon
//vector P = set of all points of a polygon
// P[0] = P[n -1]

// returns the perimeter, which is the sum of Euclidian distances
// of consecutive line segments (polygon edges)
double perimeter(const vector<point> &P) {
	double result = 0.0;
	for (int i = 0; i < (int)P.size() - 1; i++) // remember that P[0] = P[n-1]
		result += dist(P[i], P[i + 1]);
	return result;
}

// returns the area, which is half the determinant
double area(const vector<point> &P) {
	double result = 0.0, x1, y1, x2, y2;
	for (int i = 0; i < (int)P.size() - 1; i++) {
		x1 = P[i].x; x2 = P[i + 1].x;
		y1 = P[i].y; y2 = P[i + 1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return fabs(result) / 2.0;
}


// returns true if
// all three consecutive vertices of P form the same turns
bool isConvex(const vector<point> &P) {
	int sz = (int)P.size();
	if (sz <= 3) return false; // a point/sz=2 or a line/sz=3 is not convex

	bool isLeft = ccw(P[0], P[1], P[2]); // remember one result
	for (int i = 1; i < sz - 1; i++) // then compare with the others
		if (ccw(P[i], P[i + 1], P[(i + 2) == sz ? 1 : i + 2]) != isLeft)
			return false; // different sign -> this polygon is concave
	return true;
}

// returns true if point p is in either convex/concave polygon P
bool inPolygon(point pt, const vector<point> &P) {
	if ((int)P.size() == 0) return false;
	double sum = 0; // assume the first vertex is equal to the last vertex
	for (int i = 0; i < (int)P.size() - 1; i++) {
		if (ccw(pt, P[i], P[i + 1]))
			sum += angle(P[i], pt, P[i + 1]); // left turn/ccw
		else sum -= angle(P[i], pt, P[i + 1]);
	} // right turn/cw
	return fabs(fabs(sum) - 2 * pi) < EPS;
}

// line segment p-q intersect with line A-B.
point lineIntersectSeg(point p, point q, point A, point B) {
	double a = B.y - A.y;
	double b = A.x - B.x;
	double c = B.x * A.y - A.x * B.y;
	double u = fabs(a * p.x + b * p.y + c);
	double v = fabs(a * q.x + b * q.y + c);
	return point((p.x * v + q.x * u) / (u + v), (p.y * v + q.y * u) / (u + v));
}
// cuts polygon Q along the line formed by point a -> point b
// (note: the last point must be the same as the first point)
vector<point> cutPolygon(point a, point b, const vector<point> &Q) {
	vector<point> P;
	for (int i = 0; i < (int)Q.size(); i++) {
		double left1 = cross(toVec(a, b), toVec(a, Q[i])), left2 = 0;
		if (i != (int)Q.size() - 1) left2 = cross(toVec(a, b), toVec(a, Q[i + 1]));
		if (left1 > -EPS) P.push_back(Q[i]); // Q[i] is on the left of ab
		if (left1 * left2 < -EPS) // edge (Q[i], Q[i+1]) crosses line ab
			P.push_back(lineIntersectSeg(Q[i], Q[i + 1], a, b));
	}
	if (!P.empty() && !(P.back() == P.front()))
		P.push_back(P.front()); // make P’s first point = P’s last point
	return P;
}
