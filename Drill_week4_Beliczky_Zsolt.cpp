/*
    g++ Drill_week4_Beliczky_Zsolt.cpp -o Drill_week4_Beliczky_Zsolt
*/

#include "std_lib_facilities.h"

class B1{ //szülő
public:
	void f(){
		std::cout << "B1:f()\n";
	}
	virtual void vf(){
		std::cout << "B1:vf()\n";
	}
	virtual void pvf(){
		std::cout << "B1:pvf()\n";
	}
};

class B2{//másik szülő
public:
	virtual void pvf(){
		std::cout << "B2:pvf()\n";
	}
};

class D1 : public B1{ //gyerek
public:
	void f(){
		std::cout << "D1:f()\n";
	}
	virtual void vf(){
		std::cout << "D1:vf()\n";
	}
};

class D2 : public D1{ //unoka
public:
	virtual void pvf(){
		std::cout << "D2:pvf()\n";
	}
};

class D21 : public B2{
public:
	string d21_szoveg;
	virtual void pvf(){
		std::cout << d21_szoveg << std::endl;
	}
};

class D22 : public D21{
public:
	int d22_integrer;
	virtual void pvf(){
		std::cout << d22_integrer << std::endl;
	}
};

void f(B2& b2arg){
	b2arg.pvf();
}

int main()
{
	std::cout << "1. feladat\n";
	B1 b1;
	b1.f();
	b1.vf();

	std::cout << "2. feladat\n";
	D1 d1;
	d1.vf();

	std::cout << "3. feladat\n";
	B1* d1ptr = &d1;
	d1ptr->f();
	d1ptr->vf();

	std::cout << "4. feladat\n";
	b1.f();
	b1.vf();
	d1.f();
	d1.vf();
	d1ptr->f();
	d1ptr->vf();//d1.f()parancs a D1 osztályban lesz meghívva, d1ptr->f() parancs pedig a B1 osztályban mivel B1:f() nem virtuális

	std::cout << "5. feladat\n";
	b1.f();
	b1.vf();
	b1.pvf();
	d1.f();
	d1.vf();
	d1.pvf();
	d1ptr->f();
	d1ptr->vf();
	d1ptr->pvf();//mivel a gyermek osztályokban nem létezik pvf() így minden esetben a B1 osztályét hívja meg

	std::cout << "6. feladat\n";
	D2 d2;
	d2.f();
	d2.vf();
	d2.pvf();//a d2 objektum az f() és vf() esetén a szülő osztál metódusát hívja meg, a létező pvf() virtuális függvény esetében a sajátját

	std::cout << "7. feladat\n";
	D21 d21;
	D22 d22;
	d21.d21_szoveg = "Jónapot";
	d22.d22_integrer = 10;
	f(d21);
	f(d22);

}    