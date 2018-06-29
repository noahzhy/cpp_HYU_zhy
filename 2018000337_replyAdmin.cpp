#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string textList[20], temp;
int  number = 0, maxLines = 6;
bool ouputOrNot = true;

void refresh() {
	temp = "";
	for (int i = 1; i < maxLines; i++)
	{
		for (int j = 0; j < maxLines - i; j++)
		{
			if (textList[j] == "")
			{
				temp = textList[j];
				textList[j] =  textList[j + 1];
				textList[j + 1] = temp;
			}
		}
	}

};

void removeListByOne(int a) {
	textList[a] = "";

};

void output() {
	number = 0;
	maxLines = 0;
	for (int i = 0; i < 21; i++)
	{
		if ( textList[i] != "")
		{
			cout << number << " " << textList[i] << endl;
			number++;
			maxLines++;
		}
	}
};

void addList(string a) {
	textList[maxLines++] = a;
};


int main()
{

	int deleteNumber = 0,  q = 0;
	string userCommand;
	int commandContent[21];

	string strTemp;

	textList[0] = "Hello, Reply Administrator!";
	textList[1] = "I will be a good programmer.";
	textList[2] = "This class is awesome.";
	textList[3] = "Professor Lim is wise.";
	textList[4] = "Two TAs are kind and helpful.";
	textList[5] = "I think male TA looks cool.";

	while (1) {
		stringstream sStream;
		for (int i = 0; i < 21; ++i)
		{
			commandContent[i] = -1;
		}
		cin >> userCommand;
		if (userCommand == "#remove")
		{
			while (1) {
				if (getchar() == '\n')
				{
					break;
				} else {
					cin >> strTemp;
					int pos = strTemp.find(',');
					int fromto = strTemp.find('-');
					int tempft = fromto;
					int fromto_pre = strTemp[fromto - 1] ;
					int fromto_next = strTemp[fromto + 1];

					while (fromto != string::npos)
					{
						strTemp = strTemp.replace(fromto, 1, 1, ' ');
						fromto = strTemp.find('-');
					}
					while (pos != string::npos)
					{
						strTemp = strTemp.replace(pos, 1, 1, ' ');
						pos = strTemp.find(',');

					}
					sStream << strTemp;
					if ((fromto_pre >= 0) && (fromto_next >= 0))
					{
						for (int i = fromto_pre + 1; i < fromto_next; i++)
						{
							sStream << " " << (char)i << " ";
						}
					}

					q = 0;

					double ddd;

					if (sStream >> ddd) {
						while (sStream) {
							sStream >> commandContent[q++];
							ouputOrNot = true;
						}

					} else {

						ouputOrNot = false;
					}
				}
			}

			for (int i = 0; i < 21; i++)
			{
				if (commandContent[i] != -1)
				{
					removeListByOne(commandContent[i]);
				}
			}

			refresh();

			if (ouputOrNot)
			{
				output();
			}

		} else {
			addList(userCommand);
			output();
		}
		if (userCommand == "#quit")
		{
			return 0;
		}

	}
	return 0;
}