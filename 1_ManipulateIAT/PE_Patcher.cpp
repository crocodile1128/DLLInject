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
#define getNtHdr(buf) ((IMAGE_NT_HEADERS*)((size_t)buf + ((IMAGE_DOS_HEADER*)buf)->e_lfanew))
int main()
{
	char* buf;
	DWORD fileSize;

	// Get file content
	if (!readBinFile("picaball.exe", &buf, fileSize)) {
		puts("[!] selected file not found.");
		return 0;
	}
	// Get NT Header
	IMAGE_DOS_HEADER* dosHdr = (IMAGE_DOS_HEADER*)buf;
	IMAGE_NT_HEADERS* ntHdr = (IMAGE_NT_HEADERS*)(buf + dosHdr->e_lfanew);
	// Get Import Address Table
}