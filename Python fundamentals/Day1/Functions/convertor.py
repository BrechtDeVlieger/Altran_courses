import temperature
import argparse

parser = argparse.ArgumentParser()
parser.add_argument('-c2f', '-CelsiusToFahrenheit', type=int, action="append",
                    help='Converts degrees Celsius to Fahrenheit', required=False)
parser.add_argument('-c2k', '-CelsiusToKelvin', type=int, action="append",
                    help='Converts degrees Celsius to Kelvin', required=False)
parser.add_argument('-f2c', '-FahrenheitToCelsius', type=int, action="append",
                    help='Converts degrees Fahrenheit to Celsius', required=False)
parser.add_argument('-f2k', '-FahrenheitToKelvin', type=int, action="append",
                    help='Converts degrees Fahrenheit to Fahrenheit', required=False)
parser.add_argument('-k2f', '-KelvinToFahrenheit', type=int, action="append",
                    help='Converts degrees Kelvin to Fahrenheit', required=False)
parser.add_argument('-k2c', '-KelvinToCelsius', type=int, action="append",
                    help='Converts degrees Kelvin to Celsius', required=False)

args = parser.parse_args()
if(args.c2f):
    for temp in args.c2f:
        print("{c}C = {f}f".format(c=temp, f=temperature.Celsius_to_Fahrenheit(temp)))
if(args.c2k):
    for temp in args.c2k:
        print("{c}C = {k}K".format(c=temp, k=temperature.Celsius_to_Kelvin(temp)))
if(args.f2c):
    for temp in args.f2c:
        print("{f}f = {c}C".format(f=temp, c=temperature.Fahrenheit_to_Celsius(temp)))
if(args.f2k):
    for temp in args.f2k:
        print("{f}f = {k}K".format(f=temp, k=temperature.Fahrenheit_to_Kelvin(temp)))
if(args.k2c):
    for temp in args.k2c:
        print("{k}K = {c}C".format(k=temp, c=temperature.Kelvin_to_Celsius(temp)))
if(args.k2f):
    for temp in args.k2f:
        print("{k}K = {f}f".format(k=temp, f=temperature.Celsius_to_Kelvin(temp)))
