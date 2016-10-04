#include "UINode.h"
#include"ScoreManager/ScoreManager.h"

USING_NS_CC;

bool UINode::init()
{
	if (!Node::init())return false;

	/*==============================
	スコアラベルの初期化
	===============================*/
	m_pScoreLabel = Label::createWithTTF("", "font/misaki_gothic.ttf", 64);
	m_pScoreLabel->setOpacity(128);
	addChild(m_pScoreLabel);

	scheduleUpdate();

	return true;
}

void UINode::update(float dt)
{
	/*==============================
	ラベルテキストの更新
	===============================*/
	char text[128];
	sprintf(text, "%08.0f", ScoreManager::getInstance()->getScore());
	m_pScoreLabel->setString(text);
}
