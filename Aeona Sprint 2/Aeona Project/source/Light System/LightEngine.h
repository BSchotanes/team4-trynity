#ifndef LIGHTENGINE_H_
#define LIGHTENGINE_H_

class LightEngine
{
private:		
	// AMBIENT LIGHT
	float m_fAmbientAlpha;
	float m_fAmbientRed;
	float m_fAmbientGeen;
	float m_fAmbientBlue;
	
	// PLAYER POINT LIGHT
	bool  m_bPlayerPointLight;
	float m_fPlayerPointAlpha;
	float m_fPlayerPointRed;
	float m_fPlayerPointGeen;
	float m_fPlayerPointBlue;
	float m_fPlayerPointPosX;
	float m_fPlayerPointPosY;

	// ITEM 1 POINT LIGHT
	bool  m_bItem1PointLight;
	float m_fItem1PointAlpha;
	float m_fItem1PointRed;
	float m_fItem1PointGeen;
	float m_fItem1PointBlue;
	float m_fItem1PointPosX;
	float m_fItem1PointPosY;

	// ITEM 2 POINT LIGHT
	bool  m_bItem2PointLight;
	float m_fItem2PointAlpha;
	float m_fItem2PointRed;
	float m_fItem2PointGeen;
	float m_fItem2PointBlue;
	float m_fItem2PointPosX;
	float m_fItem2PointPosY;

	// ITEM 3 POINT LIGHT
	bool  m_bItem3PointLight;
	float m_fItem3PointAlpha;
	float m_fItem3PointRed;
	float m_fItem3PointGeen;
	float m_fItem3PointBlue;
	float m_fItem3PointPosX;
	float m_fItem3PointPosY;

	// ITEM 4 POINT LIGHT
	bool  m_bItem4PointLight;
	float m_fItem4PointAlpha;
	float m_fItem4PointRed;
	float m_fItem4PointGeen;
	float m_fItem4PointBlue;
	float m_fItem4PointPosX;
	float m_fItem4PointPosY;

	LightEngine(void);
	LightEngine(const LightEngine&){}
	LightEngine& operator=(const LightEngine&){}
	~LightEngine(void);

public:
	static LightEngine* GetInstance(void);

	//AMBIENT LIGHT
	void SetAmbientAlpha( float fAmbientAlpha )		{ m_fAmbientAlpha = fAmbientAlpha; }
	void SetAmbientRed( float fAmbientRed )			{ m_fAmbientRed = fAmbientRed; }
	void SetAmbientGreen( float fAmbientGreen )		{ m_fAmbientGeen = fAmbientGreen; }
	void SetAmbientBlue(float fAmbientBlue )		{ m_fAmbientBlue = fAmbientBlue; }
	float GetAmbientAlpha(void)						{ return m_fAmbientAlpha; }
	float GetAmbientRed(void)						{ return m_fAmbientRed; }
	float GetAmbientGreen(void)						{ return m_fAmbientGeen; }
	float GetAmbientBlue(void)						{ return m_fAmbientBlue; }

	//PLAYER POINT LIGHT
	void SetPlayerPointLight( bool bPlayerPoint)	{ m_bPlayerPointLight = bPlayerPoint; }
	void SetPlayerPointAlpha( float fPointAlpha )	{ m_fPlayerPointAlpha = fPointAlpha; }
	void SetPlayerPointRed( float fPointRed )		{ m_fPlayerPointRed = fPointRed; }
	void SetPlayerPointGreen( float fPointGreen )	{ m_fPlayerPointGeen = fPointGreen; }
	void SetPlayerPointBlue( float fPointBlue )		{ m_fPlayerPointBlue = fPointBlue; }
	void SetPlayerPointPosX( float fPlayerPosX )	{ m_fPlayerPointPosX = fPlayerPosX; }
	void SetPlayerPointPosY( float fPlayerPosY )	{ m_fPlayerPointPosY = fPlayerPosY; }
	bool  GetPlayerPointLight(void)					{ return m_bPlayerPointLight; }
	float GetPlayerPointAlpha(void)					{ return m_fPlayerPointAlpha; }
	float GetPlayerPointRed(void)					{ return m_fPlayerPointRed; }
	float GetPlayerPointGreen(void)					{ return m_fPlayerPointGeen; }
	float GetPlayerPointBlue(void)					{ return m_fPlayerPointBlue; }
	float GetPlayerPointPosX(void)					{ return m_fPlayerPointPosX; }
	float GetPlayerPointPosY(void)					{ return m_fPlayerPointPosY; }

	//ITEM1 POINT LIGHT
	void SetItem1PointLight( bool bItem1Point)		{ m_bItem1PointLight = bItem1Point; }
	void SetItem1PointAlpha( float fPointAlpha )	{ m_fItem1PointAlpha = fPointAlpha; }
	void SetItem1PointRed( float fPointRed )		{ m_fItem1PointRed = fPointRed; }
	void SetItem1PointGreen( float fPointGreen )	{ m_fItem1PointGeen = fPointGreen; }
	void SetItem1PointBlue( float fPointBlue )		{ m_fItem1PointBlue = fPointBlue; }
	void SetItem1PointPosX( float fItem1PosX )		{ m_fItem1PointPosX = fItem1PosX; }
	void SetItem1PointPosY( float fItem1PosY )		{ m_fItem1PointPosY = fItem1PosY; }
	bool  GetItem1PointLight(void)					{ return m_bItem1PointLight; }
	float GetItem1PointAlpha(void)					{ return m_fItem1PointAlpha; }
	float GetItem1PointRed(void)					{ return m_fItem1PointRed; }
	float GetItem1PointGreen(void)					{ return m_fItem1PointGeen; }
	float GetItem1PointBlue(void)					{ return m_fItem1PointBlue; }
	float GetItem1PointPosX(void)					{ return m_fItem1PointPosX; }
	float GetItem1PointPosY(void)					{ return m_fItem1PointPosY; }

	//ITEM2 POINT LIGHT
	void SetItem2PointLight( bool bItem2Point)		{ m_bItem2PointLight = bItem2Point; }
	void SetItem2PointAlpha( float fPointAlpha )	{ m_fItem2PointAlpha = fPointAlpha; }
	void SetItem2PointRed( float fPointRed )		{ m_fItem2PointRed = fPointRed; }
	void SetItem2PointGreen( float fPointGreen )	{ m_fItem2PointGeen = fPointGreen; }
	void SetItem2PointBlue( float fPointBlue )		{ m_fItem2PointBlue = fPointBlue; }
	void SetItem2PointPosX( float fItem2PosX )		{ m_fItem2PointPosX = fItem2PosX; }
	void SetItem2PointPosY( float fItem2PosY )		{ m_fItem2PointPosY = fItem2PosY; }
	bool  GetItem2PointLight(void)					{ return m_bItem2PointLight; }
	float GetItem2PointAlpha(void)					{ return m_fItem2PointAlpha; }
	float GetItem2PointRed(void)					{ return m_fItem2PointRed; }
	float GetItem2PointGreen(void)					{ return m_fItem2PointGeen; }
	float GetItem2PointBlue(void)					{ return m_fItem2PointBlue; }
	float GetItem2PointPosX(void)					{ return m_fItem2PointPosX; }
	float GetItem2PointPosY(void)					{ return m_fItem2PointPosY; }

	//ITEM3 POINT LIGHT
	void SetItem3PointLight( bool bItem3Point)		{ m_bItem3PointLight = bItem3Point; }
	void SetItem3PointAlpha( float fPointAlpha )	{ m_fItem3PointAlpha = fPointAlpha; }
	void SetItem3PointRed( float fPointRed )		{ m_fItem3PointRed = fPointRed; }
	void SetItem3PointGreen( float fPointGreen )	{ m_fItem3PointGeen = fPointGreen; }
	void SetItem3PointBlue( float fPointBlue )		{ m_fItem3PointBlue = fPointBlue; }
	void SetItem3PointPosX( float fItem3PosX )		{ m_fItem3PointPosX = fItem3PosX; }
	void SetItem3PointPosY( float fItem3PosY )		{ m_fItem3PointPosY = fItem3PosY; }
	bool  GetItem3PointLight(void)					{ return m_bItem3PointLight; }
	float GetItem3PointAlpha(void)					{ return m_fItem3PointAlpha; }
	float GetItem3PointRed(void)					{ return m_fItem3PointRed; }
	float GetItem3PointGreen(void)					{ return m_fItem3PointGeen; }
	float GetItem3PointBlue(void)					{ return m_fItem3PointBlue; }
	float GetItem3PointPosX(void)					{ return m_fItem3PointPosX; }
	float GetItem3PointPosY(void)					{ return m_fItem3PointPosY; }

	//ITEM4 POINT LIGHT
	void SetItem4PointLight( bool bItem4Point)		{ m_bItem4PointLight = bItem4Point; }
	void SetItem4PointAlpha( float fPointAlpha )	{ m_fItem4PointAlpha = fPointAlpha; }
	void SetItem4PointRed( float fPointRed )		{ m_fItem4PointRed = fPointRed; }
	void SetItem4PointGreen( float fPointGreen )	{ m_fItem4PointGeen = fPointGreen; }
	void SetItem4PointBlue( float fPointBlue )		{ m_fItem4PointBlue = fPointBlue; }
	void SetItem4PointPosX( float fItem4PosX )		{ m_fItem4PointPosX = fItem4PosX; }
	void SetItem4PointPosY( float fItem4PosY )		{ m_fItem4PointPosY = fItem4PosY; }
	bool  GetItem4PointLight(void)					{ return m_bItem4PointLight; }
	float GetItem4PointAlpha(void)					{ return m_fItem4PointAlpha; }
	float GetItem4PointRed(void)					{ return m_fItem4PointRed; }
	float GetItem4PointGreen(void)					{ return m_fItem4PointGeen; }
	float GetItem4PointBlue(void)					{ return m_fItem4PointBlue; }
	float GetItem4PointPosX(void)					{ return m_fItem4PointPosX; }
	float GetItem4PointPosY(void)					{ return m_fItem4PointPosY; }

	void Initialize( void );
	void Update( void );
	void Input( void );
	void ShutDown( void );

	void SetPlayerPointPos( float fPosX, float fPosY );
	void SetItem1PointPos( float fPosX, float fPosY );
	void SetItem2PointPos( float fPosX, float fPosY );
	void SetItem3PointPos( float fPosX, float fPosY );
	void SetItem4PointPos( float fPosX, float fPosY );

	void Morning( void );
	void Day( void );
	void Evening( void );
	void Night( void );

	void Rain( void );
	void Snow( void );
	void Leaves( void );
	void Sand( void );
	void Ember( void );
	void FireFlies( void );
};

#endif
