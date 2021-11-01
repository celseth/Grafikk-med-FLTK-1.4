#include "Vehicle.h"

bool Vehicle::circleCollision(double delX, double delY, double sumR){
    return (delX*delX + delY*delY < sumR*sumR);
}

void Vehicle::hitObstacle(){
    for(auto& p : Tr.getObstacle()){
        Obstacle obst = get<2>(p);
        double s;

        if(circleCollision(PS.x-get<0>(p),PS.y-get<1>(p),vehicleRadius+s)){
            if(obst==Obstacle::Boost){
                PS.grip = 5;
            }
            else if(obst==Obstacle::Peel){
                s=peelRadius;
            }
            else if(obst==Obstacle::Spill&&PS.speed>2){
                while(PS.speed>1){
                PS.grip=0.5;
                double slideangel=PS.angle;
                PS.slide(slideangel*8);
                
                }
            }
        }
    }
}

void Vehicle::draw(){



    auto goals= Tr.getGoals();
    if(circleCollision(PS.x- goals[currentGoal].first,PS.y - goals[currentGoal].second,vehicleRadius+goalRadius)){
        currentGoal=currentGoal+1%goals.size();
    };
    hitObstacle();
    

    pair retur = steer();
    //PS.update(retur.first,retur.second);
    PS.update((fmin(fmax(-1, retur.first), 1)),(fmin(fmax(-1, retur.second), 1)));//passer på at vi er innenfor intervallet
    PS.x = fmin(screenWidth - vehicleRadius, fmax(vehicleRadius, PS.x)); //begrenser skjermen
	PS.y = fmin(screenHeight - vehicleRadius, fmax(vehicleRadius, PS.y));
    // PS.x=retur.first;
    // PS.y=retur.second;
    drawBody();

    
    
    //retning sirkler FEIL!!!
    // fl_color(FL_RED);
    // fl_begin_polygon();
    // fl_circle(PS.x+50,PS.y,vehicleRadius); //fra 0 til 360 grader
    // fl_end_polygon();


    fl_color(c);
	fl_line_style(0, 5);
	//fl_circle(PS.x, PS.y ,vehicleRadius);
   	fl_line(PS.x, PS.y, PS.x + w()/2 + 40 * cos(PS.angle), PS.y + h()/2 + 40 * sin(PS.angle));

}



