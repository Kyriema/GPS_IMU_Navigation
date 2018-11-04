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
#include "read_node.h"

using namespace std;
using namespace Eigen;
string nsFileNodeIMUBias = "../../../data/node_init_imu";
string nsFileNodeR = "../../../data/node_init_R";
string nsFileNodeT = "../../../data/node_init_T";
string nsFileNodeV = "../../../data/node_init_V";

string nsFileEdgeGPS = "../../../data/edge_gps";
string nsFileEdgeSpeed = "../../../data/edge_speed";
string nsFileEdgeMotion = "../../../data/edge_motion";
string nsFileEdgeGyro = "../../../data/edge_gyro";
string nsFileEdgeAcc = "../../../data/edge_acc";

string nfileNodeIMUWrite = "../../../data/node_opti_imu";
string nfileNodeRWrite = "../../../data/node_opti_R";
string nfileNodeTWrite = "../../../data/node_opti_T";
string nfileNodeVWrite = "../../../data/node_opti_V";

int main(){
    // 1：首先读取node文件;。
    vector< Vector8d> variables_imu;
    vector< Vector5d> variables_R;
    vector< Vector5d> variables_T;
    vector< Vector5d> variables_V;
    read_node my_read_node;
    my_read_node.read_variables(nsFileNodeIMUBias,variables_imu);
    my_read_node.read_variables(nsFileNodeR, variables_R);
    my_read_node.read_variables(nsFileNodeT, variables_T);
    my_read_node.read_variables(nsFileNodeV, variables_V);

    // 2： 然后读取edge的文件;
    vector< Vector6d > edge_gps;
    vector< Vector9d > edge_acc;
    vector< Vector7d > edge_gyro;
    vector< Vector5d> edge_motion;
    vector< Vector5d> edge_speed;
    my_read_node.read_variables(nsFileEdgeGPS, edge_gps);
    my_read_node.read_variables(nsFileEdgeAcc, edge_acc);
    my_read_node.read_variables(nsFileEdgeGyro, edge_gyro);
    my_read_node.read_variables(nsFileEdgeMotion, edge_motion);
    my_read_node.read_variables(nsFileEdgeSpeed, edge_speed);

    // 3: 将节点和边参数传递到优化函数中去，返回优化之后的pose的数据，以及点的数据。然后写到文件中。
    //Optimizer nOptimizer;
    //nOptimizer.DoOptimize(nPoseLst,nPtsLst,nEdgeLst);
    optimizer my_optimizer;
    my_optimizer.run_optimize(variables_imu,variables_R,variables_T,variables_V,
            edge_gps, edge_acc, edge_gyro, edge_motion, edge_speed);

    // 将结果保存起来
    WriteNode(variable_list);
    return 1;
}