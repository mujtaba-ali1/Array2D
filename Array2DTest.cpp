#include <iostream>
#include "Array2DTest.h"
#include "Array2D.h"

#define _CRTDBG_MAP_ALLOC

int main() {


	try
	{
		TestInitalizeArray2D();





	}
	catch (const Exception e)
	{
		std::cout << e.getMessage();

	}
	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
	_CrtDumpMemoryLeaks();

	return 0;
}

void TestInitalizeArray2D()
{
	Array2D<int> test(1,5);
	for (int i = 0; i < test.getRow(); ++i) {
		for (int j = 0; j < test.getColumn(); ++j) {
			test.select(i, j) = i * test.getColumn() + j; 
		}
	}

	
	for (int i = 0; i < test.getRow(); ++i) {
		for (int j = 0; j < test.getColumn(); ++j) {
			std::cout << test.select(i, j) << " ";
		}
		std::cout << std::endl;
	}
}

	

