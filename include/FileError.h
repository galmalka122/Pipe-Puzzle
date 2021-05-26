#pragma once

#include <stdexcept>

// A class that represent file exception.

class FileError : public std::runtime_error{
public:
    FileError(const std::string & what_arg) : std::runtime_error(what_arg){}

public:
};
