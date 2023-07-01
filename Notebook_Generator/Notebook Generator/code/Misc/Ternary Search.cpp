while (hi >= lo)
{
	int mid1 = lo + (hi - lo) / 3; int mid2 = hi - (hi - lo) / 3;
	if (f(mid1) > f(mid2)) { } //change
	else //change
	}//ittehad
double x1, why1, z1, x2, y2, z2, x, y , z;
double f( double t )
{
	double xt = x1 + (x2 - x1)t;
	double yt = why1 + (y2 - why1)t;
	double zt = z1 + (z2 - z1)t;
	return ((xt - x)(xt - x) + (yt - y)(yt - y) + (zt - z)(zt - z));
}
double Tsearch()
{
	double low = 0, high = 1, mid;
	int step = 64;
	while ( step-- ) {
		double t1 = (2low + high) / 3;
		double t2 = (low + 2high) / 3;
		double d1 = f(t1);
		double d2 = f(t2);
		if ( d1 < d2 ) high = t2;
		else low = t1;
	}
	return low;
}