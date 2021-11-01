#pragma once
#include "Vehicle.h"
#include <FL/Fl.H>
#include "std_lib_facilities.h"
#include "Track.h"

class PlayerVehicle : public Vehicle{


public:
    PlayerVehicle(double x, double y, double angle, const Track& Tr, const Fl_Color c) : Vehicle(x,y,angle,Tr,c){};
    pair<double,double> steer() const override;
    void drawBody() const override;

};


class PlayerVehicle2 : public Vehicle{


public:
    PlayerVehicle2(double x, double y, double angle, const Track& Tr,const Fl_Color c) : Vehicle(x,y,angle,Tr,c){};
    pair<double,double> steer() const override;
    void drawBody() const override;

};

