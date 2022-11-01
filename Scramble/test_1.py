import unittest
from service import Service,ServiceError
from UI import Console,UIError

class Test_test_1(unittest.TestCase):

    def test_service_read_fromFile_ok(self):
        service =Service()
        service ._read_random_sentence("testInput.txt")
        assert service._sentence == [['B','i','g']]

    def test_service_won_True(self):
        service =Service()
        service ._read_random_sentence("testInput.txt")
        assert service._won()

    def test_service_swapLetters_ok(self):
        service =Service()
        service ._sentence = [['m','o','n','n','e','y'],['o','k','a']]
        service._swap_letters(0,3, 1, 1)
        assert service._sentence == [['m','o','n','k','e','y'],['o','n','a']]

    def test_undo_ok(self):
        service =Service()
        service ._sentence = [['m','o','n','n','e','y'],['o','k','a']]
        service._swap_letters(0,3, 1, 1)
        service._undo_last_swap()
        assert service._sentence == [['m','o','n','n','e','y'],['o','k','a']]

    def test_undo_Error(self):
        service =Service()
        service ._sentence = [['m','o','n','n','e','y'],['o','k','a']]
        service._swap_letters(0,3, 1, 1)
        service._undo_last_swap()
        self.assertRaises(ServiceError,service._undo_last_swap)
         

if __name__ == '__main__':
    unittest.main()
