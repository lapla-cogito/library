bool cross(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy) {
	double a = (cx - dx)*(ay - cy) + (cy - dy)*(cx - ax), b = (cx - dx)*(by - cy) + (cy - dy)*(cx - bx);
	double c = (ax - bx)*(cy - ay) + (ay - by)*(ax - cx), d = (ax - bx)*(dy - ay) + (ay - by)*(ax - dx);
	return c * d < 0 && a*b < 0;
}