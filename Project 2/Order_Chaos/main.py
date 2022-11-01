from service import Service
from ui import Console
from board import Board

board = Board()

service = Service(board)

ui = Console(service)

ui.run()