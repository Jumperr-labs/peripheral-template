# Jumper Virtual Lab Peripheral Model Template
This repo contains a template for creating a new peripheral to use with [Jumper Virtual Lab](https://vlab.jumper.io).

For more information, visit [the docs](https://docs.jumper.io).

### Prerequisites
- Ubuntu 16.04
- GCC and Make: `apt install build-essential`
- [Jumper Virtual Lab](https://docs.jumper.io)

## First step
- Fork [this repository](https://github.com/Jumperr-labs/peripheral-template) on GitHub and clone the new repository onto your Linux machine.
- Make sure you have the build prerequisites by running the following:
  
  ```bash
  cd /PATH/TO/YOUR/NEW/REPO
  python create_peripheral.py
  ```

- After entering your peripheral name you should see the following files in your local library:
1. Makefile
2. board.json
2. YOUR_PERIPHERAL_NAME.cpp
3. YOUR_PERIPHERAL_NAME.h
4. YOUR_PERIPHERAL_NAME.so in the _build folder.

## Peripheral pinout and configuration template
- You can find your peripheral component template in the board.json file with the following key fields:
 1. id - needs to be a unique number across all the peripherals in the board.json.
 2. type - no need to change this one.
 3. file - this tells the Virtual Lab where to find the shared object file for the peripheral. The default points to the YOUR_PERIPHERAL_NAME.so file in the _build folder.
 4. config: pins - this is where you can add pins. To add pins according to the peripheral's data sheet, just add pins to this list with the field name as the pin name and the value as the board's wire number.


  ```json
  {
	"name": "YOUR_PERIPHERAL_NAME",
	"id": 1,
	"type": "Peripheral",
	"file": "_build/YOUR_PERIPHERAL_NAME.so",
	"config": {
		"pins": {
		}
	}
  }
  ```

## Usage
- Add the device logic to the Main() function in the YOUR_PERIPHERAL_NAME.cpp. You can also add more methods, members and global variables as needed.

- When you want to run Jumper Virtual Lab with your peripheral:
 1. Run `make`
 2. Copy the .so file from the "_build/" directory to your Jumper Virtual Lab working directory. (same one as the "board.json" file) 
 3. Add the component to your "board.json" file.
 4. Run Jumper Virtual Lab, for more information head to the https://docs.jumper.io/ 


## License
Licensed under the Apache License, Version 2.0. See the LICENSE file for more information
