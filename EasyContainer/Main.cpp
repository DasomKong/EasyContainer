#include <iostream>
#include <crtdbg.h>

// ����Ʈ �����Ϳ� ���
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

pragma once -> �̽ļ� ���� �߻� �� �� ����.
*/

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);



}