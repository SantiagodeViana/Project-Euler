int fibonacci(int n){
  if (n<=1) return 1; //Paso base
  else return (fibonacci(n-1)+fibonacci(n-2)); //Llamada recursiva
}
