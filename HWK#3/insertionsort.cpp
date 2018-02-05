//
// Created by Yu Xia on 2/3/18.
//

#include <iostream>
#include <fstream>
#include <string>
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
    ifstream f(fileName, ios_base::in);

    f >> n;
    while(!f.eof()){
        f >> a;
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
            compare_index -= 1;
        }
    }
}

int main(int argc, char *argv[]){
    
    if(argc == 1){
        cout << "Expected one file" <<endl;
        return 0;
    }else if(argc > 2){
        cout << "Too many files to open." << endl;
    }

    vector<double> vec = readVec(argv[1]);
    insertSort(vec, int(vec.size()));

    for(int i = 0; i < vec.size(); i++){
        if(i == 0)
            cout << vec[i];
        else
            cout << "->" << vec[i];
    }

    cout << endl;
}