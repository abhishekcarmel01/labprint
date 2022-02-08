#include<stdio.h>
struct poly{
	int coef;
	int power;
};
void print(struct poly o[],int n){
	int i;
	for(i=0;i<n-1;i++)
		if(o[i].coef!=0){
			if(o[i+1].coef<0)
				printf("%ix^%i  ",o[i].coef,o[i].power);
			else
				printf("%ix^%i + ",o[i].coef,o[i].power);
                }
        printf(" %ix^%i",o[n-1].coef,o[n-1].power);
        printf("\n");
}
void main(){
	struct poly i1[100],i2[100],o[100];
	int d1,d2,i,j,flag,n,temp;
	printf("Enter the no of terms of first polynomial : ");
	scanf("%i",&d1);
	printf("Enter the coefficient and power\n");
	for(i=0;i<d1;i++){
		scanf("%i%i",&i1[i].coef,&i1[i].power);
	}
	printf("Enter the no of terms of second polynomial : ");
	scanf("%i",&d2);
	printf("Enter the coefficient and power\n");
	for(i=0;i<d2;i++){
		scanf("%i%i",&i2[i].coef,&i2[i].power);
	}
	for(i=0;i<d1;i++){
		o[i]=i1[i];
	}
	n=d1;
	for(i=0;i<d2;i++){
		flag=0;
		for(j=0;j<d1;j++){
			if(o[j].power==i2[i].power){
				o[j].coef+=i2[i].coef;
				flag=1;
				break;
			}
		}
		if(flag==0){
			o[n].power=i2[i].power;
			o[n].coef=i2[i].coef;
			n++;
		}
	}
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			if(o[j].power<o[j+1].power){
				temp=o[j].power;
				o[j].power=o[j+1].power;
				o[j+1].power=temp;
				temp=o[j].coef;
				o[j].coef=o[j+1].coef;
				o[j+1].coef=temp;
			}
	printf("First Polynomial : ");
	print(i1,d1);
	printf("Second Polynomail : ");
	print(i2,d2);
	printf("Resultant Polynomial : ");
	print(o,n);		
}
