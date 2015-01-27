class LedSquare
{
public:
	LedSquare(){}
	void init(int16_t start)
	{
		m_currentBrightness = start;
		m_brightnessAscending = true;
	}

	~LedSquare(){}
	int16_t m_currentBrightness;
	bool m_brightnessAscending;
	
};