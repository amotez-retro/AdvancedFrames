# GBAFRAMES
This repo aims to create an open source linux solution to convert video
into a gba compatible format. 
It utilizes ffmpeg to create the bitmap frames and pcm audio which is then encoded using various software. Video playback so far has some color issues and is limited in total time but is functional on real hardware.

## Required installs before this will work
Linux (Ubuntu/Debian/Centos). This is only for linux currently. I've only tested on debian but it should work on centos. This should be handled in the setup.sh

You need to have the gba devkitpro tools installed and working first and foremost.
See https://devkitpro.org/wiki/Getting_Started#Unix-like_platforms for instructions

You also need cimg and ffmpeg installed on your machine. These will be installed in the setup.sh script for both Debian/Ubuntu and Centos. 


## Setup
Download/clone the source and go to the GBAFrames directory:

`cd GBAFrames` then run

`chmod +x setup.sh && ./setup.sh`

## Running
There is a run.sh script but for now manual commands are required.
Ensure you are in the GBAFrames directory and run the following:

Convert video to bitmap frames. In this case from 0 to 30 seconds of the input.

`ffmpeg -ss 00:00:00 -to 00:30:00 -i <path/to/input.mp4> -r 10/1 -vf scale=240:160,setsar=1:1 -q:v 2 working/frames/output%03d.bmp`

Use rgb2gba which was built in the setup step above to convert frames to a c header file

`./working/rgb2gba ./working/frames`

`mv frames.h resources/frames.h`

Generate pcm audio with ffmpeg

`ffmpeg -ss 00:00:00 -to 00:30:00 <path/to/input.mp4> -y -acodec pcm_s8 -ac 1 -ar 8000 -f s8 working/audio/audio.raw`

Convert pcm audio to header

`./working/raw2gba ./working/audio/audio.raw`

Then run make to compile everything
`make`

## Credits
So many. In no particular order because all of their work led to this:

Jamie Stewart: https://github.com/JamieDStewart for his awesome gba makefile/vscode templates which I modified for Linux. He has some awesome tutorials on github and youtube as well. I seriously think that everyone should start with his templates and tutorials.

Ian Finlayson: https://github.com/IanFinlayson for his raw2gba audio software which does the heavy lifting to encode pcm audio to a gba format. Seriously without this I would have had to figure so much for audio playback.

Evan Murray: https://github.com/emurray2 for his music-gba software which this uses for the playback method to play raw2gba formatted arrays. Check out his github and youtube since that is what this uses for playback of audio.

Seriously though without these guys I wouldn't have even been able to prototype this - and especially not in just a few days!

## Goals
First and foremost I would like longer playback. I think this can be achieved using things such as lz77, chroma subsampling, lowering resolution(during build)+upscaling(by console), and potentially a lower sample rate for audio.

Next I'd like to make this a standalone cross-platform application that is super easy to use.

## Contibuting
If you have something cool or useful you'd like to add put in pull requests. 
Anyone who wants to contribute better algorithms/features/whatever (assuming it isn't copyright in some way) please do!

## Info
This project is not affiliated, endorsed by, produced by or in any way associated with Nintendo. 

Any usage of this project or any outcome produced by this project including software, source, output, binaries, executables, or any other thing generated as a result of this project; or by any software used in this build chain is done without any liability to devlopers, coders, maintainers, or any other entity with affiliation to this project. This project assumes any users/entities will use it only for legal purposes as defined by law in whatever juridiction the project, software, executables, or other outputs is/are used. 
