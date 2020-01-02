import unittest
from solution import TicTacToeBoard


class TestTicTacToe(unittest.TestCase):

    def setUp(self):
        self.board = TicTacToeBoard()

        # # column tests
    def test_left_column_with_x_win(self):
        self.board["A1"] = "X"
        self.board["B2"] = "O"
        self.board["A2"] = "X"
        self.board["B3"] = "O"
        self.board["A3"] = "X"

        self.assertEqual("X wins!", self.board.game_status())

    def test_middle_column_with_x_win(self):
        self.board["B1"] = "X"
        self.board["A1"] = "O"
        self.board["B2"] = "X"
        self.board["A2"] = "O"
        self.board["B3"] = "X"

        self.assertEqual("X wins!", self.board.game_status())

    def test_right_column_with_x_win(self):
        self.board["C1"] = "X"
        self.board["A1"] = "O"
        self.board["C2"] = "X"
        self.board["B2"] = "O"
        self.board["C3"] = "X"

        self.assertEqual("X wins!", self.board.game_status())

        # # row tests
    def test_low_row_with_x_win(self):
        self.board["A1"] = "X"
        self.board["A3"] = "O"
        self.board["B1"] = "X"
        self.board["B2"] = "O"
        self.board["C1"] = "X"

        self.assertEqual("X wins!", self.board.game_status())

    def test_middle_row_with_x_win(self):
        self.board["A2"] = "X"
        self.board["A1"] = "O"
        self.board["B2"] = "X"
        self.board["B3"] = "O"
        self.board["C2"] = "X"

        self.assertEqual("X wins!", self.board.game_status())

    def test_top_row_with_x_win(self):
        self.board["A3"] = "X"
        self.board["A2"] = "O"
        self.board["B3"] = "X"
        self.board["B2"] = "O"
        self.board["C3"] = "X"

        self.assertEqual("X wins!", self.board.game_status())

        # # diagonal tests
    def test_main_diagonal_with_x_win(self):
        self.board["A1"] = "X"
        self.board["A2"] = "O"
        self.board["B2"] = "X"
        self.board["B3"] = "O"
        self.board["C3"] = "X"

        self.assertEqual("X wins!", self.board.game_status())

    def test_main_diagonal_with_x_win(self):
        self.board["C1"] = "X"
        self.board["A2"] = "O"
        self.board["B2"] = "X"
        self.board["B3"] = "O"
        self.board["A3"] = "X"

        self.assertEqual("X wins!", self.board.game_status())

        # # column tests
    def test_left_column_with_o_win(self):
        self.board["A1"] = "O"
        self.board["B1"] = "X"
        self.board["A2"] = "O"
        self.board["B2"] = "X"
        self.board["A3"] = "O"

        self.assertEqual("O wins!", self.board.game_status())

    def test_middle_column_with_o_win(self):
        self.board["B1"] = "O"
        self.board["A1"] = "X"
        self.board["B2"] = "O"
        self.board["A2"] = "X"
        self.board["B3"] = "O"

        self.assertEqual("O wins!", self.board.game_status())

    def test_right_column_with_o_win(self):
        self.board["C1"] = "O"
        self.board["A1"] = "X"
        self.board["C2"] = "O"
        self.board["A3"] = "X"
        self.board["C3"] = "O"

        self.assertEqual("O wins!", self.board.game_status())

        # # row tests
    def test_low_row_with_o_win(self):
        self.board["A1"] = "O"
        self.board["B2"] = "X"
        self.board["B1"] = "O"
        self.board["C2"] = "X"
        self.board["C1"] = "O"

        self.assertEqual("O wins!", self.board.game_status())

    def test_middle_row_with_o_win(self):
        self.board["A2"] = "O"
        self.board["A1"] = "X"
        self.board["B2"] = "O"
        self.board["C3"] = "X"
        self.board["C2"] = "O"

        self.assertEqual("O wins!", self.board.game_status())

    def test_top_row_with_o_win(self):
        self.board["A3"] = "O"
        self.board["A1"] = "X"
        self.board["B3"] = "O"
        self.board["B2"] = "X"
        self.board["C3"] = "O"

        self.assertEqual("O wins!", self.board.game_status())

        # # diagonal tests
    def test_main_diagonal_with_o_win(self):
        self.board["A1"] = "O"
        self.board["A2"] = "X"
        self.board["B2"] = "O"
        self.board["B3"] = "X"
        self.board["C3"] = "O"

        self.assertEqual("O wins!", self.board.game_status())

    def test_main_diagonal_with_o_win(self):
        self.board["C1"] = "O"
        self.board["A2"] = "X"
        self.board["B2"] = "O"
        self.board["B3"] = "X"
        self.board["A3"] = "O"

        self.assertEqual("O wins!", self.board.game_status())

    def test_draw(self):
        self.board["B1"] = "O"
        self.board["A1"] = "X"
        self.board["A2"] = "O"
        self.board["B2"] = "X"
        self.board["C3"] = "O"
        self.board["C2"] = "X"
        self.board["A3"] = "O"
        self.board["B3"] = "X"
        self.board["C1"] = "O"

        self.assertEqual("Draw!", self.board.game_status())

    def test_game_in_progress(self):
        self.board["A1"] = "X"
        self.board["A2"] = "O"

        self.assertEqual("Game in progress.", self.board.game_status())

    # test __str__() method
    def test_print_empty_board(self):

        board_string = "\n  -------------\n\
3 |   |   |   |\n\
  -------------\n\
2 |   |   |   |\n\
  -------------\n\
1 |   |   |   |\n\
  -------------\n\
    A   B   C  \n"

        self.assertEqual(board_string, self.board.__str__())

    def test_print_full_board(self):

        self.board["B1"] = "O"
        self.board["A1"] = "X"
        self.board["A2"] = "O"
        self.board["B2"] = "X"
        self.board["C3"] = "O"
        self.board["C2"] = "X"
        self.board["A3"] = "O"
        self.board["B3"] = "X"
        self.board["C1"] = "O"

        board_string = "\n  -------------\n\
3 | O | X | O |\n\
  -------------\n\
2 | O | X | X |\n\
  -------------\n\
1 | X | O | O |\n\
  -------------\n\
    A   B   C  \n"

        self.assertEqual(board_string, self.board.__str__())


if __name__ == "__main__":
    unittest.main()