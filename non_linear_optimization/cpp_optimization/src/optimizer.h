//
// Created by nvidia on 18-10-7.
//

#ifndef OPTIMIZATION_GPSIMU_OPTIMIZER_H
#define OPTIMIZATION_GPSIMU_OPTIMIZER_H
#include <Eigen/Dense>
#include <vector>
#include <fstream>
#include "struct.h"

using namespace Eigen;
using namespace std;

class optimizer {
public:
    optimizer();
    void run_optimize(vector< Vector8d>& variables_imu, vector< Vector5d>& variables_R,
        vector< Vector5d>& variables_T, vector< Vector5d>& variables_V,
        vector< Vector6d > edge_gps, vector< Vector9d > edge_acc,
        vector< Vector7d > edge_gyro, vector< Vector5d> edge_motion, vector< Vector5d> edge_speed);
    int id_glocal_to_local(int id_global, int type);
};


#endif //OPTIMIZATION_GPSIMU_OPTIMIZER_H
