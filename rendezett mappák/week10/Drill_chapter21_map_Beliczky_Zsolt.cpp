#include "std_lib_facilities.h"

template<typename C>
void printmap(C map){
	cout << "MAP:\n";
	for(auto i = map.begin(); i != map.end();i++){
		cout << i->first << " : " << i->second << "\n";
	}
	cout << "\n";
}

void read_msi(map<string,int>& m, int max){ //5. Feladat
	for(int i = 0; i < max;i++){
		istream_iterator<string> k(cin);
		istream_iterator<int> v(cin);
		m[*k]=*v;
	}
}

int sum_msi(map<string,int> m){
	int sum = 0;
	for(auto i = m.begin(); i != m.end();i++){
		sum += i->second;
	}
	return sum;
}

void cp_map(map<string,int> m1, map<int,string>& m2){
	for(auto i = m1.begin(); i != m1.end(); i++){
		m2[i->second]=i->first;
	}
}

int main(){
	//1. Feladat
	map<string,int> msi;

	//2.Feladat
	msi["systematic"]=10;
	msi["electron"]=2;
	msi["student"]=29;
	msi["particle"]=52;
	msi["danger"]=44;
	msi["feather"]=72;
	msi["software"]=67;
	msi["belief"]=24;
	msi["vigorous"]=63;
	msi["fine"]=3;

	//3. Feladat
	printmap(msi);

	//4. Feladat
	msi.clear();
	printmap(msi);

	//6. Feladat
	read_msi(msi, 10);

	//7. Feladat
	printmap(msi);

	//8. Feladat
	cout << "SUM(msi): " << sum_msi(msi) << "\n";

	//9. Feladat
	map<int,string> mis;

	//10. Feladat
	cp_map(msi, mis);

	//11.Feladat
	printmap(mis);

}