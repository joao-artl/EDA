void ordena (int *v, int n){
    if (n <= 1) 
        return; 
    ordena(v, n - 1); 
    int ult = v[n - 1]; 
    int j = n - 2; 
    while (j >= 0 && v[j] > ult) { 
        v[j + 1] = v[j]; 
        j--; 
    } 
    v[j + 1] = ult;
} 