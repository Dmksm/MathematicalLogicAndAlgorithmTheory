//14.10. Распил бруса 2 (10)
//На пилораму привезли брус длиной L метров.Требуется сделать N распилов.Распилы делят
//брус на части, длина которых выражается натуральными числами.Стоимость одного распила
//равна длине распиливаемого бруса.Определить минимальную стоимость распила.
//Ввод. В первой строке содержатся через пробел натуральные числа L(2 ≤ L ≤ 10^5) и N(N < L) –
//длина бруса и число распилов.
//Вывод. В единственной строке вывести минимальную стоимость распилов.
//
//Выполнил Чернядьнв Максим ПС-23
//
//Cреда visual studio 2019 язык C++
//
//Параметры ввода: <Название выполняемой программы> <Входной файл> <Выходной файл>

#include <iostream>
#include <fstream>

void CloseFiles(std::ifstream& inputFile, std::ofstream& outputFile)
{
	inputFile.close();
	outputFile.close();
}

bool CheckInputParametersNumber(int paramNumber)
{
	const int parametersNumber = 3;
	if (paramNumber != parametersNumber)
	{
		std::cout << "The number of parameters must be " << parametersNumber << " !\n";
		return false;
	}
	return true;
}

bool CheckOpenFile(std::ifstream& file, const std::string& fileName)
{
	if (!file.is_open())
	{
		std::cout << "Unable to open " << fileName << " file!\n";
		return false;
	}
	return true;
}

int GetMinValueСuts(int& num)
{
	const int minValueCuts = 1;
	if (num <= minValueCuts)
	{
		return 0;
	}
	int summation1 = (num / 2);
	int summation2 = num - summation1;
	return num + GetMinValueСuts(summation1) + GetMinValueСuts(summation2);
}

int GetMinCutsNumber(const int length, int& num)
{
	return length + GetMinValueСuts(num);
}

bool GetAndCheckParamFromFile(std::ifstream& inputFile, int& firstParam, int& secondParam)
{
	inputFile >> firstParam >> secondParam;
	const int minFirstParamValue = 2;
	const int maxFirstParamValue = 100000;
	if ((minFirstParamValue <= firstParam) && (firstParam >= maxFirstParamValue) &&
		(secondParam < firstParam))
	{
		std::cout << " minFirstParamValue " << firstParam << " must be between " <<
			minFirstParamValue << " and " << maxFirstParamValue << " and " <<
			" secondParam " << secondParam << " must be less than " << firstParam << "\n";
		return false;
	}
	return true;
}

int main(int argc, char* argv[])
{
	if (!CheckInputParametersNumber(argc))
	{
		return 1;
	}
	const std::string inputFileName = argv[1];
	std::ifstream inputFile(inputFileName);
	if (!CheckOpenFile(inputFile, inputFileName))
	{
		return 2;
	}
	const std::string outputFileName = argv[2];
	std::ofstream outputFile(outputFileName);
	int beamLength, cutsNumber;
	if (!GetAndCheckParamFromFile(inputFile, beamLength, cutsNumber))
	{
		return 3;
	}
	outputFile << GetMinCutsNumber(beamLength, cutsNumber);
	CloseFiles(inputFile, outputFile);
	return 0;
}