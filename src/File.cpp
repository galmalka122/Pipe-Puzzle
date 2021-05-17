#include "File.h"

File::File(const std::string & fileName){
    auto file = std::fstream(fileName);

    if(!file)
        throw std::domain_error("");
        //FileError("File doe's not exist");

    readFile(file);

    m_iterator = begin();
}
//=============================================================================
void File::readFile(std::fstream & file) {
    auto line = std::string();
    while(std::getline(file,line))
        m_fileContent.push_back(line);
}
//=============================================================================
std::vector<std::string>::iterator File::begin(){
    return m_fileContent.begin();
}
//=============================================================================
std::vector<std::string>::iterator File::end(){
    return m_fileContent.end();
}
//=============================================================================
void File::next() {
    ++m_iterator;
}
//=============================================================================
void File::previous() {
    --m_iterator;
}
//=============================================================================
bool File::eof() const {
    return m_iterator == m_fileContent.end();
}
//=============================================================================
std::string File::getLine(int offset) const{

    /*if(getLineIndex() + offset > m_fileContent.size() || getLineIndex() - offset < 0)
        throw FileError("Attempt to access an invalid location in the file");*/

    return *(m_iterator+offset);
}
//=============================================================================
int File::getLineIndex() const {
    return m_iterator - m_fileContent.begin();
}



//=============================================================================
File &operator++(File & file) {
    file.next();
    return file;
}
//=============================================================================
File &operator--(File & file) {
    file.previous();
    return file;
}
//=============================================================================