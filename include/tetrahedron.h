#ifndef GMESHLEM_SOLID_TETRAHEDRON_H_
#define GMESHLEM_SOLID_TETRAHEDRON_H_

//!  A Tetrahedron class.
//! \brief Base class that stores the information about nodes
//! \details Tetrahedron centroide is calculated
template < unsigned Tdim, unsigned Tnnodes>
class SolidElement{
  public:
        //! \param[in] id assign as the id_ of the tetrahedron
        //! \param[in] coords coordinates of the tetrahedron nodes
        SolidElement(unsigned id, const std::array<std::array<double, Tdim>, Tnnodes> &coords);
        //! compute centroid coordinates of a element
        void  compute_centroid();
        //! Return centroid coordinates
        //! \retval centroid_ return coordinates of the element centroide
        std::array<double, Tdim> centroid() const;
        //! Return id of the element
        unsigned id() const { return id_;}

  private:
        //! id of the element
        unsigned id_;
        //! array of the centroide coordinates
        std::array<double, Tdim> centroid_;
        //! array with the nodal coordinates of the element
        std::array<std::array<double, Tdim>, Tnnodes> coord_points_;
};

#include "tetrahedron.tcc"

#endif //GMESHLEM_SOLID_TETRAHEDRON_H_
