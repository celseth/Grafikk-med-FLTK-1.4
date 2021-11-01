#include "Track.h"


//Fl_PNG_Image Track::background{"Sprites/back.jpeg"};

Track::Track(): Fl_Widget(10,10,10,10),rad{rad},length{length},background{"Sprites/back.jpeg"},spill{ "Sprites/spillSprite.jpeg" },boost{ "Sprites/boostSprite.jpeg" },	peel{ "Sprites/peelSprite.jpeg" }{
    constexpr int ncircles=30;
    for (unsigned int i = 0; i < ncircles; i++){

        goals.push_back({
		screenWidth / 2 + screenWidth / 3.0*cos(i*2.0 / ncircles * 3.14),
		screenHeight / 2 - screenHeight / 3.0*sin(i*4.0 / ncircles * 3.14)});
    }
    
}

void Track::draw(){
    
    Obstacle obst;
    static int pos = 0;
    
    
    for (int i = 0; i < goals.size(); i++)
    {

        if(i%5==0){
            peel.draw(goals[i].first,goals[i].second);
            obst=Obstacle::Peel;
        }
        else if(i%9==0){
            boost.draw(goals[i].first,goals[i].second);
            obst=Obstacle::Boost;
        }
        else if(i%11==0){
            spill.draw(goals[i].first,goals[i].second);
            obst=Obstacle::Spill;

        }
        else{
            fl_begin_polygon();
		    fl_circle(goals[i].first, goals[i].second, 20); //radius 20
		    fl_end_polygon();
            obst=Obstacle::None;
        }
        obstacle.push_back({goals[i].first,goals[i].second,obst});
    }

}
