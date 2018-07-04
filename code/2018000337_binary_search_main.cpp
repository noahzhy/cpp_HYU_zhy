#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "2018000337_binary_search.h"

using namespace std;

int main(void)
{
	BinarySearch *binarySearch = NULL;

	while (true)
	{
		if (binarySearch == NULL) // input array
		{
			string inputs;
			getline(cin, inputs);

			string *argv = new string[inputs.length()]; // more than count
			string token;
			size_t pos;
			int argc = 0;

			while (true)
			{
				pos = inputs.find(' ');
				token = inputs.substr(0, pos);

				argv[argc++] = token;

				if (pos >= inputs.length()) break;
				else inputs.erase(0, pos + 1);
			}

			int *elements = NULL;
			int elementCount = 0;

			for (int i = 0; i < argc; ++i)
			{
				string arg = argv[i];
				if (arg == "{" && elements == NULL) elements = new int[argc];
				else if (isdigit(arg[arg.length() - 1])) elements[elementCount++] = atoi(arg.c_str());
				else if (arg == "}")
				{
					binarySearch = new BinarySearch(elements, elementCount);
					delete elements;
					elements = NULL;
					elementCount = 0;
				}
			}
		}
		else // input element to find
		{
			int element;
			cin >> element;

			if (element < -998) break;

			cout << binarySearch->getIndex(element) << endl;
		}
	}

//    delete binarySearch;
	return 0;
}
