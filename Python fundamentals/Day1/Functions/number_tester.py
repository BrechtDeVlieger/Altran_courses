import unittest

def is_prime(number):
    if(number <= 0):
        return False
    for i in range(2,number//2+1):
        if number%i == 0:
            return False
    return True

def is_Armstrong(number):
    pass
    string = str(number)
    sum = 0;
    for char in string:
        if char == '-':
            number*= -1
        else :
            sum += int(char)**3
    return True if sum == number else False

def is_perfect_number(number):
    if number <= 1:
        return False
    sum = 0;
    for i in range(1, number):
        if number%i == 0:
            sum += i
    return True if sum == number else False

class Test_number_operations(unittest.TestCase):
    def test_is_prime(self):
        self.assertFalse(is_prime(0), "0 is no prime number")
        self.assertTrue(is_prime(1))
        self.assertTrue(is_prime(2))
        self.assertTrue(is_prime(3))
        self.assertFalse(is_prime(4))
        self.assertTrue(is_prime(83))
        self.assertFalse(is_prime(-1))
    
    def test_is_Armstrong(self):
        self.assertTrue(is_Armstrong(153))
        self.assertTrue(is_Armstrong(370))
        self.assertTrue(is_Armstrong(1))
        self.assertFalse(is_Armstrong(2))
        self.assertTrue(is_Armstrong(-1))
        self.assertFalse(is_Armstrong(5))

    def test_is_perfect_number(self):
        self.assertTrue(is_perfect_number(6))
        self.assertTrue(is_perfect_number(28))
        self.assertFalse(is_perfect_number(1))
        self.assertFalse(is_perfect_number(0))
        self.assertFalse(is_perfect_number(-1))
        self.assertFalse(is_perfect_number(3))
        self.assertFalse(is_perfect_number(22))

unittest.main() 
