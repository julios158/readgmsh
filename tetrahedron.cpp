//
// Created by julioa on 10/04/18.
//
#include <array>
#include <iostream>
#include "tetrahedron.h"


/// constructor
Tetrahedron::Tetrahedron(int i,std::array<std::array<double, 3>, 4>coord)
{
    id_ = i;
    coord_points_ = coord;
}
/// centroid calculation
void Tetrahedron::compute_centroid(){
    for (int i = 0; i < coord_points_.size(); i++ ) {
        for (auto &coord_point : coord_points_){
            centroid_[i] += coord_point[i]/4;
        }
    }
}
/// return centroid
std::array<double, 3> Tetrahedron::centroid(){
    return centroid_;
}
/// return i
int Tetrahedron::id(){
    return id_;
}


