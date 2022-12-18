#!/bin/bash

if [ -f /etc/redhat-release ]; then
  sudo yum install cimg-dev ffmpeg
fi

if [ -f /etc/lsb-release ]; then
  sudo apt install cimg-dev ffmpeg
fi

# Make run script work
chmod +x run.sh

# Create directories for output frames and audio
mkdir -p ./working/frames
mkdir -p ./working/audio

# Install and build raw2gba
curl -sL https://github.com/IanFinlayson/raw2gba/archive/refs/heads/master.zip -o working/raw2gba.zip && unzip working/raw2gba.zip -d working
gcc working/raw2gba-master/raw2gba.c -o working/raw2gba

# Install and build img2gba
curl -sL https://github.com/JoshThibado/rgb2gba/archive/refs/heads/master.zip -o working/rgb2gba.zip && unzip working/rgb2gba.zip -d working
g++ /working/rgb2gba-master/rgb2gba.c -lX11 -lpthread -o working/rgb2gba
