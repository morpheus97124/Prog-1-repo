#include "std_lib_facilities.h"

template<typename T>
void printv(vector<T> v){
	for(auto i = v.begin(); i != v.end(); i++){
		cout << *i << "\n";
	}
	cout << "\n";
}


int main(){
	//1. Feladat
	vector<double> vd;
	
	ifstream ifs;
	ifs.open("float.txt");
	double d;
	while(ifs >> d){
		vd.push_back(d);
	}

	//2. Feladat
	cout << "vd:\n";
	printv(vd);

	//3. Feladat
	vector<int> vi(16);
	copy(vd.begin(), vd.end(), vi.begin());
	
	//4. Feladat
	for(int i = 0; i < 16; i++){
		cout << vd[i] << " ==> " << vi[i] << "\n";
	}

	//5. Feladat
	cout << "\nSUM(vd)= " << accumulate(vd.begin(), vd.end(), 0.0);

	//6. Feladat
	cout << "\n\nSUM(vd)-SUM(vi)= " << accumulate(vd.begin(), vd.end(), 0.0)
	-accumulate(vi.begin(),vi.end(),0);

	//7. Feladat
	cout << "\n\nvd fordítva: \n";
	reverse(vd.begin(),vd.end());
	printv(vd);

	//8. Feladat
	double vd_atlag= accumulate(vd.begin(),vd.end(),0.0)/vd.size();
	cout << "\nvd átlaga: \n" << vd_atlag;

	//9. Feladat
	vector<double> vd2;
	for(auto i = vd.begin(); i != vd.end();i++){
		if(*i < vd_atlag){
			vd2.push_back(*i);
		}
	}
	cout << "\n\nvd2:\n";
	printv(vd2);

	//10. Feladat
	cout << "vd rendezve:\n";
	sort(vd);
	printv(vd);

}