//
//  solver.cpp
//  Final project
//
//  Created by WC on 2022/12/18.
//

#include "solver.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <fstream>
using namespace std;
typedef int myint;
    
    template<typename boundary_function>
    laplacian_solver<boundary_function>::laplacian_solver(double upper_, double lower_, double left_, double right_, boundary_function bound_in) {
            upper = upper_;
            lower = lower_;
            left = left_;
            right = right_;
            bound = bound_in;
        }
        
        template<typename boundary_function>
        void laplacian_solver<boundary_function>::solver(myint m, myint n, double tolerance, double stop, string output_file_name) {
            //variable preparation
            double dx=(right - left)/n, dy=(upper - lower)/m; //step size
            double alpha = (dx*dx)/(dy*dy), beta = 2.*(alpha+1.);
            double tep=0;
            myint gau_sie_count = 1; // count the number of iterations
            vector<vector<double>> matrix; //the linear system to solve
            
            //resize of matrix
            matrix.resize(m+1);
            for(myint i=0; i<matrix.size(); i++) {
                matrix[i].resize(n+1);
            }

            
            
            //assign boundary condition to matrix
            //left boundary
            for(myint i=0; i<(m+1); i++) {
                matrix[i][0] = bound.le(left, upper-i*dy);
            }
            //right boundary
            for(myint i=0; i<(m+1); i++) {
                matrix[i][n] = bound.ri(right, upper-i*dy);
            }
            //upper boundary
            for(myint i=0; i<(n+1); i++) {
                matrix[0][i] = bound.up(left+i*dx, upper);
            }
            //lower boundary
            for(myint i=0; i<(n+1); i++) {
                matrix[m][i] = bound.lo(left+i*dx, lower);
            }

            
            
            //stepper
            while(gau_sie_count <= stop) {
                double tol = 0;
                for(myint i=(m-1); i>0; i--) {
                    for (myint j=1; j<n; j++) {
                        tep = (matrix[i-1][j] + matrix[i+1][j] +
                               alpha*(matrix[i][j-1] + matrix[i][j+1]))/beta;
                        if( abs(tep-matrix[i][j]) > tol) {
                            tol = abs(tep-matrix[i][j]);
                        }
                        matrix[i][j] = tep;
                    }
                }
                if(tol <= tolerance) {
                    cout << gau_sie_count << '\n' << tol << '\n';
                    break;
                }
                gau_sie_count++;
                if(gau_sie_count > stop) {
                    cout << "Exceed max number of iterations";
                    break;
                }
            }
            
            //print data
            ofstream solution;
            solution.open(output_file_name);
            solution << fixed;
            for(myint i=0; i<=m; i++) {
                for(myint j=0; j<=n; j++) {
                    solution << matrix[i][j] << ' ';
                }
                solution << '\n';
            }
            solution.close();
        }
    
