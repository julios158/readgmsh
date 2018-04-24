#ifndef CENTROID_TETRAHEDRON_H_
#define CENTROID_TETRAHEDRON_H_
#include <array>

//!  A Tetrahedron class.
//! \brief Base class that stores the information about nodes
//! \details Tetrahedron centroide is calculated
class Tetrahedron {
    public:
        // Constructor with id and coordinates
        //! \param[in] id assign as the id_ of the tetrahedron
        //! \param[in] coords coordinates of the tetrahedron nodes
        Tetrahedron(unsigned id, std::array<std::array<double, 3>, 4>coord);
        //! compute centroid coordinates of a tetrahedron
        void  compute_centroid();
        //! Return centroid coordinates
        //! \param[out] centroid_ return coordinates of the tetrahedron centroide
        std::array<double, 3> centroid() const;
        //! Return id of the tetrahedron
        unsigned id() const { return id_; }

    private:
        // private attributes
        //! id of the tetrahedron
        unsigned id_;
        //! array of the centroide coordinates
        std::array<double, 3> centroid_;
        //! array with the nodal coordinates of the tetrahedron
        std::array<std::array<double, 3>, 4>coord_points_;
};

#endif //LEM_CENTROID_TETRAHEDRON_H
