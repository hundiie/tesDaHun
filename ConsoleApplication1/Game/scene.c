#include "Scene.h"
#include "Common.h"
#include "Framework/Input.h"
#include "Framework/text.h"

Scene g_Scene;

static ESceneTypes s_nextScene;
struct titlescenedata
{
	Text text[128];
}titlescenedata;


void title_Init(void)
{
	g_Scene.Data = malloc(sizeof(titlescenedata));
	
}
void title_Update(void)
{
	
		if (Input_GetKey(VK_SPACE))
		{
			TextCopy(data->TitleText, L"�޷�", TEXT_COLOR_BLUE);
		}
}
void title_Randerer(void)
{
	
	
}
//���� ������ ��ȯ �� �����ΰ�?
//���� ������ �� �����̸� �� �ƴϸ� ����

bool Scene_IsSetNextScene(void)
{
	if (0 == s_nextScene)
	{
		return false;
	}
	else
	{
		return true;
	}
}

//�������� �����Ѵ�.
void Scene_SetNextScene(ESceneTypes scene)
{
	assert(s_nextScene != SCENE_NULL);
	assert(SCENE_NULL <scene)
}
//�� ��ȯ
void Scene_Change(void)
{ 
	//���� ���� ���� -> Relese()
	
	//������ �ε��� ���� ���缭 g_scene(���� ��)�� ����
	//���� ���� �ʱ�ȭ
	//0 == s_nextScene

}