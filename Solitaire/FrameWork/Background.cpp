//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School.
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//

// Library Includes

// Local Includes
#include "resource.h"
#include "utils.h"
#include "game.h"
// This Include
#include "background.h"

// Static Variables

// Static Function Prototypes

// Implementation

CBackGround::CBackGround()
{

}

CBackGround::~CBackGround()
{

}

bool
CBackGround::Initialise(int _iWidth, int _iHeight)
{
	//VALIDATE(m_pSprite->Initialise(IDB_BACKGROUND, IDB_BACKGROUNDMAP));
	m_pSprite = new CSprite();
	VALIDATE(m_pSprite->Initialise(IDB_BACKGROUND, IDB_BACKGROUNDMAP));

	
	m_pSprite->SetX((float)_iWidth/2);
	m_pSprite->SetY((float)_iHeight / 2);

	return (true);
}

void
CBackGround::Draw()
{
	m_pSprite->Draw();
}

void
CBackGround::Process(float _fDeltaTick)
{
	m_pSprite->Process(_fDeltaTick);
}
