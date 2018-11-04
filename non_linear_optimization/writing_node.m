function [ output_args ] = writing_node(navigation_data)
% writing bias;
node_id_start = 1;
f_handle = fopen([navigation_data.file_node_init '_imu'],'w+');
fprintf(f_handle,'%d %d %f %f %f %f %f %f\n',node_id_start,1,navigation_data.bias);
fclose(f_handle);
% writing pose R;
f_handle = fopen([navigation_data.file_node_init '_R'],'w+');
for i = 1:length(navigation_data.R_list)
    node_id_start = node_id_start + 1;
    fprintf(f_handle,'%d %d %f %f %f\n',node_id_start,2,navigation_data.R_list(i,:));
end
fclose(f_handle);
% writing pose T;
f_handle = fopen([navigation_data.file_node_init '_T'],'w+');
for i = 1:length(navigation_data.T_list)
    node_id_start = node_id_start + 1;
    fprintf(f_handle,'%d %d %f %f %f\n',node_id_start,3,navigation_data.T_list(i,:));
end
fclose(f_handle);
% writing vehicle speed;
f_handle = fopen([navigation_data.file_node_init '_V'],'w+');
for i = 1:length(navigation_data.V_list)
    node_id_start = node_id_start + 1;
    fprintf(f_handle,'%d %d %f %f %f\n',node_id_start,4,navigation_data.V_list(i,:));
end
fclose(f_handle);
end

