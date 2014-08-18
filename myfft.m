function Outputsignal = myfft(Inputsignal)
	
	L = size(Inputsignal,2);
	Outputsignal = zeros(1,L);
	% For input of length 4:
	[Even Odd] = EvenAndOdd(Inputsignal);
	O1 = twopointfft(Even);		%even
	O2 = twopointfft(Odd);		%odd
	% Butterfly is applied to every pair by sequence;
	SO1 = butterfly(O1(1),O2(1),0,4);
	SO2 = butterfly(O1(2),O2(2),1,4);
	%is bit revesed order.
	Outputsignal = [SO1 SO2];
	
	
endfunction

function Output = butterfly(I1,I2,k,N)

	W_N=e^(-(j*2*pi/N)*k);
	ReductionPhrase = W_N*I2;
	Output(1) = I1+ReductionPhrase;
	Output(2) = I1-ReductionPhrase;

endfunction

function Output = twopointfft(Input)
	
	Output(1) = Input(1)+Input(2);
	Output(2) = Input(1)-Input(2);

endfunction

function [Even Odd] = EvenAndOdd(Input)

	length = size(Input,2);
	x = 1;
	i = 1;
	%assuming input data length is always a factor of 2.
	Even = zeros(1,length/2);
	Odds = zeros(1,length/2);
	while x < length
		Even(i) = Input(x);
		x = x+1;
		Odd(i) = Input(x);
		x = x+1;
		i = i+1;
	end

endfunction

function Out = bitreverse(In)

	%test with set function
	Out = bitrevorder(In);

endfunction
