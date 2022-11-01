class Service:
    def __init__(self,board):
        self.board = board
    
    def get_board(self):
        return self.board.get_board()
    
    def player_move(self,row,collum):
        self.board.player_move(row,collum)
        
    def computer_move(self,row,collum):
        self.board.computer_move(row,collum)
    
    def winner(self):
        return self.board.winner()