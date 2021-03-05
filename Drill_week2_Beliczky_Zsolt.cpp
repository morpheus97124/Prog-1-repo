/*
    g++ Drill_week2_Beliczky_Zsolt.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Drill_week2_Beliczky_Zsolt `fltk-config --ldflags --use-images`
*/

// 1. Get  an  empty Simple_window with the size 600 by 400 and a label
//  My window compiled, linked, and run. Note that you  have to link the 
//  FLTK library as  described in Appendix D; #include Graph.h, Window.h, 
//  and GUI.h in  your code;  and  include Graph.cpp and Window.cpp in  
//  your project. 
// 2.  Now add the  examples from  §12.7 one  by  one, testing 
//   between each added subsection example. 
// 3.  Go through and make one minor
//    change (e.g., in color, in  location, or in number of points) to each 
//    of the subsection examples. 

#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    //12.7.2.
    Point pont {200,200};
    Simple_window ablak{pont, 800, 600, "Ablak"};

    //12.7.3.
    Axis x_tengely {Axis::x, Point{30, 310}, 280, 10, "X tengely"};
    ablak.attach(x_tengely);
    ablak.set_label("Ablak #2");
    Axis y_tengely {Axis::y, Point{30, 310}, 280, 10, "Y tengely"};
    y_tengely.set_color(Color::blue);
    y_tengely.label.set_color(Color::dark_green);
    ablak.attach(y_tengely);
    ablak.set_label("Ablak #3");
    
    //12.7.4.
    Function sin_fgv(sin,0,50,Point{30,160}, 1000, 50, 50);
    ablak.attach(sin_fgv);
    ablak.set_label("Ablak #4");

    //12.7.5.
    sin_fgv.set_color(Color::red);
    Polygon haromszog;
    haromszog.add(Point(300,300));
    haromszog.add(Point(350,100));
    haromszog.add(Point(400,300));
    haromszog.set_color(Color::yellow);
    haromszog.set_style(Line_style::dashdot);
    ablak.set_label("Ablak #5");
    ablak.attach(haromszog);
    Closed_polyline sokszog;
    sokszog.add(Point(60,75));
    sokszog.add(Point(110,50));
    sokszog.add(Point(210,50));
    sokszog.add(Point(210,100));
    sokszog.add(Point(110,100));
    ablak.attach(sokszog);

    //12.7.6.
    Rectangle teglalap(Point{210,210}, 100,50);
    ablak.attach(teglalap);
    ablak.set_label("Ablak #6");

    //12.7.7.
    teglalap.set_fill_color(Color::white);
    haromszog.set_style(Line_style(Line_style::dashdotdot,6));
    sokszog.set_style(Line_style(Line_style::dot,3));
    ablak.set_label("Ablak #7");

    //12.7.8.
    Text szoveg(Point(160,150), "hello hello sziasztok");
    ablak.attach(szoveg);
    ablak.set_label("Canvas #8");
    szoveg.set_font(Font::courier_bold_italic);
    szoveg.set_font_size(18);
    ablak.set_label("Ablak #9");

    //12.7.9.
    Image kep(Point(500,0), "logo.jpg");
    ablak.attach(kep);
    ablak.set_label("Ablak #10");
    //kep.move(100,0); //Hiba: Segmentation fault (core dumped)
    ablak.set_label("Ablak #11");

    //12.7.10.
    Circle kor(Point(110,200),50);
    //ellipszis struct hiányzik a Graph.h-ból
    Mark x_jeloli_a_helyet(Point(110,20),'x');
    ablak.attach(kor);
    ablak.attach(x_jeloli_a_helyet);
    ostringstream oss;
    oss << "Kijelző mérete: " << x_max() << " * " << y_max() << ";\nAblak mérete: " << ablak.x_max() << " * " << ablak.y_max();
    Text meret(Point(110,20), oss.str());
    ablak.attach(meret);
    Image jeg(Point(230,230), "snow_cpp.gif");
    jeg.set_mask(Point(50,50),210,160);
    ablak.attach(jeg);
    ablak.set_label("Ablak #12");



    ablak.wait_for_button();
}