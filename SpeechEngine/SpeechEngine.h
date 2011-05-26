#include <sapi.h>
#pragma comment(lib,"urlmon.lib")
#include <windows.h>




class SpeechEngine
{
private: int pitch,rate,volume;

public:
	void InitSE();
	SpeechEngine();
	SpeechEngine(int TextPitch,int TextRate,int TextVolume);
	bool SpeakText(char *text);
	char* GetStringError(DWORD error);
	void SetPitch(int TextPitch) { pitch=TextPitch; }
	void SetRate(int TextRate) { rate=TextRate; }
	void SetVolume(int TextVolume) { volume=TextVolume; }
	char *IntToChar(int i);
	int GetError();
	void GetErrorMB();
	~SpeechEngine();
};