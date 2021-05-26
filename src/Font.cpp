#include "Font.h"

Font::Font()
{
    if(!m_font.loadFromFile("Impact.ttf"))
        throw FileError("Impact.ttf doe's not exist");
}
//=============================================================================
Font & Font::FontObject() {
    static Font fontObject;
    return fontObject;
}
//=============================================================================
const sf::Font & Font::getFont() const {
    return m_font;
}
//=============================================================================