////////////////////////////////////////////////////////////////////////
//    File Name				:	"CSword.h"
//
//    Author Name			:	Bryan Schotanes
//    Creation Date			:	02/08/12 - 7:47 PM
//    Purpose				:	Contains the CSword
//
//    Last Updater Name		:   Bryan Schotanes
//    Last Update Date      :   
//    Last Update Notes     :   
//								
//								
////////////////////////////////////////////////////////////////////////

// Standard header protection
#ifndef CSWORD_H_
#define CSWORD_H_

#include "IBaseWeapon.h"
class CSword : public IBaseWeapon
{
private:
	int m_sndCharged;
public:
	~CSword(void);
	CSword();

	void Attack(void);
	void ChargedAttack(void);
	//void Render(void);
	void Render(PointD nPosition);
	void Render(PointD nPos,DWORD WHICHCOLORYOUWANTHIMTOGLOWBRO);
	void Update(float fElapsedTime);
	//bool CheckCollision(IBaseInterface* pObject);
	//void Render(void);
	unsigned int GetWeaponType(void) const { return TYPE_WEAPON_SWORD; }
	unsigned int GetType(void) const { return IBaseInterface::TYPE_WEAPON_SWORD; }
	//void SetWeaponRotation(float fWeaponRotation);
	RectD CSword::GetCollisionRect(void);
};

#endif