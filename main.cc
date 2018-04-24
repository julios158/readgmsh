#include <array>
#include <iostream>
#include <memory>
#include "tetrahedron.h"


int main () {

    // id tetrahedron
    unsigned id = 1; /**< id tetrahedron */

    // Tetrahedron coordinates point
    std::array<std::array<double, 3>, 4> points{{{3,2,-1}, {5, 0, 2},{-4,5,7}, {-2,4,1}}};

    //create object
    std::shared_ptr<Tetrahedron> tet = std:: make_shared<Tetrahedron>(id,points);

    // centroid calculation
    tet->compute_centroid();

    // return centroid coords
    auto centroid = tet->centroid();

    // print centroid coords
    for (unsigned i = 0; i < centroid.size(); i++)
        std::cout << centroid.at(i) << std::endl;

}
