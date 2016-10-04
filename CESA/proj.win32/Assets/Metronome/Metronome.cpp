#include"Metronome.h"
#include"Utils/Utils.h"

USING_NS_CC;

Metronome::Metronome(ADX2Player* adx2Player,float bpm,float beatNum) :
	m_adx2Player(adx2Player),
	m_bpm(bpm),
	m_beatNum(beatNum)
{
}

bool Metronome::init()
{
	if (!Node::init())return false;

	auto winSize = Director::getInstance()->getVisibleSize();

	m_spr = Sprite::create("ring.png");
	m_spr->setOpacity(128);
	m_spr->setScale(0.0f);

	float interval = 1.f / (m_bpm / 60.f);

	auto scaleOut = ScaleTo::create(interval/2.0f, 1.0f);
	auto scaleIn = ScaleTo::create(interval/2.0f, 0.3f);
	auto easeOut = EaseOut::create(scaleOut, 2.0f);
	auto easeIn = EaseIn::create(scaleIn, 2.0f);

	auto seq = Sequence::create(easeOut, easeIn, nullptr);
	auto rep = RepeatForever::create(seq);
	m_spr->runAction(rep);
	
	addChild(m_spr);

	this->scheduleUpdate();
	
	return true;
}

void Metronome::update(float dt)
{

}