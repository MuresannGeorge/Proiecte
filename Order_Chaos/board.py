class Board:
    def __init__(self):
        self.board = [['-']*6,['-']*6,['-']*6,['-']*6,['-']*6,['-']*6,]
        self.rows = 6
        self.collum = 6
        
    def get_board(self):
        return self.board
    
    def player_move(self,row,collum):
        board = self.board
        
        board[row][collum] = 'X'
        
    def computer_move(self,row,collum):
        board = self.board
        
        board[row][collum] = '0'
    
    def winner(self):
        board = self.board
        
        for row in range(self.rows):
            for collum in range(self.collum):
                if(board[row][collum] == 'X' and board[row][collum+1]=='X' and board[row][collum+2]=='X' and board[row][collum+3]=='X' and board[row][collum+4]=='X'):
                    return 1
                if(board[row][collum] == '0' and board[row][collum+1]=='0' and board[row][collum+2]=='0' and board[row][collum+3]=='0' and board[row][collum+4]=='0'):
                    return -1
    
    
    
        
        
    