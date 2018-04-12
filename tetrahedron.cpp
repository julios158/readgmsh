//
// Created by julioa on 10/04/18.
//
#include <array>
#include <iostream>
#include "tetrahedron.h"



// centroid calculation
void Tetrahedron::compute_centroid (){

    for (int i = 0; i < coord_points[0].size(); i++ ) {
        for (int j = 0; j <coord_points.size(); j++ )
            centroid[i] +=  coord_points[j][i]/4;
    }
}
// print centroid coordinates
void Tetrahedron::print_centroid_coord(){
    std::cout << "centroid coordinated of tetrahedron"<< std::endl;
    for(int i = 0; i < centroid.size(); ++i)
        std::cout << "Centroid[" << i << "] = " << centroid[i] << std::endl;
}
