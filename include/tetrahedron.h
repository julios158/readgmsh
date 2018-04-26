#ifndef GMESHLEM_TETRAHEDRON_H_
#define GMESHLEM_TETRAHEDRON_H_

//!  A Tetrahedron class.
//! \brief Base class that stores the information about nodes
//! \details Tetrahedron centroide is calculated
class Tetrahedron {
    public:
        // Constructor with id and coordinates
        //! \param[in] id assign as the id_ of the tetrahedron
        //! \param[in] coords coordinates of the tetrahedron nodes
        Tetrahedron(unsigned id, const std::array<std::array<double, 3>, 4> &coords);
        //! compute centroid coordinates of a tetrahedron
        void  compute_centroid();
        //! Return centroid coordinates
        //! \retval centroid_ return coordinates of the tetrahedron centroide
        std::array<double, 3> centroid() const;
        //! Return id of the tetrahedron
        unsigned id() const { return id_; }

    private:
        //! id of the tetrahedron
        unsigned id_;
        //! array of the centroide coordinates
        std::array<double, 3> centroid_;
        //! array with the nodal coordinates of the tetrahedron
        std::array<std::array<double, 3>, 4> coord_points_;
};

#endif //GMESHLEM_TETRAHEDRON_H_
