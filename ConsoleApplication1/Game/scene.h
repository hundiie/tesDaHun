#pragma once
#include "Type.h"

typedef struct tagScene
{
	void (*Init)(void);//�� �ʱ�ȭ
	void (*Update)(void);//������Ʈ
	void (*Render)(void);//����
	void (*Release)(void);//������ ����� �ڿ� ����
	void* Data;

}Scene;



typedef enum tagSceneType
{
	SCENE_NULL,
	SCENE_TITLE = 1,
	SCENE_MAX

}ESceneTypes;

extern Scene g_Scene;

//���� ������ ��ȯ �� �����ΰ�?
//���� ������ �� �����̸� �� �ƴϸ� ����
bool Scene_IsSetNextScene(void);

//�������� �����Ѵ�.
void Scene_SetNextScene(ESceneTypes scene);

//�� ��ȯ
void Scene_Change(void);