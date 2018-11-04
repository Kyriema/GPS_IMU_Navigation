//
// Created by nvidia on 18-11-4.
//

#ifndef OPTIMIZATION_GPSIMU_READ_NODE_H
#define OPTIMIZATION_GPSIMU_READ_NODE_H

#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <fstream>
#include "struct.h"

using namespace std;

class read_node {
public:
    read_node();

public:
    void read_variables(std::string nfile,vector< Vector8d>& variables);
    void read_variables(std::string nfile,vector< Vector5d>& variables);
    void read_variables(std::string nfile,vector< Vector6d>& variables);
    void read_variables(std::string nfile,vector< Vector7d>& variables);
    void read_variables(std::string nfile,vector< Vector9d>& variables);

    void write_variables(string nfile, vector<Vector8d> variables);
    void write_variables(string nfile, vector<Vector5d> variables);
};



#endif //OPTIMIZATION_GPSIMU_READ_NODE_H
