#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <vector>
#include "read_mesh_file.h"
#include "tetrahedron.h"

void print_centroid_coords(std::istream & infile)
{
    //! constructor ReadGmsh
    ReadGmsh readmesh(infile);
    //! \Read mesh nodes from an input file.
    //! \@return nodes coordinates
    std::vector<std::vector<double>>nodes = readmesh.read_coords_nodes();
    //! \Read mesh nodal incidence from an input file.
    readmesh.read_nodal_incidence();
    //! \@return nodal incidence of tetrahedra
    std::vector<std::vector<int>> tetrahedra =  readmesh.tetrahedron_elements();


    bool D3dim = readmesh.dimension();
    if (D3dim){
        const int Tdim = 3;
        const int npoint = 4;
        // Tetrahedron coordinates point
        std::array<std::array<double, Tdim>,  npoint > tetpoints;
        for(unsigned k = 0; k < tetrahedra.size(); k++){
            for(unsigned j = 0; j <  npoint ; j++){
                for(unsigned i = 0; i < Tdim; i++)
                   tetpoints.at(j).at(i)= nodes.at(tetrahedra.at(k).at(j)).at(i);
            }
            auto tet = std::make_shared<SolidElement<Tdim,npoint>> (k,tetpoints);
            // centroid calculation
            tet->compute_centroid();
            // return centroid coords
            auto centroid = tet->centroid();
            // print centroid coords
            for (auto const &coords : centroid)
                std::cout << coords << ", ";
            std::cout << std::endl;
        }
    }
}

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

    print_centroid_coords(infile);

    infile.close();

}
