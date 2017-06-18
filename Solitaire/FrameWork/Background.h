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

#if !defined(__BACKGROUND_H__)
#define __BACKGROUND_H__

// Library Includes

// Local Includes
#include "sprite.h"
// Types

// Constants

// Prototypes
//class CSprite;

class CBackGround
{
	// Member Functions
public:
	CBackGround();
	virtual ~CBackGround();

	virtual bool Initialise(int _iWidth, int _iHeight);

	virtual void Draw();
	virtual void Process(float _fDeltaTick);

private:
	CSprite* m_pSprite;
};

#endif