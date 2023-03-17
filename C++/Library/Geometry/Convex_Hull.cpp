#include <bits/stdc++.h>
using namespace std;

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

// vector
struct vec {
	double x, y;
	vec(double _x, double _y) : x(_x), y(_y) {}
};

vec toVec(point a, point b) { // convert 2 points to vector a->b
	return vec(b.x - a.x, b.y - a.y);
}

double dot(vec a, vec b) { return (a.x * b.x + a.y * b.y); }

double norm_sq(vec v) { return v.x * v.x + v.y * v.y; }

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

point pivot(0, 0);
bool angleCmp(point a, point b) { // angle-sorting function
	if (collinear(pivot, a, b)) // special case
		return dist(pivot, a) < dist(pivot, b); // check which one is closer
	double d1x = a.x - pivot.x, d1y = a.y - pivot.y;
	double d2x = b.x - pivot.x, d2y = b.y - pivot.y;
	return (atan2(d1y, d1x) - atan2(d2y, d2x)) < 0;
} // compare two angles


vector<point> CH(vector<point> P) { // the content of P may be reshuffled
	int i, j, n = (int)P.size();
	if (n <= 3) {
		if (!(P[0] == P[n - 1])) P.push_back(P[0]); // safeguard from corner case
		return P;
	} // special case, the CH is P itself
// first, find P0 = point with lowest Y and if tie: rightmost X
	int P0 = 0;
	for (i = 1; i < n; i++)
		if (P[i].y < P[P0].y || (P[i].y == P[P0].y && P[i].x > P[P0].x))
			P0 = i;
	point temp = P[0]; P[0] = P[P0]; P[P0] = temp; // swap P[P0] with P[0]
// second, sort points by angle w.r.t. pivot P0
	pivot = P[0]; // use this global variable as reference
	sort(++P.begin(), P.end(), angleCmp); // we do not sort P[0]
	// third, the ccw tests
	vector<point> S;
	S.push_back(P[n - 1]); S.push_back(P[0]); S.push_back(P[1]); // initial S
	i = 2; // then, we check the rest
	while (i < n) { // note: N must be >= 3 for this method to work
		j = (int)S.size() - 1;
		if (ccw(S[j - 1], S[j], P[i])) S.push_back(P[i++]); // left turn, accept
		else S.pop_back();
	} // or pop the top of S until we have a left turn
	return S; // return the result
}
