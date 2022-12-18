# AdvancePlay
This repo aims to create an open source linux solution to convert video
into a gba compatible format. 
It utilizes ffmpeg to create the bitmap frames and pcm audio which is then encoded using various software. Video playback so far has some color issues and is limited in total time but is functional on real hardware.

## Required installs before this will work
Linux (Ubuntu/Debian/Centos). This is only for linux currently. I've only tested on debian but it should work on centos.

Debian/Ubuntu
`sudo apt install cimg-dev ffmpeg`

Centos
`sudo yum install cimg-dev ffmpeg`


## Running
 
 
`chmod +X setup.sh && setup.sh` 


## Credits
So many. In no particular order because all of their work led to this:

Jamie Stewart: https://github.com/JamieDStewart for his awesome gba makefile/vscode templates which I modified for Linux. He has some awesome tutorials on github and youtube as well. I seriously think that everyone should start with his templates and tutorials.

Ian Finlayson: https://github.com/IanFinlayson for his raw2gba audio software which does the heavy lifting to encode pcm audio to a gba format. Seriously without this I would have had to figure so much for audio playback.

Evan Murray: https://github.com/emurray2 for his music-gba software which this uses for the playback method to play raw2gba formatted arrays. Check out his github and youtube since that is what this uses for playback of audio.

Seriously though without these guys I wouldn't have even been able to prototype this - and especially not in just a few days!

## Goals
First and foremost I would like longer playback. I think this can be achieved using things such as lz77, chroma subsampling, lowering resolution(during build)+upscaling(by gba), and potentially a lower sample rate for audio.

Next I'd like to make this a standalone cross-platform application that is super easy to use.

## Contibuting
Not sure this is even necessary but certainly put in pull requests. Anyone who wants to contribute better algorithms/features/whatever please do!