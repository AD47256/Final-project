//
//  main.cpp
//  Final project
//
//  Created by WC on 2022/12/17.
//

#include <iostream>
#include "solver.hpp"
using namespace std;

struct boundary {
    double up(double x, double y){
        return 200.*x;
    }

    double lo(double x, double y){
        return 0;
    }

    double le(double x, double y){
        return 0;
    }

    double ri(double x, double y){
        return 200.*y;
    }
}bound;

int main(int argc, const char * argv[]) {
    laplacian_solver<boundary> my_lap(0.5,0,0,0.5,bound);
//    my_lap.solver(4, 4, 0.01, 50, "/Users/WC/Desktop/hc011775/Final project/Final project/sol.txt");
}

