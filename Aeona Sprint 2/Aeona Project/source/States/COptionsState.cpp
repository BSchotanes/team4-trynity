////////////////////////////////////////////////////////////////////////
//    File Name				:	"COptionsState.cpp"
//    Author Name			:	Bryan Schotanes
//    Creation Date			:	02/08/12 - 7:47 PM
//    Purpose				:	Contains the COptionsState
////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "../StdAfx.h"
#include "COptionsState.h"
#include "CVideoOptionsState.h"
#include "CAudioOptionsState.h"
#include "CMainMenuState.h"

COptionsState* COptionsState::m_pInstance = NULL;

COptionsState::COptionsState()
{
}

COptionsState::~COptionsState()
{
}

COptionsState* COptionsState::GetInstance()
{
	if(m_pInstance == NULL)
	{
		m_pInstance = new COptionsState;
	}
	return m_pInstance;
}

void COptionsState::DeleteInstance()
{
	if(m_pInstance != NULL)
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}
}

void COptionsState::Enter()
{
	CBaseMenu::Enter();

	//	Members
	m_uiMenuCount = OPTN_MAX;

	//	Imperfect..
	m_uiCurSelected = 0;
}

void COptionsState::Exit()
{
}

bool COptionsState::Input()
{
	//	NOT SURE
	CBaseMenu::Input();
	//	ABOVE?

	if(bMenuConfirm == true)
	{
		//	Set it back to false
		bMenuConfirm = false;
		//	Which choice is selected?
		switch(m_uiCurSelected)
		{
		case OPTN_VIDEO:
			{
				CVideoOptionsState::GetInstance()->SetTitleIndex(m_pnTitleIndex);
				CVideoOptionsState::GetInstance()->SetTitleScrollDir(m_pbTitleScrollDir);
				GAME->ChangeState(CVideoOptionsState::GetInstance());
				break;
			}
		case OPTN_AUDIO:
			{
				CAudioOptionsState::GetInstance()->SetTitleIndex(m_pnTitleIndex);
				CAudioOptionsState::GetInstance()->SetTitleScrollDir(m_pbTitleScrollDir);
				GAME->ChangeState(CAudioOptionsState::GetInstance());
				break;
			}
		case OPTN_BACK:
			{
				GAME->ChangeState(CMainMenuState::GetInstance());
				break;
			}
		}
	}
	return true;
}

void COptionsState::Update(float fElapsedTime)
{
	CBaseMenu::Update(fElapsedTime);
}

void COptionsState::Render()
{
	//	Draw the base menu's stuff .. NOT SURE
	CBaseMenu::Render();

	//	Draw this menu's stuff
	pFont->Write("Video Settings", 32, 12 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	pFont->Write("Audio Settings", 32, 13 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	pFont->Write("Back", 32, 14 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
}