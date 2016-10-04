#include "DebugNode.h"

USING_NS_CC;

DebugStringNode* DebugStringNode::m_pInstance = nullptr;

DebugStringNode * DebugStringNode::getInstance()
{
	if (!m_pInstance)m_pInstance = new DebugStringNode();
	return m_pInstance;
}

void DebugStringNode::release()
{
	delete m_pInstance;
}

void DebugStringNode::init(cocos2d::Node * pTargetNode)
{
	m_pTargetNode = pTargetNode;
	m_debugStrList.clear();
	for (int f1 = 0; f1 < 20; f1++)
	{
		auto label = Label::createWithSystemFont("", "Arial", 32);
		label->setAnchorPoint(Vec2(0.f, 0.f));
		label->setPosition(0.f, Director::getInstance()->getVisibleSize().height - 32.f*(f1+1));
		m_debugStrList.push_back(label);
		m_pTargetNode->addChild(label);
	}
}

void DebugStringNode::update()
{
	for (auto& elem : m_debugStrList)
	{
		elem->setString("");
	}

	for (int f1 = 0; f1 < m_stringBuffer.size(); f1++)
	{
		m_debugStrList[f1]->setString(m_stringBuffer[f1]);
	}
	m_stringBuffer.clear();
}

void DebugStringNode::printDebugString(std::string debugString)
{
	m_stringBuffer.push_back(debugString);
}