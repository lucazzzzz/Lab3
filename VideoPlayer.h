#pragma once
#include <dshow.h>
#include <conio.h>
#include <string>
class Videoplayer
{
	IGraphBuilder *pGraph = NULL;
	IMediaControl *pControl = NULL;
	IMediaEvent   *pEvent = NULL;
	IMediaSeeking	*pSeek = NULL;
	HRESULT hr;
public:
	Videoplayer(std::string filename);
	~Videoplayer();
	void Run();
	void End();
	void Pause();
	void FF();
	void NF();
	void RetourArriere();
};