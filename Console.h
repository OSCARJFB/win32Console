/*
		Writen by: Oscar Bergström
		https://github.com/OSCARJFB

		MIT License
		Copyright (c) 2024 Oscar Bergström
*/

#pragma once 

#include <iostream>
#include <Windows.h>

class Console
{
public:
	Console(BOOL bToogleMode);
	~Console();

public:
	void ClearScreen() const;
	CHAR ReadKey();
	void SetConsoleColor(WORD wColor = true);

public:	
	template <typename T>
	void Print(T tOutPut, SHORT nX, SHORT nY)
	{
		DWORD lpNumberofCharsWritten = 0;
		SetConsoleCursorPosition(m_hOutput, COORD{ nX, nY });
		std::cout << tOutPut;
	}

	template <typename T>
	void Print(T tOutPut, SHORT nX, SHORT nY, WORD wColor)
	{
		SetConsoleColor(wColor);
		DWORD lpNumberofCharsWritten = 0;
		SetConsoleCursorPosition(m_hOutput, COORD{ nX, nY });
		std::cout << tOutPut;
		SetConsoleColor(m_wBaseColor);
	}

private: 
	void SetHandlers();
	void SetBufferInfo();
	void SetMode(BOOL bToogleMode);

private:
	DWORD m_dMode = 0;
	HANDLE m_hInput = nullptr;
	HANDLE m_hOutput = nullptr;
	CONSOLE_SCREEN_BUFFER_INFO m_csbInfo;
	WORD m_wBaseColor = 0;
};
