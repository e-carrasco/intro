#include "stdafx.h"
#include "CppUnitTest.h"
#include "game_board.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTestPart
{	
	TEST_CLASS(UnitTest1)
	{
	public:

		void fillBoard(game_board *to_fill)
		{
			for (int l = 0; l < len; l++) {
				for (int w = 0; w < wid; w++) {
					to_fill->gb[l][w].obj = (TileObject)(rand() % Item);
				}
			}
		}
		
		TEST_METHOD(test_null_InitGameBoard)
		{

			CloseGameBoard();
			Assert::IsTrue(InitGameBoard(), (wchar_t*)"Failed");
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
			CloseGameBoard();
		}

		TEST_METHOD(test_addremove_edge_case_objects)
		{
			CloseGameBoard();
			InitGameBoard();
			Coord c;
			c.x = 0;
			c.y = 0;
			TileObject obj;
			obj = Empty;
			Assert::IsTrue(AddObject(c, obj), (wchar_t*)"Failed to add object");
			Assert::IsTrue(RemoveObjectCoord(c), (wchar_t*)"Failed to add object");
			obj = Item;
			Assert::IsTrue(AddObject(c, obj), (wchar_t*)"Failed to add object");
			Assert::IsTrue(RemoveObjectCoord(c), (wchar_t*)"Failed to add object");
			CloseGameBoard();
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
			CloseGameBoard();
		}

		TEST_METHOD(test_addremove_invalid_tile_object)
		{
			CloseGameBoard();
			InitGameBoard();
			Coord c;
			c.x = 0;
			c.y = 0;
			TileObject obj = (TileObject)120;
			Assert::IsFalse(AddObject(c, obj), (wchar_t*)"Failed to add object");
			obj = (TileObject)-1;
			Assert::IsFalse(AddObject(c, obj), (wchar_t*)"Failed to add object");
			CloseGameBoard();
		}

		TEST_METHOD(test_import_valid_board)
		{
			CloseGameBoard();
			InitGameBoard();
			game_board test;
			fillBoard(&test);
			Assert::IsTrue(ImportGameBoard(&test), (wchar_t*)"Failed to import board");
			CloseGameBoard();
		}

		TEST_METHOD(test_import_invalid_tileset)
		{
			CloseGameBoard();
			InitGameBoard();
			game_board test;
			fillBoard(&test);
			test.gb[0][0].obj = (TileObject)0x7f;
			Assert::IsFalse(ImportGameBoard(&test), (wchar_t*)"Failed to import board");
			test.gb[0][0].obj = (TileObject)-1;
			Assert::IsFalse(ImportGameBoard(&test), (wchar_t*)"Failed to import board");
			CloseGameBoard();
		}

	};
}