//Función usada en Project Euler #387

int isHarshad(long long int n){
    if (n % digitSum(n) == 0) return 1; //Si es divisible entre la suma de sus dígitos
    else return 0;
}
