#include "PileEntity.h"
#include "Sprite.h"



CPileEntity::CPileEntity()
{
}


CPileEntity::~CPileEntity()
{
}

void CPileEntity::Draw()
{

}

void CPileEntity::Process(float _fDeltaTick)
{

}

void CPileEntity::SetX(float _f)
{
	m_fX = _f;
}

void CPileEntity::SetY(float _f)
{
	m_fY = _f;
}

float CPileEntity::GetX() const
{
	return m_fX;
}

float CPileEntity::GetY() const
{
	return m_fY;
}
