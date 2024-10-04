// Enache Alexia-Ioana, 321CA
#include<stdio.h>
// this function checks if a line is correct
// and returns 1 if true or 0 if it is not
// v[] is the line that needs to be checked
// seq[] holds the sequences of 1s
// n is the number of elements in the line
// m is the number of sequences
int check_line(int v[], int seq[], int n, int m)
{
	int count = 0, k = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] == 0) {
			count = 0;
			continue;
		}
		if (v[i] == 1) {
			count++;
			if (count == seq[k]) {
				if ((v[i + 1] == 0 || i == n - 1) && k <= m)
					k++;
				else
					return 0;
			}
		}
	}
	return 1;
}

// this function checks if a column is correct
// and returns 1 if true or 0 if it is not
// v[][] is the matrix
// seq[] holds the sequences of 1s
// c is the column that has to be checked
// n is the number of elements in the line
// m is the nomber of sequences
int check_column(int v[][100], int c, int seq[], int n, int m)
{
	int count = 0, k = 0;
	for (int i = 0; i < n; i++) {
		if (v[i][c] == 0) {
			count = 0;
			continue;
		}
		if (v[i][c] == 1) {
			count++;
			if (count == seq[k]) {
				if ((v[i + 1][c] == 0 || i == n - 1) && k <= m)
					k++;
				else
					return 0;
			}
		}
	}
	return 1;
}

int main(void)
{
	int t, m, n, k, seq[30000], no_seq, v[100][100];
	// seq[] holds the sequences of 1s that are
	// provided before the matrix
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		k = 0;
		scanf("%d %d", &n, &m);
		for (int j = 0; j < n; j++) {
			scanf("%d", &no_seq);
			seq[k++] = no_seq;
			for (int l = 0; l < no_seq; l++)
				scanf("%d", &seq[k++]);
		}
		for (int j = 0; j < m; j++) {
			scanf("%d", &no_seq);
			seq[k++] = no_seq;
		for (int l = 0; l < no_seq; l++)
			scanf("%d", &seq[k++]);
		}
		for (int j = 0; j < n; j++)
			for (int l = 0; l < m; l++)
				scanf("%d", &v[j][l]);
		int count_seq = 0, ok = 1;
		// count_sq is the index for seq[]
		for (int j = 0; j < n && ok == 1; j++) {
			ok = check_line(v[j], seq + count_seq + 1, m, seq[count_seq]);
			count_seq += seq[count_seq] + 1;
		}
		// check if ok changed its value, if so it means that one of the
		// lines does not match the game and there is no need to contiue
		// with the rest of the instructions
		if (ok == 0) {
			printf("Eroare\n");
			continue;
		}
		for (int j = 0; j < m && ok == 1; j++) {
			ok = check_column(v, j, seq + count_seq + 1, n, seq[count_seq]);
			count_seq += seq[count_seq] + 1;
		}
		// check if ok changed its value, if so it means that one of the
		// columns does not match the game and there is no need to contiue
		// with the rest of the instructions
		if (ok == 0) {
			printf("Eroare\n");
			continue;
		}
		// if ok did not change its value it means that the matrix is correct
		printf("Corect\n");
	}
}
