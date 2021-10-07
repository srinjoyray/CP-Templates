// FFT IMPLEMENTATION

typedef complex<double> base;  // stl complex class
const double PIE = acos(-1);

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();

	if (n == 1) return;

	vector<base> y0 (n / 2), y1 (n / 2);   // y0 and y1
	
	for (int i = 0, j = 0; i < n; i += 2, ++j) {        // initialisation of the vectors
		y0[j] = a[i];
		y1[j] = a[i + 1];
	}
	
	fft (y0, invert);
	fft (y1, invert);
	
	double ang = 2 * PIE / n * (invert ? -1 : 1);   // setting angle acc. to invert or non invert
	base w(1), wn (cos(ang), sin(ang));   // setting wn for use and initialising w to 1
	
	for (int k = 0; k < n / 2; ++k) {

		a[k] = y0[k] + w * y1[k];                  // y(k)
		a[k + n / 2] = y0[k] - w * y1[k];         // y(k+n/2)
		
		 // if we are doing inverse fft, we have to divide by n at each step
		if (invert)                            
			a[k] /= 2, a[k + n / 2] /= 2;

		w *= wn;            // changing wn (from 1 to i, -1, -i etc) depending on the choice of w
	}
}

void multiply (const vector<int> & a, const vector<int> & b, vector<int> & res)
{
	vector<base> fx (a.begin(), a.end()), fy (b.begin(), b.end()) , hx;
	
	size_t n = 1;
	
	while (n < (int)a.size() + (int)b.size() - 1) n <<= 1;

	fx.resize (n), fy.resize (n), hx.resize(n);
	
	// finding fft of fx and gx and then multiplying each term of both to obtain
	// fft of hx
	
	fft (fx, false), fft (fy, false);

	for (size_t i = 0; i < n; ++i)
		hx[i] = fx[i] * fy[i];

	fft (hx, true);  // inverse fft of hx
	res.resize (n);

	// storing the result coeficients
	for (size_t i = 0; i < n; ++i)
		res[i] = int (hx[i].real() + 0.5);

}

// Sample Testing
// f(x) = 1 + x + x^2 =[1,1,1]
// g(x) = 1+3x =[1,3]
// multiply(fx,gx,hx);
// h(x) = 1+ 4x + 4x^2 + 3x^3 =[1,4,4,3]