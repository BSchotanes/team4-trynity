#ifndef LIGHTENGINE_H_
#define LIGHTENGINE_H_

class LightEngine
{
private:			
	float m_fAmbientAlpha;
	float m_fAmbientRed;
	float m_fAmbientGeen;
	float m_fAmbientBlue;
	
	float m_fPointAlpha;
	float m_fPointRed;
	float m_fPointGeen;
	float m_fPointBlue;

	float m_fPlayerPosX;
	float m_fPlayerPosY;

	LightEngine(void);
	LightEngine(const LightEngine&){}
	LightEngine& operator=(const LightEngine&){}
	~LightEngine(void);

public:
	static LightEngine* GetInstance(void);

	void SetAmbientAlpha( float fAmbientAlpha )	{ m_fAmbientAlpha = fAmbientAlpha; }
	void SetAmbientRed( float fAmbientRed )		{ m_fAmbientRed = fAmbientRed; }
	void SetAmbientGreen( float fAmbientGreen )	{ m_fAmbientGeen = fAmbientGreen; }
	void SetAmbientBlue(float fAmbientBlue )	{ m_fAmbientBlue = fAmbientBlue; }

	void SetPointAlpha( float fPointAlpha )		{ m_fPointAlpha = fPointAlpha; }
	void SetPointRed( float fPointRed )			{ m_fPointRed = fPointRed; }
	void SetPointGreen( float fPointGreen )		{ m_fPointGeen = fPointGreen; }
	void SetPointBlue( float fPointBlue )		{ m_fPointBlue = fPointBlue; }

	void SetPlayerPosX( float fPlayerPosX )		{ m_fPlayerPosX = fPlayerPosX; }
	void SetPlayerPosY( float fPlayerPosY )		{ m_fPlayerPosY = fPlayerPosY; }

	float GetAmbientAlpha(void)	{ return m_fAmbientAlpha; }
	float GetAmbientRed(void)	{ return m_fAmbientRed; }
	float GetAmbientGreen(void)	{ return m_fAmbientGeen; }
	float GetAmbientBlue(void)	{ return m_fAmbientBlue; }

	float GetPointAlpha(void)	{ return m_fPointAlpha; }
	float GetPointRed(void)		{ return m_fPointRed; }
	float GetPointGreen(void)	{ return m_fPointGeen; }
	float GetPointBlue(void)	{ return m_fPointBlue; }

	float GetPlayerPosX(void)	{ return m_fPlayerPosX; }
	float GetPlayerPosY(void)	{ return m_fPlayerPosY; }

	void Initialize( void );
	void Update( void );
	void Input( void );
	void ShutDown( void );

	void SetPlayerPos( float fPosX, float fPosY );
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
