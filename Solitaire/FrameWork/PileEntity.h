//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: PileEntity.h
// Description	: Generic pile header file
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
//

#pragma once

#if !defined(__PILEENTITY_H__)
#define __PILEENTITY_H__

// Library Includes
#include <list>
// Local Includes
#include "card.h"

class CPileEntity
{
public:
	CPileEntity();
	virtual ~CPileEntity();

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

	float m_fX;
	float m_fY;

private:
};

#endif

