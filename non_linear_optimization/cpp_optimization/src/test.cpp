//
// Created by junwangcas on 28/09/17.
//
#include "struct.h"
#include "optimizer.h"
#include <string>
#include <Eigen/Dense>
#include <fstream>
#include <iterator>
#include <iostream>
#include <ceres/ceres.h>
#include "factors.h"


using namespace std;
using namespace Eigen;

int main(){
    ceres::Problem optimize_problem;
    factor_GPS* factor_gps = new factor_GPS();
    Vector3d measure(1,0,0);
    int id_T_local = 0;
    vector<Vector3d> T_variables;
    Vector3d T_variable(0,0,0);
    T_variables.push_back(T_variable);
    factor_gps->set_measure(measure);
    ceres::CostFunction* cost_function = new ceres::AutoDiffCostFunction<factor_GPS,3,3>(factor_gps);
    //optimize_problem.AddResidualBlock(cost_function,NULL,T_variable.data());
    optimize_problem.AddResidualBlock(cost_function,NULL,T_variables[0].data());
    ceres::Solver::Options optimize_option;
    optimize_option.minimizer_progress_to_stdout = true;
    ceres::Solver::Summary optimize_summary;
    ceres::Solve(optimize_option,&optimize_problem,&optimize_summary);
    std::cout<<optimize_summary.BriefReport()<<"\n";
    std::cout<<T_variables[0].transpose()<<"\n";

    return 1;
}