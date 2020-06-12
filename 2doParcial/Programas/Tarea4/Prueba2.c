int main(){
   
    int n,i;
    int **arr;
    printf("Cuantos numeros va a ingresar: ");
    scanf("%d",&n);
    arr=(int **)malloc(n*sizeof(int *));
    for(i=0;i<=10;i++)
    {
        scanf("%i",&arr[i]);
    }
    //sort(n, arr); 

    return 0;
}
