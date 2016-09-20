import sys
import importlib
import inspect

if(len(sys.argv) != 2):
    raise AssertionError("Pass a python script as argument")

filename = sys.argv[1]
modulename = filename[0:-3]

if(filename[-3:] != '.py'):
    raise AssertionError("The script should have a .py extension")

output_name = "test_"+sys.argv[1]

mod_to_test = importlib.import_module(modulename)
function_list = inspect.getmembers(mod_to_test, inspect.isfunction)

print(function_list[0][0])

with open(output_name, 'w') as output:
    output.write("import {modulename}\n".format(modulename=modulename))
    output.write("import unittest\n\n")
    output.write("class Test_{modulename}(unittest.TestCase):\n".format(modulename=modulename))
    for function in function_list:
        output.write("\tdef test_{function}(self):\n".format(function=function[0]))
        output.write("\t\tself.assertTrue(False)\n")

    output.write("\n\nunittest.main()")
