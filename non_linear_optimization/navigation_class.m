classdef navigation_class < handle
    %NAVIGATION_CLASS Summary of this class goes here
    %   Detailed explanation goes here
    
    properties
        % variables 
        bias = 0;
        R_list = [];
        T_list = [];
        V_list = [];
        num_time = 0;
        % files;
        file_node_init = '../data/node_init';
        file_node_opti = '../data/node_opti';
        file_edge = '../data/edge';
        % data 
        raw_data = 0;
        time_unit = 0.01;
    end
    
    methods
        
    end
    
end

