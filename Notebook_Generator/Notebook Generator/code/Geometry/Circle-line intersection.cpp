struct Point {
	double x, y;
	Point(double px, double py) {
		x = px;
		y = py;
	}
	Point sub(Point p2) {
		return Point(x - p2.x, y - p2.y);
	}
	Point add(Point p2) {
		return Point(x + p2.x, y + p2.y);
	}
	double distance(Point p2) {
		return sqrt((x - p2.x) * (x - p2.x) + (y - p2.y) * (y - p2.y));
	}
	Point normal() {
		double length = sqrt(x * x + y * y);
		return Point(x / length, y / length);
	}
	Point scale(double s) {
		return Point(x * s, y * s);
	}
};
struct line // Creates a line with equation ax + by + c = 0
{
	double a, b, c;
	line() {}
	line( Point p1, Point p2 ) {
		a = p1.y - p2.y;
		b = p2.x - p1.x;
		c = p1.x * p2.y - p2.x * p1.y;
	}
};
inline bool eq(double a, double b) {
	return fabs( a - b ) < eps;
}
struct Circle {
	double x, y, r, left, right;
	Circle () {}
	Circle(double cx, double cy, double cr) {
		x = cx;
		y = cy;
		r = cr;
		left = x - r;
		right = x + r;
	}
	pair<Point, Point> intersections(Circle c) {
		Point P0(x, y);
		Point P1(c.x, c.y);
		double d, a, h;
		d = P0.distance(P1);
		a = (r * r - c.r * c.r + d * d) / (2 * d);
		h = sqrt(r * r - a * a);
		Point P2 = P1.sub(P0).scale(a / d).add(P0);
		double x3, y3, x4, y4;
		x3 = P2.x + h * (P1.y - P0.y) / d;
		y3 = P2.y - h * (P1.x - P0.x) / d;
		x4 = P2.x - h * (P1.y - P0.y) / d;
		y4 = P2.y + h * (P1.x - P0.x) / d;
		return pair<Point, Point>(Point(x3, y3), Point(x4, y4));
	}
};
inline double Distance( Point a, Point b ) {
	return sqrt( ( a.x - b.x ) * ( a.x - b.x ) + ( a.y - b.y ) * ( a.y - b.y ) );
}
inline double Distance( Point P, line L ) {
	return fabs( L.a * P.x + L.b * P.y + L.c ) / sqrt( L.a * L.a + L.b * L.b );
}
bool intersection(Circle C, line L, Point &p1, Point &p2) {
	if ( Distance( {C.x, C.y}, L ) > C.r + eps ) return false;
	double a, b, c, d, x = C.x, y = C.y;
	d = C.r * C.r - x * x - y * y;
	if ( eq( L.a, 0) ) {
		p1.y = p2.y = -L.c / L.b;
		a = 1;
		b = 2 * x;
		c = p1.y * p1.y - 2 * p1.y * y - d;
		d = b * b - 4 * a * c;
		d = sqrt( fabs (d) );
		p1.x = ( b + d ) / ( 2 * a );
		p2.x = ( b - d ) / ( 2 * a );
	}
	else {
		a = L.a * L.a + L.b * L.b;
		b = 2 * ( L.a * L.a * y - L.b * L.c - L.a * L.b * x);
		c = L.c * L.c + 2 * L.a * L.c * x - L.a * L.a * d;
		d = b * b - 4 * a * c;
		d = sqrt( fabs(d) );
		p1.y = ( b + d ) / ( 2 * a );
		p2.y = ( b - d ) / ( 2 * a );
		p1.x = ( -L.b * p1.y - L.c ) / L.a;
		p2.x = ( -L.b * p2.y - L.c ) / L.a;
	}
	return true;
}