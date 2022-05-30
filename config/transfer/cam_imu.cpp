#include<iostream>
#include<cmath>

#include<eigen3/Eigen/Core>
#include<eigen3/Eigen/Geometry>

int main (int argc, char** argv)
{
    Eigen::Matrix3d Rsc;
    //Rsc << 0.3782411037, -0.01834055657, 0.9255254137, 
    //       -0.02121110211, 0.9993695078, 0.02847237177, 
    //       -0.9254640764, -0.03040083538, 0.3776136022; //config_berta R1
    Rsc << 0.01834055657, -0.9255254137, 0.3782411037, 
           -0.9993695078, -0.02847237177, -0.02121110211, 
           0.03040083538, -0.3776136022, -0.9254640764;

    Eigen::Matrix3d Rsi;
    Rsi << 0.0297,0.9995,0.0113,
            0.9995,-0.0298,0.0076,
            -0.0079,-0.0111,0.9999;
    
    Eigen::Vector3d Tsc;
    Tsc << 5.107402201, -0.1338370139, 1.927591546;
    Eigen::Vector3d Tsi;
    Tsi << 1.43334150,-0.00546510,0.90664840;

    Eigen::Matrix3d Ric;
    Ric = Rsi.inverse() * Rsc;
    Eigen::Vector3d Tic;
    Tic = Rsi.inverse() * (Tsc - Tsi);

    std::cout << "Ric = " << Ric << std::endl;
    std::cout << "Tic = " << Tic << std::endl;
    

}
