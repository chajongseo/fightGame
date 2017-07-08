#include "stdafx.h"
#include "mainGame.h"

//======================================
// �����ڶ� �Ҹ��ڴ� ���� �ʴ´�
//======================================
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}


//======================================
// �����ڶ� �Ҹ��ڴ� ���� �ʴ´�
//======================================


//�ʱ�ȭ�� ������ ���⿡�ٰ� �ض�
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("����ϲ�", "background.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("bullet", "bullet.bmp", 21, 21, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("battle", "battle.bmp", 0, 0, 1536, 79, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("missilePF", "missilePF.bmp", 0, 0, 576, 44, 16, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("��ư", "button.bmp", 0, 0, 122, 62, 1, 2, true, RGB(255, 0, 255));


	SCENEMANAGER->addScene("����Ʈ��", new selectScene);
	SCENEMANAGER->addScene("��Ÿ��", new starcraftScene);

	SCENEMANAGER->changeScene("����Ʈ��");
	
	return S_OK;
}

//�޸� ������ ������ ���⿡�ٰ� �ض�
void mainGame::release(void)
{
	gameNode::release();

}

//������(��) ������ ���⿡�ٰ� �ض�
void mainGame::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();
	
}

//������ ���⿡�� �׷��� 
void mainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================ ���� �ǵ������� ================

	IMAGEMANAGER->findImage("����ϲ�")->render(getMemDC(), 0, 0);
 
	SCENEMANAGER->render();

	TIMEMANAGER->render(getMemDC());

	//===============�Ʒ��� �ǵ������� =================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
