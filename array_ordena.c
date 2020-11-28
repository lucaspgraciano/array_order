#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TRUE 1
#define FALSE 0

//-- CALCULAR O TEMPO DE EXECUCAO INICIO
double calc(clock_t ini, clock_t fim){
	double tempo = (double)(fim - ini)/CLOCKS_PER_SEC;
	return tempo;
}
//-- CALCULAR O TEMPO DE EXECUCAO FIM

//-- GERAR VETOR INICIO
int *vetor(int n){ 
	int *vet = (int *)malloc(n*sizeof(int));
	return vet;
}
//-- GERAR VETOR FIM

//-- PREENCHER VETORES INICIO
void crescente(int *vet, int n){
	int i;
	for (i=0;i<n;i++){
		vet[i] = i;
	}
}
void decrescente(int *vet, int n){
	int i;
	for(i=0;i<n;i++){
		vet[i] = n -i -1;
	}
}
void fisher(int *vet, int n){
	int i, j, aux;
	for(i=n-1;i>0;i--){
		j = rand()&(i+1);
		aux = vet[j];
		vet[j] = vet[i];
		vet[i] = aux;
	}
} 
//-- PREENCHER VETORES FIM

//-- ALGORITMOS DE ORDENAÇÃO INICIO
//-- TROCA INICIO
void troca(int *a, int *b){
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}
void troca_qsort(int *vet, int i, int j){
    int aux = vet[j];
    vet[j] = vet[i];
    vet[i] = aux;
}
//-- TROCA FIM

//-- BUBBLE INICIO
double bubble(int *vet, int n){
	clock_t ini = clock();
	int i, j, max_valido, aux;
	for(i=0;i<n;i++){
		max_valido=n-i-1;
		for(j=0;j<max_valido;j++){
			if(vet[j]>vet[j+1]){
				aux = vet[j];
				vet[j]=vet[j+1];
			   	vet[j+1]=aux;
			}
		}
	}	
    clock_t fim = clock();
    return calc(ini, fim);
}
//-- BUBBLE FIM

//-- QSORT INICIO
int separa(int vet[], int c, int f) {
    double d = (double)rand()/((double)RAND_MAX+1);
	double k = d * (f - c + 1);
    int r = c+k;
    
    troca_qsort(vet, r, f);

    int pivo = vet[f];
	int i = c-1;
	int j;

    for(j=c;j<=f-1;j++){
        if (vet[j]<=pivo){
            i = i+1;
            troca_qsort(vet, i, j);
        }
    }
    troca_qsort(vet, i + 1, f);
    return i + 1; 
}
void q_sort(int vet[], int c, int f) {
    if(c<f){
        int q = separa(vet, c, f);
        q_sort(vet, c, q-1);
        q_sort(vet, q + 1, f);
    }
}
double quicksort(int *vet, int n){
	clock_t ini = clock();
	q_sort(vet, 0, n-1);
	clock_t fim = clock();
	return calc(ini, fim);
}
//-- QSORT FIM 

//-- INSERT INICIO
double insert(int *vet, int n){
	clock_t ini = clock();
	int j, i, aux;
	for(j=1;j<n;j++){
		aux = vet[j];
		for(i=j-1;(i>=0)&&(vet[i]>aux);i--){
			vet[i+1]=vet[i];
		}
		vet[i+1]=aux;
	}
	clock_t fim = clock();
	return calc(ini, fim);
}
//-- INSERT FIM

//-- SELECTION INICIO
double selection(int *vet, int n){
    clock_t ini = clock();
    int i, j, maxj, max_v;
	for(i=0;i<n;i++){
		max_v = n - i;
		maxj = 0;
		for(j=1;j<max_v;j++){
			if(vet[j]>vet[maxj])
				maxj = j;
		}
		troca(&vet[max_v-1],&vet[maxj]);
	}
	clock_t fim = clock();
    return calc(ini, fim);
}
//-- SELECTION FIM

//-- MERGE INICIO
void merge(int *vet, int *vet2, int i, int m, int f){
    int z, iv = i, ic = m + 1;
    for(z=i;z<=f;z++)
        vet2[z]=vet[z];
    z = i;
    while(iv<=m&&ic<= f){
        if(vet2[iv] < vet2[ic])
            vet[z++]=vet2[iv++];
        else
            vet[z++]=vet2[ic++];
    }
    while(iv <= m)
        vet[z++]=vet2[iv++];
    while(ic<=f)
        vet[z++]=vet2[ic++];
}
void sort(int *vet, int *vet2, int i, int f){
    if(i>=f)
        return;
    int m=(i+f)/2;
    sort(vet, vet2, i, m);
    sort(vet, vet2, m + 1, f);

    if(vet[m]<=vet[m + 1])
        return;
    merge(vet, vet2, i, m, f);
}
double msort(int *vet, int n){
    clock_t ini = clock();
    int *vet2 = malloc(sizeof(int) * n);
    sort(vet, vet2, 0, n-1);
    free(vet2);
    clock_t fim = clock();
    return calc(ini, fim);
}
//-- MERGE FIM
//-- ALGORITMOS DE ORDENAÇÃO FIM

//-- IMPRIME TABELA INICIO

void cresce_t(){
	int a=1000;
	int b=10000;
	int c=100000;
	int d=200000;
	int e=300000;
	int f=400000;
	int g=500000;
	
	int *vet_a = vetor(a);
	crescente(vet_a,a);
	double tbubble_a = bubble(vet_a,a);
	double tinsert_a = insert(vet_a,a);
	double tselect_a = selection(vet_a,a);
	double tmerges_a = msort(vet_a,a);
	double tqsort_a = quicksort(vet_a,a);

	int *vet_b = vetor(b);
	crescente(vet_b, b);
	double tbubble_b = bubble(vet_b, b);
	double tinsert_b = insert(vet_b, b);
	double tselect_b = selection(vet_b, b);
	double tmerges_b = msort(vet_b, b);
	double tqsort_b = quicksort(vet_b,b);

	int *vet_c = vetor(c);
	crescente(vet_c, c);
	double tbubble_c = bubble(vet_c, c);
	double tinsert_c = insert(vet_c, c);
	double tselect_c = selection(vet_c, c);
	double tmerges_c = msort(vet_c, c);
	double tqsort_c = quicksort(vet_c,c);

	int *vet_d = vetor(d);
	crescente(vet_d, d);
	double tbubble_d = bubble(vet_d, d);
	double tinsert_d = insert(vet_d, d);
	double tselect_d = selection(vet_d, d);
	double tmerges_d = msort(vet_d, d);
	double tqsort_d = quicksort(vet_d,d);

	int *vet_e = vetor(e);
	crescente(vet_e, e);
	double tbubble_e = bubble(vet_e, e);
	double tinsert_e = insert(vet_e, e);
	double tselect_e = selection(vet_e, e);
	double tmerges_e = msort(vet_e, e);
	double tqsort_e = quicksort(vet_e,e);

	int *vet_f = vetor(f);
	crescente(vet_f, f);
	double tbubble_f = bubble(vet_f, f);
	double tinsert_f = insert(vet_f, f);
	double tselect_f = selection(vet_f, f);
	double tmerges_f = msort(vet_f, f);
	double tqsort_f = quicksort(vet_f,f);
	
	int *vet_g = vetor(g);
	crescente(vet_g, g);
	double tbubble_g = bubble(vet_g, g);
	double tinsert_g = insert(vet_g, g);
	double tselect_g = selection(vet_g, g);
	double tmerges_g = msort(vet_g, g);
	double tqsort_g = quicksort(vet_g,g);
			
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=CRESCENTE=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("TAMANHO  => %d     | %d     | %d     | %d     | %d      | %d     | %d\n", a, b, c, d, e, f, g);
	printf("______________________________________________________________________________________________\n");
	printf("BUBBLE   => %2.5f  | %2.5f   | %2.5f   | %2.5f   | %2.5f   | %2.5f  | %2.5f\n", tbubble_a, tbubble_b, tbubble_c, tbubble_d, tbubble_e, tbubble_f, tbubble_g);
	printf("INSERT   => %2.5f  | %2.5f   | %2.5f    | %2.5f    | %2.5f     | %2.5f    | %2.5f\n", tinsert_a, tinsert_b, tinsert_c, tinsert_d, tinsert_e, tinsert_f,tinsert_g);
	printf("SELECT   => %2.5f  | %2.5f   | %2.5f   | %2.5f   | %2.5f   | %2.5f  | %2.5f\n", tselect_a, tselect_b, tselect_c, tselect_d, tselect_e, tselect_f, tselect_g);
	printf("MERGE    => %2.5f  | %2.5f   | %2.5f    | %2.5f    | %2.5f     | %2.5f    | %2.5f\n", tmerges_a, tmerges_b, tmerges_c, tmerges_d, tmerges_e, tmerges_f, tmerges_g);
	printf("QSORT    => %2.5f  | %2.5f   | %2.5f    | %2.5f    | %2.5f     | %2.5f    | %2.5f\n", tqsort_a, tqsort_b, tqsort_c, tqsort_d, tqsort_e, tqsort_f, tqsort_g);
	printf("\n");
	
	free(vet_a);   
	free(vet_b);
	free(vet_c);
	free(vet_d);
	free(vet_e);
	free(vet_f);
	free(vet_g);
}
void decresce_t(){
	int a=1000;
	int b=10000;
	int c=100000;
	int d=200000;
	int e=300000;
	int f=400000;
	int g=500000;
	
	int *vet_a = vetor(a);
	decrescente(vet_a,a);
	double tbubble_a = bubble(vet_a,a);
	decrescente(vet_a,a);
	double tinsert_a = insert(vet_a,a);
	decrescente(vet_a,a);
	double tselect_a = selection(vet_a,a);
	decrescente(vet_a,a);
	double tmerges_a = msort(vet_a,a);
	decrescente(vet_a,a);
	double tqsort_a = quicksort(vet_a,a);

	int *vet_b = vetor(b);
	decrescente(vet_b, b);
	double tbubble_b = bubble(vet_b, b);
	decrescente(vet_b, b);
	double tinsert_b = insert(vet_b, b);
	decrescente(vet_b, b);
	double tselect_b = selection(vet_b, b);
	decrescente(vet_b, b);
	double tmerges_b = msort(vet_b, b);
	decrescente(vet_b,b);
	double tqsort_b = quicksort(vet_b,b);

	int *vet_c = vetor(c);
	decrescente(vet_c, c);
	double tbubble_c = bubble(vet_c, c);
	decrescente(vet_c, c);
	double tinsert_c = insert(vet_c, c);
	decrescente(vet_c, c);
	double tselect_c = selection(vet_c, c);
	decrescente(vet_c, c);
	double tmerges_c = msort(vet_c, c);
	decrescente(vet_c,c);
	double tqsort_c = quicksort(vet_c,c);

	int *vet_d = vetor(d);
	decrescente(vet_d, d);
	double tbubble_d = bubble(vet_d, d);
	decrescente(vet_d, d);
	double tinsert_d = insert(vet_d, d);
	decrescente(vet_d, d);
	double tselect_d = selection(vet_d, d);
	decrescente(vet_d, d);
	double tmerges_d = msort(vet_d, d);
	decrescente(vet_d,d);
	double tqsort_d = quicksort(vet_d,d);

	int *vet_e = vetor(e);
	decrescente(vet_e, e);
	double tbubble_e = bubble(vet_e, e);
	decrescente(vet_e, e);
	double tinsert_e = insert(vet_e, e);
	decrescente(vet_e, e);
	double tselect_e = selection(vet_e, e);
	decrescente(vet_e, e);
	double tmerges_e = msort(vet_e, e);
	decrescente(vet_e,e);
	double tqsort_e = quicksort(vet_e,e);

	int *vet_f = vetor(f);
	decrescente(vet_f, f);
	double tbubble_f = bubble(vet_f, f);
	decrescente(vet_f, f);
	double tinsert_f = insert(vet_f, f);
	decrescente(vet_f, f);
	double tselect_f = selection(vet_f, f);
	decrescente(vet_f, f);
	double tmerges_f = msort(vet_f, f);
	decrescente(vet_f,f);
	double tqsort_f = quicksort(vet_f,f);
	
	int *vet_g = vetor(g);
	decrescente(vet_g, g);
	double tbubble_g = bubble(vet_g, g);
	decrescente(vet_g, g);
	double tinsert_g = insert(vet_g, g);
	decrescente(vet_g, g);
	double tselect_g = selection(vet_g, g);
	decrescente(vet_g, g);
	double tmerges_g = msort(vet_g, g);
	decrescente(vet_g,g);
	double tqsort_g = quicksort(vet_g,g);
			
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=DECRESCENTE=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("TAMANHO  => %d     | %d     | %d     | %d     | %d      | %d     | %d\n", a, b, c, d, e, f, g);
	printf("______________________________________________________________________________________________\n");
	printf("BUBBLE   => %2.5f  | %2.5f   | %2.5f   | %2.5f   | %2.5f   | %2.5f  | %2.5f\n", tbubble_a, tbubble_b, tbubble_c, tbubble_d, tbubble_e, tbubble_f, tbubble_g);
	printf("INSERT   => %2.5f  | %2.5f   | %2.5f   | %2.5f   | %2.5f   | %2.5f  | %2.5f\n", tinsert_a, tinsert_b, tinsert_c, tinsert_d, tinsert_e, tinsert_f,tinsert_g);
	printf("SELECT   => %2.5f  | %2.5f   | %2.5f   | %2.5f   | %2.5f   | %2.5f  | %2.5f\n", tselect_a, tselect_b, tselect_c, tselect_d, tselect_e, tselect_f, tselect_g);
	printf("MERGE    => %2.5f  | %2.5f   | %2.5f    | %2.5f    | %2.5f     | %2.5f    | %2.5f\n", tmerges_a, tmerges_b, tmerges_c, tmerges_d, tmerges_e, tmerges_f, tmerges_g);
	printf("QSORT    => %2.5f  | %2.5f   | %2.5f    | %2.5f    | %2.5f     | %2.5f    | %2.5f\n", tqsort_a, tqsort_b, tqsort_c, tqsort_d, tqsort_e, tqsort_f, tqsort_g);
	printf("\n");
	
	free(vet_a);   
	free(vet_b);
	free(vet_c);
	free(vet_d);
	free(vet_e);
	free(vet_f);
	free(vet_g);
}
void fisher_t(){
	int a=1000;
	int b=10000;
	int c=100000;
	int d=200000;
	int e=300000;
	int f=400000;
	int g=500000;
	
	int *vet_a = vetor(a);
	fisher(vet_a,a);
	double tbubble_a = bubble(vet_a,a);
	fisher(vet_a,a);
	double tinsert_a = insert(vet_a,a);
	fisher(vet_a,a);
	double tselect_a = selection(vet_a,a);
	fisher(vet_a,a);
	double tmerges_a = msort(vet_a,a);

	int *vet_b = vetor(b);
	fisher(vet_b, b);
	double tbubble_b = bubble(vet_b, b);
	fisher(vet_b, b);
	double tinsert_b = insert(vet_b, b);
	fisher(vet_b, b);
	double tselect_b = selection(vet_b, b);
	fisher(vet_b, b);
	double tmerges_b = msort(vet_b, b);

	int *vet_c = vetor(c);
	fisher(vet_c, c);
	double tbubble_c = bubble(vet_c, c);
	fisher(vet_c, c);
	double tinsert_c = insert(vet_c, c);
	fisher(vet_c, c);
	double tselect_c = selection(vet_c, c);
	fisher(vet_c, c);
	double tmerges_c = msort(vet_c, c);

	int *vet_d = vetor(d);
	fisher(vet_d, d);
	double tbubble_d = bubble(vet_d, d);
	fisher(vet_d, d);
	double tinsert_d = insert(vet_d, d);
	fisher(vet_d, d);
	double tselect_d = selection(vet_d, d);
	fisher(vet_d, d);
	double tmerges_d = msort(vet_d, d);

	int *vet_e = vetor(e);
	fisher(vet_e, e);
	double tbubble_e = bubble(vet_e, e);
	fisher(vet_e, e);
	double tinsert_e = insert(vet_e, e);
	fisher(vet_e, e);
	double tselect_e = selection(vet_e, e);
	fisher(vet_e, e);
	double tmerges_e = msort(vet_e, e);

	int *vet_f = vetor(f);
	fisher(vet_f, f);
	double tbubble_f = bubble(vet_f, f);
	fisher(vet_f, f);
	double tinsert_f = insert(vet_f, f);
	fisher(vet_f, f);
	double tselect_f = selection(vet_f, f);
	fisher(vet_f, f);
	double tmerges_f = msort(vet_f, f);
	
	int *vet_g = vetor(g);
	fisher(vet_g, g);
	double tbubble_g = bubble(vet_g, g);
	fisher(vet_g, g);
	double tinsert_g = insert(vet_g, g);
	fisher(vet_g, g);
	double tselect_g = selection(vet_g, g);
	fisher(vet_g, g);
	double tmerges_g = msort(vet_g, g);

			
	printf("\n=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=EMBARALHADO=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
	printf("TAMANHO  => %d     | %d    | %d    | %d    | %d     | %d     | %d\n", a, b, c, d, e, f, g);
	printf("______________________________________________________________________________________________\n");
	printf("BUBBLE   => %2.5f  | %2.5f  | %2.5f  | %2.5f  | %2.5f  | %2.5f  | %2.5f\n", tbubble_a, tbubble_b, tbubble_c, tbubble_d, tbubble_e, tbubble_f, tbubble_g);
	printf("INSERT   => %2.5f  | %2.5f  | %2.5f   | %2.5f   | %2.5f    | %2.5f    | %2.5f\n", tinsert_a, tinsert_b, tinsert_c, tinsert_d, tinsert_e, tinsert_f,tinsert_g);
	printf("SELECT   => %2.5f  | %2.5f  | %2.5f  | %2.5f  | %2.5f  | %2.5f  | %2.5f\n", tselect_a, tselect_b, tselect_c, tselect_d, tselect_e, tselect_f, tselect_g);
	printf("MERGE    => %2.5f  | %2.5f  | %2.5f   | %2.5f   | %2.5f    | %2.5f    | %2.5f\n", tmerges_a, tmerges_b, tmerges_c, tmerges_d, tmerges_e, tmerges_f, tmerges_g);
	printf("\n");
	
	free(vet_a);   
	free(vet_b);
	free(vet_c);
	free(vet_d);
	free(vet_e);
	free(vet_f);
	free(vet_g);
}
void imprime(){
	fisher_t();
	cresce_t();
	decresce_t();
}
//-- IMPRIME FIM

int main(void){
	imprime();
	return 0;
}