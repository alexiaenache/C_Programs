// Enache Alexia-Ioana, 321CA
#include<stdio.h>
// this structure is used to keep the information
// about one subject together
struct subject {
	int grade;
	int credits;
};

// this auxiliar funtion has 2 paramtres
// and sorts the vector in descending order
// arr[] will be a vector credits that can be added to the sum
// n is the number of elemnts
void bubble_sort(int arr[], int n)
{
	int temp;
	int swapped;
	for (int i = 0; i < n - 1; i++) {
		swapped = 0;
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				swapped = 1;
			}
		}
	if (swapped == 0)
		break;
	}
}

int main(void)
{
	int n, p_min, w[100], k = 0, total = 0;
	scanf("%d", &n);
	struct subject v[100];
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i].grade);
	for  (int i = 0; i < n; i++)
		scanf("%d", &v[i].credits);
	scanf("%d", &p_min);
	// w is the vector that holds all the credits that
	// can be added to the total
	for (int i = 0; i < n; i++) {
		total += v[i].credits * v[i].grade;
		w[k++] = (10 - v[i].grade) * v[i].credits;
	}
	if (total >= p_min) {
		printf("0\n");
		return 0;
	}
	// sort the vector in descending order
	bubble_sort(w, k);
	int ok = 0, count = 1;
	// to change the least amount of grades we start with the
	// ones that can provide the most amount of credits
	for (int i = 0; i < k; i++) {
		if (total + w[i] < p_min) {
			total += w[i];
			count++;
		} else {
			ok = 1;
			break;
		}
	}
	// print -1 if the problem does not have a solution
	if (ok == 0) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n", count);
}
