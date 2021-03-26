/*
    g++ Drill_chapter15_function_graphing_Beliczky_Zsolt.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill_chapter15_function_graphing_Beliczky_Zsolt `fltk-config --ldflags --use-images`
*/

#include "Simple_window.h"
#include "Graph.h"
//#include "Graph.cpp"
//#include "Window.cpp"

double one(double){
    	return 1;
    }
    double slope(double x){
    	return (x/2);
    }
    double square(double x){
    	return x*x;
    }
    double sloping_cos(double x){
    	return (cos(x) + slope(x));
    }

int main()
{
    using namespace Graph_lib;

    const int ablak_w = 600; // ablak mérete
    const int ablak_h = 600;

    const int xtengely_hossz = 400; 			//tengelyek hossza
    const int ytengely_hossz = 400;

    const Point origo{ablak_w/2,ablak_h/2}; 	//origo pontja

    const int x_min = -10; 						//értelmezési tartomány
    const int x_max = 11;

    const int fgv_pontok = 400; 				//ennyi pontot számol függvényenként

    const int xscale = 20; 						//skálázás
    const int yscale = 20;


    											//Függvények
    
    


    //1. Feladat
    Simple_window ablak{Point{100,100},ablak_w,ablak_h,"Function graphs"};

    //4. Feladat
    Axis xtengely{Axis::x,Point{100,origo.y},xtengely_hossz,20,"X tengely ' '= 20px"};
    Axis ytengely{Axis::y,Point{origo.x,origo.y+ytengely_hossz/2},ytengely_hossz,20,"Y tengely ' '= 20px"};
	ablak.attach(xtengely);
    ablak.attach(ytengely);

    Text t1 {Point{70,origo.y+5},"-10"};			//végértékek kiíratása
    Text t2 {Point{ablak_w-70,origo.y+5},"11"};
    Text t3 {Point{origo.x-5,70},"11"};
    Text t4 {Point{origo.x-5,ablak_h-70},"-10"};
    t1.set_color(Color::red);
    t2.set_color(Color::red);
    t3.set_color(Color::red);
    t4.set_color(Color::red);
    ablak.attach(t1);
    ablak.attach(t2);
    ablak.attach(t3);
    ablak.attach(t4);

    //5. Feladat
    xtengely.set_color(Color::red);
    ytengely.set_color(Color::red);
    xtengely.notches.set_color(Color::red);
    ytengely.notches.set_color(Color::red);

    //Függvény feladatok
    //1. Feladat
    Function f1 (one,x_min,x_max,origo,fgv_pontok,xscale,yscale);
    ablak.attach(f1);

    //4. Feladat
    Function f2 (slope,x_min,x_max,origo,fgv_pontok,xscale,yscale);
    ablak.attach(f2);

    //5. Feladat
    Text f2t(Point{100,origo.y+75},"X/2");
    ablak.attach(f2t);

    //6. Feladat
    Function f3 (square,x_min,x_max,origo,fgv_pontok,xscale,yscale);
    ablak.attach(f3);

    //7.Feladat
    Function f4 (cos,x_min,x_max,origo,fgv_pontok,xscale,yscale);
    ablak.attach(f4);

    //8. Feladat
    f4.set_color(Color::blue);

    //9. Feladat
    Function f5 (sloping_cos,x_min,x_max,origo,fgv_pontok,xscale,yscale);
    ablak.attach(f5);

    ablak.wait_for_button();



}