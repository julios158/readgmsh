//
// Created by julioa on 10/04/18.
//
#include <array>
#include <iostream>
#include "tetrahedron.h"



// centroid calculation
void Tetrahedron::tetrahedron_centroid (std::array<std::array<double, 3>, 4>coord_points){

    centroid[0] = (coord_points[0][0] + coord_points[1][0]  + coord_points[2][0]+ coord_points[3][0])/4;
    centroid[1] = (coord_points[0][1] + coord_points[1][1]  + coord_points[2][1]+ coord_points[3][1])/4;
    centroid[2] = (coord_points[0][2] + coord_points[1][2]  + coord_points[2][2]+ coord_points[3][2])/4;

}
// print centroid coordinates
void Tetrahedron::print_centroid_coord()
{
    std::cout << "centroid coordinated of tetrahedron"<< std::endl;
    for (int j = 0; j <centroid.size(); j++ )
    {
        std::cout << "Centroid[" << j << "] = " << centroid[j] << std::endl;
    }
}
