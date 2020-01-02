class InvalidMove(Exception):
    pass
class InvalidValue(Exception):
    pass
class InvalidKey(Exception):
    pass
class NotYourTurn(Exception):
    pass


class TicTacToeBoard(dict):
    last_turn = " "

    def __init__(self):
        self.TicTacToeBoard = {"A1":" ", "A2":" ", "A3":" ", "B1":" ", "B2":" ", "B3":" ", "C1":" ", "C2":" ", "C3":" "}

    def __getitem__(self, key):
        return self.TicTacToeBoard[key]
    
    def __setitem__(self, key, value):
        key_counter = 0

        keys = list(self.TicTacToeBoard.keys())
        for i in range(9):
            if keys[i] != key:
                key_counter += 1

        if key_counter > 8:
            raise InvalidKey

        if value != "X" and value != "O":
            raise InvalidValue

        if self.TicTacToeBoard[key] != " ":
            raise InvalidMove

        if self.last_turn == value:
            raise NotYourTurn
        
        self.last_turn = value
        self.TicTacToeBoard[key] = value

    def game_status(self):
        moves = list(self.TicTacToeBoard.values())
        check_for_draw = 0
        check_for_winner = 0

        for i in range (9):
            if i == 0 and moves[i] == moves[i+1] and moves[i] == moves[i+2] and moves[i] != " ":
                return "{} wins!".format(self.TicTacToeBoard["A1"])
                check_for_winner += 1
                check_for_draw += 1

            elif i == 3 and moves[i] == moves[i+1] and moves[i] == moves[i+2] and moves[i] != " ":
                return "{} wins!".format(self.TicTacToeBoard["B1"])
                check_for_winner += 1
                check_for_draw += 1
            
            elif i == 6 and moves[i] == moves[i+1] and moves[i] == moves[i+2] and moves[i] != " ":
                return "{} wins!".format(self.TicTacToeBoard["C1"])
                check_for_winner += 1
                check_for_draw += 1

            elif i == 0 and moves[i] == moves[i+3] and moves[i] == moves[i+6] and moves[i] != " ":
                return "{} wins!".format(self.TicTacToeBoard["A1"])
                check_for_winner += 1
                check_for_draw += 1

            elif i == 1 and moves[i] == moves[i+3] and moves[i] == moves[i+6] and moves[i] != " ":
                return "{} wins!".format(self.TicTacToeBoard["A2"])
                check_for_winner += 1
                check_for_draw += 1

            elif i == 2 and moves[i] == moves[i+3] and moves[i] == moves[i+6] and moves[i] != " ":
                return "{} wins!".format(self.TicTacToeBoard["A3"])
                check_for_winner += 1
                check_for_draw += 1

            elif i == 0 and moves[i] == moves[i+4] and moves[i] == moves[i+8] and moves[i] != " ":
                return "{} wins!".format(self.TicTacToeBoard["A1"])
                check_for_winner += 1
                check_for_draw += 1

            elif i == 2 and moves[i] == moves[i+2] and moves[i] == moves[i+2] and moves[i] != " ":
                return "{} wins!".format(self.TicTacToeBoard["A3"])
                check_for_winner += 1
                check_for_draw += 1

        if check_for_winner == 0:
            for i in range(9):
                if moves[i] == " ":
                    return "Game in progress."
                    check_for_draw += 1
                    break

        if check_for_draw == 0 :
            return "Draw!"

    def __str__(self):
        return '\n  -------------\n' +\
            '3 | {} | {} | {} |\n'.format(self.TicTacToeBoard["A3"], self.TicTacToeBoard["B3"], self.TicTacToeBoard["C3"]) +\
            '  -------------\n' +\
            '2 | {} | {} | {} |\n'.format(self.TicTacToeBoard["A2"], self.TicTacToeBoard["B2"], self.TicTacToeBoard["C2"]) +\
            '  -------------\n' +\
            '1 | {} | {} | {} |\n'.format(self.TicTacToeBoard["A1"], self.TicTacToeBoard["B1"], self.TicTacToeBoard["C1"]) +\
            '  -------------\n' +\
            '    A   B   C  \n'