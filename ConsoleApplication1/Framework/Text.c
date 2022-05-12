#include "Text.h"
#include "Type.h"
#include "common.h"

//�ؽ�Ʈ ����?
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
// �ؽ�Ʈ ����?
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