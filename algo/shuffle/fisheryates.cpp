#include <iostream>
using namespace std;

double* fisheryates(double arr[], int len){
    double* ret = new double[len];
    for (int i = len - 1; i >= 0; i--){
        int j = rand() % len;
        ret[len - 1 - i] = arr[j];
        swap(arr[i], arr[j]);
        len--;
    }
    return ret;
}

int main(){
    double arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    double* ret = fisheryates(arr, 10);
    for(int i = 0; i < 10; i++)
        cout << arr[i] << endl;
}
