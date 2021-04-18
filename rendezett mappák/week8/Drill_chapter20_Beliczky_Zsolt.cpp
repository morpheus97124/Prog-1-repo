/*
	g++ Drill_chapter20_Beliczky_Zsolt.cpp -o Drill_chapter20_Beliczky_Zsolt
*/

#include "std_lib_facilities.h"

template<typename T>
void Tprint(T alpha, T omega){
	for(auto i=alpha; i != omega; i++){
		cout << *i << " ";
	}
	cout << endl;
}

//6.Feladat
template<typename II, typename OI>
OI xerox(II alpha, II omega, OI kimenet){
 	if(alpha == omega){}
 	else{
 		for(auto i = alpha; i != omega; i++){
 			*kimenet = *alpha;
 			++kimenet;
 			++alpha;
 		}
 	}
 	return kimenet;
}

int main(){
	//1. Feladat
	int arr[10] = {0,1,2,3,4,5,6,7,8,9};
	//2. Feladat
	vector<int> vec = {0,1,2,3,4,5,6,7,8,9};
	//3. Feladat
	list<int> lst = {0,1,2,3,4,5,6,7,8,9};

	cout << "arr: ";
	Tprint(begin(arr), end(arr));
	cout << "vec: ";
	Tprint(vec.begin(), vec.end());
	cout << "lst: ";
	Tprint(lst.begin(), lst.end());
	cout << "-------------------------\n";

	//4.Feladat
	int arr2[10];
	for(int i = 0; i < 10; i++){
		arr2[i] = arr[i];
	}
	vector<int> vec2 = vec;
	list<int> lst2 = lst;

	cout << "arr2: ";
	Tprint(begin(arr2), end(arr2));
	cout << "vec2: ";
	Tprint(vec2.begin(), vec2.end());
	cout << "lst2: ";
	Tprint(lst2.begin(), lst2.end());
	cout << "-------------------------\n";

	//5. Feladat
	for(int i = 0; i < 10; i++){
		arr[i] += 2;
		vec[i] += 3;
	}
	for(auto i = lst.begin(); i != lst.end(); i++){
		*i += 5;
	}

	cout << "arr: ";
	Tprint(begin(arr), end(arr));
	cout << "vec: ";
	Tprint(vec.begin(), vec.end());
	cout << "lst: ";
	Tprint(lst.begin(), lst.end());
	cout << "-------------------------\n";

	//7. Feladat
	xerox(begin(arr), end(arr), vec.begin());
	xerox(lst.begin(), lst.end(), begin(arr));

	cout << "arr: ";
	Tprint(begin(arr), end(arr));
	cout << "vec: ";
	Tprint(vec.begin(), vec.end());
	cout << "lst: ";
	Tprint(lst.begin(), lst.end());
	cout << "-------------------------\n";


	auto p = find(vec.begin(), vec.end(), 3);
	for(int j = 0; j < 10; j++){
		if(*p == vec[j]){
			cout << "Létezik vec-ben 3-as érték, az indexe: " << j << endl;
		}
	}

	auto q = find(lst.begin(), lst.end(), 27);
	int z = 0;
	for(auto k = lst.begin(); k != lst.end(); k++){
		if(*q == *k && *k == 27){
			cout << "Létezik lst-ben a 27-es érték, az indexe: " << z << endl;
		}
		z++;
	}

}