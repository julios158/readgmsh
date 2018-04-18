///
/// Created by julioa on 10/04/18.
///
#include <array>
#include <iostream>
#include "tetrahedron.h"

//! A constructor
/*!
    \sa Tetrahedron()
    \param id the first argument.
    \param coord the second argument.
*/
Tetrahedron::Tetrahedron(int id,const std::array<std::array<double, 3>, 4>coord_points_)
{
    id_ = static_cast<unsigned int>(id);
    this->coord_points_ = coord_points_;
}
//! compute centroid function
/*!calculate the centroid coordinates of a tetrahedron */
void Tetrahedron::compute_centroid()
{

    for (unsigned i = 0; i < centroid_.size(); i++)
        for (auto coord_point : coord_points_)
            centroid_.at(i) += coord_point.at(i) / coord_points_.size();
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
//! id function which return tetrahedron id
/*!
    \sa id()
    \return id_.
*/
int Tetrahedron::id()
{
    return id_;
}


