% load data;
nfile_data = '../data/GNSSaidedINS_data';
load(nfile_data);
% create the node;
navigation_data = navigation_class();
% select only part of the data;
in_data = select_part_of_the_data(in_data);
navigation_data.num_time = length(in_data.IMU.t);
num_time = navigation_data.num_time;
navigation_data.bias = zeros(1,6);
navigation_data.R_list = zeros(num_time,3);
navigation_data.T_list= zeros(num_time,3);
navigation_data.V_list= zeros(num_time,3);
navigation_data.raw_data = in_data;
writing_node(navigation_data);
% writing edges;
writing_edges(navigation_data);
% optimization;

navigation_data = load_nodes(navigation_data);


