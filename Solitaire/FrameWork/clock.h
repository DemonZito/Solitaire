//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2017 Media Design School
//
// File Name	: clock.h
// Description	: Clock header file
// Author		: Madeleine, Jack and Joseph
// Mail			: madeleine.day7218@mediadesign.school.nz (leader)
//

#if !defined(__CLOCK_H__)
#define __CLOCK_H__

// Prototypes
class CClock
{
    // Member Functions
public:
    CClock();
    ~CClock();

    bool Initialise();

    void Process();

    float GetDeltaTick();

protected:

private:
    CClock(const CClock& _kr);
    CClock& operator= (const CClock& _kr);

    // Member Variables
public:

protected:
    float m_fTimeElapsed;
    float m_fDeltaTime;
    float m_fLastTime;
    float m_fCurrentTime;

private:

};

#endif    // __CLOCK_H__
