import re
import os
import subprocess

string_to_replace = "MY_PERIPHERAL"
temp_cpp_file = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', 'MY_PERIPHERAL.cpp'))
temp_h_file = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', 'MY_PERIPHERAL.h'))
temp_makefile = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', 'Makefile'))
temp_board = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', 'board.json'))

peripheral_name = raw_input("Please enter your peripheral name (press enter in order to use the default name 'MY_PERIPHERAL'): ") or "MY_PERIPHERAL"

cpp_file = os.path.abspath(os.path.join(os.path.dirname(__file__),  peripheral_name + ".cpp"))
h_file = os.path.abspath(os.path.join(os.path.dirname(__file__),  peripheral_name + ".h"))
makefile = os.path.abspath(os.path.join(os.path.dirname(__file__), 'Makefile'))
board = os.path.abspath(os.path.join(os.path.dirname(__file__), 'board.json'))


def rename_peripheral(fileinput_name , fileoutput_name):
    with open(fileinput_name, 'r') as fileinput, open(fileoutput_name, 'w+') as fileoutput:
        for line in fileinput:
            line = re.sub(string_to_replace, peripheral_name, line.rstrip()) + "\n"
            fileoutput.write(line)

rename_peripheral(temp_cpp_file, cpp_file)
rename_peripheral(temp_h_file, h_file)
rename_peripheral(temp_makefile, makefile)
rename_peripheral(temp_board, board)

# run make
subprocess.check_call('make')
