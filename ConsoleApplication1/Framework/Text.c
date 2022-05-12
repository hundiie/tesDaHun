#include "Text.h"
#include "Type.h"
#include "common.h"

//텍스트 복사?
void TextCopy(Text* dest, const WCHAR* src,WORD attribute)
{
    while (*src)
    {
        dest->Char.UnicodeChar = *src;
        dest->Attributes = TEXT_COLOR_WHITE;

        ++dest;
        ++src;
    }
}
// 텍스트 길이?
int32 TextLen(const Text* text)
{
    int32 result = 0;
    while (text->Char.UnicodeChar)
    {
        ++result;
        ++text;
    }

    return result;
}