#include"SpriteStore.h"

USING_NS_CC;

SpriteStore* SpriteStore::m_pInstance = nullptr;

void SpriteStore::release()
{
	for (auto& elem : m_store)
	{
		elem.second->release();
	}

	delete m_pInstance;
}

void SpriteStore::loadSprite(int tag,std::string filename)
{
	m_store[tag] = SpriteBatchNode::create(filename);
	m_store[tag]->retain();
}

cocos2d::Texture2D* SpriteStore::getTexture(int tag)const
{
	if (m_store.find(tag) == m_store.end())return nullptr;
	return m_store.at(tag)->getTexture();
}