#pragma once
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <utility> //passer på at pair er inkludert
#include <FL/Fl.H>
#include "FL/Fl_PNG_Image.H"

#include <tuple>
#include "Fl/Fl_JPEG_Image.H"
#include "utilities.h"
using namespace std;



class Track : public Fl_Widget{
private:
    vector<pair<double,double>> goals;
    double rad;
    double length;
    Fl_JPEG_Image spill, boost, peel;
    Fl_PNG_Image background;
    vector<tuple<double,double,Obstacle>> obstacle;
public:
    Track();
    void draw() override;
    const vector<pair<double,double>>& getGoals() const{return goals;}
    const auto& getObstacle() const{return obstacle;}

};

