const double EPS = 1e-9, pi = acos(-1.0);
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
double dist(point p1, point p2) {
	return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}
double DEG_to_RAD(double theta) { return theta * pi / 180.0;}
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
//polygon
//vector P = set of all points of a polygon
// P[0] = P[n -1]
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
// returns true if all three consecutive vertices of P form the same turns
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
// convex hull
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
