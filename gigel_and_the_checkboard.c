//Enache Alexia-Ioana, 321CA
#include<stdio.h>
int v[1000][1000];
int main(void)
{
	int m[1000][1000], n, x, i, j, a, b, verifica;
	long long d; //variable to store the result
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			scanf("%d", &m[i][j]);
	x = m[0][0]; i = 0; j = 0; d = 0;
	while (1) {
		if (x < 0)
			d -= x;
		else
			d += x;
		v[i][j] = 1; //mark the current cell as visited
		// if the square is white
		if (i % 2 == j % 2) {
			if (x > 0) { // if positive move right
				if (j + x >= n) {
					a = j + x;
					while (a >= n)
						a -= n;
					x = m[i][a];
					j = a;
				} else {
					j += x;
					x = m[i][j];
				}
			} else { // if negative move left
				if (j + x < 0) {
					a = j + x;
					while (a < 0)
						a += n;
					x = m[i][a]; j = a;
				} else {
					j += x; x = m[i][j];
				}
			}
		} else { // if the square is black
			if (x > 0) { // if positive move down
				if (i + x >= n) {
					a = x + i;
					while (a >= n)
						a -= n;
					x = m[a][j]; i = a;
				} else {
					i += x; x = m[i][j];
				}
			} else { // if negtive move up
				if (i + x < 0) {
					a = i + x;
					while (a < 0)
						a += n;
					x = m[a][j]; i = a;
				} else {
					i += x; x = m[i][j];
				}
			}
		}
		if (v[i][j] == 1)
			break;
	}
	printf("%lli\n", d); printf("%d ", n - i);
	if (j < 26) {
		printf("%c\n", 'A' + j);
	} else {
		verifica = 25;
		for (a = 0; a < 26; a++) {
			for (b = 0; b < 26; b++) {
				verifica++;
				if (verifica == j) {
					printf("%c%c\n", 'A' + a, 'A' + b);
					break;
				}
			}
			if (verifica == j)
				break;
		}
	}
}
