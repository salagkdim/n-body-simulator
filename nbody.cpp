#include <iostream>
#include <cmath>
#include <fstream>

// step 4: n bodies

struct Body {

    double xPos, yPos;
    double xVel, yVel;
    double xAcc, yAcc;
    double mass;
        
    };

int main() {

    // lets try 3 bodies..

    const int N = 3;
    Body bodies[N];

    // body 1 -> at center ; not moving ; heavy mass
    bodies[0].xPos = 0; bodies[0].yPos = 0;
    bodies[0].xVel = 0; bodies[0].yVel = 0;
    bodies[0].mass = 1.0;

    // body 2 -> very light ; orbiting on the right (x = 1)
    bodies[1].xPos = 1; bodies[1].yPos = 0;
    bodies[1].xVel = 0; bodies[1].yVel = 1;
    bodies[1].mass = 0.001;

    // body 3 -> very light ; orbiting on the left (x = -1)
    bodies[2].xPos = -1; bodies[2].yPos = 0;
    bodies[2].xVel = 0; bodies[2].yVel = -1;
    bodies[2].mass = 0.001;

    double G = 1.0;      // changed GM to just G because now we have different masses
    double dt = 0.01;    // time step
    int numSteps = 630;  

    std::ofstream outfile("nbody.csv");     // create file nbody.csv

    for(int step = 0; step < numSteps; step++) {
    
        for(int i = 0; i < N; i++) {       // for each body i 

            bodies[i].xAcc = 0;
            bodies[i].yAcc = 0;

            for(int j = 0; j < N; j++) {

                if (i != j) {

                    double dx = bodies[j].xPos - bodies[i].xPos;
                    double dy = bodies[j].yPos - bodies[i].yPos;

                    double r = sqrt(dx*dx + dy*dy);

                    bodies[i].xAcc += G*bodies[j].mass*dx/(r*r*r);
                    bodies[i].yAcc += G*bodies[j].mass*dy/(r*r*r);

                }
            }
        }

        for (int i = 0; i < N; i++) {

                bodies[i].xVel += bodies[i].xAcc*dt;
                bodies[i].yVel += bodies[i].yAcc*dt;

                bodies[i].xPos += bodies[i].xVel * dt;
                bodies[i].yPos += bodies[i].yVel * dt;

            }

        for (int i = 0; i < N; i++) {

            outfile<<bodies[i].xPos<<","<<bodies[i].yPos;

            if(i < N - 1) outfile<<",";

        }

        outfile<<"\n";
    
    }

    return 0;
}