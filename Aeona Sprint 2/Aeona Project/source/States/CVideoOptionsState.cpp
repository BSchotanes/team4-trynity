////////////////////////////////////////////////////////////////////////
//    File Name				:	"CVideoOptionsState.cpp"
//    Author Name			:	Phil Sullivan
//    Creation Date			:	02/13/12 - 6:52 PM
//    Purpose				:	Contains the CVideoOptionsState
////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include "../StdAfx.h"
#include "CVideoOptionsState.h"
#include "COptionsState.h"
#include "../Post Process/CPostProcess.h"

CVideoOptionsState* CVideoOptionsState::m_pInstance = NULL;

CVideoOptionsState::CVideoOptionsState()
{
}

CVideoOptionsState::~CVideoOptionsState()
{
}

CVideoOptionsState* CVideoOptionsState::GetInstance()
{
	if(m_pInstance == NULL)
	{
		m_pInstance = new CVideoOptionsState;
	}
	return m_pInstance;
}

void CVideoOptionsState::DeleteInstance()
{
	if(m_pInstance != NULL)
	{
		delete m_pInstance;
		m_pInstance = NULL;
	}
}

void CVideoOptionsState::Enter()
{
	CBaseMenu::Enter();

	//	Members
	m_uiMenuCount = VDEO_MAX;

	//	Imperfect..
	m_uiCurSelected = 0;
}

void CVideoOptionsState::Exit()
{
}

bool CVideoOptionsState::Input()
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
		case VDEO_FULLSCREEN:
			{
				GAME->SetIsWindowed( !GAME->GetIsWindowed() );
				CPostProcess::GetInstance()->ReleaseTexture();
				D3D->ChangeDisplayParam(GAME->GetScreenWidth(), GAME->GetScreenHeight(), GAME->GetIsWindowed());
				CPostProcess::GetInstance()->ReCreateTexture();
				break;
			}
		case VDEO_SHOWHUD:
			{
				GAME->SetShowHUD( !GAME->GetShowHUD() );
				break;
			}
		case VDEO_MINIMAP:
			{
				GAME->SetMapLocation( !GAME->GetMapLocation() );
				break;
			}
		case VDEO_BACK:
			{
				//	When we leave the state, save all the crap to the outputted options files
				GAME->OutputOptionsToFile();
				GAME->ChangeState(COptionsState::GetInstance());
				break;
			}
		}
	}
	return true;
}

void CVideoOptionsState::Update(float fElapsedTime)
{
	CBaseMenu::Update(fElapsedTime);
}

void CVideoOptionsState::Render()
{
	//	Draw the base menu's stuff
	CBaseMenu::Render();

	//	Draw this menu's stuff
	pFont->Write("FullScreen", 32, 12 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	if(GAME->GetIsWindowed() == false)
	{
		pFont->Write("Enabled", 256, 12 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	}
	else
	{
		pFont->Write("Disabled", 256, 12 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	}
	pFont->Write("HUD", 32, 13 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	if(GAME->GetShowHUD() == true)
	{
		pFont->Write("Enabled", 256, 13 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	}
	else
	{
		pFont->Write("Disabled", 256, 13 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	}
	pFont->Write("Map Location", 32, 14 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	if(GAME->GetMapLocation() == 0)
	{
		pFont->Write("Left side", 256, 14 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	}
	else if(GAME->GetMapLocation() == 1)
	{
		pFont->Write("Right side", 256, 14 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
	}
	pFont->Write("Back", 32, 15 * pFont->GetCharHeight(), D3DCOLOR_XRGB(255, 255, 255));
}