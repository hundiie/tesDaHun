#pragma once
#include "Type.h"

typedef struct tagScene
{
	void (*Init)(void);//씬 초기화
	void (*Update)(void);//업데이트
	void (*Render)(void);//랜더
	void (*Release)(void);//씬에서 사용한 자원 정리
	void* Data;

}Scene;



typedef enum tagSceneType
{
	SCENE_NULL,
	SCENE_TITLE = 1,
	SCENE_MAX

}ESceneTypes;

extern Scene g_Scene;

//다음 씬으로 전환 될 예정인가?
//다은 씬으로 갈 예정이면 참 아니면 거짓
bool Scene_IsSetNextScene(void);

//다음씬을 지정한다.
void Scene_SetNextScene(ESceneTypes scene);

//씬 전환
void Scene_Change(void);