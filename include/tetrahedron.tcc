//! \param[in] id assign as the id_ of the element
//! \param[in] coords coordinates of the element nodes
template <unsigned Tdim,unsigned Tnnodes>
void SolidElement<Tdim,Tnnodes>::SolidElement(unsigned id, const std::array<std::array<double, Tdim>, Tnnodes> &coords)//:id_{id}
{
  id_ = id;
  coord_points_ = coords;
}
//! compute centroid coordinates of a tetrahedron
template <unsigned Tdim,unsigned Tnnodes>
void SolidElement<Tdim,Tnnodes>::compute_centroid(){
    for (auto const coord_point : coord_points_)
          for (unsigned i = 0; i < centroid_.size(); i++)
            centroid_.at(i) += coord_point.at(i) /coord_points_.size();
}
//! Return centroid coordinates
//! \retval centroid_ return coordinates of the element centroide
template <unsigned Tdim,unsigned Tnnodes>
std::array<double, Tdim> SolidElement<Tdim,Tnnodes>::centroid() const{
    return centroid_;
}



