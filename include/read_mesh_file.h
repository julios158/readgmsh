#ifndef GMESHLEM_READ_MESH_FILE_H
#define GMESHLEM_READ_MESH_FILE_H
#include <sstream>
#include <vector>

//!  A ReadGmsh class.
//! \brief Base class that read file.msh
//! \details ReadGmsh store the information about nodes and elements
class ReadGmsh {
	public:
		ReadGmsh(std::istream &);
		~ReadGmsh();
		bool find_section(std::string);
		std::vector <std::vector<double>> read_coords_nodes();
		void read_nodal_incidence();
		bool dimension() {return D3dim_;};
		std::vector<std::vector<int>> tetrahedron_elements()const {return tetrahedron_elements_;};
		std::vector<std::vector<int>> line_elements()const {return line_elements_;};
		std::vector<std::vector<int>> triangle_elements()const {return triangle_elements_;};

    private:
        std::istream & inputstream_;
        bool D3dim_;
        std::vector<std::vector<int>> line_elements_;
        std::vector<std::vector<int>> triangle_elements_;
        std::vector<std::vector<int>> tetrahedron_elements_;
};

#endif // GMESHLEM_READ_MESH_FILE_H
