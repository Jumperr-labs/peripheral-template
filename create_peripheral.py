import re
import os
import subprocess

string_to_replace = "MY_PERIPHERAL"
temp_cpp_file = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', 'MY_PERIPHERAL.cpp'))
temp_h_file = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', 'MY_PERIPHERAL.h'))
temp_makefile = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', 'Makefile'))

peripheral_name = raw_input("Please enter your peripheral name (press enter in order to use the default name 'MY_PERIPHERAL'): ") or "MY_PERIPHERAL"

cpp_file = os.path.abspath(os.path.join(os.path.dirname(__file__),  peripheral_name + ".cpp"))
h_file = os.path.abspath(os.path.join(os.path.dirname(__file__),  peripheral_name + ".h"))
makefile = os.path.abspath(os.path.join(os.path.dirname(__file__), 'Makefile'))

with open(temp_cpp_file, 'r') as fileinput, open(cpp_file, 'w+') as fileoutput:
    for line in fileinput:
        line = re.sub(string_to_replace, peripheral_name, line.rstrip()) + "\n"
        fileoutput.write(line)

with open(temp_h_file, 'r') as fileinput, open(h_file, 'w+') as fileoutput:
    for line in fileinput:
        line = re.sub(string_to_replace, peripheral_name, line.rstrip()) + "\n"
        fileoutput.write(line)

with open(temp_makefile, 'r') as fileinput, open(makefile, 'w+') as fileoutput:
    for line in fileinput:
        line = re.sub(string_to_replace, peripheral_name, line.rstrip()) + "\n"
        fileoutput.write(line)


subprocess.check_call('make')