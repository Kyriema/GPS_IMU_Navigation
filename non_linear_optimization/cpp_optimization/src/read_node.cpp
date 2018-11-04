//
// Created by nvidia on 18-11-4.
//

#include "read_node.h"

read_node::read_node() {

}

void read_node::read_variables(std::string nfile, vector<Vector8d> &variables) {
    ifstream nfilehand(nfile.c_str());
    if (!nfilehand) {
        std::cout << "read node file open failed\n";
        exit(1);
    }
    string line;
    while (getline(nfilehand, line)) {
        // line to vector double;
        istringstream nstrline(line);
        vector<double> variable_data;
        std::copy(std::istream_iterator<double>(nstrline),
                  std::istream_iterator<double>(),
                  std::back_inserter(variable_data));
        // read variables;
        if (variable_data.size() != 8){
            cout<<"read imu bias node error"<<"\n";
        }
        Vector8d variable;
        variable << variable_data[0], variable_data[1],
                variable_data[2], variable_data[3], variable_data[4], variable_data[5], variable_data[6], variable_data[7];
        variables.push_back(variable);
    }
}

void read_node::read_variables(std::string nfile, vector<Vector5d> &variables) {
    ifstream nfilehand(nfile.c_str());
    if (!nfilehand) {
        std::cout << "read node R file open failed\n";
        exit(1);
    }
    string line;
    while (getline(nfilehand, line)) {
        // line to vector double;
        istringstream nstrline(line);
        vector<double> variable_data;
        std::copy(std::istream_iterator<double>(nstrline),
                  std::istream_iterator<double>(),
                  std::back_inserter(variable_data));
        // read variables;
        if (variable_data.size() != 5){
            cout<<"read R node error"<<"\n";
        }
        Vector5d variable;
        variable << variable_data[0], variable_data[1],
                variable_data[2], variable_data[3], variable_data[4];
        variables.push_back(variable);
    }
}

void read_node::read_variables(std::string nfile, vector<Vector6d> &variables) {
    ifstream nfilehand(nfile.c_str());
    if (!nfilehand) {
        std::cout << "read node file open failed\n";
        exit(1);
    }
    string line;
    while (getline(nfilehand, line)) {
        // line to vector double;
        istringstream nstrline(line);
        vector<double> variable_data;
        std::copy(std::istream_iterator<double>(nstrline),
                  std::istream_iterator<double>(),
                  std::back_inserter(variable_data));
        // read variables;
        if (variable_data.size() != 6){
            cout<<"read R node error"<<"\n";
        }
        Vector6d variable;
        variable << variable_data[0], variable_data[1],
                variable_data[2], variable_data[3], variable_data[4],variable_data[5];
        variables.push_back(variable);
    }
}

void read_node::read_variables(std::string nfile, vector<Vector7d> &variables) {
    ifstream nfilehand(nfile.c_str());
    if (!nfilehand) {
        std::cout << "read node R file open failed\n";
        exit(1);
    }
    string line;
    while (getline(nfilehand, line)) {
        // line to vector double;
        istringstream nstrline(line);
        vector<double> variable_data;
        std::copy(std::istream_iterator<double>(nstrline),
                  std::istream_iterator<double>(),
                  std::back_inserter(variable_data));
        // read variables;
        if (variable_data.size() != 7){
            cout<<"read R node error"<<"\n";
        }
        Vector7d variable;
        variable << variable_data[0], variable_data[1],
                variable_data[2], variable_data[3], variable_data[4], variable_data[5], variable_data[6];
        variables.push_back(variable);
    }
}

void read_node::read_variables(std::string nfile, vector<Vector9d> &variables) {
    ifstream nfilehand(nfile.c_str());
    if (!nfilehand) {
        std::cout << "read node R file open failed\n";
        exit(1);
    }
    string line;
    while (getline(nfilehand, line)) {
        // line to vector double;
        istringstream nstrline(line);
        vector<double> variable_data;
        std::copy(std::istream_iterator<double>(nstrline),
                  std::istream_iterator<double>(),
                  std::back_inserter(variable_data));
        // read variables;
        if (variable_data.size() != 9){
            cout<<"read R node error"<<"\n";
        }
        Vector9d variable;
        variable << variable_data[0], variable_data[1],
                variable_data[2], variable_data[3], variable_data[4],
                variable_data[5], variable_data[6], variable_data[7], variable_data[8];
        variables.push_back(variable);
    }
}

void read_node::write_variables(string nfile, vector<Vector8d> variables) {
    ofstream nfilehand(nfile.c_str());
    if (!nfilehand){
        std::cout<<"write node file open error \n";
        exit(0);
    }

    for (int i=0;i<variables.size();i++){
        Vector8d variable_val = variables[i];
        Vector6d imu_variable = variable_val.block<6,1>(2,0);
        nfilehand <<imu_variable.transpose()<<"\n";
    }
    nfilehand.close();
}

void read_node::write_variables(string nfile, vector<Vector8d> variables) {
    ofstream nfilehand(nfile.c_str());
    if (!nfilehand){
        std::cout<<"write node file open error \n";
        exit(0);
    }

    for (int i=0;i<variables.size();i++){
        Vector5d variable_val = variables[i];
        Vector3d variable = variable_val.block<3,1>(2,0);
        nfilehand <<variable.transpose()<<"\n";
    }
    nfilehand.close();
}