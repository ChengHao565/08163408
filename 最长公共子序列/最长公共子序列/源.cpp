#include<iostream>
#include<string.h>
using namespace std;
void LcsLength(char *x, char *y, int **b) {
	int m = strlen(x);
	int n = strlen(y);
	int **c = new int*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		c[i] = new int[n + 1];
	}

	for (int i = 0; i <= m; i++)
		c[i][0] = 0;
	for (int i = 0; i <= n; i++)
		c[0][i] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (x[i - 1] == y[j - 1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;
			}
		}
	}
	/*for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			cout << c[i][j] <<'\t';
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			cout << b[i][j] << '\t';
		}
		cout << endl;
	}*/
}

void Lcs(int i, int j, char *x, int **b) {
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 1) {
		Lcs(i - 1, j - 1, x, b);
		cout << x[i-1];
	}
	else if (b[i][j] == 2)
		Lcs(i - 1, j, x, b);
	else
		Lcs(i, j - 1, x, b);
}

void MostLcs(char *x, char *y) {
	int m = strlen(x);
	int n = strlen(y);
	int **b = new int*[m + 1];
	for (int i = 0; i < m + 1; i++) {
		b[i] = new int[n + 1];
	}
	LcsLength(x, y, b);
	Lcs(m, n, x, b);
}


int main() {
	char x[100];
	char y[100];
	cin >> x;
	cin >> y;
	cout << "x序列为：" << x << endl;
	cout << "y序列为：" << y << endl;
	cout << "最长公共子序列为：";
	MostLcs(x, y);
	cout << endl;
	system("pause");
	return 0;
}
