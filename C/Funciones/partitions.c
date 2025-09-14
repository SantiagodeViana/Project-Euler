//Calcula particiones de n, siendo k la parte más grande
//Usado en Projeect Euler #76, #77 y #78

long long int partitions(int n, int k){ 
    if (n == 0) return 1;
    else if (n < 0 || k == 0) return 0;
    else return partitions(n, k-1) + partitions(n-k, k);
}
