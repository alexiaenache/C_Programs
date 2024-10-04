//Enache Alexia-Ioana, 321CA
#include<stdio.h>
#include<math.h>

// auxiliar function that converts a number from base 8
long long convert_from_base8(unsigned long long x)
{
	unsigned long long putere = 1;
	unsigned long long aux = 0;
	while (x != 0) {
		aux += (x % 10) * putere;
		putere *= 8;
		x /= 10;
	}
	return aux;
}

int main(void)
{
	unsigned long long ps;
	long long maxim1a, maxim2a, maxim1b, maxim2b, i;
	long long n, a, b;
	double na, nb;
	ps = 0;
	maxim1a = -1;
	maxim1b = -1;
	maxim2a = -1;
	maxim2b = -1;
	scanf("%lld", &n);
	for (i = 0; i < n; i++) {
		scanf("%lld%lld", &a, &b);
		a = convert_from_base8(a);
		b = convert_from_base8(b);
		// find the top 2 maxim values for a and b
		if (maxim1a < a) {
			maxim2a = maxim1a;
			maxim1a = a;
		} else {
			if (maxim2a < a && maxim1a != a)
				maxim2a = a;
				}
		if (maxim1b < b) {
			maxim2b = maxim1b;
			maxim1b = b;
		} else {
			if (maxim2b < b && maxim1b != b)
				maxim2b = b;
				}
		// calculate the product and the norm
		ps += (unsigned long long)a * b;
		na += (double)(pow(a, 2));
		nb += (double)(pow(b, 2));
	}
	printf("%lld\n", ps);
	printf("%lld ", maxim2a);
	printf("%lld\n", maxim2b);
	printf("%.7f ", sqrt(na));
	printf("%.7f\n", sqrt(nb));
}
