//
//  main.cpp
//  Final project
//
//  Created by WC on 2022/12/17.
//

#include <iostream>
#include <cmath>
#include "solver.cpp"
using namespace std;

struct boundary {
    double up(double x, double y){
        return cos(x)+7;
    }

    double lo(double x, double y){
        return 0;
    }

    double le(double x, double y){
        return 0;
    }

    double ri(double x, double y){
        return 0;
    }
}bound;

int main(int argc, const char * argv[]) {
    laplacian_solver<boundary> my_lap(5,0,-4,4,bound);
    my_lap.solver(8, 8, 0.001, 1000, "/Users/WC/Desktop/hc011775/Final project/Final project/solution.txt");
}

