#include "ComplexNumber.h"
#include "Employee.h"

void testComplexNumber()
{
    testReadPrint();
    testSum();
    testSubtraction();
    testMultiplication();
    testDivision();
    testAverage();
    testSort();
}
void testEmployee()
{
    testHasEmployee();
    testFindBoss();
}

int main()
{
   testComplexNumber();
   testEmployee();
}

