#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include "tetrahedron.h"


int main () {
    /// id tetrahedron
    int id;
    /// Tetrahedron coordinates point
    std::array<std::array<double, 3>, 4> points{{ {3,2,-1}, {5, 0, 2},{-4,5,7}, {-2,4,1}}};

    ///create object
    std::shared_ptr<Tetrahedron> tet = std:: make_shared<Tetrahedron>(2,points);
    /// return id tetrahedron
    id = tet->id();
    /// centroid calculation
    tet->compute_centroid();
    /// return centroid coords
    tet->centroid();

    std::string line;
    std::ifstream infile;
    infile.open("/home/julioa/CLionProjects/centroid/cube.msh");
    // open *.msh file
    if(!infile.is_open())
    {
        std::cout << " could not open file" << std::endl;
        std::cout << " program Terminating....\n";
        exit(EXIT_FAILURE);
    }

    while(line != "$EndElements") // To get you all the lines.
    {
        getline(infile,line); // Saves the line in STRING.
        std::cout<<line; // Prints our STRING.
    }

    infile.close();

   // system ("pause");
}
