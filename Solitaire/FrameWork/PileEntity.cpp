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
	

	/*for (std::list<CCard*>::iterator it = m_listpSprite.begin(); it != m_listpSprite.end(); ++it)
	{
		if ((*it)->getVisible() == true)
		{
			(*it)->GetSprite()->Draw();
		}
	}*/
}

void CPileEntity::Process(float _fDeltaTick)
{

	/*for (std::list<CCard*>::iterator it = m_listpSprite.begin(); it != m_listpSprite.end(); ++it)
	{
		(*it)->GetSprite()->SetX(static_cast<int>(m_fX));
		(*it)->GetSprite()->SetY(static_cast<int>(m_fY));

		(*it)->GetSprite()->Process(_fDeltaTick);
	}*/
}

void CPileEntity::SetX(float _f)
{
	/*for (std::list<CCard*>::iterator it = m_listpSprite.begin(); it != m_listpSprite.end(); ++it)
	{
		if ((*it)->getVisible() == true)
		{
			(*it)->setX(m_fX = _f);
		}
	}*/

	m_fX = _f;
}

void CPileEntity::SetY(float _f)
{
	/*for (std::list<CCard*>::iterator it = m_listpSprite.begin(); it != m_listpSprite.end(); ++it)
	{
		if ((*it)->getVisible() == true)
		{
			(*it)->setY(m_fY = _f);
		}
	} */

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

//float CPileEntity::GetHeight() const
//{
//	return;
//}
