/*
 Created by julioa on 10/04/18.
*/
#include <array>
#include <iostream>
#include "tetrahedron.h"

//! A constructor
/*!
    \sa Tetrahedron()
    \param id the first argument.
    \param coord the second argument.
*/
Tetrahedron::Tetrahedron(unsigned id,const std::array<std::array<double, 3>, 4>coords)
{
    id_ =id;
    coord_points_ = coords;
}
//! compute centroid function
/*!calculate the centroid coordinates of a tetrahedron */
void Tetrahedron::compute_centroid()
{
    for (auto coord_point : coord_points_)
          for (unsigned i = 0; i < centroid_.size(); i++)
            centroid_.at(i) += coord_point.at(i) /coord_points_.size();
}
//! centroid function which return tetrahedron centroid
/*!
    \sa centroid()
    \return centroid_.
*/
 std::array<double, 3> Tetrahedron::centroid() const
{
    return centroid_;
}
