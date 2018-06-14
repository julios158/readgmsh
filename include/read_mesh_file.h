#ifndef GMESHLEM_READ_MESH_FILE_H
#define GMESHLEM_READ_MESH_FILE_H
#include <array>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <stdio.h>
#include <vector>
#include "tetrahedron.h"

//!  A ReadGmsh class.
//! \brief Base class that read file.msh
//! \details ReadGmsh store the information about nodes and elements
class ReadGmsh {
	public:
        //! \param[in] infile
		ReadGmsh(std::istream &);
		~ReadGmsh();
		//! \Search for a section named "$sectionName" in the ReadGmsh's stream.
        //! \@param  string name of the section to search for
        //! \@return true if the section is found, false otherwise.
		bool find_section(std::string);
        //! \read nodes and elements information.
		void read_mesh_file();
        //! \Read mesh nodes from an input file.
        //! \@return nodes coordinates
        std::vector <std::vector<double>> read_coords_nodes();
        //! \Read and storage mesh nodal incidence from an input file.
		void read_nodal_incidence();
        //! \print centroid coordinates of the tetrahedra elements.
		void print_centroid_coords();

    private:
        std::istream & inputstream_;
        bool D3dim_;
        int nnodes_;
        std::vector <std::vector<double>> nodes_;
        std::vector<std::vector<int>> line_elements_;
        std::vector<std::vector<int>> triangle_elements_;
        std::vector<std::vector<int>> tetrahedron_elements_;
};

#endif // GMESHLEM_READ_MESH_FILE_H
