#ifndef C_SLIME_AI_STATE_H_
#define C_SLIME_AI_STATE_H_

#include "IBaseAIState.h"

class CSlimeAIState : public IBaseAIState
{
	// Trilogy for proper singleton
	CSlimeAIState(const CSlimeAIState&){}
	CSlimeAIState* operator=(const CSlimeAIState&){}
	~CSlimeAIState(void){}
	CSlimeAIState(void){}

	static CSlimeAIState* sm_pInstance;

	int m_sndSlimeBlurb;

	//	0 - GetWhacked
	//	1 - WhackedPause
	//	2 - PassiveWander =)
	//	3 - SquirmForward
	//	4 - SquirmPause
	//	5 - Lunge
	
public:
	static IBaseAIState* GetInstance(void);
	void Enter(CBaseCharacter* pCharacter);
	void Update(CBaseCharacter* pCharacter, float fElapsedTime);
	void Exit(CBaseCharacter* pCharacter);
	static void DeleteInstance(void);
};

#endif