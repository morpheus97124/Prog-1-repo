/*
    g++ Drill_chapter15_class_definition_Beliczky_Zsolt.cpp -o Drill_chapter15_class_definition_Beliczky_Zsolt
*/

#include "std_lib_facilities.h"
#include <stdexcept>


class Person{
public:
	Person(){}
	void kor_beallitas(int kkor){
		if(kkor < 0 || kkor > 150){
			throw runtime_error("HIBÁS KOR");
		}
		else{
			kor = kkor;
		}
	}

	void knev_beallitas(string kknev){
		string hibas_karakterek=";:'[]*&^%$#@!";
		hibas_karakterek += '"';
		for(int i = 0; i < kknev.size();i++){
			for(int j = 0; j < hibas_karakterek.size();j++){
				if(kknev[i] == hibas_karakterek[j]){
					throw runtime_error("HIBÁS NÉV");
				}

			}
		}
			knev = kknev;
	}



	void vnev_beallitas(string vvnev){
		string hibas_karakterek=";:'[]*&^%$#@!";
		hibas_karakterek += '"';
		for(int i = 0; i < vvnev.size();i++){
			for(int j = 0; j < hibas_karakterek.size();j++){
				if(vvnev[i] == hibas_karakterek[j]){
					throw runtime_error("HIBÁS NÉV");
				}

			}
		}
			vnev = vvnev;
	}
	Person(int kkor, string vvnev, string kknev){
		kor = kkor;
		vnev = vvnev;
		knev = kknev;
	}

	string nev_kiiratas(){
		string nev = vnev + " " + knev;
		return nev;
	}
	int kor_kiiratas() const {
		return kor;
	} 
	

private:	
	int kor;
	string vnev;
	string knev;
};



int main()
{
	Person p1(63,"Goofy","Goof");
	cout << p1.nev_kiiratas() << " " << p1.kor_kiiratas() << " éves.\n";
	Person p2;
	int tmp_int;
	string tmp_string;
	

	vector<Person *> emberek;
	cout << "Adjon meg emberek vezetéknevét,keresztnevét és életkorát. (kor->0 || név->vége) = kilépés\n";
	for(int i = 0; i < 10; i++){
		Person *ember = new Person;
		cout << "Kérek egy vezetéknevet: ";
		cin >> tmp_string;
		if(tmp_string == "vége"){
			break;
		}
		else{
			ember->vnev_beallitas(tmp_string);
		}
		cout << "Kérek egy keresztnevet: ";
		cin >> tmp_string;
		if(tmp_string == "vége"){
			break;
		}
		else{
			ember->knev_beallitas(tmp_string);
		}
		cout << "Kérek egy kort: ";
		cin >> tmp_int;
		if(tmp_int == 0){
			break;
		}
		else{
			ember->kor_beallitas(tmp_int);
		}
		emberek.push_back(ember);
	}
	for(int j = 0; j < emberek.size();j++){
			cout << emberek[j]->nev_kiiratas() << " " << emberek[j]->kor_kiiratas() << " éves.\n";
		}



}