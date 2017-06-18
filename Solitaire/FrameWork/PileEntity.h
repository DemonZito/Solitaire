//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//

#pragma once

#if !defined(__PILEENTITY_H__)
#define __PILEENTITY_H__

// Library Includes
#include <list>
// Local Includes
#include "card.h"
// Types

// Constants

// Prototypes
//class CSprite;

class CPileEntity
{
public:
	CPileEntity();
	virtual ~CPileEntity();

	//virtual bool Initialise(const int _kiSpriteID, const int _kiMaskID);

	virtual void Draw() = 0;
	virtual void Process(float _fDeltaTick);

	void SetX(float _f);
	void SetY(float _f);

	float GetX() const;
	float GetY() const;


protected:

private:
	CPileEntity(const CPileEntity& _kr);
	CPileEntity& operator= (const CPileEntity& _kr);

	// Member Variables
public:

protected:

	//std::list<CCard*> m_listpSprite;

	float m_fX;
	float m_fY;

private:
};

#endif

