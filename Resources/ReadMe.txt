CPUCC is a program used to test the performance of a CPU when cross correlating with an implementation of a FX correlator.
To run CPUCC just run the program via a terminal.
The syntax of the command is as follows:
> CPUCC [/bitdepth][/bd] {VAL} [/windowsize][/ws] {VAL} [/numsig][/ns] {VAL} [/numthreads][/nt] {VAL}

[/bitdepth][/bd]  Set the number of bits that represent the signal amplitudes. (16 by Default)
[/windowsize][/ws]Set the size of the windows that will be cross correlated, where each 1 would represent the specifeid bitdepth. (X by Default)
[/numsig][/ns]    Set the number of input signals to simulate for correlation. (20 by Default)
[/numthreads][/nt]Set the number of CPU threads to be used when processing data. (2 by Default)

Example: > CPUCC /bitdepth 8 /ns 23 /nt 4
This will run CPUCC with a bitdepth of 8 and a default windowsize with 23 input signals and run on 4 threads.
All {VAL} are integers.