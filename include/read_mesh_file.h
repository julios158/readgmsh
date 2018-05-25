#ifndef GMESHLEM_READ_MESH_FILE_H
#define GMESHLEM_READ_MESH_FILE_H
#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <iostream>
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
        //! \Read mesh nodes from an input file.
        //! \@return nodes coordinates
        std::vector <std::vector<double>> read_coords_nodes();
        //! \Read mesh nodal incidence from an input file.
		void read_nodal_incidence();
		//! \@return true if 3D analysis type
		bool dimension() {return D3dim_;};
		void print_centroid_coords();

    private:
        std::istream & inputstream_;
        bool D3dim_;
        std::vector<std::vector<int>> line_elements_;
        std::vector<std::vector<int>> triangle_elements_;
        std::vector<std::vector<int>> tetrahedron_elements_;
};

#endif // GMESHLEM_READ_MESH_FILE_H
