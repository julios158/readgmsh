#include <array>
#include "tetrahedron.h"

// Constructor with id and coordinates
//! \param[in] id assign as the id_ of the tetrahedron
//! \param[in] coords coordinates of the tetrahedron nodes

Tetrahedron::Tetrahedron(unsigned id,const std::array<std::array<double, 3>, 4> &coords):id_{id}
{
   coord_points_ = coords;
}
//! compute centroid coordinates of a tetrahedron
void Tetrahedron::compute_centroid()
{
    for (auto &coord_point : coord_points_)
          for (unsigned i = 0; i < centroid_.size(); i++)
            centroid_.at(i) += coord_point.at(i) /coord_points_.size();
}
//! Return centroid coordinates
//! \retval centroid_ return coordinates of the tetrahedron centroide
 std::array<double, 3> Tetrahedron::centroid() const
{
    return centroid_;
}



