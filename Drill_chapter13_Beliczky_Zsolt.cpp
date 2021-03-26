/*
    g++ Drill_chapter13_Beliczky_Zsolt.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill_chapter13_Beliczky_Zsolt `fltk-config --ldflags --use-images`
*/

// 1 . Make an 800-by- 1000 Simple_ window.
// 2. Put an 8-by-8 grid on the leftmost 800-by-800 part of that window (so
// that each square is 100x100
// 3. Make the eight squares on the diagonal starting from the top left corner
// red (use Rectangle).
// 4. Find a 200-by-200-pixel image (]PEG or GIF) and place three copies of
// is exactly 200 by 200, use set_mask() to pick a 200-by-200 sec­
// it on the grid (each image covering four squares).
// 5. Add a 100-by-100 image. Have it move around from square to square
// when you click the "Next" button. Just put wait_for_button() in a loop
// with some code that picks a new square for your image.

#include "Simple_window.h"
#include "Graph.h"


int main()
{
	using namespace Graph_lib;

	//1. Feladat
	Simple_window ablak{Point{0,0},1000,800,"Ablak"};

	//2. Feladat
	Point racs_start{0,0};
	vector<Rectangle *> racs_vektor;
	int a, b = 0;
	for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            a = racs_start.x + (j*100);
            b = racs_start.y + (i*100);
            Rectangle *negyzet = new Rectangle{Point{a,b},100,100};
            racs_vektor.push_back(negyzet);
            
        }
        
    }
    for(int k = 0; k < racs_vektor.size();k++){
        ablak.attach(*racs_vektor[k]);
    }

    //3.Feladat
    for(int l=0;l < 8; l++){
    	racs_vektor[l*8+l]->set_fill_color(Color::red);
    }

    //4. Feladat
    Point homer_start{200,0};
    Image homer1{homer_start,"homer.gif"};
    Image homer2{Point{homer_start.x+200,homer_start.y},"homer.gif"};
	Image homer3{Point{homer_start.x+400,homer_start.y},"homer.gif"};
	ablak.attach(homer1);
	ablak.attach(homer2);
	ablak.attach(homer3);

	//5.Feladat
	Point mario_start{0,100};
	Image mario{mario_start,"mario100.jpg"};
	ablak.attach(mario);
	//ablak.wait_for_button();
	for(int m = 0;m < 6;m++){
		ablak.wait_for_button();
		mario.move(100,100);
	}


	ablak.wait_for_button();
	//KI KELL TÖRÖLNI A POINTEREK //CODE
	for (int n =0; n < racs_vektor.size();n++){
    	delete (racs_vektor[n]);
    } 
    racs_vektor.clear();

}