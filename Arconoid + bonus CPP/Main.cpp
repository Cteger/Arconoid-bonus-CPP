//#define __CRTDBG_MAP_ALLOC
//
//#include <crtdbg.h>
//#define DEBUG_NEW new(_NORMAL_BLOCK, __FILE__, __LINE__)
//#define new DEBUG_NEW
#include "game.h"

int main(int argc, char** argv)
{
	//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//_CrtSetBreakAlloc(192);
	//_CrtSetBreakAlloc(179);
	//_CrtSetBreakAlloc(181);
	//_CrtSetBreakAlloc(159);
	//_CrtSetBreakAlloc(158);
	SystemOpen(argc, argv);
	GameInitialize(1);
}