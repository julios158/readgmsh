///
/// Created by julioa on 10/04/18.
///
#include <array>
#include <iostream>
#include "tetrahedron.h"

/// constructor
Tetrahedron::Tetrahedron(int id,const std::array<std::array<double, 3>, 4>coord)
{
    id_ = static_cast<unsigned int>(id);
    coord_points_ = coord;
}
/// centroid calculation
void Tetrahedron::compute_centroid() {
    for (unsigned i = 0; i < coord_points_[0].size(); i++)
        for (auto coord_point : coord_points_)
            centroid_.at(i) += coord_point.at(i) / coord_points_.size();
}
/// return centroid
const std::array<double, 3> Tetrahedron::centroid() {return centroid_;}
/// return i
int Tetrahedron::id(){return id_;}


