#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include "CrimeStatistics.h"
using namespace std;
namespace sdds {

    // Designing the constructor for reading the file
    CrimeStatistics::CrimeStatistics(const char* fName){
        std::ifstream is(fName) ; 
        if(is.is_open()){
            // File Exists
            while(is){
                std::string str ;  
                // Getting one line from the file
                std::getline(is ,str , '\n') ; 

                // Extracting different attributes from the line
                std::string provinceSpace = str.substr(0,25) ; 
                std::string districtSpace = str.substr(25,25) ; 
                std::string crimeSpace = str.substr(50,25) ; 
                std::string yearSpace = str.substr(75,5) ; 
                std::string noCasesSpace = str.substr(80,5) ;
                std::string noCasesResolveSpace = str.substr(85,5) ;   
                // Removing the space from the attributes using 'erase'
                provinceSpace.erase(remove(provinceSpace.begin(), provinceSpace.end(), ' '), provinceSpace.end());
                districtSpace.erase(remove(districtSpace.begin(), districtSpace.end(), ' '), districtSpace.end());
                crimeSpace.erase(remove(crimeSpace.begin(), crimeSpace.end(), ' '), crimeSpace.end());
                yearSpace.erase(remove(yearSpace.begin(), yearSpace.end(), ' '), yearSpace.end());
                noCasesSpace.erase(remove(noCasesSpace.begin(), noCasesSpace.end(), ' '), noCasesSpace.end());
                noCasesResolveSpace.erase(remove(noCasesResolveSpace.begin(), noCasesResolveSpace.end(), ' '), noCasesResolveSpace.end());

                // Creating a Crime object and storing the attributes.

                Crime crimeDetail ; 
                crimeDetail.province = provinceSpace ; 
                crimeDetail.district = districtSpace ; 
                crimeDetail.crime = crimeSpace ; 
                crimeDetail.year = std::stoi(yearSpace) ;
                crimeDetail.noCases = std::stoi(noCasesSpace);
                crimeDetail.m_resolved = std::stoi(noCasesResolveSpace) ; 

                

                // Storing the crime object in the vector.
                crimeCollection.push_back(crimeDetail); 

                
                // Checking if the end of file reached.
                if(is.peek() == EOF){
                    is.setstate(std::ios_base::badbit) ; 
                } ; 


            } ; 

        }else{
            // File not open or exist. // Throw an exception
            throw "File Name Incorrect !!!" ; 
        } ; 


    } ; 

    // Display function
    void CrimeStatistics::display(std::ostream& out) const{
        std::for_each(crimeCollection.begin() , crimeCollection.end() , [&](const Crime& crime){
            out << crime ; 
            out << std::endl ; 
        }) ; 

        // Total No of Cases
        unsigned int init = 0 ; 
        unsigned int totalCases = std::accumulate(crimeCollection.begin() , crimeCollection.end() ,init , [](unsigned int init, const Crime& crime){
            return init + crime.noCases ; 

        } ) ; 

        // Total Resolved Cases
        unsigned int totalResolvedCases = std::accumulate(crimeCollection.begin() , crimeCollection.end() ,init , [](unsigned int init, const Crime& crime){
            return init + crime.m_resolved ; 

        } ) ; 

        // Displaying the totals.
        out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
        // Total Crimes
        out << "| " ; 
        out.width(77) ; 
        out.setf(std::ios::right) ;
        out << "Total Crimes:"; 
        out.width(7) ;
        out << totalCases ;   
        out << " |" ; 
        out.unsetf(std::ios::right) ; 
        out << std::endl ; 
        // Total Resolved Cases
        out << "| " ; 
        out.width(77) ; 
        out.setf(std::ios::right) ;
        out << "Total Resolved Cases:" ; 
        out.width(7);
        out << totalResolvedCases ;  
        out << " |" ; 
        out.unsetf(std::ios::right) ; 
        out << std::endl ; 


    } ; 

    // Overloading the insertion operator
    std::ostream& operator<<(std::ostream& out, const Crime& theCrime){
        out << "| " ; 
        out.unsetf(std::ios::right);
        out.width(21) ; 
        out.setf(std::ios::left);
        out << theCrime.province ; 
        out.unsetf(std::ios::left);
        out << " | " ; 
        out.width(15);
        out.setf(std::ios::left);
        out << theCrime.district ; 
        out.unsetf(std::ios::left);
        out << " | " ; 
        out.width(20);
        out.setf(std::ios::left);
        out << theCrime.crime ; 
        out.unsetf(std::ios::left);
        out << " | " ; 
        out.width(6);
        out.setf(std::ios::right);
        out << theCrime.year ; 
        out.unsetf(std::ios::right);
        out << " | " ; 
        out.width(4);
        out.setf(std::ios::right);
        out << theCrime.noCases ; 
        out.unsetf(std::ios::right);
        out << " | " ; 
        out.width(3) ; 
        out.setf(std::ios::right);
        out << theCrime.m_resolved ; 
        out.unsetf(std::ios::right) ;
        out << " |" ; 

        return out ; 
    } ; 


    // Sort function
    void CrimeStatistics::sort(std::string fieldName){
        
        if(fieldName == "Province"){
            std::sort(crimeCollection.begin() , crimeCollection.end() , [](const Crime& crime1 , const Crime& crime2){
                return crime1.province < crime2.province ; 

            }) ;  

        }else if(fieldName == "Crime"){
            std::sort(crimeCollection.begin() , crimeCollection.end() , [](const Crime& crime1 , const Crime& crime2){
                return crime1.crime < crime2.crime ; 

            }) ;  

        }else if(fieldName == "Cases"){
            std::sort(crimeCollection.begin() , crimeCollection.end() , [](const Crime& crime1 , const Crime& crime2){
                return crime1.noCases < crime2.noCases ; 

            }) ;  

        }else{
            // Resolved
            std::sort(crimeCollection.begin() , crimeCollection.end() , [](const Crime& crime1 , const Crime& crime2){
                return crime1.m_resolved < crime2.m_resolved ; 

            }) ;  

        } ; 


    } ; 

    // Clean List
    void CrimeStatistics::cleanList(){
        std::vector <Crime> crimesWithoutNone(crimeCollection.size()) ; 
        std::transform(crimeCollection.begin() , crimeCollection.end() , crimesWithoutNone.begin(),[](Crime crimeDetail){
            
            if(crimeDetail.crime == "[None]"){
                crimeDetail.crime = "" ; 
            };
            return crimeDetail ;  

        }) ; 

        // Assigning it to the new collection.
        crimeCollection = crimesWithoutNone ; 
    } ;

    // Incollection
    bool CrimeStatistics::inCollection(std::string crimeType) const{

        unsigned int noCount = std::count_if(crimeCollection.begin(), crimeCollection.end() ,[=](const Crime& crimeDetail){
             return crimeType == crimeDetail.crime ; 
        }) ;

        return (noCount > 0)?true : false ; 

    }  ; 

    // Returning collection of a particular province.
    std::list<Crime> CrimeStatistics::getListForProvince(std::string provinceName) const{
        std::vector <Crime> crimesInProvinceVector(crimeCollection.size()) ; 
        auto it = std::copy_if(crimeCollection.begin() , crimeCollection.end() , crimesInProvinceVector.begin(),[=](const Crime& crimeDetail){
            return crimeDetail.province == provinceName ; 
        });
        
        unsigned int size = it - crimesInProvinceVector.begin() ;
        std::list <Crime> crimesInProvinceList(size) ; 
        std::copy(crimesInProvinceVector.begin() , it , crimesInProvinceList.begin());
        
        
        return crimesInProvinceList ; 
        
    } ; 


}


//Total Crimes:  35364