// if strict, returns false when a is on the boundary
inline bool insidePoly(pt *P, int np, pt a, bool strict = true) {
	int numCrossings = 0;
	for (int i = 0; i < np; i++) {
		if (onSegment(P[i], P[(i + 1) % np], a)) return !strict;
		numCrossings += crossesRay(a, P[i], P[(i + 1) % np]);
	}
	return (numCrossings & 1); // inside if odd number of crossings
}