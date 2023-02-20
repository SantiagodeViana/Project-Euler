int binary(int n);{ //Recibiendo un decimal, lo convierte y devuelve en binario
	int pt [21] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576}; //Array potencias de 2
	int i, binary;
	while (pt[i] < n){
		i++; //Se busca la potencia que sea mayor al input
	}while (pt[i] != 1){
		i--;
		n -= pt[i]; //Se le resta la potencia al número
		binary = (10^i); // Los dígitos de un número binario corresponden a los exponentes de las potencias de dos		
}
