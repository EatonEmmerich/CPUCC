function Outputsignal = myfft(Inputsignal)

	
endfunction

function Output = butterfly(Input,N,k)

	W_N=e^(-j*2*pi/N)
	ReductionPhrase = W_N*Input(1);
	Output(0) = Input(0)+ReductionPhrase;
	Output(1) = Input(0)-ReductionPhrase; 

endfunction

function Output = 2pointfft(Input)
	
	Output(0) = Input(0)+Input(1);
	Output(1) = Input(0)-Input(1);

endfunction
