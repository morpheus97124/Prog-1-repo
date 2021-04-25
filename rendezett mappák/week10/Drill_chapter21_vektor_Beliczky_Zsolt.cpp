#include "std_lib_facilities.h"

struct Item{
	string name;
	int iid;
	double value;
};

template<typename It>
void kiiratas(It alpha,It omega){
	cout << "Name\t\tID\t\tPrice\n";
	for(auto i = alpha; i != omega; i++){
		cout << i->name << "\t\t" << i->iid << "\t\t" << i->value << "G" << endl;
	}
	cout << "\n\n";
}

struct cmp_name{
	bool operator()(Item& a, Item& b){
		return (a.name < b.name);
	}
};

struct cmp_iid{
	bool operator()(Item& a, Item& b){
		return (a.iid < b.iid);
	}
};

struct cmp_value_dec{
	bool operator()(Item& a, Item& b){
		return(a.value > b.value);
	}
};

void torol_nev(vector<Item>& v, string nev){
	for(auto i= v.begin(); i != v.end(); i++){
		if(i->name == nev){
			v.erase(i);
		}
	}
}

void torol_iid(vector<Item>& v, int id){
	for(auto i= v.begin(); i != v.end(); i++){
		if(i->iid == id){
			v.erase(i);
		}
	}
}

int main(){
	//1. Feladat
	vector<string> tmp_a={"amber","bedroll","arrows","battleaxe","emblem","forgery kit","keelboat","lapsis lazuli","poisoner's kit","turquise","yklwa"};
	vector<int> tmp_b={5250,9357,5248,1588,9851,5254,5574,9321,2521,6387};
	vector<double> tmp_c={100,1,10,5,15,3000,10,50,10,1};
	vector<Item> vi{10};
	for(int i = 0;i<10;i++){
		vi[i].name=tmp_a[i];
		vi[i].iid=tmp_b[i];
		vi[i].value=tmp_c[i];
	}
	kiiratas(vi.begin(),vi.end());

	//2. Feladat
	cout << "Név szerint:\n";
	sort(vi.begin(),vi.end(),cmp_name());
	kiiratas(vi.begin(),vi.end());

	//3. Feladat
	cout << "ID szerint:\n";
	sort(vi.begin(),vi.end(),cmp_iid());
	kiiratas(vi.begin(),vi.end());

	//4. Feladat
	cout << "Ár szerint(csökkenő):\n";
	sort(vi.begin(),vi.end(),cmp_value_dec());
	kiiratas(vi.begin(),vi.end());

	//5.Feladat
	Item ujelem1{"horse shoe",99,12.34};
	vi.push_back(ujelem1);
	Item ujelem2{"Canon S400",9988,499.95};
	vi.push_back(ujelem2);
	kiiratas(vi.begin(), vi.end());

	//6. Feladat
	torol_nev(vi,"amber");
	torol_nev(vi,"turquise");
	kiiratas(vi.begin(), vi.end());

	//7. Feladat
	torol_iid(vi, 1588);
	torol_iid(vi, 5248);
	kiiratas(vi.begin(), vi.end());

	//8. Feladat
	list<Item> li;
	for(int i = 0;i<10;i++){
		Item elem{tmp_a[i],tmp_b[i],tmp_c[i]};
		li.push_back(elem);
	}
	cout << "LISTA:\n";
	kiiratas(li.begin(),li.end());

	cout << "Név szerint:\n";
	li.sort(cmp_name());
	kiiratas(li.begin(),li.end());
	
	cout << "ID szerint:\n";
	li.sort(cmp_iid());
	kiiratas(li.begin(),li.end());
	
	cout << "Ár szerint(csökkenő):\n";
	li.sort(cmp_value_dec());
	kiiratas(li.begin(),li.end());

	li.push_back(ujelem1);
	li.push_back(ujelem2);
	kiiratas(li.begin(), li.end());

	for(auto i=li.begin();i != li.end();i++){
		if(i->name == "amber"){
			i = li.erase(i);
		}
	}
	for(auto i=li.begin();i != li.end();i++){
		if(i->name == "turquise"){
			i = li.erase(i);
		}
	}
	kiiratas(li.begin(), li.end());

	for(auto i=li.begin();i != li.end();i++){
		if(i->iid == 1588){
			i = li.erase(i);
		}
	}
	for(auto i=li.begin();i != li.end();i++){
		if(i->iid == 5248){
			i = li.erase(i);
		}
	}
	kiiratas(li.begin(), li.end());

}