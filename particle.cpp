#include <iostream>

// need struct for body that holds FOUR numbers:
// x,y (position)
// vx,vy (velocity)

struct Body {

    double xPos, yPos;
    double xVel, yVel;
        
    };

int main() {

    Body b1;

    b1.xPos = 0;
    b1.yPos = 0;
    b1.xVel = 1;
    b1.yVel = 2;
    
    double dt = 0.5;     // time step
    int numSteps = 20;   // number of steps

    for(int step = 0; step < numSteps; step++) {
        b1.xPos += b1.xVel * dt;
        b1.yPos += b1.yVel * dt;

        std::cout<<"The position is ("<<b1.xPos<<","<<b1.yPos<<")\n";
    }

    return 0;
}