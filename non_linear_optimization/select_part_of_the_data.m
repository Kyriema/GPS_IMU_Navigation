function [ out_data ] = select_part_of_the_data(in_data)
% 因爲狀態太多之後不好調試，這裏採用兩個或者三個gps坐標，來弄一個簡單的數據；
% define a parameters;
num_select_gps = 1; 
% gps part;
out_data = in_data;
time_gps_drop = out_data.GNSS.t(num_select_gps);
out_data.GNSS.t(num_select_gps+1:end) =[];
out_data.GNSS.VDOP(num_select_gps+1:end) = [];
out_data.GNSS.HDOP(num_select_gps+1:end) = [];
out_data.GNSS.pos_ned(:,num_select_gps+1:end) = [];

% speed part; 
for i = 1:length(out_data.SPEEDOMETER.t)
    if (out_data.SPEEDOMETER.t(i) == time_gps_drop)
        num_select_speed = i;
        break;
    end
end
out_data.SPEEDOMETER.t(num_select_speed+1:end) = [];
out_data.SPEEDOMETER.speed(num_select_speed+1:end) = [];

% imu part;
for i = 1:length(out_data.IMU.t)
    if (out_data.IMU.t(i) == time_gps_drop)
        num_select_imu = i;
        break;
    end
end
out_data.IMU.t(num_select_imu+1:end) = [];
out_data.IMU.acc(:,num_select_imu+1:end) = [];
out_data.IMU.gyro(:,num_select_imu+1:end) = [];
end

