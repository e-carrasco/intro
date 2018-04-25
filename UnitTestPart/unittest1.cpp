#include "stdafx.h"
#include "CppUnitTest.h"
#include "game_board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTestPart
{	
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(test_null_InitGameBoard)
		{

			CloseGameBoard();
			Assert test;
			test.IsTrue(InitGameBoard(), (wchar_t*)"Failed");
			CloseGameBoard();
		}

		TEST_METHOD(test_double_initialize_InitGameBoard)
		{
			CloseGameBoard();
			InitGameBoard();
			Assert::IsFalse(InitGameBoard(),(wchar_t*) "Failed test double initialize");
			CloseGameBoard();
		}

	};
}