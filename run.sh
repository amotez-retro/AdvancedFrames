#!/bin/bash

# Generate frames from video with ffmpeg
echo "Generate frames from video with ffmpeg"
ffmpeg -ss 00:00:00 -to 00:30:00 -i $1 -r 10/1 -vf scale=240:160,setsar=1:1 -q:v 2 working/frames/output%03d.bmp

# Run frames through rgb2gba and redirect to frames.h
echo "Convert frames from bmp to header"
./working/rgb2gba-master/rgb2gba ./working/frames >> resources/frames.h

# Generate pcm audio from input with ffmpeg
echo "Generate pcm audio with ffmpeg"
ffmpeg -y -ss 00:00:00 -to 00:30:00 -i $1 -acodec pcm_s8 -ac 1 -ar 8000 -f s8 working/audio.raw

# Create sound header with raw2gba
echo "Convert pcm audio to header"
./working/raw2gba-main/raw2gba ./working/audio.raw

# Run make
make