class LedSquare
{
public:
	LedSquare(){}
	void init(int16_t start, bool brightnessAscending=true)
	{
		m_currentBrightness = start;
		m_brightnessAscending = brightnessAscending;
	}

	~LedSquare(){}
	int16_t m_currentBrightness;
	bool m_brightnessAscending;
	
};