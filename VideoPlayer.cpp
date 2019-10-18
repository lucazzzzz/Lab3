#include "VideoPlayer.h"

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}


Videoplayer::Videoplayer(std::string filename)
{
	// Initialize the COM library.
	HRESULT hr = CoInitialize(NULL);
	if (FAILED(hr))
	{
		printf("ERROR - Could not initialize COM library");
		return;
	}

	// Create the filter graph manager and query for interfaces.
	hr = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
		IID_IGraphBuilder, (void **)&pGraph);
	if (FAILED(hr))
	{
		printf("ERROR - Could not create the Filter Graph Manager.");
		return;
	}

	hr = pGraph->QueryInterface(IID_IMediaControl, (void **)&pControl);
	hr = pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);
	hr = pGraph->QueryInterface(IID_IMediaSeeking, (void **)&pSeek);

	// Build the graph. IMPORTANT: Change this string to a file on your system.
	
	std::wstring stemp = s2ws(filename);
	LPCWSTR bb = stemp.c_str();

	hr = pGraph->RenderFile(bb, NULL);

	if (FAILED(hr))
	{
		printf("ERROR - Could not render file");

	}
	Run();
}

Videoplayer::~Videoplayer()
{
}

void Videoplayer::Run()
{
	hr = pControl->Run();
}

void Videoplayer::End()
{
	if (SUCCEEDED(hr))
	{
		// Wait for completion.
		long evCode;
		pEvent->WaitForCompletion(100, &evCode);

		// Note: Do not use INFINITE in a real application, because it
		// can block indefinitely.
	}

	pControl->Release();
	pEvent->Release();
	pGraph->Release();
	CoUninitialize();
}

void Videoplayer::Pause()
{
	hr = pControl->Pause();
}

void Videoplayer::FF()
{
	hr = pSeek->SetRate(2.0);
}
void Videoplayer::NF() {
	hr = pSeek->SetRate(1.0);
}

void Videoplayer::RetourArriere()
{
	hr = pSeek->IsFormatSupported(&TIME_FORMAT_FRAME);
	if (hr == S_OK)
	{
		hr = pSeek->SetTimeFormat(&TIME_FORMAT_FRAME);
		if (SUCCEEDED(hr))
		{
			// Seek to frame number 0.
			LONGLONG rtNow = 0;
			hr = pSeek->SetPositions(
				&rtNow, AM_SEEKING_AbsolutePositioning,
				0, AM_SEEKING_NoPositioning);
		}
	}
}
