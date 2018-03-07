/*
	Author: Yu Xia
	Date: 02/25/2018
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

template <class T>
class GrowArray{
private:
	T *data;
	int capacity;
	int used;

public:
	GrowArray() : data(new T[1]), capacity(1), used(0){}
	GrowArray(int initializeSize) : data(new T[initializeSize]), capacity(initializeSize), used(0){}
	~GrowArray(){
		delete [] data;
	}

	void addEnd(T a){
		if(used < capacity){
			data[used] = a;
			used++;
		}
		else{
			grow();
			data[used] = a;
			used++;
		}
	}

	void addStart(T a){
		if(used < capacity){
			T *temp = data;
			data = new T[capacity];
			used++;

			for(int i = 1; i < used; i++){
				data[i] = temp[i - 1];
			}

			data[0] = a;
			delete [] temp;

		}else{
			T *temp = data;
			capacity *= 2;
			data = new T[capacity];
			used++;

			for(int i = 1; i < used; i++)
				data[i] = temp[i - 1];

			data[0] = a;
			delete [] temp;
		}
	}

	void insert(int i, T a){
		if(used < capacity){
			T *temp = data;
			data = new T[capacity];
			data[i] = a;
			used++;

			for(int j = 0; j < i; j++)
				data[j] = temp[j];
			for(int j = i + 1; j < used; j++)
				data[j] = temp[j - 1];

			delete [] temp;
		}else{
			T *temp = data;
			capacity *= 2;
			data = new T[capacity];
			data[i] = a;
			used++;

			for(int j = 0; j < i; j++)
				data[j] = temp[j];
			for(int j = i + 1; j < used; j++)
				data[j] = temp[j - 1];

			delete [] temp;
		}
	}

	void removeEnd(){
		used--;
	}

	void removeStart(){
		for(int i = 1; i < used; i++)
			data[i - 1] = data[i];
		used--;
	}

	void remove(int i){
		T *temp = data;
		data = new T[capacity];

		for(int j = 0; j < i; j++)
			data[j] = temp[j];
		for(int j = i + 1; j < used; j++)
			data[j - 1] = temp[j];
		
		used--;
		delete [] temp;
	}

	void grow(){
		capacity *= 2;
		T *temp = data;
		data = new T[capacity];

		copy(temp, temp + used, data);

		delete [] temp;
	}

	int size(){
		return used;
	}

	void print(){
		if(used == 0)
			cout << "Empty array.";
		for(int i = 0; i < used; i++)
			cout << data[i] << " ";

		cout << '\n';
	}

	T get(int i){
		return data[i];
	}
};


class Point {
public:
  double x,y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}

  friend ostream& operator <<(ostream& s, Point p){
  	s << '(' << p.x << ',' << p.y << ')';
  	return s;
  }
};

class ConvexHull{
private:
	double max_x, max_y, min_x, min_y;
	double scope_x, scope_y;
	int grid_size;
	GrowArray<Point> (*g);

public:
	ConvexHull(int grid_size):grid_size(grid_size), g(new GrowArray<Point>[grid_size * grid_size]){}

	void read(string filename){
		ifstream f(filename);
		double a, b;
		GrowArray<Point> temp_arr;
		Point temp_point;

		f >> a >> b;

		max_x = a; max_y = b; min_x = a; min_y = b;
		temp_point = Point(a, b);
		temp_arr.addEnd(temp_point);

		while(!f.eof()){
			f >> a >> b;
			if(a > max_x)
				max_x = a; 
			else if(a < min_x)
				min_x = a;
			if(b > max_y)
				max_y = b;
			else if(b < min_y)
				min_y = b;

			temp_point = Point(a, b);
			temp_arr.addEnd(temp_point);

		}

		f.close();
		GrowArray<Point> centroids = create_grid();
		
		double used_centroids = centroids.size();
		double used_points = temp_arr.size();

		Point p, c;

		for(int i = 0; i < used_points; i++){
			p = temp_arr.get(i);
			for(int j = 0; j < used_centroids; j++){
				c = centroids.get(j);
				if(abs(p.x - c.x) <= scope_x / 2 && abs(p.y - c.y) <= scope_y / 2){
					g[j].addEnd(p);
					break;
				}
			}
			
		}

	}

	void printMinMax(){
		cout << "Min_x: " << min_x << '\n';
		cout << "Min_y: " << min_y << '\n';
		cout << "Max_x: " << max_x << '\n';
		cout << "Max_y: " << max_y << '\n';
	}

	void printAllListSizes(){
		for(int i = 0; i < grid_size * grid_size; i++)
			cout << "List " << i + 1 << " : " << g[i].size() << endl;
	}

	void printPerimeterClockWiseOrder(){
		int z = grid_size * 4 - 4;
		int * a;
		a = new int[z];
		for(int i = 0; i < pow(grid_size, 2); i++){
			if(i < grid_size)
				a[i] = i;
			else if(i % grid_size == 0)
				a[z - i / grid_size] = i;
			else if(i % grid_size == grid_size - 1)
				a[grid_size + i / grid_size - 1] = i;
			else if(i > grid_size * (grid_size - 1))
				a[2 * grid_size - 2 + grid_size * grid_size - i - 1] = i;
		}

		for(int i = 0; i < z; i++){
			cout << "Group " << a[i] + 1 << ": ";
			g[a[i]].print();
		}

	}

	GrowArray<Point> create_grid(){
		GrowArray<Point> arr;
		Point tp;
		
		double central_x, central_y;
		scope_x = (max_x - min_x) / grid_size;
		scope_y = (max_y - min_y) / grid_size;

		for(double i = 1; i <= grid_size; i++){
			for(double j = 1; j <= grid_size; j++){
				tp = Point(min_x + (j - 1.0 / 2) * scope_x, max_y - (i - 1.0 / 2) * scope_y);
				arr.addEnd(tp);
			}
		}
		return arr;
	}

};

int main(){
	ConvexHull ch(16);
	ch.read("convexhullpoints.dat");
	ch.printAllListSizes();
	ch.printMinMax();
	ch.printPerimeterClockWiseOrder();
	return 0;
}
