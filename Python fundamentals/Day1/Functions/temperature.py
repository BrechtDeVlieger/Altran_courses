import unittest

def Celsius_to_Fahrenheit(Celsius):
    if Celsius < -273.15:
        raise ValueError('Temperature cannot be lower than -273.15 degrees Celsius')
    return Celsius*9/5 + 32

def Celsius_to_Kelvin(Celsius):
    if Celsius < -273.15:
        raise ValueError('Temperature cannot be lower than -273.15 degrees Celsius')
    return Celsius + 273.15

def Fahrenheit_to_Celsius(fahrenheit):
    if fahrenheit < -459.67:
        raise ValueError('Temperature cannot be lower than -459.67 degrees Fahrenheit')
    return (fahrenheit - 32) * 5/9

def Fahrenheit_to_Kelvin(fahrenheit):
    if fahrenheit < -459.67:
        raise ValueError('Temperature cannot be lower than -459.67 degrees Fahrenheit')
    return(Celsius_to_Kelvin(Fahrenheit_to_Celsius(fahrenheit)))

def Kelvin_to_Celsius(kelvin):
    if kelvin < 0:
        raise ValueError('Temperature cannot be lower than 0 degrees Kelvin')
    return kelvin - 273.15

def Kelvin_to_fahrenheit(kelvin):
    if kelvin < 0:
        raise ValueError('Temperature cannot be lower than 0 degrees Kelvin')
    return Celsius_to_Fahrenheit(Kelvin_to_Celsius(kelvin))

