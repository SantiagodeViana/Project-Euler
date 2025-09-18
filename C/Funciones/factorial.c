int factorial(int n){
  if (n == 0) return 1; //Paso base
  else return (n * factorial(n-1)); //Llamada recursiva
}
