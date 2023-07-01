struct circle {
	pt c;
	double r;
	circle() {}
	circle(pt c, double r) : c(c) , r(r) {}
};
/* returns circumcircle of a triangle
the radius of circumcircle --> intersection point of the perpendicular
bisectors of the three sides */
circle circumCircle(pt a, pt b, pt c) {
	b = b - a, c = c - a; // consider coordinates relative to point a
	assert(cross(b, c) != 0); // no circumcircle if A, B, C are co - linear
// detecting the intersection point using the same technique used in line line intersection
	pt center = a + ( perp( b * dot(c, c) - c * dot(b, b) ) / cross(b, c) / 2 );
	return {center, norm(center - a)};
}
int sgn(double val) {
	if (val > 0) return 1;
	else if (val == 0) return 0;
	else return -1;
}
/* returns number of intersection points between a line and a circle
O --> Center
I,J --> Intersection points
P -- > Projection of O onto line l
IP = JP = h , OP = d */
int circleLineIntersection(circle c, line l, pair<pt, pt> &out) {
	double h2 = c.r * c.r - l.sqDist(c.c); // h^2
	if (h2 >= 0) { // the line touches the circle
		pt p = l.proj(c.c); // point P
		pt h = l.v * sqrt(h2) / norm(l.v); // vector parallel to l, of length h
		out = {p - h, p + h}; // {I,J}
	}
	return 1 + sgn(h2); // number of intersection points
}
/* returns number of intersection points between
,→ two circles
O_i --> Center of circle i
I,J --> Intersection points
P -- > Projection of O onto line IJ
IP = JP = h , O_1O_2 = d */
int circleCircleIntersection(circle c1, circle c2, pair<pt, pt> &out) {
	pt d = c2.c - c1.c; double d2 = dot(d, d); // d^2
	if (d2 == 0) { // concentric circle
		assert(c1.r != c2.r); // same circle
		return 0;
	}
	double pd = (d2 + c1.r * c1.r - c2.r * c2.r) / 2; // = | O_1P | * d
	double h2 = c1.r * c1.r - pd * pd / d2; // = h^2
	if (h2 >= 0) {
		pt p = c1.c + d * pd / d2, h = perp(d) * sqrt(h2 / d2);
		out = {p - h, p + h};
	}
	return 1 + sgn(h2);
}
/* inner --> if true returns inner tangents
* if the radius of c2 is 0, returns tangents that go through the center
of circle c2 (value of inner is does not matter in this case)
* if there are 2 tangents, it fills out with two pairs of points: the pairs
of tangency points on each circle (P1; P2), for each of the tangents
* if there is 1 tangent, the circles are tangent to each other at some point
P, out just contains P 4 times, and the tangent line can be found as
line(c1.c,p).perpThrough(p)
* if there are 0 tangents, it does nothing
* if the circles are identical, it aborts. */
int tangents(circle c1, circle c2, bool inner, vector < pair <pt, pt> > &out) {
	if (inner) c2.r = -c2.r;
	pt d = c2.c - c1.c;
	double dr = c1.r - c2.r, d2 = dot(d, d), h2 = d2 - dr * dr;
	if (d2 == 0 || h2 < 0) {//assert(h2 != 0);
		return 0;
	}
	for (double sign : { -1, 1}) {
		pt v = (d * dr + perp(d) * sqrt(h2) * sign) / d2;
		out.push_back({c1.c + v * c1.r, c2.c + v * c2.r});
	}
	return 1 + (h2 > 0);
}