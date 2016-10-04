#pragma once

#include"cocos2d.h"
#include<map>

class SpriteStore
{
private:
	static SpriteStore* m_pInstance;

	SpriteStore() = default;
	~SpriteStore() = default;
	SpriteStore(const SpriteStore&) = delete;
	SpriteStore(const SpriteStore&&) = delete;
	SpriteStore& operator=(const SpriteStore&) = delete;

	std::map<int, cocos2d::SpriteBatchNode*> m_store;

public:
	static SpriteStore* getInstance()
	{
		if (m_pInstance == nullptr)m_pInstance = new SpriteStore();
		return m_pInstance;
	}

	void release();

	void loadSprite(int tag, std::string filename);

	cocos2d::Texture2D* getTexture(int tag)const;

};

//__declspec(selectany) SpriteStore* SpriteStore::m_pInstance = nullptr;