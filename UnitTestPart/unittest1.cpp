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

		TEST_METHOD(test_addremove_valid_objects)
		{
			CloseGameBoard();
			InitGameBoard();
			Coord c;
			c.x = 0;
			c.y = 0;
			TileObject obj;
			obj = Player;
			Assert::IsTrue(AddObject(c, obj), (wchar_t*)"Failed to add object");
			Assert::IsTrue(RemoveObjectCoord(c), (wchar_t*)"Failed to add object");
		}

		TEST_METHOD(test_addremove_invalid_coord)
		{
			CloseGameBoard();
			InitGameBoard();
			Coord c;
			c.x = len + 1;
			c.y = wid + 1;
			TileObject obj;
			obj = Player;
			Assert::IsFalse(AddObject(c, obj), (wchar_t*)"Failed to add object");
			Assert::IsFalse(RemoveObjectCoord(c), (wchar_t*)"Failed to add object");
		}

	};
}