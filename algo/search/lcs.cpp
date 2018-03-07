#include <iostream>
using namespace std;

int max(int a, int b){
	return (a > b) ? a : b;
}

int lcs(char *s1, char *s2, int m, int n){
	int a[m+1][n+1];
	int i, j;
	for(i = 0; i <= m; i++){
		for(j = 0; j <= n; j++){
			if(i == 0 || j == 0)
				a[i][j] = 0;
			else if(s1[i - 1] == s2[j - 1])
				a[i][j] = a[i - 1][j - 1] + 1;
			else
				a[i][j] = max(a[i - 1][j], a[i][j - 1]);
		}
	}

	return a[m][n];
}

int main()
{
  char X[] = "AGGTAB";
  char Y[] = "GXTXAYB";
  
  int m = strlen(X);
  int n = strlen(Y);
  
  printf("Length of LCS is %d\n", lcs( X, Y, m, n ));
 
  return 0;
}
