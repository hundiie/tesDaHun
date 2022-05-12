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
			TextCopy(data->TitleText, L"메롱", TEXT_COLOR_BLUE);
		}
}
void title_Randerer(void)
{
	
	
}
//다음 씬으로 전환 될 예정인가?
//다은 씬으로 갈 예정이면 참 아니면 거짓

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

//다음씬을 지정한다.
void Scene_SetNextScene(ESceneTypes scene)
{
	assert(s_nextScene != SCENE_NULL);
	assert(SCENE_NULL <scene)
}
//씬 전환
void Scene_Change(void)
{ 
	//이전 씬을 정리 -> Relese()
	
	//다음에 로드할 씬에 맞춰서 g_scene(현재 씬)을 구성
	//다음 씬을 초기화
	//0 == s_nextScene

}