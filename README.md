# Jumper Virtual Lab Peripheral Model Template
This repo contains a template for creating a new peripheral to use with [Jumper Virtual Lab](https://vlab.jumper.io).

For more information, visit [the docs](https://docs.jumper.io).

### Prerequisites
- Ubuntu 16.04
- GCC and Make: `apt install build-essential`
- [Jumper Virtual Lab](https://docs.jumper.io)

## Usage
- Fork [this repository](https://github.com/Jumperr-labs/peripheral-template) on GitHub and clone the new repository onto your Linux machine.
- Make sure you have the build prerequisites by running the following:
  
  ```bash
  cd /PATH/TO/YOUR/NEW/REPO
  make
  ```

  If everything worked as expected, you should now have a "_build/MY_PERIPHERAL.so" file.
- Change the name of the peripheral from "MY_PERIPHERAL" to the correct name (usually the part no.). You should change the following files:
  - MY_PERIPHERAL.cpp/.h (filename and contents)
  - Makefile

  After changing the files run:
  
  ```bash
  make clean
  make
  ```

  And make sure you have a new .so file in the _build/ directory.

- Add the device logic to the Main() function. You can also add more methods, members and global variables as needed.
- When you want to run Jumper Virtual Lab with your peripheral:
  1. Run `make`
  2. copy the .so file from the "_build/" directory to your Jumper Virtual Lab working directory (same one as the "board.json" file) and add the component to your "board.json" file:

  ```json
  {
    "name": "[PERIPHERAL NAME HERE]",
    "id": 2,
    "type": "Peripheral",
    "file": "[MY_PERIPHERAL.so]",
    "config": {
      "pins": {
        // TODO: State the connected pins here
      }
    }
  }
  ```

  Make sure to set the **name**, **file** and **pins** fields to the correct values (remove the brackets "[" "]").

## License
Licensed under the Apache License, Version 2.0. See the LICENSE file for more information
