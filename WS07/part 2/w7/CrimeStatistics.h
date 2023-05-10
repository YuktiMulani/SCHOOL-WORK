#ifndef CRIMESTATISTICS_H
#define CRIMESTATISTICS_H
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <list>
#include <numeric>
#include <iomanip>
namespace sdds {

    // Declaring the structure
    struct Crime {
        std::string province ;  
        std::string district ;  
        std::string crime ;  
        unsigned int noCases ;  
        unsigned int year ;  
        unsigned int m_resolved ;  

    } ; 

    // Definig the class CrimeStatistics
    class CrimeStatistics {
            std::vector <Crime> crimeCollection ; 

        public:
            // Custom Constructor
            CrimeStatistics(const char* fName) ; 
            // Display       
            void display(std::ostream& out) const ;
            // Sort
            void sort(std::string fieldName) ; 
            // Clean List
            void cleanList() ; 
            // Checking if the crime exists in the collection
            bool inCollection(std::string crimeType) const ;
            // Returning crimes of a particular province
            std::list<Crime> getListForProvince(std::string provinceName) const ; 


    } ;
    
    // Free helper
    // Overloading the insertion operator.
    std::ostream& operator<<(std::ostream& out, const Crime& theCrime) ; 



}


#endif