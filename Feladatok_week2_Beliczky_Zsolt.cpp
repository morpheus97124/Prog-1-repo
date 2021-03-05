/*
    g++ Feladatok_week2_Beliczky_Zsolt.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o Feladatok_week2_Beliczky_Zsolt `fltk-config --ldflags --use-images`
*/
/*
    1. Draw a rectangle as a Rectangle and as a Polygon. 
Make the lines of the Polygon red and the lines of the Rectangle blue. 
    2.  Draw a 100-by-30 Rectangle and place the text "Howdy!" inside it. 
    3.  Draw your initials 150 pixels high. Use a thick line. 
Draw each initial in a different color. 
    4. Draw a checkers board: 8-by-8 alternating white and red squares. 
    5.  Draw a red  1/4-inch frame around a rectangle that is  three-quarters 
the height of your screen and two-thirds the width. 
    6. What happens when you draw a Shape that doesn't fit inside its win­dow? 
What happens when you draw a Window that doesn't fit on your screen? 
Write two programs that illustrate these two phenomena. 
    7.  Draw a two-dimensional house seen  from the  front,  
the way a child would:  with a door, two windows, and a roof with a chimney. 
Feel free to add details; maybe have "smoke" come out of the chimney. 
    8.  Draw the  Olympic five  rings.  If you  can't  remember the  colors, 
look them up. 
    9. Display an image on the screen, e.g., a photo of a friend. 
Label the image both with a tiLle on the window and with a caption in the window. 
*/

#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    Simple_window ablak{Point{100,100}, 800,600, "Friends"};

    //1. Feladat
    Rectangle r_teglalap(Point{100,50},100,50);
    Closed_polyline p_teglalap;
    p_teglalap.add(Point(100,150));
    p_teglalap.add(Point(100,200));
    p_teglalap.add(Point(200,200));
    p_teglalap.add(Point(200,150));
    p_teglalap.set_color(Color::red);
    r_teglalap.set_color(Color::blue);
    ablak.attach(r_teglalap);
    ablak.attach(p_teglalap);

    //2. Feladat
    Rectangle r_howdy(Point{100,250},100,30);
    Text t_howdy(Point{110,275}, "Howdy!");
    ablak.attach(r_howdy);
    ablak.attach(t_howdy);
    
    //3. Feladat
    Text monogram1 (Point{20,150}, "B.");
    Text monogram2 (Point{40,150}, "Zs.");
    monogram1.set_color(Color::dark_green);
    monogram2.set_color(Color::magenta);
    ablak.attach(monogram1);
    ablak.attach(monogram2);

    //4. Feladat
    Point dama_start{100,300}; //kezdőpont
    int a,b, tmp = 0;
    vector<Rectangle *> dama_tabla;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            a = dama_start.x + (j*30);
            b = dama_start.y + (i*30);
            Rectangle *dama = new Rectangle{Point{a,b},30,30};
            if((i+j)%2 == 0)
            {
                dama->set_fill_color(Color::red);
            }
            else
            {
                dama->set_fill_color(Color::white);
            }
            dama_tabla.push_back(dama);
            
        }
        
    }
    //kirajzolás
    for(int k = 0; k < dama_tabla.size();k++)
    {
        ablak.attach(*dama_tabla[k]);
    }
        

    //5. Feladat
    int xmax = 1920;
    int ymax = 1080;
    //az én esetemben 1 inch -> 96 pixel
    int dpi=96;
    Rectangle r(Point{15,15},xmax*2/3,ymax*3/4);
    r.set_style(Line_style(Line_style::solid,dpi/4));
    ablak.attach(r);

    //6. Feladat
    /*
    What happens when you draw a Shape that doesn't fit inside its win­dow? 
    -Az ablak határán túl kirajzolódik, ablak átméretezése után láthatóvá válik.
    What happens when you draw a Window that doesn't fit on your screen? 
    -Felveszi az operációs rendszer felbontásának méretét
    Write two programs that illustrate these two phenomena.
    */
   /*
   Rectangle r2(Point{15,15}, xmax*2,ymax*3);
   ablak.attach(r2);

   Simple_window ablak2{Point{100,100}, xmax*2, ymax*3, "Ablak2"};
   ablak2.wait_for_button();*/
    
    
   //7. feladat
    Point haz_start{500,500};
    Rectangle haz(haz_start, 300,300);
    haz.set_fill_color(Color::white);
    Polygon teto;
    teto.add(haz_start);
    teto.add(Point{haz_start.x+150,haz_start.y-260});
    teto.add(Point{haz_start.x+300,haz_start.y});
    teto.set_fill_color(Color::red);
    Rectangle kemeny(Point{haz_start.x+200,haz_start.y-200},50,150);
    kemeny.set_fill_color(Color::dark_red);
    Rectangle ajto(Point{haz_start.x+120,haz_start.y+150}, 60,150);
    ajto.set_fill_color(Color::dark_red);
    Rectangle nyilaszaro1(Point{haz_start.x+30,haz_start.y+80},40,40);
    nyilaszaro1.set_fill_color(Color::blue);
    Rectangle nyilaszaro2(Point{haz_start.x+230,haz_start.y+80},40,40);
    nyilaszaro2.set_fill_color(Color::blue);
    Lines vonalak;
    vonalak.add(Point{haz_start.x+30,haz_start.y+100},Point{haz_start.x+70,haz_start.y+100});
    vonalak.add(Point{haz_start.x+230,haz_start.y+100},Point{haz_start.x+270,haz_start.y+100});
    vonalak.add(Point{haz_start.x+50,haz_start.y+80},Point{haz_start.x+50,haz_start.y+120});
    vonalak.add(Point{haz_start.x+250,haz_start.y+80},Point{haz_start.x+250,haz_start.y+120});
   
    ablak.attach(haz);
    ablak.attach(kemeny);
    ablak.attach(teto);
    ablak.attach(ajto);
    ablak.attach(nyilaszaro1);
    ablak.attach(nyilaszaro2);
    ablak.attach(vonalak);
    
    //8. Feladat kék,fekete,piros,sárga,zöld
    Point olimpia{500,100};
    Circle o1(olimpia,50);
    o1.set_color(Color::blue);
    o1.set_style(Line_style(Line_style::solid,8));
    Circle o2(Point{olimpia.x+110,olimpia.y},50);
    o2.set_color(Color::black);
    o2.set_style(Line_style(Line_style::solid,8));
    Circle o3(Point{olimpia.x+220,olimpia.y},50);
    o3.set_color(Color::red);
    o3.set_style(Line_style(Line_style::solid,8));
    Circle o4(Point{olimpia.x+55,olimpia.y+55},50);
    o4.set_color(Color::yellow);
    o4.set_style(Line_style(Line_style::solid,8));
    Circle o5(Point{olimpia.x+165,olimpia.y+55},50);
    o5.set_color(Color::green);
    o5.set_style(Line_style(Line_style::solid,8));

    ablak.attach(o1);
    ablak.attach(o4);
    ablak.attach(o2);
    ablak.attach(o5);
    ablak.attach(o3);

    //9. Feladat
    Point kep_start{1000,200};
    Image kep{kep_start,"friends.jpg"}; //600x469 px
    Text friends{Point{kep_start.x+200,kep_start.y+500},"Friends"};
    friends.set_color(Color::magenta);
    friends.set_fill_color(Color::magenta);
    friends.set_font(Font::helvetica_bold_italic);
    friends.set_font_size(30);

    ablak.attach(kep);
    ablak.attach(friends);
    


    ablak.wait_for_button();
}