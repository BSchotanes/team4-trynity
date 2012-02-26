////////////////////////////////////////////////////////////////////////
//    File Name				:	"CBaseObject.cpp"
//
//    Author Name			:	Daniel Lima
//    Creation Date			:	02/25 - 8:30 PM
//    Purpose				:	Class that inherits from IBaseInterface
//								and contains all the functionality that
//								is common to all game objects
////////////////////////////////////////////////////////////////////////

// Precompiled header
#include "StdAfx.h"
// Include header file
#include "CBaseObject.h"

#include "../States/CGameplayState.h"
#define SCREEN_POS_X(X) CGameplayState::GetInstance()->GetScreenPositionX(X)
#define SCREEN_POS_Y(Y) CGameplayState::GetInstance()->GetScreenPositionY(Y)


// Constructor
CBaseObject::CBaseObject(long lPositionX, long lPositionY, unsigned int uiSpeed,
	int nImageID, unsigned int uiWidth, unsigned int uiHeight, bool bActive)
{
	m_ptPosition.x		= lPositionX;
	m_ptPosition.y		= lPositionY;
	m_uiSpeed			= uiSpeed;
	m_nImageID			= nImageID;
	m_uiWidth			= uiWidth;
	m_uiHeight			= uiHeight;
	m_bActive			= bActive;
	m_anmCurrent		= -1;
	m_vecVelocity.fX	= 0.0f;
	m_vecVelocity.fY	= 0.0f;
}

// Common routines
void CBaseObject::Update(float fElapsedTime)
{
	if(!IsActive()) return;

	// Update position based on velocity
	m_ptPosition.x = (long) (m_ptPosition.x + m_vecVelocity.fX * fElapsedTime);
	m_ptPosition.y = (long) (m_ptPosition.y + m_vecVelocity.fY * fElapsedTime);

	if(m_anmCurrent != -1 && m_anmCurrent < (int)m_vpAnimations.size())
	{
		m_vpAnimations[m_anmCurrent]->Update(fElapsedTime);
	}
}

void CBaseObject::Render(void)
{
	if(!IsActive()) return;

	POINT ptAnchor = { m_uiWidth / 2, m_uiHeight / 2 };

	// If there's no animation, render object's image in its position
	if(m_vpAnimations.empty())
	{
		TEX_MNG->Draw(m_nImageID, SCREEN_POS_X(m_ptPosition.x) - ptAnchor.x, SCREEN_POS_Y(m_ptPosition.y) - ptAnchor.y);
	}
	else if(m_anmCurrent != -1 && m_anmCurrent < (int)m_vpAnimations.size())
	{
		m_vpAnimations[m_anmCurrent]->Render(SCREEN_POS_X(m_ptPosition.x), SCREEN_POS_Y(m_ptPosition.y));
	}
}

RECT CBaseObject::GetCollisionRect(void) const
{
	RECT rectCollision = { 0, 0, 0, 0 };
	Point ptAnchor(m_uiWidth / 2, m_uiHeight / 2);

	// If there's no animation use the width and height to get
	// a collision rect
	if(m_vpAnimations.empty())
	{
		rectCollision.left		= m_ptPosition.x - ptAnchor.x;
		rectCollision.top		= m_ptPosition.y - ptAnchor.y;
		rectCollision.right		= rectCollision.left + m_uiWidth;		
		rectCollision.bottom	= rectCollision.top + m_uiHeight;
	}
	// Else if there's an animation playing use the rect returned
	// by the animation manager
	else if(m_anmCurrent != -1 && m_anmCurrent < (int)m_vpAnimations.size())
	{
		rectCollision = m_vpAnimations[m_anmCurrent]->ReturnCollisionRect();
		ptAnchor = m_vpAnimations[m_anmCurrent]->ReturnAnchorPoint();

		rectCollision.left		+= m_ptPosition.x - ptAnchor.x;
		rectCollision.top		+= m_ptPosition.y - ptAnchor.y;
		rectCollision.right		+= m_ptPosition.x - ptAnchor.x;
		rectCollision.bottom	+= m_ptPosition.y - ptAnchor.y;
	}

	return rectCollision;
}

// Check Collision against another object
// Return true if collided, false otherwise
bool CBaseObject::CheckCollision(IBaseInterface* pObject)
{
	RECT rectCollisionResult = { 0, 0, 0, 0 };
	if(IntersectRect(&rectCollisionResult, &GetCollisionRect(), &pObject->GetCollisionRect()))
		return true;
	else return false;
}

// Add and release references
void CBaseObject::AddRef(void)
{
	m_uiRefCount++;
}
void CBaseObject::Release(void)
{
	m_uiRefCount--;

	if(m_uiRefCount == 0)
		delete this;
}

// Destructor
CBaseObject::~CBaseObject(void)
{
	for(unsigned int i = 0; i < m_vpAnimations.size(); ++i)
		delete m_vpAnimations[i];

	m_vpAnimations.clear();
}


// Animation accessors and mutators
CAnimationPlayer* CBaseObject::GetAnimationPlayer (unsigned int uiAnmIndex ) const
{
	if(uiAnmIndex < m_vpAnimations.size())
		return m_vpAnimations[uiAnmIndex];
	else return nullptr;
}
void CBaseObject::PushAnimationPlayer (CAnimationPlayer* pAnimation)
{
	if(pAnimation != nullptr)
		m_vpAnimations.push_back(pAnimation);
}
bool CBaseObject::PopAnimationPlayer (void)
{
	if(m_vpAnimations.empty())
		return false;
	m_vpAnimations.pop_back();
	return true;
}