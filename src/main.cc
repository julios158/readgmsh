#include <array>
#include <iostream>
#include <memory>
#include "tetrahedron.h"


int main () {

    // id tetrahedron element
    unsigned id = 1;

    // Tetrahedron coordinates point
     std::array<std::array<double, 3>, 4> points{{{3,2,-1}, {5, 0, 2},{-4,5,7}, {-2,4,1}}};

    //create object
     auto tet = std::make_shared<SolidElement<3,4>> (id,points);

    // centroid calculation
     tet->compute_centroid();

    // return centroid coords
    auto centroid = tet->centroid();

    // print centroid coords
   for (auto const &coords : centroid)
       std::cout << coords << std::endl;

}
