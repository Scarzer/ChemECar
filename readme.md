# Chem E Car code for CCNY
## Connection Diagram:
   - Brown Wire is power, connect it to 5 volts
   - Blue Wire is ground, you can connect it to any of the grounds on the arduino
   - Black wire is data, this MUST be connected to Digital Pin 2
   ![Imgur](http://i.imgur.com/HwSAlQ4.jpg?1)

## How to get it to run on your computer!

### Things to download
   - [Node.js](www.nodejs.org) | Needs to be installed
   - [FTDI Drivers](http://www.ftdichip.com/Drivers/VCP.htm) | Needs to be installed
   - This Package

### General Instructions
1. Once you download and install everything that needs to be installed, you will need to open up a terminal window. Almost everything from here on end will be done there.

2. In the terminal, before you plug in the xbee communicator, run the following command: `$ ls /dev/tty.*`

3. This will give you an output of all the currently loaded serial devices, the output will look like the following:


      ```
      /dev/tty.Bluetooth
      /dev/tty.someIphone
      ```
4. At this point, plug in the xbee and run `ls /dev/tty.*`, the output will now look like the following:

      ```
      /dev/tty.Bluetooth
      /dev/tty.someIphone
      /dev/tty.usbserial1452
      ```

5. The last line of the output is the xbee! Save that line, because we are going to have to use it to replace a line in the file that is in the package that you downloaded! (Note that you need to get the last line of YOUR input. Mine might not be the same as yours)

6. Open up `config.json` with a text edior, there will only be one line that you could change. It will look like

      ```
      "serialPort" : "/dev/ttyUSB0"
      ```

7. Here you'll have to change the `/dev/ttyUSB0` to the location of the xbee. In our example, we replace it with `/dev/tty.usbserial1452`

8. Once you've done this, enter `npm install` and wait for everything installed. If you encounter any issues with this, please email me immediately. Debugging might be more involved.

9. Finally, once everything is said and done, enter `node app.js`. This will start the program. If everything runs without any error or issue, open up your favorite web browser and enter the url [localhost:8080](http://localhost:8080)

      
