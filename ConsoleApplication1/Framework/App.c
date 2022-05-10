#include "App.h"
#include "common.h"
#include "renderer.h"


bool App_Init()
{
	return true;
}
void processInput()
{

}
void update()
{
	Renderer_DrawText("Hello Game", sizeof("Hello Game"));
}
void render()
{
	Renderer_Flip();
}
void cleanup()
{
	Renderer_Cleanup();
}

int32 App_Run()
{
	atexit(cleanup);
	// Game Loop : ������ ���۽�Ű�� ����. ������(Frame)�̶�� �Ѵ�.
	while (true)
	{
		processInput();      // �Է� ó��
		update();         // ���� ������Ʈ
		render();         // ���� ���
	}

	return 0;
}