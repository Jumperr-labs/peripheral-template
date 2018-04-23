import re
import os
import subprocess

string_to_replace = "MY_PERIPHERAL"
temp_makefile = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', 'Makefile'))
temp_board = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', 'board.json'))

communication_string = "\n\t1.None\n\t2.I2C\n\t3.SPI\nEnter your communication number (press enter in order to use the default None type):\n"
peripheral_name = raw_input("Please enter your peripheral name (press enter in order to use the default name 'MY_PERIPHERAL'): ") or "MY_PERIPHERAL"
communication_type = raw_input("Please select your peripheral communication type: " + communication_string) or "1"
communication_path = "general"

try:
    communication_type_number = int(communication_type)
    if communication_type_number == 1:
        communication_path = "general"
    elif communication_type_number == 2:
        communication_path = "i2c"
    elif communication_type_number == 3:
        communication_path = "spi"
    else:
        print("Wrong communication type number. Should be 1, 2 or 3. Try to run again.")
        exit(1)
except Exception:
   print("Wrong communication type number. Should be 1, 2 or 3. Try to run again.")
   exit(1)


temp_cpp_file = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', communication_path, 'MY_PERIPHERAL.cpp'))
temp_h_file = os.path.abspath(os.path.join(os.path.dirname(__file__), 'temp_peripheral', communication_path, 'MY_PERIPHERAL.h'))

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
