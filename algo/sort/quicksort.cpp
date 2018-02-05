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

void quickSort(vector<double> &vec, int start_index, int end_index){

    int smaller_number_index = start_index - 1;
    int pivot_index = end_index - 1;
    int pivot = vec[pivot_index];

    if(start_index >= end_index - 1)
        return;
    else{
        for(int i = start_index; i < pivot_index; i++){
            if(vec[i] <= vec[pivot_index]){
                smaller_number_index++;
                swap(vec[smaller_number_index], vec[i]);
            }
        }
        smaller_number_index++;
        swap(vec[smaller_number_index], vec[pivot_index]);
    }

    quickSort(vec, start_index, smaller_number_index);
    quickSort(vec, smaller_number_index + 1, end_index);
}

void printVec(vector<double> vec){
    for(int i = 0; i < vec.size(); i++){
        if (i == 0)
            cout << vec[i];
        else
            cout << "->" << vec[i];
    }

    cout << endl;
}

int main(){
    vector<double> vec = readVec();
    quickSort(vec, 0, int(vec.size()));
    printVec(vec);
}