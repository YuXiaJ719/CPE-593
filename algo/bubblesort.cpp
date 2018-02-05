//
// Created by Yu Xia on 2/2/18.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

int swap(double &a, double &b){
    double temp = a;
    a = b;
    b = temp;
    return 0;
}

vector<double> readVec(string fileName){

    vector<double> vec;
    ifstream f(fileName, ios_base::in);
    double a;
    while(!f.eof()){
        f >> a;
        vec.push_back(a);
    }

    return vec;
}

int bubbleSort(vector<double> &arr){

    unsigned long vecSize = arr.size();
    for(int i = 0; i < vecSize - 1; i++){
        for(int j = 0; j < vecSize - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                cout << arr[j] << endl;
                swap(arr[j], arr[j+1]);
            }
        }
    }

    return 0;
}


int main(int argc, char *argv[]){
    if(argc > 2){
        cout << "Too many files to open." << endl;
        return 0;
    }else if(argc == 1){
        cout << "Expected one file." << endl;
        return 0;
    }

    vector<double> vec = readVec(argv[1]);
    bubbleSort(vec);

    unsigned long vecSize = vec.size(), i;

    for(i = 0; i < vecSize; i++){
        if(i == 0)
            cout << vec[i];
        else
            cout << "->" << vec[i];
    }

    cout << endl;

    return 0;
}

