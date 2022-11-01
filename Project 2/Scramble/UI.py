from service import Service,ServiceError

class UIError(Exception):
    pass

class Console(object):
    """description of class"""
    def __init__(self):
        self._service = Service()

    def __startGame(self):
        self._service._read_random_sentence("input.txt")
        score = self._service._compute_score()
        self._service._shuffle_letters()

        print(self._service.getPrintableSentence())

        while score>0 and self._service._won() == False:
            print(self._service.getPrintableSentence())
            print("Score is "+str(score))
            arguments = input("Move:")
            if arguments == 'undo':
                try:
                    self._service._undo_last_swap()
                except ServiceError as se:
                    print(se)

            else:
                arguments = arguments.strip()
                arguments = arguments.split()
                if arguments[0] == 'swap':
                    arguments.pop(0)
                    if len(arguments) !=4:
                        print("4 Integers!")
                    try:
                        arguments[0] =int(arguments[0])
                        arguments[1] =int(arguments[1])
                        arguments[2] =int(arguments[2])
                        arguments[3] =int(arguments[3])
                        self._service._swap_letters(arguments[0], arguments[1], arguments[2], arguments[3] )
                        score -=1
                    except ValueError as ve:
                        print("Must have 4 integer Values")
                    except ServiceError as se:
                        print(se)
                else:
                    print("Invalid Command!")

        if score == 0:
            print("You lose")
        else:
            print("You win! Youtr score is " +str(score))
