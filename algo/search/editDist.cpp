#include <iostream>
using namespace std;

int min(int a, int b){
	return (a > b) ? b : a;
}

int editDist(char *X, char *Y, int m, int n){
	int a[m+1][n+1];

	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= n; j++){
			if(i == 0)
				a[i][j] = j;
			else if(j == 0)
				a[i][j] = i;
			else if(X[i - 1] == Y[j - 1])
				a[i][j] = a[i - 1][j - 1];
			else
				a[i][j] = min(a[i-1][j], min(a[i][j - 1], a[i - 1][j - 1])) + 1;
		}
	}
	return a[m][n];
}

int main(){

    char str1[] = "sunday";
    char str2[] = "saturday";
 
    cout << editDist(str1, str2, strlen(str1), strlen(str2)) << endl;;
 
    return 0;
}








