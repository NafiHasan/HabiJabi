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

bool areParallel(line l1, line l2) {
	return (fabs(l1.a - l2.a) < EPS) && (fabs(l1.b - l2.b) < EPS);
}

bool areSame(line l1, line l2) {
	return areParallel(l1, l2) && (fabs(l1.c - l2.c) < EPS);
}

// check areParallel before calling this
point areIntersect(line l1, line l2) {
	point p;
	p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
	// test for vertical line
	if (fabs(l1.b) > EPS) p.y = -(l1.a * p.x + l1.c);
	else p.y = -(l2.a * p.x + l2.c);
	return p;
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

// returns true if point r is on the same line as the line pq
bool collinear(point p, point q, point r) {
	return fabs(cross(toVec(p, q), toVec(p, r))) < EPS;
}


// circles

int insideCircle(point_i p, point_i c, int r) { // all integer version
	int dx = p.x - c.x, dy = p.y - c.y;
	int Euc = dx * dx + dy * dy, rSq = r * r; // all integer
	return Euc < rSq ? 0 : Euc == rSq ? 1 : 2;
} 					//inside/border/outside

//inscribed circle or incircle radius

double area(double ab, double bc, double ca) {
	double s = (ab + bc + ca) / 2.0;
	return sqrt(s * (s - ab) * (s - bc) * (s - ca));
}

//returns radius of incircle
double rInCircle(double ab, double bc, double ca) {
	return area(ab, bc, ca) / (0.5 * (ab + bc + ca));
}
double rInCircle(point a, point b, point c) {
	return rInCircle(dist(a, b), dist(b, c), dist(c, a));
}

// returns 1 if there is an inCircle center, returns 0 otherwise
// if this function returns 1, ctr will be the inCircle center
// and r is the same as rInCircle
int inCircle(point p1, point p2, point p3, point &ctr, double &r) {
	r = rInCircle(p1, p2, p3);
	if (fabs(r) < EPS) return 0; // no inCircle center
	line l1, l2; // compute these two angle bisectors
	double ratio = dist(p1, p2) / dist(p1, p3);
	point p = translate(p2, scale(toVec(p2, p3), ratio / (1 + ratio)));
	l1 = pointsToLine(p1, p);
	ratio = dist(p2, p1) / dist(p2, p3);
	p = translate(p1, scale(toVec(p1, p3), ratio / (1 + ratio)));
	l2 = pointsToLine(p2, p);
	ctr = areIntersect(l1, l2); // get their intersection point
	return 1;
}


//radius of circumcircle
double rCircumCircle(double ab, double bc, double ca) {
	return ab * bc * ca / (4.0 * area(ab, bc, ca));
}
double rCircumCircle(point a, point b, point c) {
	return rCircumCircle(dist(a, b), dist(b, c), dist(c, a));
}
