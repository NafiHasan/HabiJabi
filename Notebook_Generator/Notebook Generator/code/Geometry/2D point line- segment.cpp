const double PI = acos(-1.0);
const double EPS = 1e-12;
/***
u . v = |u|*|v|*cos(theta)
= u.x*v.x + u.y*v.y
= How much parallel they are
= Dot product does not change if one vector move perpendicular to the other
u x v = |u|*|v|*sin(theta)
= u.x*v.y - v.x*u.y
= How much perpendicular they are
= Cross product does not change if one vector move parallel to the other
dot(a-b,a-b) returns squared distance between pt a and pt b
***/
struct pt {
	double x, y;
	pt() {}
	pt(double x, double y) : x(x) , y(y) {}
	pt operator + (const pt &p) const {
		return pt( x + p.x , y + p.y );
	}
	pt operator - (const pt &p) const {
		return pt( x - p.x , y - p.y );
	}
	pt operator * (double c) const {
		return pt( x * c , y * c );
	}
	pt operator / (double c) const {
		return pt( x / c , y / c );
	}
	bool operator == (const pt &p) const {
		return ( fabs( x - p.x ) < EPS && fabs( y - p.y ) < EPS );
	}
	bool operator != (const pt &p) const {
		return !(pt(x, y) == p);
	}
};
ostream& operator << (ostream& os, pt p) {
	return os << "(" << p.x << "," << p.y << ")";
}
// u.v = |u|*|v|*cos(theta)
inline double dot(pt u, pt v) {
	return u.x * v.x + u.y * v.y;
}
// a x b = |a|*|b|*sin(theta)
inline double cross(pt u, pt v) {
	return u.x * v.y - u.y * v.x;
}
// returns |u|
inline double norm(pt u) { return sqrt(dot(u, u)); }
// returns angle between two vectors
inline double angle(pt u, pt v) {
	double cosTheta = dot(u, v) / norm(u) / norm(v);
	return acos(max(-1.0, min(1.0, cosTheta))); // keeping cosTheta in [-1, 1]
}
// returns ang radian rotated version of vector u
// ccw rotation if angle is positive else cw rotation
inline pt rotate(pt u, double ang) {
	return pt( u.x * cos(ang) - u.y * sin(ang) , u.x * sin(ang) + u.y * cos(ang) );
}
// returns a vector perpendicular to v
inline pt perp(pt u) { return pt( -u.y , u.x ); }
// returns 2*area of triangle
inline double triArea2(pt a, pt b, pt c) {
	return cross(b - a, c - a);
}
// compare function for angular sort around point P0
inline bool comp(pt P0, pt a, pt b) {
	double d = triArea2(P0, a, b);
	if (d < 0) return false;
	if (d == 0 && dot(P0 - a, P0 - a) > dot(P0 - b, P0 - b) ) return false;
	return true;
}
/***
if line equation is, ax + by = c
then,
v --> direction vector of the line (b,-a)
c --> v cross p
p --> Any point(vector) on the line
side(p) = ( v cross p) - c )
= triArea2(origin,v,p)
if side(p) is,
positive --> p is above the line
zero --> p is on the line
negative --> p is below the line
***/
struct line {
	pt v;
	double c;
	line(pt v, double c) : v(v), c(c) {}
// From equation ax + by = c
	line(double a, double b, double c) : v( {b, -a}), c(c) {}
// From points p and q
	line(pt p, pt q) : v(q - p), c(cross(v, p)) {}
// |v| * dist
// dist --> distance of p from the line
	double side(pt p) { return cross(v, p) - c; }
// better to using sqDist than dist
	double dist(pt p) {
		return abs(side(p)) / norm(v);
	}
	double sqDist(pt p) {
		return side(p) * side(p) / dot(v, v);
	}
// perpendicular line through point p
// 90deg ccw rotated line
	line perpThrough(pt p) {
		return {p, p + perp(v)};
	}
// translates a line by vector t(dx,dy)
// every point (x,y) of previous line is translated to (x + dx, y + dy)
	line translate(pt t) {
		return {v, c + cross(v, t)};
	}
// for every point
// distance between previous position and current position is dist
	line shiftLeft(double dist) {
		return {v, c + dist * norm(v)};
	}
// projection of point p on the line
	pt projection(pt p) {
		return p - perp(v) * side(p) / dot(v, v);
	}
// reflection of point p wrt the line
	pt reflection(pt p) {
		return p - perp(v) * side(p) * 2.0 / dot(v, v);
	}
};
inline bool lineLineIntersection(line l1, line l2, pt &out) {
	double d = cross(l1.v, l2.v);
	if (d == 0) return false;
	out = (l2.v * l1.c - l1.v * l2.c) / d;
	return true;
}
// interior = true for interior bisector
// interior = false for exterior bisector
inline line bisector(line l1, line l2, bool interior) {
	assert(cross(l1.v, l2.v) != 0); // l1 and l2 cannot be parallel!
	double sign = interior ? 1 : -1;
	return {l2.v / norm(l2.v) + (l1.v * sign) / norm(l1.v),
	        l2.c / norm(l2.v) + (l1.c * sign) / norm(l1.v)};
}
/*** Segment ***/
/// C --> A circle which have diameter ab
/// returns true if point p is inside C or on the border of C
inline bool inDisk(pt a, pt b, pt p) {
	return
	  , → dot(a - p, b - p) <= 0;
}
/// returns true if point p is on the segment
inline bool onSegment(pt a, pt b, pt p) {
	return triArea2(a, b, p) == 0 && inDisk(a, b, p);
}
inline bool segSegIntersection(pt a, pt b, pt c, pt d, pt &out) {
	if (onSegment(a, b, c)) return out = c, true;
	if (onSegment(a, b, d)) return out = d, true;
	if (onSegment(c, d, a)) return out = a, true;
	if (onSegment(c, d, b)) return out = b, true;
	double oa = triArea2(c, d, a);
	double ob = triArea2(c, d, b);
	double oc = triArea2(a, b, c);
	double od = triArea2(a, b, d);
	if (oa * ob < 0 && oc * od < 0) {
		out = (a * ob - b * oa) / (ob - oa);
		return true;
	}
	return false;
}
// returns distance between segment ab and point p
inline double segPointDist(pt a, pt b, pt p) {
	if ( norm(a - b) == 0 ) {
		line l(a, b);
		pt pr = l.projection(p);
		if (onSegment(a, b, p)) return l.dist(p);
	}
	return min(norm(a - p), norm(b - p));
}
// returns distance between segment ab and segment cd
inline double segSegDist(pt a, pt b, pt c, pt d) {
	double oa = triArea2(c, d, a);
	double ob = triArea2(c, d, b);
	double oc = triArea2(a, b, c);
	double od = triArea2(a, b, d);
	if (oa * ob < 0 && oc * od < 0) return 0; // proper intersection
// If the segments don't intersect, the result will be minimum of these four
	return min({segPointDist(a, b, c), segPointDist(a, b, d),
	            segPointDist(c, d, a), segPointDist(c, d, b)
	           });
}