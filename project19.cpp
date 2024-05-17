#include <iostream>
#pragma warning(disable : 4996)
using namespace std;

/*void writeToFileChar()
{
	const char* PATH_TO_FILE = "data.txt";
	FILE* file = fopen(PATH_TO_FILE, "a"); //append if (file != nullptr)
	{  //запис у файл fputc - file put char
	 // fputs - file put string  //fgetc - file get char
	 //fgets - file get string  char ch;
		bool isContinue = true;  while (isContinue)
		{
			ch = getchar();
			fputc(ch, file);   fputc(' ', file);
			cout << "Continue?? (true/false): ";   cin >> isContinue;
			cin.ignore();
		}
		fclose(file);
	}
 else
 {
	 cout << "Error";
 }
}*/
/*void writeToStr()
{
	const char* PATH_TO_FILE = "data.txt";
 FILE* file = fopen(PATH_TO_FILE, "a"); //append if (file != nullptr)
 {  //запис у файл fputc - file put char
  // fputs - file put string  //fgetc - file get char
  //fgets - file get string
  bool isContinue = true;  while (isContinue)
  {   char str[10];
   cin >> str;   fputs(str, file);
   fputs("\n", file);   cout << "Continue?? (true/false): ";
   cin >> isContinue;   cin.ignore();
  }
  fclose(file); }
 else {
  cout << "Error";
	}
}*/

/*void writeToFileFormat()
{
	const char* PATH_TO_FILE = "data.txt";

	FILE* file = fopen(PATH_TO_FILE, "w");
	if (file != nullptr)
	{
		//запис у файл fputc - file put char
		//fputs - file puts string
		//fgetsc - file ger char
		//fgets - file get string
		//fprintf - file print format

		fprintf(file, "My number is %f and %d", 5.2f, 67); //форматований вигляд




		fclose(file);
	}
	else
	{
		cout << "Error";
	}
	cout << file;
}*/

/*int main()
{
	const char* PATH_TO_FILE = "data.txt";

	FILE* file = fopen(PATH_TO_FILE, "r");
	if (file != nullptr)
	{

		while (!feof(file))
		{
			const int SIZE = 20;
			char str[SIZE] = {' '};
			fgets(str, SIZE, file);
			cout << str;
		}
		


	
	
		fclose(file);
	}
	else
	{
		cout << "Error";
	}

}*/


int main()
{
	//1

	const char* PATH_TO_FILE = "daat.txt";
	const char* OUTPUT_FILE = "output.txt"; 

	FILE* file = fopen(PATH_TO_FILE, "r");
	FILE* outfile = fopen(OUTPUT_FILE, "w");

	const int N = 100;
	char str[N];
	char lastLine[N];
	bool firstLine = true;

	if (file != nullptr && outfile != nullptr)
	{
		
		while (fgets(str, N, file))
		{
			if (!firstLine)
			{
				fputs(lastLine, outfile);
			}
			strcpy(lastLine, str);
			firstLine = false;

		}
		fclose(file);
		fclose(outfile);
	}
	else
	{
		cout << "Error";
	}

	//2

	const char* PATH_TO_FILE_2 = "file2.txt";
	FILE* file2 = fopen(PATH_TO_FILE_2, "r");

	int maxLength = 0;
	int currentLength = 0;
	char ch;

	if (file2 != nullptr)
	{
		while ((ch = fgetc(file2)) != EOF)
		{
			if (ch != '\n')
			{
				currentLength++;
			}
			else
			{
				if (currentLength > maxLength)
				{
					maxLength = currentLength;
				}
				currentLength = 0;

			}
		}
		if (currentLength > maxLength)
		{
			maxLength = currentLength;
		}

		fclose(file2);

		cout << "Length of the longest line in the file: " << maxLength << endl;
	}
	else
	{
		cout << "Error";
	}
}