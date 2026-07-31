#include <iostream>
#include <cmath>
#include <fstream>

// step 1: move and print on console
// step 2: orbit and print on console
// step 3: positions plotted with python

// struct for body that holds these (for now):
// x,y (position)
// vx,vy (velocity)

struct Body {

    double xPos, yPos;
    double xVel, yVel;
        
    };

int main() {

    Body b1;   // 1 body for now..

    b1.xPos = 1;
    b1.yPos = 0;
    b1.xVel = 0;
    b1.yVel = 1;

    // newton's law of universal gravitation: F = G*m1*m2/r^2 where G = 6.674×10−11 (m^3⋅kg^−1⋅s^−2)
    // if we have a sun (with mass M) and a planet (with mass m) orbiting it, then we have F = G*M*m/r^2 
    // to find acceleration of the planet we use F = m*a => a = F/m = (G*M*m/r^2)/m = G*M/r^2 (the planets mass is irrelevant)
    // a = G*M/r^2 splits into ax and ay by multiplying it with unit vector (dx/r,dy/r), where r = sqrt(dx^2 + dy^2)
    // so we have ax = G*M*dx/r^3 and ay = G*M*dy/r^3


    double GM = 1.0;     // for convenience lets assume that M is such that G*M = 1.0
    double dt = 0.01;    // time step
    int numSteps = 630;  // number of steps , 630*0.01 = 6.3 which is almost 2*pi (one full orbit)
                         // for circular orbit: period T = 2*pi*r/v, here r = 1 and v = 1
                         // r=sqrt((1-0)^2+(0-0)^2)=1,v=sqrt(0^2+1^2)=1

    std::ofstream outfile("orbit.csv");     // create file orbit.csv

    outfile<<"x,y\n";

    for(int step = 0; step < numSteps; step++) {

        // lets say that the sun coordinates are (0,0) so
        double dx = 0 - b1.xPos;
        double dy = 0 - b1.yPos;

        double r = sqrt(dx*dx + dy*dy);

        double ax = GM*dx/(r*r*r);
        double ay = GM*dy/(r*r*r);

        b1.xVel += ax*dt;
        b1.yVel += ay*dt;
        
        b1.xPos += b1.xVel * dt;
        b1.yPos += b1.yVel * dt;

        // std::cout<<"The position is: ("<<b1.xPos<<","<<b1.yPos<<")\n";      this line writes to console so we replace it with
        outfile<<b1.xPos<<","<<b1.yPos<<"\n";
    }

    return 0;
}
