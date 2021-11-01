#pragma once
#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include <utility> //passer på at pair er inkludert
#include <FL/Fl.H>
#include "utilities.h"
#include "Track.h"


using namespace std;

class Vehicle : public Fl_Widget{
private:


protected:
    PhysicsState PS;
    const Track& Tr;
    int currentGoal=0;
    const Fl_Color c;
    
public:
    Vehicle(double x, double y, double angel, const Track& Tr,const Fl_Color c): Fl_Widget(10,10,10,10),PS{x,y,angel},Tr{Tr},c{c}{};
    virtual void draw() final;
    virtual pair<double,double> steer() const = 0;
    virtual void drawBody() const = 0;
    bool circleCollision(double delX, double delY, double sumR);
    void hitObstacle();
};