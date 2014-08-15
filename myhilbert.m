function Outputsignal = myhilbert (Inputsignal)
        N = size(Inputsignal,2)
        Phi_H = zeros(1,N);
	Phi_H = Phi_H(1,:);
        Phi_H(2:N/2-1) = e^(-j*pi/2);
        Phi_H(N/2+1:N) = e^(j*pi/2);
        Inputsignal = real(Inputsignal);
        temp = fft(Inputsignal);
        temp2 = temp.*Phi_H;
        Outputsignal = real(ifft(temp2))*j + Inputsignal;
	

endfunction

