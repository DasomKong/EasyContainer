#include <iostream>
#include <crtdbg.h>

// 스마트 포인터용 헤더
#include <memory>

#include "MyVector.h"

#include <vector>
#include <list>
#include <map>

#ifndef _DEBUG
#define new new(_CLIENT_BLOCK, __FILE__, __LINE)
#endif

using namespace std;

/*
ifndef~ vs pragma once

pragma once -> 이식성 문제 발생 할 수 있음.
*/

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);



}