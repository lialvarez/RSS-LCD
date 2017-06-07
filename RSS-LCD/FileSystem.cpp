#include "FileSystem.h"
#include <fstream>

bool FileSystem::loadFileToList(const char *file, std::list<std::pair<char *, unsigned int>>& buffList)
{
	std::ifstream fileStream;
	fileStream.open(file, std::ios::binary | std::ios::ate);
	if (fileStream.fail())
	{
		return false;
	}
	unsigned int fileLength = (unsigned int)fileStream.tellg();
	char *buffer = new char[fileLength];
	fileStream.seekg(0, fileStream.beg);
	fileStream.read(buffer, fileLength);
	fileStream.close();
	buffList.push_back(std::make_pair(buffer, fileLength));
	return true;
}
