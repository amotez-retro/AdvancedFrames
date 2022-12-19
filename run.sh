#!/bin/bash

#Work in progress, run commands manually for now

# Generate frames from video with ffmpeg
echo "Generate frames from video with ffmpeg"
ffmpeg -t 30 -i "$1" -nostdin -r 10/1 -vf scale=240:160,setsar=1:1 -q:v 2 working/frames/output%03d.bmp

# Run frames through rgb2gba and redirect to frames.h
echo "Convert frames from bmp to header"
framescmd='./working/rgb2gba ./working/frames >> resources/frames.h'
eval $framescmd

# Generate pcm audio from input with ffmpeg
echo "Generate pcm audio with ffmpeg"
ffmpeg -t 30 -i "$1" -nostdin -y -acodec pcm_s8 -ac 1 -ar 8000 -f s8 working/audio/audio.raw

# Create sound header with raw2gba
echo "Convert pcm audio to header"
./working/raw2gba ./working/audio/audio.raw
#mv ./working/audio/audio.h ./working/audio/audio.h
cp ./working/audio/audio.h ./resources/sound.h

# Run make
make
