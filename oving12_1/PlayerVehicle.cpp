#include "PlayerVehicle.h"


void PlayerVehicle::drawBody() const{

    //fl_color(FL_BLUE);   

    fl_draw_box(Fl_Boxtype::FL_BORDER_BOX,PS.x,PS.y,10,10,FL_RED); //fra 0 til 360 grader
	fl_color(FL_RED);
	fl_begin_polygon();
 	fl_circle(Tr.getGoals()[currentGoal].first, Tr.getGoals()[currentGoal].second, goalRadius);
	fl_end_polygon();
}

pair<double,double> PlayerVehicle::steer() const{
    if(Fl::event_key(FL_Right)){
        return make_pair(x(),y());
    }
    else if(Fl::event_key(FL_Left)){
        return make_pair(x(),-y());
    }
    return {0,0};
}

void PlayerVehicle2::drawBody() const{

    fl_color(FL_BLUE);

    fl_draw_box(Fl_Boxtype::FL_BORDER_BOX,PS.x,PS.y,10,10,FL_BLUE); //fra 0 til 360 grader
    fl_color(FL_BLUE);
	fl_begin_polygon();
	fl_circle(Tr.getGoals()[currentGoal].first, Tr.getGoals()[currentGoal].second, goalRadius);
	fl_end_polygon();
}

pair<double,double> PlayerVehicle2::steer() const{
    if(Fl::event_key('c')){
        return make_pair(x(),y());
    }
    else if(Fl::event_key('v')){
        return make_pair(x(),-y());
    }
    return {0,0};
}

