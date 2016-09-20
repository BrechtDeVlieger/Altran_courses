import unittest
import temperature as temp

class Test_temperature_conversion(unittest.TestCase):
    def test_C2F(self):
        self.assertAlmostEqual(temp.Celsius_to_Fahrenheit(25), 77)
        self.assertNotAlmostEqual(temp.Celsius_to_Fahrenheit(77),25)
        self.assertRaises(ValueError, temp.Celsius_to_Fahrenheit, -300)

    def test_C2K(self):
        self.assertAlmostEqual(temp.Celsius_to_Kelvin(25), 298.15)
        self.assertNotAlmostEqual(temp.Celsius_to_Kelvin(298.15),25)
        self.assertRaises(ValueError, temp.Celsius_to_Kelvin, -300)

    def test_F2C(self):
        self.assertAlmostEqual(temp.Fahrenheit_to_Celsius(25), -3.88888889)
        self.assertNotAlmostEqual(temp.Fahrenheit_to_Celsius(-3.88888889),25)
        self.assertRaises(ValueError, temp.Fahrenheit_to_Celsius, -460)

    def test_F2K(self):
        self.assertAlmostEqual(temp.Fahrenheit_to_Kelvin(25), 269.261111,4)
        self.assertNotAlmostEqual(temp.Fahrenheit_to_Kelvin(269.261111),25)
        self.assertRaises(ValueError, temp.Fahrenheit_to_Kelvin, -460)

    def test_K2C(self):
        self.assertAlmostEqual(temp.Kelvin_to_Celsius(298.15), 25)
        self.assertNotAlmostEqual(temp.Kelvin_to_Celsius(25), 298.15)
        self.assertRaises(ValueError, temp.Kelvin_to_Celsius, -1)

    def test_K2F(self):
        self.assertAlmostEqual(temp.Kelvin_to_fahrenheit(25), -414.67)
        self.assertNotAlmostEqual(temp.Kelvin_to_fahrenheit(0),25)
        self.assertRaises(ValueError, temp.Kelvin_to_fahrenheit, -1)

unittest.main()
