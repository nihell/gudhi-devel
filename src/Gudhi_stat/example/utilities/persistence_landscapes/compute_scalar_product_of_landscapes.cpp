/*    This file is part of the Gudhi Library. The Gudhi library
 *    (Geometric Understanding in Higher Dimensions) is a generic C++
 *    library for computational topology.
 *
 *    Author(s):       Pawel Dlotko
 *
 *    Copyright (C) 2015  INRIA Sophia-Saclay (France)
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */



#include <gudhi/abstract_classes/Abs_Topological_data.h>
#include <gudhi/concretizations/Persistence_landscape.h>



using namespace Gudhi;
using namespace Gudhi::Gudhi_stat;

#include <iostream>
#include <sstream>


int main( int argc , char** argv )
{
	std::cout << "This program compute scalar product of persistence landscapes stored in a file (the file needs to be created beforehand). \n";	
	std::cout << "The parameters of this programs are names of files with persistence landscapes.\n";

	std::vector< const char* > filenames;
	for ( int i = 1 ; i < argc ; ++i )
	{
		filenames.push_back( argv[i] );
	}
	std::vector< Persistence_landscape > landscaspes;
	landscaspes.reserve( filenames.size() );
	for ( size_t file_no = 0 ; file_no != filenames.size() ; ++file_no )
	{
		std::cout << "Reading persistence landscape from a file : " << filenames[file_no] << std::endl;
		Persistence_landscape l;
		l.load_landscape_from_file( filenames[file_no] );
		landscaspes.push_back( l );
	}
		
	//and now we will compute the scalar product of landscapes.
	
	//first we prepare an array:
	std::vector< std::vector< double > > scalar_product( filenames.size() );
	for ( size_t i = 0 ; i != filenames.size() ; ++i )
	{
		std::vector< double > v( filenames.size() , 0 );
		scalar_product[i] = v;
	}
	
	//and now we can compute the scalar product:
	for ( size_t i = 0 ; i != landscaspes.size() ; ++i )
	{
		for ( size_t j = i ; j != landscaspes.size() ; ++j )
		{
			scalar_product[i][j] = scalar_product[j][i] = compute_inner_product( landscaspes[i], landscaspes[j] ) ;
		}
	}
	
	//and now output the result to the screen and a file:
	ofstream out;
	out.open( "scalar_product" );
	for ( size_t i = 0 ; i != scalar_product.size() ; ++i )
	{
		for ( size_t j = 0 ; j != scalar_product.size() ; ++j )
		{
			cout << scalar_product[i][j] << " ";
			out << scalar_product[i][j] << " ";
		}
		cout << endl;
		out << endl;
	}
	out.close();
		
	return 0;
}
