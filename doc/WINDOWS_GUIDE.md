# How to build a .hex file and flash it to your keyboard using Windows

## Install VirtualBox

## Install ConEmu
Let's be honest, the Windows Command Prompt is awful. To make our experience less tormenting, I suggest to install ConEmu using [this](https://scotch.io/tutorials/get-a-functional-and-sleek-console-in-windows) tutorial. ConEmu-Maximus5 is a Windows console emulator with tabs, which presents multiple consoles and simple GUI applications as one customizable GUI window with various features. At least, that's what their website says. 

In short, it's a command prompt with some of the more popular linux commands (if you followed the tutorial from above) and with a lot less problems when it comes to 'PATH' references.


## Install Vagrant


## Create a Vagrant Box, I prefer Debian. 
Choose a box from [https://vagrantcloud.com](Vagrant Cloud) 

`vagrant box add debian/jessie64`

Create a new folder for your project & init vagrant

`vagrant init debian/jessie64`

Run your new machine

`vagrant up` 

Ssh into your new machine

`vagrant ssh`

## Install git on your Vagrant box
After you are logged into your machine using SSH you can install git using the following command:

`sudo apt-get install git`

## Clone the QMK repository
Create a directory using the following command:

`mkdir <directory-name>`

Now go into that command using: 

`cd <directory-name>`

Next you need to clone the github repository with the following command:

`sudo git clone https://github.com/qmk/qmk_firmware.git`





