#include<stdio.h>
#include<stdlib.h>
int main(void){
	int n,i,num=0,num2;
	int a[100],max,j;
	char*ch[100];
	scanf("%d",&n);
	for(i=0;i<n;i++){
		ch[i]=(char*)malloc(sizeof(char)*100);
		scanf("%s",ch[i]);
	}
	for(i=0;i<n;i++){
		num=0;
		for(j=0;j<n;j++){
			if(ch[i]==ch[j]){
				num++;
			}
		}
		a[i]=num;
	}
	for(i=1;i<n;i++){
		max=a[0];
		if(a[0]>a[i]){
			max=a[0];
			num2=0;
		}
		else{
			max=a[i];
			num2=i;
		}
	}
	printf("%s\n",ch[num2]);
	system("pause");
	return 0;
}