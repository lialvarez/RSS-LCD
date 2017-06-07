#ifndef FILESYSTEM_H
#define FILESYSTEM_H

#include <string>
#include <list>
#include <vector>


class FileSystem
{
public:
	bool loadFileToList(const char *file, std::list<std::pair<char *, unsigned int>>& buffList);

private:

};

#endif // !FILESYSTEM_H
