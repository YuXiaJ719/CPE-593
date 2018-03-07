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

void insertSort(vector<double> &vec, int n){

    for(int i = 0; i < n - 1; i++){

        int room_index = i + 1;
        int compare_index = i;

        while(vec[room_index] < vec[compare_index] && compare_index >= 0){
            swap(vec[room_index], vec[compare_index]);
            room_index = compare_index;
            compare_index--;
        }
    }
}

int main(){

    vector<double> vec = readVec();
    insertSort(vec, int(vec.size()));

    for(int i = 0; i < vec.size(); i++){
        if(i == 0)
            cout << vec[i];
        else
            cout << "->" << vec[i];
    }

    cout << endl;
}