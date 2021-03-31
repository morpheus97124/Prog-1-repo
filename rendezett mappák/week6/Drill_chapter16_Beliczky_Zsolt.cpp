/*
    g++ Drill_chapter16_Beliczky_Zsolt.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill_chapter16_Beliczky_Zsolt `fltk-config --ldflags --use-images`
*/
#include "Graph.h"
#include "GUI.h"
#include "std_lib_facilities.h"
using namespace Graph_lib;

//Kell Lines_window struktúra
//Kell ilyen objektum

struct Vonalablak : Graph_lib::Window{
public:
	Vonalablak(Point xy,int w, int h, const string& title); //ugyanaz mint Simple_windowban
	Open_polyline vonalak; 		//Open_polyline objektum amihez vonalakat adok
	Menu szinvalaszto;  		//Menu típusú object
	Menu stilusvalaszto;

private:
	Button kovetkezo_gomb;	//widgetek
	Button kilepes_gomb;
	In_box in_textbox_x;	
	In_box in_textbox_y;
	Out_box out_textbox;
	Button szinek_gomb;
	Button stilusok_gomb;


	static void cb_kovetkezo(Address, Address pw){ //callback-függvények
		reference_to<Vonalablak>(pw).kovetkezo();
	}
	static void cb_kilepes(Address, Address pw){
		reference_to<Vonalablak>(pw).kilepes();
	}
	static void cb_piros(Address, Address pw){		
		reference_to<Vonalablak>(pw).piros_prssd();
	} 
	static void cb_kek(Address, Address pw){		
		reference_to<Vonalablak>(pw).kek_prssd();
	} 
	static void cb_fekete(Address, Address pw){		
		reference_to<Vonalablak>(pw).fekete_prssd();
	} 
	static void cb_szinek(Address, Address pw){		
		reference_to<Vonalablak>(pw).szinek();
	} 
	static void cb_stilusok(Address, Address pw){		
		reference_to<Vonalablak>(pw).stilusok();
	}

	static void cb_vonal(Address, Address pw){		
		reference_to<Vonalablak>(pw).vonal_prssd();
	}
	static void cb_pont(Address, Address pw){		
		reference_to<Vonalablak>(pw).pont_prssd();
	}
	static void cb_vesszo(Address, Address pw){		
		reference_to<Vonalablak>(pw).vesszo_prssd();
	}
	static void cb_vesszopont(Address, Address pw){		
		reference_to<Vonalablak>(pw).vesszopont_prssd();
	}

	void kovetkezo(){
		int x = in_textbox_x.get_int(); 
		int y = in_textbox_y.get_int();
		vonalak.add(Point{x,y});
		stringstream ss;
		ss << '(' << x << ',' << y << ')';
		out_textbox.put(ss.str());
		redraw();    						
	}
	void piros_prssd(){szinvaltas(Color::red); szinek_help();}	//metódusok
	void kek_prssd(){szinvaltas(Color::blue); szinek_help();}
	void fekete_prssd(){szinvaltas(Color::black); szinek_help();}

	//stílusok solid,dot,dash,dashgot,dashdotdot
	void vonal_prssd(){stilusvaltas(Line_style::solid); stilusok_help();}
	void pont_prssd(){stilusvaltas(Line_style::dot); stilusok_help();}
	void vesszo_prssd(){stilusvaltas(Line_style::dash); stilusok_help();}
	void vesszopont_prssd(){stilusvaltas(Line_style::dashdot); stilusok_help();}



	void szinvaltas(Color c) {vonalak.set_color(c);}
	void stilusvaltas(Line_style s) {vonalak.set_style(s);}
	void kilepes(){hide();}
	void szinek(){szinek_gomb.hide(); szinvalaszto.show();}
	void szinek_help(){szinvalaszto.hide(); szinek_gomb.show();}
	void stilusok(){stilusok_gomb.hide(); stilusvalaszto.show();}
	void stilusok_help(){stilusvalaszto.hide(); stilusok_gomb.show();}



};

//Vonalablak::Vonalablak(a,b,c){attach(a);attach(b);attach(c);} //syntax konstruktorhoz

Vonalablak::Vonalablak(Point xy,int w, int h, const string& title):Window(xy,w,h,title),
	kovetkezo_gomb(Point{x_max()-220,0},100,30,"Kovetkezo",cb_kovetkezo), //vonalak konstruktor
	kilepes_gomb(Point{x_max()-100,0},100,30,"Kilepes", cb_kilepes),
	in_textbox_y(Point{x_max()-310,0}, 50,20, "Kovetkezo y kordinata"),
	in_textbox_x(Point{x_max()-540,0}, 50,20, "Kovetkezo x kordinata:"),
	out_textbox(Point{100,0},100,20,"Aktualis (x,y):"),

	szinvalaszto(Point{x_max()-100,40},100,30,Menu::vertical,"Szinek"),//színek konstruktora
	szinek_gomb(Point{x_max()-100,40},100,30,"Szinek",cb_szinek),

	stilusvalaszto(Point{x_max()-220,40},100,30,Menu::vertical,"Stilusok"),//stílusok konstruktora
	stilusok_gomb(Point{x_max()-220,40},100,30,"Stilusok",cb_stilusok)
{
	attach(kovetkezo_gomb);
	attach(kilepes_gomb);
	attach(in_textbox_x);
	attach(in_textbox_y);
	attach(out_textbox);
	

	szinvalaszto.attach(new Button(Point{0,0},0,0,"Piros",cb_piros));
	szinvalaszto.attach(new Button(Point{0,0},0,0,"Kek",cb_kek));
	szinvalaszto.attach(new Button(Point{0,0},0,0,"Fekete",cb_fekete));
	attach(szinvalaszto);
	szinvalaszto.hide();
	attach(szinek_gomb);

	stilusvalaszto.attach(new Button(Point{0,0},0,0,"Vonal",cb_vonal)); //stilusvalaszto meg kell írni
	stilusvalaszto.attach(new Button(Point{0,0},0,0,"Pont",cb_pont));
	stilusvalaszto.attach(new Button(Point{0,0},0,0,"Vesszo",cb_vesszo));
	stilusvalaszto.attach(new Button(Point{0,0},0,0,"Vesszo/pont",cb_vesszopont));
	attach(stilusvalaszto);
	stilusvalaszto.hide();
	attach(stilusok_gomb);

	attach(vonalak);
}




int main()
{
    
    const int w_max = 1000;
    const int h_max = 800;


try{
	Vonalablak ablak {Point{100, 100}, w_max, h_max, "Chapter 16 drill"};
    return gui_main();
}
catch(exception& e){
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
    



}