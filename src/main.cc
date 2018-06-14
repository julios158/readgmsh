#include <iostream>
#include "read_mesh_file.h"

int main () {
    std::string line;
    std::ifstream infile;
    //! open *.msh file
    infile.open("cube.msh");
    if(!infile.is_open())
    {
        std::cout << " could not open file" << std::endl;
        std::cout << " program Terminating....\n";
        exit(EXIT_FAILURE);
    }
    //create object
    ReadGmsh readmesh(infile);
    //read file.msh
    readmesh.read_mesh_file();
    //print centroid coords
    readmesh.print_centroid_coords();
    //close file
    infile.close();

}
