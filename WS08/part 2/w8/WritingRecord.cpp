#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"
#include <memory>

using namespace std;

namespace sdds {
    GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
        GeneratingList<EmployeeWage> activeEmp;

        // TODO: Add your code here to build a list of employees
        //         using raw pointers
        for (size_t i = 0; i < emp.size(); i++)
            for (size_t j = 0; j < sal.size(); j++)
            {
                if (emp[i].id == sal[j].id)
                {
                    EmployeeWage ew(emp[i].name, sal[j].salary);


                    ew.rangeValidator();

                    if (activeEmp.checkLuhn(emp[i].id))
                        activeEmp += ew;
                    else
                        throw "*** Employees salaray id is not valid";






                }

            }

        return activeEmp;
    }

    GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
        GeneratingList<EmployeeWage> activeEmp;
        // TODO: Add your code here to build a list of employees
        //         using smart pointers



        for (size_t i = 0; i < emp.size(); i++)
            for (size_t j = 0; j < sal.size(); j++)
            {
                if (emp[i].id == sal[j].id)
                {
                    std::shared_ptr<EmployeeWage> ew(new EmployeeWage(emp[i].name, sal[j].salary));



                    ew->rangeValidator();

                    if (activeEmp.checkLuhn(emp[i].id))
                        activeEmp += ew;
                    else
                        throw "*** Employees salaray id is not valid";
                }

            }

        return activeEmp;
    }
}