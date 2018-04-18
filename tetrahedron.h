/* File: tetrahedron.h
   Details: Implementation of  tetrahedron class for calculate a centroid of a tetrahedron.
   Author: Julio Rueda on 10/04/18.
*/

#ifndef LEM_CENTROID_TETRAHEDRON_H
#define LEM_CENTROID_TETRAHEDRON_H
#include <array>
#include <iostream>

//!  A Tetrahedron class.
/*!
  Basic information of a Tetrahedron where
  is possible to calculate the centroid of a tetrahedron
*/
class Tetrahedron {
    //! private attributes
    unsigned id_;
    std::array<double, 3> centroid_; /**< array with the centroid coords */
    std::array<std::array<double, 3>, 4>coord_points_; /**< array with the nodal coords */
/*!
-------------------------------------------
TETRAHEDRON
---------------------------------------------
               n4
             / | \
            /  |  \
           /   |   \
         /     |     \
        /      |      \
       /       |       \
     /         |        \
    /          |          \
   /           |           \
 n1------------|-----------n3
   \           |           /
     \         |         /
       \       |       /
         \     |     /
           \   |   /
             \ | /
               n2
--------------------------------------------
*/

public:
    //! A constructor
    /*!
      \sa Tetrahedron()
      \param id the first argument.
      \param coord the second argument.
    */
    Tetrahedron(int id, std::array<std::array<double, 3>, 4>coord);
    //! compute centroid function
    /*!calculate the centroid coordinates of a tetrahedron
     */
    void  compute_centroid();
    //! centroid function which return tetrahedron centroid
    /*!
      \sa centroid()
      \return centroid_.
    */
    std::array<double, 3> centroid() const;
    //! id function which return tetrahedron id
    /*!
      \sa id()
      \return id_.
    */
    int id();
};

#endif //LEM_CENTROID_TETRAHEDRON_H
