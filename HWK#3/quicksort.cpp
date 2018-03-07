//
// Created by Yu Xia on 2/3/18.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

void swap(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
}

vector<double> readVec(string fileName){
    int n;
    double a;
    vector<double> vec;

    ifstream File(fileName, ios_base::in);
    File >> n;

    while(!File.eof()){
        File >> a;
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
    for(int i = 0; i < vec.size(); i++)
        cout << vec[i] << ' '; 

    cout << '\n';
}

int main(){
    vector<double> vec = readVec("hw3.dat");
    quickSort(vec, 0, int(vec.size()));
    printVec(vec);
}