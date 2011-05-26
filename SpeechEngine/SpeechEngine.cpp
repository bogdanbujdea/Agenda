#include "SpeechEngine.h"


WCHAR widechar[1024];
char tmp[1024],Pitch[20];

SpeechEngine::SpeechEngine()
{
	InitSE();
	pitch=20;
	rate=2;
	volume=90;
}

char* SpeechEngine::GetStringError(DWORD error)
{
	DWORD result;
	char *ErrorBuffer=(char*)malloc(1024);
	result = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,NULL,error,0,(LPSTR)ErrorBuffer,1024,NULL);
	if(result)
		return ErrorBuffer;
	return NULL;
}

SpeechEngine::SpeechEngine(int TextPitch,int TextRate,int TextVolume)
{
	InitSE();
	pitch=TextPitch;
	rate=TextRate;
	volume=TextVolume;
}

void SpeechEngine::InitSE()
{
	//ZeroMemory ( this, sizeof ( *this ) );
	CoInitialize ( NULL );
	ISpVoice * Voice = NULL;
	CoCreateInstance 
	( 
		CLSID_SpVoice,
		NULL,					
		CLSCTX_ALL,			
		IID_ISpVoice,			
		(void**)&Voice	
	);
}

char *SpeechEngine::IntToChar(int i)
{
	char buffer[100];
	_itoa_s(i,buffer,10);
	return &buffer[0];
}

bool SpeechEngine::SpeakText(char *text)
{

	ISpVoice * Voice = NULL;
    if (FAILED(::CoInitialize(NULL)))
	{
		MessageBox(0,"Could not initialize ISpVoice",0,0);
		return FALSE;
	}
	strcpy(tmp,"<pitch middle = '");
	_itoa_s(pitch,Pitch,10);
	strcat(tmp,Pitch);
	strcat(tmp,"'/>");
	strcat(tmp,text);
	//strcpy(text,tmp);
    HRESULT hr = CoCreateInstance(CLSID_SpVoice, NULL, CLSCTX_ALL, IID_ISpVoice, (void **)&Voice);
    if( SUCCEEDED( hr ) )
    {
		MultiByteToWideChar(CP_ACP, 0, tmp, -1, widechar,MAX_PATH );
		Voice->SetRate(rate);
		Voice->SetVolume(volume);
        hr = Voice->Speak((LPCWSTR)widechar, SPF_IS_XML, NULL);
        Voice->Release();
        Voice = NULL;
	}
	return TRUE;
}	

SpeechEngine::~SpeechEngine()
{
	 ::CoUninitialize();
}

int SpeechEngine::GetError()
{
	DWORD error=GetLastError();
	char *buffer=new char[1024];
	FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM,NULL,error,0,buffer,1024,NULL);
	SpeakText(buffer);
	delete[] buffer;
	return error;
}

void SpeechEngine::GetErrorMB()
{
	MessageBox(0,IntToChar(GetLastError()),0,0);
}