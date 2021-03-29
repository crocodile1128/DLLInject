#include <iostream>
#include <Windows.h>
#pragma warning (disable:4996)

BOOL readBinFile(const char* fileName, char** bufPtr, DWORD& length) // DWORD& length: Call by reference
{
	if (FILE* fp = fopen(fileName, "rb")) {
		fseek(fp, 0, SEEK_END);
		length = ftell(fp);
		*bufPtr = new char[length + 1];
		fseek(fp, 0, SEEK_SET);
		fread(*bufPtr, sizeof(char), length, fp);
		return true;
	}
	else return false;
}
int main()
{
	char* buf;
	DWORD fileSize;

	// Get file content
	if (!readBinFile("picaball.exe", &buf, fileSize)) {
		puts("[!] selected file not found.");
		return 0;
	}

	// Get Import Address Table
}