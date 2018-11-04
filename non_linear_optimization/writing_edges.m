function [ output_args ] = writing_edges(navigation_data)
id_edge = 0;
id_edge = write_gps_edge(navigation_data,id_edge);
id_edge = write_speed_edge(navigation_data,id_edge);
id_edge = write_acc_edge(navigation_data,id_edge);
id_edge = write_gyro_edge(navigation_data,id_edge);
id_edge = write_motionmodel_edge(navigation_data,id_edge);
end

function [id_edge] = write_gps_edge(navigation_data,id_edge)
% loop over the gps measurements and find the write node id;
f_handle = fopen([navigation_data.file_edge '_gps'],'w+');
imu_time_base = 1;
for i = 1:length(navigation_data.raw_data.GNSS.t)
    t_gps = navigation_data.raw_data.GNSS.t(i);
    gps_val = navigation_data.raw_data.GNSS.pos_ned(:,i)';
    for j = imu_time_base:length(navigation_data.raw_data.IMU.t)
        t_imu = navigation_data.raw_data.IMU.t(j);
        if abs(t_imu - t_gps) < 0.0001
            imu_time_base = j;
            % j: this is the pose id;
            id_T = j;
            id_edge = id_edge +1;
            fprintf(f_handle,'%d %d %d %f %f %f\n',id_edge,1,id_T,gps_val);
            break;
        end
    end
end
fclose(f_handle);
end

function [id_edge] = write_speed_edge(navigation_data,id_edge)
f_handle = fopen([navigation_data.file_edge '_speed'],'w+');
imu_time_base = 1;
for i = 1:length(navigation_data.raw_data.SPEEDOMETER.t)
    t_speed = navigation_data.raw_data.SPEEDOMETER.t(i);
    speed_val = navigation_data.raw_data.SPEEDOMETER.speed(i);
    for j = imu_time_base:length(navigation_data.raw_data.IMU.t)
        t_imu = navigation_data.raw_data.IMU.t(j);
        if abs(t_imu - t_speed) < 0.0001
            imu_time_base = j;
            % j: this is the pose id;
            id_R = j;
            id_V = j;
            id_edge = id_edge +1;
            fprintf(f_handle,'%d %d %d %d %f\n',id_edge,2,id_R,id_V,speed_val);
            break;
        end
    end
end
fclose(f_handle);
end

function [id_edge] = write_acc_edge(navigation_data,id_edge)
f_handle = fopen([navigation_data.file_edge '_acc'],'w+');
for j = 1:length(navigation_data.raw_data.IMU.t)-1
    t_imu = navigation_data.raw_data.IMU.t(j);
    acc_val = navigation_data.raw_data.IMU.acc(:,j)';
    % j: this is the pose id;
    id_R = j;
    id_T = j;
    id_V = j;
    id_T2 = id_T + 1;
    id_edge = id_edge +1;
    fprintf(f_handle,'%d %d %d %d %d %d %f %f %f\n',id_edge,3,id_R,id_T,id_V,id_T2,acc_val);
end
fclose(f_handle);

end

function [id_edge] = write_gyro_edge(navigation_data,id_edge)
f_handle = fopen([navigation_data.file_edge '_gyro'],'w+');
for j = 1:length(navigation_data.raw_data.IMU.t)-1
    t_imu = navigation_data.raw_data.IMU.t(j);
    gyro_val = navigation_data.raw_data.IMU.gyro(:,j)';
    % j: this is the pose id;
    id_R = j;
    id_T = j;
    id_V = j;
    id_R2 = id_R + 1;
    id_edge = id_edge +1;
    fprintf(f_handle,'%d %d %d %d %f %f %f\n',id_edge,4,id_R,id_R2,gyro_val);
end
fclose(f_handle);

end

function id_edge = write_motionmodel_edge(navigation_data,id_edge)
f_handle = fopen([navigation_data.file_edge '_motion'],'w+');
for j = 1:length(navigation_data.raw_data.IMU.t)-1
    t_imu = navigation_data.raw_data.IMU.t(j);
    % j: this is the pose id;
    id_R = j;
    id_T = j;
    id_V = j;
    id_T2 = id_T + 1;
    id_edge = id_edge +1;
    fprintf(f_handle,'%d %d %d %d %d\n',id_edge,5,id_T,id_V,id_T2);
end
fclose(f_handle);
end