import unittest

def is_palindrome(sentence):
    sentence = sentence.lower()
    return True if sentence == sentence[::-1] else False

class Test_is_palindrome(unittest.TestCase):
    def test_is_palindrome(self):
        self.assertTrue(is_palindrome("ABBA"), "ABBA should be a palindrome")
        self.assertTrue(is_palindrome("SOS"), "SOS should be a palindrome")
        self.assertTrue(is_palindrome("SOs"), "Palindrome algorithm should be case-insensitive")
        self.assertFalse(is_palindrome("Brecht"), "Brecht is not a palindrome")
        self.assertTrue(is_palindrome("Satanoscillatemymetallicsonatas"),
            "This shit is a palindrome!")

unittest.main()
