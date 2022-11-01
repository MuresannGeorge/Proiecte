import random
class Console:
    def __init__(self,service):
        self.service = service
        
    def print_board(self):
        print("BOARD")
        board = self.service.get_board()
        
        for line in board:
            print(" ".join(line))
    
    def read_hit(self):
        row = int(input("Row:"))
        collum = int(input("Collum:"))
        return row,collum
    
    def player_move(self,row,collum):
        self.service.player_move(row,collum)
        
    def computer_move(self,row,collum):
        self.service.computer_move(row,collum)
    
    def run(self):
        self.print_board()
        game = True
        turn = True
        
        while game == True:
            if turn == True:
                row,collum = self.read_hit()
                self.player_move(row,collum)
                if self.service.winner() == 1:
                    game = False
                    print("Bds")
                self.print_board()
                turn = not turn
            else:
                computer_row = random.randint(0,5)
                computer_collum = random.randint(0,5)
                self.computer_move(computer_row,computer_collum)
                self.print_board()
                turn = not turn
                
    