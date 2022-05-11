#pragma once
#include <stdbool.h>

bool Renderer_Init(void);
void Renderer_Cleanup(void);
void Renderer_Flip(void);//( ^_^)/ < Hi I'm Dahoon. )
void Renderer_Clear(void);
void Renderer_DrawText(const char* text, int numberofText);