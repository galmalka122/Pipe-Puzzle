#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iterator>

//#include "FileError.h"

// A class that represent a file.

class File {
public:
    File(const std::string &);

    std::vector<std::string>::iterator begin();
    std::vector<std::string>::iterator end();

    bool eof() const;
    std::string getLine(int = 0) const;
    int getLineIndex() const;
    void next();
    void previous();

private:
    std::vector<std::string> m_fileContent;
    std::vector<std::string>::iterator m_iterator;
    void readFile(std::fstream &);
};
//=============================================================================
File & operator++(File &);
File & operator--(File &);
//=============================================================================