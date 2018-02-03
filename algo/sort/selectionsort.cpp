//
// Created by Yu Xia on 2/3/18.
//

#include <iostream>
#include <vector>
using namespace std;

void swap(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}

vector<double> readVec(){

    int n;
    double a;
    vector<double> vec;

    cout << "Enter the length of your array: " << endl;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> a;
        vec.push_back(a);
    }

    return vec;
}

void selectionSort(vector<double> &arr, int n){

    
    for(int i = 0; i < n - 1; i++){
        int min_index = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
}

int main(){

    vector<double> vec = readVec();
    selectionSort(vec, int(vec.size()));
    for(int i = 0; i < vec.size(); i++){
        if(i == 0)
            cout << vec[i];
        else
            cout << "->" << vec[i];
    }

    cout << endl;
    return 0;
}
