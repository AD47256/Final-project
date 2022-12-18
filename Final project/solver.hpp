//
//  solver.hpp
//  Final project
//
//  Created by WC on 2022/12/18.
//

#ifndef solver_hpp
#define solver_hpp

#include <stdio.h>
#include <string>
using namespace std;

template<typename boundary_function>
class laplacian_solver {
public:
    
    typedef int myint;
    laplacian_solver(double upper_, double lower_, double left_, double right_,
                     boundary_function bound_in);
    
    void solver(myint m, myint n, double tolerance, double stop, string output_file_name);
    
private:
    
    double upper=0, lower=0, left=0, right=0; //bound of the plate
    boundary_function bound;
    
};
#endif /* solver_hpp */
